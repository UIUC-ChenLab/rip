#ifndef __PARAMS__X86ISA__
#define __PARAMS__X86ISA__

namespace X86ISA {
class ISA;
} // namespace X86ISA


#include "params/SimObject.hh"

struct X86ISAParams
    : public SimObjectParams
{
    X86ISA::ISA * create();
};

#endif // __PARAMS__X86ISA__
