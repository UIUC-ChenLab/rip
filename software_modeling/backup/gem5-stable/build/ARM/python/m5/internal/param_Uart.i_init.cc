#include "sim/init.hh"

extern "C" {
    void init_param_Uart();
}

EmbeddedSwig embed_swig_param_Uart(init_param_Uart);
