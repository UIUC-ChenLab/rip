#ifndef __PARAMS__AmbaDmaDevice__
#define __PARAMS__AmbaDmaDevice__

class AmbaDmaDevice;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/DmaDevice.hh"

struct AmbaDmaDeviceParams
    : public DmaDeviceParams
{
    uint32_t amba_id;
    BaseGic * gic;
    uint32_t int_num;
    Addr pio_addr;
    Tick pio_latency;
};

#endif // __PARAMS__AmbaDmaDevice__
