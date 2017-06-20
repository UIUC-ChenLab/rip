#ifndef __PARAMS__TimingExprReadIntReg__
#define __PARAMS__TimingExprReadIntReg__

class TimingExprReadIntReg;

#include <cstddef>
#include "params/TimingExpr.hh"

#include "params/TimingExpr.hh"

struct TimingExprReadIntRegParams
    : public TimingExprParams
{
    TimingExprReadIntReg * create();
    TimingExpr * reg;
};

#endif // __PARAMS__TimingExprReadIntReg__
