#include "sim/init.hh"

extern "C" {
    void init_MinorFUTiming_vector();
}

EmbeddedSwig embed_swig_MinorFUTiming_vector(init_MinorFUTiming_vector);
