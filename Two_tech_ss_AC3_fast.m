function [trans_prob_o,v_new_o,v_new_resh_o,dist_o,trans_matrix_n,p_e_n,cap_contemp_new,eff_n_final,...
    trans_prob_n,v_new_n,v_new_resh_n,dist_n,trans_matrix_o,p_e_o,cap_contemp_old,eff_o_final,...
    age_g,a_grid_old,a_prob_old,a_grid_new,a_prob_new,pi_contemp_new,p_E,m_of_firms_new,m_of_firms_old,exit_n,exit_o] = ...
    Two_tech_ss_AC3_fast(a_grow,alpha,beta,c_of_a,c_a_new,mu_old,sigma_old,mu_new,sigma_new,...
    a_num_g,age_num,max_iter,v_tol,dist_tol,fco_o,fco_n,e_p,d_0,c_of_e,c_e_new,dem_tol,...
    tech_dist,e0_o,e_o_eps,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,...
    solar_cap_mean,solar_price_corr,P_E_grid_norm,fossil_terminal)
% Optimized fossil-green steady state.

if isfield(fossil_terminal,"grid") && ~isempty(fossil_terminal.grid)
    a_grid_old = fossil_terminal.grid(:)';
    a_num_g = numel(a_grid_old);
else
    x_old = norminv(linspace(0,1,a_num_g+2),mu_old,sigma_old);
    a_grid_old = x_old(2:a_num_g+1);
end
if isfield(fossil_terminal,"prob") && ~isempty(fossil_terminal.prob)
    a_prob_old = fossil_terminal.prob(:)';
else
    x_edge_old = [-inf,(a_grid_old(1:end-1)+a_grid_old(2:end))/2,inf];
    a_prob_old = diff(normcdf(x_edge_old,mu_old,sigma_old));
end
a_prob_old = max(a_prob_old,0)/sum(max(a_prob_old,0));

x_new = norminv(linspace(0,1,a_num_g+2),mu_new,sigma_new);
a_grid_new = x_new(2:a_num_g+1);
a_cdf_new = normcdf(x_new,mu_new,sigma_new);
a_prob_new = a_cdf_new(2:a_num_g+1)-a_cdf_new(1:a_num_g);
a_prob_new = a_prob_new/sum(a_prob_new);
assert(all(a_grid_new>0)&&all(a_grid_old>0),"Efficiency grids must be positive.");

age_g = (0:age_num-1)';
a_eff_new = a_grid_new'.*max(1-a_grow.*age_g',0);
a_eff_old = (a_grid_old./tech_dist)'.*max(1-a_grow.*age_g',0);
prob_matrix_new = auto_corr_prob(a_grid_new,a_prob_new,rho);
prob_matrix_old = auto_corr_prob(a_grid_old,a_prob_old,rho);

P_E_grid_norm = P_E_grid_norm(:);
p_e_o_grid_norm = p_input_grid(10,1,sigma_p_o,rho_p_o);
dlog_weight_PE = log_scale_weight_derivative(P_E_grid_norm);
dlog_weight_pe = log_scale_weight_derivative(p_e_o_grid_norm);
[solar_cap_norm,~] = solar_availability_grid(P_E_grid_norm,solar_cap_mean,solar_price_corr);

p_E = field_or(fossil_terminal,"p_E",35);
p_e_o = field_or(fossil_terminal,"p_e",3.5);
p_e_n = 0;
m_of_firms_new = field_or(fossil_terminal,"green_measure_guess",1);
m_of_firms_old = field_or(fossil_terminal,"fossil_measure_guess",3);

p_E_prev = p_E;
p_e_prev = p_e_o;
demand_err_prev = 1;
input_err_prev = 1;
output_adjust = 0.1;
input_adjust = 0.2;
measure_adjust_n = 0.02;
measure_adjust_o = 0.02;
value_err_n_prev = 0;
value_err_o_prev = 0;
entry_n_prev = m_of_firms_new;
entry_o_prev = m_of_firms_old;
static_anchor_o = [];

max_iter_price = max(10,min(max_iter,30000));
max_iter_measure = max_iter;
for h=1:max_iter_measure
    for k=1:max_iter_price
        [eff_n_vec,cap_contemp_new,pi_n_mat] = ...
            solar_static_solver(a_eff_new,p_E.*P_E_grid_norm,solar_cap_norm,fco_n);
        static_o = static_solver_anchor(a_eff_old,p_E,p_e_o,P_E_grid_norm,p_e_o_grid_norm,...
            alpha,fco_o,1./a_grid_old(:),dlog_weight_PE,dlog_weight_pe,static_anchor_o,0.01);
        static_anchor_o = static_o;
        eff_o_vec = double(static_o.eff);
        cap_contemp_old = double(static_o.cap);
        pi_o_mat = double(static_o.pi);

        pi_contemp_new = pi_n_mat';
        pi_contemp_old = pi_o_mat';
        [v_new_resh_n,policy_choice_n,exit_vec_n] = solve_branch_value_fast(...
            pi_contemp_new,prob_matrix_new,beta,c_a_new,v_tol,max_iter,age_reduc,exo_exit);
        [v_new_resh_o,policy_choice_o,exit_vec_o] = solve_branch_value_fast(...
            pi_contemp_old,prob_matrix_old,beta,c_of_a,v_tol,max_iter,age_reduc,exo_exit);

        trans_matrix_n = build_branch_transition_fast(policy_choice_n,exit_vec_n,...
            prob_matrix_new,a_prob_new,age_reduc,exo_exit,a_num_g,age_num);
        trans_matrix_o = build_branch_transition_fast(policy_choice_o,exit_vec_o,...
            prob_matrix_old,a_prob_old,age_reduc,exo_exit,a_num_g,age_num);
        [dist_n,exit_n] = stationary_branch_dist_fast(trans_matrix_n,m_of_firms_new,...
            a_prob_new,a_num_g,age_num,dist_tol,max_iter);
        [dist_o,exit_o] = stationary_branch_dist_fast(trans_matrix_o,m_of_firms_old,...
            a_prob_old,a_num_g,age_num,dist_tol,max_iter);

        total_cap = dist_n*cap_contemp_new(:)+dist_o*cap_contemp_old(:);
        supply_price = (d_0/max(total_cap,sqrt(eps)))^(1/e_p);
        demand_err = max(min(supply_price-p_E,25),-25);
        tentative_p_E = p_E+0.1*output_adjust*demand_err;
        oscill_E = sign(demand_err)~=sign(demand_err_prev);
        if oscill_E
            tentative_p_E = (p_E*abs(demand_err_prev)+p_E_prev*abs(demand_err))/...
                max(abs(demand_err)+abs(demand_err_prev),sqrt(eps));
            output_adjust = 0.95*output_adjust;
        end

        input_old = dist_o*eff_o_vec(:);
        input_target = (max(input_old,0)/max(e0_o,sqrt(eps)))^(1/e_o_eps);
        input_err = max(min(input_target-p_e_o,25),-25);
        tentative_p_e = p_e_o+0.1*input_adjust*input_err;
        oscill_e = sign(input_err)~=sign(input_err_prev);
        if oscill_e
            tentative_p_e = (p_e_o*abs(input_err_prev)+p_e_prev*abs(input_err))/...
                max(abs(input_err)+abs(input_err_prev),sqrt(eps));
            input_adjust = 0.95*input_adjust;
        end

        p_E_prev = p_E;
        p_e_prev = p_e_o;
        p_E = max(tentative_p_E,sqrt(eps));
        p_e_o = max(tentative_p_e,sqrt(eps));
        demand_err_prev = demand_err;
        input_err_prev = input_err;
        if abs(demand_err)<dem_tol && abs(input_err)<dem_tol && ...
                abs(p_E-p_E_prev)<5*v_tol && abs(p_e_o-p_e_prev)<5*v_tol
            break
        end
    end

    value_err_n = a_prob_new*v_new_resh_n(1,:)'-c_e_new;
    value_err_o = a_prob_old*v_new_resh_o(1,:)'-c_of_e;
    if (abs(value_err_n)<5*dem_tol || m_of_firms_new<v_tol) && ...
            (abs(value_err_o)<5*dem_tol || m_of_firms_old<v_tol)
        break
    end

    entry_n_lag = m_of_firms_new;
    entry_o_lag = m_of_firms_old;
    m_of_firms_new = max(0,m_of_firms_new*(1+0.2*measure_adjust_n*value_err_n));
    m_of_firms_old = max(0,m_of_firms_old*(1+0.2*measure_adjust_o*value_err_o));
    if h>1 && sign(value_err_n)~=sign(value_err_n_prev)
        m_of_firms_new = (entry_n_lag*abs(value_err_n_prev)+entry_n_prev*abs(value_err_n))/...
            max(abs(value_err_n)+abs(value_err_n_prev),sqrt(eps));
        measure_adjust_n = 0.95*measure_adjust_n;
    end
    if h>1 && sign(value_err_o)~=sign(value_err_o_prev)
        m_of_firms_old = (entry_o_lag*abs(value_err_o_prev)+entry_o_prev*abs(value_err_o))/...
            max(abs(value_err_o)+abs(value_err_o_prev),sqrt(eps));
        measure_adjust_o = 0.95*measure_adjust_o;
    end
    entry_n_prev = entry_n_lag;
    entry_o_prev = entry_o_lag;
    value_err_n_prev = value_err_n;
    value_err_o_prev = value_err_o;
end

v_new_n = v_new_resh_n(:);
v_new_o = v_new_resh_o(:);
trans_prob_n = sum(policy_choice_n.*repmat(prob_matrix_new,age_num,1),2);
trans_prob_o = sum(policy_choice_o.*repmat(prob_matrix_old,age_num,1),2);
eff_n_final = eff_n_vec(:);
eff_o_final = eff_o_vec(:);
end

function [value,policy,exit_vec] = solve_branch_value_fast(pi_mat,prob,beta,cost,tol,max_iter,age_reduc,exo_exit)
[age_num,a_num_g] = size(pi_mat);
value = max(pi_mat,0);
for ii=1:max_iter
    continuation = [value(2:end,:);zeros(1,a_num_g)];
    adopt_age = max((1:age_num)-age_reduc,1);
    adoption = value(adopt_age,:)-cost;
    choice_age = adoption>continuation;
    best = continuation+(adoption-continuation).*choice_age;
    value_new = pi_mat+beta*(1-exo_exit)*(best*prob');
    value_new = max(value_new,0);
    if max(abs(value_new-value),[],"all")<tol
        value = value_new;
        break
    end
    value = value_new;
end
continuation = [value(2:end,:);zeros(1,a_num_g)];
adopt_age = max((1:age_num)-age_reduc,1);
adoption = value(adopt_age,:)-cost;
choice_age = adoption>continuation;
policy = repelem(choice_age,a_num_g,1);
exit_vec = (value<=0);
exit_vec = exit_vec';
exit_vec = exit_vec(:);
policy = policy.*(1-exit_vec);
end

function transition = build_branch_transition_fast(policy,exit_vec,prob,a_prob,age_reduc,exo_exit,a_num_g,age_num)
n_state = age_num*a_num_g;
source = repelem((1:n_state)',a_num_g);
dest_type = repmat((1:a_num_g)',n_state,1);
state_age = repelem(repelem((1:age_num)',a_num_g),a_num_g);
state_type = repmat(repelem((1:a_num_g)',a_num_g),age_num,1);
choice = reshape(policy',[],1);
target_age = min(state_age+1,age_num);
target_age(choice>0) = max(state_age(choice>0)-age_reduc,1);
keep = (choice>0 | state_age<age_num) & repelem(exit_vec<1,a_num_g);
target = (target_age-1)*a_num_g+dest_type;
prob_expanded = prob(sub2ind(size(prob),state_type,dest_type));
values = prob_expanded*(1-exo_exit);
transition = sparse(source(keep),target(keep),values(keep),n_state,n_state);
last = (age_num-1)*a_num_g+1:n_state;
transition(last,1:a_num_g) = repmat(a_prob,a_num_g,1).*(1-exit_vec(last));
end

function [dist,exit_mass] = stationary_branch_dist_fast(transition,entry_mass,a_prob,a_num_g,age_num,tol,max_iter)
dist = entry_mass*ones(1,age_num*a_num_g)/(age_num*a_num_g);
entrant = zeros(1,age_num*a_num_g);
entrant(1:a_num_g) = a_prob;
for ii=1:max_iter
    dist_new = dist*transition;
    exit_mass = sum(dist-dist_new);
    dist_new = dist_new+max(entry_mass-sum(dist_new),0)*entrant;
    if max(abs(dist_new-dist))<tol
        dist = dist_new;
        return
    end
    dist = dist_new;
end
exit_mass = sum(dist-dist*transition);
end

function [cap,order] = solar_availability_grid(P_E_grid_norm,mean_cap,corr)
[~,order] = sort(P_E_grid_norm,"ascend");
sorted = linspace(1+corr,1-corr,numel(P_E_grid_norm))';
cap = zeros(size(sorted));
cap(order) = sorted;
cap = max(min(mean_cap*cap/mean(cap),1),0);
end

function value = field_or(S,name,fallback)
if isfield(S,name)&&~isempty(S.(name))
    value = S.(name);
else
    value = fallback;
end
end
