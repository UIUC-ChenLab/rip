#ifndef __PARAMS__GarnetRouter_d__
#define __PARAMS__GarnetRouter_d__

class Router_d;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicRouter.hh"

struct GarnetRouter_dParams
    : public BasicRouterParams
{
    Router_d * create();
    uint32_t vcs_per_vnet;
    uint32_t virt_nets;
};

#endif // __PARAMS__GarnetRouter_d__
