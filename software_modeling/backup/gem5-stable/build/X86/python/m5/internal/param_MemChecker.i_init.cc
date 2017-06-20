#include "sim/init.hh"

extern "C" {
    void init_param_MemChecker();
}

EmbeddedSwig embed_swig_param_MemChecker(init_param_MemChecker);
