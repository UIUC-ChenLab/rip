%module(package="m5.internal") NetworkLink_d_vector
%{
#include "params/NetworkLink_d.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_NetworkLink_d.i"

%include "std_vector.i"

%template(vector_NetworkLink_d) std::vector< NetworkLink_d * >;
