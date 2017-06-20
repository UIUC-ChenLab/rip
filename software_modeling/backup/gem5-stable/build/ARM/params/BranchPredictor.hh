#ifndef __PARAMS__BranchPredictor__
#define __PARAMS__BranchPredictor__

class BPredUnit;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

struct BranchPredictorParams
    : public SimObjectParams
{
    unsigned BTBEntries;
    unsigned BTBTagSize;
    unsigned RASSize;
    unsigned instShiftAmt;
    unsigned numThreads;
};

#endif // __PARAMS__BranchPredictor__
