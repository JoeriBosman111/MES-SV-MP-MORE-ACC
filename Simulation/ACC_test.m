clc
clear all
close all

%load('MPCDesignerSession.mat')
%% Parameters

m = 1000;
b = 50;

%% Vehicle Model
% Transfer function vehicle model
num = 1;
den = [m b];
G = tf(num,den);

t = 1:0.01:100;
u = zeros(length(t),1);
u(1:end) = 140;

y = lsim(G,u,t);

%plot(t,y)

% DC Motor
J = (1/2)*0.15*0.02^2;
D = 0.000004;
T_stall = 1.77;
e_max = 12;
KtRa = T_stall/e_max;
w_noload = 26;
Kb = e_max/w_noload;

num_dc = KtRa/J;
den_dc = [1 (1/J)*(D+KtRa*Kb)];
sim('ACC_test_sim.slx')

%% Plot

figure()
yyaxis left
plot(tout,gap)
ylabel('Lead Distance [m]')
yyaxis right
plot(tout,ACC_CC_Switch)
xlabel('Time [s]')
ylabel('ACC Enabled Signal')
ylim([0 2])
title('Distance between leading and ego vehicle')
grid on

figure()
plot(tout,ego_speed,tout,lead_speed)
xlabel('Time [s]')
ylabel('Speed [m/s]')
legend('Ego vehicle speed','Lead vehicle speed')
title('Ego and lead vehicle speed')
grid on