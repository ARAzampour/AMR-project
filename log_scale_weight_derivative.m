function dlog_weight = log_scale_weight_derivative(normalized_grid)
% First-order redistribution of equal probability mass after a log-scale shift.
%
% The normalized quadrature nodes are fixed. A multiplicative increase in
% the mean price moves probability toward the next higher node. The flux
% across each boundary is estimated from adjacent quantile-node spacing.

z = double(normalized_grid(:));
n = numel(z);

if n<2 || any(~isfinite(z)) || any(z<=0) || any(diff(z)<=0)
    error("The normalized price grid must contain at least two finite, positive, increasing nodes.");
end

probability_step = 1/n;
boundary = sqrt(z(1:end-1).*z(2:end));
density_at_boundary = probability_step./diff(z);
probability_flux = boundary.*density_at_boundary;

dlog_weight = zeros(n,1);
dlog_weight(1) = -probability_flux(1);
dlog_weight(2:n-1) = probability_flux(1:end-1)-probability_flux(2:end);
dlog_weight(n) = probability_flux(end);

% Remove roundoff while preserving total probability.
dlog_weight = dlog_weight-mean(dlog_weight);
end
