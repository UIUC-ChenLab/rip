#ifndef __PARAMS__X86ACPIXSDT__
#define __PARAMS__X86ACPIXSDT__

namespace X86ISA {
namespace ACPI {
class XSDT;
} // namespace ACPI
} // namespace X86ISA

#include <vector>
#include "params/X86ACPISysDescTable.hh"

#include "params/X86ACPISysDescTable.hh"

struct X86ACPIXSDTParams
    : public X86ACPISysDescTableParams
{
    X86ISA::ACPI::XSDT * create();
    std::vector< X86ISA::ACPI::SysDescTable * > entries;
};

#endif // __PARAMS__X86ACPIXSDT__
