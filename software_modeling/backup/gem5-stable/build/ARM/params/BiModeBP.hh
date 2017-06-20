#ifndef __PARAMS__BiModeBP__
#define __PARAMS__BiModeBP__

class BiModeBP;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BranchPredictor.hh"

struct BiModeBPParams
    : public BranchPredictorParams
{
    BiModeBP * create();
    unsigned choiceCtrBits;
    unsigned choicePredictorSize;
    unsigned globalCtrBits;
    unsigned globalPredictorSize;
};

#endif // __PARAMS__BiModeBP__
