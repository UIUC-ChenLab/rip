#ifndef __PARAMS__X86IntSourcePin__
#define __PARAMS__X86IntSourcePin__

namespace X86ISA {
class IntSourcePin;
} // namespace X86ISA


#include "params/SimObject.hh"

struct X86IntSourcePinParams
    : public SimObjectParams
{
    X86ISA::IntSourcePin * create();
};

#endif // __PARAMS__X86IntSourcePin__
