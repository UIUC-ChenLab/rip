#ifndef __PARAMS__VncInput__
#define __PARAMS__VncInput__

class VncInput;

#include <cstddef>

#include "params/SimObject.hh"

struct VncInputParams
    : public SimObjectParams
{
    VncInput * create();
    bool frame_capture;
};

#endif // __PARAMS__VncInput__
