#ifndef __PARAMS__X86E820Entry__
#define __PARAMS__X86E820Entry__

namespace X86ISA {
class E820Entry;
} // namespace X86ISA

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct X86E820EntryParams
    : public SimObjectParams
{
    X86ISA::E820Entry * create();
    Addr addr;
    uint64_t range_type;
    uint64_t size;
};

#endif // __PARAMS__X86E820Entry__
