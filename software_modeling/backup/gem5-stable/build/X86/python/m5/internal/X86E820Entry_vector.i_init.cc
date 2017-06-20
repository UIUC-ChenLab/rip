#include "sim/init.hh"

extern "C" {
    void init_X86E820Entry_vector();
}

EmbeddedSwig embed_swig_X86E820Entry_vector(init_X86E820Entry_vector);
