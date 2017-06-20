from m5.params import *
from m5.SimObject import SimObject
from Controller import RubyController

class DMA_Controller(RubyController):
    type = 'DMA_Controller'
    cxx_header = 'mem/protocol/DMA_Controller.hh'
    dma_sequencer = Param.DMASequencer("")
    request_latency = Param.Cycles((6), "")
    responseFromDir = SlavePort("")
    requestToDir = MasterPort("")
