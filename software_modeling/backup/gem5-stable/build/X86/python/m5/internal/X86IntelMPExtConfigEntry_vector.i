%module(package="m5.internal") X86IntelMPExtConfigEntry_vector
%{
#include "params/X86IntelMPExtConfigEntry.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_X86IntelMPExtConfigEntry.i"

%include "std_vector.i"

%template(vector_X86IntelMPExtConfigEntry) std::vector< X86ISA::IntelMP::ExtConfigEntry * >;
