function error = simulator(a_grow,alpha,a_bar,beta,c_of_a,c_a_new,...
        mu_old,sigma_old,mu_new,sigma_new,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,fco_o,fco_n,e_p,d_0,c_of_e,c_e_new,dem_tol,tech_dist,...
        e0_n,e0_o,e_n_eps,e_o_eps,rho,age_reduc,exo_exit,e_max,gamma,rat,...
        p_E_m,p_e_n_m,p_e_o_m,inp_ratio,m_ratio,mean_eff,feul_ce_ratio,M_cap_age)
global tracks JJ
JJ  = JJ+1;

age_reduc    = floor(age_reduc);

tracks(1,JJ) = alpha;
tracks(2,JJ) = c_of_a;
tracks(3,JJ) = c_a_new;
tracks(4,JJ) = d_0;
tracks(5,JJ) = e0_n;
tracks(6,JJ) = e0_o;
tracks(7,JJ) = rat;
tracks(8,JJ) = age_reduc;
save tracks tracks
[trans_prob_old,~,~,dist_o,trans_matrix_n,p_e_n,cap_contemp_new,eff_n_final,...
        trans_prob_n_1st,~,~,dist_n,trans_matrix_old,p_e_o,cap_contemp_old,eff_o_final,...
        age_g,a_grid_old,a_prob_old,a_grid_new,a_prob_new,pi_contemp_new_1st,p_E,m_of_firms_new,m_of_firms_old,...
        exit_n_1st,exit_o_1st] = ...
        Two_tech_ss_AC2(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new,...
        mu_old,sigma_old,mu_new,sigma_new,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0/tech_dist,rat*c_of_e,rat*c_e_new,dem_tol,tech_dist,...
        e0_n,e0_o,e_n_eps,e_o_eps,rho,age_reduc,exo_exit,e_max,gamma);

eff_grid_expan_o= ((a_grid_old)./((1+a_grow).^age_g))';
eff_grid_expan_n= ((a_grid_new)./((1+a_grow).^age_g))';

avr_cap_age     = ((dist_o+dist_n)*kron(age_g,ones(a_num_g,1)))/2;

inp_rat_model   = (dist_o*eff_o_final)/(dist_n*eff_n_final);
m_rat_model     = m_of_firms_old/m_of_firms_new;
mean_eff_model  = (dist_n*eff_grid_expan_n(:)+dist_o*eff_grid_expan_o(:)/tech_dist)/...
    sum(dist_n+dist_o);
fe_ce_rat_model = dist_n*eff_n_final*p_e_n/(rat*c_e_new*sum(dist_n));

error   = (p_E_m-p_E)^2/p_E_m + (p_e_n_m-p_e_n)^2/p_e_n_m + (p_e_o_m-p_e_o)^2/p_e_o_m ...
    + (mean_eff-mean_eff_model)^2/mean_eff + (m_ratio-m_rat_model)^2/m_ratio ...
    + (inp_ratio - inp_rat_model)^2/inp_ratio + (feul_ce_ratio - fe_ce_rat_model)^2/feul_ce_ratio+...
    +(avr_cap_age-M_cap_age)^2/M_cap_age;

tracks(9,JJ)    = p_E;
tracks(10,JJ)    = p_e_n;
tracks(11,JJ)   = p_e_o;
tracks(12,JJ)   = mean_eff_model;
tracks(13,JJ)   = m_rat_model;
tracks(14,JJ)   = inp_rat_model;
tracks(15,JJ)   = fe_ce_rat_model;
tracks(16,JJ)   = avr_cap_age;
tracks(17,JJ)   = error;
save tracks tracks
end