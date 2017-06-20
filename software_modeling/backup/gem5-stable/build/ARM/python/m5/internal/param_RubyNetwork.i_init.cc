#include "sim/init.hh"

extern "C" {
    void init_param_RubyNetwork();
}

EmbeddedSwig embed_swig_param_RubyNetwork(init_param_RubyNetwork);
