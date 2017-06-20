#ifndef __PARAMS__GarnetIntLink_d__
#define __PARAMS__GarnetIntLink_d__

class GarnetIntLink_d;

#include <vector>
#include "params/CreditLink_d.hh"
#include <vector>
#include "params/NetworkLink_d.hh"

#include "params/BasicIntLink.hh"

struct GarnetIntLink_dParams
    : public BasicIntLinkParams
{
    GarnetIntLink_d * create();
    std::vector< CreditLink_d * > credit_links;
    std::vector< NetworkLink_d * > network_links;
};

#endif // __PARAMS__GarnetIntLink_d__
