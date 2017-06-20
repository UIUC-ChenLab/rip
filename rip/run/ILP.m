function [x, latency, power, decision, bram, dsp, lut, ff] = ILP(powerStart, powerEnd,nodes, cnodes, sampleHw, zConstraints, mayShareNodes)
A = importdata('./outputA.txt');
B = importdata('./outputB.txt');
f = importdata('./outputf.txt');
Aeq = importdata('./outputAeq.txt');
Beq = importdata('./outputBeq.txt');
%nodes = 6;
%cnodes = 2;
%sampleHw = 5;


cnodesVar = (sampleHw+1)*cnodes;
varNum = cnodesVar + nodes + zConstraints + sampleHw * mayShareNodes;
lb = zeros(1,varNum);
ub_a = inf(1,nodes);
ub_b = ones(1,cnodesVar+zConstraints + sampleHw*mayShareNodes);
ub = [ub_a, ub_b];
intcon= double(nodes+1: varNum);
x=intlinprog(f,intcon,A,B,Aeq,Beq,lb,ub);

%to see the decision
decision = inf(cnodes,1);


Asize = size(A);

%number of rows
Arow = Asize(1);

%power index
powerS_idx = powerStart +1;
powerE_idx = powerEnd + 1;

power_old = 0;
for i = powerS_idx : powerE_idx
    power_row = A(i, :);
    power_tmp = power_row * x;
    power_tmp
    if(power_tmp > power_old)
        power_old = power_tmp;
    end
end

%energy_matrix = A(Arow-4,:);
bram_matrix = A(Arow-3,:);
dsp_matrix = A(Arow-2,:);
lut_matrix = A(Arow-1,:);
ff_matrix = A(Arow,:);
bram = bram_matrix * x;
dsp = dsp_matrix * x;
lut = lut_matrix * x;
ff = ff_matrix * x;
latency = x(nodes);
power = power_old;
%energy = energy_matrix *x;
    for i = 1:cnodes
    for j = 1:sampleHw+1
        index = nodes+(i-1)*(sampleHw+1)+j;
        if(round(x(index)) == 1)
            decision(i) = j-1;
            break;
        end
    end
end
