#ifndef __PARAMS__X86IntelMPCompatAddrSpaceMod__
#define __PARAMS__X86IntelMPCompatAddrSpaceMod__

namespace X86ISA {
namespace IntelMP {
class CompatAddrSpaceMod;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/X86IntelMPRangeList.hh"

#include "params/X86IntelMPExtConfigEntry.hh"

#include "enums/X86IntelMPRangeList.hh"

struct X86IntelMPCompatAddrSpaceModParams
    : public X86IntelMPExtConfigEntryParams
{
    X86ISA::IntelMP::CompatAddrSpaceMod * create();
    bool add;
    uint8_t bus_id;
    Enums::X86IntelMPRangeList range_list;
};

#endif // __PARAMS__X86IntelMPCompatAddrSpaceMod__
