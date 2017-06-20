%module(package="m5.internal") MinorFUTiming_vector
%{
#include "params/MinorFUTiming.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_MinorFUTiming.i"

%include "std_vector.i"

%template(vector_MinorFUTiming) std::vector< MinorFUTiming * >;
