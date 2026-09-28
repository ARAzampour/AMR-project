function result = static_solver_anchor(a_eff,p_E,p_e,P_E_grid_norm,p_e_grid_norm,...
    alpha,fco,e_max_vec,dlog_weight_PE,dlog_weight_pe,anchor,relative_threshold)
% Reuse a first-order static solution while both prices remain near an exact anchor.

has_anchor = isstruct(anchor) && isfield(anchor,"anchor_p_E") && ...
    isfinite(anchor.anchor_p_E) && isfinite(anchor.anchor_p_e);

if has_anchor
    relative_PE = abs(p_E/anchor.anchor_p_E-1);
    relative_pe = abs(p_e/anchor.anchor_p_e-1);
else
    relative_PE = inf;
    relative_pe = inf;
end

if relative_PE<relative_threshold && relative_pe<relative_threshold
    result = anchor;
    dlog_PE = single(log(p_E/anchor.anchor_p_E));
    dlog_pe = single(log(p_e/anchor.anchor_p_e));

    result.eff = anchor.eff_anchor + anchor.d_eff_PE.*dlog_PE + anchor.d_eff_pe.*dlog_pe;
    result.cap = anchor.cap_anchor + anchor.d_cap_PE.*dlog_PE + anchor.d_cap_pe.*dlog_pe;
    result.pi  = anchor.pi_anchor  + anchor.d_pi_PE.*dlog_PE  + anchor.d_pi_pe.*dlog_pe;

    [~,age_num] = size(a_eff);
    eff_upper = single(repmat(e_max_vec(:),1,age_num));
    result.eff = min(max(result.eff,single(0)),eff_upper);
    result.cap = min(max(result.cap,single(0)),single(1));
    result.used_approximation = true;
    return
end

[eff,cap,pi,slopes] = static_solver(a_eff,p_E.*P_E_grid_norm,p_e.*p_e_grid_norm,...
    alpha,fco,e_max_vec,dlog_weight_PE,dlog_weight_pe);

result.eff = single(eff);
result.cap = single(cap);
result.pi  = single(pi);
result.eff_anchor = result.eff;
result.cap_anchor = result.cap;
result.pi_anchor  = result.pi;
result.d_eff_PE = single(slopes.eff_log_PE);
result.d_eff_pe = single(slopes.eff_log_pe);
result.d_cap_PE = single(slopes.cap_log_PE);
result.d_cap_pe = single(slopes.cap_log_pe);
result.d_pi_PE  = single(slopes.pi_log_PE);
result.d_pi_pe  = single(slopes.pi_log_pe);
result.anchor_p_E = p_E;
result.anchor_p_e = p_e;
result.used_approximation = false;
end
