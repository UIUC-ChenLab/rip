#include "sim/init.hh"

extern "C" {
    void init_param_TimingSimpleCPU();
}

EmbeddedSwig embed_swig_param_TimingSimpleCPU(init_param_TimingSimpleCPU);
