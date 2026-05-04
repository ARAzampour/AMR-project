function [eff_vec, cap_vec, pi_vec] = static_solver(a_eff, P_E_vec, p_e_vec, alpha, fco, e_max_vec)
% Solves the static hourly dispatch problem for all generator states.
%
% For each realization of electricity and input prices, the generator chooses
% utilization x in [0,1]. Expected input, output, and variable profit are
% averaged across price realizations. The fixed operating cost is paid once
% by every non-exited plant, so it is subtracted after taking expectations.
%
% Production function:
%   q(x) = x * (1 - (1-x)^alpha),  where x = a_eff * e
%
% Input:
%   e = x / a_eff
%
% Hourly variable profit:
%   max_x P_E * q(x) - p_e * e(x)
%
% Annual/current profit:
%   E[hourly variable profit] - fco

x_num  = 400;
x_grid = single(linspace(0, 1, x_num)');             % (x_num x 1)
q_of_x = x_grid .* (1 - (1-x_grid).^single(alpha));  % (x_num x 1)

P_E_vec = single(P_E_vec(:));
p_e_vec = single(p_e_vec(:));
n_PE    = numel(P_E_vec);
n_pe    = numel(p_e_vec);

[a_num_g, age_num] = size(a_eff);
N = a_num_g * age_num;

a_flat = single(reshape(a_eff, 1, N));       % (1 x N)  row of all states
a_safe = max(a_flat, single(1e-10));         % guard against zero/negative a_eff

e_base = x_grid ./ a_safe;                   % (x_num x N)
q_base = repmat(q_of_x, 1, N);               % (x_num x N)

%%% e_M = 1/a_{i,0}: capacity input limit is generator-specific.
e_max_flat = single(reshape(repmat(e_max_vec(:), 1, age_num), 1, N));
feasible = e_base <= e_max_flat;
q_base_feasible = q_base;
q_base_feasible(~feasible) = -inf;           % x=0 remains feasible and gives zero variable profit.

eff_sum = zeros(N, 1, "single");
cap_sum = zeros(N, 1, "single");
pi_sum  = zeros(N, 1, "single");

state_idx = repmat(1:N, 1, n_pe);
col_offset = uint32((state_idx-1) * x_num);

for iPE = 1:n_PE
    % pi_mat is the intentionally large object: x_grid x states x input prices.
    % Keep it single precision to halve memory use.
    pi_mat = P_E_vec(iPE) .* q_base_feasible - e_base .* reshape(p_e_vec, 1, 1, n_pe);
    pi_mat = reshape(pi_mat, x_num, N*n_pe);

    [pi_best, idx_best] = max(pi_mat, [], 1);

    lin_idx  = double(uint32(idx_best) + col_offset);
    eff_best = e_base(lin_idx);
    cap_best = q_base(lin_idx);

    eff_sum = eff_sum + sum(reshape(eff_best, N, n_pe), 2);
    cap_sum = cap_sum + sum(reshape(cap_best, N, n_pe), 2);
    pi_sum  = pi_sum  + sum(reshape(pi_best,  N, n_pe), 2);
end

price_count = single(n_PE * n_pe);
eff_vec = double(reshape(eff_sum ./ price_count, a_num_g, age_num));
cap_vec = double(reshape(cap_sum ./ price_count, a_num_g, age_num));
pi_vec  = double(reshape(pi_sum  ./ price_count, a_num_g, age_num)) - fco;

end
