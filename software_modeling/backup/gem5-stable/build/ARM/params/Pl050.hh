#ifndef __PARAMS__Pl050__
#define __PARAMS__Pl050__

class Pl050;

#include <cstddef>
#include <cstddef>
#include "params/VncInput.hh"

#include "params/AmbaIntDevice.hh"

struct Pl050Params
    : public AmbaIntDeviceParams
{
    Pl050 * create();
    bool is_mouse;
    VncInput * vnc;
};

#endif // __PARAMS__Pl050__
