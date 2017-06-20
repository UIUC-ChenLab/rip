#include "sim/init.hh"

extern "C" {
    void init_param_GarnetNetworkInterface_d();
}

EmbeddedSwig embed_swig_param_GarnetNetworkInterface_d(init_param_GarnetNetworkInterface_d);
