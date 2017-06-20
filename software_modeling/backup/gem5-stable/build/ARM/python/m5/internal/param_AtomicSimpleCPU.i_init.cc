#include "sim/init.hh"

extern "C" {
    void init_param_AtomicSimpleCPU();
}

EmbeddedSwig embed_swig_param_AtomicSimpleCPU(init_param_AtomicSimpleCPU);
