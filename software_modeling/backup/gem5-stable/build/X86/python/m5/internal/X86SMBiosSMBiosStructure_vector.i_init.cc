#include "sim/init.hh"

extern "C" {
    void init_X86SMBiosSMBiosStructure_vector();
}

EmbeddedSwig embed_swig_X86SMBiosSMBiosStructure_vector(init_X86SMBiosSMBiosStructure_vector);
