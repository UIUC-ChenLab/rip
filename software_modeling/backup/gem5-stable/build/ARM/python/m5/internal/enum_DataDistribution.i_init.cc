#include "sim/init.hh"

extern "C" {
    void init_enum_DataDistribution();
}

EmbeddedSwig embed_swig_enum_DataDistribution(init_enum_DataDistribution);
