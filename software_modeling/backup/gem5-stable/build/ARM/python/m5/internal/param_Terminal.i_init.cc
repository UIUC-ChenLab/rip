#include "sim/init.hh"

extern "C" {
    void init_param_Terminal();
}

EmbeddedSwig embed_swig_param_Terminal(init_param_Terminal);
