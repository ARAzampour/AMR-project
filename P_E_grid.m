function Pgrid = P_E_grid(np,E_P)


    % PARAMETERS
    kappa = 0.8;
    rho = 1 - kappa;
    sigma = 0.4;

    lambda = 0.2;

    % Jump parameters (log space)
    muJ = 1;
    sigmaJ = 0.5;

    % Target mean
    target_mean = E_P;

    % Compute Var(p)
    EJ2 = sigmaJ^2 + muJ^2;
    var_p = (sigma^2 + lambda * EJ2) / (2*kappa - kappa^2);

    % Adjust mean
    pbar = log(target_mean) - 0.5 * var_p;

    % SIMULATION
    T = 10000000;
    burn = 50000;

    p = zeros(T,1);
    p(1) = pbar;

    for t = 2:T
        
        eps = randn;

        if rand < lambda
            J = muJ + sigmaJ * randn;
        else
            J = 0;
        end

        p(t) = rho * p(t-1) + kappa * pbar + sigma * eps + J;
    end

    P = exp(p(burn+1:end));

    % Quantile grid
    q = ((1:np) - 0.5) / np;
    Pgrid = quantile(P, q);

end