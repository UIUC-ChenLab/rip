#include "sim/init.hh"

extern "C" {
    void init_param_EnergyCtrl();
}

EmbeddedSwig embed_swig_param_EnergyCtrl(init_param_EnergyCtrl);
