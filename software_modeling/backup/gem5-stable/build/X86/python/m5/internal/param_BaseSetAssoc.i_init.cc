#include "sim/init.hh"

extern "C" {
    void init_param_BaseSetAssoc();
}

EmbeddedSwig embed_swig_param_BaseSetAssoc(init_param_BaseSetAssoc);
