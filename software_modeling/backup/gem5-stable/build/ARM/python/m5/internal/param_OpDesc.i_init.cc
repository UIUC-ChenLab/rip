#include "sim/init.hh"

extern "C" {
    void init_param_OpDesc();
}

EmbeddedSwig embed_swig_param_OpDesc(init_param_OpDesc);
