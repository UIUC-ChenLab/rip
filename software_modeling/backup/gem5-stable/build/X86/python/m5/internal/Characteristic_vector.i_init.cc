#include "sim/init.hh"

extern "C" {
    void init_Characteristic_vector();
}

EmbeddedSwig embed_swig_Characteristic_vector(init_Characteristic_vector);
