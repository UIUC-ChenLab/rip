#include "sim/init.hh"

extern "C" {
    void init_enum_Characteristic();
}

EmbeddedSwig embed_swig_enum_Characteristic(init_enum_Characteristic);
