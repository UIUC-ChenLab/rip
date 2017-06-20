#include "sim/init.hh"

extern "C" {
    void init_param_RangeAddrMapper();
}

EmbeddedSwig embed_swig_param_RangeAddrMapper(init_param_RangeAddrMapper);
