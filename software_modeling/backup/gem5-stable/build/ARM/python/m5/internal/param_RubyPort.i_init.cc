#include "sim/init.hh"

extern "C" {
    void init_param_RubyPort();
}

EmbeddedSwig embed_swig_param_RubyPort(init_param_RubyPort);
