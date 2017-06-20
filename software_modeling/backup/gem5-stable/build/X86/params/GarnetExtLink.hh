#ifndef __PARAMS__GarnetExtLink__
#define __PARAMS__GarnetExtLink__

class GarnetExtLink;

#include <vector>
#include "params/NetworkLink.hh"

#include "params/BasicExtLink.hh"

struct GarnetExtLinkParams
    : public BasicExtLinkParams
{
    GarnetExtLink * create();
    std::vector< NetworkLink * > network_links;
};

#endif // __PARAMS__GarnetExtLink__
