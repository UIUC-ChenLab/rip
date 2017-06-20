%module(package="m5.internal") FUDesc_vector
%{
#include "params/FUDesc.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_FUDesc.i"

%include "std_vector.i"

%template(vector_FUDesc) std::vector< FUDesc * >;
