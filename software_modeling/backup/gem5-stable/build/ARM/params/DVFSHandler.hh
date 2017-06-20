#ifndef __PARAMS__DVFSHandler__
#define __PARAMS__DVFSHandler__

class DVFSHandler;

#include <vector>
#include "params/SrcClockDomain.hh"
#include <cstddef>
#include <cstddef>
#include "params/SrcClockDomain.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct DVFSHandlerParams
    : public SimObjectParams
{
    DVFSHandler * create();
    std::vector< SrcClockDomain * > domains;
    bool enable;
    SrcClockDomain * sys_clk_domain;
    Tick transition_latency;
};

#endif // __PARAMS__DVFSHandler__
