#ifndef __PARAMS__GarnetNetworkInterface__
#define __PARAMS__GarnetNetworkInterface__

class NetworkInterface;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

struct GarnetNetworkInterfaceParams
    : public ClockedObjectParams
{
    NetworkInterface * create();
    uint32_t id;
    uint32_t vcs_per_vnet;
    uint32_t virt_nets;
};

#endif // __PARAMS__GarnetNetworkInterface__
