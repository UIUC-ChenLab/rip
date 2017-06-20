%module(package="m5.internal") Float_vector
%{
%}

%include "std_container.i"


%include "std_vector.i"

%template(vector_Float) std::vector< double >;
