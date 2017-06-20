#ifndef __PARAMS__X86ACPIRSDT__
#define __PARAMS__X86ACPIRSDT__

namespace X86ISA {
namespace ACPI {
class RSDT;
} // namespace ACPI
} // namespace X86ISA

#include <vector>
#include "params/X86ACPISysDescTable.hh"

#include "params/X86ACPISysDescTable.hh"

struct X86ACPIRSDTParams
    : public X86ACPISysDescTableParams
{
    X86ISA::ACPI::RSDT * create();
    std::vector< X86ISA::ACPI::SysDescTable * > entries;
};

#endif // __PARAMS__X86ACPIRSDT__
