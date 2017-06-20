// Auto generated C++ code started by /home/kemmere2/gem5/gem5-stable/src/mem/slicc/symbols/StateMachine.py:1133
// Directory: Directory protocol

#include <cassert>

#include "base/misc.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/Directory_Event.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"

#define HASH_FUN(state, event)  ((int(state)*Directory_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (Directory_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (Directory_transitionComment.str(""))

TransitionResult
Directory_Controller::doTransition(Directory_Event event,
                                  Directory_TBE* m_tbe_ptr,
                                  const Address addr)
{
    Directory_State state = getState(m_tbe_ptr, addr);
    Directory_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %s\n",
            *this, curCycle(), Directory_State_to_string(state),
            Directory_Event_to_string(event), addr);

    TransitionResult result =
    doTransitionWorker(event, state, next_state, m_tbe_ptr, addr);

    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                Directory_State_to_string(next_state));
        countTransition(state, event);

        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 addr, GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
    setState(m_tbe_ptr, addr, next_state);
    setAccessPermission(addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 addr, "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 addr, "Protocol Stall");
    }

    return result;
}

TransitionResult
Directory_Controller::doTransitionWorker(Directory_Event event,
                                        Directory_State state,
                                        Directory_State& next_state,
                                        Directory_TBE*& m_tbe_ptr,
                                        const Address& addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(Directory_State_M_DRD, Directory_Event_GETX):
  case HASH_FUN(Directory_State_M_DWR, Directory_Event_GETX):
  case HASH_FUN(Directory_State_M_DWRI, Directory_Event_GETX):
  case HASH_FUN(Directory_State_M_DRDI, Directory_Event_GETX):
  case HASH_FUN(Directory_State_IM, Directory_Event_GETX):
  case HASH_FUN(Directory_State_IM, Directory_Event_GETS):
  case HASH_FUN(Directory_State_IM, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_IM, Directory_Event_PUTX_NotOwner):
  case HASH_FUN(Directory_State_MI, Directory_Event_GETX):
  case HASH_FUN(Directory_State_MI, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MI, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_MI, Directory_Event_PUTX_NotOwner):
  case HASH_FUN(Directory_State_ID, Directory_Event_GETX):
  case HASH_FUN(Directory_State_ID, Directory_Event_GETS):
  case HASH_FUN(Directory_State_ID, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_ID, Directory_Event_PUTX_NotOwner):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_GETX):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_GETS):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_PUTX):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_PUTX_NotOwner):
    z_recycleRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_IM, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_IM, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_MI, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_MI, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_ID, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_ID, Directory_Event_DMA_WRITE):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_DMA_READ):
  case HASH_FUN(Directory_State_ID_W, Directory_Event_DMA_WRITE):
    y_recycleDMARequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_GETX):
    next_state = Directory_State_IM;
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    e_ownerIsRequestor(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_IM, Directory_Event_Memory_Data):
    next_state = Directory_State_M;
    if (!(*m_responseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    d_sendData(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_DMA_READ):
    next_state = Directory_State_ID;
    r_allocateTbeForDmaRead(m_tbe_ptr, addr);
    qf_queueMemoryFetchRequestDMA(m_tbe_ptr, addr);
    p_popIncomingDMARequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_ID, Directory_Event_Memory_Data):
    next_state = Directory_State_I;
    if (!(*m_dmaResponseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    dr_sendDMAData(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_I, Directory_Event_DMA_WRITE):
    next_state = Directory_State_ID_W;
    v_allocateTBE(m_tbe_ptr, addr);
    qw_queueMemoryWBRequest_partial(m_tbe_ptr, addr);
    p_popIncomingDMARequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_ID_W, Directory_Event_Memory_Ack):
    next_state = Directory_State_I;
    if (!(*m_dmaResponseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    da_sendDMAAck(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_DMA_READ):
    next_state = Directory_State_M_DRD;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    v_allocateTBE(m_tbe_ptr, addr);
    inv_sendCacheInvalidate(m_tbe_ptr, addr);
    p_popIncomingDMARequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M_DRD, Directory_Event_PUTX):
    next_state = Directory_State_M_DRDI;
    if (!(*m_dmaResponseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    drp_sendDMAData(m_tbe_ptr, addr);
    c_clearOwner(m_tbe_ptr, addr);
    l_queueMemoryWBRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M_DRDI, Directory_Event_Memory_Ack):
  case HASH_FUN(Directory_State_MI, Directory_Event_Memory_Ack):
    next_state = Directory_State_I;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    l_sendWriteBackAck(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_DMA_WRITE):
    next_state = Directory_State_M_DWR;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    v_allocateTBE(m_tbe_ptr, addr);
    inv_sendCacheInvalidate(m_tbe_ptr, addr);
    p_popIncomingDMARequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M_DWR, Directory_Event_PUTX):
    next_state = Directory_State_M_DWRI;
    qw_queueMemoryWBRequest_partialTBE(m_tbe_ptr, addr);
    c_clearOwner(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M_DWRI, Directory_Event_Memory_Ack):
    next_state = Directory_State_I;
    if (!(*m_dmaResponseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    l_sendWriteBackAck(m_tbe_ptr, addr);
    da_sendDMAAck(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    l_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_GETX):
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    e_ownerIsRequestor(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_PUTX):
    next_state = Directory_State_MI;
    c_clearOwner(m_tbe_ptr, addr);
    v_allocateTBEFromRequestNet(m_tbe_ptr, addr);
    l_queueMemoryWBRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

  case HASH_FUN(Directory_State_M, Directory_Event_PUTX_NotOwner):
  case HASH_FUN(Directory_State_I, Directory_Event_PUTX_NotOwner):
    if (!(*m_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    b_sendWriteBackNack(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;

      default:
        fatal("Invalid transition\n"
              "%s time: %d addr: %s event: %s state: %s\n",
              name(), curCycle(), addr, event, state);
    }

    return TransitionResult_Valid;
}
