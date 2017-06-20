#include "sim/init.hh"

extern "C" {
    void init_param_RubyMemoryControl();
}

EmbeddedSwig embed_swig_param_RubyMemoryControl(init_param_RubyMemoryControl);
