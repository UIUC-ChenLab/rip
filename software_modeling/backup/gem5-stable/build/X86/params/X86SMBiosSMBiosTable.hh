#ifndef __PARAMS__X86SMBiosSMBiosTable__
#define __PARAMS__X86SMBiosSMBiosTable__

namespace X86ISA {
namespace SMBios {
class SMBiosTable;
} // namespace SMBios
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/X86SMBiosSMBiosStructure.hh"

#include "params/SimObject.hh"

struct X86SMBiosSMBiosTableParams
    : public SimObjectParams
{
    X86ISA::SMBios::SMBiosTable * create();
    uint8_t major_version;
    uint8_t minor_version;
    std::vector< X86ISA::SMBios::SMBiosStructure * > structures;
};

#endif // __PARAMS__X86SMBiosSMBiosTable__
