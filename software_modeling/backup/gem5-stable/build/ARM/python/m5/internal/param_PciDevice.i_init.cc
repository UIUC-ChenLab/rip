#include "sim/init.hh"

extern "C" {
    void init_param_PciDevice();
}

EmbeddedSwig embed_swig_param_PciDevice(init_param_PciDevice);
