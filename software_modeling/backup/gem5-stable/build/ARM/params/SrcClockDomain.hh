#ifndef __PARAMS__SrcClockDomain__
#define __PARAMS__SrcClockDomain__

class SrcClockDomain;

#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/VoltageDomain.hh"

#include "params/ClockDomain.hh"

struct SrcClockDomainParams
    : public ClockDomainParams
{
    SrcClockDomain * create();
    std::vector< Tick > clock;
    int32_t domain_id;
    uint32_t init_perf_level;
    VoltageDomain * voltage_domain;
};

#endif // __PARAMS__SrcClockDomain__
