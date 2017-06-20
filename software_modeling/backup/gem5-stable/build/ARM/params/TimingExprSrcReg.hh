#ifndef __PARAMS__TimingExprSrcReg__
#define __PARAMS__TimingExprSrcReg__

class TimingExprSrcReg;

#include <cstddef>
#include "base/types.hh"

#include "params/TimingExpr.hh"

struct TimingExprSrcRegParams
    : public TimingExprParams
{
    TimingExprSrcReg * create();
    unsigned index;
};

#endif // __PARAMS__TimingExprSrcReg__
