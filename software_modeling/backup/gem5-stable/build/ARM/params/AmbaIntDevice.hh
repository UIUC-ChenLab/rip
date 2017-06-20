#ifndef __PARAMS__AmbaIntDevice__
#define __PARAMS__AmbaIntDevice__

class AmbaIntDevice;

#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/AmbaPioDevice.hh"

struct AmbaIntDeviceParams
    : public AmbaPioDeviceParams
{
    BaseGic * gic;
    Tick int_delay;
    uint32_t int_num;
};

#endif // __PARAMS__AmbaIntDevice__
