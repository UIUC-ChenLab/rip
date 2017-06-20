#include "sim/init.hh"

extern "C" {
    void init_param_DiskImage();
}

EmbeddedSwig embed_swig_param_DiskImage(init_param_DiskImage);
