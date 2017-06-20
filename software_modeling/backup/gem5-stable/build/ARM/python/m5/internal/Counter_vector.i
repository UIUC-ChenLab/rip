%module(package="m5.internal") Counter_vector
%{
#include "base/types.hh"
%}

%include "std_container.i"

%import "stdint.i"
%import "base/types.hh"

%include "std_vector.i"

%template(vector_Counter) std::vector< Counter >;
