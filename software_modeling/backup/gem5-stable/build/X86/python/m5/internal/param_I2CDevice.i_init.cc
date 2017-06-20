#include "sim/init.hh"

extern "C" {
    void init_param_I2CDevice();
}

EmbeddedSwig embed_swig_param_I2CDevice(init_param_I2CDevice);
