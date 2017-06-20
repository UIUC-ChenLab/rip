#include "sim/init.hh"

extern "C" {
    void init_param_GarnetExtLink_d();
}

EmbeddedSwig embed_swig_param_GarnetExtLink_d(init_param_GarnetExtLink_d);
