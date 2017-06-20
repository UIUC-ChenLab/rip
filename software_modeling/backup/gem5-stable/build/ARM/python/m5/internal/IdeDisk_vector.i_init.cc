#include "sim/init.hh"

extern "C" {
    void init_IdeDisk_vector();
}

EmbeddedSwig embed_swig_IdeDisk_vector(init_IdeDisk_vector);
