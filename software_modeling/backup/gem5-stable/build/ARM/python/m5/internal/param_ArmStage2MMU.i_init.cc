#include "sim/init.hh"

extern "C" {
    void init_param_ArmStage2MMU();
}

EmbeddedSwig embed_swig_param_ArmStage2MMU(init_param_ArmStage2MMU);
