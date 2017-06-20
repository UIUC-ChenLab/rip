#include "sim/init.hh"

extern "C" {
    void init_param_EmulatedDriver();
}

EmbeddedSwig embed_swig_param_EmulatedDriver(init_param_EmulatedDriver);
