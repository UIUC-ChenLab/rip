#ifndef __PARAMS__DmaDevice__
#define __PARAMS__DmaDevice__

class DmaDevice;


#include "params/PioDevice.hh"

struct DmaDeviceParams
    : public PioDeviceParams
{
    unsigned int port_dma_connection_count;
};

#endif // __PARAMS__DmaDevice__
