#ifndef __PARAMS__L1Cache_Controller__
#define __PARAMS__L1Cache_Controller__

class L1Cache_Controller;

#include <cstddef>
#include "params/RubyCache.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/RubySequencer.hh"

#include "params/RubyController.hh"

struct L1Cache_ControllerParams
    : public RubyControllerParams
{
    L1Cache_Controller * create();
    CacheMemory * cacheMemory;
    Cycles cache_response_latency;
    Cycles issue_latency;
    bool send_evictions;
    Sequencer * sequencer;
    unsigned int port_responseFromCache_connection_count;
    unsigned int port_requestFromCache_connection_count;
    unsigned int port_forwardToCache_connection_count;
    unsigned int port_responseToCache_connection_count;
};

#endif // __PARAMS__L1Cache_Controller__
