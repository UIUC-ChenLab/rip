#ifndef __PARAMS__PioDevice__
#define __PARAMS__PioDevice__

class PioDevice;

#include <cstddef>
#include "params/System.hh"

#include "params/MemObject.hh"

struct PioDeviceParams
    : public MemObjectParams
{
    System * system;
    unsigned int port_pio_connection_count;
};

#endif // __PARAMS__PioDevice__
