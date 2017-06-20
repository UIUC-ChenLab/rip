#ifndef __PARAMS__CheckerCPU__
#define __PARAMS__CheckerCPU__

class CheckerCPU;

#include <cstddef>
#include <cstddef>
#include <cstddef>

#include "params/BaseCPU.hh"

struct CheckerCPUParams
    : public BaseCPUParams
{
    bool exitOnError;
    bool updateOnError;
    bool warnOnlyOnLoadError;
};

#endif // __PARAMS__CheckerCPU__
