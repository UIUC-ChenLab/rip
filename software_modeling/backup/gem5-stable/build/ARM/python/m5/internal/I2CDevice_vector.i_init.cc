#include "sim/init.hh"

extern "C" {
    void init_I2CDevice_vector();
}

EmbeddedSwig embed_swig_I2CDevice_vector(init_I2CDevice_vector);
