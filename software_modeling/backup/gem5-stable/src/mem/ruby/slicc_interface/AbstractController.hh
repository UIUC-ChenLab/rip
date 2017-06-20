/*
 * Copyright (c) 2009-2014 Mark D. Hill and David A. Wood
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

#ifndef __MEM_RUBY_SLICC_INTERFACE_ABSTRACTCONTROLLER_HH__
#define __MEM_RUBY_SLICC_INTERFACE_ABSTRACTCONTROLLER_HH__

#include <iostream>
#include <string>

#include "base/callback.hh"
#include "mem/protocol/AccessPermission.hh"
#include "mem/ruby/common/Address.hh"
#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/common/DataBlock.hh"
#include "mem/ruby/common/Histogram.hh"
#include "mem/ruby/common/MachineID.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/Network.hh"
#include "mem/ruby/system/CacheRecorder.hh"
#include "mem/packet.hh"
#include "mem/qport.hh"
#include "params/RubyController.hh"
#include "mem/mem_object.hh"

class Network;

class AbstractController : public MemObject, public Consumer
{
  public:
    typedef RubyControllerParams Params;
    AbstractController(const Params *p);
    void init();
    const Params *params() const { return (const Params *)_params; }

    const NodeID getVersion() const { return m_machineID.getNum(); }
    const MachineType getType() const { return m_machineID.getType(); }

    void initNetworkPtr(Network* net_ptr) { m_net_ptr = net_ptr; }

    // return instance name
    void blockOnQueue(Address, MessageBuffer*);
    void unblock(Address);

    virtual MessageBuffer* getMandatoryQueue() const = 0;
    virtual AccessPermission getAccessPermission(const Address& addr) = 0;

    virtual void print(std::ostream & out) const = 0;
    virtual void wakeup() = 0;
    virtual void resetStats() = 0;
    virtual void regStats();

    virtual void recordCacheTrace(int cntrl, CacheRecorder* tr) = 0;
    virtual Sequencer* getSequencer() const = 0;

    //! These functions are used by ruby system to read/write the data blocks
    //! that exist with in the controller.
    virtual void functionalRead(const Address &addr, PacketPtr) = 0;
    void functionalMemoryRead(PacketPtr);
    //! The return value indicates the number of messages written with the
    //! data from the packet.
    virtual int functionalWriteBuffers(PacketPtr&) = 0;
    virtual int functionalWrite(const Address &addr, PacketPtr) = 0;
    int functionalMemoryWrite(PacketPtr);

    //! Function for enqueuing a prefetch request
    virtual void enqueuePrefetch(const Address&, const RubyRequestType&)
    { fatal("Prefetches not implemented!");}

    //! Function for collating statistics from all the controllers of this
    //! particular type. This function should only be called from the
    //! version 0 of this controller type.
    virtual void collateStats()
    {fatal("collateStats() should be overridden!");}

    //! Set the message buffer with given name.
    virtual void setNetQueue(const std::string& name, MessageBuffer *b) = 0;

    /** A function used to return the port associated with this bus object. */
    BaseMasterPort& getMasterPort(const std::string& if_name,
                                  PortID idx = InvalidPortID);

    void queueMemoryRead(const MachineID &id, Address addr, Cycles latency);
    void queueMemoryWrite(const MachineID &id, Address addr, Cycles latency,
                          const DataBlock &block);
    void queueMemoryWritePartial(const MachineID &id, Address addr, Cycles latency,
                                 const DataBlock &block, int size);
    void recvTimingResp(PacketPtr pkt);

  public:
    MachineID getMachineID() const { return m_machineID; }

    Stats::Histogram& getDelayHist() { return m_delayHistogram; }
    Stats::Histogram& getDelayVCHist(uint32_t index)
    { return *(m_delayVCHistogram[index]); }

  protected:
    //! Profiles original cache requests including PUTs
    void profileRequest(const std::string &request);
    //! Profiles the delay associated with messages.
    void profileMsgDelay(uint32_t virtualNetwork, Cycles delay);

    void stallBuffer(MessageBuffer* buf, Address addr);
    void wakeUpBuffers(Address addr);
    void wakeUpAllBuffers(Address addr);
    void wakeUpAllBuffers();

  protected:
    NodeID m_version;
    MachineID m_machineID;
    NodeID m_clusterID;

    // MasterID used by some components of gem5.
    MasterID m_masterId;

    Network* m_net_ptr;
    bool m_is_blocking;
    std::map<Address, MessageBuffer*> m_block_map;

    typedef std::vector<MessageBuffer*> MsgVecType;
    typedef std::map< Address, MsgVecType* > WaitingBufType;
    WaitingBufType m_waiting_buffers;

    unsigned int m_in_ports;
    unsigned int m_cur_in_port;
    int m_number_of_TBEs;
    int m_transitions_per_cycle;
    unsigned int m_buffer_size;
    Cycles m_recycle_latency;

    //! Counter for the number of cycles when the transitions carried out
    //! were equal to the maximum allowed
    Stats::Scalar m_fully_busy_cycles;

    //! Histogram for profiling delay for the messages this controller
    //! cares for
    Stats::Histogram m_delayHistogram;
    std::vector<Stats::Histogram *> m_delayVCHistogram;

    //! Callback class used for collating statistics from all the
    //! controller of this type.
    class StatsCallback : public Callback
    {
      private:
        AbstractController *ctr;

      public:
        virtual ~StatsCallback() {}
        StatsCallback(AbstractController *_ctr) : ctr(_ctr) {}
        void process() {ctr->collateStats();}
    };

    /**
     * Port that forwards requests and receives responses from the
     * memory controller.  It has a queue of packets not yet sent.
     */
    class MemoryPort : public QueuedMasterPort
    {
      private:
        // Packet queues used to store outgoing requests and snoop responses.
        ReqPacketQueue reqQueue;
        SnoopRespPacketQueue snoopRespQueue;

        // Controller that operates this port.
        AbstractController *controller;

      public:
        MemoryPort(const std::string &_name, AbstractController *_controller,
                   const std::string &_label);

        // Function for receiving a timing response from the peer port.
        // Currently the pkt is handed to the coherence controller
        // associated with this port.
        bool recvTimingResp(PacketPtr pkt);
    };

    /* Master port to the memory controller. */
    MemoryPort memoryPort;

    // Message Buffer for storing the response received from the
    // memory controller.
    MessageBuffer *m_responseFromMemory_ptr;

    // State that is stored in packets sent to the memory controller.
    struct SenderState : public Packet::SenderState
    {
        // Id of the machine from which the request originated.
        MachineID id;

        SenderState(MachineID _id) : id(_id)
        {}
    };
};

#endif // __MEM_RUBY_SLICC_INTERFACE_ABSTRACTCONTROLLER_HH__
