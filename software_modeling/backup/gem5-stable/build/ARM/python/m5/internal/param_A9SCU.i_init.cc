#include "sim/init.hh"

extern "C" {
    void init_param_A9SCU();
}

EmbeddedSwig embed_swig_param_A9SCU(init_param_A9SCU);
