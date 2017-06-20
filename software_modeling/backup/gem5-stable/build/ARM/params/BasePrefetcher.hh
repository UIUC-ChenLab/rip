#ifndef __PARAMS__BasePrefetcher__
#define __PARAMS__BasePrefetcher__

class BasePrefetcher;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "params/System.hh"

#include "params/ClockedObject.hh"

struct BasePrefetcherParams
    : public ClockedObjectParams
{
    bool on_data;
    bool on_inst;
    bool on_miss;
    bool on_read;
    bool on_write;
    System * sys;
};

#endif // __PARAMS__BasePrefetcher__
