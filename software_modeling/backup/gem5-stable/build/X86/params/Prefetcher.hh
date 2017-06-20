#ifndef __PARAMS__Prefetcher__
#define __PARAMS__Prefetcher__

class Prefetcher;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct PrefetcherParams
    : public SimObjectParams
{
    Prefetcher * create();
    bool cross_page;
    uint32_t nonunit_filter;
    uint32_t num_startup_pfs;
    uint32_t num_streams;
    uint32_t pf_per_stream;
    System * sys;
    uint32_t train_misses;
    uint32_t unit_filter;
};

#endif // __PARAMS__Prefetcher__
