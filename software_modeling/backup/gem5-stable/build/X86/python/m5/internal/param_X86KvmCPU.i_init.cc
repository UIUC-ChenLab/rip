#include "sim/init.hh"

extern "C" {
    void init_param_X86KvmCPU();
}

EmbeddedSwig embed_swig_param_X86KvmCPU(init_param_X86KvmCPU);
