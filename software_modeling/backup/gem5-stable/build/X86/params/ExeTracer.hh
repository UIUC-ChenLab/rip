#ifndef __PARAMS__ExeTracer__
#define __PARAMS__ExeTracer__

namespace Trace {
class ExeTracer;
} // namespace Trace


#include "params/InstTracer.hh"

struct ExeTracerParams
    : public InstTracerParams
{
    Trace::ExeTracer * create();
};

#endif // __PARAMS__ExeTracer__
