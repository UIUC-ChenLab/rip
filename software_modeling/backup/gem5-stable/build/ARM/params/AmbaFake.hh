#ifndef __PARAMS__AmbaFake__
#define __PARAMS__AmbaFake__

class AmbaFake;

#include <cstddef>

#include "params/AmbaPioDevice.hh"

struct AmbaFakeParams
    : public AmbaPioDeviceParams
{
    AmbaFake * create();
    bool ignore_access;
};

#endif // __PARAMS__AmbaFake__
