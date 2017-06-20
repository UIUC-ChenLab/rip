#ifndef __PARAMS__CowDiskImage__
#define __PARAMS__CowDiskImage__

class CowDiskImage;

#include <cstddef>
#include "params/DiskImage.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/DiskImage.hh"

struct CowDiskImageParams
    : public DiskImageParams
{
    CowDiskImage * create();
    DiskImage * child;
    int table_size;
};

#endif // __PARAMS__CowDiskImage__
