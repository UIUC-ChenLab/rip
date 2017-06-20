#include "sim/init.hh"

extern "C" {
    void init_param_Pl050();
}

EmbeddedSwig embed_swig_param_Pl050(init_param_Pl050);
