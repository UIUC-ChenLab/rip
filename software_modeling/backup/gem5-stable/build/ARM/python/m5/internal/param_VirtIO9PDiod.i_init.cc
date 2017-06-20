#include "sim/init.hh"

extern "C" {
    void init_param_VirtIO9PDiod();
}

EmbeddedSwig embed_swig_param_VirtIO9PDiod(init_param_VirtIO9PDiod);
