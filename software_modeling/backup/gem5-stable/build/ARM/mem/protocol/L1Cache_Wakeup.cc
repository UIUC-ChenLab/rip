// Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/StateMachine.py:1040
// L1Cache: MI Example L1 Cache

#include <sys/types.h>
#include <unistd.h>

#include <cassert>

#include "base/misc.hh"
#include "debug/RubySlicc.hh"
#include "mem/protocol/L1Cache_Controller.hh"
#include "mem/protocol/L1Cache_Event.hh"
#include "mem/protocol/L1Cache_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"
#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;

void
L1Cache_Controller::wakeup()
{
    int counter = 0;
    while (true) {
        // Some cases will put us into an infinite loop without this limit
        assert(counter <= m_transitions_per_cycle);
        if (counter == m_transitions_per_cycle) {
            // Count how often we are fully utilized
            m_fully_busy_cycles++;

            // Wakeup in another cycle and try again
            scheduleEvent(Cycles(1));
            break;
        }
            // L1CacheInPort forwardRequestNetwork_in
            m_cur_in_port = 0;
                        if ((((*m_forwardToCache_ptr)).isReady())) {
                            {
                                // Declare message
                                const RequestMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_forwardToCache_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                                if (m_is_blocking &&
                                    (m_block_map.count(in_msg_ptr->m_Addr) == 1) &&
                                    (m_block_map[in_msg_ptr->m_Addr] != &(*m_forwardToCache_ptr))) {
                                        (*m_forwardToCache_ptr).delayHead();
                                        continue;
                                }
                                        
                            L1Cache_Entry* cache_entry
                             = (getCacheEntry(((*in_msg_ptr)).m_Addr));
                            L1Cache_TBE* tbe
                             = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Addr));
                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX)) {
                                    {

                                        TransitionResult result = doTransition(L1Cache_Event_Fwd_GETX, cache_entry, tbe, ((*in_msg_ptr)).m_Addr);

                                        if (result == TransitionResult_Valid) {
                                            counter++;
                                            continue; // Check the first port again
                                        }

                                        if (result == TransitionResult_ResourceStall) {
                                            scheduleEvent(Cycles(1));

                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                        }
                                    }
                                    ;
                                } else {
                                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_WB_ACK)) {
                                            {

                                                TransitionResult result = doTransition(L1Cache_Event_Writeback_Ack, cache_entry, tbe, ((*in_msg_ptr)).m_Addr);

                                                if (result == TransitionResult_Valid) {
                                                    counter++;
                                                    continue; // Check the first port again
                                                }

                                                if (result == TransitionResult_ResourceStall) {
                                                    scheduleEvent(Cycles(1));

                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                }
                                            }
                                            ;
                                        } else {
                                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_WB_NACK)) {
                                                    {

                                                        TransitionResult result = doTransition(L1Cache_Event_Writeback_Nack, cache_entry, tbe, ((*in_msg_ptr)).m_Addr);

                                                        if (result == TransitionResult_Valid) {
                                                            counter++;
                                                            continue; // Check the first port again
                                                        }

                                                        if (result == TransitionResult_ResourceStall) {
                                                            scheduleEvent(Cycles(1));

                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                        }
                                                    }
                                                    ;
                                                } else {
                                                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_INV)) {
                                                            {

                                                                TransitionResult result = doTransition(L1Cache_Event_Inv, cache_entry, tbe, ((*in_msg_ptr)).m_Addr);

                                                                if (result == TransitionResult_Valid) {
                                                                    counter++;
                                                                    continue; // Check the first port again
                                                                }

                                                                if (result == TransitionResult_ResourceStall) {
                                                                    scheduleEvent(Cycles(1));

                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                }
                                                            }
                                                            ;
                                                        } else {
                                                            panic("Runtime Error at MI_example-cache.sm:223: %s.\n", ("Unexpected message"));
                                                            ;
                                                        }
                                                    }
                                                }
                                            }
                                            }
                                        }
            // L1CacheInPort responseNetwork_in
            m_cur_in_port = 0;
                        if ((((*m_responseToCache_ptr)).isReady())) {
                            {
                                // Declare message
                                const ResponseMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_responseToCache_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                                if (m_is_blocking &&
                                    (m_block_map.count(in_msg_ptr->m_Addr) == 1) &&
                                    (m_block_map[in_msg_ptr->m_Addr] != &(*m_responseToCache_ptr))) {
                                        (*m_responseToCache_ptr).delayHead();
                                        continue;
                                }
                                        
                            L1Cache_Entry* cache_entry
                             = (getCacheEntry(((*in_msg_ptr)).m_Addr));
                            L1Cache_TBE* tbe
                             = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Addr));
                                if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA)) {
                                    {

                                        TransitionResult result = doTransition(L1Cache_Event_Data, cache_entry, tbe, ((*in_msg_ptr)).m_Addr);

                                        if (result == TransitionResult_Valid) {
                                            counter++;
                                            continue; // Check the first port again
                                        }

                                        if (result == TransitionResult_ResourceStall) {
                                            scheduleEvent(Cycles(1));

                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                        }
                                    }
                                    ;
                                } else {
                                    panic("Runtime Error at MI_example-cache.sm:240: %s.\n", ("Unexpected message"));
                                    ;
                                }
                                }
                            }
            // L1CacheInPort mandatoryQueue_in
            m_cur_in_port = 0;
                        if ((((*m_mandatoryQueue_ptr)).isReady())) {
                            {
                                // Declare message
                                const RubyRequest* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const RubyRequest *>(((*m_mandatoryQueue_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                                if (m_is_blocking &&
                                    (m_block_map.count(in_msg_ptr->m_LineAddress) == 1) &&
                                    (m_block_map[in_msg_ptr->m_LineAddress] != &(*m_mandatoryQueue_ptr))) {
                                        (*m_mandatoryQueue_ptr).delayHead();
                                        continue;
                                }
                                        
                            L1Cache_Entry* cache_entry
                             = (getCacheEntry(((*in_msg_ptr)).m_LineAddress));
                                if (((cache_entry == NULL) && ((((*m_cacheMemory_ptr)).cacheAvail(((*in_msg_ptr)).m_LineAddress)) == (false)))) {
                                    {

                                        TransitionResult result = doTransition(L1Cache_Event_Replacement, (getCacheEntry((((*m_cacheMemory_ptr)).cacheProbe(((*in_msg_ptr)).m_LineAddress)))), (((*m_TBEs_ptr)).lookup((((*m_cacheMemory_ptr)).cacheProbe(((*in_msg_ptr)).m_LineAddress)))), (((*m_cacheMemory_ptr)).cacheProbe(((*in_msg_ptr)).m_LineAddress)));

                                        if (result == TransitionResult_Valid) {
                                            counter++;
                                            continue; // Check the first port again
                                        }

                                        if (result == TransitionResult_ResourceStall) {
                                            scheduleEvent(Cycles(1));

                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                        }
                                    }
                                    ;
                                } else {
                                    {

                                        TransitionResult result = doTransition((mandatory_request_type_to_event(((*in_msg_ptr)).m_Type)), cache_entry, (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress)), ((*in_msg_ptr)).m_LineAddress);

                                        if (result == TransitionResult_Valid) {
                                            counter++;
                                            continue; // Check the first port again
                                        }

                                        if (result == TransitionResult_ResourceStall) {
                                            scheduleEvent(Cycles(1));

                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                        }
                                    }
                                    ;
                                }
                                }
                            }
        break;  // If we got this far, we have nothing left todo
    }
}
