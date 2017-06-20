#include "sim/init.hh"

extern "C" {
    void init_param_VGic();
}

EmbeddedSwig embed_swig_param_VGic(init_param_VGic);
