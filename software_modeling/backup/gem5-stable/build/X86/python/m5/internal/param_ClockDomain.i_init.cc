#include "sim/init.hh"

extern "C" {
    void init_param_ClockDomain();
}

EmbeddedSwig embed_swig_param_ClockDomain(init_param_ClockDomain);
