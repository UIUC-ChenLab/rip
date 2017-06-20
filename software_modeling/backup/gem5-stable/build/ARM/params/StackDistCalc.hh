#ifndef __PARAMS__StackDistCalc__
#define __PARAMS__StackDistCalc__

class StackDistCalc;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/SimObject.hh"

struct StackDistCalcParams
    : public SimObjectParams
{
    StackDistCalc * create();
    bool disable_linear_hists;
    bool disable_log_hists;
    unsigned linear_hist_bins;
    unsigned log_hist_bins;
    bool verify;
};

#endif // __PARAMS__StackDistCalc__
