#ifndef __PARAMS__X86TLB__
#define __PARAMS__X86TLB__

namespace X86ISA {
class TLB;
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/X86PagetableWalker.hh"

#include "params/BaseTLB.hh"

struct X86TLBParams
    : public BaseTLBParams
{
    X86ISA::TLB * create();
    unsigned size;
    X86ISA::Walker * walker;
};

#endif // __PARAMS__X86TLB__
