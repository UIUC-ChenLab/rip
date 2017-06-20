#include "sim/init.hh"

extern "C" {
    void init_param_RubySystem();
}

EmbeddedSwig embed_swig_param_RubySystem(init_param_RubySystem);
