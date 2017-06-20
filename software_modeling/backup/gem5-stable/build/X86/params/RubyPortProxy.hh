#ifndef __PARAMS__RubyPortProxy__
#define __PARAMS__RubyPortProxy__

class RubyPortProxy;


#include "params/RubyPort.hh"

struct RubyPortProxyParams
    : public RubyPortParams
{
    RubyPortProxy * create();
};

#endif // __PARAMS__RubyPortProxy__
