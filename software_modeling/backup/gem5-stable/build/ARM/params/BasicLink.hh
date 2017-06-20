#ifndef __PARAMS__BasicLink__
#define __PARAMS__BasicLink__

class BasicLink;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct BasicLinkParams
    : public SimObjectParams
{
    BasicLink * create();
    int bandwidth_factor;
    Cycles latency;
    int link_id;
    int weight;
};

#endif // __PARAMS__BasicLink__
