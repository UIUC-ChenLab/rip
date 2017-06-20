#ifndef __PARAMS__DiskImage__
#define __PARAMS__DiskImage__

class DiskImage;

#include <cstddef>
#include <string>
#include <cstddef>

#include "params/SimObject.hh"

struct DiskImageParams
    : public SimObjectParams
{
    std::string image_file;
    bool read_only;
};

#endif // __PARAMS__DiskImage__
