%module(package="m5.internal") CreditLink_d_vector
%{
#include "params/CreditLink_d.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_CreditLink_d.i"

%include "std_vector.i"

%template(vector_CreditLink_d) std::vector< CreditLink_d * >;
