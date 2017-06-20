#include "sim/init.hh"

extern "C" {
    void init_param_BaseKvmCPU();
}

EmbeddedSwig embed_swig_param_BaseKvmCPU(init_param_BaseKvmCPU);
