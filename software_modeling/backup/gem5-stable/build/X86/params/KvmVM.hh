#ifndef __PARAMS__KvmVM__
#define __PARAMS__KvmVM__

class KvmVM;

#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/SimObject.hh"

struct KvmVMParams
    : public SimObjectParams
{
    KvmVM * create();
    std::vector< AddrRange > coalescedMMIO;
    System * system;
};

#endif // __PARAMS__KvmVM__
