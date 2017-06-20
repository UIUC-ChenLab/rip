%module(package="m5.internal") BasicRouter_vector
%{
#include "params/BasicRouter.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_BasicRouter.i"

%include "std_vector.i"

%template(vector_BasicRouter) std::vector< BasicRouter * >;
