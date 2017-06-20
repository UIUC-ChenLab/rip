%module(package="m5.internal") X86E820Entry_vector
%{
#include "params/X86E820Entry.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_X86E820Entry.i"

%include "std_vector.i"

%template(vector_X86E820Entry) std::vector< X86ISA::E820Entry * >;
