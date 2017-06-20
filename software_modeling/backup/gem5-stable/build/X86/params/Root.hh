#ifndef __PARAMS__Root__
#define __PARAMS__Root__

class Root;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct RootParams
    : public SimObjectParams
{
    Root * create();
    bool full_system;
    Tick sim_quantum;
    bool time_sync_enable;
    Tick time_sync_period;
    Tick time_sync_spin_threshold;
};

#endif // __PARAMS__Root__
