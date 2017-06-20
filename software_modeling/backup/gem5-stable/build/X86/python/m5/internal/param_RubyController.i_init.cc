#include "sim/init.hh"

extern "C" {
    void init_param_RubyController();
}

EmbeddedSwig embed_swig_param_RubyController(init_param_RubyController);
