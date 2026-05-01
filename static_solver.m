function [eff_vec, cap_vec, pi_vec] = static_solver(a_eff, p_E, p_e, alpha, fco, e_max_vec)
% Solves the static production problem for all generator states.
%
% Production function (in terms of utilization x = a_eff * e,  x in [0,1]):
%   q(x) = x * (1 - (1-x)^alpha)
%
% Optimal input from utilization:
%   e = x / a_eff
%
% Per-unit profit:
%   pi = p_E * q(x) - p_e * e - fco
%
% Subject to the per-generator input capacity constraint:  e <= e_M = 1/a_{i,0}
% The constraint is generator-specific: a generator with base productivity a_i
% can take at most 1/a_i units of fuel (the level that achieves full utilization).
%
% Solved by grid search over x in [0,1] for every state.
%
% Inputs:
%   a_eff    : (a_num_g x age_num) effective productivity,
%              a_eff(i,t) = a_i * max(1 - a_grow*t, 0)
%   p_E      : electricity price (scalar)
%   p_e      : fuel input price (scalar)
%   alpha    : production function curvature  (0 < alpha < 1)
%   fco      : fixed operating cost (scalar)
%   e_max_vec: (a_num_g x 1) maximum fuel input per generator = 1./a_grid
%
% Outputs  (all a_num_g x age_num):
%   eff_vec : optimal fuel input  e*
%   cap_vec : optimal output      q*
%   pi_vec  : optimal profit      pi*

x_num  = 400;
x_grid = linspace(0, 1, x_num)';             % (x_num x 1)
q_of_x = x_grid .* (1 - (1-x_grid).^alpha); % (x_num x 1)

[a_num_g, age_num] = size(a_eff);
N = a_num_g * age_num;

a_flat = reshape(a_eff, 1, N);               % (1 x N)  row of all states
a_safe = max(a_flat, 1e-10);                 % guard against zero/negative a_eff

e_mat  = x_grid ./ a_safe;                  % (x_num x N)  input for each (x, state)
q_mat  = repmat(q_of_x, 1, N);              % (x_num x N)  output (price-independent)

pi_mat = p_E * q_mat - p_e * e_mat - fco;   % (x_num x N)

%%% e_M = 1/a_{i,0}: capacity input limit is generator-specific (varies by a_grid row)
e_max_flat = reshape(repmat(e_max_vec(:), 1, age_num), 1, N);  % (1 x N)
pi_mat(e_mat > e_max_flat) = -inf;          % enforce per-generator input capacity
% x=0 is always feasible (e=0 <= e_M for any generator), giving pi = -fco.

[pi_best, idx_best] = max(pi_mat, [], 1);   % (1 x N)

lin_idx  = idx_best + (0:N-1) * x_num;      % linear indices into e_mat (column-major)
eff_flat = e_mat(lin_idx);                  % (1 x N)  optimal fuel input
cap_flat = q_of_x(idx_best);               % (1 x N)  optimal output

eff_vec = reshape(eff_flat, a_num_g, age_num);
cap_vec = reshape(cap_flat, a_num_g, age_num);
pi_vec  = reshape(pi_best,  a_num_g, age_num);

end
