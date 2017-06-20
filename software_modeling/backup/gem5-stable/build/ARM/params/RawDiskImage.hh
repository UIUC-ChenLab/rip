#ifndef __PARAMS__RawDiskImage__
#define __PARAMS__RawDiskImage__

class RawDiskImage;


#include "params/DiskImage.hh"

struct RawDiskImageParams
    : public DiskImageParams
{
    RawDiskImage * create();
};

#endif // __PARAMS__RawDiskImage__
