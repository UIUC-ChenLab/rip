#ifndef __PARAMS__BadDevice__
#define __PARAMS__BadDevice__

class BadDevice;

#include <cstddef>
#include <string>

#include "params/BasicPioDevice.hh"

struct BadDeviceParams
    : public BasicPioDeviceParams
{
    BadDevice * create();
    std::string devicename;
};

#endif // __PARAMS__BadDevice__
