function [trans_prob_o_all,v_new_resh_o_all,dist_o_all,measure_vec_o,p_e_o_vec,input_all_o,...
    trans_prob_n_all,v_new_resh_n_all,dist_n_all,measure_vec_n,p_E_vec,cap_old,cap_new,...
    age_g,a_grid_old,a_prob_old,a_grid_n_all,a_prob_n_all,entry_n_path,adopt_n_path,tax_revenue_path] = ...
    MIT_transition_green(a_grow,alpha,beta,c_of_a,c_a_new_vec,a_grid_old,a_prob_old,...
    mu_new_vec,sigma_new_vec,a_num_g,age_num,max_iter,v_tol,fco_o,fco_n,e_p,d_0,...
    c_of_e,c_e_new_vec,dem_tol,init_dist_n,init_dist_o,final_val_o,final_val_n,...
    init_p_E,final_p_E,trans_t,final_dist_n,final_dist_o,e0_o,e_o_eps,...
    fin_p_e_o,init_p_e_o,rho,age_reduc,exit_n_final,exit_o_final,exo_exit,...
    init_input_o,penalty_o,penalty_p,d0_gr,rho_p_o,sigma_p_o,solar_cap_mean,solar_price_corr,fossil_tax_vec)

if nargin<47 || isempty(fossil_tax_vec)
    fossil_tax_vec = zeros(1,trans_t);
end
fossil_tax_vec = fossil_tax_vec(:)';

age_g = (linspace(0,age_num-1,age_num))';
P_E_grid_norm = P_E_grid(50,1);
p_e_o_grid_norm = p_input_grid(10,1,sigma_p_o,rho_p_o);

[solar_cap_norm,~] = solar_availability_grid(P_E_grid_norm,solar_cap_mean,solar_price_corr);

a_grid_old = a_grid_old(:)';
a_prob_old = a_prob_old(:)'/sum(a_prob_old);
prob_matrix_old = auto_corr_prob(a_grid_old,a_prob_old,rho);

a_grid_n_all = zeros(a_num_g,trans_t);
a_prob_n_all = zeros(a_num_g,trans_t);
prob_mat_n_all = cell(trans_t,1);
for tt=1:trans_t
    x_new = norminv(linspace(0,1,a_num_g+2),mu_new_vec(tt),sigma_new_vec(tt));
    a_grid_new = x_new(2:a_num_g+1)';
    a_cdf_new = normcdf(x_new,mu_new_vec(tt),sigma_new_vec(tt));
    a_prob_new = (a_cdf_new(2:a_num_g+1)-a_cdf_new(1:a_num_g))';
    a_grid_n_all(:,tt) = a_grid_new;
    a_prob_n_all(:,tt) = a_prob_new/sum(a_prob_new);

    if tt<trans_t
        x_next = norminv(linspace(0,1,a_num_g+2),mu_new_vec(tt+1),sigma_new_vec(tt+1));
        a_grid_next = x_next(2:a_num_g+1)';
        a_cdf_next = normcdf(x_next,mu_new_vec(tt+1),sigma_new_vec(tt+1));
    else
        a_grid_next = a_grid_new;
        a_cdf_next = a_cdf_new;
    end
    a_prob_next = (a_cdf_next(2:a_num_g+1)-a_cdf_next(1:a_num_g))';
    prob_mat_n_all{tt} = auto_corr_prob_transition2(a_grid_new,a_prob_next,rho,a_grid_next);
end

p_E_vec = linspace(init_p_E,final_p_E,trans_t);
p_E_prev = p_E_vec;
p_e_o_vec = linspace(init_p_e_o,fin_p_e_o,trans_t);
p_e_o_vec_pre = p_e_o_vec;
d0_vec = d_0*(1+d0_gr).^(1:trans_t);

dist_n_all  = zeros(trans_t,age_num*a_num_g);
dist_o_all  = zeros(trans_t,age_num*a_num_g);
v_new_resh_n_all = zeros(age_num,a_num_g,trans_t);
v_new_resh_o_all = zeros(age_num,a_num_g,trans_t);

policy_choice_n_all = zeros(age_num*a_num_g,a_num_g,trans_t);
policy_choice_o_all = zeros(age_num*a_num_g,a_num_g,trans_t);

trans_prob_n_all    = zeros(age_num*a_num_g,trans_t);
trans_prob_o_all    = zeros(age_num*a_num_g,trans_t);

exit_vec_n_all  = zeros(age_num*a_num_g,trans_t);
exit_vec_o_all  = zeros(age_num*a_num_g,trans_t);

measure_vec_n   = linspace(sum(init_dist_n),sum(final_dist_n),trans_t);
measure_vec_o   = linspace(sum(init_dist_o),sum(final_dist_o),trans_t);
input_all_o     = init_input_o*ones(trans_t,1);
cap_old     = zeros(1,trans_t);
cap_new     = zeros(1,trans_t);
p_e_o_adj   = 0.01*ones(trans_t,1);
adopt_n_path = zeros(1,trans_t);
tax_revenue_path = zeros(1,trans_t);

m_entry_n = initial_entry_path(init_dist_n,final_dist_n,exit_n_final,trans_t);
m_entry_o = initial_entry_path(init_dist_o,final_dist_o,exit_o_final,trans_t);
m_entry_n_prev = m_entry_n;
m_entry_o_prev = m_entry_o;
value_err_n_prev = zeros(trans_t,1);
value_err_o_prev = zeros(trans_t,1);

for h=1:max_iter
    for k=1:floor(max_iter/10)
        v_next_n = final_val_n;
        v_next_o = final_val_o;

        for tt=trans_t:-1:1
            a_grid_new = a_grid_n_all(:,tt);
            if tt<trans_t
                a_grid_next = a_grid_n_all(:,tt+1);
            else
                a_grid_next = a_grid_new;
            end
            [idx_hi,ratio_hi] = bracket_grid(a_grid_new,a_grid_next);
            idx_exp     = repmat(idx_hi,age_num,1)+kron((0:age_num-1)',a_num_g*ones(a_num_g,1));
            ratio_exp   = repmat(ratio_hi,age_num,1);

            v_p_n = v_next_n';
            v_p_n(:,1:age_num-1) = v_p_n(:,2:age_num);
            v_p_n(:,age_num) = 0;
            v_p_n_vec = v_p_n(:);
            v_p_n_vec = v_p_n_vec(idx_exp).*(1-ratio_exp) + v_p_n_vec(idx_exp-1).*ratio_exp;

            a_eff_n = a_grid_new .* max(1-a_grow.*age_g',0);
            [~,~,pi_n] = solar_static_solver(a_eff_n,p_E_vec(tt).*P_E_grid_norm,solar_cap_norm,fco_n);
            [v_next_n,policy_choice_n,exit_vec_n] = solve_branch_value_from_next(pi_n',v_p_n_vec,prob_mat_n_all{tt},...
                beta,c_a_new_vec(max(tt,1)),v_tol,age_reduc,exo_exit,a_num_g,age_num);

            a_eff_o = a_grid_old' .* max(1-a_grow.*age_g',0);
            p_e_o_plant = p_e_o_vec(tt) + fossil_tax_vec(tt);
            [~,~,pi_o] = static_solver(a_eff_o,p_E_vec(tt).*P_E_grid_norm,p_e_o_plant.*p_e_o_grid_norm,alpha,fco_o,1./a_grid_old(:));
            v_p_o = v_next_o';
            v_p_o(:,1:age_num-1) = v_p_o(:,2:age_num);
            v_p_o(:,age_num) = 0;
            [v_next_o,policy_choice_o,exit_vec_o] = solve_branch_value_from_next(pi_o',v_p_o(:),prob_matrix_old,...
                beta,c_of_a,v_tol,age_reduc,exo_exit,a_num_g,age_num);

            v_new_resh_n_all(:,:,tt) = v_next_n;
            v_new_resh_o_all(:,:,tt) = v_next_o;
            policy_choice_n_all(:,:,tt) = policy_choice_n;
            policy_choice_o_all(:,:,tt) = policy_choice_o;
            exit_vec_n_all(:,tt) = exit_vec_n;
            exit_vec_o_all(:,tt) = exit_vec_o;
            trans_prob_n_all(:,tt) = sum(policy_choice_n.*repmat(prob_mat_n_all{tt},age_num,1),2);
            trans_prob_o_all(:,tt) = sum(policy_choice_o.*repmat(prob_matrix_old,age_num,1),2);
        end

        dist_n = init_dist_n;
        dist_o = init_dist_o;
        for tt=1:trans_t
            a_grid_new = a_grid_n_all(:,tt);
            if tt<trans_t
                a_grid_next = a_grid_n_all(:,tt+1);
            else
                a_grid_next = a_grid_new;
            end
            [idx_hi,ratio_hi] = bracket_grid(a_grid_new,a_grid_next);
            trans_n = build_transition(policy_choice_n_all(:,:,tt),exit_vec_n_all(:,tt),prob_mat_n_all{tt},...
                a_prob_n_all(:,tt)',age_reduc,exo_exit,a_num_g,age_num,idx_hi,ratio_hi,true);
            trans_o = build_transition(policy_choice_o_all(:,:,tt),exit_vec_o_all(:,tt),prob_matrix_old,...
                a_prob_old,age_reduc,exo_exit,a_num_g,age_num,[],[],false);

            a_eff_n = a_grid_new .* max(1-a_grow.*age_g',0);
            [~,cap_n] = solar_static_solver(a_eff_n,p_E_vec(tt).*P_E_grid_norm,solar_cap_norm,fco_n);
            a_eff_o = a_grid_old' .* max(1-a_grow.*age_g',0);
            p_e_o_plant = p_e_o_vec(tt) + fossil_tax_vec(tt);
            [eff_o,cap_o] = static_solver(a_eff_o,p_E_vec(tt).*P_E_grid_norm,p_e_o_plant.*p_e_o_grid_norm,alpha,fco_o,1./a_grid_old(:));

            cap_new(tt) = dist_n*cap_n(:);
            cap_old(tt) = dist_o*cap_o(:);
            input_old = dist_o*eff_o(:);
            adopt_n_path(tt) = dist_n*trans_prob_n_all(:,tt);
            tax_revenue_path(tt) = fossil_tax_vec(tt)*input_old;

            dist_n = dist_n*trans_n + m_entry_n(tt)*entry_dist(a_prob_n_all(:,tt)',a_num_g,age_num);
            dist_o = dist_o*trans_o + m_entry_o(tt)*entry_dist(a_prob_old,a_num_g,age_num);

            dist_n_all(tt,:) = dist_n;
            dist_o_all(tt,:) = dist_o;
            measure_vec_n(tt) = sum(dist_n);
            measure_vec_o(tt) = sum(dist_o);
            input_all_o(min(tt+1,trans_t)) = input_old;

            p_e_target = (input_old/e0_o * (input_old/max(input_all_o(tt),1e-8))^penalty_o)^(1/e_o_eps);
            p_e_o_adj(tt) = 0.04*(p_e_target-p_e_o_vec_pre(tt));
            p_e_o_vec(tt) = p_e_o_vec_pre(tt)+p_e_o_adj(tt);
        end

        total_cap = cap_old+cap_new;
        total_cap_lag = [d_0/(init_p_E^e_p), total_cap(1:end-1)];
        supply_price = (d0_vec./(total_cap.*(total_cap./total_cap_lag).^penalty_p)).^(1/e_p);
        demand_err = max(min(supply_price-p_E_vec,25),-25);
        p_E_vec = p_E_vec + 0.5*demand_err/ceil(k/20);

        if mean(abs(demand_err)<dem_tol | abs(p_E_vec-p_E_prev)<5*v_tol)>0.99 && mean(abs(p_e_o_adj)<5*v_tol)>0.99
            break;
        end
        p_E_prev = p_E_vec;
        p_e_o_vec_pre = p_e_o_vec;
    end

    value_err_n = sum(a_prob_n_all.*squeeze(v_new_resh_n_all(1,:,:)),1)'-c_e_new_vec(:);
    value_err_o = sum(a_prob_old(:).*squeeze(v_new_resh_o_all(1,:,:)),1)'-c_of_e;
    if mean(abs(value_err_n)<5*dem_tol | m_entry_n(:)<v_tol)>=0.95 && ...
            mean(abs(value_err_o)<5*dem_tol | m_entry_o(:)<v_tol)>=0.95 && ...
            abs(sum(final_dist_n)-measure_vec_n(end))<dem_tol
        fprintf("green MIT entry converged in %2.1f iterations\n",h);
        break;
    end

    m_entry_n = adjust_entry_path(m_entry_n,value_err_n,measure_vec_n(end),sum(final_dist_n),m_entry_n_prev);
    m_entry_o = adjust_entry_path(m_entry_o,value_err_o,measure_vec_o(end),sum(final_dist_o),m_entry_o_prev);
    m_entry_n_prev = m_entry_n;
    m_entry_o_prev = m_entry_o;
end
entry_n_path = m_entry_n;
end

function [solar_cap_norm,price_order] = solar_availability_grid(P_E_grid_norm,solar_cap_mean,solar_price_corr)
[~,price_order] = sort(P_E_grid_norm,'ascend');
n = numel(P_E_grid_norm);
solar_cap_sorted = linspace(1+solar_price_corr,1-solar_price_corr,n)';
solar_cap_norm = zeros(n,1);
solar_cap_norm(price_order) = solar_cap_sorted;
solar_cap_norm = solar_cap_mean*solar_cap_norm/mean(solar_cap_norm);
solar_cap_norm = max(min(solar_cap_norm,1),0);
end

function path = initial_entry_path(init_dist,final_dist,exit_final,trans_t)
base = 1+exp(linspace(0,-10,trans_t));
target = (sum(final_dist)-sum(init_dist))/trans_t + max(exit_final,0);
path = max(target,10^-8)*trans_t*base/sum(base);
end

function [idx_hi,ratio_hi] = bracket_grid(a_grid_current,a_grid_next)
idx_cell = arrayfun(@(x) find(x<=a_grid_next,1,'first'),a_grid_current,'UniformOutput',false);
idx_hi = cellfun(@(x) choose_idx(x,numel(a_grid_next)),idx_cell);
idx_hi(idx_hi<2) = 2;
idx_hi(idx_hi>numel(a_grid_next)) = numel(a_grid_next);
ratio_hi = (a_grid_next(idx_hi)-a_grid_current)./(a_grid_next(idx_hi)-a_grid_next(idx_hi-1));
ratio_hi = max(min(ratio_hi,1),0);
end

function idx = choose_idx(value,fallback)
if isempty(value)
    idx = fallback;
else
    idx = value;
end
end

function [v_new_resh,policy_choice,exit_vec] = solve_branch_value_from_next(pi_contemp,v_continue_vec,prob_matrix,beta,c_a,v_tol,age_reduc,exo_exit,a_num_g,age_num)
v_adopt_mat = zeros(age_num,a_num_g);
v_cont_mat = reshape(v_continue_vec,a_num_g,age_num)';
for age=1:age_num
    adopt_age = max(age-age_reduc,1);
    v_adopt_mat(age,:) = v_cont_mat(adopt_age,:);
end
v_adopt_vec = v_adopt_mat';
v_adopt_vec = v_adopt_vec(:)-c_a;
v_continue_expand = kron(v_continue_vec,ones(a_num_g,1));
v_adopt_expand = kron(v_adopt_vec,ones(a_num_g,1));
choice_vec = v_adopt_expand>v_continue_expand;
v_best = v_continue_expand + (v_adopt_expand-v_continue_expand).*choice_vec;
v_best_resh = reshape(v_best,a_num_g,age_num*a_num_g)';
v_new = sum(v_best_resh.*repmat(prob_matrix,age_num,1),2);
v_new_resh = reshape(v_new,a_num_g,age_num)' ;
v_new_resh = pi_contemp + beta*(1-exo_exit)*v_new_resh;
exit_vec = (v_new_resh<0)';
exit_vec = exit_vec(:);
v_new_resh(v_new_resh<0) = 0;
policy_choice = reshape(choice_vec,a_num_g,age_num*a_num_g)';
policy_choice = (1-exit_vec).*policy_choice;
end

function trans_matrix = build_transition(policy_choice,exit_vec,prob_matrix,a_prob,age_reduc,exo_exit,a_num_g,age_num,idx_hi,ratio_hi,map_grid)
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
            prob = prob_matrix(ia,ja)*(1-exo_exit);
            if policy_choice(s,ja)>0
                target_age = max(age-age_reduc,1);
            elseif age<age_num
                target_age = age+1;
            else
                continue;
            end
            if map_grid
                hi = idx_hi(ja);
                lo = hi-1;
                r = ratio_hi(ja);
                rows = [rows s s]; %#ok<AGROW>
                cols = [cols (target_age-1)*a_num_g+lo (target_age-1)*a_num_g+hi]; %#ok<AGROW>
                vals = [vals prob*r prob*(1-r)]; %#ok<AGROW>
            else
                rows(end+1) = s; %#ok<AGROW>
                cols(end+1) = (target_age-1)*a_num_g+ja; %#ok<AGROW>
                vals(end+1) = prob; %#ok<AGROW>
            end
        end
    end
end
trans_matrix = sparse(rows,cols,vals,age_num*a_num_g,age_num*a_num_g);
trans_matrix((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = repmat(a_prob,a_num_g,1).*(1-exit_vec((age_num-1)*a_num_g+1:age_num*a_num_g));
end

function dist_ent = entry_dist(a_prob,a_num_g,age_num)
dist_ent = zeros(1,age_num*a_num_g);
dist_ent(1:a_num_g) = a_prob;
end

function path = adjust_entry_path(path,value_err,end_measure,target_measure,previous_path)
if abs(end_measure-target_measure)<0.1
    path = path.*(1+0.2*value_err');
else
    path = (path+1e-8)/sum(path+1e-8)*(sum(path)+0.1*(target_measure-end_measure));
end
path = max(path,0);
path = path.*(sign(value_err')==sign(previous_path-path)) + (path+previous_path)/2.*(sign(value_err')~=sign(previous_path-path));
end
