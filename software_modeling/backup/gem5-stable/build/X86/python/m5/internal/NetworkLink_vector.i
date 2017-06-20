%module(package="m5.internal") NetworkLink_vector
%{
#include "params/NetworkLink.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_NetworkLink.i"

%include "std_vector.i"

%template(vector_NetworkLink) std::vector< NetworkLink * >;
