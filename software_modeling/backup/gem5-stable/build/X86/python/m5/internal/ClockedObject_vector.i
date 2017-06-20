%module(package="m5.internal") ClockedObject_vector
%{
#include "params/ClockedObject.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_ClockedObject.i"

%include "std_vector.i"

%template(vector_ClockedObject) std::vector< ClockedObject * >;
