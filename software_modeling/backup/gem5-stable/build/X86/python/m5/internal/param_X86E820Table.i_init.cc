#include "sim/init.hh"

extern "C" {
    void init_param_X86E820Table();
}

EmbeddedSwig embed_swig_param_X86E820Table(init_param_X86E820Table);
