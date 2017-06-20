#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPProcessor();
}

EmbeddedSwig embed_swig_param_X86IntelMPProcessor(init_param_X86IntelMPProcessor);
