#include "sim/init.hh"

extern "C" {
    void init_param_AddrMapper();
}

EmbeddedSwig embed_swig_param_AddrMapper(init_param_AddrMapper);
