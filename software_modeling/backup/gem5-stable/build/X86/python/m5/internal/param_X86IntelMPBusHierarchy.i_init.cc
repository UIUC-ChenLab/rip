#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPBusHierarchy();
}

EmbeddedSwig embed_swig_param_X86IntelMPBusHierarchy(init_param_X86IntelMPBusHierarchy);
