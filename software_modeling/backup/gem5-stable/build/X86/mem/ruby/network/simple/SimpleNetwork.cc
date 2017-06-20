/*
 * Copyright (c) 1999-2008 Mark D. Hill and David A. Wood
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <cassert>
#include <numeric>

#include "base/cast.hh"
#include "base/stl_helpers.hh"
#include "mem/ruby/common/NetDest.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/simple/SimpleLink.hh"
#include "mem/ruby/network/simple/SimpleNetwork.hh"
#include "mem/ruby/network/simple/Switch.hh"
#include "mem/ruby/network/simple/Throttle.hh"
#include "mem/ruby/profiler/Profiler.hh"
#include "mem/ruby/system/System.hh"

using namespace std;
using m5::stl_helpers::deletePointers;

SimpleNetwork::SimpleNetwork(const Params *p)
    : Network(p)
{
    m_buffer_size = p->buffer_size;
    m_endpoint_bandwidth = p->endpoint_bandwidth;
    m_adaptive_routing = p->adaptive_routing;

    // Note: the parent Network Object constructor is called before the
    // SimpleNetwork child constructor.  Therefore, the member variables
    // used below should already be initialized.
    m_endpoint_switches.resize(m_nodes);

    // record the routers
    for (vector<BasicRouter*>::const_iterator i = p->routers.begin();
         i != p->routers.end(); ++i) {
        Switch* s = safe_cast<Switch*>(*i);
        m_switches.push_back(s);
        s->init_net_ptr(this);
    }
}

void
SimpleNetwork::init()
{
    Network::init();

    // The topology pointer should have already been initialized in
    // the parent class network constructor.
    assert(m_topology_ptr != NULL);
    m_topology_ptr->createLinks(this);
}

SimpleNetwork::~SimpleNetwork()
{
    deletePointers(m_switches);
    deletePointers(m_buffers_to_free);
}

// From a switch to an endpoint node
void
SimpleNetwork::makeOutLink(SwitchID src, NodeID dest, BasicLink* link, 
                           LinkDirection direction, 
                           const NetDest& routing_table_entry)
{
    assert(dest < m_nodes);
    assert(src < m_switches.size());
    assert(m_switches[src] != NULL);

    SimpleExtLink *simple_link = safe_cast<SimpleExtLink*>(link);

    m_switches[src]->addOutPort(m_fromNetQueues[dest], routing_table_entry,
                                simple_link->m_latency,
                                simple_link->m_bw_multiplier);

    m_endpoint_switches[dest] = m_switches[src];
}

// From an endpoint node to a switch
void
SimpleNetwork::makeInLink(NodeID src, SwitchID dest, BasicLink* link, 
                          LinkDirection direction, 
                          const NetDest& routing_table_entry)
{
    assert(src < m_nodes);
    m_switches[dest]->addInPort(m_toNetQueues[src]);
}

// From a switch to a switch
void
SimpleNetwork::makeInternalLink(SwitchID src, SwitchID dest, BasicLink* link, 
                                LinkDirection direction, 
                                const NetDest& routing_table_entry)
{
    // Create a set of new MessageBuffers
    std::vector<MessageBuffer*> queues(m_virtual_networks);

    for (int i = 0; i < m_virtual_networks; i++) {
        // allocate a buffer
        MessageBuffer* buffer_ptr = new MessageBuffer;
        buffer_ptr->setOrdering(true);

        if (m_buffer_size > 0) {
            buffer_ptr->resize(m_buffer_size);
        }

        queues[i] = buffer_ptr;
        // remember to deallocate it
        m_buffers_to_free.push_back(buffer_ptr);
    }

    // Connect it to the two switches
    SimpleIntLink *simple_link = safe_cast<SimpleIntLink*>(link);

    m_switches[dest]->addInPort(queues);
    m_switches[src]->addOutPort(queues, routing_table_entry,
                                simple_link->m_latency,
                                simple_link->m_bw_multiplier);
}

void
SimpleNetwork::checkNetworkAllocation(NodeID id, bool ordered, int network_num)
{
    assert(id < m_nodes);
    assert(network_num < m_virtual_networks);

    if (ordered) {
        m_ordered[network_num] = true;
    }
    m_in_use[network_num] = true;
}

void
SimpleNetwork::setToNetQueue(NodeID id, bool ordered, int network_num,
                             std::string vnet_type, MessageBuffer *b)
{
    checkNetworkAllocation(id, ordered, network_num);
    while (m_toNetQueues[id].size() <= network_num) {
        m_toNetQueues[id].push_back(nullptr);
    }
    m_toNetQueues[id][network_num] = b;
}

void
SimpleNetwork::setFromNetQueue(NodeID id, bool ordered, int network_num,
                               std::string vnet_type, MessageBuffer *b)
{
    checkNetworkAllocation(id, ordered, network_num);
    while (m_fromNetQueues[id].size() <= network_num) {
        m_fromNetQueues[id].push_back(nullptr);
    }
    m_fromNetQueues[id][network_num] = b;
}

void
SimpleNetwork::regStats()
{
    for (MessageSizeType type = MessageSizeType_FIRST;
         type < MessageSizeType_NUM; ++type) {
        m_msg_counts[(unsigned int) type]
            .name(name() + ".msg_count." + MessageSizeType_to_string(type))
            .flags(Stats::nozero)
            ;
        m_msg_bytes[(unsigned int) type]
            .name(name() + ".msg_byte." + MessageSizeType_to_string(type))
            .flags(Stats::nozero)
            ;

        // Now state what the formula is.
        for (int i = 0; i < m_switches.size(); i++) {
            m_msg_counts[(unsigned int) type] +=
                sum(m_switches[i]->getMsgCount(type));
        }

        m_msg_bytes[(unsigned int) type] =
            m_msg_counts[(unsigned int) type] * Stats::constant(
                    Network::MessageSizeType_to_int(type));
    }
}

void
SimpleNetwork::collateStats()
{
    for (int i = 0; i < m_switches.size(); i++) {
        m_switches[i]->collateStats();
    }
}

void
SimpleNetwork::print(ostream& out) const
{
    out << "[SimpleNetwork]";
}

SimpleNetwork *
SimpleNetworkParams::create()
{
    return new SimpleNetwork(this);
}

/*
 * The simple network has an array of switches. These switches have buffers
 * that need to be accessed for functional reads and writes. Also the links
 * between different switches have buffers that need to be accessed.
 */
bool
SimpleNetwork::functionalRead(Packet *pkt)
{
    for (unsigned int i = 0; i < m_switches.size(); i++) {
        if (m_switches[i]->functionalRead(pkt)) {
            return true;
        }
    }

    for (unsigned int i = 0; i < m_buffers_to_free.size(); ++i) {
        if (m_buffers_to_free[i]->functionalRead(pkt)) {
            return true;
        }
    }

    return false;
}

uint32_t
SimpleNetwork::functionalWrite(Packet *pkt)
{
    uint32_t num_functional_writes = 0;

    for (unsigned int i = 0; i < m_switches.size(); i++) {
        num_functional_writes += m_switches[i]->functionalWrite(pkt);
    }

    for (unsigned int i = 0; i < m_buffers_to_free.size(); ++i) {
        num_functional_writes += m_buffers_to_free[i]->functionalWrite(pkt);
    }
    return num_functional_writes;
}
