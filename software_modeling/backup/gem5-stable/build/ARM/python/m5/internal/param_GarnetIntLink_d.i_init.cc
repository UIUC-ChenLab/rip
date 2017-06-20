#include "sim/init.hh"

extern "C" {
    void init_param_GarnetIntLink_d();
}

EmbeddedSwig embed_swig_param_GarnetIntLink_d(init_param_GarnetIntLink_d);
