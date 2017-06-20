#include "sim/init.hh"

extern "C" {
    void init_param_BaseTags();
}

EmbeddedSwig embed_swig_param_BaseTags(init_param_BaseTags);
