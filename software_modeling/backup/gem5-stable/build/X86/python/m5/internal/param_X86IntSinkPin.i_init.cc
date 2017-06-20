#include "sim/init.hh"

extern "C" {
    void init_param_X86IntSinkPin();
}

EmbeddedSwig embed_swig_param_X86IntSinkPin(init_param_X86IntSinkPin);
