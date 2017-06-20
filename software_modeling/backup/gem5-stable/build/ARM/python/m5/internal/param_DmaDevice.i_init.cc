#include "sim/init.hh"

extern "C" {
    void init_param_DmaDevice();
}

EmbeddedSwig embed_swig_param_DmaDevice(init_param_DmaDevice);
