#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPIOAPIC();
}

EmbeddedSwig embed_swig_param_X86IntelMPIOAPIC(init_param_X86IntelMPIOAPIC);
