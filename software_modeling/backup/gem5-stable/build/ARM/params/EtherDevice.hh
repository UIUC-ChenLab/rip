#ifndef __PARAMS__EtherDevice__
#define __PARAMS__EtherDevice__

class EtherDevice;


#include "params/PciDevice.hh"

struct EtherDeviceParams
    : public PciDeviceParams
{
    unsigned int port_interface_connection_count;
};

#endif // __PARAMS__EtherDevice__
