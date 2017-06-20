#include "sim/init.hh"

extern "C" {
    void init_Process_vector();
}

EmbeddedSwig embed_swig_Process_vector(init_Process_vector);
