#ifndef __PARAMS__ProbeListenerObject__
#define __PARAMS__ProbeListenerObject__

class ProbeListenerObject;

#include <cstddef>
#include "params/SimObject.hh"

#include "params/SimObject.hh"

struct ProbeListenerObjectParams
    : public SimObjectParams
{
    ProbeListenerObject * create();
    SimObject * manager;
};

#endif // __PARAMS__ProbeListenerObject__
