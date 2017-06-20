#ifndef __PARAMS__Pc__
#define __PARAMS__Pc__

class Pc;

#include <cstddef>
#include "params/System.hh"

#include "params/Platform.hh"

struct PcParams
    : public PlatformParams
{
    Pc * create();
    System * system;
};

#endif // __PARAMS__Pc__
