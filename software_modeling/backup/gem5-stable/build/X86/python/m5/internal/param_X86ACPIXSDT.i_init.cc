#include "sim/init.hh"

extern "C" {
    void init_param_X86ACPIXSDT();
}

EmbeddedSwig embed_swig_param_X86ACPIXSDT(init_param_X86ACPIXSDT);
