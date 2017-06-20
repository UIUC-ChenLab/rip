#ifndef __PARAMS__SimpleDisk__
#define __PARAMS__SimpleDisk__

class SimpleDisk;

#include <cstddef>
#include "params/DiskImage.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/SimObject.hh"

struct SimpleDiskParams
    : public SimObjectParams
{
    SimpleDisk * create();
    DiskImage * disk;
    System * system;
};

#endif // __PARAMS__SimpleDisk__
