#include "sim/init.hh"

extern "C" {
    void init_enum_MemoryMode();
}

EmbeddedSwig embed_swig_enum_MemoryMode(init_enum_MemoryMode);
