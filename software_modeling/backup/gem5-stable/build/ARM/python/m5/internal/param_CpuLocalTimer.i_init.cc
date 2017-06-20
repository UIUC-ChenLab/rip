#include "sim/init.hh"

extern "C" {
    void init_param_CpuLocalTimer();
}

EmbeddedSwig embed_swig_param_CpuLocalTimer(init_param_CpuLocalTimer);
