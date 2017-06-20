#include "sim/init.hh"

extern "C" {
    void init_param_X86LocalApic();
}

EmbeddedSwig embed_swig_param_X86LocalApic(init_param_X86LocalApic);
