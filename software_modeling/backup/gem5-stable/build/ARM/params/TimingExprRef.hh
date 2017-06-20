#ifndef __PARAMS__TimingExprRef__
#define __PARAMS__TimingExprRef__

class TimingExprRef;

#include <cstddef>
#include "base/types.hh"

#include "params/TimingExpr.hh"

struct TimingExprRefParams
    : public TimingExprParams
{
    TimingExprRef * create();
    unsigned index;
};

#endif // __PARAMS__TimingExprRef__
