#include "sim/init.hh"

extern "C" {
    void init_param_X86IntelMPConfigTable();
}

EmbeddedSwig embed_swig_param_X86IntelMPConfigTable(init_param_X86IntelMPConfigTable);
