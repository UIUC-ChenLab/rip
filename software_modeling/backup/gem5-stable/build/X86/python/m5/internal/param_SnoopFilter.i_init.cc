#include "sim/init.hh"

extern "C" {
    void init_param_SnoopFilter();
}

EmbeddedSwig embed_swig_param_SnoopFilter(init_param_SnoopFilter);
