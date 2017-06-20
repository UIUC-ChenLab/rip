%module(package="m5.internal") Int_vector
%{
#include "base/types.hh"
%}

%include "std_container.i"

%import "stdint.i"
%import "base/types.hh"

%include "std_vector.i"

%template(vector_Int) std::vector< int >;
