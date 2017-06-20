#ifndef __PARAMS__SimpleTrace__
#define __PARAMS__SimpleTrace__

class SimpleTrace;


#include "params/ProbeListenerObject.hh"

struct SimpleTraceParams
    : public ProbeListenerObjectParams
{
    SimpleTrace * create();
};

#endif // __PARAMS__SimpleTrace__
