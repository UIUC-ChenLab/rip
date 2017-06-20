%module(package="m5.internal") Voltage_vector
%{
%}

%include "std_container.i"


%include "std_vector.i"

%template(vector_Voltage) std::vector< double >;
