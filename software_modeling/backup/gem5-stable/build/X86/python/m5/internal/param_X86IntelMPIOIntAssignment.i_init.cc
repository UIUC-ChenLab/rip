#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPIOIntAssignment();
}

EmbeddedSwig embed_swig_param_X86IntelMPIOIntAssignment(init_param_X86IntelMPIOIntAssignment);
