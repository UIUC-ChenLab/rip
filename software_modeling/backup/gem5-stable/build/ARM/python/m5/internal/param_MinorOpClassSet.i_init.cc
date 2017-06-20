#include "sim/init.hh"

extern "C" {
    void init_param_MinorOpClassSet();
}

EmbeddedSwig embed_swig_param_MinorOpClassSet(init_param_MinorOpClassSet);
