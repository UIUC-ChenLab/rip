%module(package="m5.internal") ArmISA_vector
%{
#include "params/ArmISA.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_ArmISA.i"

%include "std_vector.i"

%template(vector_ArmISA) std::vector< ArmISA::ISA * >;
