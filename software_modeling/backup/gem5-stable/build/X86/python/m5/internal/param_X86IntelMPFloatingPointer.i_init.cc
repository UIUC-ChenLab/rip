#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPFloatingPointer();
}

EmbeddedSwig embed_swig_param_X86IntelMPFloatingPointer(init_param_X86IntelMPFloatingPointer);
