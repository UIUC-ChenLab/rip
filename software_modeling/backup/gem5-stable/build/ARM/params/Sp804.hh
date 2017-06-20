#ifndef __PARAMS__Sp804__
#define __PARAMS__Sp804__

class Sp804;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/AmbaPioDevice.hh"

struct Sp804Params
    : public AmbaPioDeviceParams
{
    Sp804 * create();
    Tick clock0;
    Tick clock1;
    BaseGic * gic;
    uint32_t int_num0;
    uint32_t int_num1;
};

#endif // __PARAMS__Sp804__
