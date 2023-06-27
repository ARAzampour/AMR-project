function [trans_prob,v_new,v_new_resh,dist,trans_matrix,...
    age_g,a_grid,a_prob,pi_contemp,p_E,m_of_firms] = ...
    One_tech_ss_AC(a_grow,alpha,~,beta,c_of_a,a_lamb,p_e,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,fco,e_p,d_0,c_of_e,dem_tol,rho,age_reduc)

a_grid  =  expinv(linspace(0,0.999,a_num_g),a_lamb);
a_cdf   = expcdf(a_grid,a_lamb);
a_prob  = [a_cdf(2:a_num_g) 1]-a_cdf;

prob_matrix         = auto_corr_prob(a_grid,a_prob,rho);

max_iter_price      = floor(max_iter/100);
max_iter_measure    = max_iter_price;
 
age_g   = (linspace(0,age_num-1,age_num))';

%%%%% these should be predefined for mex purposes

trans_matrix    = sparse(age_num*a_num_g,age_num*a_num_g);
dist            = zeros(1,age_num*a_num_g);
v_new           = zeros(age_num*a_num_g,1);
v_new_resh      = zeros(age_num,a_num_g);
exit_vec = zeros(age_num*a_num_g,'logical');

%%%%%
policy_choice   = zeros(age_num*a_num_g,a_num_g);


%%% Here we will have endogenous entry: this means that as long as value of
%%% entrant - the cost of entry is positive there should be entrants. To
%%% solve it I will loop over the whole soltuion till I find the
%%% equilibrium price satisfying this condition; first I start with p_E = 1


p_E         = 1;
p_E_prev    = 1;
dem_err_pre = 0;




pi_contemp      = ((1+a_grid).*(alpha*p_E/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
    .^(1/(1-alpha))*(1-alpha);

% cap_contemp     = (((1+a_grid).*(alpha*p_E/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
%     .^(1/(1-alpha)))';

%%% here I'm adding fixed cost of operation to implement exit decision: it
%%% should be calibrated

pi_contemp      = pi_contemp - fco;

%%% those with negative contemporary profit will exit
% pi_contemp_neg  = pi_contemp<0;
% pi_contemp(pi_contemp_neg) = 0;


% a_prob_3d           = zeros(1,1,a_num_g);
% a_prob_3d(1,1,:)    = a_prob;


v = pi_contemp;


%%%% also to have the entry and exit equal to each other the measure of the
%%%% firms should be the correct number

m_of_firms      = 1;
value_err_pre   = 0;
m_of_firm_pre   = 1;


for h=1:1:max_iter_measure
    for k=1:1:max_iter_price
        pi_contemp      = ((1+a_grid).*(alpha*p_E/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha))*(1-alpha);
        
        cap_contemp     = (((1+a_grid).*(alpha*p_E/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
            .^(1/(1-alpha)))';
    
        pi_contemp      = pi_contemp - fco;
    
%         pi_contemp_neg  = pi_contemp<0;
%         pi_contemp(pi_contemp_neg) = 0;

        for i=1:1:max_iter
        
            v_p = v';
            v_p(:,1:age_num-1)  = v_p(:,2:age_num);
            v_p(:,age_num)      = 0;            %%% setting the
                                                %%% value of those who don't adopt
                                                %%% at the highest age to zero; it
                                                %%% should also be noted that if a
                                                %%% firm is not adopting, in the
                                                %%% next period it would get the
                                                %%% value of v(age+1,a_i)
        
        
        
            v_p_vec     = (v_p(:));
            v_p_expand  = kron(v_p_vec,ones(a_num_g,1));
            v_adopt     = [kron(ones(age_reduc,a_num_g),v(1,:));...
                kron(ones(1,a_num_g),v(1:end-age_reduc,:))];
            v_adopt_p   = v_adopt';
            v_adopt_vec = v_adopt_p(:);        
        
        
        %     v_best      = max(v_adopt_vec-c_of_a*(1+(kron([1:age_num],ones(1,a_num_g^2)))'/a_bar)...
        %         ,v_p_expand);
            %%%% with fixed cost of operation I'm not sure if we need the
            %%%% increasing with time cost of adoptation
            v_best      = max(v_adopt_vec-c_of_a*(1)...
                ,v_p_expand);
        
            v_best_resh = (reshape(v_best,a_num_g,age_num*a_num_g))';
        
             
            policy_choice = 1-(v_best_resh==v_p_vec);
        
            %%% those who get non-positive npv should exit
            v_neg           = v<0; 
            exiting_firm    = v_neg';
            exit_vec        = exiting_firm(:);
            policy_choice   = repmat(1-exit_vec,1,a_num_g).*policy_choice;
        
            v_new       = sum(v_best_resh.*repmat(prob_matrix,age_num,1),2);
            v_new_resh  = (reshape(v_new,a_num_g,age_num))';
            v_new_resh  = pi_contemp + beta*v_new_resh;

            v_new_resh(v_neg)           = 0;
            v_new_resh(v_new_resh<0)    = 0;
        
            error       = max(abs(v-v_new_resh),[],"all");
        
            if error<v_tol
                
                fprintf("value function converged in %4.1f periods\n",i);
                break;
            end
        
            v = v_new_resh;
        

        end
        
        
        %%
        %%% Here I derive the transition matrix; first those who don't adopt go to
        %%% the same technology state with a higher age, those who adopt go the
        %%% technology they adopt with the age zero meaning we have:

%         p_of_naot_besideold           = zeros((age_num-1)*a_num_g,1);
        temp                          = exit_vec(1:(age_num-1)*a_num_g,1);
        state_if_adopt                = zeros(1,a_num_g*age_num*a_num_g);
        state_if_adopt(1:age_reduc*a_num_g*a_num_g)     = ...
            repmat(1:1:age_reduc*a_num_g,1,a_num_g)...
            + kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,age_reduc*a_num_g));
        if age_reduc<age_num
        state_if_adopt(age_reduc*a_num_g*a_num_g+1:end) = ...
            kron(age_reduc*a_num_g+(0:1:(age_num-age_reduc-1))*a_num_g,ones(1,a_num_g^2)) +...
            repmat(1:1:a_num_g,1,(age_num-age_reduc)*a_num_g)+...
            kron((0:1:a_num_g*(age_num-age_reduc-1)+a_num_g-1),a_num_g*age_num*ones(1,a_num_g));
        end

        temp_address                  = zeros(1,a_num_g*age_num*a_num_g);
        temp_address(1:age_reduc*a_num_g*a_num_g)       = ...
            repmat(1:1:age_reduc*a_num_g,1,a_num_g)...
            + kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,age_reduc*a_num_g));
        if age_reduc<age_num
        temp_address(age_reduc*a_num_g*a_num_g+1:end)   = ...
            kron(age_reduc*a_num_g+(0:1:(age_num-age_reduc-1))*a_num_g,ones(1,a_num_g^2)) +...
            repmat(1:1:a_num_g,1,(age_num-age_reduc)*a_num_g)+...
            repmat(kron(0:1:a_num_g-1,a_num_g*age_num*ones(1,(a_num_g))),1,age_num-age_reduc);
        end

        trans_matrix                  = sparse(a_num_g*age_num,a_num_g*age_num);
        temp_matrix                   = policy_choice.*repmat(prob_matrix,age_num,1).*(1-exit_vec);
        trans_matrix(state_if_adopt)  = temp_matrix(temp_address);
        prob_of_naot                  = sum((1-policy_choice).*repmat(prob_matrix,age_num,1),2);
        state_if_naot                 =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
            [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
        p_of_naot_besideold           = ones((age_num-1)*a_num_g,1).*prob_of_naot(1:(age_num-1)*a_num_g);
        stay_alive_besideold          = (ones((age_num-1)*a_num_g,1)-temp);
        trans_matrix(state_if_naot)   = p_of_naot_besideold.*stay_alive_besideold;
            
            
    

        
        %%% also those who are at the last period would die if they don't adopt to
        %%% any technology and a new firm would enter with a random technology
        %%% meaning for those states with the highest age the transition would be
        %%% randomly to age 0 and tech in [0, a_max]
        
        trans_matrix((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = ...
                repmat(a_prob,a_num_g,1).*(1-exit_vec((age_num-1)*a_num_g+1:(age_num)*a_num_g,1));
        
        dist        = m_of_firms*ones(1,age_num*a_num_g)/(age_num*a_num_g);
        dist_ent    = zeros(1,age_num*a_num_g);
        dist_ent(1:a_num_g) = 1/a_num_g;

        
        for j=1:1:max_iter
            dist_new    = dist *trans_matrix;
            dist_new    = dist_new + (m_of_firms-sum(dist_new))*dist_ent;
            error       = max(abs(dist_new-dist));
            if error<dist_tol
                fprintf("distribution converged in %4.1f periods\n",j);
                break;
            end
            dist        = dist_new;
        
        end
        
        total_cap   = dist * cap_contemp(:);
        
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
    end
    value_err   = a_prob*(v_new_resh(1,:))'-c_of_e;
    if abs(value_err)<dem_tol
        fprintf("entry and exit have converged and E(v) is %2.4f in %2.1f periods \n"...
            ,value_err,h);
        break;
    end
    if value_err>-5
        m_of_firms = m_of_firms*(1+0.1*value_err);
    else
        m_of_firms = m_of_firms*(1+0.05*value_err);
    end

    if sign(value_err_pre) ~= sign(value_err)
        m_of_firms = (m_of_firms+m_of_firm_pre)/2;
    end

    value_err_pre   = value_err;
    m_of_firm_pre   = m_of_firms;
end
trans_prob  = policy_choice*a_prob';
end