%%%% Power plants' dynamics: Alireza and Maija

%%% let's start with only one technology, I assume that after 100 period a
%%% plant would for sure adopt a new technology meaning that we should have
%%% the policy of the plant for a set of [0 age_num] years * [a_l a_L]


clear
close
clc

%%
a_bar   = 1;
beta    = 0.97;

max_iter    = 30000;
v_tol       = 10^-5;
dist_tol    = 10^-7;

a_grow      = 0.005; %%% obsoletion rate of generators

e_n_eps = 0.8;
e_o_eps = 1.1;  %%% elasticites of fuel price supply from literature

alpha   = 1.9;  %%% estimated from the data, not in the calibration anymore 1/5/2026
p_e     = 1;
mu      = 0.35;
sigma   = sqrt(0.023^2);
mu2     = 0.51;
sigma2  = sqrt(0.025^2); %%% these are used for cc generators
a_num_g = 50;
age_num = 80;


fco_o   = 3;    %%% there are different types of old (boiler based) and new
                %%% (combustion based) generator. The ratio of their O&M
                %%% cost is between 2 and 4. We pick 3 and check for the
                %%% sensivity
fco_n   = 1;
e_p     = 0.75; %%% this demand elasticity is estimated around between 0.5 
                %%% and 1 and we set it to 0.75 in the literature
                %%% 

d_0     = 100;   %%% what should this value be?? it has profound effect on 
                %%% the final distribution of the firms due to low
                %%% elacticity of demand
c_of_e  = 130;  %%% there are different types of old (boiler based) and new
                %%% (combustion based) generator. The ratio of their
                %%% Overhead cost (installation, entry cost) therefore can
                %%% vary too both with respect to each other and their own
                %%% fco. We pick these numbers from the average but we'll
                %%% check for sensitivity
c_e_new_pre_cc = 80 ;  %%%% setting a different entry cost for the new tech 
                %%%% might be a solution to get a two tech SS; for gas and
                %%%% coal case they will be set to be the same
dem_tol = 0.01;





%%% auto correlation case parameters
rho         = 0.6;


%%% branch-specific input price processes used by p_input_grid
rho_p_n     = 0.95;
sigma_p_n   = 0.2;%0.25
rho_p_o     = 0.95;
sigma_p_o   = 0.2;%0.15


%%% exogenous exit
exo_exit    = 0.01;

%%% maximum input is put in place since there is naturally a maximum input
%%% that a generator can take in

e_max       = 30; %%% it's uselesss now


%%% we have set that generators with a higher initial efficiency would
%%% depreciate slower, this incorporated using ((a_grid).^gamma).^t
 
gamma       = -0.0189; %%% it's uselesss now




%% Load calibration and initial steady state
%%% Calibration is now run externally. The calibration file can either contain
%%% named parameters or a vector named best_calibration / track0 with:
%%% [alpha, c_of_a, c_a_new, d_0, e0_n_1st, e0_o, rat, age_reduc].
%%%p_E_m = 35; p_e_n_m = 12; p_e_o_m = 3.4;  %%% these numbers come from the papers
%%% in the literature (cited withthe help of gpt)
% inp_ratio = 7; m_ratio = 3;
% mean_eff = 0.37; tech_dist   = 1; feul_ce_ratio = 0.085; M_cap_age = 6.1;
mu_old  = mu;
mu_new0 = mu_old-0.05;
% calibration_file = "best_calibration_coal_gas.mat";
% first_ss_file    = "first_ss_coal_gas.mat";

% if exist(calibration_file,"file") ~= 2
%     error("Missing calibration file %s. Save the server calibration output under this name or update calibration_file.",calibration_file);
% end


load("calibration_file.mat")
if isfield(calib,"best_calibration")
    track0 = calib.best_calibration(:);
elseif isfield(calib,"track0")
    track0 = calib.track0(:);
elseif isfield(calib,"tracks")
    valid_cols = find(calib.tracks(17,:)~=0);
    [~,best_loc] = min(calib.tracks(17,valid_cols));
    track0 = calib.tracks(:,valid_cols(best_loc));
end

if exist("track0","var")
    alpha       = track0(1);
    c_of_a      = track0(2);
    c_a_new_pre_cc = track0(3);
    d_0         = track0(4);
    e0_n_1st    = track0(5);
    e0_o        = track0(6);
    rat         = track0(7);
    age_reduc   = floor(track0(8));
else
    required_calib = {'alpha','c_of_a','c_a_new','d_0','e0_n_1st','e0_o','rat','age_reduc'};
    for rr = 1:numel(required_calib)
        if ~isfield(calib,required_calib{rr})
            error("Calibration file must contain %s or best_calibration/track0.",required_calib{rr});
        end
    end
    alpha       = calib.alpha;
    c_of_a      = calib.c_of_a;
    c_a_new_pre_cc = calib.c_a_new;
    d_0         = calib.d_0;
    e0_n_1st    = calib.e0_n_1st;
    e0_o        = calib.e0_o;
    rat         = calib.rat;
    age_reduc   = floor(calib.age_reduc);
end

c_a_new     = c_a_new_pre_cc*0.5;  %%% the drop in the adoption cost of the
                %%% average entrant
c_e_new     = c_e_new_pre_cc*0.5;  %%% the drop in the installation cost of the
                %%% average entrant

e0_n_post_shale = e0_n_1st*1.75; %%% the change in the baseline supply as a 
                %%% result of the shale boom


try
    load("ss_gas_coal0.mat");
    
catch
    [trans_prob_o0,v_new_o0,v_new_resh_old,dist_old,trans_matrix_n0,p_e_n_1st,cap_contemp_n0,eff_n_final0,...
    trans_prob_n0,v_new_n0,v_new_resh_n_1st,dist_n_1st,trans_matrix_o0,p_e_o_1st,cap_contemp_o0,eff_o_final0,...
    age_g,a_grid_old,a_prob_o0,a_grid_n0,a_prob_n0,...
    pi_contemp_new0,p_E_old,m_of_firms_new0,m_of_firms_old0,exit_n_final0,exit_o_final0] = ...
    Two_tech_ss_AC2(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new_pre_cc,mu,sigma,mu_new0,sigma,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0,rat*c_of_e,rat*c_e_new_pre_cc,dem_tol,1,...
    e0_n_1st,e0_o,e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,e_max,gamma);

    save ss_gas_coal0 trans_prob_o0 v_new_o0 v_new_resh_old dist_old trans_matrix_n0 p_e_n_1st cap_contemp_n0 eff_n_final0 ...
    trans_prob_n0 v_new_n0 v_new_resh_n_1st dist_n_1st trans_matrix_o0 p_e_o_1st cap_contemp_o0 eff_o_final0 ...
    age_g a_grid_old a_prob_o0 a_grid_n0 a_prob_n0 ...
    pi_contemp_new0 p_E_old m_of_firms_new0 m_of_firms_old0 exit_n_final0 exit_o_final0
end

%% MIT and shock parameters
trans_t1 = 80;   % CC installation cost decline + first efficiency gain
trans_t2 = 80;   % pure CC efficiency gain
trans_t3 = 80;   % shale gas input-cost shock
d0_gr    = 0.01;

diff_gr_t1  = 10;
diff_gr_t2  = 10;
diff_gr_t3  = 1;
diff_gr1    = 0.00;
diff_gr2    = 0.00;
diff_gr3    = 0.0;

sec_trans_t = 15;
thi_trans_t = 10; %%% the starting time of the second and third transitions



mu_vec1     = [linspace(mu_new0,mu,diff_gr_t1),mu*ones(1,trans_t1-diff_gr_t1)];
mu_vec2     = [linspace(mu,mu2,diff_gr_t2),mu2*ones(1,trans_t2-diff_gr_t2)];
mu_vec3     = ones(1,trans_t3)*mu2;

sigma_vec1  = ones(1,trans_t1)*sigma;
sigma_vec2  = [linspace(sigma,sigma2,diff_gr_t2),sigma2*ones(1,trans_t2-diff_gr_t2)];
sigma_vec3  = ones(1,trans_t3)*sigma2;

tech_dist_ss0 = 1;
tech_dist_ss1 = 1;
tech_dist_ss2 = 1;
tech_dist_ss3 = 1;

c_conver  = 20;
conv_rate = 0.15;
penalty_p = 1;
penalty_n = 1;
penalty_o = 1;

n_PE = 50;
n_pe = 10;
P_E_grid_norm   = P_E_grid(n_PE,1);
p_e_n_grid_norm = p_input_grid(n_pe,1,sigma_p_n,rho_p_n);
p_e_o_grid_norm = p_input_grid(n_pe,1,sigma_p_o,rho_p_o);

%% SS1: CC installation cost decline + first new-tech efficiency gain
try 
    load ss_gas_coal1
catch
    [trans_prob_o1,v_new_o1,v_new_resh_o1,dist_o1,trans_matrix_n1,p_e_n1,cap_contemp_n1,eff_n_final1,...
        trans_prob_n1,v_new_n1,v_new_resh_n1,dist_n1,trans_matrix_o1,p_e_o1,cap_contemp_o1,eff_o_final1,...
        age_g1,a_grid_o1,a_prob_o1,a_grid_n1,a_prob_n1,...
        pi_contemp_new1,p_E1,m_of_firms_new1,m_of_firms_old1,exit_n_final1,exit_o_final1] = ...
        Two_tech_ss_AC2(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new,mu,sigma,mu2,sigma2,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0*(1+d0_gr)^trans_t1/(tech_dist_ss1^(1/(1-alpha))),...
        rat*c_of_e,rat*c_e_new,dem_tol,tech_dist_ss1,...
        e0_n_1st/(tech_dist_ss1^(1/(1-alpha))),e0_o/(tech_dist_ss1^(1/(1-alpha))),...
        e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,e_max,gamma);

    save ss_gas_coal1 trans_prob_o1 v_new_o1 v_new_resh_o1 dist_o1 trans_matrix_n1 p_e_n1 cap_contemp_n1 eff_n_final1 ...
        trans_prob_n1 v_new_n1 v_new_resh_n1 dist_n1 trans_matrix_o1 p_e_o1 cap_contemp_o1 eff_o_final1 ...
        age_g1 a_grid_o1 a_prob_o1 a_grid_n1 a_prob_n1 ...
        pi_contemp_new1 p_E1 m_of_firms_new1 m_of_firms_old1 exit_n_final1 exit_o_final1
end
%% SS2: pure new-tech efficiency gain
try
    load ss_gas_coal2
catch
    [trans_prob_o2,v_new_o2,v_new_resh_o2,dist_o2,trans_matrix_n2,p_e_n2,cap_contemp_n2,eff_n_final2,...
        trans_prob_n2,v_new_n2,v_new_resh_n2,dist_n2,trans_matrix_o2,p_e_o2,cap_contemp_o2,eff_o_final2,...
        age_g2,a_grid_o2,a_prob_o2,a_grid_n2,a_prob_n2,...
        pi_contemp_new2,p_E2,m_of_firms_new2,m_of_firms_old2,exit_n_final2,exit_o_final2] = ...
        Two_tech_ss_AC2(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new,mu,sigma,mu2,sigma2,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0*(1+d0_gr)^(sec_trans_t+trans_t2)/(tech_dist_ss2^(1/(1-alpha))),...
        rat*c_of_e,rat*c_e_new,dem_tol,tech_dist_ss2,...
        e0_n_1st/(tech_dist_ss2^(1/(1-alpha))),e0_o/(tech_dist_ss2^(1/(1-alpha))),...
        e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,e_max,gamma);

    save ss_gas_coal2 trans_prob_o2 v_new_o2 v_new_resh_o2 dist_o2 trans_matrix_n2 p_e_n2 cap_contemp_n2 eff_n_final2 ...
        trans_prob_n2 v_new_n2 v_new_resh_n2 dist_n2 trans_matrix_o2 p_e_o2 cap_contemp_o2 eff_o_final2 ...
        age_g2 a_grid_o2 a_prob_o2 a_grid_n2 a_prob_n2 ...
        pi_contemp_new2 p_E2 m_of_firms_new2 m_of_firms_old2 exit_n_final2 exit_o_final2
end
%% SS3: shale gas input-cost shock
try
    load ss_gas_coal3

catch

    [trans_prob_o3,v_new_o3,v_new_resh_o3,dist_o3,trans_matrix_n3,p_e_n3,cap_contemp_n3,eff_n_final3,...
    trans_prob_n3,v_new_n3,v_new_resh_n3,dist_n3,trans_matrix_o3,p_e_o3,cap_contemp_o3,eff_o_final3,...
    age_g3,a_grid_o3,a_prob_o3,a_grid_n3,a_prob_n3,...
    pi_contemp_new3,p_E3,m_of_firms_new3,m_of_firms_old3,exit_n_final3,exit_o_final3] = ...
    Two_tech_ss_AC2(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new,mu,sigma,mu2,sigma2,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0*(1+d0_gr)^(sec_trans_t+thi_trans_t+trans_t3)/(tech_dist_ss3^(1/(1-alpha))),...
    rat*c_of_e,rat*c_e_new,dem_tol,tech_dist_ss3,...
    e0_n_post_shale/(tech_dist_ss3^(1/(1-alpha))),e0_o/(tech_dist_ss3^(1/(1-alpha))),...
    e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,e_max,gamma);

    save ss_gas_coal3 trans_prob_o3 v_new_o3 v_new_resh_o3 dist_o3 trans_matrix_n3 p_e_n3 cap_contemp_n3 eff_n_final3 ...
    trans_prob_n3 v_new_n3 v_new_resh_n3 dist_n3 trans_matrix_o3 p_e_o3 cap_contemp_o3 eff_o_final3 ...
    age_g3 a_grid_o3 a_prob_o3 a_grid_n3 a_prob_n3 ...
    pi_contemp_new3 p_E3 m_of_firms_new3 m_of_firms_old3 exit_n_final3 exit_o_final3
end

save ss_gas_coal_three_phase

%% MIT1: CC installation cost decline + first efficiency gain
c_a_new_vec1 = c_a_new + (c_a_new_pre_cc-c_a_new)*exp(linspace(0,-40,trans_t1));
c_e_new_vec1 = c_e_new + (c_e_new_pre_cc-c_e_new)*exp(linspace(0,-40,trans_t1));
e0_n_vec1    = e0_n_1st*ones(1,trans_t1);

a_eff_n0    = a_grid_n0' .* max(1 - a_grow .* age_g', 0);
a_eff_o0    = a_grid_old' .* max(1 - a_grow .* age_g', 0);
[eff_n_vec, ~] = static_solver(a_eff_n0, p_E_old.*P_E_grid_norm, p_e_n_1st.*p_e_n_grid_norm, alpha, fco_n, 1./a_grid_n0(:));
[eff_o_vec, ~] = static_solver(a_eff_o0, p_E_old.*P_E_grid_norm, p_e_o_1st.*p_e_o_grid_norm, alpha, fco_o, 1./a_grid_old(:));
init_input_n = dist_n_1st * eff_n_vec(:);
init_input_o = dist_old * eff_o_vec(:);
try
    load ss_gas_coal_1stMIT
catch
    [trans_prob_o_all1,v_new_resh_o_all1,dist_o_all1,measure_vec_o1,p_e_o_vec1,input_all_o1,...
        trans_prob_n_all1,v_new_resh_n_all1,dist_n_all1,measure_vec_n1,p_e_n_vec1,input_all_n1,...
        age_g_mit1,a_grid_mit1,a_prob_mit1,a_grid_n_all1,a_prob_n_all1,p_E_vec1,cap_old1,cap_new1] =...
        MIT_transition_AC(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new_vec1,mu_old,sigma,...
        mu_vec1,sigma_vec1, a_num_g,age_num,max_iter,...
        v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0,rat*c_of_e,rat*c_e_new_vec1,dem_tol,dist_n_1st,dist_old,v_new_resh_o1,v_new_resh_n1,...
        diff_gr1,diff_gr_t1,p_E_old,p_E1,trans_t1,dist_n1,dist_o1,...
        e0_n_vec1,e0_o,e_n_eps,e_o_eps,tech_dist_ss0,p_e_n1,p_e_n_1st,p_e_o1,p_e_o_1st,...
        rho,age_reduc,rat*c_conver,conv_rate,exit_n_final1,exit_o_final1,exo_exit,...
        e_max,gamma,init_input_n,init_input_o,penalty_o,penalty_n,penalty_p,d0_gr,...
        rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,"checkpoint_ss_gas_coal_1stMIT");
    save ss_gas_coal_1stMIT trans_prob_o_all1 v_new_resh_o_all1 dist_o_all1 measure_vec_o1 p_e_o_vec1 input_all_o1 ...
        trans_prob_n_all1 v_new_resh_n_all1 dist_n_all1 measure_vec_n1 p_e_n_vec1 input_all_n1 ...
        age_g_mit1 a_grid_mit1 a_prob_mit1 a_grid_n_all1 a_prob_n_all1 p_E_vec1 cap_old1 cap_new1
end
%% MIT2: pure new-tech efficiency gain
c_a_new_vec2 = c_a_new*ones(1,trans_t2);
c_e_new_vec2 = c_e_new*ones(1,trans_t2);
e0_n_vec2    = e0_n_1st*ones(1,trans_t2);

init_dist_o = dist_o_all1(sec_trans_t,:);
init_dist_n = dist_n_all1(sec_trans_t,:);
init_p_E    = p_E_vec1(sec_trans_t);
a_gr_init1n = a_grid_n_all1(:,sec_trans_t);
a_eff_n2    = a_gr_init1n' .* max(1 - a_grow .* age_g_mit1', 0);
a_eff_o2    = (a_grid_mit1./tech_dist_ss1)' .* max(1 - a_grow .* age_g_mit1', 0);
[eff_n_vec, ~] = static_solver(a_eff_n2, init_p_E.*P_E_grid_norm, ...
    p_e_n_vec1(end).*p_e_n_grid_norm, alpha, fco_n, 1./a_gr_init1n(:));
[eff_o_vec, ~] = static_solver(a_eff_o2, init_p_E.*P_E_grid_norm, p_e_o_vec1(end).*p_e_o_grid_norm, alpha, fco_o, 1./a_grid_mit1(:));
init_input_n = init_dist_n * eff_n_vec(:);
init_input_o = init_dist_o * eff_o_vec(:);

try 
    load ss_gas_coal_2stMIT
catch
    [trans_prob_o_all2,v_new_resh_o_all2,dist_o_all2,measure_vec_o2,p_e_o_vec2,input_all_o2,...
        trans_prob_n_all2,v_new_resh_n_all2,dist_n_all2,measure_vec_n2,p_e_n_vec2,input_all_n2,...
        age_g_mit2,a_grid_mit2,a_prob_mit2,a_grid_n_all2,a_prob_n_all2,p_E_vec2,cap_old2,cap_new2] =...
        MIT_transition_AC(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new_vec2,mu,sigma,...
        mu_vec2,sigma_vec2,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0*(1+d0_gr)^(sec_trans_t),rat*c_of_e,rat*c_e_new_vec2,...
        dem_tol,init_dist_n,init_dist_o,v_new_resh_o2,v_new_resh_n2,...
        diff_gr2,diff_gr_t2,init_p_E,p_E2,trans_t2,dist_n2,dist_o2,...
        e0_n_vec2,e0_o,e_n_eps,e_o_eps,tech_dist_ss1,p_e_n2,p_e_n_vec1(end),p_e_o2,p_e_o_vec1(end),...
        rho,age_reduc,rat*c_conver,conv_rate,exit_n_final2,exit_o_final2,exo_exit,...
        e_max,gamma,init_input_n,init_input_o,penalty_o,penalty_n,penalty_p,d0_gr,...
        rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,"checkpoint_ss_gas_coal_2stMIT");
    save ss_gas_coal_2stMIT trans_prob_o_all2 v_new_resh_o_all2 dist_o_all2 measure_vec_o2 p_e_o_vec2 input_all_o2 ...
        trans_prob_n_all2 v_new_resh_n_all2 dist_n_all2 measure_vec_n2 p_e_n_vec2 input_all_n2 ...
        age_g_mit2 a_grid_mit2 a_prob_mit2 a_grid_n_all2 a_prob_n_all2 p_E_vec2 cap_old2 cap_new2
end

%% MIT3: shale gas input-cost shock
c_a_new_vec3 = c_a_new*ones(1,trans_t3);
c_e_new_vec3 = c_e_new*ones(1,trans_t3);
e0_n_vec3    = e0_n_post_shale + (e0_n_1st-e0_n_post_shale)*exp(linspace(0,-40,trans_t3));

init_dist_o = dist_o_all2(thi_trans_t,:);
init_dist_n = dist_n_all2(thi_trans_t,:);
init_p_E    = p_E_vec2(thi_trans_t);
a_gr_init2n = a_grid_n_all2(:,thi_trans_t);
a_eff_n3    = a_gr_init2n' .* max(1 - a_grow .* age_g_mit2', 0);
a_eff_o3    = (a_grid_mit2./tech_dist_ss2)' .* max(1 - a_grow .* age_g_mit2', 0);
[eff_n_vec, ~] = static_solver(a_eff_n3, init_p_E.*P_E_grid_norm, p_e_n_vec2(end).*p_e_n_grid_norm, alpha, fco_n, 1./a_gr_init2n(:));
[eff_o_vec, ~] = static_solver(a_eff_o3, init_p_E.*P_E_grid_norm, p_e_o_vec2(end).*p_e_o_grid_norm, alpha, fco_o, 1./a_grid_mit2(:));
init_input_n = init_dist_n * eff_n_vec(:);
init_input_o = init_dist_o * eff_o_vec(:);

try
    load ss_gas_coal_3rdMIT
catch
    [trans_prob_o_all3,v_new_resh_o_all3,dist_o_all3,measure_vec_o3,p_e_o_vec3,input_all_o3,...
        trans_prob_n_all3,v_new_resh_n_all3,dist_n_all3,measure_vec_n3,p_e_n_vec3,input_all_n3,...
        age_g_mit3,a_grid_mit3,a_prob_mit3,a_grid_n_all3,a_prob_n_all3,p_E_vec3,cap_old3,cap_new3] =...
        MIT_transition_AC(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new_vec3,mu,sigma,...
        mu_vec3,sigma_vec3,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0,rat*c_of_e,rat*c_e_new_vec3,...
        dem_tol,init_dist_n,init_dist_o,v_new_resh_o3,v_new_resh_n3,...
        diff_gr3,diff_gr_t3,init_p_E,p_E3,trans_t3,dist_n3,dist_o3,...
        e0_n_vec3,e0_o,e_n_eps,e_o_eps,tech_dist_ss2,p_e_n3,p_e_n_vec2(end),p_e_o3,p_e_o_vec2(end),...
        rho,age_reduc,rat*c_conver,conv_rate,exit_n_final3,exit_o_final3,exo_exit,...
        e_max,gamma,init_input_n,init_input_o,penalty_o,penalty_n,penalty_p,d0_gr,...
        rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,"checkpoint_ss_gas_coal_3rdMIT");

    save ss_gas_coal_3rdMIT trans_prob_o_all3 v_new_resh_o_all3 dist_o_all3 measure_vec_o3 p_e_o_vec3 input_all_o3 ...
        trans_prob_n_all3 v_new_resh_n_all3 dist_n_all3 measure_vec_n3 p_e_n_vec3 input_all_n3 ...
        age_g_mit3 a_grid_mit3 a_prob_mit3 a_grid_n_all3 a_prob_n_all3 p_E_vec3 cap_old3 cap_new3
end
%% Save and plot combined paths
cap_share_path = [cap_new1(1:sec_trans_t)./(cap_old1(1:sec_trans_t)+cap_new1(1:sec_trans_t)), ...
    cap_new2(2:thi_trans_t)./(cap_old2(2:thi_trans_t)+cap_new2(2:thi_trans_t)), ...
    cap_new3(2:end)./(cap_old3(2:end)+cap_new3(2:end))];
p_E_path       = [p_E_vec1(1:sec_trans_t), p_E_vec2(2:thi_trans_t), p_E_vec3(2:end)];
e0_n_path      = [e0_n_vec1(1:sec_trans_t), e0_n_vec2(2:thi_trans_t), e0_n_vec3(2:end)];

%% Export aggregated fossil old tech for the fossil-to-green transition
%%% Choose where the green transition starts. By default we use the midpoint
%%% of the shale transition; change these two values to pick another point.
green_aggregation_phase = 3;     % 1: MIT1, 2: MIT2, 3: MIT3
green_aggregation_t     = 10; % "mid" or an integer index within the phase

switch green_aggregation_phase
    case 1
        agg_dist_boiler      = dist_o_all1;
        agg_dist_combustion  = dist_n_all1;
        agg_cap_boiler       = cap_old1;
        agg_cap_combustion   = cap_new1;
        agg_p_E_vec          = p_E_vec1;
        agg_p_e_boiler_vec   = p_e_o_vec1;
        agg_p_e_comb_vec     = p_e_n_vec1;
        agg_age_g            = age_g_mit1;
        a_grid_boiler        = a_grid_mit1;
        a_grid_combustion    = a_grid_n_all1;
        a_prob_boiler        = a_prob_mit1;
        a_prob_combustion    = a_prob_n_all1;
    case 2
        agg_dist_boiler      = dist_o_all2;
        agg_dist_combustion  = dist_n_all2;
        agg_cap_boiler       = cap_old2;
        agg_cap_combustion   = cap_new2;
        agg_p_E_vec          = p_E_vec2;
        agg_p_e_boiler_vec   = p_e_o_vec2;
        agg_p_e_comb_vec     = p_e_n_vec2;
        agg_age_g            = age_g_mit2;
        a_grid_boiler        = a_grid_mit2;
        a_grid_combustion    = a_grid_n_all2;
        a_prob_boiler        = a_prob_mit2;
        a_prob_combustion    = a_prob_n_all2;
    case 3
        agg_dist_boiler      = dist_o_all3;
        agg_dist_combustion  = dist_n_all3;
        agg_cap_boiler       = cap_old3;
        agg_cap_combustion   = cap_new3;
        agg_p_E_vec          = p_E_vec3;
        agg_p_e_boiler_vec   = p_e_o_vec3;
        agg_p_e_comb_vec     = p_e_n_vec3;
        agg_age_g            = age_g_mit3;
        a_grid_boiler        = a_grid_mit3;
        a_grid_combustion    = a_grid_n_all3;
        a_prob_boiler        = a_prob_mit3;
        a_prob_combustion    = a_prob_n_all3;
    otherwise
        error("green_aggregation_phase must be 1, 2, or 3.");
end

if isstring(green_aggregation_t) || ischar(green_aggregation_t)
    agg_t = ceil(size(agg_dist_boiler,1)/2);
else
    agg_t = green_aggregation_t;
end
agg_t = max(1,min(agg_t,size(agg_dist_boiler,1)));

cap_boiler_at_t     = agg_cap_boiler(agg_t);
cap_combustion_at_t = agg_cap_combustion(agg_t);
cap_fossil_at_t     = cap_boiler_at_t + cap_combustion_at_t;
if cap_fossil_at_t>0
    weight_boiler     = cap_boiler_at_t/cap_fossil_at_t;
    weight_combustion = cap_combustion_at_t/cap_fossil_at_t;
else
    weight_boiler     = 0.5;
    weight_combustion = 0.5;
end

dist_fossil_old      = agg_dist_boiler(agg_t,:) + agg_dist_combustion(agg_t,:);
a_grid_fossil_old    = a_grid_boiler;
a_prob_fossil_old    = weight_boiler*a_prob_boiler(:) + weight_combustion*a_prob_combustion(:,agg_t);
a_prob_fossil_old    = a_prob_fossil_old/sum(a_prob_fossil_old);
age_g_fossil_old     = (agg_age_g*sum(agg_dist_boiler(agg_t,:)) + a_grid_combustion(:,agg_t)*sum(agg_dist_combustion(agg_t,:)))/...
    (sum(dist_fossil_old));
p_E_fossil_old       = agg_p_E_vec(agg_t);
p_e_fossil_old       = weight_boiler*agg_p_e_boiler_vec(agg_t) + weight_combustion*agg_p_e_comb_vec(agg_t);
fco_fossil_old       = weight_boiler*fco_o + weight_combustion*fco_n;
c_e_fossil_old       = weight_boiler*c_of_e + weight_combustion*c_e_new;
c_a_fossil_old       = weight_boiler*c_of_a + weight_combustion*c_a_new;
rho_p_fossil_old     = weight_boiler*rho_p_o + weight_combustion*rho_p_n;
sigma_p_fossil_old   = weight_boiler*sigma_p_o + weight_combustion*sigma_p_n;
aggregation_weights  = [weight_boiler, weight_combustion];

save fossil_old_aggregated_for_green dist_fossil_old a_grid_fossil_old a_prob_fossil_old age_g_fossil_old ...
    p_E_fossil_old p_e_fossil_old fco_fossil_old c_e_fossil_old c_a_fossil_old ...
    rho_p_fossil_old sigma_p_fossil_old aggregation_weights green_aggregation_phase agg_t

save final_gas_coal_three_phase

ScSz = get(0, 'ScreenSize');

figure(9)
plot(cap_share_path,LineWidth=2)
xlabel('periods into transition'), ylabel('share')
title('new tech share of capacity')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

figure(11)
plot(p_E_path,LineWidth=2)
xlabel('periods into transition'), ylabel('price')
title('price path')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

figure(12)
yyaxis left
plot([c_e_new_vec1 c_e_new_vec2(2:end) c_e_new_vec3(2:end)],'LineWidth',2)
ylabel('new-tech entry cost')
yyaxis right
plot(e0_n_path,'LineWidth',2)
ylabel('new-tech fuel supply shifter')
xlabel('periods into transition')
title('shock path')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);