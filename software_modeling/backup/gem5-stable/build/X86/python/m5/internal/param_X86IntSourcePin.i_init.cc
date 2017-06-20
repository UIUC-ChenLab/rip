#include "sim/init.hh"

extern "C" {
    void init_param_X86IntSourcePin();
}

EmbeddedSwig embed_swig_param_X86IntSourcePin(init_param_X86IntSourcePin);
