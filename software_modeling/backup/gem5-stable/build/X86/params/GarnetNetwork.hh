#ifndef __PARAMS__GarnetNetwork__
#define __PARAMS__GarnetNetwork__

class GarnetNetwork;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BaseGarnetNetwork.hh"

struct GarnetNetworkParams
    : public BaseGarnetNetworkParams
{
    GarnetNetwork * create();
    uint32_t buffer_size;
    uint32_t number_of_pipe_stages;
};

#endif // __PARAMS__GarnetNetwork__
