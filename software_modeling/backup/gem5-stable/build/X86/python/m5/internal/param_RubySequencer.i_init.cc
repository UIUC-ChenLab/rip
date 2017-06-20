#include "sim/init.hh"

extern "C" {
    void init_param_RubySequencer();
}

EmbeddedSwig embed_swig_param_RubySequencer(init_param_RubySequencer);
