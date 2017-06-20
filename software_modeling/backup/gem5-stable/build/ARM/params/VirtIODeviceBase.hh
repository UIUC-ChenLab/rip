#ifndef __PARAMS__VirtIODeviceBase__
#define __PARAMS__VirtIODeviceBase__

class VirtIODeviceBase;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/SimObject.hh"

struct VirtIODeviceBaseParams
    : public SimObjectParams
{
    uint8_t subsystem;
    System * system;
};

#endif // __PARAMS__VirtIODeviceBase__
