#include "sim/init.hh"

extern "C" {
    void init_param_ProbeListenerObject();
}

EmbeddedSwig embed_swig_param_ProbeListenerObject(init_param_ProbeListenerObject);
