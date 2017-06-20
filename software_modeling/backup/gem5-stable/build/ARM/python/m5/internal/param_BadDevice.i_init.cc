#include "sim/init.hh"

extern "C" {
    void init_param_BadDevice();
}

EmbeddedSwig embed_swig_param_BadDevice(init_param_BadDevice);
