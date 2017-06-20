#include "sim/init.hh"

extern "C" {
    void init_param_FlashDevice();
}

EmbeddedSwig embed_swig_param_FlashDevice(init_param_FlashDevice);
