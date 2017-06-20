#include "sim/init.hh"

extern "C" {
    void init_param_Pc();
}

EmbeddedSwig embed_swig_param_Pc(init_param_Pc);
