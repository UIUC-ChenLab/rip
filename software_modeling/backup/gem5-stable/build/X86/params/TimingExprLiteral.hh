#ifndef __PARAMS__TimingExprLiteral__
#define __PARAMS__TimingExprLiteral__

class TimingExprLiteral;

#include <cstddef>
#include "base/types.hh"

#include "params/TimingExpr.hh"

struct TimingExprLiteralParams
    : public TimingExprParams
{
    TimingExprLiteral * create();
    uint64_t value;
};

#endif // __PARAMS__TimingExprLiteral__
