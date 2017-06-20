#ifndef __PARAMS__Gicv2m__
#define __PARAMS__Gicv2m__

class Gicv2m;

#include <vector>
#include "params/Gicv2mFrame.hh"
#include <cstddef>
#include "params/BaseGic.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PioDevice.hh"

struct Gicv2mParams
    : public PioDeviceParams
{
    Gicv2m * create();
    std::vector< Gicv2mFrame * > frames;
    BaseGic * gic;
    Tick pio_delay;
};

#endif // __PARAMS__Gicv2m__
