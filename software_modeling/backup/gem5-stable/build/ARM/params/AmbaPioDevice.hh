#ifndef __PARAMS__AmbaPioDevice__
#define __PARAMS__AmbaPioDevice__

class AmbaPioDevice;

#include <cstddef>
#include "base/types.hh"

#include "params/BasicPioDevice.hh"

struct AmbaPioDeviceParams
    : public BasicPioDeviceParams
{
    uint32_t amba_id;
};

#endif // __PARAMS__AmbaPioDevice__
