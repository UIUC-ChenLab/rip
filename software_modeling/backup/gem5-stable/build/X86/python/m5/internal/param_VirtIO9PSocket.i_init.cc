#include "sim/init.hh"

extern "C" {
    void init_param_VirtIO9PSocket();
}

EmbeddedSwig embed_swig_param_VirtIO9PSocket(init_param_VirtIO9PSocket);
