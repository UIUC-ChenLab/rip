#ifndef __PARAMS__Platform__
#define __PARAMS__Platform__

class Platform;

#include <cstddef>
#include "params/IntrControl.hh"

#include "params/SimObject.hh"

struct PlatformParams
    : public SimObjectParams
{
    IntrControl * intrctrl;
};

#endif // __PARAMS__Platform__
