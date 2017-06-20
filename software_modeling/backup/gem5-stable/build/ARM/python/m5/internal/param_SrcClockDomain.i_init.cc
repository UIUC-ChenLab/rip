#include "sim/init.hh"

extern "C" {
    void init_param_SrcClockDomain();
}

EmbeddedSwig embed_swig_param_SrcClockDomain(init_param_SrcClockDomain);
