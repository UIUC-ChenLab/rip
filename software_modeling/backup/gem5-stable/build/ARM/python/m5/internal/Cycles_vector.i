%module(package="m5.internal") Cycles_vector
%{
#include "base/types.hh"
%}

%include "std_container.i"

%import "stdint.i"
%import "base/types.hh"

%include "std_vector.i"

%template(vector_Cycles) std::vector< Cycles >;
