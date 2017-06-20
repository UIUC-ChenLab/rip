#include "sim/init.hh"

extern "C" {
    void init_param_X86E820Entry();
}

EmbeddedSwig embed_swig_param_X86E820Entry(init_param_X86E820Entry);
