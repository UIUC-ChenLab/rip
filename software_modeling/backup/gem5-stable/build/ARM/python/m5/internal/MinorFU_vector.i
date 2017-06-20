%module(package="m5.internal") MinorFU_vector
%{
#include "params/MinorFU.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_MinorFU.i"

%include "std_vector.i"

%template(vector_MinorFU) std::vector< MinorFU * >;
