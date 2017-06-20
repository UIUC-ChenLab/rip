#include "sim/init.hh"

extern "C" {
    void init_param_GarnetRouter_d();
}

EmbeddedSwig embed_swig_param_GarnetRouter_d(init_param_GarnetRouter_d);
