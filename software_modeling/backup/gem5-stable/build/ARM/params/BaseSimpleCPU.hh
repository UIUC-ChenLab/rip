#ifndef __PARAMS__BaseSimpleCPU__
#define __PARAMS__BaseSimpleCPU__

class BaseSimpleCPU;

#include <cstddef>
#include "params/BranchPredictor.hh"

#include "params/BaseCPU.hh"

struct BaseSimpleCPUParams
    : public BaseCPUParams
{
    BPredUnit * branchPred;
};

#endif // __PARAMS__BaseSimpleCPU__
