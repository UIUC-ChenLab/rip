#include "sim/init.hh"

extern "C" {
    void init_enum_OpClass();
}

EmbeddedSwig embed_swig_enum_OpClass(init_enum_OpClass);
