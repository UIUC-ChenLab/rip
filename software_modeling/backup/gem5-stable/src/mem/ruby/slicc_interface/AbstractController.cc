/*
 * Copyright (c) 2011-2014 Mark D. Hill and David A. Wood
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

#include "mem/protocol/MemoryMsg.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "mem/ruby/system/Sequencer.hh"
#include "mem/ruby/system/System.hh"
#include "sim/system.hh"

AbstractController::AbstractController(const Params *p)
    : MemObject(p), Consumer(this), m_version(p->version),
      m_clusterID(p->cluster_id),
      m_masterId(p->system->getMasterId(name())), m_is_blocking(false),
      m_number_of_TBEs(p->number_of_TBEs),
      m_transitions_per_cycle(p->transitions_per_cycle),
      m_buffer_size(p->buffer_size), m_recycle_latency(p->recycle_latency),
      memoryPort(csprintf("%s.memory", name()), this, ""),
      m_responseFromMemory_ptr(new MessageBuffer())
{
    // Set the sender pointer of the response message buffer from the
    // memory controller.
    // This pointer is used for querying for the current time.
    m_responseFromMemory_ptr->setSender(this);
    m_responseFromMemory_ptr->setReceiver(this);
    m_responseFromMemory_ptr->setOrdering(false);

    if (m_version == 0) {
        // Combine the statistics from all controllers
        // of this particular type.
        Stats::registerDumpCallback(new StatsCallback(this));
    }
}

void
AbstractController::init()
{
    params()->ruby_system->registerAbstractController(this);
    m_delayHistogram.init(10);
    uint32_t size = Network::getNumberOfVirtualNetworks();
    for (uint32_t i = 0; i < size; i++) {
        m_delayVCHistogram.push_back(new Stats::Histogram());
        m_delayVCHistogram[i]->init(10);
    }
}

void
AbstractController::resetStats()
{
    m_delayHistogram.reset();
    uint32_t size = Network::getNumberOfVirtualNetworks();
    for (uint32_t i = 0; i < size; i++) {
        m_delayVCHistogram[i]->reset();
    }
}

void
AbstractController::regStats()
{
    m_fully_busy_cycles
        .name(name() + ".fully_busy_cycles")
        .desc("cycles for which number of transistions == max transitions")
        .flags(Stats::nozero);
}

void
AbstractController::profileMsgDelay(uint32_t virtualNetwork, Cycles delay)
{
    assert(virtualNetwork < m_delayVCHistogram.size());
    m_delayHistogram.sample(delay);
    m_delayVCHistogram[virtualNetwork]->sample(delay);
}

void
AbstractController::stallBuffer(MessageBuffer* buf, Address addr)
{
    if (m_waiting_buffers.count(addr) == 0) {
        MsgVecType* msgVec = new MsgVecType;
        msgVec->resize(m_in_ports, NULL);
        m_waiting_buffers[addr] = msgVec;
    }
    (*(m_waiting_buffers[addr]))[m_cur_in_port] = buf;
}

void
AbstractController::wakeUpBuffers(Address addr)
{
    if (m_waiting_buffers.count(addr) > 0) {
        //
        // Wake up all possible lower rank (i.e. lower priority) buffers that could
        // be waiting on this message.
        //
        for (int in_port_rank = m_cur_in_port - 1;
             in_port_rank >= 0;
             in_port_rank--) {
            if ((*(m_waiting_buffers[addr]))[in_port_rank] != NULL) {
                (*(m_waiting_buffers[addr]))[in_port_rank]->reanalyzeMessages(addr);
            }
        }
        delete m_waiting_buffers[addr];
        m_waiting_buffers.erase(addr);
    }
}

void
AbstractController::wakeUpAllBuffers(Address addr)
{
    if (m_waiting_buffers.count(addr) > 0) {
        //
        // Wake up all possible lower rank (i.e. lower priority) buffers that could
        // be waiting on this message.
        //
        for (int in_port_rank = m_in_ports - 1;
             in_port_rank >= 0;
             in_port_rank--) {
            if ((*(m_waiting_buffers[addr]))[in_port_rank] != NULL) {
                (*(m_waiting_buffers[addr]))[in_port_rank]->reanalyzeMessages(addr);
            }
        }
        delete m_waiting_buffers[addr];
        m_waiting_buffers.erase(addr);
    }
}

void
AbstractController::wakeUpAllBuffers()
{
    //
    // Wake up all possible buffers that could be waiting on any message.
    //

    std::vector<MsgVecType*> wokeUpMsgVecs;

    if(m_waiting_buffers.size() > 0) {
        for (WaitingBufType::iterator buf_iter = m_waiting_buffers.begin();
             buf_iter != m_waiting_buffers.end();
             ++buf_iter) {
             for (MsgVecType::iterator vec_iter = buf_iter->second->begin();
                  vec_iter != buf_iter->second->end();
                  ++vec_iter) {
                  if (*vec_iter != NULL) {
                      (*vec_iter)->reanalyzeAllMessages();
                  }
             }
             wokeUpMsgVecs.push_back(buf_iter->second);
        }

        for (std::vector<MsgVecType*>::iterator wb_iter = wokeUpMsgVecs.begin();
             wb_iter != wokeUpMsgVecs.end();
             ++wb_iter) {
             delete (*wb_iter);
        }

        m_waiting_buffers.clear();
    }
}

void
AbstractController::blockOnQueue(Address addr, MessageBuffer* port)
{
    m_is_blocking = true;
    m_block_map[addr] = port;
}

void
AbstractController::unblock(Address addr)
{
    m_block_map.erase(addr);
    if (m_block_map.size() == 0) {
       m_is_blocking = false;
    }
}

BaseMasterPort &
AbstractController::getMasterPort(const std::string &if_name,
                                  PortID idx)
{
    return memoryPort;
}

void
AbstractController::queueMemoryRead(const MachineID &id, Address addr,
                                    Cycles latency)
{
    RequestPtr req = new Request(addr.getAddress(),
                                 RubySystem::getBlockSizeBytes(), 0,
                                 m_masterId);

    PacketPtr pkt = Packet::createRead(req);
    uint8_t *newData = new uint8_t[RubySystem::getBlockSizeBytes()];
    pkt->dataDynamic(newData);

    SenderState *s = new SenderState(id);
    pkt->pushSenderState(s);

    // Use functional rather than timing accesses during warmup
    if (RubySystem::getWarmupEnabled()) {
        memoryPort.sendFunctional(pkt);
        recvTimingResp(pkt);
        return;
    }

    memoryPort.schedTimingReq(pkt, clockEdge(latency));
}

void
AbstractController::queueMemoryWrite(const MachineID &id, Address addr,
                                     Cycles latency, const DataBlock &block)
{
    RequestPtr req = new Request(addr.getAddress(),
                                 RubySystem::getBlockSizeBytes(), 0,
                                 m_masterId);

    PacketPtr pkt = Packet::createWrite(req);
    uint8_t *newData = new uint8_t[RubySystem::getBlockSizeBytes()];
    pkt->dataDynamic(newData);
    memcpy(newData, block.getData(0, RubySystem::getBlockSizeBytes()),
           RubySystem::getBlockSizeBytes());

    SenderState *s = new SenderState(id);
    pkt->pushSenderState(s);

    // Use functional rather than timing accesses during warmup
    if (RubySystem::getWarmupEnabled()) {
        memoryPort.sendFunctional(pkt);
        recvTimingResp(pkt);
        return;
    }

    // Create a block and copy data from the block.
    memoryPort.schedTimingReq(pkt, clockEdge(latency));
}

void
AbstractController::queueMemoryWritePartial(const MachineID &id, Address addr,
                                            Cycles latency,
                                            const DataBlock &block, int size)
{
    RequestPtr req = new Request(addr.getAddress(),
                                 RubySystem::getBlockSizeBytes(), 0,
                                 m_masterId);

    PacketPtr pkt = Packet::createWrite(req);
    uint8_t *newData = new uint8_t[size];
    pkt->dataDynamic(newData);
    memcpy(newData, block.getData(addr.getOffset(), size), size);

    SenderState *s = new SenderState(id);
    pkt->pushSenderState(s);

    // Create a block and copy data from the block.
    memoryPort.schedTimingReq(pkt, clockEdge(latency));
}

void
AbstractController::functionalMemoryRead(PacketPtr pkt)
{
    memoryPort.sendFunctional(pkt);
}

int
AbstractController::functionalMemoryWrite(PacketPtr pkt)
{
    int num_functional_writes = 0;

    // Check the message buffer that runs from the memory to the controller.
    num_functional_writes += m_responseFromMemory_ptr->functionalWrite(pkt);

    // Check the buffer from the controller to the memory.
    if (memoryPort.checkFunctional(pkt)) {
        num_functional_writes++;
    }

    // Update memory itself.
    memoryPort.sendFunctional(pkt);
    return num_functional_writes + 1;
}

void
AbstractController::recvTimingResp(PacketPtr pkt)
{
    assert(pkt->isResponse());

    std::shared_ptr<MemoryMsg> msg = std::make_shared<MemoryMsg>(clockEdge());
    (*msg).m_Addr.setAddress(pkt->getAddr());
    (*msg).m_Sender = m_machineID;

    SenderState *s = dynamic_cast<SenderState *>(pkt->senderState);
    (*msg).m_OriginalRequestorMachId = s->id;
    delete s;

    if (pkt->isRead()) {
        (*msg).m_Type = MemoryRequestType_MEMORY_READ;
        (*msg).m_MessageSize = MessageSizeType_Response_Data;

        // Copy data from the packet
        (*msg).m_DataBlk.setData(pkt->getPtr<uint8_t>(), 0,
                                 RubySystem::getBlockSizeBytes());
    } else if (pkt->isWrite()) {
        (*msg).m_Type = MemoryRequestType_MEMORY_WB;
        (*msg).m_MessageSize = MessageSizeType_Writeback_Control;
    } else {
        panic("Incorrect packet type received from memory controller!");
    }

    m_responseFromMemory_ptr->enqueue(msg);
    delete pkt;
}

bool
AbstractController::MemoryPort::recvTimingResp(PacketPtr pkt)
{
    controller->recvTimingResp(pkt);
    return true;
}

AbstractController::MemoryPort::MemoryPort(const std::string &_name,
                                           AbstractController *_controller,
                                           const std::string &_label)
    : QueuedMasterPort(_name, _controller, reqQueue, snoopRespQueue),
      reqQueue(*_controller, *this, _label),
      snoopRespQueue(*_controller, *this, _label),
      controller(_controller)
{
}
