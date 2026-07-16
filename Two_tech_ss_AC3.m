function [trans_prob_o,v_new_o,v_new_resh_o,dist_o,trans_matrix_n,p_e_n,cap_contemp_new,eff_n_final,...
    trans_prob_n,v_new_n,v_new_resh_n,dist_n,trans_matrix_o,p_e_o,cap_contemp_old,eff_o_final,...
    age_g,a_grid_old,a_prob_old,a_grid_new,a_prob_new,pi_contemp_new,p_E,m_of_firms_new,m_of_firms_old,exit_n,exit_o] = ...
    Two_tech_ss_AC3(a_grow,alpha,~,beta,c_of_a,c_a_new,mu_old,sigma_old,mu_new,sigma_new,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,fco_o,fco_n,e_p,d_0,c_of_e,c_e_new,dem_tol,tech_dist,...
    e0_o,e_o_eps,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,solar_cap_mean,solar_price_corr)

% Two-tech steady state for fossil old tech and intermittent green new tech.
% Old tech uses the fossil static solver. New tech always produces available
% capacity and has no fuel input. Availability is negatively correlated with
% hourly electricity prices through solar_price_corr.

x_old = norminv(linspace(0,1,a_num_g+2),mu_old,sigma_old);
a_grid_old = x_old(2:a_num_g+1);
a_cdf_old = normcdf(x_old,mu_old,sigma_old);
a_prob_old = a_cdf_old(2:a_num_g+1)-a_cdf_old(1:a_num_g);
prob_matrix_old = auto_corr_prob(a_grid_old,a_prob_old,rho);

x_new = norminv(linspace(0,1,a_num_g+2),mu_new,sigma_new);
a_grid_new = x_new(2:a_num_g+1);
assert(all(a_grid_new>0),'variance of green tech efficiency draw is too large')
assert(all(a_grid_old>0),'variance of fossil tech efficiency draw is too large')
a_cdf_new = normcdf(x_new,mu_new,sigma_new);
a_prob_new = a_cdf_new(2:a_num_g+1)-a_cdf_new(1:a_num_g);
prob_matrix_new = auto_corr_prob(a_grid_new,a_prob_new,rho);

age_g = (linspace(0,age_num-1,age_num))';
a_eff_new = a_grid_new' .* max(1 - a_grow .* age_g', 0);
a_eff_old = (a_grid_old./tech_dist)' .* max(1 - a_grow .* age_g', 0);

n_PE = 50;
n_pe = 10;
P_E_grid_norm = P_E_grid(n_PE,1);
p_e_o_grid_norm = p_input_grid(n_pe,1,sigma_p_o,rho_p_o);

% Higher electricity prices coincide with lower solar availability.
[~,price_order] = sort(P_E_grid_norm,'ascend');
solar_cap_sorted = linspace(1+solar_price_corr,1-solar_price_corr,n_PE)';
solar_cap_norm = zeros(n_PE,1);
solar_cap_norm(price_order) = solar_cap_sorted;
solar_cap_norm = solar_cap_mean * solar_cap_norm / mean(solar_cap_norm);
solar_cap_norm = max(min(solar_cap_norm,1),0);

p_E = 35;
p_E_prev = p_E;
p_e_o = 3.5;
p_e_o_pre = p_e_o;
dem_err_pre = 0;

m_of_firms_new = 1;
m_of_firms_old = 3;
m_of_new_pre = m_of_firms_new;
m_of_old_pre = m_of_firms_old;
value_err_n_pre = 0;
value_err_o_pre = 0;

p_e_n = 0;
max_iter_price = max_iter;
max_iter_measure = max_iter;

for h=1:max_iter_measure
    for k=1:max_iter_price
        [eff_n_vec, cap_contemp_new, pi_n_mat] = solar_static_solver(a_eff_new, p_E.*P_E_grid_norm, solar_cap_norm, fco_n);
        [eff_o_vec, cap_contemp_old, pi_o_mat] = static_solver(a_eff_old, p_E.*P_E_grid_norm, p_e_o.*p_e_o_grid_norm, alpha, fco_o, 1./a_grid_old(:));

        pi_contemp_new = pi_n_mat';
        pi_contemp_old = pi_o_mat';

        [v_new_resh_n,policy_choice_n,exit_vec_n] = solve_branch_value(pi_contemp_new,prob_matrix_new,beta,c_a_new,v_tol,max_iter,age_reduc,exo_exit);
        [v_new_resh_o,policy_choice_o,exit_vec_o] = solve_branch_value(pi_contemp_old,prob_matrix_old,beta,c_of_a,v_tol,max_iter,age_reduc,exo_exit);

        trans_matrix_n = build_branch_transition(policy_choice_n,exit_vec_n,prob_matrix_new,a_prob_new,age_reduc,exo_exit,a_num_g,age_num);
        trans_matrix_o = build_branch_transition(policy_choice_o,exit_vec_o,prob_matrix_old,a_prob_old,age_reduc,exo_exit,a_num_g,age_num);

        if all(v_new_resh_n<=0,"all")
            dist_n = zeros(1,age_num*a_num_g);
            exit_n = 0;
        else
            [dist_n,exit_n] = stationary_branch_dist(trans_matrix_n,m_of_firms_new,a_prob_new,a_num_g,age_num,dist_tol,max_iter);
        end

        if all(v_new_resh_o<=0,"all")
            dist_o = zeros(1,age_num*a_num_g);
            exit_o = 0;
        else
            [dist_o,exit_o] = stationary_branch_dist(trans_matrix_o,m_of_firms_old,a_prob_old,a_num_g,age_num,dist_tol,max_iter);
        end

        total_cap = dist_n*cap_contemp_new(:) + dist_o*cap_contemp_old(:);
        if total_cap>0
            supply_price = (d_0/total_cap)^(1/e_p);
        else
            supply_price = p_E + 100;
        end
        demand_err = max(min(supply_price-p_E,100),-100);
        p_E = p_E + 0.1*demand_err/min(ceil(k/10),20);
        if sign(dem_err_pre)~=sign(demand_err)
            p_E = (p_E_prev+p_E)/2;
        end

        input_old = dist_o*eff_o_vec(:);
        if input_old>0
            p_e_o_target = (input_old/e0_o)^(1/e_o_eps);
        else
            p_e_o_target = 0.5*p_e_o;
        end
        p_e_o = p_e_o_pre + 0.03*(p_e_o_target-p_e_o_pre);

        if abs(demand_err)<dem_tol && abs(p_E-p_E_prev)<5*v_tol && abs(p_e_o-p_e_o_pre)<5*v_tol
            break;
        end

        p_E_prev = p_E;
        p_e_o_pre = p_e_o;
        dem_err_pre = demand_err;
    end

    value_err_n = a_prob_new*(v_new_resh_n(1,:))' - c_e_new;
    value_err_o = a_prob_old*(v_new_resh_o(1,:))' - c_of_e;

    if ((abs(value_err_n)<dem_tol||m_of_firms_new<v_tol) && ...
            (abs(value_err_o)<dem_tol||m_of_firms_old<v_tol)) || ...
            (abs(1-m_of_new_pre/m_of_firms_new)<v_tol && abs(1-m_of_old_pre/m_of_firms_old)<v_tol && h>max_iter_measure/10)
        fprintf("entry and exit converged with E(v_new)-ce=%2.4f and E(v_old)-ce=%2.4f\n",value_err_n,value_err_o);
        break;
    end

    m_of_new_pre = m_of_firms_new;
    m_of_old_pre = m_of_firms_old;

    hh = max(floor(log(h+2)),1);
    m_of_firms_new = max(v_tol,m_of_firms_new*(1+min(0.02*abs(value_err_n)/hh,0.2)*sign(value_err_n)));
    m_of_firms_old = max(v_tol,m_of_firms_old*(1+min(0.02*abs(value_err_o)/hh,0.2)*sign(value_err_o)));

    if sign(value_err_n_pre)~=sign(value_err_n)
        m_of_firms_new = (m_of_firms_new+m_of_new_pre)/2;
    end
    if sign(value_err_o_pre)~=sign(value_err_o)
        m_of_firms_old = (m_of_firms_old+m_of_old_pre)/2;
    end

    value_err_n_pre = value_err_n;
    value_err_o_pre = value_err_o;
end

v_new_n = v_new_resh_n(:);
v_new_o = v_new_resh_o(:);
trans_prob_n = sum(policy_choice_n.*repmat(prob_matrix_new,age_num,1),2);
trans_prob_o = sum(policy_choice_o.*repmat(prob_matrix_old,age_num,1),2);
eff_n_final = eff_n_vec(:);
eff_o_final = eff_o_vec(:);

end

function [v_new_resh,policy_choice,exit_vec] = solve_branch_value(pi_contemp,prob_matrix,beta,c_a,v_tol,max_iter,age_reduc,exo_exit)
[age_num,a_num_g] = size(pi_contemp);
v_old = max(pi_contemp,0);
policy_choice = zeros(age_num*a_num_g,a_num_g);
exit_vec = zeros(age_num*a_num_g,1);

for it=1:max_iter
    v_new_resh = zeros(age_num,a_num_g);
    policy_choice = zeros(age_num*a_num_g,a_num_g);

    for age=1:age_num
        for ia=1:a_num_g
            s = (age-1)*a_num_g + ia;
            expected_v = 0;
            for ja=1:a_num_g
                if age<age_num
                    v_continue = v_old(age+1,ja);
                else
                    v_continue = 0;
                end
                adopt_age = max(age-age_reduc,1);
                v_adopt = v_old(adopt_age,ja) - c_a;
                if v_adopt>v_continue
                    expected_v = expected_v + prob_matrix(ia,ja)*v_adopt;
                    policy_choice(s,ja) = 1;
                else
                    expected_v = expected_v + prob_matrix(ia,ja)*v_continue;
                end
            end
            v_new_resh(age,ia) = pi_contemp(age,ia) + beta*(1-exo_exit)*expected_v;
        end
    end

    v_neg = v_new_resh<0;
    exit_vec = v_neg(:);
    v_new_resh(v_neg) = 0;

    if max(abs(v_new_resh-v_old),[],"all")<v_tol
        break;
    end
    v_old = v_new_resh;
end
end

function trans_matrix = build_branch_transition(policy_choice,exit_vec,prob_matrix,a_prob,age_reduc,exo_exit,a_num_g,age_num)
rows = [];
cols = [];
vals = [];

for age=1:age_num
    for ia=1:a_num_g
        s = (age-1)*a_num_g + ia;
        if exit_vec(s)>=1
            continue;
        end
        for ja=1:a_num_g
            surv_prob = prob_matrix(ia,ja)*(1-exo_exit);
            if policy_choice(s,ja)>0
                target_age = max(age-age_reduc,1);
            elseif age<age_num
                target_age = age+1;
            else
                continue;
            end
            target = (target_age-1)*a_num_g + ja;
            rows(end+1) = s; %#ok<AGROW>
            cols(end+1) = target; %#ok<AGROW>
            vals(end+1) = surv_prob; %#ok<AGROW>
        end
    end
end

trans_matrix = sparse(rows,cols,vals,age_num*a_num_g,age_num*a_num_g);
trans_matrix((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = repmat(a_prob,a_num_g,1);
end

function [dist,exit_mass] = stationary_branch_dist(trans_matrix,m_of_firms,a_prob,a_num_g,age_num,dist_tol,max_iter)
dist = m_of_firms*ones(1,age_num*a_num_g)/(age_num*a_num_g);
dist_ent = zeros(1,age_num*a_num_g);
dist_ent(1:a_num_g) = a_prob;
exit_mass = 0;

for it=1:max_iter
    dist_new = dist*trans_matrix;
    exit_mass = sum(dist-dist_new);
    dist_new = dist_new + max(m_of_firms-sum(dist_new),0)*dist_ent;
    if max(abs(dist_new-dist))<dist_tol
        dist = dist_new;
        break;
    end
    dist = dist_new;
end
end
