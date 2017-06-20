#ifndef __PARAMS__X86IntLine__
#define __PARAMS__X86IntLine__

namespace X86ISA {
class IntLine;
} // namespace X86ISA

#include <cstddef>
#include "params/X86IntSinkPin.hh"
#include <cstddef>
#include "params/X86IntSourcePin.hh"

#include "params/SimObject.hh"

struct X86IntLineParams
    : public SimObjectParams
{
    X86ISA::IntLine * create();
    X86ISA::IntSinkPin * sink;
    X86ISA::IntSourcePin * source;
};

#endif // __PARAMS__X86IntLine__
