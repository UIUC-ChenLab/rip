#ifndef __PARAMS__I2CDevice__
#define __PARAMS__I2CDevice__

class I2CDevice;

#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct I2CDeviceParams
    : public SimObjectParams
{
    uint8_t i2c_addr;
};

#endif // __PARAMS__I2CDevice__
