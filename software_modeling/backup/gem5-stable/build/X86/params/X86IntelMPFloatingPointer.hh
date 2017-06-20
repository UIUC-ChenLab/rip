#ifndef __PARAMS__X86IntelMPFloatingPointer__
#define __PARAMS__X86IntelMPFloatingPointer__

namespace X86ISA {
namespace IntelMP {
class FloatingPointer;
} // namespace IntelMP
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct X86IntelMPFloatingPointerParams
    : public SimObjectParams
{
    X86ISA::IntelMP::FloatingPointer * create();
    uint8_t default_config;
    bool imcr_present;
    uint8_t spec_rev;
};

#endif // __PARAMS__X86IntelMPFloatingPointer__
