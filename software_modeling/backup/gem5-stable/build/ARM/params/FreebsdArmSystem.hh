#ifndef __PARAMS__FreebsdArmSystem__
#define __PARAMS__FreebsdArmSystem__

class FreebsdArmSystem;


#include "params/GenericArmSystem.hh"

struct FreebsdArmSystemParams
    : public GenericArmSystemParams
{
    FreebsdArmSystem * create();
};

#endif // __PARAMS__FreebsdArmSystem__
