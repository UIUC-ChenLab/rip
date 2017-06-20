#ifndef __PARAMS__PciVirtIO__
#define __PARAMS__PciVirtIO__

class PciVirtIO;

#include <cstddef>
#include "params/VirtIODeviceBase.hh"

#include "params/PciDevice.hh"

struct PciVirtIOParams
    : public PciDeviceParams
{
    PciVirtIO * create();
    VirtIODeviceBase * vio;
};

#endif // __PARAMS__PciVirtIO__
