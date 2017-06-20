#ifndef __PARAMS__ArmNativeTrace__
#define __PARAMS__ArmNativeTrace__

namespace Trace {
class ArmNativeTrace;
} // namespace Trace

#include <cstddef>

#include "params/NativeTrace.hh"

struct ArmNativeTraceParams
    : public NativeTraceParams
{
    Trace::ArmNativeTrace * create();
    bool stop_on_pc_error;
};

#endif // __PARAMS__ArmNativeTrace__
