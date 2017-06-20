%module(package="m5.internal") BasicExtLink_vector
%{
#include "params/BasicExtLink.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_BasicExtLink.i"

%include "std_vector.i"

%template(vector_BasicExtLink) std::vector< BasicExtLink * >;
