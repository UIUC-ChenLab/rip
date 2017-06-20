#include "sim/init.hh"

extern "C" {
    void init_param_I2CBus();
}

EmbeddedSwig embed_swig_param_I2CBus(init_param_I2CBus);
