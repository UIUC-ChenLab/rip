#ifndef __PARAMS__PciConfigAll__
#define __PARAMS__PciConfigAll__

class PciConfigAll;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/Platform.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicPioDevice.hh"

struct PciConfigAllParams
    : public BasicPioDeviceParams
{
    PciConfigAll * create();
    uint8_t bus;
    Platform * platform;
    uint32_t size;
};

#endif // __PARAMS__PciConfigAll__
