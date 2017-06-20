#include "sim/init.hh"

extern "C" {
    void init_param_SimpleTrace();
}

EmbeddedSwig embed_swig_param_SimpleTrace(init_param_SimpleTrace);
