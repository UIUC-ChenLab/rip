#ifndef __PARAMS__X86ACPISysDescTable__
#define __PARAMS__X86ACPISysDescTable__

namespace X86ISA {
namespace ACPI {
class SysDescTable;
} // namespace ACPI
} // namespace X86ISA

#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>

#include "params/SimObject.hh"

struct X86ACPISysDescTableParams
    : public SimObjectParams
{
    std::string creator_id;
    uint32_t creator_revision;
    std::string oem_id;
    uint32_t oem_revision;
    std::string oem_table_id;
};

#endif // __PARAMS__X86ACPISysDescTable__
