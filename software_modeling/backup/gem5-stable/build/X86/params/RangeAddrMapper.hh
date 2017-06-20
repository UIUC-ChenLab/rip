#ifndef __PARAMS__RangeAddrMapper__
#define __PARAMS__RangeAddrMapper__

class RangeAddrMapper;

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"

#include "params/AddrMapper.hh"

struct RangeAddrMapperParams
    : public AddrMapperParams
{
    RangeAddrMapper * create();
    std::vector< AddrRange > original_ranges;
    std::vector< AddrRange > remapped_ranges;
};

#endif // __PARAMS__RangeAddrMapper__
