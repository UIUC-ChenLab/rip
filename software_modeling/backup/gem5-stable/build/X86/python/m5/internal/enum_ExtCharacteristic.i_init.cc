#include "sim/init.hh"

extern "C" {
    void init_enum_ExtCharacteristic();
}

EmbeddedSwig embed_swig_enum_ExtCharacteristic(init_enum_ExtCharacteristic);
