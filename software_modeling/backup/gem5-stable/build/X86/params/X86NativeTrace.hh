#ifndef __PARAMS__X86NativeTrace__
#define __PARAMS__X86NativeTrace__

namespace Trace {
class X86NativeTrace;
} // namespace Trace


#include "params/NativeTrace.hh"

struct X86NativeTraceParams
    : public NativeTraceParams
{
    Trace::X86NativeTrace * create();
};

#endif // __PARAMS__X86NativeTrace__
