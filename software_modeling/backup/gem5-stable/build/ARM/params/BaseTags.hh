#ifndef __PARAMS__BaseTags__
#define __PARAMS__BaseTags__

class BaseTags;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

struct BaseTagsParams
    : public ClockedObjectParams
{
    int block_size;
    Cycles hit_latency;
    uint64_t size;
};

#endif // __PARAMS__BaseTags__
