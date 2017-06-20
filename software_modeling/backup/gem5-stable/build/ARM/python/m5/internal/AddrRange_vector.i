%module(package="m5.internal") AddrRange_vector
%{
#include "base/types.hh"
#include "base/addr_range.hh"
%}

%include "std_container.i"

%import "stdint.i"
%import "base/types.hh"

%include "std_vector.i"

%template(vector_AddrRange) std::vector< AddrRange >;
