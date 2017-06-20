#include "sim/init.hh"

extern "C" {
    void init_param_BaseCPU();
}

EmbeddedSwig embed_swig_param_BaseCPU(init_param_BaseCPU);
