#ifndef __PARAMS__X86E820Table__
#define __PARAMS__X86E820Table__

namespace X86ISA {
class E820Table;
} // namespace X86ISA

#include <vector>
#include "params/X86E820Entry.hh"

#include "params/SimObject.hh"

struct X86E820TableParams
    : public SimObjectParams
{
    X86ISA::E820Table * create();
    std::vector< X86ISA::E820Entry * > entries;
};

#endif // __PARAMS__X86E820Table__
