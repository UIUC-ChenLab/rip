#ifndef __PARAMS__I2CBus__
#define __PARAMS__I2CBus__

class I2CBus;

#include <vector>
#include "params/I2CDevice.hh"

#include "params/BasicPioDevice.hh"

struct I2CBusParams
    : public BasicPioDeviceParams
{
    I2CBus * create();
    std::vector< I2CDevice * > devices;
};

#endif // __PARAMS__I2CBus__
