#include "sim/init.hh"

extern "C" {
    void init_param_L1Cache_Controller();
}

EmbeddedSwig embed_swig_param_L1Cache_Controller(init_param_L1Cache_Controller);
