#ifndef __PARAMS__DerivedClockDomain__
#define __PARAMS__DerivedClockDomain__

class DerivedClockDomain;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/ClockDomain.hh"

#include "params/ClockDomain.hh"

struct DerivedClockDomainParams
    : public ClockDomainParams
{
    DerivedClockDomain * create();
    unsigned clk_divider;
    ClockDomain * clk_domain;
};

#endif // __PARAMS__DerivedClockDomain__
