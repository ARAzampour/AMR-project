function [trans_prob_o,v_new_o,v_new_resh_o,dist_o,trans_matrix_n,p_e_n,cap_contemp_new,eff_n_final,...
    trans_prob_n,v_new_n,v_new_resh_n,dist_n,trans_matrix_o,p_e_o,cap_contemp_old,eff_o_final,...
    age_g,a_grid_old,a_prob_old,a_grid_new,a_prob_new,pi_contemp_new,p_E,m_of_firms_new,m_of_firms_old,exit_n,exit_o] = ...
    Two_tech_ss_AC2(a_grow,alpha,~,beta,c_of_a,c_a_new,mu_old,sigma_old,mu_new,sigma_new,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,fco_o,fco_n,e_p,d_0,c_of_e,c_e_new,dem_tol,tech_dist,...
    e0_n,e0_o,e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,P_E_grid_norm)

if nargin<35 || isempty(P_E_grid_norm)
    P_E_grid_norm = P_E_grid(50,1);
else
    P_E_grid_norm = P_E_grid_norm(:);
end

% a_grid  =  expinv(linspace(0,0.999,a_num_g),a_lamb);
x_old   = norminv(linspace(0,1,a_num_g+2),mu_old,sigma_old); %%% looking at the entrants, 
                            %%% distribution we have now decided to use
                            %%% normal distribution 2024-09-11
%a_grid  = expinv(1-exp(linspace(log(1),log(0.001),a_num_g)),a_lamb); %%% here
                %%%% I've change the spacing for grid productivity, the
                %%%% reason is that by using the grid the gives equall prob
                %%%% to each grid point we would focus to much on the
                %%%% points that no action would be happening
                %%%%%% the previous comments is not a danger here now we're
                %%%%%% in normal
a_grid_old  = x_old(2:a_num_g+1);
a_cdf_old   = normcdf(x_old,mu_old,sigma_old);
a_prob_old  = a_cdf_old(2:a_num_g+1)-a_cdf_old(1:a_num_g);
a_prob_old  = a_prob_old/sum(a_prob_old);

prob_matrix_old     = auto_corr_prob(a_grid_old,a_prob_old,rho);


x_new   = norminv(linspace(0,1,a_num_g+2),mu_new,sigma_new); %%% looking at the entrants of new,



a_grid_new  = x_new(2:a_num_g+1);

assert(all(a_grid_new>0),'variance of new tech efficiency draw is too large')
assert(all(a_grid_old>0),'variance of old tech efficiency draw is too large')

a_cdf_new   = normcdf(x_new,mu_new,sigma_new);
a_prob_new  = a_cdf_new(2:a_num_g+1)-a_cdf_new(1:a_num_g);
a_prob_new  = a_prob_new/sum(a_prob_new);

prob_matrix_new     = auto_corr_prob(a_grid_new,a_prob_new,rho);

max_iter_price      = floor(max_iter/1);
max_iter_measure    = max_iter_price*1;
 
age_g   = (linspace(0,age_num-1,age_num))';
exit_sm = 2;

%%% effective productivity per state: a_{i,t} = a_i * (1 - a_grow*t), capped at zero
a_eff_new = a_grid_new' .* max(1 - a_grow .* age_g', 0);   % (a_num_g x age_num)
a_eff_old = (a_grid_old./tech_dist)' .* max(1 - a_grow .* age_g', 0);

%%% normalized price grids: scale by the mean prices that clear the markets
n_pe = 10;
p_e_n_grid_norm = p_input_grid(n_pe,1,sigma_p_n,rho_p_n);
p_e_o_grid_norm = p_input_grid(n_pe,1,sigma_p_o,rho_p_o);

policy_choice_n   = zeros(age_num*a_num_g,a_num_g);
policy_choice_o   = zeros(age_num*a_num_g,a_num_g);


weight_adj_p      = 0.2;
%%%%% these should be predefined for mex purposes

trans_matrix_n   = sparse(age_num*a_num_g,age_num*a_num_g);
dist_n           = zeros(1,age_num*a_num_g);
v_new_n          = zeros(age_num*a_num_g,1);
v_new_resh_n     = zeros(age_num,a_num_g);
exit_vec_n       = zeros(age_num*a_num_g,'logical');


trans_matrix_o   = sparse(age_num*a_num_g,age_num*a_num_g);
dist_o           = zeros(1,age_num*a_num_g);
v_new_o          = zeros(age_num*a_num_g,1);
v_new_resh_o     = zeros(age_num,a_num_g);
exit_vec_o       = zeros(age_num*a_num_g,'logical');


%%%%%

%%%%%

%%% Here we will have endogenous entry: this means that as long as value of
%%% entrant - the cost of entry is positive there should be entrants. To
%%% solve it I will loop over the whole soltuion till I find the
%%% equilibrium price satisfying this condition; first I start with p_E = 1


p_E         = 35;
p_E_prev    = 35;
dem_err_pre = 0;
input_err_n_pre = 0;
input_err_o_pre = 0;

%%%% I think we need to have varying price of effort for the techs of
%%%% course it can have an ifinite elasticity like the case of solar, 
%%%% fist set it to be equal for both to one

p_e_n   = 12;
p_e_o   = 3.5;

% eff_n_vec   = zeros(age_num,a_num_g);
% eff_o_vec   = zeros(age_num,a_num_g); if mex gives error I'll pre define
% them


%%% initial period profits via new production function (seeds value iteration)
[~, ~, pi_n_init]   = static_solver(a_eff_new, p_E.*P_E_grid_norm, p_e_n.*p_e_n_grid_norm, alpha, fco_n, 1./a_grid_new(:));
[~, ~, pi_o_init]   = static_solver(a_eff_old, p_E.*P_E_grid_norm, p_e_o.*p_e_o_grid_norm, alpha, fco_o, 1./a_grid_old(:));
pi_contemp_new      = pi_n_init';   % (age_num x a_num_g)
pi_contemp_old      = pi_o_init';

%%% those with negative contemporary profit will exit
% pi_contemp_neg_new  = pi_contemp_new<0;
% pi_contemp_new(pi_contemp_neg_new) = 0;

% pi_contemp_neg_old  = pi_contemp_old<0;
% pi_contemp_old(pi_contemp_neg_old) = 0;




v_of_new = pi_contemp_new;
v_of_old = pi_contemp_old;


%%%% also to have the entry and exit equal to each other the measure of the
%%%% firms should be the correct number

m_of_firms_new  = 1;
m_of_firms_old  = 3;

value_err_n_pre = 0;
value_err_o_pre = 0;
m_of_new_pre    = m_of_firms_new;
m_of_old_pre    = m_of_firms_old;

p_e_n_pre       = p_e_n;
p_e_o_pre       = p_e_o;


%%%
measure_adj_n   = 0.1;
measure_adj_o   = 0.1;

%%
for h=1:1:max_iter_measure
    output_adjsut   = 0.2/(max(e_n_eps,e_o_eps));
    input_adjsut_n  = 0.5;
    input_adjsut_o  = 0.5;
    for k=1:1:max_iter_price
        [eff_n_vec, cap_contemp_new, pi_n_mat] = static_solver(a_eff_new, p_E.*P_E_grid_norm, p_e_n.*p_e_n_grid_norm, alpha, fco_n, 1./a_grid_new(:));
        [eff_o_vec, cap_contemp_old, pi_o_mat] = static_solver(a_eff_old, p_E.*P_E_grid_norm, p_e_o.*p_e_o_grid_norm, alpha, fco_o, 1./a_grid_old(:));
        pi_contemp_new      = pi_n_mat';   % (age_num x a_num_g)
        pi_contemp_old      = pi_o_mat';



        for i1=1:1:max_iter
        
%             if all(pi_contemp_new<=0)
%                 fprintf("all profits of new tech is zero \n");
% 
%                 break;
%             end

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
            v_n_adopt     = [kron(ones(age_reduc,a_num_g),v_of_new(1,:));...
                kron(ones(1,a_num_g),v_of_new(1:end-age_reduc,:))];
            v_n_adopt_p   = v_n_adopt';
            v_n_adopt_vec = v_n_adopt_p(:);

            temp_smoother = (1-exp(-(v_n_adopt_vec-c_a_new*(1)-v_p_n_expand)*exit_sm));
            temp_smoother(isinf(temp_smoother)) = -1000;
        
            v_n_best      = v_p_n_expand + (v_n_adopt_vec-c_a_new*(1)-v_p_n_expand)...
                .*(v_n_adopt_vec-c_a_new*(1)>v_p_n_expand).* ...
                temp_smoother;     %%% let's try different adoption costs

            choice_vec_n  = (v_n_adopt_vec-c_a_new*(1)>v_p_n_expand).* ...
                temp_smoother;

            %%% here I've also smoothed the adoption policy, this is because
            %%% the discrete changes in adoption decision makes small
            %%% perturbation in the distribution which hinders market
            %%% clearig
        
            v_n_best_resh = (reshape(v_n_best,a_num_g,age_num*a_num_g))';
        
             
            policy_choice_n = (reshape(choice_vec_n,a_num_g,age_num*a_num_g))';
        
            
        
            v_new_n       = sum(v_n_best_resh.*repmat(prob_matrix_new,age_num,1),2);
            v_new_resh_n  = (reshape(v_new_n,a_num_g,age_num))';
            v_new_resh_n  = pi_contemp_new + beta*(1-exo_exit)*v_new_resh_n;

            %%% those who get non-positive npv should exit
            v_n_neg           = v_new_resh_n<0;
            exiting_firm_n    = v_n_neg'+(1-v_n_neg').*(exp(-v_new_resh_n'*10^exit_sm));
            exiting_firm_n(isnan(exiting_firm_n)) = 1;
            exit_vec_n        = exiting_firm_n(:);
            policy_choice_n   = (1-exit_vec_n).*policy_choice_n;

            v_new_resh_n(v_n_neg)           = 0;
        
            error       = max(abs(v_of_new-v_new_resh_n),[],"all");
        
            if error<v_tol
                
                fprintf("value function of new converged in %4.1f periods\n",i1);
                break;
            end
        
            if (sum(isnan(exit_vec_n))>0)
            fprintf("there is nan\n at %2.1f",i1);
            break;
            end

            v_of_new = v_new_resh_n;
            
        end
        
        for i2=1:1:max_iter
%             if all(pi_contemp_old<=0)
%                 fprintf("all profits of old tech is zero \n");
%                 break;
%             end
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
        
            v_o_best_resh = (reshape(v_o_best,a_num_g,age_num*a_num_g))';
        
             
            policy_choice_o = (reshape(choice_vec_o,a_num_g,age_num*a_num_g))';
        
            
        
            v_new_o       = sum(v_o_best_resh.*repmat(prob_matrix_old,age_num,1),2);
            v_new_resh_o  = (reshape(v_new_o,a_num_g,age_num))';
            v_new_resh_o  = pi_contemp_old + beta*(1-exo_exit)*v_new_resh_o;

            %%% those who get non-positive npv should exit
            v_o_neg           = v_new_resh_o<0; 
            exiting_firm_o    = v_o_neg'+(1-v_o_neg').*(exp(-v_new_resh_o'*10^exit_sm));
            exiting_firm_o(isnan(exiting_firm_o)) = 1;
            exit_vec_o        = exiting_firm_o(:);
            policy_choice_o   = (1-exit_vec_o).*policy_choice_o;

            v_new_resh_o(v_o_neg)           = 0;
        
            error       = max(abs(v_of_old-v_new_resh_o),[],"all");
        
            if error<v_tol
                
                fprintf("value function of old converged in %4.1f periods\n",i2);
                break;
            end
        
            if sum(isnan(v_new_resh_o),"all")>1
                fprintf("there is nan\n at %2.1f",i2);
            break;
            
            end
            
            v_of_old = v_new_resh_o;

            
        end
        
        all_new_values_negative = all(v_n_neg,"all");
        all_old_values_negative = all(v_o_neg,"all");

        %%
        %%% Here I derive the transition matrix; first those who don't adopt go to
        %%% the same technology state with a higher age, those who adopt go the
        %%% technology they adopt with the age zero meaning we have:
        
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

        trans_matrix_n                      = sparse(a_num_g*age_num,a_num_g*age_num);
        temp_matrix_n                       = policy_choice_n.*repmat(prob_matrix_new,age_num,1).*...
            (1-exit_vec_n)*(1-exo_exit);
        trans_matrix_n(state_if_adopt_n)    = temp_matrix_n(temp_address_n);
        prob_of_naot_n                      = sum((1-policy_choice_n).*repmat(prob_matrix_new,age_num,1),2);
        state_if_naot_n                     =  kron((1:age_num-1),ones(1,a_num_g))*age_num*a_num_g^2+...
            (1:(age_num-1)*a_num_g)+kron(ones(1,age_num-1),(0:a_num_g-1))*age_num*a_num_g;
        p_of_naot_besideold_n               = ones((age_num-1)*a_num_g,1).*...
            prob_of_naot_n(1:(age_num-1)*a_num_g)*(1-exo_exit);
        stay_alive_besideold_n              = (ones((age_num-1)*a_num_g,1)-temp_n);
        trans_matrix_n(state_if_naot_n)     = p_of_naot_besideold_n.*stay_alive_besideold_n;




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

        trans_matrix_o                      = sparse(a_num_g*age_num,a_num_g*age_num);
        temp_matrix_o                       = policy_choice_o.*repmat(prob_matrix_old,age_num,1)...
            .*(1-exit_vec_o)*(1-exo_exit);
        trans_matrix_o(state_if_adopt_o)    = temp_matrix_o(temp_address_o);
        prob_of_naot_o                      = sum((1-policy_choice_o).*repmat(prob_matrix_old,age_num,1),2);
        state_if_naot_o                     =  kron((1:age_num-1),ones(1,a_num_g))*age_num*a_num_g^2+...
            (1:(age_num-1)*a_num_g)+kron(ones(1,age_num-1),(0:a_num_g-1))*age_num*a_num_g;
        p_of_naot_besideold_o               = ones((age_num-1)*a_num_g,1).*...
            prob_of_naot_o(1:(age_num-1)*a_num_g)*(1-exo_exit);
        stay_alive_besideold_o              = (ones((age_num-1)*a_num_g,1)-temp_o);
        trans_matrix_o(state_if_naot_o)     = p_of_naot_besideold_o.*stay_alive_besideold_o;

        %%% A plant that reaches the maximum age exits. That mass is part of
        %%% the exiting mass below; it is not replaced inside the transition.
        %%% Steady-state replacement is the entrant distribution times the
        %%% mass of every exit.
        max_age_states = (age_num-1)*a_num_g+1:age_num*a_num_g;
        trans_matrix_n(max_age_states,:) = 0;
        trans_matrix_o(max_age_states,:) = 0;
        
        dist_ent_new    = zeros(1,age_num*a_num_g);
        dist_ent_new(1:a_num_g) = a_prob_new;

        dist_ent_old    = zeros(1,age_num*a_num_g);
        dist_ent_old(1:a_num_g) = a_prob_old;

        if all_new_values_negative
            fprintf("all values of new tech are negative; setting distribution to zero\n");
            dist_n = zeros(1,age_num*a_num_g);
            exit_n = 0;
        else
            [dist_n,exit_n] = stationary_distribution(trans_matrix_n,...
                m_of_firms_new,dist_ent_new,dist_tol,max_iter,"new");
        end

        if all_old_values_negative
            fprintf("all values of old tech are negative; setting distribution to zero\n");
            dist_o = zeros(1,age_num*a_num_g);
            exit_o = 0;
        else
            [dist_o,exit_o] = stationary_distribution(trans_matrix_o,...
                m_of_firms_old,dist_ent_old,dist_tol,max_iter,"old");
        end
        
        total_cap   = dist_n * cap_contemp_new(:) + dist_o * cap_contemp_old(:);
        if total_cap>0
            suply_price = (d_0/total_cap)^(1/e_p);
        else
            suply_price = p_E+100;
        end
        
        fuel_n = (max(dist_n*eff_n_vec(:),0)/e0_n).^(1/e_n_eps);
        fuel_o = (max(dist_o*eff_o_vec(:),0)/e0_o).^(1/e_o_eps);
        [p_E,p_E_prev,dem_err_pre,output_adjsut,demand_err,step_E] = ...
            transition_price_step(p_E,p_E_prev,suply_price,dem_err_pre,...
            output_adjsut,weight_adj_p);
        [p_e_n,p_e_n_pre,input_err_n_pre,input_adjsut_n,input_err_n,step_n] = ...
            transition_price_step(p_e_n,p_e_n_pre,fuel_n,input_err_n_pre,...
            input_adjsut_n,weight_adj_p);
        [p_e_o,p_e_o_pre,input_err_o_pre,input_adjsut_o,input_err_o,step_o] = ...
            transition_price_step(p_e_o,p_e_o_pre,fuel_o,input_err_o_pre,...
            input_adjsut_o,weight_adj_p);

        if (abs(demand_err)<dem_tol || (step_E<5*v_tol && k>max_iter_price/5)) && ...
                (abs(input_err_n)<dem_tol || (step_n<5*v_tol && k>max_iter_price/5)) && ...
                (abs(input_err_o)<dem_tol || (step_o<5*v_tol && k>max_iter_price/5))
            fprintf("demand and supply has converged and the prices is ..." + ...
                "%2.4f in %2.1f periods\n",p_E,k);
            break;
        end

    end


    
%%%why did I do this?
%     value_err_n   = max(a_prob_new*(v_new_resh_n(1,:))'-c_e_new,-1/(0.5*measure_adj_n)); %%% let's try 
%                                 %%%% different entry cost for techs
%     value_err_o   = max(a_prob_old*(v_new_resh_o(1,:))'-c_of_e,-1/(0.5*measure_adj_o));

    value_err_n   = a_prob_new*(v_new_resh_n(1,:))'-c_e_new;
    value_err_o   = a_prob_old*(v_new_resh_o(1,:))'-c_of_e;


    


    

    if (abs(value_err_n)<dem_tol || m_of_firms_new<v_tol) && ...
            (abs(value_err_o)<dem_tol || m_of_firms_old<v_tol)
        fprintf("entry and exit have converged and E(v_new) and E(v_old) ..." + ...
            "is %2.4f and %2.4f in %2.1f periods \n"...
            ,value_err_n,value_err_o,h);
        break;
    end

    [m_of_firms_new,m_of_new_pre,value_err_n_pre,measure_adj_n] = ...
        transition_entry_step(m_of_firms_new,m_of_new_pre,value_err_n,...
        value_err_n_pre,measure_adj_n,h,v_tol);
    [m_of_firms_old,m_of_old_pre,value_err_o_pre,measure_adj_o] = ...
        transition_entry_step(m_of_firms_old,m_of_old_pre,value_err_o,...
        value_err_o_pre,measure_adj_o,h,v_tol);
end

trans_prob_n    = sum(policy_choice_n.*repmat(prob_matrix_new,age_num,1),2);
trans_prob_o    = sum(policy_choice_o.*repmat(prob_matrix_old,age_num,1),2);

eff_n_final     = eff_n_vec(:);
eff_o_final     = eff_o_vec(:);

end

function [price,previous,error_previous,adjust,err,step] = ...
        transition_price_step(price,previous,implied,error_previous,adjust,weight)
price_before = price;
if price_before>0 && implied>0 && abs(implied-price_before)/price_before>0.5
    implied = exp((1-weight)*log(price_before)+weight*log(implied));
end
err = max(min(implied-price_before,25),-25);
tentative = price_before+0.1*adjust*err;
oscill = sign(err)~=sign(error_previous);
den = abs(err)+abs(error_previous);
if oscill && den>0
    price = (price_before*abs(error_previous)+previous*abs(err))/den;
    adjust = adjust*0.95;
else
    price = tentative;
end
price = max(price,sqrt(eps));
step = abs(price-price_before);
previous = price;
error_previous = err;
end

function [mass,previous,error_previous,adjust] = ...
        transition_entry_step(mass,previous,err,error_previous,adjust,h,tol)
lag = mass;
if mass==0 && err>0
    mass = max(10*tol,1e-8);
end
step = 0.1*(abs(err)>50)+0.2*(abs(err)<=50)+0.2*(abs(err)<=1);
mass = mass*(1+step*adjust*err);
if h>1 && sign(err)~=sign(error_previous)
    den = abs(err)+abs(error_previous);
    mass = (lag*abs(error_previous)+previous*abs(err))/max(den,sqrt(eps));
    adjust = adjust*0.95;
end
mass = max(mass,0);
previous = lag;
error_previous = err;
end

function [dist,exit_mass] = stationary_distribution(transition,total_measure,entrant,tol,max_iter,tech_name)
% Stationary distribution with every exit, including maximum age, replaced
% by a draw from the entrant distribution. The direct solve is checked
% against the transition; multiplication is used only when it is inaccurate.
n_state = size(transition,2);
dist = zeros(1,n_state);
exit_mass = 0;
if ~(total_measure>0)
    return
end
row_deficit = 1-full(sum(transition,2));
valid_transition = all(row_deficit>=-1e-10) && all(isfinite(row_deficit));
if valid_transition
    row_deficit = max(row_deficit,0);
    kernel = transition+sparse(row_deficit)*sparse(entrant);
    [unit,direct_ok] = invariant_from_transition(kernel,tol);
else
    direct_ok = false;
    kernel = transition;
end
if direct_ok
    fprintf("distribution of %s solved directly\n",tech_name);
else
    [unit,iter_ok,precision,iterations] = invariant_by_multiplication(...
        kernel,entrant,tol,max_iter);
    if iter_ok
        fprintf("distribution of %s converged in %4.1f periods\n",tech_name,iterations);
    else
        fprintf("distribution of %s stopped at precision %g after %4.1f periods\n",...
            tech_name,precision,iterations);
    end
end
dist = total_measure*unit;
exit_mass = sum(dist-dist*transition);
end

function [dis,ok] = invariant_from_transition(TMsp,tol)
nstate = size(TMsp,1);
dis = ones(1,nstate)/nstate;
ok = false;
if size(TMsp,2)~=nstate || any(~isfinite(nonzeros(TMsp)))
    return
end
A = TMsp'-speye(nstate);
A(end,:) = 1;
b = zeros(nstate,1);
b(end) = 1;
try
    pi_col = A\b;
catch
    return
end
if ~(isnumeric(pi_col) && isvector(pi_col) && numel(pi_col)==nstate) || ...
        any(~isfinite(pi_col))
    return
end
pi_col = real(pi_col);
if any(pi_col<-1e-8)
    return
end
pi_col = max(pi_col,0);
mass = sum(pi_col);
if ~(mass>0) || ~isfinite(mass)
    return
end
dis = (pi_col/mass)';
residual = max(abs(dis*TMsp-dis));
row_error = max(abs(full(sum(TMsp,2))-1));
ok = residual<=max(10*tol,1e-10) && row_error<=max(10*tol,1e-10);
end

function [dis,ok,precision,iterations] = invariant_by_multiplication(TMsp,entrant,tol,max_iter)
nstate = size(TMsp,2);
dis = ones(1,nstate)/nstate;
if abs(sum(entrant)-1)<=sqrt(eps) && all(entrant>=0)
    dis = entrant;
end
ok = false;
precision = inf;
iterations = max_iter;
for ii=1:max_iter
    survived = dis*TMsp;
    if any(~isfinite(survived))
        precision = inf;
        iterations = ii;
        return
    end
    dis_new = survived+(1-sum(survived))*entrant;
    dis_new = max(dis_new,0);
    mass = sum(dis_new);
    if ~(mass>0) || ~isfinite(mass)
        precision = inf;
        iterations = ii;
        return
    end
    dis_new = dis_new/mass;
    precision = max(abs(dis_new-dis));
    iterations = ii;
    dis = dis_new;
    if precision<tol
        ok = true;
        return
    end
end
end