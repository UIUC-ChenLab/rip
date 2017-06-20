#include "sim/init.hh"

extern "C" {
    void init_CreditLink_d_vector();
}

EmbeddedSwig embed_swig_CreditLink_d_vector(init_CreditLink_d_vector);
