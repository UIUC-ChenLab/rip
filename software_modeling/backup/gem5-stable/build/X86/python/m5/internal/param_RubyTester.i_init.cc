#include "sim/init.hh"

extern "C" {
    void init_param_RubyTester();
}

EmbeddedSwig embed_swig_param_RubyTester(init_param_RubyTester);
