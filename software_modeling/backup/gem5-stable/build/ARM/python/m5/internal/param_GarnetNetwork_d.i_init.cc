#include "sim/init.hh"

extern "C" {
    void init_param_GarnetNetwork_d();
}

EmbeddedSwig embed_swig_param_GarnetNetwork_d(init_param_GarnetNetwork_d);
