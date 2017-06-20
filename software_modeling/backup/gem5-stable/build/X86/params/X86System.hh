#ifndef __PARAMS__X86System__
#define __PARAMS__X86System__

class X86System;

#include <cstddef>
#include "params/X86ACPIRSDP.hh"
#include <cstddef>
#include "params/X86IntelMPFloatingPointer.hh"
#include <cstddef>
#include "params/X86IntelMPConfigTable.hh"
#include <cstddef>
#include "params/X86SMBiosSMBiosTable.hh"

#include "params/System.hh"

struct X86SystemParams
    : public SystemParams
{
    X86System * create();
    X86ISA::ACPI::RSDP * acpi_description_table_pointer;
    X86ISA::IntelMP::FloatingPointer * intel_mp_pointer;
    X86ISA::IntelMP::ConfigTable * intel_mp_table;
    X86ISA::SMBios::SMBiosTable * smbios_table;
};

#endif // __PARAMS__X86System__
