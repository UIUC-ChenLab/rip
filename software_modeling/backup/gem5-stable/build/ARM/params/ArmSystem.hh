#ifndef __PARAMS__ArmSystem__
#define __PARAMS__ArmSystem__

class ArmSystem;

#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/System.hh"

struct ArmSystemParams
    : public SystemParams
{
    ArmSystem * create();
    std::string boot_loader;
    Addr flags_addr;
    Addr gic_cpu_addr;
    bool have_large_asid_64;
    bool have_lpae;
    bool have_security;
    bool have_virtualization;
    bool highest_el_is_64;
    bool multi_proc;
    uint8_t phys_addr_range_64;
    Addr reset_addr_64;
};

#endif // __PARAMS__ArmSystem__
