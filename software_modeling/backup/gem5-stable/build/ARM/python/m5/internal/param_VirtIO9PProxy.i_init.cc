#include "sim/init.hh"

extern "C" {
    void init_param_VirtIO9PProxy();
}

EmbeddedSwig embed_swig_param_VirtIO9PProxy(init_param_VirtIO9PProxy);
