#include "sim/init.hh"

extern "C" {
    void init_param_O3Checker();
}

EmbeddedSwig embed_swig_param_O3Checker(init_param_O3Checker);
