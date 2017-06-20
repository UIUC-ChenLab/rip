#ifndef __PARAMS__SimPoint__
#define __PARAMS__SimPoint__

class SimPoint;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>

#include "params/ProbeListenerObject.hh"

struct SimPointParams
    : public ProbeListenerObjectParams
{
    SimPoint * create();
    uint64_t interval;
    std::string profile_file;
};

#endif // __PARAMS__SimPoint__
