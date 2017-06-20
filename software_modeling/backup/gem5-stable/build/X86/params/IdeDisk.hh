#ifndef __PARAMS__IdeDisk__
#define __PARAMS__IdeDisk__

class IdeDisk;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/IdeID.hh"
#include <cstddef>
#include "params/DiskImage.hh"

#include "params/SimObject.hh"

#include "enums/IdeID.hh"

struct IdeDiskParams
    : public SimObjectParams
{
    IdeDisk * create();
    Tick delay;
    Enums::IdeID driveID;
    DiskImage * image;
};

#endif // __PARAMS__IdeDisk__
