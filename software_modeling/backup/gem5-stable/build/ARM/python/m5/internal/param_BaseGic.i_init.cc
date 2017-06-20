#include "sim/init.hh"

extern "C" {
    void init_param_BaseGic();
}

EmbeddedSwig embed_swig_param_BaseGic(init_param_BaseGic);
