#include "sim/init.hh"

extern "C" {
    void init_param_X86IntLine();
}

EmbeddedSwig embed_swig_param_X86IntLine(init_param_X86IntLine);
