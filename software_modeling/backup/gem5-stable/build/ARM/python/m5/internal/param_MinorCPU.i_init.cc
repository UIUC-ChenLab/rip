#include "sim/init.hh"

extern "C" {
    void init_param_MinorCPU();
}

EmbeddedSwig embed_swig_param_MinorCPU(init_param_MinorCPU);
