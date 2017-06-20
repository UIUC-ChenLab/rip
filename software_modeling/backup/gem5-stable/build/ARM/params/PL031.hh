#ifndef __PARAMS__PL031__
#define __PARAMS__PL031__

class PL031;

#include <cstddef>
#include <time.h>

#include "params/AmbaIntDevice.hh"

struct PL031Params
    : public AmbaIntDeviceParams
{
    PL031 * create();
    tm time;
};

#endif // __PARAMS__PL031__
