#ifndef __PARAMS__VGic__
#define __PARAMS__VGic__

class VGic;

#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PioDevice.hh"

struct VGicParams
    : public PioDeviceParams
{
    VGic * create();
    BaseGic * gic;
    Addr hv_addr;
    Tick pio_delay;
    Platform * platform;
    uint32_t ppint;
    Addr vcpu_addr;
};

#endif // __PARAMS__VGic__
