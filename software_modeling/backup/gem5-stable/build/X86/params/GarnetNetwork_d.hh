#ifndef __PARAMS__GarnetNetwork_d__
#define __PARAMS__GarnetNetwork_d__

class GarnetNetwork_d;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BaseGarnetNetwork.hh"

struct GarnetNetwork_dParams
    : public BaseGarnetNetworkParams
{
    GarnetNetwork_d * create();
    uint32_t buffers_per_ctrl_vc;
    uint32_t buffers_per_data_vc;
};

#endif // __PARAMS__GarnetNetwork_d__
