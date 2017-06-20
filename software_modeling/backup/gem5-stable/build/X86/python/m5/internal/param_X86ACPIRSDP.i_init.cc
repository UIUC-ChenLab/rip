#include "sim/init.hh"

extern "C" {
    void init_param_X86ACPIRSDP();
}

EmbeddedSwig embed_swig_param_X86ACPIRSDP(init_param_X86ACPIRSDP);
