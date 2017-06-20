#include "sim/init.hh"

extern "C" {
    void init_DiskImage_vector();
}

EmbeddedSwig embed_swig_DiskImage_vector(init_DiskImage_vector);
