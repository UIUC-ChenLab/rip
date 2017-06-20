#include "sim/init.hh"

extern "C" {
    void init_param_GarnetNetworkInterface();
}

EmbeddedSwig embed_swig_param_GarnetNetworkInterface(init_param_GarnetNetworkInterface);
