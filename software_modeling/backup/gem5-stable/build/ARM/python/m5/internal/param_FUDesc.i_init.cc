#include "sim/init.hh"

extern "C" {
    void init_param_FUDesc();
}

EmbeddedSwig embed_swig_param_FUDesc(init_param_FUDesc);
