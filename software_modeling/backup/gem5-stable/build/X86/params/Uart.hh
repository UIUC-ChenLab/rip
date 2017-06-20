#ifndef __PARAMS__Uart__
#define __PARAMS__Uart__

class Uart;

#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include "params/Terminal.hh"

#include "params/BasicPioDevice.hh"

struct UartParams
    : public BasicPioDeviceParams
{
    Platform * platform;
    Terminal * terminal;
};

#endif // __PARAMS__Uart__
