#include "sim/init.hh"

extern "C" {
    void init_param_VirtIOBlock();
}

EmbeddedSwig embed_swig_param_VirtIOBlock(init_param_VirtIOBlock);
