#include "sim/init.hh"

extern "C" {
    void init_param_ArmISA();
}

EmbeddedSwig embed_swig_param_ArmISA(init_param_ArmISA);
