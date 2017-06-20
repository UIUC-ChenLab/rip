#ifndef __PARAMS__QueuedPrefetcher__
#define __PARAMS__QueuedPrefetcher__

class QueuedPrefetcher;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>

#include "params/BasePrefetcher.hh"

struct QueuedPrefetcherParams
    : public BasePrefetcherParams
{
    bool cache_snoop;
    int latency;
    bool queue_filter;
    int queue_size;
    bool queue_squash;
    bool tag_prefetch;
};

#endif // __PARAMS__QueuedPrefetcher__
