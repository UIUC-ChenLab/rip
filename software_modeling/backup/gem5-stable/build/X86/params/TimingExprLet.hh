#ifndef __PARAMS__TimingExprLet__
#define __PARAMS__TimingExprLet__

class TimingExprLet;

#include <vector>
#include "params/TimingExpr.hh"
#include <cstddef>
#include "params/TimingExpr.hh"

#include "params/TimingExpr.hh"

struct TimingExprLetParams
    : public TimingExprParams
{
    TimingExprLet * create();
    std::vector< TimingExpr * > defns;
    TimingExpr * expr;
};

#endif // __PARAMS__TimingExprLet__
