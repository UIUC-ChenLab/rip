#include "sim/init.hh"

extern "C" {
    void init_param_NetworkTest();
}

EmbeddedSwig embed_swig_param_NetworkTest(init_param_NetworkTest);
