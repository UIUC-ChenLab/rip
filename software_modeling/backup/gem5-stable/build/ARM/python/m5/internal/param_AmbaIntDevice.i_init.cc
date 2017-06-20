#include "sim/init.hh"

extern "C" {
    void init_param_AmbaIntDevice();
}

EmbeddedSwig embed_swig_param_AmbaIntDevice(init_param_AmbaIntDevice);
