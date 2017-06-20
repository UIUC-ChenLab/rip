#ifndef __PARAMS__DummyChecker__
#define __PARAMS__DummyChecker__

class DummyChecker;


#include "params/CheckerCPU.hh"

struct DummyCheckerParams
    : public CheckerCPUParams
{
    DummyChecker * create();
};

#endif // __PARAMS__DummyChecker__
