#include "sim/init.hh"

extern "C" {
    void init_param_Directory_Controller();
}

EmbeddedSwig embed_swig_param_Directory_Controller(init_param_Directory_Controller);
