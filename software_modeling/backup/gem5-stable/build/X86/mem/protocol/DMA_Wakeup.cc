// Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/StateMachine.py:1040
// DMA: DMA Controller

#include <sys/types.h>
#include <unistd.h>

#include <cassert>

#include "base/misc.hh"
#include "debug/RubySlicc.hh"
#include "mem/protocol/DMA_Controller.hh"
#include "mem/protocol/DMA_Event.hh"
#include "mem/protocol/DMA_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"
#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"

using namespace std;

void
DMA_Controller::wakeup()
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
            // DMAInPort dmaRequestQueue_in
            m_cur_in_port = 0;
                        if ((((*m_mandatoryQueue_ptr)).isReady())) {
                            {
                                // Declare message
                                const SequencerMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const SequencerMsg *>(((*m_mandatoryQueue_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                                if ((((*in_msg_ptr)).m_Type == SequencerRequestType_LD)) {
                                    {

                                        TransitionResult result = doTransition(DMA_Event_ReadRequest, ((*in_msg_ptr)).m_LineAddress);

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
                                        if ((((*in_msg_ptr)).m_Type == SequencerRequestType_ST)) {
                                            {

                                                TransitionResult result = doTransition(DMA_Event_WriteRequest, ((*in_msg_ptr)).m_LineAddress);

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
                                            panic("Runtime Error at MI_example-dma.sm:87: %s.\n", ("Invalid request type"));
                                            ;
                                        }
                                    }
                                    }
                                }
            // DMAInPort dmaResponseQueue_in
            m_cur_in_port = 0;
                        if ((((*m_responseFromDir_ptr)).isReady())) {
                            {
                                // Declare message
                                const DMAResponseMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const DMAResponseMsg *>(((*m_responseFromDir_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                                if ((((*in_msg_ptr)).m_Type == DMAResponseType_ACK)) {
                                    {

                                        TransitionResult result = doTransition(DMA_Event_Ack, ((*in_msg_ptr)).m_LineAddress);

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
                                        if ((((*in_msg_ptr)).m_Type == DMAResponseType_DATA)) {
                                            {

                                                TransitionResult result = doTransition(DMA_Event_Data, ((*in_msg_ptr)).m_LineAddress);

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
                                            panic("Runtime Error at MI_example-dma.sm:101: %s.\n", ("Invalid response type"));
                                            ;
                                        }
                                    }
                                    }
                                }
        break;  // If we got this far, we have nothing left todo
    }
}
