#include "sim/init.hh"

extern "C" {
    void init_param_MemTest();
}

EmbeddedSwig embed_swig_param_MemTest(init_param_MemTest);
