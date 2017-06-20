#ifndef __PARAMS__GarnetIntLink__
#define __PARAMS__GarnetIntLink__

class GarnetIntLink;

#include <vector>
#include "params/NetworkLink.hh"

#include "params/BasicIntLink.hh"

struct GarnetIntLinkParams
    : public BasicIntLinkParams
{
    GarnetIntLink * create();
    std::vector< NetworkLink * > network_links;
};

#endif // __PARAMS__GarnetIntLink__
