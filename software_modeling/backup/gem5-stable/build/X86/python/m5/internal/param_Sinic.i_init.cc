#include "sim/init.hh"

extern "C" {
    void init_param_Sinic();
}

EmbeddedSwig embed_swig_param_Sinic(init_param_Sinic);
