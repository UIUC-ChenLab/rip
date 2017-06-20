#ifndef __PARAMS__MemChecker__
#define __PARAMS__MemChecker__

class MemChecker;


#include "params/SimObject.hh"

struct MemCheckerParams
    : public SimObjectParams
{
    MemChecker * create();
};

#endif // __PARAMS__MemChecker__
