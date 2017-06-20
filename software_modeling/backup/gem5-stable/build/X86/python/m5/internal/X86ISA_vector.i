%module(package="m5.internal") X86ISA_vector
%{
#include "params/X86ISA.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_X86ISA.i"

%include "std_vector.i"

%template(vector_X86ISA) std::vector< X86ISA::ISA * >;
