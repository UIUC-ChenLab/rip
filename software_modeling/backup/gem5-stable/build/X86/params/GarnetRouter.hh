#ifndef __PARAMS__GarnetRouter__
#define __PARAMS__GarnetRouter__

class Router;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicRouter.hh"

struct GarnetRouterParams
    : public BasicRouterParams
{
    Router * create();
    int vcs_per_vnet;
    int virt_nets;
};

#endif // __PARAMS__GarnetRouter__
