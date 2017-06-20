#include "sim/init.hh"

extern "C" {
    void init_param_RawDiskImage();
}

EmbeddedSwig embed_swig_param_RawDiskImage(init_param_RawDiskImage);
