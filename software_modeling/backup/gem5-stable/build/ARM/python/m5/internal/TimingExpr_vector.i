%module(package="m5.internal") TimingExpr_vector
%{
#include "params/TimingExpr.hh"
%}

%include "std_container.i"

%import "python/m5/internal/param_TimingExpr.i"

%include "std_vector.i"

%template(vector_TimingExpr) std::vector< TimingExpr * >;
