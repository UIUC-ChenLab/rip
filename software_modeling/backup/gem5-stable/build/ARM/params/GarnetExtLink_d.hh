#ifndef __PARAMS__GarnetExtLink_d__
#define __PARAMS__GarnetExtLink_d__

class GarnetExtLink_d;

#include <vector>
#include "params/CreditLink_d.hh"
#include <vector>
#include "params/NetworkLink_d.hh"

#include "params/BasicExtLink.hh"

struct GarnetExtLink_dParams
    : public BasicExtLinkParams
{
    GarnetExtLink_d * create();
    std::vector< CreditLink_d * > credit_links;
    std::vector< NetworkLink_d * > network_links;
};

#endif // __PARAMS__GarnetExtLink_d__
