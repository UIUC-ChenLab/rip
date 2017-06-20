%module(package="m5.internal") MinorOpClass_vector
%{
#include "params/MinorOpClass.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_MinorOpClass.i"

%include "std_vector.i"

%template(vector_MinorOpClass) std::vector< MinorOpClass * >;
