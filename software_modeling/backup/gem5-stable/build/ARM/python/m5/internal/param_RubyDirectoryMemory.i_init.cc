#include "sim/init.hh"

extern "C" {
    void init_param_RubyDirectoryMemory();
}

EmbeddedSwig embed_swig_param_RubyDirectoryMemory(init_param_RubyDirectoryMemory);
