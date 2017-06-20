#ifndef __PARAMS__X86IntelMPAddrSpaceMapping__
#define __PARAMS__X86IntelMPAddrSpaceMapping__

namespace X86ISA {
namespace IntelMP {
class AddrSpaceMapping;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/X86IntelMPAddressType.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/X86IntelMPExtConfigEntry.hh"

#include "enums/X86IntelMPAddressType.hh"

struct X86IntelMPAddrSpaceMappingParams
    : public X86IntelMPExtConfigEntryParams
{
    X86ISA::IntelMP::AddrSpaceMapping * create();
    Addr address;
    Enums::X86IntelMPAddressType address_type;
    uint8_t bus_id;
    uint64_t length;
};

#endif // __PARAMS__X86IntelMPAddrSpaceMapping__
