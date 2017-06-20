#include "sim/init.hh"

extern "C" {
    void init_param_Platform();
}

EmbeddedSwig embed_swig_param_Platform(init_param_Platform);
