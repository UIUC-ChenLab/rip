#ifndef __PARAMS__RubyMemoryControl__
#define __PARAMS__RubyMemoryControl__

class RubyMemoryControl;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/AbstractMemory.hh"

struct RubyMemoryControlParams
    : public AbstractMemoryParams
{
    RubyMemoryControl * create();
    int bank_bit_0;
    int bank_busy_time;
    int bank_queue_size;
    int banks_per_rank;
    int basic_bus_busy_time;
    int dimm_bit_0;
    int dimms_per_channel;
    Cycles mem_ctl_latency;
    Cycles mem_fixed_delay;
    int mem_random_arbitrate;
    int rank_bit_0;
    int rank_rank_delay;
    int ranks_per_dimm;
    int read_write_delay;
    Cycles refresh_period;
    int tFaw;
    unsigned int port_port_connection_count;
};

#endif // __PARAMS__RubyMemoryControl__
