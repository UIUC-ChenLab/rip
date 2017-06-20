#include "sim/init.hh"

extern "C" {
    void init_param_Pl111();
}

EmbeddedSwig embed_swig_param_Pl111(init_param_Pl111);
