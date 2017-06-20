#include "sim/init.hh"

extern "C" {
    void init_param_RubyWireBuffer();
}

EmbeddedSwig embed_swig_param_RubyWireBuffer(init_param_RubyWireBuffer);
