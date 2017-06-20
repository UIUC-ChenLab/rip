#ifndef __PARAMS__TimingExprUn__
#define __PARAMS__TimingExprUn__

class TimingExprUn;

#include <cstddef>
#include "params/TimingExpr.hh"
#include <cstddef>
#include "enums/TimingExprOp.hh"

#include "params/TimingExpr.hh"

#include "enums/TimingExprOp.hh"

struct TimingExprUnParams
    : public TimingExprParams
{
    TimingExprUn * create();
    TimingExpr * arg;
    Enums::TimingExprOp op;
};

#endif // __PARAMS__TimingExprUn__
