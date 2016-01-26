%% Root Finding Interval Test
clear;close all;clc;
tic

format long;

left_bound = 0.0;
right_bound = 2.0;
max_iter = 1000;
eps_abs = 1e-5;
eps_step = 1e-5;

root = interval_roots(left_bound, right_bound, max_iter, eps_step, eps_abs);

disp(root);

toc