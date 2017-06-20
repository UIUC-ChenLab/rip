#ifndef __PARAMS__SnoopFilter__
#define __PARAMS__SnoopFilter__

class SnoopFilter;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/SimObject.hh"

struct SnoopFilterParams
    : public SimObjectParams
{
    SnoopFilter * create();
    Cycles lookup_latency;
    System * system;
};

#endif // __PARAMS__SnoopFilter__
