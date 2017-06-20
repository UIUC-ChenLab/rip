#include "sim/init.hh"

extern "C" {
    void init_X86ACPISysDescTable_vector();
}

EmbeddedSwig embed_swig_X86ACPISysDescTable_vector(init_X86ACPISysDescTable_vector);
