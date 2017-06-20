#include "sim/init.hh"

extern "C" {
    void init_param_ExeTracer();
}

EmbeddedSwig embed_swig_param_ExeTracer(init_param_ExeTracer);
