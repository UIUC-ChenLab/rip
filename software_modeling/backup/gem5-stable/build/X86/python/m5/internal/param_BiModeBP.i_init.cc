#include "sim/init.hh"

extern "C" {
    void init_param_BiModeBP();
}

EmbeddedSwig embed_swig_param_BiModeBP(init_param_BiModeBP);
