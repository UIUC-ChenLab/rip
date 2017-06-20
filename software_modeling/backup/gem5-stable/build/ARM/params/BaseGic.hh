#ifndef __PARAMS__BaseGic__
#define __PARAMS__BaseGic__

class BaseGic;

#include <cstddef>
#include "params/Platform.hh"

#include "params/PioDevice.hh"

struct BaseGicParams
    : public PioDeviceParams
{
    Platform * platform;
};

#endif // __PARAMS__BaseGic__
