#ifndef __PARAMS__MinorFUTiming__
#define __PARAMS__MinorFUTiming__

class MinorFUTiming;

#include <cstddef>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/TimingExpr.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/MinorOpClassSet.hh"
#include <vector>
#include "base/types.hh"
#include <cstddef>

#include "params/SimObject.hh"

struct MinorFUTimingParams
    : public SimObjectParams
{
    MinorFUTiming * create();
    std::string description;
    Cycles extraAssumedLat;
    Cycles extraCommitLat;
    TimingExpr * extraCommitLatExpr;
    uint64_t mask;
    uint64_t match;
    MinorOpClassSet * opClasses;
    std::vector< Cycles > srcRegsRelativeLats;
    bool suppress;
};

#endif // __PARAMS__MinorFUTiming__
