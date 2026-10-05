function [trans_prob_o_all,v_new_resh_o_all,dist_o_all,measure_vec_o,p_e_o_vec,input_all_o,...
    trans_prob_n_all,v_new_resh_n_all,dist_n_all,measure_vec_n,p_E_vec,cap_old,cap_new,...
    age_g,a_grid_old,a_prob_old,a_grid_n_all,a_prob_n_all,entry_n_path,adopt_n_path,tax_revenue_path,entry_o_path] = ...
    MIT_transition_green_fast(a_grow,alpha,beta,c_of_a,c_a_new_vec,a_grid_old,a_prob_old,...
    mu_new_vec,sigma_new_vec,a_num_g,age_num,max_iter,v_tol,fco_o,fco_n,e_p,d_0,...
    c_of_e,c_e_new_vec,dem_tol,init_dist_n,init_dist_o,final_val_o,final_val_n,...
    init_p_E,final_p_E,trans_t,final_dist_n,final_dist_o,e0_o,e_o_eps,...
    fin_p_e_o,init_p_e_o,rho,age_reduc,exit_n_final,exit_o_final,exo_exit,...
    init_input_o,penalty_o,penalty_p,d0_gr,rho_p_o,sigma_p_o,solar_cap_mean,...
    solar_price_corr,fossil_tax_vec,fossil_path,P_E_grid_norm,checkpoint_name,...
    static_solver_workers)
% Optimized fossil-green MIT with time-varying aggregate fossil technology.
% static_solver_workers is optional: above 1 selects parfor with that many
% workers; 0 or 1 runs the static loop serially. Empty keeps the default.

age_g = (0:age_num-1)';
P_E_grid_norm = P_E_grid_norm(:);
[solar_cap_norm,~] = solar_availability_grid(P_E_grid_norm,solar_cap_mean,solar_price_corr);

[a_grid_o_all,a_prob_o_all,a_grid_entry_o_all,a_prob_entry_o_all,...
    fco_o_vec,c_of_a_vec,c_of_e_vec,e0_o_vec,e_o_eps_vec,rho_p_o_vec,sigma_p_o_vec] = ...
    fossil_inputs(fossil_path,a_grid_old,a_prob_old,fco_o,c_of_a,c_of_e,e0_o,e_o_eps,...
    rho_p_o,sigma_p_o,trans_t);
a_grid_old = a_grid_o_all(:,1)';
a_prob_old = a_prob_entry_o_all(:,1)';

a_grid_n_all = zeros(a_num_g,trans_t);
a_prob_n_all = zeros(a_num_g,trans_t);
for tt=1:trans_t
    x_new = norminv(linspace(0,1,a_num_g+2),mu_new_vec(tt),sigma_new_vec(tt));
    a_grid_n_all(:,tt) = x_new(2:a_num_g+1)';
    cdf_new = normcdf(x_new,mu_new_vec(tt),sigma_new_vec(tt));
    probability = (cdf_new(2:a_num_g+1)-cdf_new(1:a_num_g))';
    a_prob_n_all(:,tt) = probability/sum(probability);
end

prob_mat_n_all = cell(trans_t,1);
prob_mat_o_all = cell(trans_t,1);
entry_prob_n_all = zeros(a_num_g,trans_t);
entry_prob_o_all = zeros(a_num_g,trans_t);
for tt=1:trans_t
    next = min(tt+1,trans_t);
    prob_mat_n_all{tt} = auto_corr_prob_transition2(a_grid_n_all(:,tt),...
        a_prob_n_all(:,next),rho,a_grid_n_all(:,next));
    prob_mat_o_all{tt} = auto_corr_prob_transition2(a_grid_o_all(:,tt),...
        a_prob_o_all(:,next),rho,a_grid_o_all(:,next));
    entry_prob_n_all(:,tt) = a_prob_n_all(:,next);
    entry_prob_o_all(:,tt) = map_distribution(a_grid_entry_o_all(:,next),...
        a_prob_entry_o_all(:,next),a_grid_o_all(:,next));
end
transition_address = precompute_transition_addresses(a_num_g,age_num);

p_e_grid_norm_all = cell(trans_t,1);
dlog_weight_pe_all = cell(trans_t,1);
for tt=1:trans_t
    p_e_grid_norm_all{tt} = p_input_grid(10,1,sigma_p_o_vec(tt),rho_p_o_vec(tt));
    dlog_weight_pe_all{tt} = log_scale_weight_derivative(p_e_grid_norm_all{tt});
end
dlog_weight_PE = log_scale_weight_derivative(P_E_grid_norm);

p_E_vec = linspace(init_p_E,final_p_E,trans_t);
p_E_prev = p_E_vec;
p_e_o_vec = linspace(init_p_e_o,fin_p_e_o,trans_t);
p_e_o_prev = p_e_o_vec;
d0_vec = d_0*(1+d0_gr).^(1:trans_t);

dist_n_all = zeros(trans_t,age_num*a_num_g);
dist_o_all = zeros(trans_t,age_num*a_num_g);
measure_vec_n = zeros(1,trans_t);
measure_vec_o = zeros(1,trans_t);
v_new_resh_n_all = zeros(age_num,a_num_g,trans_t);
v_new_resh_o_all = zeros(age_num,a_num_g,trans_t);
policy_choice_n_all = zeros(age_num*a_num_g,a_num_g,trans_t);
policy_choice_o_all = zeros(age_num*a_num_g,a_num_g,trans_t);
exit_vec_n_all = zeros(age_num*a_num_g,trans_t);
exit_vec_o_all = zeros(age_num*a_num_g,trans_t);
trans_prob_n_all = zeros(age_num*a_num_g,trans_t);
trans_prob_o_all = zeros(age_num*a_num_g,trans_t);
input_all_o = init_input_o*ones(trans_t+1,1);
cap_old = zeros(1,trans_t);
cap_new = zeros(1,trans_t);
adopt_n_path = zeros(1,trans_t);
tax_revenue_path = zeros(1,trans_t);

m_entry_n = initial_entry_path(init_dist_n,final_dist_n,exit_n_final,trans_t);
m_entry_o = initial_entry_path(init_dist_o,final_dist_o,exit_o_final,trans_t);
m_entry_n_prev = m_entry_n;
m_entry_o_prev = m_entry_o;
value_err_n_prev = zeros(trans_t,1);
value_err_o_prev = zeros(trans_t,1);
measure_adjust_n = 0.02*ones(1,trans_t);
measure_adjust_o = 0.02*ones(1,trans_t);
demand_err_prev = ones(1,trans_t);
input_err_prev = ones(1,trans_t);
output_adjust = 0.1/max(e_p,sqrt(eps))*ones(1,trans_t);
input_adjust = 0.2*ones(1,trans_t);
static_anchor_o = cell(trans_t,1);
delta_p_thres = 0.02; %%% Price adjustment threshold for static anchor solver.

checkpoint_file = checkpoint_filename(checkpoint_name);
h_start = 1;
if strlength(checkpoint_file)>0 && isfile(checkpoint_file)
    S = load(checkpoint_file);
    p_E_vec = checkpoint_value(S,"p_E_vec",p_E_vec);
    p_E_prev = checkpoint_value(S,"p_E_prev",p_E_prev);
    p_e_o_vec = checkpoint_value(S,"p_e_o_vec",p_e_o_vec);
    p_e_o_prev = checkpoint_value(S,"p_e_o_prev",p_e_o_prev);
    m_entry_n = checkpoint_value(S,"m_entry_n",m_entry_n);
    m_entry_o = checkpoint_value(S,"m_entry_o",m_entry_o);
    m_entry_n_prev = checkpoint_value(S,"m_entry_n_prev",m_entry_n_prev);
    m_entry_o_prev = checkpoint_value(S,"m_entry_o_prev",m_entry_o_prev);
    value_err_n_prev = checkpoint_value(S,"value_err_n_prev",value_err_n_prev);
    value_err_o_prev = checkpoint_value(S,"value_err_o_prev",value_err_o_prev);
    measure_adjust_n = checkpoint_value(S,"measure_adjust_n",measure_adjust_n);
    measure_adjust_o = checkpoint_value(S,"measure_adjust_o",measure_adjust_o);
    demand_err_prev = checkpoint_value(S,"demand_err_prev",demand_err_prev);
    input_err_prev = checkpoint_value(S,"input_err_prev",input_err_prev);
    output_adjust = checkpoint_value(S,"output_adjust",output_adjust);
    input_adjust = checkpoint_value(S,"input_adjust",input_adjust);
    if isfield(S,"h_start"), h_start = S.h_start; end
end

max_iter_price = max(1,floor(max_iter/10));
if nargin<51 || isempty(static_solver_workers)
    static_solver_workers = 4*(trans_t>=8);
end
for h=h_start:max_iter
    for k=1:max_iter_price
        static_result_n = cell(trans_t,1);
        static_result_o = cell(trans_t,1);
        if static_solver_workers>1
            parfor (tt=1:trans_t,static_solver_workers)
                a_eff_n = a_grid_n_all(:,tt).*max(1-a_grow.*age_g',0);
                [eff_n,cap_n,pi_n] = solar_static_solver(a_eff_n,...
                    p_E_vec(tt).*P_E_grid_norm,solar_cap_norm,fco_n);
                result_n = struct("eff",single(eff_n),"cap",single(cap_n),"pi",single(pi_n));
                static_result_n{tt} = result_n;

                a_eff_o = a_grid_o_all(:,tt).*max(1-a_grow.*age_g',0);
                p_e_plant = p_e_o_vec(tt)+fossil_tax_vec(tt);
                static_result_o{tt} = static_solver_anchor(a_eff_o,p_E_vec(tt),p_e_plant,...
                    P_E_grid_norm,p_e_grid_norm_all{tt},alpha,fco_o_vec(tt),...
                    1./a_grid_o_all(:,tt),dlog_weight_PE,dlog_weight_pe_all{tt},...
                    static_anchor_o{tt},0.01);
            end
        else
            for tt=1:trans_t
                a_eff_n = a_grid_n_all(:,tt).*max(1-a_grow.*age_g',0);
                [eff_n,cap_n,pi_n] = solar_static_solver(a_eff_n,...
                    p_E_vec(tt).*P_E_grid_norm,solar_cap_norm,fco_n);
                result_n = struct("eff",single(eff_n),"cap",single(cap_n),"pi",single(pi_n));
                static_result_n{tt} = result_n;

                a_eff_o = a_grid_o_all(:,tt).*max(1-a_grow.*age_g',0);
                p_e_plant = p_e_o_vec(tt)+fossil_tax_vec(tt);
                static_result_o{tt} = static_solver_anchor(a_eff_o,p_E_vec(tt),p_e_plant,...
                    P_E_grid_norm,p_e_grid_norm_all{tt},alpha,fco_o_vec(tt),...
                    1./a_grid_o_all(:,tt),dlog_weight_PE,dlog_weight_pe_all{tt},...
                    static_anchor_o{tt},delta_p_thres);
            end
        end
        static_anchor_o = static_result_o;

        v_next_n = final_val_n;
        v_next_o = final_val_o;
        for tt=trans_t:-1:1
            [v_current_n,policy_n,exit_n] = value_step_from_next(...
                double(static_result_n{tt}.pi)',v_next_n,prob_mat_n_all{tt},...
                beta,c_a_new_vec(tt),age_reduc,exo_exit);
            [v_current_o,policy_o,exit_o] = value_step_from_next(...
                double(static_result_o{tt}.pi)',v_next_o,prob_mat_o_all{tt},...
                beta,c_of_a_vec(tt),age_reduc,exo_exit);
            v_new_resh_n_all(:,:,tt) = v_current_n;
            v_new_resh_o_all(:,:,tt) = v_current_o;
            policy_choice_n_all(:,:,tt) = policy_n;
            policy_choice_o_all(:,:,tt) = policy_o;
            exit_vec_n_all(:,tt) = exit_n;
            exit_vec_o_all(:,tt) = exit_o;
            trans_prob_n_all(:,tt) = sum(policy_n.*repmat(prob_mat_n_all{tt},age_num,1),2);
            trans_prob_o_all(:,tt) = sum(policy_o.*repmat(prob_mat_o_all{tt},age_num,1),2);
            v_next_n = v_current_n;
            v_next_o = v_current_o;
        end

        dist_n = init_dist_n;
        dist_o = init_dist_o;
        input_implied = zeros(1,trans_t);
        for tt=1:trans_t
            trans_n = build_transition_fast(policy_choice_n_all(:,:,tt),exit_vec_n_all(:,tt),...
                prob_mat_n_all{tt},entry_prob_n_all(:,tt)',age_reduc,exo_exit,transition_address);
            trans_o = build_transition_fast(policy_choice_o_all(:,:,tt),exit_vec_o_all(:,tt),...
                prob_mat_o_all{tt},entry_prob_o_all(:,tt)',age_reduc,exo_exit,transition_address);

            cap_n = double(static_result_n{tt}.cap);
            cap_o = double(static_result_o{tt}.cap);
            eff_o = double(static_result_o{tt}.eff);
            cap_new(tt) = dist_n*cap_n(:);
            cap_old(tt) = dist_o*cap_o(:);
            input_old = dist_o*eff_o(:);
            adopt_n_path(tt) = dist_n*trans_prob_n_all(:,tt);
            tax_revenue_path(tt) = fossil_tax_vec(tt)*input_old;

            dist_n = dist_n*trans_n+m_entry_n(tt)*entry_dist(entry_prob_n_all(:,tt)',a_num_g,age_num);
            dist_o = dist_o*trans_o+m_entry_o(tt)*entry_dist(entry_prob_o_all(:,tt)',a_num_g,age_num);
            dist_n_all(tt,:) = dist_n;
            dist_o_all(tt,:) = dist_o;
            measure_vec_n(tt) = sum(dist_n);
            measure_vec_o(tt) = sum(dist_o);
            input_all_o(tt+1) = input_old;
            input_implied(tt) = (max(input_old,0)/max(e0_o_vec(tt),sqrt(eps))*...
                (max(input_old,0)/max(input_all_o(tt),sqrt(eps)))^penalty_o)^(1/e_o_eps_vec(tt));
        end

        total_cap = cap_old+cap_new;
        total_cap_lag = [d_0/(init_p_E^e_p),total_cap(1:end-1)];
        supply_price = (d0_vec./max(total_cap.*...
            (total_cap./max(total_cap_lag,sqrt(eps))).^penalty_p,sqrt(eps))).^(1/e_p);
        demand_err = max(min(supply_price-p_E_vec,25),-25);
        p_E_tentative = p_E_vec+0.1*output_adjust.*demand_err;
        oscill_E = sign(demand_err)~=sign(demand_err_prev);
        den_E = max(abs(demand_err)+abs(demand_err_prev),sqrt(eps));
        p_E_tentative(oscill_E) = (p_E_vec(oscill_E).*abs(demand_err_prev(oscill_E))+...
            p_E_prev(oscill_E).*abs(demand_err(oscill_E)))./den_E(oscill_E);
        output_adjust = output_adjust.*(0.95.^double(oscill_E));

        input_err = max(min(input_implied-p_e_o_vec,25),-25);
        p_e_tentative = p_e_o_vec+0.1*input_adjust.*input_err;
        oscill_e = sign(input_err)~=sign(input_err_prev);
        den_e = max(abs(input_err)+abs(input_err_prev),sqrt(eps));
        p_e_tentative(oscill_e) = (p_e_o_vec(oscill_e).*abs(input_err_prev(oscill_e))+...
            p_e_o_prev(oscill_e).*abs(input_err(oscill_e)))./den_e(oscill_e);
        input_adjust = input_adjust.*(0.95.^double(oscill_e));

        p_E_prev = p_E_vec;
        p_e_o_prev = p_e_o_vec;
        p_E_vec = max(p_E_tentative,sqrt(eps));
        p_e_o_vec = max(p_e_tentative,sqrt(eps));
        demand_err_prev = demand_err;
        input_err_prev = input_err;
        if mod(k,50)==0
            fprintf("green MIT h=%d, k=%d, mean |demand error|=%g, mean |fuel error|=%g\n",...
                h,k,mean(abs(demand_err)),mean(abs(input_err)));
        end

        if mean(abs(demand_err)<dem_tol | abs(p_E_vec-p_E_prev)<5*v_tol)>0.99 && ...
                mean(abs(input_err)<dem_tol | abs(p_e_o_vec-p_e_o_prev)<5*v_tol)>0.99
            break
        end
        if strlength(checkpoint_file)>0 && mod(k,50)==0
            save_green_checkpoint(checkpoint_file,h,p_E_vec,p_E_prev,p_e_o_vec,p_e_o_prev,...
                m_entry_n,m_entry_o,m_entry_n_prev,m_entry_o_prev,value_err_n_prev,value_err_o_prev,...
                measure_adjust_n,measure_adjust_o,demand_err_prev,input_err_prev,output_adjust,input_adjust);
        end
    end

    value_err_n = zeros(trans_t,1);
    value_err_o = zeros(trans_t,1);
    if trans_t>1
        value_err_n(1:end-1) = sum(entry_prob_n_all(:,1:end-1).*...
            reshape(v_new_resh_n_all(1,:,2:end),a_num_g,trans_t-1),1)'-c_e_new_vec(1:end-1)';
        value_err_o(1:end-1) = sum(entry_prob_o_all(:,1:end-1).*...
            reshape(v_new_resh_o_all(1,:,2:end),a_num_g,trans_t-1),1)'-c_of_e_vec(1:end-1)';
    end
    value_err_n(end) = entry_prob_n_all(:,end)'*final_val_n(1,:)'-c_e_new_vec(end);
    value_err_o(end) = entry_prob_o_all(:,end)'*final_val_o(1,:)'-c_of_e_vec(end);

    active = 1:max(trans_t-1,1);
    if mod(h,10)==0
        fprintf("green MIT h=%d complete after k=%d, mean |green entry error|=%g, mean |fossil entry error|=%g\n",...
            h,k,mean(abs(value_err_n(active))),mean(abs(value_err_o(active))));
    end
    if mean(abs(value_err_n(active))<5*dem_tol | m_entry_n(active)'<v_tol)>=0.95 && ...
            mean(abs(value_err_o(active))<5*dem_tol | m_entry_o(active)'<v_tol)>=0.95 && ...
            abs(sum(final_dist_n)-measure_vec_n(end))<dem_tol && ...
            abs(sum(final_dist_o)-measure_vec_o(end))<dem_tol
        break
    end

    [m_entry_n,m_entry_n_prev,measure_adjust_n] = update_entry_path(...
        m_entry_n,value_err_n,value_err_n_prev,m_entry_n_prev,measure_adjust_n,v_tol);
    [m_entry_o,m_entry_o_prev,measure_adjust_o] = update_entry_path(...
        m_entry_o,value_err_o,value_err_o_prev,m_entry_o_prev,measure_adjust_o,v_tol);
    value_err_n_prev = value_err_n;
    value_err_o_prev = value_err_o;
    if trans_t>1
        m_entry_n(end) = sum(final_dist_n,"all")-(1-exo_exit)*measure_vec_n(end-1);
        m_entry_o(end) = sum(final_dist_o,"all")-(1-exo_exit)*measure_vec_o(end-1);
    end
    if strlength(checkpoint_file)>0
        save_green_checkpoint(checkpoint_file,h+1,p_E_vec,p_E_prev,p_e_o_vec,p_e_o_prev,...
            m_entry_n,m_entry_o,m_entry_n_prev,m_entry_o_prev,value_err_n_prev,value_err_o_prev,...
            measure_adjust_n,measure_adjust_o,demand_err_prev,input_err_prev,output_adjust,input_adjust);
    end
end

fprintf("green MIT finished at h=%d, k=%d\n",h,k);
fprintf("demand error mean=%g max=%g; fuel error mean=%g max=%g\n",...
    mean(abs(demand_err)),max(abs(demand_err)),mean(abs(input_err)),max(abs(input_err)));
fprintf("green entry error mean=%g max=%g; fossil entry error mean=%g max=%g\n",...
    mean(abs(value_err_n(active))),max(abs(value_err_n(active))),...
    mean(abs(value_err_o(active))),max(abs(value_err_o(active))));
fprintf("terminal measure gap green=%g, fossil=%g\n",...
    sum(final_dist_n)-measure_vec_n(end),sum(final_dist_o)-measure_vec_o(end));

entry_n_path = m_entry_n;
entry_o_path = m_entry_o;
input_all_o = input_all_o(1:trans_t);
end

function [grid,prob,entry_grid,entry_prob,fco,adopt_cost,entry_cost,e0,elasticity,rho_p,sigma_p] = ...
    fossil_inputs(path,grid0,prob0,fco0,adopt0,entry0,e00,elasticity0,rho0,sigma0,T)
grid = fit_matrix(field_or(path,"grid_stock",grid0(:)),T);
prob = normalize_columns(fit_matrix(field_or(path,"prob_stock",prob0(:)),T));
entry_grid = fit_matrix(field_or(path,"grid_entry",grid),T);
entry_prob = normalize_columns(fit_matrix(field_or(path,"prob_entry",prob),T));
fco = fit_row(field_or(path,"fco",fco0),T);
adopt_cost = fit_row(field_or(path,"adopt_cost",adopt0),T);
entry_cost = fit_row(field_or(path,"entry_cost",entry0),T);
e0 = fit_row(field_or(path,"e0",e00),T);
elasticity = fit_row(field_or(path,"fuel_elasticity",elasticity0),T);
rho_p = fit_row(field_or(path,"rho_p",rho0),T);
sigma_p = fit_row(field_or(path,"sigma_p",sigma0),T);
end

function value = field_or(S,name,fallback)
if isfield(S,name)&&~isempty(S.(name)), value=S.(name); else, value=fallback; end
end

function value = checkpoint_value(S,name,fallback)
if isfield(S,name), value=S.(name); else, value=fallback; end
end

function out = fit_row(value,T)
value = reshape(value,1,[]);
if numel(value)>=T, out=value(1:T); else, out=[value,repmat(value(end),1,T-numel(value))]; end
end

function out = fit_matrix(value,T)
if isvector(value), value=value(:); end
if size(value,2)>=T, out=value(:,1:T); else, out=[value,repmat(value(:,end),1,T-size(value,2))]; end
end

function out = normalize_columns(value)
value = max(value,0);
out = value./max(sum(value,1),sqrt(eps));
end

function mapped = map_distribution(source_grid,source_prob,target_grid)
mapped = zeros(numel(target_grid),1);
for ii=1:numel(source_grid)
    x = source_grid(ii);
    hi = sum(target_grid<x)+1;
    if hi>numel(target_grid), mapped(end)=mapped(end)+source_prob(ii);
    elseif hi==1, mapped(1)=mapped(1)+source_prob(ii);
    else
        lo = hi-1;
        w = (x-target_grid(lo))/max(target_grid(hi)-target_grid(lo),sqrt(eps));
        mapped(lo)=mapped(lo)+source_prob(ii)*(1-w);
        mapped(hi)=mapped(hi)+source_prob(ii)*w;
    end
end
mapped = mapped/sum(mapped);
end

function address = precompute_transition_addresses(a_num_g,age_num)
n_state = a_num_g*age_num;
address.source = repelem((1:n_state)',a_num_g);
address.dest_type = repmat((1:a_num_g)',n_state,1);
address.state_age = repelem(repelem((1:age_num)',a_num_g),a_num_g);
address.state_type = repmat(repelem((1:a_num_g)',a_num_g),age_num,1);
address.n_state = n_state;
address.a_num_g = a_num_g;
address.age_num = age_num;
end

function [value,policy,exit_vec] = value_step_from_next(pi_mat,value_next,prob,beta,cost,age_reduc,exo_exit)
[age_num,a_num_g] = size(pi_mat);
continuation = [value_next(2:end,:);zeros(1,a_num_g)];
adopt_age = max((1:age_num)-age_reduc,1);
adoption = value_next(adopt_age,:)-cost;
choice_age = adoption>continuation;
best = continuation+(adoption-continuation).*choice_age;
value = pi_mat+beta*(1-exo_exit)*(best*prob');
exit_vec = value<=0;
value = max(value,0);
exit_vec = exit_vec';
exit_vec = exit_vec(:);
policy = repelem(choice_age,a_num_g,1).*(1-exit_vec);
end

function transition = build_transition_fast(policy,exit_vec,prob,a_prob,age_reduc,exo_exit,A)
choice = reshape(policy',[],1);
target_age = min(A.state_age+1,A.age_num);
target_age(choice>0) = max(A.state_age(choice>0)-age_reduc,1);
keep = (choice>0|A.state_age<A.age_num)&repelem(exit_vec<1,A.a_num_g);
target = (target_age-1)*A.a_num_g+A.dest_type;
prob_values = prob(sub2ind(size(prob),A.state_type,A.dest_type))*(1-exo_exit);
transition = sparse(A.source(keep),target(keep),prob_values(keep),A.n_state,A.n_state);
last = (A.age_num-1)*A.a_num_g+1:A.n_state;
transition(last,1:A.a_num_g) = repmat(a_prob,A.a_num_g,1).*(1-exit_vec(last));
end

function dist = entry_dist(prob,a_num_g,age_num)
dist = zeros(1,a_num_g*age_num);
dist(1:a_num_g) = prob;
end

function path = initial_entry_path(init_dist,final_dist,exit_final,T)
base = 1+exp(linspace(0,-10,T));
target = (sum(final_dist)-sum(init_dist))/T+max(exit_final,0);
path = max(target,1e-8)*T*base/sum(base);
end

function [path,previous_path,adjust] = update_entry_path(path,error,error_previous,previous_path,adjust,v_tol)
lag = path;
active = 1:max(numel(path)-1,1);
zero_restart = path(active)==0 & error(active)'>0;
path(active(zero_restart)) = max(10*v_tol,1e-8);
step = 0.1*(abs(error(active)')>50)+0.2*(abs(error(active)')<=50)+0.2*(abs(error(active)')<=1);
path(active) = path(active).*(1+step.*adjust(active).*error(active)');
oscill = false(size(path));
oscill(active) = sign(error(active)')~=sign(error_previous(active)');
den = max(abs(error(active)')+abs(error_previous(active)'),sqrt(eps));
oscill_active = oscill(active);
idx = active(oscill_active);
path(idx) = (lag(idx).*abs(error_previous(idx)')+previous_path(idx).*abs(error(idx)'))./den(oscill_active);
adjust = adjust.*(0.95.^double(oscill));
path(active) = max(path(active),0);
previous_path = lag;
end

function [cap,order] = solar_availability_grid(P_E_grid_norm,mean_cap,corr)
[~,order] = sort(P_E_grid_norm,"ascend");
sorted = linspace(1+corr,1-corr,numel(P_E_grid_norm))';
cap = zeros(size(sorted));
cap(order) = sorted;
cap = max(min(mean_cap*cap/mean(cap),1),0);
end

function file = checkpoint_filename(name)
file = string(name);
if strlength(file)>0 && ~endsWith(file,".mat"), file=file+".mat"; end
end

function save_green_checkpoint(file,h_start,p_E_vec,p_E_prev,p_e_o_vec,p_e_o_prev,...
    m_entry_n,m_entry_o,m_entry_n_prev,m_entry_o_prev,value_err_n_prev,value_err_o_prev,...
    measure_adjust_n,measure_adjust_o,demand_err_prev,input_err_prev,output_adjust,input_adjust)
save(file,"h_start","p_E_vec","p_E_prev","p_e_o_vec","p_e_o_prev","m_entry_n","m_entry_o",...
    "m_entry_n_prev","m_entry_o_prev","value_err_n_prev","value_err_o_prev",...
    "measure_adjust_n","measure_adjust_o","demand_err_prev","input_err_prev",...
    "output_adjust","input_adjust");
end
