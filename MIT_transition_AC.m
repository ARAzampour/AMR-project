function [trans_prob_o_all,v_new_resh_o_all,dist_o_all,measure_vec_o,p_e_o_vec,input_all_o,...
    trans_prob_n_all,v_new_resh_n_all,dist_n_all,measure_vec_n,p_e_n_vec,input_all_n,...
    age_g,a_grid_old,a_prob_old,a_grid_n_all,a_prob_n_all,p_E_vec,cap_old,cap_new] =...
    MIT_transition_AC(a_grow,alpha,~,beta,c_of_a,c_a_new_vec,mu_old,sigma_old,...
    mu_new_vec, sigma_new_vec, a_num_g,age_num,max_iter,...
    v_tol,~,fco_o,fco_n,e_p,d_0,c_of_e,c_e_new_vec,dem_tol,init_dist_n,init_dist_o,final_val1,final_val2,...
    diff_gr,diff_gr_t,init_p_E,final_p_E,trans_t,final_dist_n,final_dist_o,...
    e0_n_vec,e0_o,e_n_eps,e_o_eps,diff_gr_cons,fin_p_e_n,init_p_e_n,...
    fin_p_e_o,init_p_e_o,rho,age_reduc,c_conver,conv_rate,exit_n_final,exit_o_final,...
    exo_exit,~,~,init_input_n,init_input_o,penalty_o,penalty_n,penalty_p,d0_gr,...
    rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,checkpoint_name)

if nargin<62
    checkpoint_name = "";
end
checkpoint_file = checkpoint_filename(checkpoint_name);
use_checkpoint = strlength(checkpoint_file)>0;
checkpoint_freq = 50;

%%% conv_rate is used to make the conversion slower, the reason is that
%%% sudden conversion creates swinging features
x_old = norminv(linspace(0,1,a_num_g+2),mu_old,sigma_old); %%% looking at the entrants, 
                            %%% distribution we have now decided to use
                            %%% normal distribution 2024-09-11
% a_grid  = expinv(1-exp(linspace(log(1),log(0.001),a_num_g)),a_lamb); %%% here
                %%%% I've change the spacing for grid productivity, the
                %%%% reason is that by using the grid the gives equall prob
                %%%% to each grid point we would focus to much on the
                %%%% points that no action would be happening
a_grid_old  = x_old(2:a_num_g+1);
% a_g_nex = (a_grid_old)'/(1+diff_gr);
a_cdf_old   = normcdf(x_old,mu_old,sigma_old);
a_prob_old  = a_cdf_old(2:a_num_g+1)-a_cdf_old(1:a_num_g);
a_prob_old  = a_prob_old/sum(a_prob_old);

prob_matrix_old     = auto_corr_prob(a_grid_old,a_prob_old,rho);


max_iter_price      = floor(max_iter/10);
max_iter_measure    = max_iter_price*10;
 
age_g   = (linspace(0,age_num-1,age_num))';
exit_sm = 2;

%%% new tech effective productivity: a_{i,t} = a_i*(1 - a_grow*t), capped at zero
%%% constant across transition periods (does not depend on tech_dist_vec)
% a_eff_o = a_grid_old' .* max(1 - a_grow .* age_g', 0);  

a_prob_n_all    = zeros(a_num_g,trans_t);
prob_mat_n_all  = cell(trans_t,1);
a_grid_n_all    = zeros(a_num_g,trans_t);


for ii=1:1:trans_t
    x_new = norminv(linspace(0,1,a_num_g+2),mu_new_vec(ii),sigma_new_vec(ii)); %%% looking at the entrants, 
                    %%% distribution we have now decided to use
                    %%% normal distribution 2024-09-11
  
    a_grid_new  = x_new(2:a_num_g+1);
    a_grid_n_all(:,ii) = a_grid_new;

    a_cdf_new   = normcdf(x_new,mu_new_vec(ii),sigma_new_vec(ii));
    a_prob_new  = a_cdf_new(2:a_num_g+1)-a_cdf_new(1:a_num_g);
    a_prob_new  = a_prob_new/sum(a_prob_new);

    a_prob_n_all(:,ii) = a_prob_new;

    if ii<trans_t
        x_new_next = norminv(linspace(0,1,a_num_g+2),mu_new_vec(ii+1),sigma_new_vec(ii+1));
        a_cdf_Next = normcdf(x_new_next,mu_new_vec(ii+1),sigma_new_vec(ii+1));
    else
        x_new_next = norminv(linspace(0,1,a_num_g+2),mu_new_vec(end),sigma_new_vec(end));
        a_cdf_Next = normcdf(x_new_next,mu_new_vec(end),sigma_new_vec(end));
    end

    a_grid_next  = x_new_next(2:a_num_g+1);
    
    a_prob_Next  = a_cdf_Next(2:a_num_g+1)-a_cdf_Next(1:a_num_g);
    a_prob_Next  = a_prob_Next/sum(a_prob_Next);

    
    prob_matrix_tr      = auto_corr_prob_transition2(a_grid_new,a_prob_Next,rho,a_grid_next);
    prob_mat_n_all{ii}  = prob_matrix_tr;
     
  
end

if ~exist("rho_p_n","var")
    rho_p_n = 0.95;
end
if ~exist("sigma_p_n","var")
    sigma_p_n = 0.2;
end
if ~exist("rho_p_o","var")
    rho_p_o = 0.95;
end
if ~exist("sigma_p_o","var")
    sigma_p_o = 0.2;
end

%%% normalized price grids: scaled by period-specific mean prices along the transition
n_PE = 50;
n_pe = 10;
P_E_grid_norm   = P_E_grid(n_PE,1);
p_e_n_grid_norm = p_input_grid(n_pe,1,sigma_p_n,rho_p_n);
p_e_o_grid_norm = p_input_grid(n_pe,1,sigma_p_o,rho_p_o);

dist_o_all          = zeros(trans_t,age_num*a_num_g);
dist_n_all          = zeros(trans_t,age_num*a_num_g);
% policy_choice_n     = zeros(age_num*a_num_g,a_num_g);
% policy_choice_o     = zeros(age_num*a_num_g,a_num_g);

trans_prob_n_all    = zeros(age_num*a_num_g,trans_t);
trans_prob_o_all    = zeros(age_num*a_num_g,trans_t);

p_E_vec         = linspace(init_p_E,final_p_E,trans_t);
p_E_prev        = linspace(init_p_E,final_p_E,trans_t);
p_e_n_vec       = linspace(init_p_e_n,fin_p_e_n,trans_t);
p_e_o_vec       = linspace(init_p_e_o,fin_p_e_o,trans_t);
p_e_n_vec_pre   = linspace(init_p_e_n,fin_p_e_n,trans_t);
p_e_o_vec_pre   = linspace(init_p_e_o,fin_p_e_o,trans_t);
dem_err_pre     = 1;
demand_err      = 1;

growth_t_line   = diff_gr_t*ones(1,trans_t);
growth_t_line(1:diff_gr_t) = linspace(1,diff_gr_t,diff_gr_t);
tech_dist_vec   = (1+diff_gr).^growth_t_line*diff_gr_cons;
d0_vec          = d_0*(1+d0_gr).^(1:1:trans_t);

% v_of_new    = final_val2;
% v_of_old    = final_val1;

v_new_resh_n_all    = zeros(age_num,a_num_g,trans_t);
v_new_resh_o_all    = zeros(age_num,a_num_g,trans_t);

policy_choice_o_all = zeros(age_num*a_num_g,a_num_g,trans_t);
policy_choice_n_all = zeros(age_num*a_num_g,a_num_g,trans_t);

exit_vec_n_all      = zeros(age_num*a_num_g,trans_t);
exit_vec_o_all      = zeros(age_num*a_num_g,trans_t);

measure_vec_n       = linspace(sum(init_dist_n,'all'),sum(final_dist_n,'all'),trans_t);
measure_vec_o       = linspace(sum(init_dist_o,'all'),sum(final_dist_o,'all'),trans_t);

m_of_entry_n        = 1+exp(linspace(0,-10,trans_t));
m_of_entry_n        = trans_t*m_of_entry_n/(sum(m_of_entry_n))*...
    ((sum(final_dist_n,'all')-sum(init_dist_n,'all')+...
    0)/trans_t)... %% (sum(final_dist_o,'all')-sum(init_dist_o,'all'))
    +exo_exit*linspace(sum(init_dist_n),sum(final_dist_n),trans_t);
    
m_of_entry_o        = 1+exp(linspace(0,-10,trans_t));
m_of_entry_o        = trans_t*m_of_entry_o/(sum(m_of_entry_o))*...
    ((sum(final_dist_o,'all')-sum(init_dist_o,'all')-...
    0)/trans_t)... %% (sum(final_dist_n,'all')-sum(init_dist_n,'all'))
    +exo_exit*linspace(sum(init_dist_o),sum(final_dist_o),trans_t);

m_of_entry_n(m_of_entry_n<0)    = 0;
m_of_entry_o(m_of_entry_o<0)    = 0;

if max(m_of_entry_n)<v_tol && max(m_of_entry_o)<v_tol
    m_of_entry_n    = 10*v_tol*ones(1,trans_t);
    m_of_entry_o    = 10*v_tol*ones(1,trans_t);
end

value_err_n_pre     = zeros(trans_t,1);
value_err_o_pre     = zeros(trans_t,1);
entry_new_pre       = m_of_entry_n;
entry_old_pre       = m_of_entry_o;

entry_old_pre(isnan(entry_old_pre)) = 0;
p_conv_o_all        = zeros(age_num*a_num_g,trans_t);
p_conv_o_all_prev   = zeros(age_num*a_num_g,trans_t);
converion_o_all     = zeros(age_num*a_num_g,trans_t);
converion_o_all_pre = zeros(age_num*a_num_g,trans_t);
conv_decrease_all   = zeros(age_num*a_num_g,trans_t);


measure_vec_n_rec   = zeros(max_iter_measure,trans_t);
measure_vec_o_rec   = zeros(max_iter_measure,trans_t);
price_vec_rec       = zeros(max_iter_measure,trans_t);

exit_n      = zeros(trans_t,1);
exit_o      = zeros(trans_t,1);
conv_entry  = zeros(trans_t,1);
conv_exit   = zeros(trans_t,1);

price_ratio_n_p = 0.9*ones(1,trans_t);  %%%% ratio of price of electricity to input in the previous period
price_ratio_o_p = 0.9*ones(1,trans_t);
price_ratio_n_q = 0.9*ones(1,trans_t);  %%%% ratio of price of electricity to input in the 2 previous period
price_ratio_o_q = 0.9*ones(1,trans_t);

%%%
input_adjsut    = 0.2;         %%%% the maximum variation in input price
output_adjsut   = 0.1/(max(e_n_eps,e_o_eps)); %%% max var in output prices
measure_adj_n   = min(0.02/(e_n_eps),1); %%%% the maximum variation in newtech measure
measure_adj_o   = min(0.02/(e_o_eps),1); %%%% the maximum variation in newtech measure





%%%
lag_grow_compensate = (1+diff_gr).*((1:1:trans_t)<diff_gr_t)+...
    1*((1:1:trans_t)>=diff_gr_t);                   %%% the notion here
                %%%% is that beacuase in each period the dist of last
                %%%% period is used to get the profit, production and input
                %%%% these functions should also belong to the last period

%%%
input_all_n         = init_input_n*ones(trans_t,1);
input_all_o         = init_input_o*ones(trans_t,1);

%%% the price of input should also be stable between two iterations. The
%%% following variables are used to ensure that
input_adjsut_o_all  = 0.01*ones(trans_t,1);
input_adjsut_n_all  = 0.01*ones(trans_t,1);
i_a_param           = 0.1;

%%% Static decisions are solved once per technology and transition period
%%% in each price iteration, then reused by both backward and forward loops.
eff_n_cache = zeros(a_num_g,age_num,trans_t,"single");
cap_n_cache = zeros(a_num_g,age_num,trans_t,"single");
pi_n_cache  = zeros(a_num_g,age_num,trans_t,"single");
eff_o_cache = zeros(a_num_g,age_num,trans_t,"single");
cap_o_cache = zeros(a_num_g,age_num,trans_t,"single");
pi_o_cache  = zeros(a_num_g,age_num,trans_t,"single");

%%% The adjustment in the price of electricity will be bounded and weight_adj_p
%%% will determine the amount of adjustment when bound is reached
weight_adj_p        = 0.2;

%%% Grid interpolation and sparse-transition addresses depend only on the
%%% fixed grids and dimensions, so construct them once rather than in every
%%% value/distribution iteration.
[temp_index_grid_exp_all,rat_of_tran_exp_all,tech_con_exp_all,...
    ratio_tech_conv_all,state_if_adopt_y,state_if_adopt_x,temp_address,...
    state_if_naot_n_y_all,state_if_naot_n_x_all,state_if_naot_o_y,...
    state_if_naot_o_x,conv_address_y1_all,conv_address_y2_all,...
    conv_address_x1_all,conv_address_x2_all] = precompute_mit_mappings(...
    a_grid_n_all,a_grid_old,age_num,a_num_g,age_reduc,trans_t);

%%%%%% Important note %%%%%%%%
%%% In the transition first the output (and its decision) happens and then
%%% the decisions on adoption (conversion) and exit are made. This means
%%% that in the period t of the transtion a generator would make it
%%% decisions for the period t+1 and therefore in the adjustment of measures
%%% of entry also the value of entry for the period t+1 should be
%%% considered

%%
checkpoint_h_start = 1;
checkpoint_k_start = 1;
if use_checkpoint
    try
        load(checkpoint_file);
        fprintf("Loaded MIT checkpoint %s; resuming at h=%d, k=%d\n",checkpoint_file,checkpoint_h_start,checkpoint_k_start);
    catch
        fprintf("No MIT checkpoint found at %s; starting from scratch\n",checkpoint_file);
    end
end

for h=checkpoint_h_start:1:max_iter_measure

    if h==checkpoint_h_start && checkpoint_k_start>1
        k_first = checkpoint_k_start;
    else
        k_first = 1;
        p_conv_o_all_prev   = p_conv_o_all + p_conv_o_all_prev.*(1-conv_decrease_all);
        converion_o_all_pre = converion_o_all + converion_o_all_pre.*(1-conv_decrease_all);
    end

    p_conv_o_all_prev(p_conv_o_all_prev>1)      = 1;
    converion_o_all_pre(converion_o_all_pre>1)  = 1;
    p_conv_o_all_prev(p_conv_o_all_prev<0)      = 0;
    converion_o_all_pre(converion_o_all_pre<0)  = 0;

    measure_adj_n = (h<100)*measure_adj_n + 0.1*(h<200&&h>=100) + 0.05*(h>=200);
    measure_adj_o = (h<100)*measure_adj_o + 0.1*(h<200&&h>=100) + 0.05*(h>=200);

    for k=k_first:1:max_iter_price

        output_adjsut   = 0.1/(max(e_n_eps,e_o_eps))*(k<50) ...
           + 1.5/(max(e_n_eps,e_o_eps))*(k>=50); %%% max var in output prices
        v_of_new    = final_val2;
        v_of_old    = final_val1;

      
        

        dist_o_all_prev = dist_o_all;
        dist_n_all_prev = dist_n_all; %%%%% this is used for debuggin it
                        %%%% should be erased afterwards with it's related
                        %%%% codes
        
        % P_E_vec_expan = [p_E_vec final_p_E];
        % p_e_n_vec_exp = [p_e_n_vec fin_p_e_n];
        % p_e_o_vec_exp = [p_e_o_vec fin_p_e_o];

        price_ratio_n = p_E_vec./p_e_n_vec;
        price_ratio_o = p_E_vec./p_e_o_vec;

        for it=1:trans_t
            a_grid_new = a_grid_n_all(:,it);
            a_eff_n = a_grid_new .* max(1 - a_grow .* age_g', 0);
            [eff_temp,cap_temp,pi_temp] = static_solver(a_eff_n,...
                p_E_vec(it).*P_E_grid_norm,p_e_n_vec(it).*p_e_n_grid_norm,...
                alpha,fco_n,1./a_grid_new(:));
            eff_n_cache(:,:,it) = single(eff_temp);
            cap_n_cache(:,:,it) = single(cap_temp);
            pi_n_cache(:,:,it)  = single(pi_temp);

            a_eff_o = (a_grid_old./tech_dist_vec(it))' .* max(1 - a_grow .* age_g', 0);
            [eff_temp,cap_temp,pi_temp] = static_solver(a_eff_o,...
                p_E_vec(it).*P_E_grid_norm,p_e_o_vec(it).*p_e_o_grid_norm,...
                alpha,fco_o,1./a_grid_old(:));
            eff_o_cache(:,:,it) = single(eff_temp);
            cap_o_cache(:,:,it) = single(cap_temp);
            pi_o_cache(:,:,it)  = single(pi_temp);
        end

        for i1=trans_t:-1:1

            a_grid_new  = a_grid_n_all(:,i1);
            temp_index_grid_exp = temp_index_grid_exp_all{i1};
            rat_of_tran_exp     = rat_of_tran_exp_all{i1};


            v_p_n                 = v_of_new';
            v_p_n(:,1:age_num-1)  = v_p_n(:,2:age_num);
            v_p_n(:,age_num)      = 0;            %%% setting the
                                                %%% value of those who don't adopt
                                                %%% at the highest age to zero; it
                                                %%% should also be noted that if a
                                                %%% firm is not adopting, in the
                                                %%% next period it would get the
                                                %%% value of v(age+1,a_i)
        
        
        
            v_p_n_vec     = (v_p_n(:));

            prob_matrix     = prob_mat_n_all{i1};
            v_p_n_vec       = v_p_n_vec(temp_index_grid_exp).*(1-rat_of_tran_exp)+...
                v_p_n_vec(temp_index_grid_exp-1).*(rat_of_tran_exp);

            pi_contemp_new = double(pi_n_cache(:,:,i1))';
        
%             pi_contemp_neg_new  = pi_contemp_new<0;
%             pi_contemp_new(pi_contemp_neg_new) = 0;
    
            
            c_a_new_temp    = c_a_new_vec(1:i1);
            c_a_new_temp    = [flip(c_a_new_temp) ones(1,age_num-i1)*c_a_new_vec(1)];
            c_a_new_temp    = kron(c_a_new_temp',ones(a_num_g^2,1));
            %%% those who are old and have not updated should pay their
            %%% respective cost of adoption (it matters for solar
            %%% transition)
            
            v_p_n_expand  = kron(v_p_n_vec,ones(a_num_g,1));
            v_n_adopt     = [kron(ones(age_reduc,a_num_g),v_of_new(1,:));...
                kron(ones(1,a_num_g),v_of_new(1:end-age_reduc,:))];
            v_n_adopt_p   = v_n_adopt';
            v_n_adopt_vec = v_n_adopt_p(:);

            temp_smoother = (1-exp(-(v_n_adopt_vec-c_a_new_temp-v_p_n_expand)*exit_sm));
            temp_smoother(isinf(temp_smoother)) = -1000;
        
            v_n_best      = v_p_n_expand + (v_n_adopt_vec-c_a_new_temp-v_p_n_expand)...
                .*(v_n_adopt_vec-c_a_new_temp>v_p_n_expand).* ...
                temp_smoother;

            choice_vec_n  = (v_n_adopt_vec-c_a_new_temp>v_p_n_expand).* ...
                temp_smoother;

            %%% here I've also smoothed the adoption policy, this is because
            %%% the discrete changes in adoption decision makes small
            %%% perturbation in the distribution which hinders market
            %%% clearig
        
            v_n_best_resh = (reshape(v_n_best,a_num_g,age_num*a_num_g))';
        
             
            policy_choice_n = (reshape(choice_vec_n,a_num_g,age_num*a_num_g))';
        
            
        
            v_new_n       = sum(v_n_best_resh.*repmat(prob_matrix,age_num,1),2);
            v_new_resh_n  = (reshape(v_new_n,a_num_g,age_num))';
            %%% those who get non-positive npv in the upcoming periods should exit
            v_n_neg           = v_new_resh_n<0;
            exiting_firm_n    = v_n_neg'+(1-v_n_neg').*(exp(-v_new_resh_n'*10^exit_sm));
            exiting_firm_n(isnan(exiting_firm_n)) = 1;

            v_new_resh_n  = pi_contemp_new + beta*(1-exo_exit)*v_new_resh_n;

            
            exit_vec_n        = exiting_firm_n(:);
            policy_choice_n   = (1-exit_vec_n).*policy_choice_n;

            v_new_resh_n(v_n_neg) = 0;
        
%             error       = max(abs(v_of_new-v_new_resh_n),[],"all");
        
        if (sum(isnan(exit_vec_n))>0)
            fprintf("there is nan\n at %2.1f",i1);
            break;
        end
            v_of_new = v_new_resh_n;

            v_new_resh_n_all(:,:,i1)    = v_new_resh_n;
            policy_choice_n_all(:,:,i1) = policy_choice_n;
            exit_vec_n_all(:,i1)        = exit_vec_n;

            trans_prob_n_all(:,i1)      = sum(policy_choice_n.*repmat(prob_matrix,age_num,1),2);
        end
        fprintf("MIT value function of new is done\n");


        v_new_re_temp = final_val2;

        for i2=trans_t:-1:1


  
            prob_matrix     = prob_matrix_old;
           
            %*lag_grow_compensate(i2)
            % pi_contemp_old      = ((a_grid)/tech_dist_vec(i2)...
            %     .*(alpha*p_E_vec(i2)/p_e_o_vec(i2))^alpha.*(1/(1+a_grow)).^age_g)...
            %     .^(1/(1-alpha))*(1-alpha);

            pi_contemp_old = double(pi_o_cache(:,:,i2))';
            
%             pi_contemp_neg_old  = pi_contemp_old<0;
%             pi_contemp_old(pi_contemp_neg_old) = 0;

            v_p_o = v_of_old';
            v_p_o(:,1:age_num-1)  = v_p_o(:,2:age_num);
            v_p_o(:,age_num)      = 0;            %%% setting the
                                                %%% value of those who don't adopt
                                                %%% at the highest age to zero; it
                                                %%% should also be noted that if a
                                                %%% firm is not adopting, in the
                                                %%% next period it would get the
                                                %%% value of v(age+1,a_i)
        
        
        
            v_p_o_vec     = (v_p_o(:));
            v_p_o_expand  = kron(v_p_o_vec,ones(a_num_g,1));
            v_o_adopt     = [kron(ones(age_reduc,a_num_g),v_of_old(1,:));...
                kron(ones(1,a_num_g),v_of_old(1:end-age_reduc,:))];
            v_o_adopt_p   = v_o_adopt';
            v_o_adopt_vec = v_o_adopt_p(:);
            temp_smoother = (1-exp(-(v_o_adopt_vec-c_of_a*(1)-v_p_o_expand)*exit_sm));
            temp_smoother(isinf(temp_smoother)) = -1000;
        
            v_o_best      = v_p_o_expand + (v_o_adopt_vec-c_of_a*(1)-v_p_o_expand)...
                .*(v_o_adopt_vec-c_of_a*(1)>v_p_o_expand).* ...
                temp_smoother;
            choice_vec_o  = (v_o_adopt_vec-c_of_a*(1)>v_p_o_expand).* ...
                temp_smoother;
            %%% here I've also smoothe the adoption policy, this is because
            %%% the discrete changes in adoption decision makes small
            %%% perturbation in the distribution which hinders market
            %%% clearig

            %%%% The transition has a low pace, I'm adding delibrate
            %%%% converstion from one tech to another. Here the conversion
            %%%% is such that a generator with old tech would go to two
            %%%% closest new tech states when adjusted for it's decay

            tech_con_exp      = tech_con_exp_all(:,i2);
            ratio_tech_conver = ratio_tech_conv_all(:,i2);

        
            v_o_best_resh = (reshape(v_o_best,a_num_g,age_num*a_num_g))';

            
            v_new_re_temp = v_new_re_temp';
            
            v_new_re_temp(:,1:age_num-1) = v_new_re_temp(:,2:age_num);
            v_new_re_temp(:,age_num)     = 0;

            v_new_temp    = v_new_re_temp(:);
%             v_o_con_vec   = v_o_convert';
%             v_o_con_vec   = v_o_con_vec(:);
        
             
            policy_choice_o = (reshape(choice_vec_o,a_num_g,age_num*a_num_g))';

%             v_o_best_resh   = max(v_o_best_resh,v_o_convert);
%             converion_old   = v_o_best_resh == v_o_convert;
           
        
            v_new_o       = sum(v_o_best_resh.*repmat(prob_matrix,age_num,1),2);

%             v_o_convert   = conv_rate*(v_new_temp(tech_con_exp).*repmat(ratio_tech_conver,age_num,1)...
%                 + v_new_temp(tech_con_exp-1).*(1-repmat(ratio_tech_conver,age_num,1))-c_conver)...
%                 +(1-conv_rate)*v_new_o;

            v_o_convert   = (v_new_temp(tech_con_exp).*ratio_tech_conver...
                + v_new_temp(tech_con_exp-1).*(1-ratio_tech_conver)-c_conver);


            v_new_o(v_new_o==0) = 10^-9;
            converion_old = conv_rate*(v_new_o<v_o_convert).*(v_o_convert-v_new_o)./v_new_o;
            conv_decrease = conv_rate*(v_new_o>v_o_convert).*(-v_o_convert+v_new_o)./v_new_o;
            
            conv_decrease(conv_decrease>1) = 1;

            conv_decrease_all(:,i2) = conv_decrease;
            converion_o_all(:,i2)   = converion_old;
            converion_old_temp      = converion_o_all_pre(:,i2);
            
            v_new_o       = (1-converion_old_temp).*v_new_o + converion_old_temp.*v_o_convert;

            v_new_resh_o  = (reshape(v_new_o,a_num_g,age_num))';
            %%% those who get non-positive npv in the upcoming periods should exit
            v_o_neg           = v_new_resh_o<0; 
            exiting_firm_o    = v_o_neg'+(1-v_o_neg').*(exp(-v_new_resh_o'*10^exit_sm));
            exiting_firm_o(isnan(exiting_firm_o)) = 1;

            v_new_resh_o  = pi_contemp_old + beta*(1-exo_exit)*v_new_resh_o;

            
            exit_vec_o        = exiting_firm_o(:);
            policy_choice_o   = (1-exit_vec_o).*(1-converion_old_temp).*policy_choice_o;
            p_conversion_o    = sum(converion_old.*(1-exit_vec_o).*repmat(prob_matrix,age_num,1),2);

            v_new_resh_o(v_o_neg) = 0;

            v_new_re_temp     = v_new_resh_n_all(:,:,i2);
        
%             error       = max(abs(v_of_old-v_new_resh_o),[],"all");
        if sum(isnan(v_new_resh_o),"all")>1
            fprintf("there is nan\n at %2.1f",i2);
            break;
            
        end
        
            v_of_old = v_new_resh_o;
            
            v_new_resh_o_all(:,:,i2)    = v_new_resh_o;
            policy_choice_o_all(:,:,i2) = policy_choice_o;
            exit_vec_o_all(:,i2)        = exit_vec_o;

            trans_prob_o_all(:,i2)      = sum(policy_choice_o.*repmat(prob_matrix,age_num,1),2);
            p_conv_o_all(:,i2)          = p_conversion_o;
        end
        
        fprintf("MIT value function of old is done\n");
        %%
       

%         m_of_firms_old  = sum(init_dist,'all');
        m_of_firms_new  = 0;
        dist_n          = init_dist_n;
        dist_o          = init_dist_o;
        dist_o_prev     = init_dist_o;
        dist_n_prev     = init_dist_n;   %%%%% this is used for debuggin it
                        %%%% should be erased afterwards with it's related
                        %%%% codes

        cap_old         = ones(1,trans_t);
        cap_new         = ones(1,trans_t);
        cap_n_temp      = ones(1,trans_t);
        cap_o_temp      = ones(1,trans_t);

        
        dist_ent_old     = zeros(1,age_num*a_num_g);
        dist_ent_old(1:a_num_g) = a_prob_old;
        


        
        for j=1:1:trans_t
             %%% Here I derive the transition matrix; first those who don't adopt go to
            %%% the same technology state with a higher age, those who adopt go the
            %%% technology they adopt with the age zero meaning we have:
%             tic
            dist_ent_new     = zeros(1,age_num*a_num_g);
            dist_ent_new(1:a_num_g) = a_prob_n_all(:,j);

            prob_matrix     = prob_mat_n_all{j};
            
            temp_index_grid_exp = temp_index_grid_exp_all{j};
            rat_of_tran_exp     = rat_of_tran_exp_all{j};

            eff_n_vec       = double(eff_n_cache(:,:,j));
            cap_contemp_new = double(cap_n_cache(:,:,j));
            
            
            exit_vec_n                      = exit_vec_n_all(:,j);
            policy_choice_n                 = policy_choice_n_all(:,:,j);
            
            temp_n                          = exit_vec_n(1:(age_num-1)*a_num_g,1);
    
            temp_matrix_n                       = policy_choice_n.*repmat(prob_matrix,age_num,1)...
                .*(1-exit_vec_n)*(1-exo_exit);
            prob_of_naot_n                      = sum((1-policy_choice_n).*repmat(prob_matrix,age_num,1),2);
            p_of_naot_besideold_n               = ones((age_num-1)*a_num_g,1)...
                .*prob_of_naot_n(1:(age_num-1)*a_num_g)*(1-exo_exit);
            stay_alive_besideold_n              = (ones((age_num-1)*a_num_g,1)-temp_n);

            values_of_naot      = [p_of_naot_besideold_n.*stay_alive_besideold_n.*(1-rat_of_tran_exp(1:(age_num-1)*a_num_g));...
                p_of_naot_besideold_n.*stay_alive_besideold_n.*(rat_of_tran_exp(1:(age_num-1)*a_num_g))]';

            state_if_naot_n_y = state_if_naot_n_y_all{j};
            state_if_naot_n_x = state_if_naot_n_x_all{j};
            values_of_adopt   = temp_matrix_n(temp_address);
            trans_matrix_n    = sparse([state_if_adopt_y,state_if_naot_n_y],[state_if_adopt_x,state_if_naot_n_x]...
                ,[values_of_adopt,values_of_naot],a_num_g*age_num,a_num_g*age_num);

            %%% also those who are at the last period would die if they don't adopt to
            %%% any technology and a new firm would enter with a random technology
            %%% meaning for those states with the highest age the transition would be
            %%% randomly to age 0 and tech in [0, a_max]
            
            trans_matrix_n((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob_n_all(:,j)',a_num_g,1).*(1-exit_vec_n((age_num-1)*a_num_g+1:(age_num)*a_num_g));
%             trans_matrix_n = sparse(trans_matrix_n);

            p_conversion_o = p_conv_o_all_prev(:,j);
            
            dist_new_n    = dist_n *trans_matrix_n ;

            %%%% we can not kick out people and we can just observer
            %%%% whether it's benefitial to enter or not, thus I have to
            %%%% adjust how the transition works

            %%%% Here in addition we have those who convert form old tech
            %%%% to new tech. They are transistion based on a matrix and we
            %%%% have:

            tech_con_exp        = (tech_con_exp_all(:,j));
            ratio_tech_conver   = (ratio_tech_conv_all(:,j));
            conv_address_x1     = conv_address_x1_all{j};
            conv_address_x2     = conv_address_x2_all{j};
            conv_address_y1     = conv_address_y1_all{j};
            conv_address_y2     = conv_address_y2_all{j};

            conv_matrix         = sparse([conv_address_y1;conv_address_y2],...
                [conv_address_x1;conv_address_x2],...
                [ratio_tech_conver.*p_conversion_o;(1-ratio_tech_conver).*p_conversion_o],...
                a_num_g*age_num,a_num_g*age_num);
            
            cap_new(j)    = dist_n * cap_contemp_new(:);
            input_use_n   = dist_n * eff_n_vec(:);
            
            p_e_n_vec(j)  = (input_use_n/(e0_n_vec(j)/tech_dist_vec(j).^(1/(1-alpha)))*...
                (input_use_n/input_all_n(j))^penalty_n).^(1/e_n_eps);
            kk      = k*(k<10) + 10*(k>=10); 
            input_adjsut_n_all(j)   = i_a_param*input_adjsut/(ceil(kk/10))...
                *(-p_e_n_vec_pre(j)+p_e_n_vec(j));
            if median(abs(input_adjsut_n_all))*10<abs(input_adjsut_n_all(j))
                input_adjsut_n_all(j)   = (median(abs(input_adjsut_n_all))*10)*...
                    sign(input_adjsut_n_all(j));
            end
            p_e_n_vec(j)  = p_e_n_vec_pre(j) + input_adjsut_n_all(j);
            exit_n(j)     = sum(dist_n-dist_new_n);
            dist_conv     = dist_o_prev*conv_matrix;
            conv_entry(j) = sum(dist_conv);
            dist_new_n    = dist_new_n + m_of_entry_n(j)*dist_ent_new +...
                dist_conv;
 
            dist_n        = dist_new_n;

            dist_n_all(j,:)  = dist_n;
            input_all_n(j+1) = input_use_n;

            cap_n_temp(j) = dist_n_prev*cap_contemp_new(:);

            
            
            measure_vec_n(j) = sum(dist_n);

            

            dist_o_prev      = dist_o_all(j,:);
            dist_n_prev      = dist_n_all_prev(j,:);

            if sum(isnan(dist_n),"all")>1
                fprintf("there is nan\n at %2.1f",j);
                break;
                
            end
%         toc
        end
        
        fprintf("MIT distribution of new is found\n");

        dist_o_prev     = init_dist_o;
        for j=1:1:trans_t

            prob_matrix     = prob_matrix_old;

%              tic  

            eff_o_vec       = double(eff_o_cache(:,:,j));
            cap_contemp_old = double(cap_o_cache(:,:,j));

            exit_vec_o                      = exit_vec_o_all(:,j);
            policy_choice_o                 = policy_choice_o_all(:,:,j);

            temp_o                          = exit_vec_o(1:(age_num-1)*a_num_g,1);
    
            temp_matrix_o                       = policy_choice_o.*repmat(prob_matrix,age_num,1)...
                .*(1-exit_vec_o)*(1-exo_exit);
            prob_of_naot_o                      = sum((1-policy_choice_o).*repmat(prob_matrix,age_num,1),2);
            p_of_naot_besideold_o               = ones((age_num-1)*a_num_g,1)...
                .*prob_of_naot_o(1:(age_num-1)*a_num_g)*(1-exo_exit);
            stay_alive_besideold_o              = (ones((age_num-1)*a_num_g,1)-temp_o);
            p_conversion_o                      = p_conv_o_all_prev(:,j);
            
            values_of_adopt_o   = temp_matrix_o(temp_address);
            values_of_naot_o    = (p_of_naot_besideold_o.*stay_alive_besideold_o)';
            trans_matrix_o      = sparse([state_if_adopt_y,state_if_naot_o_y],[state_if_adopt_x,state_if_naot_o_x]...
                ,[values_of_adopt_o,values_of_naot_o],a_num_g*age_num,a_num_g*age_num);
    
            trans_matrix_o((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob_old,a_num_g,1).*(1-exit_vec_o((age_num-1)*a_num_g+1:(age_num)*a_num_g));
%             trans_matrix_o = sparse(trans_matrix_o);
            
            cap_old(j)    = dist_o * cap_contemp_old(:);
            conv_exit(j)  = sum(dist_o.*p_conversion_o');

            input_use_o   = dist_o * eff_o_vec(:);
            
            p_e_o_vec(j)  = (input_use_o/(e0_o/tech_dist_vec(j).^(1/(1-alpha)))*...
                (input_use_o/input_all_o(j))^penalty_o).^(1/e_o_eps);

            kk      = k*(k<10) + 10*(k>=10); 

            input_adjsut_o_all(j)   = i_a_param*input_adjsut/(ceil(kk/10))...
                *(-p_e_o_vec_pre(j)+p_e_o_vec(j));
            if median(abs(input_adjsut_o_all))*10<abs(input_adjsut_o_all(j))
                input_adjsut_o_all(j)   = (median(abs(input_adjsut_o_all))*10)*...
                    sign(input_adjsut_o_all(j));
            end
            % p_e_o_vec(j)  = (dist_o * eff_o_vec(:)/e0_o).^e_o_eps;
            p_e_o_vec(j)  = p_e_o_vec_pre(j)*1+input_adjsut_o_all(j);
            dist_new_o    = (dist_o.*(1-p_conversion_o')) *trans_matrix_o;
            exit_o(j)     = sum(dist_o-dist_new_o);
            dist_new_o    = dist_new_o + m_of_entry_o(j)*dist_ent_old;
            dist_o        = dist_new_o;
            


            cap_o_temp(j) = dist_o_prev*cap_contemp_old(:);
            

            if sum(isnan(dist_o),"all")>1
                fprintf("there is nan\n at %2.1f",j);
                break;
                
            end

            dist_o_all(j,:)  = dist_o;
            measure_vec_o(j) = sum(dist_o);

            dist_o_prev      = dist_o_all_prev(j,:);
            input_all_o(j+1) = input_use_o;
            
%             toc
        
        end

        fprintf("MIT distribution of old is found\n");
        
        total_cap   = cap_old + cap_new;
        tot_cap_lag = zeros(size(total_cap));
        tot_cap_lag(2:end)  = total_cap(1:end-1);
        tot_cap_lag(1)      = d_0/(init_p_E^e_p);
        %(1+diff_gr)*
        suply_price = ((d0_vec./(tech_dist_vec.^(1/(1-alpha))))./(total_cap.*...
            (total_cap./tot_cap_lag).^penalty_p)).^(1/e_p);

        %%% I aim to bound the changes in the supply price to 50% of the
        %%% previous period's supply price otherwise it would make prcie
        %%% loop volatile and convergence would take longer

        % suply_price_lag         = suply_price;
        % suply_price_lag(2:end)  = suply_price(1:end-1);
        % suply_price_lag(1)      = init_p_E;
        suply_price_lag     = p_E_vec;


        sup_price_d = abs((suply_price-suply_price_lag)./suply_price_lag); 
        suply_price((sup_price_d)>0.5) = exp((1-weight_adj_p)*log(suply_price_lag((sup_price_d)>0.5)) + ...
            weight_adj_p.*log(suply_price(abs(sup_price_d)>0.5)));
        
        demand_err  = suply_price - p_E_vec;
        
        if sum(abs(demand_err)>25)>0
            sum(abs(demand_err)>25)
        end

        demand_err(demand_err>25)   = 25;
        demand_err(demand_err<-25)  = -25;
        
        
        p_E_vec     = p_E_vec + 0.1*output_adjsut*demand_err/(min(ceil(k/10),20));

        p_E_vec     = p_E_vec.*(sign(demand_err)==sign(dem_err_pre)) +...
            (p_E_vec+p_E_prev)/2.*(sign(demand_err)~=sign(dem_err_pre));

        if mean(abs(demand_err)<dem_tol | (abs(p_E_prev-p_E_vec)<5*v_tol & k>max_iter_price/5))>0.99 ...
                && mean(abs(input_adjsut_o_all)<5*v_tol)>0.99 ...
                && mean(abs(input_adjsut_n_all)<5*v_tol)>0.99
            fprintf("demand and supply has converged and the prices is ..." + ...
                "%2.4f in %2.1f periods\n",mean(p_E_vec),k);
            break;
        end
        


        p_e_n_vec   = p_e_n_vec.*(sign(price_ratio_n-price_ratio_n_p)==sign(price_ratio_n_p-price_ratio_n_q))...
            + (p_e_n_vec_pre + p_e_n_vec)/2.*(sign(price_ratio_n-price_ratio_n_p)~=sign(price_ratio_n_p-price_ratio_n_q));
        p_e_o_vec   = p_e_o_vec.*(sign(price_ratio_o-price_ratio_o_p)==sign(price_ratio_o_p-price_ratio_o_q))...
            + (p_e_o_vec_pre + p_e_o_vec)/2.*(sign(price_ratio_o-price_ratio_o_p)~=sign(price_ratio_o_p-price_ratio_o_q));
%         [~,loc1] = max(abs(dem_err_pre));
%         [~,loc2] = max(abs(demand_err));
% 
%         if max(abs(p_E_vec-p_E_prev))<0.05*dem_tol &&...
%                 (sign(dem_err_pre(loc1)) ~= demand_err(loc2)) && mod(k,10)==0
%             conv_rate   = conv_rate*0.9;
%         end

            if sum(isnan(dist_o),"all")>1||sum(isnan(dist_n),"all")>1||sum(isnan(v_new_resh_o),"all")>1||sum(isnan(v_new_resh_n),"all")>1
                fprintf("there is nan\n at %2.1f",j);
                break;
                
            end

%         p_E_vec(end) = final_p_E;

        p_E_prev            = p_E_vec;
        dem_err_pre         = demand_err;
        p_e_o_vec_pre       = p_e_o_vec;
        p_e_n_vec_pre       = p_e_n_vec;
        price_ratio_n_q     = price_ratio_n_p;
        price_ratio_o_q     = price_ratio_o_p;
        price_ratio_n_p     = price_ratio_n;
        price_ratio_o_p     = price_ratio_o;

        if use_checkpoint && mod(k,checkpoint_freq)==0
            checkpoint_h_start = h;
            checkpoint_k_start = k + 1;
            save_mit_checkpoint(checkpoint_file,checkpoint_h_start,checkpoint_k_start,...
                p_conv_o_all,p_conv_o_all_prev,converion_o_all,converion_o_all_pre,...
                conv_decrease_all,...
                trans_prob_n_all,trans_prob_o_all,v_new_resh_n_all,v_new_resh_o_all,...
                dist_n_all,dist_o_all,measure_vec_n,measure_vec_o,p_E_vec,p_E_prev,p_e_n_vec,p_e_o_vec,...
                p_e_n_vec_pre,p_e_o_vec_pre,dem_err_pre,demand_err,price_ratio_n_p,...
                price_ratio_o_p,price_ratio_n_q,price_ratio_o_q,input_all_n,input_all_o,...
                input_adjsut_n_all,input_adjsut_o_all,cap_new,cap_old,...
                m_of_entry_n,m_of_entry_o,value_err_n_pre,value_err_o_pre,...
                entry_new_pre,entry_old_pre,c_conver,measure_adj_n,measure_adj_o);
        end
        
    end
    v_new_resh_n_all(:,:,1:end-1)   = v_new_resh_n_all(:,:,2:end);
    v_new_resh_n_all(:,:,end)       = final_val2;
    v_new_resh_o_all(:,:,1:end-1)   = v_new_resh_o_all(:,:,2:end);
    v_new_resh_o_all(:,:,end)       = final_val1;
    value_err_n   = sum(a_prob_n_all.*squeeze(v_new_resh_n_all(1,:,:)),1)'-c_e_new_vec';
    value_err_o   = sum(a_prob_old(:).*squeeze(v_new_resh_o_all(1,:,:)),1)'-c_of_e;
    if mean((abs(value_err_n))<5*dem_tol|(m_of_entry_n)'<v_tol)>=0.95 && ...
            mean((abs(value_err_o))<5*dem_tol|(m_of_entry_o)'<v_tol)>=0.95 && ...
            mean(sum(p_conv_o_all_prev.*conv_decrease_all.*dist_o_all',1)./measure_vec_o<10^-4)==1
        if abs(sum(final_dist_n)-measure_vec_n(end))<dem_tol
            fprintf("entry and exit have converged and E(v_new) and E(v_old) ..." + ...
                "is %2.4f and %2.4f in %2.1f periods \n"...
                ,mean(value_err_n),mean(value_err_o),h);
            break;
        else
            c_conver    = c_conver*(1-(sum(final_dist_n)-measure_vec_n(end))...
                ./max(sum(final_dist_n),measure_vec_n(end)));
        end
    end
%+0.0001*value_err_n'
    if abs(measure_vec_n(end)-sum(final_dist_n))<0.1
        
        m_of_entry_n    = (m_of_entry_n.*(1+0.1*measure_adj_n*value_err_n')).*(abs(value_err_n')>50)...
            + m_of_entry_n.*(1+0.2*measure_adj_n*value_err_n').*(abs(value_err_n')<=50);
        
    else
        m_of_entry_n    = (m_of_entry_n+10^-6)/sum(m_of_entry_n+10^-6)*...
            (sum(m_of_entry_n)+0.1*(sum(final_dist_n)-measure_vec_n(end)));
    end
%+0.0001*value_err_o'
    if abs(measure_vec_o(end)-sum(final_dist_o))<0.1
        
        m_of_entry_o    = (m_of_entry_o.*(1+0.1*measure_adj_o*value_err_o')).*(abs(value_err_o')>50)...
            + m_of_entry_o.*(1+0.2*measure_adj_o*value_err_o').*(abs(value_err_o')<=50);
       
    else
        m_of_entry_o    = (m_of_entry_o+10^-6)/sum(m_of_entry_o+10^-6)*...
            (sum(m_of_entry_o)+0.1*(sum(final_dist_o)-measure_vec_o(end)));
    end
    
    m_of_entry_n    = m_of_entry_n.*(sign(value_err_n')==value_err_n_pre')+...
        (m_of_entry_n+entry_new_pre)/2.*(sign(value_err_n')~=value_err_n_pre');
    m_of_entry_o    = m_of_entry_o.*(sign(value_err_o')==value_err_o_pre')+...
        (m_of_entry_o+entry_old_pre)/2.*(sign(value_err_o')~=value_err_o_pre');

% %     conv_rate       = conv_rate*(1+...
% %         0.2*abs(measure_vec_o(end)-sum(final_dist_o))/max(measure_vec_o(end),sum(final_dist_o)));

    if h==10
        h
    end
    value_err_n_pre = value_err_n;
    value_err_o_pre = value_err_o;
    entry_new_pre   = m_of_entry_n;
    entry_old_pre   = m_of_entry_o;
    

    m_of_entry_n(m_of_entry_n<0) = 0;
    m_of_entry_o(m_of_entry_o<0) = 0;

    measure_vec_n_rec(h,:)  = measure_vec_n;
    measure_vec_o_rec(h,:)  = measure_vec_o;
    price_vec_rec(h,:)      = p_E_vec;
    if use_checkpoint
        checkpoint_h_start = h + 1;
        checkpoint_k_start = 1;
        save_mit_checkpoint(checkpoint_file,checkpoint_h_start,checkpoint_k_start,...
            p_conv_o_all,p_conv_o_all_prev,converion_o_all,converion_o_all_pre,...
            conv_decrease_all,...
            trans_prob_n_all,trans_prob_o_all,v_new_resh_n_all,v_new_resh_o_all,...
            dist_n_all,dist_o_all,measure_vec_n,measure_vec_o,p_E_vec,p_E_prev,p_e_n_vec,p_e_o_vec,...
            p_e_n_vec_pre,p_e_o_vec_pre,dem_err_pre,demand_err,price_ratio_n_p,...
            price_ratio_o_p,price_ratio_n_q,price_ratio_o_q,input_all_n,input_all_o,...
            input_adjsut_n_all,input_adjsut_o_all,cap_new,cap_old,...
            m_of_entry_n,m_of_entry_o,value_err_n_pre,value_err_o_pre,...
            entry_new_pre,entry_old_pre,c_conver,measure_adj_n,measure_adj_o);
    end
end

function out = iif_empty(value, fallback)
if isempty(value)
    out = fallback;
else
    out = value;
end
end

function checkpoint_file = checkpoint_filename(checkpoint_name)
if isstring(checkpoint_name) || ischar(checkpoint_name)
    checkpoint_file = string(checkpoint_name);
else
    checkpoint_file = "";
end
if strlength(checkpoint_file)>0 && ~endsWith(checkpoint_file,".mat")
    checkpoint_file = checkpoint_file + ".mat";
end
end

function [temp_index_grid_exp_all,rat_of_tran_exp_all,tech_con_exp_all,...
    ratio_tech_conv_all,state_if_adopt_y,state_if_adopt_x,temp_address,...
    state_if_naot_n_y_all,state_if_naot_n_x_all,state_if_naot_o_y,...
    state_if_naot_o_x,conv_address_y1_all,conv_address_y2_all,...
    conv_address_x1_all,conv_address_x2_all] = precompute_mit_mappings(...
    a_grid_n_all,a_grid_old,age_num,a_num_g,age_reduc,trans_t)

state_num = age_num*a_num_g;
age_offset = kron((0:age_num-1)',a_num_g*ones(a_num_g,1));
temp_index_grid_exp_all = cell(trans_t,1);
rat_of_tran_exp_all = cell(trans_t,1);
state_if_naot_n_y_all = cell(trans_t,1);
state_if_naot_n_x_all = cell(trans_t,1);
conv_address_y1_all = cell(trans_t,1);
conv_address_y2_all = cell(trans_t,1);
conv_address_x1_all = cell(trans_t,1);
conv_address_x2_all = cell(trans_t,1);
tech_con_exp_all = zeros(state_num,trans_t);
ratio_tech_conv_all = zeros(state_num,trans_t);

for t=1:trans_t
    a_grid_new = a_grid_n_all(:,t);
    if t<trans_t
        a_grid_next = a_grid_n_all(:,t+1);
    else
        a_grid_next = a_grid_n_all(:,t);
    end

    index_cell = arrayfun(@(x) find(x<=a_grid_next,1,'first'),...
        a_grid_new,'UniformOutput',false);
    grid_index = cellfun(@(x) iif_empty(x,a_num_g),index_cell);
    grid_index = min(max(grid_index,2),a_num_g);
    grid_ratio = (a_grid_next(grid_index)-a_grid_new)./...
        (a_grid_next(grid_index)-a_grid_next(grid_index-1));
    grid_ratio = min(max(grid_ratio,0),1);
    grid_index_exp = repmat(grid_index,age_num,1)+age_offset;
    grid_ratio_exp = repmat(grid_ratio,age_num,1);
    temp_index_grid_exp_all{t} = grid_index_exp;
    rat_of_tran_exp_all{t} = grid_ratio_exp;

    active_state_num = (age_num-1)*a_num_g;
    state_if_naot_n = [(1:active_state_num)+age_num*a_num_g^2+...
        (grid_index_exp(1:active_state_num)'-1)*state_num,...
        (1:active_state_num)+age_num*a_num_g^2+...
        (grid_index_exp(1:active_state_num)'-2)*state_num];
    [state_if_naot_n_y_all{t},state_if_naot_n_x_all{t}] = ...
        sparse_subscripts(state_if_naot_n,state_num);

    a_grid_convert = a_grid_next;
    conv_cell = arrayfun(@(x) find(x<=a_grid_convert,1,'first'),...
        a_grid_old','UniformOutput',false);
    tech_conver_h = cellfun(@(x) iif_empty(x,a_num_g),conv_cell);
    tech_conver_h = min(max(tech_conver_h,2),a_num_g);
    ratio_tech_conver = (a_grid_old'-a_grid_convert(tech_conver_h-1))./...
        (a_grid_convert(tech_conver_h)-a_grid_convert(tech_conver_h-1));
    ratio_tech_conver = min(max(ratio_tech_conver,0),1);
    tech_con_exp = repmat(tech_conver_h,age_num,1)+age_offset;
    ratio_tech_conv = repmat(ratio_tech_conver,age_num,1);
    tech_con_exp_all(:,t) = tech_con_exp;
    ratio_tech_conv_all(:,t) = ratio_tech_conv;

    state_sequence = (1:state_num)';
    conv_state_1 = (tech_con_exp-1)*state_num+state_sequence;
    conv_state_2 = (tech_con_exp-2)*state_num+state_sequence;
    [conv_address_y1_all{t},conv_address_x1_all{t}] = ...
        sparse_subscripts(conv_state_1,state_num);
    [conv_address_y2_all{t},conv_address_x2_all{t}] = ...
        sparse_subscripts(conv_state_2,state_num);
end

mapping_num = a_num_g*age_num*a_num_g;
state_if_adopt = zeros(1,mapping_num);
first_mapping_num = age_reduc*a_num_g^2;
state_if_adopt(1:first_mapping_num) = ...
    repmat(1:age_reduc*a_num_g,1,a_num_g)+...
    kron(0:a_num_g-1,state_num*ones(1,age_reduc*a_num_g));
if age_reduc<age_num
    state_if_adopt(first_mapping_num+1:end) = ...
        kron(age_reduc*a_num_g+(0:age_num-age_reduc-1)*a_num_g,ones(1,a_num_g^2))+...
        repmat(1:a_num_g,1,(age_num-age_reduc)*a_num_g)+...
        kron(0:a_num_g*(age_num-age_reduc)-1,state_num*ones(1,a_num_g));
end
[state_if_adopt_y,state_if_adopt_x] = sparse_subscripts(state_if_adopt,state_num);

temp_address = zeros(1,mapping_num);
temp_address(1:first_mapping_num) = ...
    repmat(1:age_reduc*a_num_g,1,a_num_g)+...
    kron(0:a_num_g-1,state_num*ones(1,age_reduc*a_num_g));
if age_reduc<age_num
    temp_address(first_mapping_num+1:end) = ...
        kron(age_reduc*a_num_g+(0:age_num-age_reduc-1)*a_num_g,ones(1,a_num_g^2))+...
        repmat(1:a_num_g,1,(age_num-age_reduc)*a_num_g)+...
        repmat(kron(0:a_num_g-1,state_num*ones(1,a_num_g)),1,age_num-age_reduc);
end

state_if_naot_o = kron(1:age_num-1,ones(1,a_num_g))*age_num*a_num_g^2+...
    (1:(age_num-1)*a_num_g)+...
    kron(ones(1,age_num-1),0:a_num_g-1)*state_num;
[state_if_naot_o_y,state_if_naot_o_x] = sparse_subscripts(state_if_naot_o,state_num);
end

function [row_index,column_index] = sparse_subscripts(linear_state,state_num)
row_index = mod(linear_state,state_num);
row_index(row_index<1) = state_num;
column_index = ceil((linear_state-0.1)/state_num);
end

function save_mit_checkpoint(checkpoint_file,checkpoint_h_start,checkpoint_k_start,...
    p_conv_o_all,p_conv_o_all_prev,converion_o_all,converion_o_all_pre,...
    conv_decrease_all,...
    trans_prob_n_all,trans_prob_o_all,v_new_resh_n_all,v_new_resh_o_all,...
    dist_n_all,dist_o_all,measure_vec_n,measure_vec_o,p_E_vec,p_E_prev,p_e_n_vec,p_e_o_vec,...
    p_e_n_vec_pre,p_e_o_vec_pre,dem_err_pre,demand_err,price_ratio_n_p,...
    price_ratio_o_p,price_ratio_n_q,price_ratio_o_q,input_all_n,input_all_o,...
    input_adjsut_n_all,input_adjsut_o_all,cap_new,cap_old,...
    m_of_entry_n,m_of_entry_o,value_err_n_pre,value_err_o_pre,...
    entry_new_pre,entry_old_pre,c_conver,measure_adj_n,measure_adj_o)

save(checkpoint_file,"checkpoint_h_start","checkpoint_k_start",...
    "p_conv_o_all","p_conv_o_all_prev","converion_o_all","converion_o_all_pre",...
    "conv_decrease_all",...
    "trans_prob_n_all","trans_prob_o_all","v_new_resh_n_all","v_new_resh_o_all",...
    "dist_n_all","dist_o_all","measure_vec_n","measure_vec_o","p_E_vec","p_E_prev","p_e_n_vec","p_e_o_vec",...
    "p_e_n_vec_pre","p_e_o_vec_pre","dem_err_pre","demand_err","price_ratio_n_p",...
    "price_ratio_o_p","price_ratio_n_q","price_ratio_o_q","input_all_n","input_all_o",...
    "input_adjsut_n_all","input_adjsut_o_all","cap_new","cap_old",...
    "m_of_entry_n","m_of_entry_o","value_err_n_pre","value_err_o_pre",...
    "entry_new_pre","entry_old_pre","c_conver","measure_adj_n","measure_adj_o");
end
end