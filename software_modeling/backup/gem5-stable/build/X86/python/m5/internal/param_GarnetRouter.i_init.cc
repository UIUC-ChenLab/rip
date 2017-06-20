#include "sim/init.hh"

extern "C" {
    void init_param_GarnetRouter();
}

EmbeddedSwig embed_swig_param_GarnetRouter(init_param_GarnetRouter);
