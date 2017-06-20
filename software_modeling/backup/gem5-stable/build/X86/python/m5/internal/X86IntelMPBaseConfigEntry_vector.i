%module(package="m5.internal") X86IntelMPBaseConfigEntry_vector
%{
#include "params/X86IntelMPBaseConfigEntry.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_X86IntelMPBaseConfigEntry.i"

%include "std_vector.i"

%template(vector_X86IntelMPBaseConfigEntry) std::vector< X86ISA::IntelMP::BaseConfigEntry * >;
