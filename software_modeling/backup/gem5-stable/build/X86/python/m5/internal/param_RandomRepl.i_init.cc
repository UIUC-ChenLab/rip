#include "sim/init.hh"

extern "C" {
    void init_param_RandomRepl();
}

EmbeddedSwig embed_swig_param_RandomRepl(init_param_RandomRepl);
