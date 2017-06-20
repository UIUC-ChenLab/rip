#ifndef __PARAMS__TournamentBP__
#define __PARAMS__TournamentBP__

class TournamentBP;

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
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BranchPredictor.hh"

struct TournamentBPParams
    : public BranchPredictorParams
{
    TournamentBP * create();
    unsigned choiceCtrBits;
    unsigned choicePredictorSize;
    unsigned globalCtrBits;
    unsigned globalPredictorSize;
    unsigned localCtrBits;
    unsigned localHistoryTableSize;
    unsigned localPredictorSize;
};

#endif // __PARAMS__TournamentBP__
