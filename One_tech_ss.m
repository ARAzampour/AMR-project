function [policy_choice,v_new,v_new_resh,dist,trans_matrix,age_g,a_grid,a_prob,pi_contemp] = ...
    One_tech_ss(a_grow,alpha,a_bar,beta,c_of_a,a_lamb,p_e,a_num_g,age_num,max_iter,...
    v_tol,dist_tol)

a_grid  =  expinv(linspace(0,0.999,a_num_g),a_lamb);
a_cdf   = expcdf(a_grid,a_lamb);
a_prob  = [a_cdf(2:a_num_g) 1]-a_cdf;


 
age_g   = (linspace(0,age_num-1,age_num))';




policy_choice   = zeros(age_num*a_num_g,a_num_g);

pi_contemp      = ((1+a_grid).*(alpha/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
    .^(1/(1-alpha))*(1-alpha);

% a_prob_3d           = zeros(1,1,a_num_g);
% a_prob_3d(1,1,:)    = a_prob;


v = pi_contemp;

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
    v_adopt     = kron(ones(age_num,a_num_g),v(1,:));
    v_adopt_p   = v_adopt';
    v_adopt_vec = v_adopt_p(:);        


    v_best      = max(v_adopt_vec-c_of_a*(1+(kron([1:age_num],ones(1,a_num_g^2)))'/a_bar)...
        ,v_p_expand);
    v_best_resh = (reshape(v_best,a_num_g,age_num*a_num_g))';

     
    policy_choice = 1-(v_best_resh==v_p_vec);

    v_new       = v_best_resh*a_prob';
    v_new_resh  = (reshape(v_new,a_num_g,age_num))';
    v_new_resh  = pi_contemp + beta*v_new_resh;

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

trans_matrix    = zeros(a_num_g*age_num,a_num_g*age_num);
trans_matrix(:,1:a_num_g) = policy_choice.*repmat(a_prob,age_num*a_num_g,1);
prob_of_naot    = sum((1-policy_choice).*repmat(a_prob,age_num*a_num_g,1),2);
state_if_naot   =  kron([1:age_num-1],ones(1,a_num_g))*age_num*a_num_g^2+...
    [1:(age_num-1)*a_num_g]+kron(ones(1,age_num-1),[0:a_num_g-1])*age_num*a_num_g;
trans_matrix(state_if_naot) = 1*prob_of_naot(1:(age_num-1)*a_num_g);

%%% also those who are at the last period would die if they don't adopt to
%%% any technology and a new firm would enter with a random technology
%%% meaning for those states with the highest age the transition would be
%%% randomly to age 0 and tech in [0, a_max]

trans_matrix((age_num-1)*a_num_g+1:age_num*a_num_g,1:a_num_g) = repmat(a_prob,a_num_g,1);
trans_matrix = sparse(trans_matrix);

dist = ones(1,age_num*a_num_g)/(age_num*a_num_g);

for j=1:1:max_iter
    dist_new    = dist *trans_matrix;
    error       = max(abs(dist_new-dist));
    if error<dist_tol
        fprintf("distribution converged in %4.1f periods\n",j);
        break;
    end
    dist        = dist_new;

end



end