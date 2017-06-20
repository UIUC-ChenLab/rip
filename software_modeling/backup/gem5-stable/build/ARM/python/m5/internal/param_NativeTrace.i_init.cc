#include "sim/init.hh"

extern "C" {
    void init_param_NativeTrace();
}

EmbeddedSwig embed_swig_param_NativeTrace(init_param_NativeTrace);
