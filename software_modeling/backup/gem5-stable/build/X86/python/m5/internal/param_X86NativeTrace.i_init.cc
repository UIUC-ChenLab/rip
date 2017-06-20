#include "sim/init.hh"

extern "C" {
    void init_param_X86NativeTrace();
}

EmbeddedSwig embed_swig_param_X86NativeTrace(init_param_X86NativeTrace);
