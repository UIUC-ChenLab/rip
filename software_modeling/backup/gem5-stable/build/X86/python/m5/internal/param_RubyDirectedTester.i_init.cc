#include "sim/init.hh"

extern "C" {
    void init_param_RubyDirectedTester();
}

EmbeddedSwig embed_swig_param_RubyDirectedTester(init_param_RubyDirectedTester);
