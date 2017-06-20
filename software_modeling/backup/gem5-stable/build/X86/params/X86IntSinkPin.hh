#ifndef __PARAMS__X86IntSinkPin__
#define __PARAMS__X86IntSinkPin__

namespace X86ISA {
class IntSinkPin;
} // namespace X86ISA

#include <cstddef>
#include "params/SimObject.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct X86IntSinkPinParams
    : public SimObjectParams
{
    X86ISA::IntSinkPin * create();
    SimObject * device;
    int number;
};

#endif // __PARAMS__X86IntSinkPin__
