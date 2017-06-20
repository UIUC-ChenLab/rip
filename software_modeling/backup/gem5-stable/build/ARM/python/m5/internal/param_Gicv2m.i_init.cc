#include "sim/init.hh"

extern "C" {
    void init_param_Gicv2m();
}

EmbeddedSwig embed_swig_param_Gicv2m(init_param_Gicv2m);
