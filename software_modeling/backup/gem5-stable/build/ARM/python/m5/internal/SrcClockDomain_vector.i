%module(package="m5.internal") SrcClockDomain_vector
%{
#include "params/SrcClockDomain.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_SrcClockDomain.i"

%include "std_vector.i"

%template(vector_SrcClockDomain) std::vector< SrcClockDomain * >;
