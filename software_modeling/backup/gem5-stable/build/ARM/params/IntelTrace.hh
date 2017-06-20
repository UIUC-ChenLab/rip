#ifndef __PARAMS__IntelTrace__
#define __PARAMS__IntelTrace__

namespace Trace {
class IntelTrace;
} // namespace Trace


#include "params/InstTracer.hh"

struct IntelTraceParams
    : public InstTracerParams
{
    Trace::IntelTrace * create();
};

#endif // __PARAMS__IntelTrace__
