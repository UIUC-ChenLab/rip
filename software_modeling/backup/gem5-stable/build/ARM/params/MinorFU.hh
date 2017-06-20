#ifndef __PARAMS__MinorFU__
#define __PARAMS__MinorFU__

class MinorFU;

#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/MinorOpClassSet.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/MinorFUTiming.hh"

#include "params/SimObject.hh"

struct MinorFUParams
    : public SimObjectParams
{
    MinorFU * create();
    std::vector< unsigned > cantForwardFromFUIndices;
    Cycles issueLat;
    MinorOpClassSet * opClasses;
    Cycles opLat;
    std::vector< MinorFUTiming * > timings;
};

#endif // __PARAMS__MinorFU__
