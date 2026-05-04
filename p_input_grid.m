function Pgrid = p_input_grid(np, mean_price, sigma_p, rho)

    % INPUTS:
    % mean_price = E[P]
    % sigma_p = std dev of log price innovation
    % rho = persistence (e.g. 0.95)

    % Convert to kappa
    kappa = 1 - rho;

    % Stationary variance of log price
    var_p = sigma_p^2 / (2*kappa - kappa^2);

    % Mean of log price (adjust for lognormal)
    m = log(mean_price) - 0.5 * var_p;

    % Quantiles
    q = ((1:np) - 0.5) / np;

    % Inverse CDF of lognormal
    Pgrid = exp(m + sqrt(var_p) * norminv(q));

end