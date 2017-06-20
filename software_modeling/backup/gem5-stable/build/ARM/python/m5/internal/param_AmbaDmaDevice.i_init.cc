#include "sim/init.hh"

extern "C" {
    void init_param_AmbaDmaDevice();
}

EmbeddedSwig embed_swig_param_AmbaDmaDevice(init_param_AmbaDmaDevice);
