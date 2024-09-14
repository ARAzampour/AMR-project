function [trans_prob_o_all,v_new_resh_o_all,dist_o_all,measure_vec_o,p_e_o_vec,input_all_o,...
    trans_prob_n_all,v_new_resh_n_all,dist_n_all,measure_vec_n,p_e_n_vec,input_all_n,...
    age_g,a_grid,a_prob,p_E_vec,cap_old,cap_new] =...
    MIT_transition_AC(a_grow,alpha,~,beta,c_of_a,c_a_new_vec,mu,sigma,a_num_g,age_num,max_iter,...
    v_tol,~,fco_o,fco_n,e_p,d_0,c_of_e,c_e_new_vec,dem_tol,init_dist_n,init_dist_o,final_val1,final_val2,...
    diff_gr,diff_gr_t,init_p_E,final_p_E,trans_t,final_dist_n,final_dist_o,...
    e0_n_vec,e0_o,e_n_eps,e_o_eps,diff_gr_cons,fin_p_e_n,init_p_e_n,...
    fin_p_e_o,init_p_e_o,rho,age_reduc,c_conver,conv_rate,exit_n_final,exit_o_final,...
    exo_exit,e_max,gamma,init_input_n,init_input_o,penalty_o,penalty_n,penalty_p,d0_gr)

%%% conv_rate is used to make the conversion slower, the reason is that
%%% suddent conversion creates swinging features
x = norminv(linspace(0,1,a_num_g+2),mu,sigma); %%% looking at the entrants, 
                            %%% distribution we have now decided to use
                            %%% normal distribution 2024-09-11
% a_grid  = expinv(1-exp(linspace(log(1),log(0.001),a_num_g)),a_lamb); %%% here
                %%%% I've change the spacing for grid productivity, the
                %%%% reason is that by using the grid the gives equall prob
                %%%% to each grid point we would focus to much on the
                %%%% points that no action would be happening
a_grid  = x(2:a_num_g+1);
a_g_nex = (a_grid)'/(1+diff_gr);
a_cdf   = normcdf(x,mu,sigma);
a_prob  = a_cdf(2:a_num_g+1)-a_cdf(1:a_num_g);

prob_matrix_ss       = auto_corr_prob(a_grid,a_prob,rho);
prob_matrix_tr      = auto_corr_prob_transition(a_grid,a_prob,rho,diff_gr);

max_iter_price      = floor(max_iter/10);
max_iter_measure    = max_iter_price*10;
 
age_g   = (linspace(0,age_num-1,age_num))';
exit_sm = 2;

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
    (sum(final_dist_o,'all')-sum(init_dist_o,'all')))/trans_t...
    +exit_n_final/sum(final_dist_n,'all')*sum(init_dist_n+final_dist_n,'all')/2*1.5);
m_of_entry_o        = 1+exp(linspace(0,-10,trans_t));
m_of_entry_o        = trans_t*m_of_entry_o/(sum(m_of_entry_o))*...
    ((sum(final_dist_o,'all')-sum(init_dist_o,'all')-...
    (sum(final_dist_n,'all')-sum(init_dist_n,'all')))/trans_t...
    +exit_o_final/sum(final_dist_o,'all')*sum(init_dist_o+final_dist_o,'all')/2*1.5);

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
tech_con_exp_all    = zeros(age_num*a_num_g,trans_t);
ratio_tech_conv_all = zeros(age_num*a_num_g,trans_t);


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


%%% this part is used to model the decay of the new generators in the
%%% period of growth in new generators' productivity, this is beacuse the
%%% new ones that have not updated are lagging behind
[~,temp_index_grid] = max(a_g_nex<a_grid,[],2);
if temp_index_grid(end) == 1
    temp_index_grid(end) = a_num_g;
end
temp_index_grid(temp_index_grid==1)         = 2;
ratio_of_transition = (a_grid(temp_index_grid)'-a_g_nex)./(a_grid(temp_index_grid)'-a_grid(temp_index_grid-1)');
ratio_of_transition(ratio_of_transition>1)  = 1;
temp_index_grid_exp = repmat(temp_index_grid,age_num,1)+kron((0:1:age_num-1)',a_num_g*ones(a_num_g,1));
rat_of_tran_exp     = repmat(ratio_of_transition,age_num,1);


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
i_a_param           = 0.4;

%%% The adjustment in the price of electricity will be bounded and weight_adj_p
%%% will determine the amount of adjustment when bound is reached
weight_adj_p        = 0.2;

%%%%%% Important note %%%%%%%%
%%% In the transition first the output (and its decision) happens and then
%%% the decisions on adoption (conversion) and exit are made. This measn
%%% that in the period t of the transtion a generator would make it
%%% decsions for the period t+1 and therefore in the adjustment of measures
%%% of entry also the value of entry for the period t+1 should be
%%% considered

%%
for h=1:1:max_iter_measure

    p_conv_o_all_prev   = p_conv_o_all + p_conv_o_all_prev.*(1-conv_decrease_all);
    converion_o_all_pre = converion_o_all + converion_o_all_pre.*(1-conv_decrease_all);

    p_conv_o_all_prev(p_conv_o_all_prev>1)      = 1;
    converion_o_all_pre(converion_o_all_pre>1)  = 1;
    p_conv_o_all_prev(p_conv_o_all_prev<0)      = 0;
    converion_o_all_pre(converion_o_all_pre<0)  = 0;

    measure_adj_n = (h<100)*measure_adj_n + 0.1*(h<200&&h>=100) + 0.05*(h>=200);
    measure_adj_o = (h<100)*measure_adj_o + 0.1*(h<200&&h>=100) + 0.05*(h>=200);

    for k=1:1:max_iter_price

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

        for i1=trans_t:-1:1

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
            if i1>diff_gr_t
                prob_matrix     = prob_matrix_ss;
                
            else
                prob_matrix     = prob_matrix_tr;
                v_p_n_vec       = v_p_n_vec(temp_index_grid_exp).*(1-rat_of_tran_exp)+...
                    v_p_n_vec(temp_index_grid_exp-1).*(rat_of_tran_exp);
            end

            % pi_contemp_new      = ((a_grid).*(alpha*p_E_vec(i1)/p_e_n_vec(i1))^alpha.*(1/(1+a_grow)).^age_g)...
            %     .^(1/(1-alpha))*(1-alpha);

            eff_n_vec           = (((a_grid).*alpha*p_E_vec(i1)/p_e_n_vec(i1)...
                .*(((a_grid).^gamma)./(1+a_grow)).^age_g).^(1/(1-alpha)))';
            eff_n_vec           = min(eff_n_vec,e_max*(a_grid)'); %%% e_max is add to cap
                        %%% the amount of input a generator can use

            cap_contemp_new     = (a_grid)'.*(((a_grid).^gamma)./(1+a_grow)).^age_g'.*(eff_n_vec.^alpha);
        
            pi_contemp_new      = p_E_vec(i1).*cap_contemp_new'-p_e_n_vec(i1).*eff_n_vec'- fco_n;
        
%             pi_contemp_neg_new  = pi_contemp_new<0;
%             pi_contemp_new(pi_contemp_neg_new) = 0;
    
            
            c_a_new_temp    = c_a_new_vec(1:i1);
            c_a_new_temp    = [flip(c_a_new_temp) ones(1,age_num-i1)*c_a_new_vec(1)];
            c_a_new_temp    = kron(c_a_new_temp',ones(a_num_g^2,1));
            %%% those whor are old and have not updated should pay their
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


  
            prob_matrix     = prob_matrix_ss;
           
            %*lag_grow_compensate(i2)
            % pi_contemp_old      = ((a_grid)/tech_dist_vec(i2)...
            %     .*(alpha*p_E_vec(i2)/p_e_o_vec(i2))^alpha.*(1/(1+a_grow)).^age_g)...
            %     .^(1/(1-alpha))*(1-alpha);

            eff_o_vec           = (((a_grid)/tech_dist_vec(i2).*alpha*p_E_vec(i2)...
                /p_e_o_vec(i2).*(((a_grid).^gamma)./(1+a_grow)).^age_g)...
            .^(1/(1-alpha)))';
            eff_o_vec           = min(eff_o_vec,e_max*(a_grid)'); %%% e_max is add to cap
                        %%% the amount of input a generator can use

            cap_contemp_old     = (a_grid')/tech_dist_vec(i2)...
                .*(((a_grid).^gamma)./(1+a_grow)).^age_g'.*(eff_o_vec.^alpha);

            pi_contemp_old      = p_E_vec(i2).*cap_contemp_old'-p_e_o_vec(i2).*eff_o_vec'- fco_o;
            
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

            [~,tech_conver_h] = max((a_grid)'/tech_dist_vec(i2)<(a_grid),[],2);
            if tech_conver_h(end)==1
                tech_conver_h(end) = a_num_g;
            end
            tech_conver_h(tech_conver_h==1) = 2;
            ratio_tech_conver = ((a_grid)'/tech_dist_vec(i2)-(a_grid(tech_conver_h-1))')...
                ./((a_grid(tech_conver_h))'-(a_grid(tech_conver_h-1))');
            ratio_tech_conver(ratio_tech_conver<0) = 0;

        
            v_o_best_resh = (reshape(v_o_best,a_num_g,age_num*a_num_g))';

            
            v_new_re_temp = v_new_re_temp';
            
            v_new_re_temp(:,1:age_num-1) = v_new_re_temp(:,2:age_num);
            v_new_re_temp(:,age_num)     = 0;

            v_new_temp    = v_new_re_temp(:);
            tech_con_exp  = repmat(tech_conver_h,age_num,1) + ...
                kron((0:1:age_num-1)',a_num_g*ones(a_num_g,1));
            
%             v_o_con_vec   = v_o_convert';
%             v_o_con_vec   = v_o_con_vec(:);
        
             
            policy_choice_o = (reshape(choice_vec_o,a_num_g,age_num*a_num_g))';

%             v_o_best_resh   = max(v_o_best_resh,v_o_convert);
%             converion_old   = v_o_best_resh == v_o_convert;
           
        
            v_new_o       = sum(v_o_best_resh.*repmat(prob_matrix,age_num,1),2);

%             v_o_convert   = conv_rate*(v_new_temp(tech_con_exp).*repmat(ratio_tech_conver,age_num,1)...
%                 + v_new_temp(tech_con_exp-1).*(1-repmat(ratio_tech_conver,age_num,1))-c_conver)...
%                 +(1-conv_rate)*v_new_o;

            v_o_convert   = (v_new_temp(tech_con_exp).*repmat(ratio_tech_conver,age_num,1)...
                + v_new_temp(tech_con_exp-1).*(1-repmat(ratio_tech_conver,age_num,1))-c_conver);


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
            tech_con_exp_all(:,i2)      = tech_con_exp;
            ratio_tech_conv_all(:,i2)   = repmat(ratio_tech_conver,age_num,1);
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

        
        dist_ent        = zeros(1,age_num*a_num_g);
        dist_ent(1:a_num_g) = a_prob;

        
        for j=1:1:trans_t
             %%% Here I derive the transition matrix; first those who don't adopt go to
            %%% the same technology state with a higher age, those who adopt go the
            %%% technology they adopt with the age zero meaning we have:
%             tic
            if j>diff_gr_t
                prob_matrix     = prob_matrix_ss;
            else
                prob_matrix     = prob_matrix_tr;
            end

            % cap_contemp_new   = (((a_grid).*(alpha*p_E_vec(j)/p_e_n_vec(j))^alpha.*(1/(1+a_grow)).^age_g)...
            %     .^(1/(1-alpha)))';
            % eff_n_vec         = (((a_grid).*alpha*p_E_vec(j)/p_e_n_vec(j).*(1/(1+a_grow)).^age_g)...
            % .^(1/(1-alpha)))';

            eff_n_vec           = (((a_grid).*alpha*p_E_vec(j)/p_e_n_vec(j)...
                .*(((a_grid).^gamma)./(1+a_grow)).^age_g).^(1/(1-alpha)))';
            eff_n_vec           = min(eff_n_vec,e_max*(a_grid)'); %%% e_max is add to cap
                            %%% the amount of input a generator can use
    
            cap_contemp_new     = (a_grid)'.*(((a_grid).^gamma)./(1+a_grow)).^age_g'.*(eff_n_vec.^alpha);
            
            
            exit_vec_n                      = exit_vec_n_all(:,j);
            policy_choice_n                 = policy_choice_n_all(:,:,j);
            
            temp_n                          = exit_vec_n(1:(age_num-1)*a_num_g,1);
            state_if_adopt_n                = zeros(1,a_num_g*age_num*a_num_g);
            state_if_adopt_n(1:age_reduc*a_num_g*a_num_g)     = ...
                repmat(1:1:age_reduc*a_num_g,1,a_num_g)...
                + kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,age_reduc*a_num_g));
            if age_reduc<age_num
            state_if_adopt_n(age_reduc*a_num_g*a_num_g+1:end) = ...
                kron(age_reduc*a_num_g+(0:1:(age_num-age_reduc-1))*a_num_g,ones(1,a_num_g^2)) +...
                repmat(1:1:a_num_g,1,(age_num-age_reduc)*a_num_g)+...
                kron((0:1:a_num_g*(age_num-age_reduc-1)+a_num_g-1),a_num_g*age_num*ones(1,a_num_g));
            end
    
            temp_address_n                  = zeros(1,a_num_g*age_num*a_num_g);
            temp_address_n(1:age_reduc*a_num_g*a_num_g)       = ...
                repmat(1:1:age_reduc*a_num_g,1,a_num_g)...
                + kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,age_reduc*a_num_g));
            if age_reduc<age_num
            temp_address_n(age_reduc*a_num_g*a_num_g+1:end)   = ...
                kron(age_reduc*a_num_g+(0:1:(age_num-age_reduc-1))*a_num_g,ones(1,a_num_g^2)) +...
                repmat(1:1:a_num_g,1,(age_num-age_reduc)*a_num_g)+...
                repmat(kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,(a_num_g))),1,age_num-age_reduc);
            end
    
            temp_matrix_n                       = policy_choice_n.*repmat(prob_matrix,age_num,1)...
                .*(1-exit_vec_n)*(1-exo_exit);
            prob_of_naot_n                      = sum((1-policy_choice_n).*repmat(prob_matrix,age_num,1),2);
            p_of_naot_besideold_n               = ones((age_num-1)*a_num_g,1)...
                .*prob_of_naot_n(1:(age_num-1)*a_num_g)*(1-exo_exit);
            stay_alive_besideold_n              = (ones((age_num-1)*a_num_g,1)-temp_n);

            if j>diff_gr_t
                state_if_naot_n     =  kron((1:1:age_num-1),ones(1,a_num_g))*age_num*a_num_g^2+...
                    (1:1:(age_num-1)*a_num_g)+kron(ones(1,age_num-1),(0:1:a_num_g-1))*age_num*a_num_g;
                values_of_naot      = [p_of_naot_besideold_n.*stay_alive_besideold_n]';
            else
                state_if_naot_n     =  [((1:1:((age_num-1)*a_num_g))...
                    +age_num*a_num_g^2+...
                    (temp_index_grid_exp(1:(age_num-1)*a_num_g)'-1)*age_num*a_num_g),...
                    ((1:1:((age_num-1)*a_num_g))...
                    +age_num*a_num_g^2+...
                    (temp_index_grid_exp(1:(age_num-1)*a_num_g)'-2)*age_num*a_num_g)];
                values_of_naot      = [p_of_naot_besideold_n.*stay_alive_besideold_n.*(1-rat_of_tran_exp(1:(age_num-1)*a_num_g));...
                    p_of_naot_besideold_n.*stay_alive_besideold_n.*(rat_of_tran_exp(1:(age_num-1)*a_num_g))]';

            end

            state_if_adopt_n_y  = mod(state_if_adopt_n,a_num_g*age_num);
            state_if_naot_n_y   = mod(state_if_naot_n,a_num_g*age_num);
            state_if_adopt_n_y(state_if_adopt_n_y<1) = a_num_g*age_num;
            state_if_naot_n_y(state_if_naot_n_y<1) = a_num_g*age_num;
            state_if_naot_n_x   = ceil((state_if_naot_n-0.1)/(a_num_g*age_num));
            state_if_adopt_n_x  = ceil((state_if_adopt_n-0.1)/(a_num_g*age_num));
            values_of_adopt     = temp_matrix_n(temp_address_n);
            trans_matrix_n      = sparse([state_if_adopt_n_y,state_if_naot_n_y],[state_if_adopt_n_x,state_if_naot_n_x]...
                ,[values_of_adopt,values_of_naot],a_num_g*age_num,a_num_g*age_num);

            %%% also those who are at the last period would die if they don't adopt to
            %%% any technology and a new firm would enter with a random technology
            %%% meaning for those states with the highest age the transition would be
            %%% randomly to age 0 and tech in [0, a_max]
            
            trans_matrix_n((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob,a_num_g,1).*(1-exit_vec_n((age_num-1)*a_num_g+1:(age_num)*a_num_g));
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

            conv_address_x1     = ceil(((tech_con_exp-1)*a_num_g*age_num...
                +(1:1:a_num_g*age_num)'-0.1)/(a_num_g*age_num));
            conv_address_x2     = ceil(((tech_con_exp-2)*a_num_g*age_num...
                +(1:1:a_num_g*age_num)'-0.1)/(a_num_g*age_num));

            conv_address_y1     = mod((tech_con_exp-1)*a_num_g*age_num+(1:1:a_num_g*age_num)',a_num_g*age_num);
            conv_address_y1(conv_address_y1<1) = a_num_g*age_num;
            conv_address_y2     = mod((tech_con_exp-2)*a_num_g*age_num+(1:1:a_num_g*age_num)',a_num_g*age_num);
            conv_address_y2(conv_address_y2<1) = a_num_g*age_num;

            conv_matrix         = sparse([conv_address_y1;conv_address_y2],...
                [conv_address_x1;conv_address_x2],...
                [ratio_tech_conver.*p_conversion_o;(1-ratio_tech_conver).*p_conversion_o],...
                a_num_g*age_num,a_num_g*age_num);
            
            cap_new(j)    = dist_n * cap_contemp_new(:);
            input_use_n   = dist_n * eff_n_vec(:);
            
            p_e_n_vec(j)  = (input_use_n/e0_n_vec(j)*...
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
            dist_new_n    = dist_new_n + m_of_entry_n(j)*dist_ent +...
                dist_conv;
 
            dist_n        = dist_new_n;

            dist_n_all(j,:)  = dist_n;
            input_all_n(j+1) =input_use_n;

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

            prob_matrix     = prob_matrix_ss;

%              tic  *lag_grow_compensate(j)         
            % cap_contemp_old   = (((a_grid)/tech_dist_vec(j)...
            %     .*(alpha*p_E_vec(j)/p_e_o_vec(j))^alpha.*(1/(1+a_grow)).^age_g)...
            %     .^(1/(1-alpha)))';
            % eff_o_vec           = (((a_grid)/tech_dist_vec(j)...
            %     .*alpha*p_E_vec(j)/p_e_o_vec(j).*(1/(1+a_grow)).^age_g)...
            % .^(1/(1-alpha)))';

            eff_o_vec           = (((a_grid)/tech_dist_vec(j).*alpha*...
                p_E_vec(j)/p_e_o_vec(j).*(((a_grid).^gamma)./(1+a_grow)).^age_g)...
                .^(1/(1-alpha)))';
            eff_o_vec           = min(eff_o_vec,e_max*(a_grid)'); %%% e_max is add to cap
                            %%% the amount of input a generator can use
    
            cap_contemp_old     = (a_grid')/tech_dist_vec(j).*...
                (((a_grid).^gamma)./(1+a_grow)).^age_g'.*(eff_o_vec.^alpha);

            exit_vec_o                      = exit_vec_o_all(:,j);
            policy_choice_o                 = policy_choice_o_all(:,:,j);

            temp_o                          = exit_vec_o(1:(age_num-1)*a_num_g,1);
            state_if_adopt_o                = zeros(1,a_num_g*age_num*a_num_g);
            state_if_adopt_o(1:age_reduc*a_num_g*a_num_g)     = ...
                repmat(1:1:age_reduc*a_num_g,1,a_num_g)...
                + kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,age_reduc*a_num_g));
            if age_reduc<age_num
            state_if_adopt_o(age_reduc*a_num_g*a_num_g+1:end) = ...
                kron(age_reduc*a_num_g+(0:1:(age_num-age_reduc-1))*a_num_g,ones(1,a_num_g^2)) +...
                repmat(1:1:a_num_g,1,(age_num-age_reduc)*a_num_g)+...
                kron((0:1:a_num_g*(age_num-age_reduc-1)+a_num_g-1),a_num_g*age_num*ones(1,a_num_g));
            end
    
            temp_address_o                  = zeros(1,a_num_g*age_num*a_num_g);
            temp_address_o(1:age_reduc*a_num_g*a_num_g)       = ...
                repmat(1:1:age_reduc*a_num_g,1,a_num_g)...
                + kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,age_reduc*a_num_g));
            if age_reduc<age_num
            temp_address_o(age_reduc*a_num_g*a_num_g+1:end)   = ...
                kron(age_reduc*a_num_g+(0:1:(age_num-age_reduc-1))*a_num_g,ones(1,a_num_g^2)) +...
                repmat(1:1:a_num_g,1,(age_num-age_reduc)*a_num_g)+...
                repmat(kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,(a_num_g))),1,age_num-age_reduc);
            end
    
            temp_matrix_o                       = policy_choice_o.*repmat(prob_matrix,age_num,1)...
                .*(1-exit_vec_o)*(1-exo_exit);
            prob_of_naot_o                      = sum((1-policy_choice_o).*repmat(prob_matrix,age_num,1),2);
            state_if_naot_o                     =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
                [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
            p_of_naot_besideold_o               = ones((age_num-1)*a_num_g,1)...
                .*prob_of_naot_o(1:(age_num-1)*a_num_g)*(1-exo_exit);
            stay_alive_besideold_o              = (ones((age_num-1)*a_num_g,1)-temp_o);
            p_conversion_o                      = p_conv_o_all_prev(:,j);
            

            state_if_adopt_o_y  = mod(state_if_adopt_o,a_num_g*age_num);
            state_if_naot_o_y   = mod(state_if_naot_o,a_num_g*age_num);
            state_if_adopt_o_y(state_if_adopt_o_y<1) = a_num_g*age_num;
            state_if_naot_o_y(state_if_naot_o_y<1) = a_num_g*age_num;
            state_if_naot_o_x   = ceil((state_if_naot_o-0.1)/(a_num_g*age_num));
            state_if_adopt_o_x  = ceil((state_if_adopt_o-0.1)/(a_num_g*age_num));
            values_of_adopt_o   = temp_matrix_o(temp_address_o);
            values_of_naot_o    = (p_of_naot_besideold_o.*stay_alive_besideold_o)';
            trans_matrix_o      = sparse([state_if_adopt_o_y,state_if_naot_o_y],[state_if_adopt_o_x,state_if_naot_o_x]...
                ,[values_of_adopt_o,values_of_naot_o],a_num_g*age_num,a_num_g*age_num);
    
            trans_matrix_o((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob,a_num_g,1).*(1-exit_vec_o((age_num-1)*a_num_g+1:(age_num)*a_num_g));
%             trans_matrix_o = sparse(trans_matrix_o);
            
            cap_old(j)    = dist_o * cap_contemp_old(:);
            conv_exit(j)  = sum(dist_o.*p_conversion_o');

            input_use_o   = dist_o * eff_o_vec(:);
            
            p_e_o_vec(j)  = (input_use_o/e0_o*...
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
            dist_new_o    = dist_new_o + m_of_entry_o(j)*dist_ent;
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
        
        
        p_E_vec     = p_E_vec + 0.5*output_adjsut*demand_err/((ceil(k/20)));

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
        

        
        
    end
    v_new_resh_n_all(:,:,1:end-1)   = v_new_resh_n_all(:,:,2:end);
    v_new_resh_n_all(:,:,end)       = final_val2;
    v_new_resh_o_all(:,:,1:end-1)   = v_new_resh_o_all(:,:,2:end);
    v_new_resh_o_all(:,:,end)       = final_val1;
    temp          = sum(a_prob.*v_new_resh_n_all(1,:,:),2);
    value_err_n   = reshape(temp(:),trans_t,1)-c_e_new_vec';
    temp          = sum(a_prob.*v_new_resh_o_all(1,:,:),2);
    value_err_o   = temp(:)-c_of_e;
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
        if k>1
            m_of_entry_n    = (m_of_entry_n.*(1+0.4*measure_adj_n*value_err_n')).*(value_err_n'>0)...
                + m_of_entry_n.*(1+0.4*measure_adj_n*value_err_n').*(value_err_n'<0);
        else
            m_of_entry_n    = (m_of_entry_n.*(1+0.2*value_err_n')).*(value_err_n'>0)...
                + m_of_entry_n.*(1+0.2*value_err_n').*(value_err_n'<0);
        end
    else
        m_of_entry_n    = (m_of_entry_n+0.00001)/sum(m_of_entry_n+0.00001)*...
            (sum(m_of_entry_n)+0.1*(sum(final_dist_n)-measure_vec_n(end)));
    end
%+0.0001*value_err_o'
    if abs(measure_vec_o(end)-sum(final_dist_o))<0.1
        if k>1
            m_of_entry_o    = (m_of_entry_o.*(1+0.4*measure_adj_o*value_err_o')).*(value_err_o'>0)...
                + m_of_entry_o.*(1+0.4*measure_adj_o*value_err_o').*(value_err_o'<0);
        else
            m_of_entry_o    = (m_of_entry_o.*(1+0.2*value_err_o')).*(value_err_o'>0)...
                + m_of_entry_o.*(1+0.2*value_err_o').*(value_err_o'<0);
        end
    else
        m_of_entry_o    = (m_of_entry_o+0.00001)/sum(m_of_entry_o+0.00001)*...
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
end
end