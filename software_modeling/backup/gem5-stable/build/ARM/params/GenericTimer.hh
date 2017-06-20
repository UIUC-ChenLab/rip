#ifndef __PARAMS__GenericTimer__
#define __PARAMS__GenericTimer__

class GenericTimer;

#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/SimObject.hh"

struct GenericTimerParams
    : public SimObjectParams
{
    GenericTimer * create();
    BaseGic * gic;
    uint32_t int_phys;
    uint32_t int_virt;
    System * system;
};

#endif // __PARAMS__GenericTimer__
