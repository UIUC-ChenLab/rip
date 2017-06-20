/** \file L1Cache_Controller.cc
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/StateMachine.py:443
 * Created by slicc definition of Module "MI Example L1 Cache"
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
#include "mem/protocol/L1Cache_Controller.hh"
#include "mem/protocol/L1Cache_Event.hh"
#include "mem/protocol/L1Cache_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"
#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;
#include "mem/protocol/MessageBuffer.hh"
#include "mem/protocol/TBETable.hh"
L1Cache_Controller *
L1Cache_ControllerParams::create()
{
    return new L1Cache_Controller(this);
}

int L1Cache_Controller::m_num_controllers = 0;
std::vector<Stats::Vector *>  L1Cache_Controller::eventVec;
std::vector<std::vector<Stats::Vector *> >  L1Cache_Controller::transVec;

// for adding information to the protocol debug trace
stringstream L1Cache_transitionComment;

#ifndef NDEBUG
#define APPEND_TRANSITION_COMMENT(str) (L1Cache_transitionComment << str)
#else
#define APPEND_TRANSITION_COMMENT(str) do {} while (0)
#endif

/** \brief constructor */
L1Cache_Controller::L1Cache_Controller(const Params *p)
    : AbstractController(p)
{
    m_machineID.type = MachineType_L1Cache;
    m_machineID.num = m_version;
    m_num_controllers++;

    m_in_ports = 3;
    m_sequencer_ptr = p->sequencer;
    m_sequencer_ptr->setController(this);
    m_cacheMemory_ptr = p->cacheMemory;
    m_cache_response_latency = p->cache_response_latency;
    m_issue_latency = p->issue_latency;
    m_send_evictions = p->send_evictions;
    m_mandatoryQueue_ptr = new MessageBuffer();
    m_mandatoryQueue_ptr->setReceiver(this);

    for (int state = 0; state < L1Cache_State_NUM; state++) {
        for (int event = 0; event < L1Cache_Event_NUM; event++) {
            m_possible[state][event] = false;
            m_counters[state][event] = 0;
        }
    }
    for (int event = 0; event < L1Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }
}

void
L1Cache_Controller::setNetQueue(const std::string& name, MessageBuffer *b)
{
    MachineType machine_type = string_to_MachineType("L1Cache");
    int base M5_VAR_USED = MachineType_base_number(machine_type);

    if ("requestFromCache" == name) {
        m_requestFromCache_ptr = b;
        assert(m_requestFromCache_ptr != NULL);
        m_net_ptr->setToNetQueue(m_version + base, true, 2,
                                         "request", b);
        m_requestFromCache_ptr->setSender(this);
        m_requestFromCache_ptr->setOrdering(true);
        m_requestFromCache_ptr->resize(m_buffer_size);
        m_requestFromCache_ptr->setRecycleLatency(m_recycle_latency);
        m_requestFromCache_ptr->setDescription("[Version " + to_string(m_version) + ", L1Cache, name=requestFromCache]");
    }
    if ("responseFromCache" == name) {
        m_responseFromCache_ptr = b;
        assert(m_responseFromCache_ptr != NULL);
        m_net_ptr->setToNetQueue(m_version + base, true, 4,
                                         "response", b);
        m_responseFromCache_ptr->setSender(this);
        m_responseFromCache_ptr->setOrdering(true);
        m_responseFromCache_ptr->resize(m_buffer_size);
        m_responseFromCache_ptr->setRecycleLatency(m_recycle_latency);
        m_responseFromCache_ptr->setDescription("[Version " + to_string(m_version) + ", L1Cache, name=responseFromCache]");
    }
    if ("forwardToCache" == name) {
        m_forwardToCache_ptr = b;
        assert(m_forwardToCache_ptr != NULL);
        m_net_ptr->setFromNetQueue(m_version + base, true, 3,
                                         "forward", b);
        m_forwardToCache_ptr->setReceiver(this);
        m_forwardToCache_ptr->setOrdering(true);
        m_forwardToCache_ptr->resize(m_buffer_size);
        m_forwardToCache_ptr->setRecycleLatency(m_recycle_latency);
        m_forwardToCache_ptr->setDescription("[Version " + to_string(m_version) + ", L1Cache, name=forwardToCache]");
    }
    if ("responseToCache" == name) {
        m_responseToCache_ptr = b;
        assert(m_responseToCache_ptr != NULL);
        m_net_ptr->setFromNetQueue(m_version + base, true, 4,
                                         "response", b);
        m_responseToCache_ptr->setReceiver(this);
        m_responseToCache_ptr->setOrdering(true);
        m_responseToCache_ptr->resize(m_buffer_size);
        m_responseToCache_ptr->setRecycleLatency(m_recycle_latency);
        m_responseToCache_ptr->setDescription("[Version " + to_string(m_version) + ", L1Cache, name=responseToCache]");
    }
}

void
L1Cache_Controller::init()
{
    // initialize objects

    assert(m_mandatoryQueue_ptr != NULL);
    m_mandatoryQueue_ptr->setOrdering(false);
    m_mandatoryQueue_ptr->setRecycleLatency(m_recycle_latency);
    m_TBEs_ptr  = new TBETable<L1Cache_TBE>(m_number_of_TBEs);
    assert(m_TBEs_ptr != NULL);


    (*m_forwardToCache_ptr).setConsumer(this);
    (*m_forwardToCache_ptr).setDescription("[Version " + to_string(m_version) + ", L1Cache, forwardRequestNetwork_in]");
    (*m_responseToCache_ptr).setConsumer(this);
    (*m_responseToCache_ptr).setDescription("[Version " + to_string(m_version) + ", L1Cache, responseNetwork_in]");
    (*m_mandatoryQueue_ptr).setConsumer(this);
    (*m_mandatoryQueue_ptr).setDescription("[Version " + to_string(m_version) + ", L1Cache, mandatoryQueue_in]");

    possibleTransition(L1Cache_State_MI, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Store);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Load);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Ifetch);
    possibleTransition(L1Cache_State_IS, L1Cache_Event_Data);
    possibleTransition(L1Cache_State_IM, L1Cache_Event_Data);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_I, L1Cache_Event_Replacement);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Replacement);
    possibleTransition(L1Cache_State_M, L1Cache_Event_Inv);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Writeback_Ack);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_MI, L1Cache_Event_Writeback_Nack);
    possibleTransition(L1Cache_State_MII, L1Cache_Event_Fwd_GETX);
    possibleTransition(L1Cache_State_II, L1Cache_Event_Writeback_Nack);
    AbstractController::init();
    resetStats();
}

void
L1Cache_Controller::regStats()
{
    AbstractController::regStats();

    if (m_version == 0) {
        for (L1Cache_Event event = L1Cache_Event_FIRST;
             event < L1Cache_Event_NUM; ++event) {
            Stats::Vector *t = new Stats::Vector();
            t->init(m_num_controllers);
            t->name(g_system_ptr->name() + ".L1Cache_Controller." +
                L1Cache_Event_to_string(event));
            t->flags(Stats::pdf | Stats::total | Stats::oneline |
                     Stats::nozero);

            eventVec.push_back(t);
        }

        for (L1Cache_State state = L1Cache_State_FIRST;
             state < L1Cache_State_NUM; ++state) {

            transVec.push_back(std::vector<Stats::Vector *>());

            for (L1Cache_Event event = L1Cache_Event_FIRST;
                 event < L1Cache_Event_NUM; ++event) {

                Stats::Vector *t = new Stats::Vector();
                t->init(m_num_controllers);
                t->name(g_system_ptr->name() + ".L1Cache_Controller." +
                        L1Cache_State_to_string(state) +
                        "." + L1Cache_Event_to_string(event));

                t->flags(Stats::pdf | Stats::total | Stats::oneline |
                         Stats::nozero);
                transVec[state].push_back(t);
            }
        }
    }
}

void
L1Cache_Controller::collateStats()
{
    for (L1Cache_Event event = L1Cache_Event_FIRST;
         event < L1Cache_Event_NUM; ++event) {
        for (unsigned int i = 0; i < m_num_controllers; ++i) {
            std::map<uint32_t, AbstractController *>::iterator it =
                                g_abs_controls[MachineType_L1Cache].find(i);
            assert(it != g_abs_controls[MachineType_L1Cache].end());
            (*eventVec[event])[i] =
                ((L1Cache_Controller *)(*it).second)->getEventCount(event);
        }
    }

    for (L1Cache_State state = L1Cache_State_FIRST;
         state < L1Cache_State_NUM; ++state) {

        for (L1Cache_Event event = L1Cache_Event_FIRST;
             event < L1Cache_Event_NUM; ++event) {

            for (unsigned int i = 0; i < m_num_controllers; ++i) {
                std::map<uint32_t, AbstractController *>::iterator it =
                                g_abs_controls[MachineType_L1Cache].find(i);
                assert(it != g_abs_controls[MachineType_L1Cache].end());
                (*transVec[state][event])[i] =
                    ((L1Cache_Controller *)(*it).second)->getTransitionCount(state, event);
            }
        }
    }
}

void
L1Cache_Controller::countTransition(L1Cache_State state, L1Cache_Event event)
{
    assert(m_possible[state][event]);
    m_counters[state][event]++;
    m_event_counters[event]++;
}
void
L1Cache_Controller::possibleTransition(L1Cache_State state,
                             L1Cache_Event event)
{
    m_possible[state][event] = true;
}

uint64
L1Cache_Controller::getEventCount(L1Cache_Event event)
{
    return m_event_counters[event];
}

bool
L1Cache_Controller::isPossible(L1Cache_State state, L1Cache_Event event)
{
    return m_possible[state][event];
}

uint64
L1Cache_Controller::getTransitionCount(L1Cache_State state,
                             L1Cache_Event event)
{
    return m_counters[state][event];
}

int
L1Cache_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
L1Cache_Controller::getMandatoryQueue() const
{
    return m_mandatoryQueue_ptr;
}

Sequencer*
L1Cache_Controller::getSequencer() const
{
    return m_sequencer_ptr;
}

void
L1Cache_Controller::print(ostream& out) const
{
    out << "[L1Cache_Controller " << m_version << "]";
}

void L1Cache_Controller::resetStats()
{
    for (int state = 0; state < L1Cache_State_NUM; state++) {
        for (int event = 0; event < L1Cache_Event_NUM; event++) {
            m_counters[state][event] = 0;
        }
    }

    for (int event = 0; event < L1Cache_Event_NUM; event++) {
        m_event_counters[event] = 0;
    }

    AbstractController::resetStats();
}

// Set and Reset for cache_entry variable
void
L1Cache_Controller::set_cache_entry(L1Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry)
{
  m_cache_entry_ptr = (L1Cache_Entry*)m_new_cache_entry;
}

void
L1Cache_Controller::unset_cache_entry(L1Cache_Entry*& m_cache_entry_ptr)
{
  m_cache_entry_ptr = 0;
}

// Set and Reset for tbe variable
void
L1Cache_Controller::set_tbe(L1Cache_TBE*& m_tbe_ptr, L1Cache_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
L1Cache_Controller::unset_tbe(L1Cache_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
L1Cache_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
    m_cacheMemory_ptr->recordCacheContents(cntrl, tr);
}

// Actions
/** \brief Issue a request */
void
L1Cache_Controller::a_issueRequest(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing a_issueRequest\n");
    {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_GETX;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((map_Address_to_Directory(addr))));
    (*out_msg).m_MessageSize = MessageSizeType_Control;
    ((*m_requestFromCache_ptr)).enqueue(out_msg, Cycles(m_issue_latency));
}

}

/** \brief Issue a PUT request */
void
L1Cache_Controller::b_issuePUT(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing b_issuePUT\n");
    {
    std::shared_ptr<RequestMsg> out_msg = std::make_shared<RequestMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MI_example-cache.sm:281: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceRequestType_PUTX;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add((map_Address_to_Directory(addr))));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Data;
    ((*m_requestFromCache_ptr)).enqueue(out_msg, Cycles(m_issue_latency));
}

}

/** \brief Send data from cache to requestor */
void
L1Cache_Controller::e_sendData(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing e_sendData\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_forwardToCache_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_cache_entry_ptr != NULL))) {
        panic("Runtime Error at MI_example-cache.sm:294: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromCache_ptr)).enqueue(out_msg, Cycles(m_cache_response_latency));
}
}

}

/** \brief Send data from TBE to requestor */
void
L1Cache_Controller::ee_sendDataFromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing ee_sendDataFromTBE\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_forwardToCache_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    std::shared_ptr<ResponseMsg> out_msg = std::make_shared<ResponseMsg>(clockEdge());
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        panic("Runtime Error at MI_example-cache.sm:308: %s.\n", "assert failure");

    }
    #endif
    ;
    (*out_msg).m_Addr = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*m_tbe_ptr).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    ((*m_responseFromCache_ptr)).enqueue(out_msg, Cycles(m_cache_response_latency));
}
}

}

/** \brief Allocate a cache block */
void
L1Cache_Controller::i_allocateL1CacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing i_allocateL1CacheBlock\n");
        if ((m_cache_entry_ptr != NULL)) {
    } else {
        set_cache_entry(m_cache_entry_ptr, (((*m_cacheMemory_ptr)).allocate(addr, new L1Cache_Entry)));;
    }

}

/** \brief deallocate a cache block */
void
L1Cache_Controller::h_deallocateL1CacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing h_deallocateL1CacheBlock\n");
        if ((m_cache_entry_ptr != NULL)) {
        (((*m_cacheMemory_ptr)).deallocate(addr));
        unset_cache_entry(m_cache_entry_ptr);;
    }

}

/** \brief Pop the mandatory request queue */
void
L1Cache_Controller::m_popMandatoryQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing m_popMandatoryQueue\n");
    (((*m_mandatoryQueue_ptr)).dequeue());

}

/** \brief Pop the response queue */
void
L1Cache_Controller::n_popResponseQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing n_popResponseQueue\n");
    (profileMsgDelay((1), (((*m_responseToCache_ptr)).dequeue())));

}

/** \brief Pop the forwarded request queue */
void
L1Cache_Controller::o_popForwardedRequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing o_popForwardedRequestQueue\n");
    (profileMsgDelay((2), (((*m_forwardToCache_ptr)).dequeue())));

}

/** \brief Profile cache miss */
void
L1Cache_Controller::p_profileMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing p_profileMiss\n");
    (++ ((*m_cacheMemory_ptr)).m_demand_misses);

}

/** \brief Profile cache miss */
void
L1Cache_Controller::p_profileHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing p_profileHit\n");
    (++ ((*m_cacheMemory_ptr)).m_demand_hits);

}

/** \brief Notify sequencer the load completed. */
void
L1Cache_Controller::r_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing r_load_hit\n");
    #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:354: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MI_example-cache.sm:355: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (false)));

}

/** \brief External load completed. */
void
L1Cache_Controller::rx_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing rx_load_hit\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToCache_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:361: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MI_example-cache.sm:362: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_sequencer_ptr)).readCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true), (machineIDToMachineType(((*in_msg_ptr)).m_Sender))));
}

}

/** \brief Notify sequencer that store completed. */
void
L1Cache_Controller::s_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing s_store_hit\n");
    #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:369: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MI_example-cache.sm:370: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_sequencer_ptr)).writeCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (false)));

}

/** \brief External store completed. */
void
L1Cache_Controller::sx_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing sx_store_hit\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToCache_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:376: %s.\n", "assert failure");

}
#endif
;
DPRINTF(RubySlicc, "MI_example-cache.sm:377: %s\n", (*m_cache_entry_ptr).m_DataBlk);
(((*m_sequencer_ptr)).writeCallback(addr, (*m_cache_entry_ptr).m_DataBlk, (true), (machineIDToMachineType(((*in_msg_ptr)).m_Sender))));
}

}

/** \brief Write data to the cache */
void
L1Cache_Controller::u_writeDataToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing u_writeDataToCache\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToCache_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
#ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:385: %s.\n", "assert failure");

}
#endif
;
(*m_cache_entry_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

}

/** \brief sends eviction information to the processor */
void
L1Cache_Controller::forward_eviction_to_cpu(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing forward_eviction_to_cpu\n");
        if (m_send_evictions) {
        DPRINTF(RubySlicc, "MI_example-cache.sm:392: Sending invalidation for %s to the CPU\n", addr);
        (((*m_sequencer_ptr)).evictionCallback(addr));
    }

}

/** \brief Allocate TBE */
void
L1Cache_Controller::v_allocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing v_allocateTBE\n");
    (((*m_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_TBEs_ptr)).lookup(addr)));;

}

/** \brief Deallocate TBE */
void
L1Cache_Controller::w_deallocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing w_deallocateTBE\n");
    (((*m_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

}

/** \brief Copy data from cache to TBE */
void
L1Cache_Controller::x_copyDataFromCacheToTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing x_copyDataFromCacheToTBE\n");
    #ifndef NDEBUG
if (!((m_cache_entry_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:408: %s.\n", "assert failure");

}
#endif
;
#ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    panic("Runtime Error at MI_example-cache.sm:409: %s.\n", "assert failure");

}
#endif
;
(*m_tbe_ptr).m_DataBlk = (*m_cache_entry_ptr).m_DataBlk;

}

/** \brief stall */
void
L1Cache_Controller::z_stall(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing z_stall\n");
    
}

L1Cache_Entry*
L1Cache_Controller::getCacheEntry(const Address& param_address)
{
return static_cast<L1Cache_Entry *>((((*m_cacheMemory_ptr)).lookup(param_address)));

}
L1Cache_Event
L1Cache_Controller::mandatory_request_type_to_event(const RubyRequestType& param_type)
{
    if ((param_type == RubyRequestType_LD)) {
        return L1Cache_Event_Load;
    } else {
            if ((param_type == RubyRequestType_IFETCH)) {
                return L1Cache_Event_Ifetch;
            } else {
                    if (((param_type == RubyRequestType_ST) || (param_type == RubyRequestType_ATOMIC))) {
                        return L1Cache_Event_Store;
                    } else {
                        panic("Runtime Error at MI_example-cache.sm:126: %s.\n", ("Invalid RubyRequestType"));
                        ;
                    }
                }
            }

}
L1Cache_State
L1Cache_Controller::getState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Address& param_addr)
{
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((param_cache_entry != NULL)) {
                return (*param_cache_entry).m_CacheState;
            } else {
                return L1Cache_State_I;
            }
        }

}
void
L1Cache_Controller::setState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Address& param_addr, const L1Cache_State& param_state)
{
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((param_cache_entry != NULL)) {
            (*param_cache_entry).m_CacheState = param_state;
        }

}
AccessPermission
L1Cache_Controller::getAccessPermission(const Address& param_addr)
{
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        return (L1Cache_State_to_permission((*tbe).m_TBEState));
    }
    L1Cache_Entry* cache_entry
     = (getCacheEntry(param_addr));
        if ((cache_entry != NULL)) {
            return (L1Cache_State_to_permission((*cache_entry).m_CacheState));
        }
        return AccessPermission_NotPresent;

}
void
L1Cache_Controller::setAccessPermission(L1Cache_Entry* param_cache_entry, const Address& param_addr, const L1Cache_State& param_state)
{
    if ((param_cache_entry != NULL)) {
        ((*(param_cache_entry)).changePermission((L1Cache_State_to_permission(param_state))));
    }

}
void
L1Cache_Controller::functionalRead(const Address& param_addr, Packet* param_pkt)
{
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        (testAndRead(param_addr, (*tbe).m_DataBlk, param_pkt));
    } else {
        (testAndRead(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt));
    }

}
int
L1Cache_Controller::functionalWrite(const Address& param_addr, Packet* param_pkt)
{
int num_functional_writes
 = (0);
L1Cache_TBE* tbe
 = (((*m_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*tbe).m_DataBlk, param_pkt)));
        return num_functional_writes;
    }
    num_functional_writes = (num_functional_writes + (testAndWrite(param_addr, (*(getCacheEntry(param_addr))).m_DataBlk, param_pkt)));
    return num_functional_writes;

}
int
L1Cache_Controller::functionalWriteBuffers(PacketPtr& pkt)
{
    int num_functional_writes = 0;
num_functional_writes += m_mandatoryQueue_ptr->functionalWrite(pkt);
num_functional_writes += m_requestFromCache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseFromCache_ptr->functionalWrite(pkt);
num_functional_writes += m_forwardToCache_ptr->functionalWrite(pkt);
num_functional_writes += m_responseToCache_ptr->functionalWrite(pkt);
    return num_functional_writes;
}
