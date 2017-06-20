%module(package="m5.internal") X86SMBiosSMBiosStructure_vector
%{
#include "params/X86SMBiosSMBiosStructure.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_X86SMBiosSMBiosStructure.i"

%include "std_vector.i"

%template(vector_X86SMBiosSMBiosStructure) std::vector< X86ISA::SMBios::SMBiosStructure * >;
