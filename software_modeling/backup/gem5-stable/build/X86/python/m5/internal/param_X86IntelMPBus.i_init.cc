#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPBus();
}

EmbeddedSwig embed_swig_param_X86IntelMPBus(init_param_X86IntelMPBus);
