#ifndef __PARAMS__VirtIOConsole__
#define __PARAMS__VirtIOConsole__

class VirtIOConsole;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/Terminal.hh"

#include "params/VirtIODeviceBase.hh"

struct VirtIOConsoleParams
    : public VirtIODeviceBaseParams
{
    VirtIOConsole * create();
    unsigned qRecvSize;
    unsigned qTransSize;
    Terminal * terminal;
};

#endif // __PARAMS__VirtIOConsole__
