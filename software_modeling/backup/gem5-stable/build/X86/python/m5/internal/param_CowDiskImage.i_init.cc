#include "sim/init.hh"

extern "C" {
    void init_param_CowDiskImage();
}

EmbeddedSwig embed_swig_param_CowDiskImage(init_param_CowDiskImage);
