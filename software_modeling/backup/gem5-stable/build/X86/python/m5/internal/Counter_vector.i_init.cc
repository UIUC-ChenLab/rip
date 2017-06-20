#include "sim/init.hh"

extern "C" {
    void init_Counter_vector();
}

EmbeddedSwig embed_swig_Counter_vector(init_Counter_vector);
