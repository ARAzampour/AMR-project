function [policy_choice_o_all,v_new_resh_o_all,dist_o_all,...
    policy_choice_n_all,v_new_resh_n_all,dist_n_all,...
    age_g,a_grid,a_prob,pi_contemp_new,p_E_vec,m_of_firms_new] =...
    MIT_transition(a_grow,alpha,a_bar,beta,c_of_a,a_lamb,p_e,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,fco,e_p,d_0,c_of_e,dem_tol,init_dist,final_val1,final_val2,...
    diff_gr,diff_gr_t,init_p_E,final_p_E,trans_t,final_dist_n,final_dist_o)

a_grid  =  expinv(linspace(0,0.999,a_num_g),a_lamb);
a_cdf   = expcdf(a_grid,a_lamb);
a_prob  = [a_cdf(2:a_num_g) 1]-a_cdf;

max_iter_price      = floor(max_iter/100);
max_iter_measure    = max_iter_price;
 
age_g   = (linspace(0,age_num-1,age_num))';


dist_o_all          = zeros(trans_t,age_num*a_num_g);
dist_n_all          = zeros(trans_t,age_num*a_num_g);
policy_choice_n     = zeros(age_num*a_num_g,a_num_g);
policy_choice_o     = zeros(age_num*a_num_g,a_num_g);

p_E_vec         = linspace(init_p_E,final_p_E,trans_t);
growth_t_line   = 20*ones(1,trans_t);
growth_t_line(1:diff_gr_t) = linspace(1,diff_gr_t,diff_gr_t);
tech_dist_vec   = (1+diff_gr).^growth_t_line;

v_of_new    = final_val2;
v_of_old    = final_val1;

v_new_resh_n_all    = zeros(age_num,a_num_g,trans_t);
v_new_resh_o_all    = zeros(age_num,a_num_g,trans_t);

policy_choice_o_all = zeros(age_num*a_num_g,a_num_g,trans_t);
policy_choice_n_all = zeros(age_num*a_num_g,a_num_g,trans_t);

exit_vec_n_all      = zeros(age_num*a_num_g,trans_t);
exit_vec_o_all      = zeros(age_num*a_num_g,trans_t);

for h=1:1:max_iter_measure
    for k=1:1:max_iter_price
        
        for i1=trans_t:-1:1

            

            pi_contemp_new      = ((1+a_grid).*(alpha*p_E_vec(i1)/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
                .^(1/(1-alpha))*(1-alpha);
            
        
            pi_contemp_new      = pi_contemp_new - fco;
        
            pi_contemp_neg_new  = pi_contemp_new<0;
            pi_contemp_new(pi_contemp_neg_new) = 0;
    
            
            v_p_n = v_of_new';
            v_p_n(:,1:age_num-1)  = v_p_n(:,2:age_num);
            v_p_n(:,age_num)      = 0;            %%% setting the
                                                %%% value of those who don't adopt
                                                %%% at the highest age to zero; it
                                                %%% should also be noted that if a
                                                %%% firm is not adopting, in the
                                                %%% next period it would get the
                                                %%% value of v(age+1,a_i)
        
        
        
            v_p_n_vec     = (v_p_n(:));
            v_p_n_expand  = kron(v_p_n_vec,ones(a_num_g,1));
            v_n_adopt     = kron(ones(age_num,a_num_g),v_of_new(1,:));
            v_n_adopt_p   = v_n_adopt';
            v_n_adopt_vec = v_n_adopt_p(:);        
        
            v_n_best      = max(v_n_adopt_vec-c_of_a*(1)...
                ,v_p_n_expand);
        
            v_n_best_resh = (reshape(v_n_best,a_num_g,age_num*a_num_g))';
        
             
            policy_choice_n = 1-(v_n_best_resh==v_p_n_vec);
        
            %%% those who couldn't pay the fco should exit
            exiting_firm_n    = pi_contemp_neg_new';
            exit_vec_n        = exiting_firm_n(:);
            policy_choice_n   = (1-exit_vec_n).*policy_choice_n;
        
            v_new_n       = v_n_best_resh*a_prob';
            v_new_resh_n  = (reshape(v_new_n,a_num_g,age_num))';
            v_new_resh_n  = pi_contemp_new + beta*v_new_resh_n;

            v_new_resh_n(pi_contemp_neg_new) = 0;
        
            error       = max(abs(v_of_new-v_new_resh_n),[],"all");
        
        
            v_of_new = v_new_resh_n;

            v_new_resh_n_all(:,:,i1)    = v_new_resh_n;
            policy_choice_n_all(:,:,i1) = policy_choice_n;
            exit_vec_n_all(:,i1)        = exit_vec_n;
        end
        fprintf("MIT value function of new is done\n");


        for i2=trans_t:-1:1


            pi_contemp_old      = ((1+a_grid)/tech_dist_vec(i2).*(alpha*p_E_vec(i1)/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
                .^(1/(1-alpha))*(1-alpha);

            pi_contemp_old      = pi_contemp_old - fco;
            
            pi_contemp_neg_old  = pi_contemp_old<0;
            pi_contemp_old(pi_contemp_neg_old) = 0;

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
            v_o_adopt     = kron(ones(age_num,a_num_g),v_of_old(1,:));
            v_o_adopt_p   = v_o_adopt';
            v_o_adopt_vec = v_o_adopt_p(:);        
        
            v_o_best      = max(v_o_adopt_vec-c_of_a*(1)...
                ,v_p_o_expand);
        
            v_o_best_resh = (reshape(v_o_best,a_num_g,age_num*a_num_g))';
        
             
            policy_choice_o = 1-(v_o_best_resh==v_p_o_vec);
        
            %%% those who couldn't pay the fco should exit
            exiting_firm_o    = pi_contemp_neg_old';
            exit_vec_o        = exiting_firm_o(:);
            policy_choice_o   = (1-exit_vec_o).*policy_choice_o;
        
            v_new_o       = v_o_best_resh*a_prob';
            v_new_resh_o  = (reshape(v_new_o,a_num_g,age_num))';
            v_new_resh_o  = pi_contemp_old + beta*v_new_resh_o;

            v_new_resh_o(pi_contemp_neg_old) = 0;
        
            error       = max(abs(v_of_old-v_new_resh_o),[],"all");
        
            if error<v_tol
                
                fprintf("value function of old converged in %4.1f periods\n",i2);
                break;
            end
        
            v_of_old = v_new_resh_o;
            
            v_new_resh_o_all(:,:,i2)    = v_new_resh_o;
            policy_choice_o_all(:,:,i2) = policy_choice_o;
            exit_vec_o_all(:,i1)        = exit_vec_o;
        end
        
        fprintf("MIT value function of ld is done\n");
        %%
       

        m_of_firms_old  = sum(init_dist,'all');
        m_of_firms_new  = 0;
        dist_n          = m_of_firms_new*ones(1,age_num*a_num_g)/(age_num*a_num_g);
        dist_o          = init_dist;

        cap_old         = ones(1,trans_t);
        cap_new         = ones(1,trans_t);

        measure_vec_n   = linspace(0,sum(final_dist_n,'all'),trans_t);
        measure_vec_o   = linspace(sum(init_dist,'all'),sum(final_dist_o,'all'),trans_t);
        
        dist_ent        = zeros(1,age_num*a_num_g);
        dist_ent(1:a_num_g) = 1/a_num_g;

        
        for j=1:1:trans_t
             %%% Here I derive the transition matrix; first those who don't adopt go to
            %%% the same technology state with a higher age, those who adopt go the
            %%% technology they adopt with the age zero meaning we have:
            
            cap_contemp_new   = (((1+a_grid).*(alpha*p_E_vec(i1)/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
                .^(1/(1-alpha)))';

            exit_vec_n        = exit_vec_o_all(:,i1);
            policy_choice_n   = policy_choice_n_all(:,:,j);
            trans_matrix_n    = zeros(a_num_g*age_num,a_num_g*age_num);
            trans_matrix_n(:,1:a_num_g) = policy_choice_n.*repmat(a_prob,age_num*a_num_g,1);
            prob_of_naot_n    = sum((1-policy_choice_n).*repmat(a_prob,age_num*a_num_g,1),2);
            state_if_naot_n   =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
                [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
            trans_matrix_n(state_if_naot_n) = 1*prob_of_naot_n(1:(age_num-1)*a_num_g);

            %%% also those who are at the last period would die if they don't adopt to
            %%% any technology and a new firm would enter with a random technology
            %%% meaning for those states with the highest age the transition would be
            %%% randomly to age 0 and tech in [0, a_max]
            
            trans_matrix_n((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = repmat(a_prob,a_num_g,1);
            trans_matrix_n = trans_matrix_n.*(1-exit_vec_n);
%             trans_matrix_n = sparse(trans_matrix_n);
            
            dist_new_n    = dist_n *trans_matrix_n;
            dist_new_n    = dist_new_n + (measure_vec_n(j)-sum(dist_new_n))*dist_ent;
 
            dist_n        = dist_new_n;

            cap_new(j)    = dist_n * cap_contemp_new(:);
        
        end
        fprintf("MIT distribution of new is found\n");

        for j=1:1:trans_t

                        
            cap_contemp_old   = (((1+a_grid)/tech_dist_vec(i2).*(alpha*p_E_vec(i1)/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
                .^(1/(1-alpha)))';

            exit_vec_o        = exit_vec_o_all(:,i1);
            policy_choice_o   = policy_choice_o_all(:,:,j);
            trans_matrix_o    = zeros(a_num_g*age_num,a_num_g*age_num);
            trans_matrix_o(:,1:a_num_g) = policy_choice_o.*repmat(a_prob,age_num*a_num_g,1);
            prob_of_naot_o    = sum((1-policy_choice_o).*repmat(a_prob,age_num*a_num_g,1),2);
            state_if_naot_o   =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
                [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
            trans_matrix_o(state_if_naot_o) = 1*prob_of_naot_o(1:(age_num-1)*a_num_g);
            
            
    
            trans_matrix_o((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = repmat(a_prob,a_num_g,1);
            trans_matrix_o = trans_matrix_o.*(1-exit_vec_o);
%             trans_matrix_o = sparse(trans_matrix_o);
            
            
            dist_new_o    = dist_o *trans_matrix_o;
            dist_new_o    = dist_new_o + (measure_vec_o(j)-sum(dist_new_o))*dist_ent;
            dist_o        = dist_new_o;
            cap_old(j)    = dist_o * cap_contemp_old(:);
        
        end

         fprintf("MIT distribution of old is found\n");
        
        total_cap   = cap_old + cap_new;
        
        suply_price = ((d_0./tech_dist_vec)./total_cap).^(1/e_p);
        
        demand_err  = suply_price - p_E_vec;
        
        if sum(abs(demand_err)/trans_t)<dem_tol
            fprintf("demand and supply has converged and the prices is ..." + ...
                "%2.4f in %2.1f periods\n",p_E,k);
            break;
        end
        
        p_E_vec     = p_E_vec + 0.2*demand_err/(ceil(k/10));
    end
    temp          = sum(a_prob.*v_new_resh_n_all(1,:,:),2);
    value_err_n   = temp(:)-c_of_e;
    temp          = sum(a_prob.*v_new_resh_o_all(1,:,:),2);
    value_err_o   = temp(:)-c_of_e;
    if (sum(abs(value_err_n))/trans_t<dem_tol||sum(measure_vec_n)/trans_t<v_tol) && ...
            (sum(abs(value_err_o))/trans_t<dem_tol||sum(measure_vec_o)/trans_t<v_tol)
        fprintf("entry and exit have converged and E(v_new) and E(v_old) ..." + ...
            "is %2.4f and %2.4f in %2.1f periods \n"...
            ,value_err_n,value_err_o,h);
        break;
    end
    if value_err_n>-5
        measure_vec_n = measure_vec_n*(1+0.1*value_err_n);
    else
        measure_vec_n = measure_vec_n*(1+0.05*value_err_n);
    end
    if value_err_o>-5
        measure_vec_o = measure_vec_o*(1+0.1*value_err_o);
    else
        measure_vec_o = measure_vec_o*(1+0.05*value_err_o);
    end
end
end