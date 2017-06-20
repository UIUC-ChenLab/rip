#ifndef __PARAMS__O3Checker__
#define __PARAMS__O3Checker__

class O3Checker;


#include "params/CheckerCPU.hh"

struct O3CheckerParams
    : public CheckerCPUParams
{
    O3Checker * create();
};

#endif // __PARAMS__O3Checker__
