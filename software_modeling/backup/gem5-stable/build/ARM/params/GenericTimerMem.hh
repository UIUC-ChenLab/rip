#ifndef __PARAMS__GenericTimerMem__
#define __PARAMS__GenericTimerMem__

class GenericTimerMem;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PioDevice.hh"

struct GenericTimerMemParams
    : public PioDeviceParams
{
    GenericTimerMem * create();
    Addr base;
    BaseGic * gic;
    uint32_t int_phys;
    uint32_t int_virt;
};

#endif // __PARAMS__GenericTimerMem__
