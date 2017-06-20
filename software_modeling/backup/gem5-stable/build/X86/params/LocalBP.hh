#ifndef __PARAMS__LocalBP__
#define __PARAMS__LocalBP__

class LocalBP;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BranchPredictor.hh"

struct LocalBPParams
    : public BranchPredictorParams
{
    LocalBP * create();
    unsigned localCtrBits;
    unsigned localPredictorSize;
};

#endif // __PARAMS__LocalBP__
