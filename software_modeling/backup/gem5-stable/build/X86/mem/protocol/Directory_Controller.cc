/** \file Directory_Controller.cc
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/StateMachine.py:443
 * Created by slicc definition of Module "Directory protocol"
 */

#include <sys/types.h>
#include <unistd.h>

#include <cassert>
#include <sstream>
#include <string>

#include "base/compiler.hh"
#include "base/cprintf.hh"
#include "debug/RubyGenerated.hh"
#include "debug/RubySlicc.hh"
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/Directory_Event.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"
#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;
#include "mem/protocol/TBETable.hh"
Directory_Controller *
Directory_ControllerParams::create()
{
    return new Directory_Controller(this);
}

int Directory_Controller::m_num_controllers = 0;
std::vector<Stats::Vector *>  Directory_Controller::eventVec;
std::vector<std::vector<Stats::Vector *> >  Directory_Controller::transVec;

// for adding information to the protocol debug trace
stringstream Directory_transitionComment;

#ifndef NDEBUG
#define APPEND_TRANSITION_COMMENT(str) (Directory_transitionComment << str)
#else
#define APPEND_TRANSITION_COMMENT(str) do {} while (0)
#endif

/** \brief constructor */
Directory_Controller::Directory_Controller(const Params *p)
    : AbstractController(p)
{
    m_machineID.type = MachineType_Directory;
    m_machineID.num = m_version;
    m_num_controllers++;

    m_in_ports = 3;
    m_directory_ptr = p->directory;
    m_directory_latency = p->directory_latency;
    m_to_memory_controller_latency = p->to_memory_controller_latency;

    for (int state = 0; state < Directory_State_NUM; state++) {
        for (int event = 0; event < Directory_Event_NUM; event++) {
            m_possible[state][event] = false;
            m_counters[state][event] = 0;
        }
    }
    for (int event = 0; event < Directory_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }
}

void
Directory_Controller::setNetQueue(const std::string& name, MessageBuffer *b)
{
    MachineType machine_type = string_to_MachineType("Directory");
    int base M5_VAR_USED = MachineType_base_number(machine_type);

    if ("forwardFromDir" == name) {
        m_forwardFromDir_ptr = b;
        assert(m_forwardFromDir_ptr != NULL);
        m_net_ptr->setToNetQueue(m_version + base, false, 3,
                                         "forward", b);
        m_forwardFromDir_ptr->setSender(this);
        m_forwardFromDir_ptr->setOrdering(false);
        m_forwardFromDir_ptr->resize(m_buffer_size);
        m_forwardFromDir_ptr->setRecycleLatency(m_recycle_latency);
        m_forwardFromDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=forwardFromDir]");
    }
    if ("responseFromDir" == name) {
        m_responseFromDir_ptr = b;
        assert(m_responseFromDir_ptr != NULL);
        m_net_ptr->setToNetQueue(m_version + base, false, 4,
                                         "response", b);
        m_responseFromDir_ptr->setSender(this);
        m_responseFromDir_ptr->setOrdering(false);
        m_responseFromDir_ptr->resize(m_buffer_size);
        m_responseFromDir_ptr->setRecycleLatency(m_recycle_latency);
        m_responseFromDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=responseFromDir]");
    }
    if ("dmaResponseFromDir" == name) {
        m_dmaResponseFromDir_ptr = b;
        assert(m_dmaResponseFromDir_ptr != NULL);
        m_net_ptr->setToNetQueue(m_version + base, true, 1,
                                         "response", b);
        m_dmaResponseFromDir_ptr->setSender(this);
        m_dmaResponseFromDir_ptr->setOrdering(true);
        m_dmaResponseFromDir_ptr->resize(m_buffer_size);
        m_dmaResponseFromDir_ptr->setRecycleLatency(m_recycle_latency);
        m_dmaResponseFromDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=dmaResponseFromDir]");
    }
    if ("requestToDir" == name) {
        m_requestToDir_ptr = b;
        assert(m_requestToDir_ptr != NULL);
        m_net_ptr->setFromNetQueue(m_version + base, true, 2,
                                         "request", b);
        m_requestToDir_ptr->setReceiver(this);
        m_requestToDir_ptr->setOrdering(true);
        m_requestToDir_ptr->resize(m_buffer_size);
        m_requestToDir_ptr->setRecycleLatency(m_recycle_latency);
        m_requestToDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=requestToDir]");
    }
    if ("dmaRequestToDir" == name) {
        m_dmaRequestToDir_ptr = b;
        assert(m_dmaRequestToDir_ptr != NULL);
        m_net_ptr->setFromNetQueue(m_version + base, true, 0,
                                         "request", b);
        m_dmaRequestToDir_ptr->setReceiver(this);
        m_dmaRequestToDir_ptr->setOrdering(true);
        m_dmaRequestToDir_ptr->resize(m_buffer_size);
        m_dmaRequestToDir_ptr->setRecycleLatency(m_recycle_latency);
        m_dmaRequestToDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=dmaRequestToDir]");
    }
}

void
Directory_Controller::init()
{
    // initialize objects

    m_TBEs_ptr  = new TBETable<Directory_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);


    (*m_dmaRequestToDir_ptr).setConsumer(this);
    (*m_dmaRequestToDir_ptr).setDescription("[Version " + to_string(m_version) + ", Directory, dmaRequestQueue_in]");
    (*m_requestToDir_ptr).setConsumer(this);
    (*m_requestToDir_ptr).setDescription("[Version " + to_string(m_version) + ", Directory, requestQueue_in]");
    (*m_responseFromMemory_ptr).setConsumer(this);
    (*m_responseFromMemory_ptr).setDescription("[Version " + to_string(m_version) + ", Directory, memQueue_in]");

    possibleTransition(Directory_State_M_DRD, Directory_Event_GETX);
    possibleTransition(Directory_State_M_DWR, Directory_Event_GETX);
    possibleTransition(Directory_State_M_DWRI, Directory_Event_GETX);
    possibleTransition(Directory_State_M_DRDI, Directory_Event_GETX);
    possibleTransition(Directory_State_IM, Directory_Event_GETX);
    possibleTransition(Directory_State_IM, Directory_Event_GETS);
    possibleTransition(Directory_State_IM, Directory_Event_PUTX);
    possibleTransition(Directory_State_IM, Directory_Event_PUTX_NotOwner);
    possibleTransition(Directory_State_MI, Directory_Event_GETX);
    possibleTransition(Directory_State_MI, Directory_Event_GETS);
    possibleTransition(Directory_State_MI, Directory_Event_PUTX);
    possibleTransition(Directory_State_MI, Directory_Event_PUTX_NotOwner);
    possibleTransition(Directory_State_ID, Directory_Event_GETX);
    possibleTransition(Directory_State_ID, Directory_Event_GETS);
    possibleTransition(Directory_State_ID, Directory_Event_PUTX);
    possibleTransition(Directory_State_ID, Directory_Event_PUTX_NotOwner);
    possibleTransition(Directory_State_ID_W, Directory_Event_GETX);
    possibleTransition(Directory_State_ID_W, Directory_Event_GETS);
    possibleTransition(Directory_State_ID_W, Directory_Event_PUTX);
    possibleTransition(Directory_State_ID_W, Directory_Event_PUTX_NotOwner);
    possibleTransition(Directory_State_IM, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_IM, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_MI, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_MI, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_ID, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_ID, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_ID_W, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_ID_W, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_I, Directory_Event_GETX);
    possibleTransition(Directory_State_IM, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_I, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_ID, Directory_Event_Memory_Data);
    possibleTransition(Directory_State_I, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_ID_W, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_M, Directory_Event_DMA_READ);
    possibleTransition(Directory_State_M_DRD, Directory_Event_PUTX);
    possibleTransition(Directory_State_M_DRDI, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_M, Directory_Event_DMA_WRITE);
    possibleTransition(Directory_State_M_DWR, Directory_Event_PUTX);
    possibleTransition(Directory_State_M_DWRI, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_M, Directory_Event_GETX);
    possibleTransition(Directory_State_M, Directory_Event_PUTX);
    possibleTransition(Directory_State_MI, Directory_Event_Memory_Ack);
    possibleTransition(Directory_State_M, Directory_Event_PUTX_NotOwner);
    possibleTransition(Directory_State_I, Directory_Event_PUTX_NotOwner);
    AbstractController::init();
    resetStats();
}

void
Directory_Controller::regStats()
{
    AbstractController::regStats();

    if (m_version == 0) {
        for (Directory_Event event = Directory_Event_FIRST;
             event < Directory_Event_NUM; ++event) {
            Stats::Vector *t = new Stats::Vector();
            t->init(m_num_controllers);
            t->name(g_system_ptr->name() + ".Directory_Controller." +
                Directory_Event_to_string(event));
            t->flags(Stats::pdf | Stats::total | Stats::oneline |
                     Stats::nozero);

            eventVec.push_back(t);
        }

        for (Directory_State state = Directory_State_FIRST;
             state < Directory_State_NUM; ++state) {

            transVec.push_back(std::vector<Stats::Vector *>());

            for (Directory_Event event = Directory_Event_FIRST;
                 event < Directory_Event_NUM; ++event) {

                Stats::Vector *t = new Stats::Vector();
                t->init(m_num_controllers);
                t->name(g_system_ptr->name() + ".Directory_Controller." +
                        Directory_State_to_string(state) +
                        "." + Directory_Event_to_string(event));

                t->flags(Stats::pdf | Stats::total | Stats::oneline |
                         Stats::nozero);
                transVec[state].push_back(t);
            }
        }
    }
}

void
Directory_Controller::collateStats()
{
    for (Directory_Event event = Directory_Event_FIRST;
         event < Directory_Event_NUM; ++event) {
        for (unsigned int i = 0; i < m_num_controllers; ++i) {
            std::map<uint32_t, AbstractController *>::iterator it =
                                g_abs_controls[MachineType_Directory].find(i);
            assert(it != g_abs_controls[MachineType_Directory].end());
            (*eventVec[event])[i] =
                ((Directory_Controller *)(*it).second)->getEventCount(event);
        }
    }

    for (Directory_State state = Directory_State_FIRST;
         state < Directory_State_NUM; ++state) {

        for (Directory_Event event = Directory_Event_FIRST;
             event < Directory_Event_NUM; ++event) {

            for (unsigned int i = 0; i < m_num_controllers; ++i) {
                std::map<uint32_t, AbstractController *>::iterator it =
                                g_abs_controls[MachineType_Directory].find(i);
                assert(it != g_abs_controls[MachineType_Directory].end());
                (*transVec[state][event])[i] =
                    ((Directory_Controller *)(*it).second)->getTransitionCount(state, event);
            }
        }
    }
}

void
Directory_Controller::countTransition(Directory_State state, Directory_Event event)
{
    assert(m_possible[state][event]);
    m_counters[state][event]++;
    m_event_counters[event]++;
}
void
Directory_Controller::possibleTransition(Directory_State state,
                             Directory_Event event)
{
    m_possible[state][event] = true;
}

uint64
Directory_Controller::getEventCount(Directory_Event event)
{
    return m_event_counters[event];
}

bool
Directory_Controller::isPossible(Directory_State state, Directory_Event event)
{
    return m_possible[state][event];
}

uint64
Directory_Controller::getTransitionCount(Directory_State state,
                             Directory_Event event)
{
    return m_counters[state][event];
}

int
Directory_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
Directory_Controller::getMandatoryQueue() const
{
    return NULL;
}

Sequencer*
Directory_Controller::getSequencer() const
{
    return NULL;
}

void
Directory_Controller::print(ostream& out) const
{
    out << "[Directory_Controller " << m_version << "]";
}

void Directory_Controller::resetStats()
{
    for (int state = 0; state < Directory_State_NUM; state++) {
        for (int event = 0; event < Directory_Event_NUM; event++) {
            m_counters[state][event] = 0;
        }
    }

    for (int event = 0; event < Directory_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }

    AbstractController::resetStats();
}

// Set and Reset for tbe variable
void
Directory_Controller::set_tbe(Directory_TBE*& m_tbe_ptr, Directory_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
Directory_Controller::unset_tbe(Directory_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
Directory_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
}

// Actions
/** \brief Send writeback ack to requestor */
void
Directory_Controller::a_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing a_sendWriteBackAck\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_ACK;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_forwardFromDir_ptr)).enqueue(out_msg, Cycles(m_directory_latency));
}
}

}

/** \brief Send writeback ack to requestor */
void
Directory_Controller::l_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing l_sendWriteBackAck\n");
    {
    // Declare message
    const MemoryMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_responseFromMemory_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_ACK;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_OriginalRequestorMachId;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_OriginalRequestorMachId));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_forwardFromDir_ptr)).enqueue(out_msg, Cycles((1)));
}
}

}

/** \brief Send writeback nack to requestor */
void
Directory_Controller::b_sendWriteBackNack(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing b_sendWriteBackNack\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_NACK;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_forwardFromDir_ptr)).enqueue(out_msg, Cycles(m_directory_latency));
}
}

}

/** \brief Clear the owner field */
void
Directory_Controller::c_clearOwner(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing c_clearOwner\n");
    (((*(getDirectoryEntry(addr))).m_Owner).clear());

}

/** \brief Send data to requestor */
void
Directory_Controller::d_sendData(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing d_sendData\n");
    {
    // Declare message
    const MemoryMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_responseFromMemory_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_OriginalRequestorMachId));
    (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromDir_ptr)).enqueue(out_msg, Cycles((1)));
}
}

}

/** \brief Send Data to DMA controller from directory */
void
Directory_Controller::dr_sendDMAData(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing dr_sendDMAData\n");
    {
    // Declare message
    const MemoryMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_responseFromMemory_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<DMAResponseMsg> out_msg = std::make_shared<DMAResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MI_example-dir.sm:317: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_PhysicalAddress = addr;
    (*out_msg).m_LineAddress = addr;
    (*out_msg).m_Type = DMAResponseType_DATA;
    (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    (((*out_msg).m_Destination).add((*m_tbe_ptr).m_DmaRequestor));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_dmaResponseFromDir_ptr)).enqueue(out_msg, Cycles((1)));
}
}

}

/** \brief Send Data to DMA controller from incoming PUTX */
void
Directory_Controller::drp_sendDMAData(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing drp_sendDMAData\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<DMAResponseMsg> out_msg = std::make_shared<DMAResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MI_example-dir.sm:333: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_PhysicalAddress = addr;
    (*out_msg).m_LineAddress = addr;
    (*out_msg).m_Type = DMAResponseType_DATA;
    (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    (((*out_msg).m_Destination).add((*m_tbe_ptr).m_DmaRequestor));
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_dmaResponseFromDir_ptr)).enqueue(out_msg, Cycles((1)));
}
}

}

/** \brief Send Ack to DMA controller */
void
Directory_Controller::da_sendDMAAck(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing da_sendDMAAck\n");
    {
    std::shared_ptr<DMAResponseMsg> out_msg = std::make_shared<DMAResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MI_example-dir.sm:349: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_PhysicalAddress = addr;
    (*out_msg).m_LineAddress = addr;
    (*out_msg).m_Type = DMAResponseType_ACK;
    (((*out_msg).m_Destination).add((*m_tbe_ptr).m_DmaRequestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_dmaResponseFromDir_ptr)).enqueue(out_msg, Cycles((1)));
}

}

/** \brief The owner is now the requestor */
void
Directory_Controller::e_ownerIsRequestor(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing e_ownerIsRequestor\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*(getDirectoryEntry(addr))).m_Owner).clear());
(((*(getDirectoryEntry(addr))).m_Owner).add(((*in_msg_ptr)).m_Requestor));
}

}

/** \brief Forward request to owner */
void
Directory_Controller::f_forwardRequest(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing f_forwardRequest\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
APPEND_TRANSITION_COMMENT(("Own: "));
APPEND_TRANSITION_COMMENT((*(getDirectoryEntry(((*in_msg_ptr)).m_Addr))).m_Owner);
APPEND_TRANSITION_COMMENT(("Req: "));
APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_Destination = (*(getDirectoryEntry(((*in_msg_ptr)).m_Addr))).m_Owner;
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_forwardFromDir_ptr)).enqueue(out_msg, Cycles(m_directory_latency));
}
}

}

/** \brief Invalidate a cache block */
void
Directory_Controller::inv_sendCacheInvalidate(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing inv_sendCacheInvalidate\n");
    {
    // Declare message
    const DMARequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const DMARequestMsg *>(((*m_dmaRequestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_INV;
    (*out_msg).m_Requestor = m_machineID;
    (*out_msg).m_Destination = (*(getDirectoryEntry(((*in_msg_ptr)).m_PhysicalAddress))).m_Owner;
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    ((*m_forwardFromDir_ptr)).enqueue(out_msg, Cycles(m_directory_latency));
}
}

}

/** \brief Pop incoming request queue */
void
Directory_Controller::i_popIncomingRequestQueue(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing i_popIncomingRequestQueue\n");
    (((*m_requestToDir_ptr)).dequeue());

}

/** \brief Pop incoming DMA queue */
void
Directory_Controller::p_popIncomingDMARequestQueue(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing p_popIncomingDMARequestQueue\n");
    (((*m_dmaRequestToDir_ptr)).dequeue());

}

/** \brief Allocate TBE */
void
Directory_Controller::v_allocateTBE(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing v_allocateTBE\n");
    {
    // Declare message
    const DMARequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const DMARequestMsg *>(((*m_dmaRequestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
(*m_tbe_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
(*m_tbe_ptr).m_PhysicalAddress = ((*in_msg_ptr)).m_PhysicalAddress;
(*m_tbe_ptr).m_Len = ((*in_msg_ptr)).m_Len;
(*m_tbe_ptr).m_DmaRequestor = ((*in_msg_ptr)).m_Requestor;
}

}

/** \brief Allocate TBE for DMA Read */
void
Directory_Controller::r_allocateTbeForDmaRead(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing r_allocateTbeForDmaRead\n");
    {
    // Declare message
    const DMARequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const DMARequestMsg *>(((*m_dmaRequestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
(*m_tbe_ptr).m_DmaRequestor = ((*in_msg_ptr)).m_Requestor;
}

}

/** \brief Allocate TBE */
void
Directory_Controller::v_allocateTBEFromRequestNet(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing v_allocateTBEFromRequestNet\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;
(*m_tbe_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

}

/** \brief Deallocate TBE */
void
Directory_Controller::w_deallocateTBE(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing w_deallocateTBE\n");
    (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

}

/** \brief recycle request queue */
void
Directory_Controller::z_recycleRequestQueue(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing z_recycleRequestQueue\n");
    (((*m_requestToDir_ptr)).recycle());

}

/** \brief recycle dma request queue */
void
Directory_Controller::y_recycleDMARequestQueue(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing y_recycleDMARequestQueue\n");
    (((*m_dmaRequestToDir_ptr)).recycle());

}

/** \brief Queue off-chip fetch request */
void
Directory_Controller::qf_queueMemoryFetchRequest(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing qf_queueMemoryFetchRequest\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(queueMemoryRead(((*in_msg_ptr)).m_Requestor, addr, m_to_memory_controller_latency));
}

}

/** \brief Queue off-chip fetch request */
void
Directory_Controller::qf_queueMemoryFetchRequestDMA(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing qf_queueMemoryFetchRequestDMA\n");
    {
    // Declare message
    const DMARequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const DMARequestMsg *>(((*m_dmaRequestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(queueMemoryRead(((*in_msg_ptr)).m_Requestor, addr, m_to_memory_controller_latency));
}

}

/** \brief Queue off-chip writeback request */
void
Directory_Controller::qw_queueMemoryWBRequest_partial(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing qw_queueMemoryWBRequest_partial\n");
    {
    // Declare message
    const DMARequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const DMARequestMsg *>(((*m_dmaRequestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(queueMemoryWritePartial(((*in_msg_ptr)).m_Requestor, addr, m_to_memory_controller_latency, ((*in_msg_ptr)).m_DataBlk, ((*in_msg_ptr)).m_Len));
}

}

/** \brief Queue off-chip writeback request */
void
Directory_Controller::qw_queueMemoryWBRequest_partialTBE(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing qw_queueMemoryWBRequest_partialTBE\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(queueMemoryWritePartial(((*in_msg_ptr)).m_Requestor, addr, m_to_memory_controller_latency, (*m_tbe_ptr).m_DataBlk, (*m_tbe_ptr).m_Len));
}

}

/** \brief Write PUTX data to memory */
void
Directory_Controller::l_queueMemoryWBRequest(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing l_queueMemoryWBRequest\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(queueMemoryWrite(((*in_msg_ptr)).m_Requestor, addr, m_to_memory_controller_latency, ((*in_msg_ptr)).m_DataBlk));
}

}

/** \brief Pop off-chip request queue */
void
Directory_Controller::l_popMemQueue(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing l_popMemQueue\n");
    (((*m_responseFromMemory_ptr)).dequeue());

}

Directory_Entry*
Directory_Controller::getDirectoryEntry(const Address& param_addr)
{
Directory_Entry* dir_entry
 = static_cast<Directory_Entry *>((((*m_directory_ptr)).lookup(param_addr)))
;
    if ((dir_entry != NULL)) {
        return dir_entry;
    }
    dir_entry = static_cast<Directory_Entry *>((((*m_directory_ptr)).allocate(param_addr, new Directory_Entry)))
    ;
    return dir_entry;

}
Directory_State
Directory_Controller::getState(Directory_TBE* param_tbe, const Address& param_addr)
{
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((((*m_directory_ptr)).isPresent(param_addr))) {
                return (*(getDirectoryEntry(param_addr))).m_DirectoryState;
            } else {
                return Directory_State_I;
            }
        }

}
void
Directory_Controller::setState(Directory_TBE* param_tbe, const Address& param_addr, const Directory_State& param_state)
{
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((((*m_directory_ptr)).isPresent(param_addr))) {
                if ((param_state == Directory_State_M)) {
                    #ifndef NDEBUG
                    if (!(((((*(getDirectoryEntry(param_addr))).m_Owner).count()) == (1)))) {
                        panic("Runtime Error at MI_example-dir.sm:144: %s.\n", "assert failure");

                    }
                    #endif
                    ;
                    #ifndef NDEBUG
                    if (!(((((*(getDirectoryEntry(param_addr))).m_Sharers).count()) == (0)))) {
                        panic("Runtime Error at MI_example-dir.sm:145: %s.\n", "assert failure");

                    }
                    #endif
                    ;
                }
                (*(getDirectoryEntry(param_addr))).m_DirectoryState = param_state;
                    if ((param_state == Directory_State_I)) {
                        #ifndef NDEBUG
                        if (!(((((*(getDirectoryEntry(param_addr))).m_Owner).count()) == (0)))) {
                            panic("Runtime Error at MI_example-dir.sm:151: %s.\n", "assert failure");

                        }
                        #endif
                        ;
                        #ifndef NDEBUG
                        if (!(((((*(getDirectoryEntry(param_addr))).m_Sharers).count()) == (0)))) {
                            panic("Runtime Error at MI_example-dir.sm:152: %s.\n", "assert failure");

                        }
                        #endif
                        ;
                    }
                }

}
AccessPermission
Directory_Controller::getAccessPermission(const Address& param_addr)
{
Directory_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        return (Directory_State_to_permission((*tbe).m_TBEState));
    }
        if ((((*m_directory_ptr)).isPresent(param_addr))) {
            return (Directory_State_to_permission((*(getDirectoryEntry(param_addr))).m_DirectoryState));
        }
        return AccessPermission_NotPresent;

}
void
Directory_Controller::setAccessPermission(const Address& param_addr, const Directory_State& param_state)
{
    if ((((*m_directory_ptr)).isPresent(param_addr))) {
        ((*((getDirectoryEntry(param_addr)))).changePermission((Directory_State_to_permission(param_state))));
    }

}
void
Directory_Controller::functionalRead(const Address& param_addr, Packet* param_pkt)
{
Directory_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        (testAndRead(param_addr, (*tbe).m_DataBlk, param_pkt));
    } else {
        (functionalMemoryRead(param_pkt));
    }

}
int
Directory_Controller::functionalWrite(const Address& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
Directory_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*tbe).m_DataBlk, param_pkt)));
    }
    num_functional_writes = (num_functional_writes + (functionalMemoryWrite(param_pkt)));
    return num_functional_writes;

}
int
Directory_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_forwardFromDir_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromDir_ptr->functionalWrite(pkt);
num_functional_writes += m_dmaResponseFromDir_ptr->functionalWrite(pkt);
num_functional_writes += m_requestToDir_ptr->functionalWrite(pkt);
num_functional_writes += m_dmaRequestToDir_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
