#ifndef __PARAMS__DMA_Controller__
#define __PARAMS__DMA_Controller__

class DMA_Controller;

#include <cstddef>
#include "params/DMASequencer.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/RubyController.hh"

struct DMA_ControllerParams
    : public RubyControllerParams
{
    DMA_Controller * create();
    DMASequencer * dma_sequencer;
    Cycles request_latency;
    unsigned int port_requestToDir_connection_count;
    unsigned int port_responseFromDir_connection_count;
};

#endif // __PARAMS__DMA_Controller__
