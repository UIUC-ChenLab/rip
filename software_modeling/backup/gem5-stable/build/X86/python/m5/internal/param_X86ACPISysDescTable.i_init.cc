#include "sim/init.hh"

extern "C" {
    void init_param_X86ACPISysDescTable();
}

EmbeddedSwig embed_swig_param_X86ACPISysDescTable(init_param_X86ACPISysDescTable);
