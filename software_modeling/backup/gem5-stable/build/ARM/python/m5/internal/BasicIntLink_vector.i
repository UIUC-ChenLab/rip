%module(package="m5.internal") BasicIntLink_vector
%{
#include "params/BasicIntLink.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_BasicIntLink.i"

%include "std_vector.i"

%template(vector_BasicIntLink) std::vector< BasicIntLink * >;
