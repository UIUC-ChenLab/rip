#include "sim/init.hh"

extern "C" {
    void init_param_ExternalSlave();
}

EmbeddedSwig embed_swig_param_ExternalSlave(init_param_ExternalSlave);
