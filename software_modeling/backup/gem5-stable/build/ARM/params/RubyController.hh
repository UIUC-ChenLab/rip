#ifndef __PARAMS__RubyController__
#define __PARAMS__RubyController__

class AbstractController;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/RubySystem.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct RubyControllerParams
    : public MemObjectParams
{
    uint32_t buffer_size;
    uint32_t cluster_id;
    int number_of_TBEs;
    Cycles recycle_latency;
    RubySystem * ruby_system;
    System * system;
    int transitions_per_cycle;
    int version;
    unsigned int port_memory_connection_count;
};

#endif // __PARAMS__RubyController__
