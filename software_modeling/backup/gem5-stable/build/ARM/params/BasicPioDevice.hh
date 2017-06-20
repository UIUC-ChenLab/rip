#ifndef __PARAMS__BasicPioDevice__
#define __PARAMS__BasicPioDevice__

class BasicPioDevice;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PioDevice.hh"

struct BasicPioDeviceParams
    : public PioDeviceParams
{
    Addr pio_addr;
    Tick pio_latency;
};

#endif // __PARAMS__BasicPioDevice__
