#include "sim/init.hh"

extern "C" {
    void init_param_GarnetNetwork();
}

EmbeddedSwig embed_swig_param_GarnetNetwork(init_param_GarnetNetwork);
