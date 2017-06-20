#include "sim/init.hh"

extern "C" {
    void init_Voltage_vector();
}

EmbeddedSwig embed_swig_Voltage_vector(init_Voltage_vector);
