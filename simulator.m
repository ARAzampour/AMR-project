function error = simulator(a_grow,alpha,a_bar,beta,c_of_a,c_a_new,mu,sigma,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,fco_o,fco_n,e_p,d_0,c_of_e,c_e_new,dem_tol,tech_dist,...
        e0_n,e0_o,e_n_eps,e_o_eps,rho,age_reduc,exo_exit,e_max,gamma,rat,...
        p_E_m,p_e_n_m,p_e_o_m,inp_ratio,m_ratio,mean_eff,feul_ce_ratio)
global tracks JJ
JJ  = JJ+1;
tracks(1,JJ) = alpha;
tracks(2,JJ) = c_of_a;
tracks(3,JJ) = c_a_new;
tracks(4,JJ) = d_0;
tracks(5,JJ) = e0_n;
tracks(6,JJ) = e0_o;
tracks(7,JJ) = rat;
save tracks tracks
[trans_prob_old,~,~,dist_o,trans_matrix_n,p_e_n,cap_contemp_new,eff_n_final,...
        trans_prob_n_1st,~,~,dist_n,trans_matrix_old,p_e_o,cap_contemp_old,eff_o_final,...
        age_g,a_grid,a_prob,pi_contemp_new_1st,p_E,m_of_firms_new,m_of_firms_old,...
        exit_n_1st,exit_o_1st] = ...
        Two_tech_ss_AC(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new,mu,sigma,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0/tech_dist,rat*c_of_e,rat*c_e_new,dem_tol,tech_dist,...
        e0_n,e0_o,e_n_eps,e_o_eps,rho,age_reduc,exo_exit,e_max,gamma);

eff_grid_expan  = ((a_grid)./((1+a_grow).^age_g))';
inp_rat_model   = (dist_o*eff_o_final)/(dist_n*eff_n_final);
m_rat_model     = m_of_firms_old/m_of_firms_new;
mean_eff_model  = (dist_n*eff_grid_expan(:)+dist_o*eff_grid_expan(:)/tech_dist)/...
    sum(dist_n+dist_o);
fe_ce_rat_model = dist_n*eff_grid_expan(:)*p_e_n/(rat*c_e_new*sum(dist_n));

error   = (p_E_m-p_E)^2/p_E_m + (p_e_n_m-p_e_n)^2/p_e_n_m + (p_e_o_m-p_e_o)^2/p_e_o_m ...
    + (mean_eff-mean_eff_model)^2/mean_eff + (m_ratio-m_rat_model)^2/m_ratio ...
    + (inp_ratio - inp_rat_model)^2/inp_ratio + (feul_ce_ratio - fe_ce_rat_model)^2/feul_ce_ratio;

tracks(8,JJ)    = p_E;
tracks(9,JJ)    = p_e_n;
tracks(10,JJ)   = p_e_o;
tracks(11,JJ)   = mean_eff_model;
tracks(12,JJ)   = m_rat_model;
tracks(13,JJ)   = inp_rat_model;
tracks(14,JJ)   = fe_ce_rat_model;
tracks(15,JJ)   = error;
save tracks tracks
end