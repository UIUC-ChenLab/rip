#include "sim/init.hh"

extern "C" {
    void init_param_ArmNativeTrace();
}

EmbeddedSwig embed_swig_param_ArmNativeTrace(init_param_ArmNativeTrace);
