#include "sim/init.hh"

extern "C" {
    void init_param_UFSHostDevice();
}

EmbeddedSwig embed_swig_param_UFSHostDevice(init_param_UFSHostDevice);
