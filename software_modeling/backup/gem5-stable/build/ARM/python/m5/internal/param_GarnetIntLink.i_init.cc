#include "sim/init.hh"

extern "C" {
    void init_param_GarnetIntLink();
}

EmbeddedSwig embed_swig_param_GarnetIntLink(init_param_GarnetIntLink);
