function [eff_vec, cap_vec, pi_vec] = solar_static_solver(a_eff, P_E_vec, solar_cap_vec, fco)
% Static problem for intermittent green generators.
%
% Green generators do not choose a fuel input. In every hourly state they
% produce their available capacity. The availability path should be ordered to
% match P_E_vec and is typically negatively correlated with electricity prices.
%
% Inputs:
%   a_eff         (a_num_g x age_num) base capacity/productivity by state
%   P_E_vec       hourly electricity price grid
%   solar_cap_vec hourly availability/max-capacity factor in [0,1]
%   fco           fixed operating cost paid once per period
%
% Outputs:
%   eff_vec       zero fuel input
%   cap_vec       expected output
%   pi_vec        expected revenue minus fixed operating cost

P_E_vec = P_E_vec(:);
solar_cap_vec = solar_cap_vec(:);

if numel(P_E_vec) ~= numel(solar_cap_vec)
    error("P_E_vec and solar_cap_vec must have the same number of grid points.");
end

solar_cap_vec = max(min(solar_cap_vec,1),0);
expected_cap_factor = mean(solar_cap_vec);
expected_price_cap  = mean(P_E_vec.*solar_cap_vec);

eff_vec = zeros(size(a_eff));
cap_vec = a_eff .* expected_cap_factor;
pi_vec  = a_eff .* expected_price_cap - fco;

end
