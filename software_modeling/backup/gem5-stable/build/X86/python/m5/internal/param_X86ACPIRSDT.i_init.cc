#include "sim/init.hh"

extern "C" {
    void init_param_X86ACPIRSDT();
}

EmbeddedSwig embed_swig_param_X86ACPIRSDT(init_param_X86ACPIRSDT);
