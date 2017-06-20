from m5.params import *
from m5.SimObject import SimObject
from Controller import RubyController

class L1Cache_Controller(RubyController):
    type = 'L1Cache_Controller'
    cxx_header = 'mem/protocol/L1Cache_Controller.hh'
    sequencer = Param.RubySequencer("")
    cacheMemory = Param.RubyCache("")
    cache_response_latency = Param.Cycles((12), "")
    issue_latency = Param.Cycles((2), "")
    send_evictions = Param.Bool("")
    requestFromCache = MasterPort("")
    responseFromCache = MasterPort("")
    forwardToCache = SlavePort("")
    responseToCache = SlavePort("")
