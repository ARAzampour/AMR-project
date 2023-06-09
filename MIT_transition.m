function [trans_prob_o_all,v_new_resh_o_all,dist_o_all,measure_vec_o,p_e_o_vec,...
    trans_prob_n_all,v_new_resh_n_all,dist_n_all,measure_vec_n,p_e_n_vec,...
    age_g,a_grid,a_prob,p_E_vec,cap_old,cap_new] =...
    MIT_transition(a_grow,alpha,~,beta,c_of_a,c_a_new_vec,a_lamb,a_num_g,age_num,max_iter,...
    v_tol,~,fco,e_p,d_0,c_of_e,c_e_new_vec,dem_tol,init_dist_n,init_dist_o,final_val1,final_val2,...
    diff_gr,diff_gr_t,init_p_E,final_p_E,trans_t,final_dist_n,final_dist_o,...
    e0_n_vec,e0_o,e_n_eps,e_o_eps,diff_gr_cons,fin_p_e_n,init_p_e_n,fin_p_e_o,init_p_e_o)

a_grid  =  expinv(linspace(0,0.999,a_num_g),a_lamb);
a_cdf   = expcdf(a_grid,a_lamb);
a_prob  = [a_cdf(2:a_num_g) 1]-a_cdf;

max_iter_price      = floor(max_iter/10);
max_iter_measure    = max_iter_price*10;
 
age_g   = (linspace(0,age_num-1,age_num))';


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
dem_err_pre     = 1;
demand_err      = 1;

growth_t_line   = diff_gr_t*ones(1,trans_t);
growth_t_line(1:diff_gr_t) = linspace(1,diff_gr_t,diff_gr_t);
tech_dist_vec   = (1+diff_gr).^growth_t_line*diff_gr_cons;

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

m_of_entry_n        = exp(linspace(0,-10,trans_t));
m_of_entry_n        = m_of_entry_n/(sum(m_of_entry_n))*...
    (sum(final_dist_n,'all')-sum(init_dist_n,'all'));
m_of_entry_o        = exp(linspace(0,-10,trans_t));
m_of_entry_o        = m_of_entry_o/(sum(m_of_entry_o))*...
    (sum(final_dist_o,'all')-sum(init_dist_o,'all'));

m_of_entry_n(m_of_entry_n<0)    = 0;
m_of_entry_o(m_of_entry_o<0)    = 0;

value_err_n_pre     = zeros(trans_t,1);
value_err_o_pre     = zeros(trans_t,1);
entry_new_pre       = m_of_entry_n/(sum(m_of_entry_n))*...
    (sum(final_dist_n,'all')-sum(init_dist_n,'all'));
entry_old_pre       = m_of_entry_o/(sum(m_of_entry_o))*...
    (sum(final_dist_o,'all')-sum(init_dist_o,'all'));

entry_old_pre(isnan(entry_old_pre)) = 0;



for h=1:1:max_iter_measure
    for k=1:1:max_iter_price

        v_of_new    = final_val2;
        v_of_old    = final_val1;

        for i1=trans_t:-1:1

            

            pi_contemp_new      = ((1+a_grid).*(alpha*p_E_vec(i1)/p_e_n_vec(i1))^alpha.*(1/(1+a_grow)).^age_g)...
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
        
            v_n_best      = max(v_n_adopt_vec-c_a_new_vec(i1)...
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
        
%             error       = max(abs(v_of_new-v_new_resh_n),[],"all");
        
        
            v_of_new = v_new_resh_n;

            v_new_resh_n_all(:,:,i1)    = v_new_resh_n;
            policy_choice_n_all(:,:,i1) = policy_choice_n;
            exit_vec_n_all(:,i1)        = exit_vec_n;

            trans_prob_n_all(:,i1)      = policy_choice_n*a_prob';
        end
        fprintf("MIT value function of new is done\n");


        for i2=trans_t:-1:1


            pi_contemp_old      = ((1+a_grid)/tech_dist_vec(i2).*(alpha*p_E_vec(i2)/p_e_o_vec(i2))^alpha.*(1/(1+a_grow)).^age_g)...
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
        
%             error       = max(abs(v_of_old-v_new_resh_o),[],"all");
        
        
            v_of_old = v_new_resh_o;
            
            v_new_resh_o_all(:,:,i2)    = v_new_resh_o;
            policy_choice_o_all(:,:,i2) = policy_choice_o;
            exit_vec_o_all(:,i2)        = exit_vec_o;

            trans_prob_o_all(:,i2)      = policy_choice_o * a_prob';
        end
        
        fprintf("MIT value function of ld is done\n");
        %%
       

%         m_of_firms_old  = sum(init_dist,'all');
        m_of_firms_new  = 0;
        dist_n          = init_dist_n;
        dist_o          = init_dist_o;

        cap_old         = ones(1,trans_t);
        cap_new         = ones(1,trans_t);


        
        dist_ent        = zeros(1,age_num*a_num_g);
        dist_ent(1:a_num_g) = 1/a_num_g;

        
        for j=1:1:trans_t
             %%% Here I derive the transition matrix; first those who don't adopt go to
            %%% the same technology state with a higher age, those who adopt go the
            %%% technology they adopt with the age zero meaning we have:
            
            cap_contemp_new   = (((1+a_grid).*(alpha*p_E_vec(j)/p_e_n_vec(j))^alpha.*(1/(1+a_grow)).^age_g)...
                .^(1/(1-alpha)))';
            eff_n_vec         = (((1+a_grid).*alpha*p_E_vec(j)/p_e_n_vec(j).*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha)))';
            
            exit_vec_n                      = logical(exit_vec_n_all(:,j));
            policy_choice_n                 = policy_choice_n_all(:,:,j);
            
            trans_matrix_n                  = sparse(a_num_g*age_num,a_num_g*age_num);
            trans_matrix_n(:,1:a_num_g)     = policy_choice_n.*repmat(a_prob,age_num*a_num_g,1).*(1-exit_vec_n);
            prob_of_naot_n                  = sum((1-policy_choice_n).*repmat(a_prob,age_num*a_num_g,1),2);
            state_if_naot_n                 =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
                [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
            trans_matrix_n(state_if_naot_n) = 1*prob_of_naot_n(1:(age_num-1)*a_num_g)...
                .*(1-exit_vec_n(1:(age_num-1)*a_num_g));
            

            %%% also those who are at the last period would die if they don't adopt to
            %%% any technology and a new firm would enter with a random technology
            %%% meaning for those states with the highest age the transition would be
            %%% randomly to age 0 and tech in [0, a_max]
            
            trans_matrix_n((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob,a_num_g,1).*(1-exit_vec_n((age_num-1)*a_num_g+1:(age_num)*a_num_g));
%             trans_matrix_n = sparse(trans_matrix_n);
            
            dist_new_n    = dist_n *trans_matrix_n;

            %%%% we can not kick out people and we can just observer
            %%%% whether it's benefitial to enter or not, thus I have to
            %%%% adjust how the transition works
            
            dist_new_n    = dist_new_n + m_of_entry_n(j)*dist_ent;
 
            dist_n        = dist_new_n;

            cap_new(j)    = dist_n * cap_contemp_new(:);
            
            
            measure_vec_n(j) = sum(dist_n);

            p_e_n_vec(j)     = (dist_n * eff_n_vec(:)/e0_n_vec(j)).^e_n_eps;
        
        end
        
        fprintf("MIT distribution of new is found\n");

        for j=1:1:trans_t

                        
            cap_contemp_old   = (((1+a_grid)/tech_dist_vec(j).*(alpha*p_E_vec(j)/p_e_o_vec(j))^alpha.*(1/(1+a_grow)).^age_g)...
                .^(1/(1-alpha)))';
            eff_o_vec           = (((1+a_grid)/tech_dist_vec(j).*alpha*p_E_vec(j)/p_e_o_vec(j).*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha)))';

            exit_vec_o                      = exit_vec_o_all(:,j);
            policy_choice_o                 = policy_choice_o_all(:,:,j);
            trans_matrix_o                  = sparse(a_num_g*age_num,a_num_g*age_num);
            trans_matrix_o(:,1:a_num_g)     = policy_choice_o.*repmat(a_prob,age_num*a_num_g,1).*(1-exit_vec_o);
            prob_of_naot_o                  = sum((1-policy_choice_o).*repmat(a_prob,age_num*a_num_g,1),2);
            state_if_naot_o                 =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
                [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
            trans_matrix_o(state_if_naot_o) = 1*prob_of_naot_o(1:(age_num-1)*a_num_g)...
                .*(1-exit_vec_o(1:(age_num-1)*a_num_g));
            
            
    
            trans_matrix_o((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob,a_num_g,1).*(1-exit_vec_o((age_num-1)*a_num_g+1:(age_num)*a_num_g));
%             trans_matrix_o = sparse(trans_matrix_o);
            
            
            dist_new_o    = dist_o *trans_matrix_o;
            dist_new_o    = dist_new_o + m_of_entry_o(j)*dist_ent;
            dist_o        = dist_new_o;
            cap_old(j)    = dist_o * cap_contemp_old(:);

            measure_vec_o(j) = sum(dist_o);

            p_e_o_vec(j)     = (dist_o * eff_o_vec(:)/e0_o).^e_o_eps;
        
        end

         fprintf("MIT distribution of old is found\n");
        
        total_cap   = cap_old + cap_new;
        
        suply_price = ((d_0./tech_dist_vec)./total_cap).^(1/e_p);
        
        demand_err  = suply_price - p_E_vec;
        
        if sum(abs(demand_err)/trans_t)<dem_tol
            fprintf("demand and supply has converged and the prices is ..." + ...
                "%2.4f in %2.1f periods\n",mean(p_E_vec),k);
            break;
        end
        
        p_E_vec     = p_E_vec + 0.01*demand_err/((ceil(k/10)));

        p_E_vec     = p_E_vec.*(sign(demand_err)==sign(dem_err_pre)) +...
            (p_E_vec+p_E_prev)/2.*(sign(demand_err)~=sign(dem_err_pre));

%         p_E_vec(end) = final_p_E;

        p_E_prev    = p_E_vec;
        dem_err_pre = demand_err;
        

        
        
    end
    temp          = sum(a_prob.*v_new_resh_n_all(1,:,:),2);
    value_err_n   = reshape(temp(:),trans_t,1)-c_e_new_vec';
    temp          = sum(a_prob.*v_new_resh_o_all(1,:,:),2);
    value_err_o   = temp(:)-c_of_e;
    if (max(abs(value_err_n))<dem_tol||max(m_of_entry_n)<v_tol) && ...
            (max(abs(value_err_o))<dem_tol||max(m_of_entry_o)<v_tol)
        fprintf("entry and exit have converged and E(v_new) and E(v_old) ..." + ...
            "is %2.4f and %2.4f in %2.1f periods \n"...
            ,mean(value_err_n),mean(value_err_o),h);
        break;
    end

    m_of_entry_n    = m_of_entry_n.*(1+0.04*value_err_n').*(value_err_n'>0)...
        + m_of_entry_n.*(1+0.01*value_err_n').*(value_err_n'<0);

    m_of_entry_o    = m_of_entry_o.*(1+0.04*value_err_o').*(value_err_o'>0)...
        + m_of_entry_o.*(1+0.01*value_err_o').*(value_err_o'<0);

    
    m_of_entry_n    = m_of_entry_n.*(sign(value_err_n')==value_err_n_pre')+...
        (m_of_entry_n+entry_new_pre)/2.*(sign(value_err_n')~=value_err_n_pre');
    m_of_entry_o    = m_of_entry_o.*(sign(value_err_o')==value_err_o_pre')+...
        (m_of_entry_o+entry_old_pre)/2.*(sign(value_err_o')~=value_err_o_pre');

    value_err_n_pre = value_err_n;
    value_err_o_pre = value_err_o;
    entry_new_pre   = m_of_entry_n;
    entry_old_pre   = m_of_entry_o;
    

    m_of_entry_n(m_of_entry_n<0) = 0;
    m_of_entry_o(m_of_entry_o<0) = 0;
end
end