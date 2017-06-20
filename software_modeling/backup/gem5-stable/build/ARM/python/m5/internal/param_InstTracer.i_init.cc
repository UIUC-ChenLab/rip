#include "sim/init.hh"

extern "C" {
    void init_param_InstTracer();
}

EmbeddedSwig embed_swig_param_InstTracer(init_param_InstTracer);
