#ifndef __PARAMS__BaseCache__
#define __PARAMS__BaseCache__

class BaseCache;

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/BasePrefetcher.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "params/BaseTags.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/MemObject.hh"

struct BaseCacheParams
    : public MemObjectParams
{
    BaseCache * create();
    std::vector< AddrRange > addr_ranges;
    unsigned assoc;
    unsigned demand_mshr_reserve;
    bool forward_snoops;
    Cycles hit_latency;
    bool is_top_level;
    Counter max_miss_count;
    unsigned mshrs;
    bool prefetch_on_access;
    BasePrefetcher * prefetcher;
    Cycles response_latency;
    bool sequential_access;
    uint64_t size;
    System * system;
    BaseTags * tags;
    unsigned tgts_per_mshr;
    unsigned write_buffers;
    unsigned int port_mem_side_connection_count;
    unsigned int port_cpu_side_connection_count;
};

#endif // __PARAMS__BaseCache__
