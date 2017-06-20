#include "sim/init.hh"

extern "C" {
    void init_param_VoltageDomain();
}

EmbeddedSwig embed_swig_param_VoltageDomain(init_param_VoltageDomain);
