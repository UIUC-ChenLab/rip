#ifndef __PARAMS__IntrControl__
#define __PARAMS__IntrControl__

class IntrControl;

#include <cstddef>
#include "params/System.hh"

#include "params/SimObject.hh"

struct IntrControlParams
    : public SimObjectParams
{
    IntrControl * create();
    System * sys;
};

#endif // __PARAMS__IntrControl__
