#ifndef __PARAMS__RubyWireBuffer__
#define __PARAMS__RubyWireBuffer__

class WireBuffer;


#include "params/SimObject.hh"

struct RubyWireBufferParams
    : public SimObjectParams
{
    WireBuffer * create();
};

#endif // __PARAMS__RubyWireBuffer__
