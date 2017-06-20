#include "sim/init.hh"

extern "C" {
    void init_param_Uart8250();
}

EmbeddedSwig embed_swig_param_Uart8250(init_param_Uart8250);
