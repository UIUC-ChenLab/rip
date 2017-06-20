#ifndef __PARAMS__NetworkLink__
#define __PARAMS__NetworkLink__

class NetworkLink;

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

struct NetworkLinkParams
    : public ClockedObjectParams
{
    NetworkLink * create();
    int channel_width;
    int link_id;
    Cycles link_latency;
    int vcs_per_vnet;
    int virt_nets;
};

#endif // __PARAMS__NetworkLink__
