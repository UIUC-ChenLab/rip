#include "sim/init.hh"

extern "C" {
    void init_param_TournamentBP();
}

EmbeddedSwig embed_swig_param_TournamentBP(init_param_TournamentBP);
