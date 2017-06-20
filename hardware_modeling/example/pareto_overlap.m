pareto_curve = csvread('atax_measured_pareto.csv');
figure(9);
hold on;
scatter(pareto_curve(:,end),pareto_curve(:,end-1),'+');
hold off;