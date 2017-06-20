%module(package="m5.internal") OpDesc_vector
%{
#include "params/OpDesc.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_OpDesc.i"

%include "std_vector.i"

%template(vector_OpDesc) std::vector< OpDesc * >;
