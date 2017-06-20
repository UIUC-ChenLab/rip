#include "sim/init.hh"

extern "C" {
    void init_param_RubyCache();
}

EmbeddedSwig embed_swig_param_RubyCache(init_param_RubyCache);
