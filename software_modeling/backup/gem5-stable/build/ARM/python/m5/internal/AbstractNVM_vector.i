%module(package="m5.internal") AbstractNVM_vector
%{
#include "params/AbstractNVM.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_AbstractNVM.i"

%include "std_vector.i"

%template(vector_AbstractNVM) std::vector< AbstractNVM * >;
