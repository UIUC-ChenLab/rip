#ifndef __PARAMS__TimingExprBin__
#define __PARAMS__TimingExprBin__

class TimingExprBin;

#include <cstddef>
#include "params/TimingExpr.hh"
#include <cstddef>
#include "enums/TimingExprOp.hh"
#include <cstddef>
#include "params/TimingExpr.hh"

#include "params/TimingExpr.hh"

#include "enums/TimingExprOp.hh"

struct TimingExprBinParams
    : public TimingExprParams
{
    TimingExprBin * create();
    TimingExpr * left;
    Enums::TimingExprOp op;
    TimingExpr * right;
};

#endif // __PARAMS__TimingExprBin__
