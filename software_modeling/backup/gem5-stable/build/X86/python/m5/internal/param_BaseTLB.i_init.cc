#include "sim/init.hh"

extern "C" {
    void init_param_BaseTLB();
}

EmbeddedSwig embed_swig_param_BaseTLB(init_param_BaseTLB);
