#ifndef __PARAMS__SubSystem__
#define __PARAMS__SubSystem__

class SubSystem;


#include "params/SimObject.hh"

struct SubSystemParams
    : public SimObjectParams
{
    SubSystem * create();
};

#endif // __PARAMS__SubSystem__
