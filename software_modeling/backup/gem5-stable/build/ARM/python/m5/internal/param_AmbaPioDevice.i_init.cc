#include "sim/init.hh"

extern "C" {
    void init_param_AmbaPioDevice();
}

EmbeddedSwig embed_swig_param_AmbaPioDevice(init_param_AmbaPioDevice);
