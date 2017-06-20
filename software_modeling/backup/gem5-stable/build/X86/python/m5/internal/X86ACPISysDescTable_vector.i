%module(package="m5.internal") X86ACPISysDescTable_vector
%{
#include "params/X86ACPISysDescTable.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_X86ACPISysDescTable.i"

%include "std_vector.i"

%template(vector_X86ACPISysDescTable) std::vector< X86ISA::ACPI::SysDescTable * >;
