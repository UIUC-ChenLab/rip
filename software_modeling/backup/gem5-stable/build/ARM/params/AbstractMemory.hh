#ifndef __PARAMS__AbstractMemory__
#define __PARAMS__AbstractMemory__

class AbstractMemory;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include "base/addr_range.hh"

#include "params/MemObject.hh"

struct AbstractMemoryParams
    : public MemObjectParams
{
    bool conf_table_reported;
    bool in_addr_map;
    bool null;
    AddrRange range;
};

#endif // __PARAMS__AbstractMemory__
