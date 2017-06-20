#include "sim/init.hh"

extern "C" {
    void init_param_ArmPMU();
}

EmbeddedSwig embed_swig_param_ArmPMU(init_param_ArmPMU);
