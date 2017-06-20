#ifndef __PARAMS__NetworkLink_d__
#define __PARAMS__NetworkLink_d__

class NetworkLink_d;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

struct NetworkLink_dParams
    : public ClockedObjectParams
{
    NetworkLink_d * create();
    int channel_width;
    int link_id;
    Cycles link_latency;
    int vcs_per_vnet;
    int virt_nets;
};

#endif // __PARAMS__NetworkLink_d__
