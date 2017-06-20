/** \file L1Cache_Controller.hh
 *
 * Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/StateMachine.py:256
 * Created by slicc definition of Module "MI Example L1 Cache"
 */

#ifndef __L1Cache_CONTROLLER_HH__
#define __L1Cache_CONTROLLER_HH__

#include <iostream>
#include <sstream>
#include <string>

#include "mem/protocol/TransitionResult.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "params/L1Cache_Controller.hh"
#include "mem/protocol/MessageBuffer.hh"
#include "mem/protocol/TBETable.hh"
extern std::stringstream L1Cache_transitionComment;

class L1Cache_Controller : public AbstractController
{
  public:
    typedef L1Cache_ControllerParams Params;
    L1Cache_Controller(const Params *p);
    static int getNumControllers();
    void init();

    MessageBuffer* getMandatoryQueue() const;
    void setNetQueue(const std::string& name, MessageBuffer *b);

    void print(std::ostream& out) const;
    void wakeup();
    void resetStats();
    void regStats();
    void collateStats();

    void recordCacheTrace(int cntrl, CacheRecorder* tr);
    Sequencer* getSequencer() const;

    int functionalWriteBuffers(PacketPtr&);

    void countTransition(L1Cache_State state, L1Cache_Event event);
    void possibleTransition(L1Cache_State state, L1Cache_Event event);
    uint64 getEventCount(L1Cache_Event event);
    bool isPossible(L1Cache_State state, L1Cache_Event event);
    uint64 getTransitionCount(L1Cache_State state, L1Cache_Event event);

private:
    Sequencer* m_sequencer_ptr;
    CacheMemory* m_cacheMemory_ptr;
    Cycles m_cache_response_latency;
    Cycles m_issue_latency;
    bool m_send_evictions;
    MessageBuffer* m_requestFromCache_ptr;
    MessageBuffer* m_responseFromCache_ptr;
    MessageBuffer* m_forwardToCache_ptr;
    MessageBuffer* m_responseToCache_ptr;
    TransitionResult doTransition(L1Cache_Event event,
                                  L1Cache_Entry* m_cache_entry_ptr,
                                  L1Cache_TBE* m_tbe_ptr,
                                  const Address addr);

    TransitionResult doTransitionWorker(L1Cache_Event event,
                                        L1Cache_State state,
                                        L1Cache_State& next_state,
                                        L1Cache_TBE*& m_tbe_ptr,
                                        L1Cache_Entry*& m_cache_entry_ptr,
                                        const Address& addr);

    int m_counters[L1Cache_State_NUM][L1Cache_Event_NUM];
    int m_event_counters[L1Cache_Event_NUM];
    bool m_possible[L1Cache_State_NUM][L1Cache_Event_NUM];

    static std::vector<Stats::Vector *> eventVec;
    static std::vector<std::vector<Stats::Vector *> > transVec;
    static int m_num_controllers;

    // Internal functions
    L1Cache_Entry* getCacheEntry(const Address& param_address);
    L1Cache_Event mandatory_request_type_to_event(const RubyRequestType& param_type);
    L1Cache_State getState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Address& param_addr);
    void setState(L1Cache_TBE* param_tbe, L1Cache_Entry* param_cache_entry, const Address& param_addr, const L1Cache_State& param_state);
    AccessPermission getAccessPermission(const Address& param_addr);
    void setAccessPermission(L1Cache_Entry* param_cache_entry, const Address& param_addr, const L1Cache_State& param_state);
    void functionalRead(const Address& param_addr, Packet* param_pkt);
    int functionalWrite(const Address& param_addr, Packet* param_pkt);

    // Set and Reset for cache_entry variable
    void set_cache_entry(L1Cache_Entry*& m_cache_entry_ptr, AbstractCacheEntry* m_new_cache_entry);
    void unset_cache_entry(L1Cache_Entry*& m_cache_entry_ptr);

    // Set and Reset for tbe variable
    void set_tbe(L1Cache_TBE*& m_tbe_ptr, L1Cache_TBE* m_new_tbe);
    void unset_tbe(L1Cache_TBE*& m_tbe_ptr);

    // Actions
    /** \brief Issue a request */
    void a_issueRequest(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Issue a PUT request */
    void b_issuePUT(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Send data from cache to requestor */
    void e_sendData(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Send data from TBE to requestor */
    void ee_sendDataFromTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Allocate a cache block */
    void i_allocateL1CacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief deallocate a cache block */
    void h_deallocateL1CacheBlock(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Pop the mandatory request queue */
    void m_popMandatoryQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Pop the response queue */
    void n_popResponseQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Pop the forwarded request queue */
    void o_popForwardedRequestQueue(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Profile cache miss */
    void p_profileMiss(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Profile cache miss */
    void p_profileHit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Notify sequencer the load completed. */
    void r_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief External load completed. */
    void rx_load_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Notify sequencer that store completed. */
    void s_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief External store completed. */
    void sx_store_hit(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Write data to the cache */
    void u_writeDataToCache(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief sends eviction information to the processor */
    void forward_eviction_to_cpu(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Allocate TBE */
    void v_allocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Deallocate TBE */
    void w_deallocateTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief Copy data from cache to TBE */
    void x_copyDataFromCacheToTBE(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);
    /** \brief stall */
    void z_stall(L1Cache_TBE*& m_tbe_ptr, L1Cache_Entry*& m_cache_entry_ptr, const Address& addr);

    // Objects
    MessageBuffer* m_mandatoryQueue_ptr;
    TBETable<L1Cache_TBE>* m_TBEs_ptr;
};
#endif // __L1Cache_CONTROLLER_H__
