#ifndef __PARAMS__A9SCU__
#define __PARAMS__A9SCU__

class A9SCU;


#include "params/BasicPioDevice.hh"

struct A9SCUParams
    : public BasicPioDeviceParams
{
    A9SCU * create();
};

#endif // __PARAMS__A9SCU__
