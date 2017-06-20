#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPLocalIntAssignment();
}

EmbeddedSwig embed_swig_param_X86IntelMPLocalIntAssignment(init_param_X86IntelMPLocalIntAssignment);
