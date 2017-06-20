#ifndef __PARAMS__X86ACPIRSDP__
#define __PARAMS__X86ACPIRSDP__

namespace X86ISA {
namespace ACPI {
class RSDP;
} // namespace ACPI
} // namespace X86ISA

#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/X86ACPIRSDT.hh"
#include <cstddef>
#include "params/X86ACPIXSDT.hh"

#include "params/SimObject.hh"

struct X86ACPIRSDPParams
    : public SimObjectParams
{
    X86ISA::ACPI::RSDP * create();
    std::string oem_id;
    uint8_t revision;
    X86ISA::ACPI::RSDT * rsdt;
    X86ISA::ACPI::XSDT * xsdt;
};

#endif // __PARAMS__X86ACPIRSDP__
