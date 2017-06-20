#ifndef __PARAMS__X86IntelMPBusHierarchy__
#define __PARAMS__X86IntelMPBusHierarchy__

namespace X86ISA {
namespace IntelMP {
class BusHierarchy;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/X86IntelMPExtConfigEntry.hh"

struct X86IntelMPBusHierarchyParams
    : public X86IntelMPExtConfigEntryParams
{
    X86ISA::IntelMP::BusHierarchy * create();
    uint8_t bus_id;
    uint8_t parent_bus;
    bool subtractive_decode;
};

#endif // __PARAMS__X86IntelMPBusHierarchy__
