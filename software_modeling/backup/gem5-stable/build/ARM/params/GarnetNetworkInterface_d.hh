#ifndef __PARAMS__GarnetNetworkInterface_d__
#define __PARAMS__GarnetNetworkInterface_d__

class NetworkInterface_d;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

struct GarnetNetworkInterface_dParams
    : public ClockedObjectParams
{
    NetworkInterface_d * create();
    uint32_t id;
    uint32_t vcs_per_vnet;
    uint32_t virt_nets;
};

#endif // __PARAMS__GarnetNetworkInterface_d__
