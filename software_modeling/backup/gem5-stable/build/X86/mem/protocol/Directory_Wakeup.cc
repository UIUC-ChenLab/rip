// Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/StateMachine.py:1040
// Directory: Directory protocol

#include <sys/types.h>
#include <unistd.h>

#include <cassert>

#include "base/misc.hh"
#include "debug/RubySlicc.hh"
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/Directory_Event.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"
#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;

void
Directory_Controller::wakeup()
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
            // DirectoryInPort dmaRequestQueue_in
            m_cur_in_port = 0;
                        if ((((*m_dmaRequestToDir_ptr)).isReady())) {
                            {
                                // Declare message
                                const DMARequestMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const DMARequestMsg *>(((*m_dmaRequestToDir_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                            Directory_TBE* tbe
                             = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress));
                                if ((((*in_msg_ptr)).m_Type == DMARequestType_READ)) {
                                    {

                                        TransitionResult result = doTransition(Directory_Event_DMA_READ, tbe, ((*in_msg_ptr)).m_LineAddress);

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
                                        if ((((*in_msg_ptr)).m_Type == DMARequestType_WRITE)) {
                                            {

                                                TransitionResult result = doTransition(Directory_Event_DMA_WRITE, tbe, ((*in_msg_ptr)).m_LineAddress);

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
                                            panic("Runtime Error at MI_example-dir.sm:214: %s.\n", ("Invalid message"));
                                            ;
                                        }
                                    }
                                    }
                                }
            // DirectoryInPort requestQueue_in
            m_cur_in_port = 0;
                        if ((((*m_requestToDir_ptr)).isReady())) {
                            {
                                // Declare message
                                const RequestMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_requestToDir_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                            Directory_TBE* tbe
                             = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Addr));
                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS)) {
                                    {

                                        TransitionResult result = doTransition(Directory_Event_GETS, tbe, ((*in_msg_ptr)).m_Addr);

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
                                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETX)) {
                                            {

                                                TransitionResult result = doTransition(Directory_Event_GETX, tbe, ((*in_msg_ptr)).m_Addr);

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
                                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_PUTX)) {
                                                        if ((((*(getDirectoryEntry(((*in_msg_ptr)).m_Addr))).m_Owner).isElement(((*in_msg_ptr)).m_Requestor))) {
                                                            {

                                                                TransitionResult result = doTransition(Directory_Event_PUTX, tbe, ((*in_msg_ptr)).m_Addr);

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

                                                                TransitionResult result = doTransition(Directory_Event_PUTX_NotOwner, tbe, ((*in_msg_ptr)).m_Addr);

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
                                                    } else {
                                                        panic("Runtime Error at MI_example-dir.sm:235: %s.\n", ("Invalid message"));
                                                        ;
                                                    }
                                                }
                                            }
                                            }
                                        }
            // DirectoryInPort memQueue_in
            m_cur_in_port = 0;
                        if ((((*m_responseFromMemory_ptr)).isReady())) {
                            {
                                // Declare message
                                const MemoryMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_responseFromMemory_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                            Directory_TBE* tbe
                             = (((*m_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Addr));
                                if ((((*in_msg_ptr)).m_Type == MemoryRequestType_MEMORY_READ)) {
                                    {

                                        TransitionResult result = doTransition(Directory_Event_Memory_Data, tbe, ((*in_msg_ptr)).m_Addr);

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
                                        if ((((*in_msg_ptr)).m_Type == MemoryRequestType_MEMORY_WB)) {
                                            {

                                                TransitionResult result = doTransition(Directory_Event_Memory_Ack, tbe, ((*in_msg_ptr)).m_Addr);

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
                                            DPRINTF(RubySlicc, "MI_example-dir.sm:252: %s\n", ((*in_msg_ptr)).m_Type);
                                            panic("Runtime Error at MI_example-dir.sm:253: %s.\n", ("Invalid message"));
                                            ;
                                        }
                                    }
                                    }
                                }
        break;  // If we got this far, we have nothing left todo
    }
}
