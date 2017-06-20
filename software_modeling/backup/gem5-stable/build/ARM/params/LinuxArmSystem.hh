#ifndef __PARAMS__LinuxArmSystem__
#define __PARAMS__LinuxArmSystem__

class LinuxArmSystem;


#include "params/GenericArmSystem.hh"

struct LinuxArmSystemParams
    : public GenericArmSystemParams
{
    LinuxArmSystem * create();
};

#endif // __PARAMS__LinuxArmSystem__
