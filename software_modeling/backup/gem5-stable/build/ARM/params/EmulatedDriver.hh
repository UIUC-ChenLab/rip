#ifndef __PARAMS__EmulatedDriver__
#define __PARAMS__EmulatedDriver__

class EmulatedDriver;

#include <cstddef>
#include <string>

#include "params/SimObject.hh"

struct EmulatedDriverParams
    : public SimObjectParams
{
    std::string filename;
};

#endif // __PARAMS__EmulatedDriver__
