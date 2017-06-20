%module(package="m5.internal") AbstractMemory_vector
%{
#include "params/AbstractMemory.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_AbstractMemory.i"

%include "std_vector.i"

%template(vector_AbstractMemory) std::vector< AbstractMemory * >;
