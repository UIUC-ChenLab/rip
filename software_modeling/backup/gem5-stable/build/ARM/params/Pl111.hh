#ifndef __PARAMS__Pl111__
#define __PARAMS__Pl111__

class Pl111;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/VncInput.hh"

#include "params/AmbaDmaDevice.hh"

struct Pl111Params
    : public AmbaDmaDeviceParams
{
    Pl111 * create();
    bool enable_capture;
    Tick pixel_clock;
    VncInput * vnc;
};

#endif // __PARAMS__Pl111__
