#ifndef __PARAMS__ClockedObject__
#define __PARAMS__ClockedObject__

class ClockedObject;

#include <cstddef>
#include "params/ClockDomain.hh"

#include "params/SimObject.hh"

struct ClockedObjectParams
    : public SimObjectParams
{
    ClockDomain * clk_domain;
};

#endif // __PARAMS__ClockedObject__
