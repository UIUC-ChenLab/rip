#ifndef __PARAMS__TimingExprIf__
#define __PARAMS__TimingExprIf__

class TimingExprIf;

#include <cstddef>
#include "params/TimingExpr.hh"
#include <cstddef>
#include "params/TimingExpr.hh"
#include <cstddef>
#include "params/TimingExpr.hh"

#include "params/TimingExpr.hh"

struct TimingExprIfParams
    : public TimingExprParams
{
    TimingExprIf * create();
    TimingExpr * cond;
    TimingExpr * falseExpr;
    TimingExpr * trueExpr;
};

#endif // __PARAMS__TimingExprIf__
