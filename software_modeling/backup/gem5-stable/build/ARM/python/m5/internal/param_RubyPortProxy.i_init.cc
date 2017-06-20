#include "sim/init.hh"

extern "C" {
    void init_param_RubyPortProxy();
}

EmbeddedSwig embed_swig_param_RubyPortProxy(init_param_RubyPortProxy);
