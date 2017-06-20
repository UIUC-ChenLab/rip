#include "sim/init.hh"

extern "C" {
    void init_param_DMA_Controller();
}

EmbeddedSwig embed_swig_param_DMA_Controller(init_param_DMA_Controller);
