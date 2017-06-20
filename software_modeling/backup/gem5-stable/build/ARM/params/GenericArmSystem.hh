#ifndef __PARAMS__GenericArmSystem__
#define __PARAMS__GenericArmSystem__

class GenericArmSystem;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "enums/ArmMachineType.hh"
#include <cstddef>
#include <cstddef>

#include "params/ArmSystem.hh"

#include "enums/ArmMachineType.hh"

struct GenericArmSystemParams
    : public ArmSystemParams
{
    GenericArmSystem * create();
    Addr atags_addr;
    std::string dtb_filename;
    bool early_kernel_symbols;
    bool enable_context_switch_stats_dump;
    Enums::ArmMachineType machine_type;
    bool panic_on_oops;
    bool panic_on_panic;
};

#endif // __PARAMS__GenericArmSystem__
