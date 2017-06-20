#include "sim/init.hh"

extern "C" {
    void init_param_HDLcd();
}

EmbeddedSwig embed_swig_param_HDLcd(init_param_HDLcd);
