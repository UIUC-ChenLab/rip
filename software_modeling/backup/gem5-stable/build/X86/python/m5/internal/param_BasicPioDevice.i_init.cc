#include "sim/init.hh"

extern "C" {
    void init_param_BasicPioDevice();
}

EmbeddedSwig embed_swig_param_BasicPioDevice(init_param_BasicPioDevice);
