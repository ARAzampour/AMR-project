function [trans_prob_o,v_new_o,v_new_resh_o,dist_o,trans_matrix_n,p_e_n,...
    trans_prob_n,v_new_n,v_new_resh_n,dist_n,trans_matrix_o,p_e_o,...
    trans_prob_m,v_new_m,v_new_resh_m,dist_m,trans_matrix_m,p_e_m,...
    age_g,a_grid,a_prob,p_E,m_of_firms_new,m_of_firms_old,m_of_firms_mix,...
    pi_contemp_new,pi_contemp_old,pi_contemp_mix] = ...
    Three_tech_ss(a_grow,alpha,~,beta,c_of_a,c_a_new,a_lamb,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,fco,e_p,d_0,c_of_e,c_e_new,dem_tol,tech_dist,...
    e0_n,e0_o,e_n_eps,e_o_eps,gamma,rho,c_a_mix,c_e_mix)

a_grid  =  expinv(linspace(0,0.999,a_num_g),a_lamb);
a_cdf   = expcdf(a_grid,a_lamb);
a_prob  = [a_cdf(2:a_num_g) 1]-a_cdf;

max_iter_price      = floor(max_iter/100);
max_iter_measure    = max_iter_price*100;
 
age_g   = (linspace(0,age_num-1,age_num))';



policy_choice_n   = zeros(age_num*a_num_g,a_num_g);
policy_choice_o   = zeros(age_num*a_num_g,a_num_g);
policy_choice_m   = zeros(age_num*a_num_g,a_num_g);

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

trans_matrix_m   = sparse(age_num*a_num_g,age_num*a_num_g);
dist_m           = zeros(1,age_num*a_num_g);
v_new_m          = zeros(age_num*a_num_g,1);
v_new_resh_m     = zeros(age_num,a_num_g);
exit_vec_m       = zeros(age_num*a_num_g,'logical');

%%%%%

%%%%%

%%% Here we will have endogenous entry: this means that as long as value of
%%% entrant - the cost of entry is positive there should be entrants. To
%%% solve it I will loop over the whole soltuion till I find the
%%% equilibrium price satisfying this condition; first I start with p_E = 1


p_E         = 1;
p_E_prev    = 1;
dem_err_pre = 0;

%%%% I think we need to have varying price of effort for the techs of
%%%% course it can have an ifinite elasticity like the case of solar, 
%%%% fist set it to be equal for both to one

p_e_n   = 1;
p_e_o   = 1;
p_e_m   = 1;

m_coice = ((1-gamma)*p_e_n/(p_e_o*gamma))^(1/(1-rho));  %%% the ratio of coal to gas use by the mixed ones

% eff_n_vec   = zeros(age_num,a_num_g);
% eff_o_vec   = zeros(age_num,a_num_g); if mex gives error I'll pre define
% them


pi_contemp_new      = ((1+a_grid).*(alpha*p_E/p_e_n)^alpha.*(1/(1+a_grow)).^age_g)...
    .^(1/(1-alpha))*(1-alpha);

%%% I also consider the remainder of the firms that have not transitioned

pi_contemp_old      = ((1+a_grid)/tech_dist.*(alpha*p_E/p_e_o)^alpha.*(1/(1+a_grow)).^age_g)...
    .^(1/(1-alpha))*(1-alpha);

%%% there can also be generators that can use both 

pi_contemp_mix      = ((1+a_grid)/((tech_dist+1)/2).*(alpha*p_E/p_e_m)^alpha.*(1/(1+a_grow)).^age_g)...
    .^(1/(1-alpha))*(1-alpha);   %%% this function is temporary, it changes in
                                %%% the main body of the code


%%% here I'm adding fixed cost of operation to implement exit decision: it
%%% should be calibrated

pi_contemp_new      = pi_contemp_new - fco;
pi_contemp_old      = pi_contemp_old - fco;
pi_contemp_mix      = pi_contemp_mix - fco;

%%% those with negative contemporary profit will exit
pi_contemp_neg_new  = pi_contemp_new<0;
pi_contemp_new(pi_contemp_neg_new) = 0;

pi_contemp_neg_old  = pi_contemp_old<0;
pi_contemp_old(pi_contemp_neg_old) = 0;

pi_contemp_neg_mix  = pi_contemp_mix<0;
pi_contemp_mix(pi_contemp_neg_mix) = 0;




v_of_new = pi_contemp_new;
v_of_old = pi_contemp_old;
v_of_mix = pi_contemp_mix;

%%%% also to have the entry and exit equal to each other the measure of the
%%%% firms should be the correct number

m_of_firms_new  = 1;
m_of_firms_old  = 1;
m_of_firms_mix  = 1;

value_err_n_pre = 0;
value_err_o_pre = 0;
value_err_m_pre = 0;
m_of_new_pre    = 1;
m_of_old_pre    = 1;
m_of_mix_pre    = 1;




for h=1:1:max_iter_measure
    for k=1:1:max_iter_price
        pi_contemp_new      = ((1+a_grid).*(alpha*p_E/p_e_n)^alpha.*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha))*(1-alpha);
        
        cap_contemp_new     = (((1+a_grid).*(alpha*p_E/p_e_n)^alpha.*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha)))';

        eff_n_vec           = (((1+a_grid).*alpha*p_E/p_e_n.*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha)))';
    
        pi_contemp_new      = pi_contemp_new - fco;
    
        pi_contemp_neg_new  = pi_contemp_new<0;
        pi_contemp_new(pi_contemp_neg_new) = 0;



        pi_contemp_old      = ((1+a_grid)/tech_dist.*(alpha*p_E/p_e_o)^alpha.*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha))*(1-alpha);
        
        eff_o_vec           = (((1+a_grid)/tech_dist.*alpha*p_E/p_e_o.*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha)))';
        
        cap_contemp_old     = (((1+a_grid)/tech_dist.*(alpha*p_E/p_e_o)^alpha.*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha)))';
        pi_contemp_old      = pi_contemp_old - fco;
        
        pi_contemp_neg_old  = pi_contemp_old<0;
        pi_contemp_old(pi_contemp_neg_old) = 0;



        eff_m_vec           = (((1+a_grid)/((tech_dist+1)/2).*alpha*p_E*(p_e_o*gamma)^((1-alpha)/(1-rho))/...
            (p_e_o*p_e_n).*(1/(1+a_grow)).^age_g*...
            ((p_e_o^rho*gamma)^(1/(1-rho))+(p_e_n^rho*(1-gamma))^(1/(1-rho)))^((alpha-rho)/rho)).^(1/(1-alpha)))';
        %%% this is the amount of new effort used by the mix generators

        cap_contemp_mix     = (((1+a_grid)/((tech_dist+1)/2)*p_E*(p_e_o*gamma)...
            ^(-alpha/(1-rho)).*(1/(1+a_grow)).^age_g*...
            ((p_e_o^rho*gamma)^(1/(1-rho))+(p_e_n^rho*(1-gamma))^(1/(1-rho)))^(alpha/rho))...
            .*(eff_m_vec.^alpha)')';


        pi_contemp_mix      = cap_contemp_mix'*p_E - eff_m_vec'*(p_e_o*p_e_n)...
            *(p_e_o*gamma)^(-1/(1-rho)) * ...
            ((p_e_o^rho*gamma)^(1/(1-rho))+(p_e_n^rho*(1-gamma))^(1/(1-rho)));

        pi_contemp_mix      = pi_contemp_mix - fco;

        pi_contemp_neg_mix  = pi_contemp_mix<0;
        pi_contemp_mix(pi_contemp_neg_mix) = 0;

        
        
        


        for i1=1:1:max_iter
        
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
        
            v_n_best      = max(v_n_adopt_vec-c_a_new*(1)...
                ,v_p_n_expand);     %%% let's try different adoption costs
        
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
        
            if error<v_tol
                
                fprintf("value function of new converged in %4.1f periods\n",i1);
                break;
            end
        
            v_of_new = v_new_resh_n;
        end
        
        for i2=1:1:max_iter
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
        end
        
        for i3=1:1:max_iter
            v_p_m = v_of_mix';
            v_p_m(:,1:age_num-1)  = v_p_m(:,2:age_num);
            v_p_m(:,age_num)      = 0;            %%% setting the
                                                %%% value of those who don't adopt
                                                %%% at the highest age to zero; it
                                                %%% should also be noted that if a
                                                %%% firm is not adopting, in the
                                                %%% next period it would get the
                                                %%% value of v(age+1,a_i)
        
        
        
            v_p_m_vec     = (v_p_m(:));
            v_p_m_expand  = kron(v_p_m_vec,ones(a_num_g,1));
            v_m_adopt     = kron(ones(age_num,a_num_g),v_of_mix(1,:));
            v_m_adopt_p   = v_m_adopt';
            v_m_adopt_vec = v_m_adopt_p(:);        
        
            v_m_best      = max(v_m_adopt_vec-c_a_mix*(1)...
                ,v_p_m_expand);
        
            v_m_best_resh = (reshape(v_m_best,a_num_g,age_num*a_num_g))';
        
             
            policy_choice_m = 1-(v_m_best_resh==v_p_m_vec);
        
            %%% those who couldn't pay the fco should exit
            exiting_firm_m    = pi_contemp_neg_mix';
            exit_vec_m        = exiting_firm_m(:);
            policy_choice_m   = (1-exit_vec_m).*policy_choice_m;
        
            v_new_m       = v_m_best_resh*a_prob';
            v_new_resh_m  = (reshape(v_new_m,a_num_g,age_num))';
            v_new_resh_m  = pi_contemp_mix + beta*v_new_resh_m;

            v_new_resh_m(pi_contemp_neg_mix) = 0;
        
            error       = max(abs(v_of_mix-v_new_resh_m),[],"all");
        
            if error<v_tol
                
                fprintf("value function of mix converged in %4.1f periods\n",i2);
                break;
            end
        
            v_of_mix = v_new_resh_m;
        end
        %%
        %%% Here I derive the transition matrix; first those who don't adopt go to
        %%% the same technology state with a higher age, those who adopt go the
        %%% technology they adopt with the age zero meaning we have:
        
        trans_matrix_n                  = sparse(a_num_g*age_num,a_num_g*age_num);
        trans_matrix_n(:,1:a_num_g)     = policy_choice_n.*repmat(a_prob,age_num*a_num_g,1).*(1-exit_vec_n);
        prob_of_naot_n                  = sum((1-policy_choice_n).*repmat(a_prob,age_num*a_num_g,1),2);
        state_if_naot_n                 =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
            [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
        trans_matrix_n(state_if_naot_n) = 1*prob_of_naot_n(1:(age_num-1)*a_num_g)...
            .*(1-exit_vec_n(1:(age_num-1)*a_num_g,1));

        trans_matrix_o                  = sparse(a_num_g*age_num,a_num_g*age_num);
        trans_matrix_o(:,1:a_num_g)     = policy_choice_o.*repmat(a_prob,age_num*a_num_g,1).*(1-exit_vec_o);
        prob_of_naot_o                  = sum((1-policy_choice_o).*repmat(a_prob,age_num*a_num_g,1),2);
        state_if_naot_o                 =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
            [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
        trans_matrix_o(state_if_naot_o) = 1*prob_of_naot_o(1:(age_num-1)*a_num_g)...
            .*(1-exit_vec_o(1:(age_num-1)*a_num_g,1));
        

        trans_matrix_m                  = sparse(a_num_g*age_num,a_num_g*age_num);
        trans_matrix_m(:,1:a_num_g)     = policy_choice_m.*repmat(a_prob,age_num*a_num_g,1).*(1-exit_vec_m);
        prob_of_naot_m                  = sum((1-policy_choice_m).*repmat(a_prob,age_num*a_num_g,1),2);
        state_if_naot_m                 =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
            [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
        trans_matrix_m(state_if_naot_m) = 1*prob_of_naot_m(1:(age_num-1)*a_num_g)...
            .*(1-exit_vec_m(1:(age_num-1)*a_num_g,1));
        %%% also those who are at the last period would die if they don't adopt to
        %%% any technology and a new firm would enter with a random technology
        %%% meaning for those states with the highest age the transition would be
        %%% randomly to age 0 and tech in [0, a_max]
        
        trans_matrix_n((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob,a_num_g,1).*(1-exit_vec_n((age_num-1)*a_num_g+1:(age_num)*a_num_g,1));

        trans_matrix_o((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob,a_num_g,1).*(1-exit_vec_o((age_num-1)*a_num_g+1:(age_num)*a_num_g,1));

        trans_matrix_m((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob,a_num_g,1).*(1-exit_vec_m((age_num-1)*a_num_g+1:(age_num)*a_num_g,1));
        
        dist_n          = m_of_firms_new*ones(1,age_num*a_num_g)/(age_num*a_num_g);
        dist_o          = m_of_firms_old*ones(1,age_num*a_num_g)/(age_num*a_num_g);
        dist_m          = m_of_firms_mix*ones(1,age_num*a_num_g)/(age_num*a_num_g);
        dist_ent        = zeros(1,age_num*a_num_g);
        dist_ent(1:a_num_g) = 1/a_num_g;

        
        for j=1:1:max_iter
            dist_new_n    = dist_n *trans_matrix_n;
            dist_new_n    = dist_new_n + (m_of_firms_new-sum(dist_new_n))*dist_ent;
            error       = max(abs(dist_new_n-dist_n));
            if error<dist_tol
                fprintf("distribution of new converged in %4.1f periods\n",j);
                break;
            end
            dist_n        = dist_new_n;
        
        end

        for j=1:1:max_iter
            dist_new_o    = dist_o *trans_matrix_o;
            dist_new_o    = dist_new_o + (m_of_firms_old-sum(dist_new_o))*dist_ent;
            error       = max(abs(dist_new_o-dist_o));
            if error<dist_tol
                fprintf("distribution of old converged in %4.1f periods\n",j);
                break;
            end
            dist_o        = dist_new_o;
        
        end

        for j=1:1:max_iter
            dist_new_m    = dist_m *trans_matrix_m;
            dist_new_m    = dist_new_m + (m_of_firms_mix-sum(dist_new_m))*dist_ent;
            error       = max(abs(dist_new_m-dist_m));
            if error<dist_tol
                fprintf("distribution of mix converged in %4.1f periods\n",j);
                break;
            end
            dist_m        = dist_new_m;
        
        end
        
        total_cap   = dist_n * cap_contemp_new(:) + dist_o * cap_contemp_old(:)...
            + dist_m * cap_contemp_mix(:);
        
        suply_price = (d_0/total_cap)^(1/e_p);
        
        demand_err  = suply_price - p_E;
        
        if abs(demand_err)<dem_tol
            fprintf("demand and supply has converged and the prices is ..." + ...
                "%2.4f in %2.1f periods\n",p_E,k);
            break;
        end
        
        

        p_E     = p_E + 0.04*demand_err/(ceil(k/10));

        if sign(dem_err_pre)~=sign(demand_err)
            p_E = (p_E_prev + p_E)/2;
        end

        p_E_prev    = p_E;
        dem_err_pre = demand_err;

        p_e_n       = ((dist_n * eff_n_vec(:)+dist_m * eff_m_vec(:))/e0_n).^e_n_eps;
        p_e_o       = ((dist_o * eff_o_vec(:)+m_coice*dist_m * eff_m_vec(:))/e0_o).^e_o_eps;

        p_e_m       = ((m_coice*p_e_o+p_e_n)*dist_m * eff_m_vec(:))/...
            (dist_m *(gamma*(eff_m_vec(:)).^rho+(1-gamma)*(m_coice*eff_m_vec(:)).^rho).^(1/rho));
        m_coice     = ((1-gamma)*p_e_n/(p_e_o*gamma))^(1/(1-rho));
        

    end
    value_err_n   = a_prob*(v_new_resh_n(1,:))'-c_e_new; %%% let's try 
                                %%%% different entry cost for techs
    value_err_o   = a_prob*(v_new_resh_o(1,:))'-c_of_e;

    value_err_m   = a_prob*(v_new_resh_m(1,:))'-c_e_mix;

    

    if abs(value_err_n)>0.5
        m_of_firms_new = m_of_firms_new*(1+0.05*value_err_n/ceil(h/10));
    else
        m_of_firms_new = m_of_firms_new*(1+0.1*value_err_n/ceil(h/10));
    end
    if abs(value_err_o)>0.5
        m_of_firms_old = m_of_firms_old*(1+0.05*value_err_o/ceil(h/10));
    else
        m_of_firms_old = m_of_firms_old*(1+0.1*value_err_o/ceil(h/10));
    end
    if abs(value_err_m)>0.5
        m_of_firms_mix = m_of_firms_mix*(1+0.05*value_err_m/ceil(h/10));
    else
        m_of_firms_mix = m_of_firms_mix*(1+0.1*value_err_m/ceil(h/10));
    end


    if sign(value_err_n_pre) ~= sign(value_err_n)
        m_of_firms_new = (m_of_firms_new+m_of_new_pre)/2;
    end
    if sign(value_err_o_pre) ~= sign(value_err_o)
        m_of_firms_old = (m_of_firms_old+m_of_old_pre)/2;
    end
    if sign(value_err_m_pre) ~= sign(value_err_m)
        m_of_firms_mix = (m_of_firms_mix+m_of_mix_pre)/2;
    end

    if ((abs(value_err_n)<dem_tol||m_of_firms_new<v_tol) && ...
            (abs(value_err_o)<dem_tol||m_of_firms_old<v_tol) && ...
            (abs(value_err_m)<dem_tol||m_of_firms_mix<v_tol))||...
            (abs(1-m_of_new_pre/m_of_firms_new)<10*v_tol && ...
            abs(1-m_of_old_pre/m_of_firms_old)<10*v_tol...
            && abs(1-m_of_mix_pre/m_of_firms_mix)<10*v_tol && h>100)
        fprintf("entry and exit have converged and E(v_new) and E(v_old) ..." + ...
            "is %2.4f and %2.4f in %2.1f periods \n"...
            ,value_err_n,value_err_o,h);
        break;
    end
    

    value_err_n_pre = value_err_n;
    value_err_o_pre = value_err_o;
    value_err_m_pre = value_err_m;
    m_of_new_pre    = m_of_firms_new;
    m_of_old_pre    = m_of_firms_old;
    m_of_mix_pre    = m_of_firms_mix;
end

trans_prob_n    = policy_choice_n*a_prob';
trans_prob_o    = policy_choice_o*a_prob';
trans_prob_m    = policy_choice_m*a_prob';
end