#include "sim/init.hh"

extern "C" {
    void init_param_SeriesRequestGenerator();
}

EmbeddedSwig embed_swig_param_SeriesRequestGenerator(init_param_SeriesRequestGenerator);
