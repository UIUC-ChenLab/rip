#include "sim/init.hh"

extern "C" {
    void init_param_CreditLink_d();
}

EmbeddedSwig embed_swig_param_CreditLink_d(init_param_CreditLink_d);
