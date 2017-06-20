#include "sim/init.hh"

extern "C" {
    void init_param_CheckerCPU();
}

EmbeddedSwig embed_swig_param_CheckerCPU(init_param_CheckerCPU);
