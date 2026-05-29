%%%% Power plants' dynamics: Alireza and Maija

%%% let's start with only one technology, I assume that after 100 period a
%%% plant would for sure adopt a new technology meaning that we should have
%%% the policy of the plant for a set of [0 age_num] years * [a_l a_L]


clear
close
clc

%%
a_bar   = 80;
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
mu2     = 0.53;
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
c_e_new = 80 ;%10;   %%%% setting a different entry cost for the new tech 
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




%% calibration first part
%%% the unkown paramteres are d_0, e0_n, e0_o, alpha, c_of_a, c_a_new, rat, age_reduc and
%%% the moments are p_E, p_e_n, p_e_o, total_eff_ratio, measure_ratio, mean
%%% efficiency, and ratio of input cost to instalation cost and also mean
%%% of cap_Age

rat     = 1; %%% this governs the ratio of the overhead costs to O&M cost in the model
options = optimoptions('surrogateopt','Display','iter','PlotFcn',[]);

global tracks JJ
tracks  = zeros(17,100);
JJ      = 0;

p_E_m = 35; p_e_n_m = 12; p_e_o_m = 3.4;  %%% these numbers come from the papers
        %%% in the literature (cited withthe help of gpt)
inp_ratio = 7; m_ratio = 3;
mean_eff = 0.37; tech_dist   = 1; feul_ce_ratio = 0.12; M_cap_age = 6.1;
mu_old = mu;
mu_new = mu-0.05;
A = []; B = []; Aeq = []; Beq = []; nonlcon=[];
lb  = [0.25,0.25,45,0.15,1.25,2.0,1.5];
ub  = [2.00,2.00,65,0.95,3.50,3.5,7.5];
[x,fval,exitflag,output]    = surrogateopt(@(x)simulator(a_grow,alpha,a_bar...
    ,beta,x(1),x(2),mu_old,sigma,mu_new,sigma,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,fco_o,fco_n,e_p,x(3),c_of_e,c_e_new,dem_tol,tech_dist,...
        x(4),x(5),e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,x(7),exo_exit,e_max,gamma,x(6),...
        p_E_m,p_e_n_m,p_e_o_m,inp_ratio,m_ratio,mean_eff,feul_ce_ratio,M_cap_age)...
        ,lb,ub,nonlcon,A,B,Aeq,Beq,options);




%% old tech ss
vec_c_a_1st     = zeros(100,1);
vec_c_e_1st     = zeros(100,1);
% [trans_prob_old,v_new_old,v_new_resh_old,dist_old,...
%     trans_matrix_old,age_g,a_grid,~,pi_contemp,p_E_old,m_of_firms_old] = ...
% One_tech_ss(a_grow,alpha,a_bar,beta,c_of_a,a_lamb,p_e,a_num_g,age_num,max_iter,...
% v_tol,dist_tol,fco,e_p,d_0,c_of_e,dem_tol);

%%%%% or the old tech ss for the transition of solar introduction can be a
%%%%% two tech ss where c_a_new and c_e_new are high numbers leading to
%%%%% a near zero measure of the new_tech firms. In this setting the reduction in
%%%%% the fixed costs of new-tech would lead to the increase in their share
%%%%% Or also use the two-tech system for a case when coal and gas
%%%%% transition is happening
tech_dist   = 1;
% 
% tracks(15,tracks(15,:)==0)=30;
% track0  = tracks(1:7,tracks(15,:)==min(tracks(15,:)));
track0 = tracks(:,3);
alpha   = track0(1);
c_of_a  = track0(2); 
c_a_new = track0(3);
d_0     = track0(4);
e0_n_1st= track0(5);
e0_o    = track0(6);
rat     = track0(7);
age_reduc   = track0(8);

% for i=1:1:20

% for tt = 1:1:100 
    % alpha = alphas(i);
    [trans_prob_old,v_new_old,v_new_resh_old,dist_old,trans_matrix_n_1st,p_e_n_1st,cap_contemp_new,eff_n_final,...
        trans_prob_n_1st,v_new_n_1st,v_new_resh_n_1st,dist_n_1st,trans_matrix_old,p_e_o_1st,cap_contemp_old,eff_o_final,...
        age_g,a_grid,~,a_grid,~,pi_contemp_new_1st,p_E_old,m_of_firms_new_1st,m_of_firms_old_1st,...
        exit_n_1st,exit_o_1st] = ...
        Two_tech_ss_AC2(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new,mu,sigma,mu,sigma,a_num_g,age_num,max_iter,...
        v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0/(tech_dist^(1/(1-alpha))),rat*c_of_e,rat*c_e_new_1st,dem_tol,tech_dist,...
        e0_n_1st/(tech_dist^(1/(1-alpha))),e0_o/(tech_dist^(1/(1-alpha))),e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,e_max,gamma);

    error_ss    = dist_n_1st*cap_contemp_new(:)/(dist_n_1st*cap_contemp_new(:)+dist_old*cap_contemp_old(:))-0.075;
    filensme = ['1st_ss_trial' num2str(i)];
    save(filensme);
% end
%     if abs(error_ss)<0.025
%         break;
%     else
%         c_e_new_1st     = c_e_new_1st*(1+0.1*error_ss);
%         c_a_new_1st     = c_a_new_1st*(1+0.1*error_ss);
%         vec_c_a_1st(tt) = c_a_new_1st;
%         vec_c_e_1st(tt) = c_e_new_1st;
%     end
% end


% save results_with_highAC_low(ca)
% 
% age_reduc   = 10;
% 
% [trans_prob_old,v_new_old,v_new_resh_old,dist_old,trans_matrix_n_1st,p_e_n_1st,...
%     trans_prob_n_1st,v_new_n_1st,v_new_resh_n_1st,dist_n_1st,trans_matrix_old,p_e_o_1st,...
%     age_g,a_grid,a_prob,pi_contemp_new_1st,p_E_old,m_of_firms_new_1st,m_of_firms_old_1st] = ...
%     Two_tech_ss_AC(a_grow,alpha,a_bar,beta,c_of_a,c_a_new_1st,a_lamb,a_num_g,age_num,max_iter,...
%     v_tol,dist_tol,fco,e_p,d_0/tech_dist,c_of_e,c_e_new_1st,dem_tol,tech_dist,...
%     e0_n_1st,e0_o,e_n_eps,e_o_eps,rho,age_reduc);
% 
% save results_with_highAC_low(ca)_low(age_reduc)

%%

ScSz = get(0, 'ScreenSize');

figure(1)
surf(a_grid,age_g,v_new_resh_old);
xlabel('productivity'), ylabel('age')
title('value of firm in each state')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
%%
dist_resh = (reshape(dist_o',a_num_g,age_num))';
figure(22)
surf(a_grid,age_g(1:50),(dist_resh(1:50,:)));
xlabel('productivity'), ylabel('age')
title('mass of firms in each state ')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
%%
figure(6)
temp            = reshape(trans_prob_old,a_num_g,age_num);
temp(temp==0)   = NaN;
surf(age_g,a_grid,temp,'edgecolor','none')
% colormap(map_color)
% shading("interp")
colorbar
xlabel("age")
ylabel("productivity")
set(gca, 'FontSize', 24);
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
title("probability of tech adoption");
% address = 'D:\AMR_github\graphs\transition_prob.png';
% saveas(gcf,address)
% annotation('textarrow',[1,10],'String','y = x ')
%% MIT paramters
trans_t  = 100;

%%% we also incorporate the growth in baseline demand growth
d0_gr   = 0.01;

%%% there can be also an efficiency wedge that has been there without any
%%% growth; this would be the case for solar and gas
diff_gr_t       = 10;
diff_gr         = 0.03;

% diff_gr_cons    = (1+0.4)^diff_gr_t;    %%% to be used for solar case
diff_gr_cons    = 1;                    %%% to be used for gas and coal


%%% let's define a supply curve for the effort used in different techs
e0_n    = 1;
e0_o    = 10;


%%% let's define a high fixed cost a starting point for the new_tech guys
%%% and it's transition in a declining exponential phase; in this case
%%% e0_n_vec would be a constant.
% c_a_new_1st     = 3.35;
% c_e_new_1st     = 33.5;
% 
% c_a_new_vec     = c_a_new + (c_a_new_1st-c_a_new)*exp(linspace(0,-20,trans_t));
% c_e_new_vec     = c_e_new + (c_e_new_1st-c_e_new)*exp(linspace(0,-20,trans_t));


%%% if the tech transition combined with supply expansion (for gas
%%% transition) is in mind then the fix cost vectors are a constant and the
%%% supply side would increase from on level to another one

c_a_new_1st     = c_a_new;
c_e_new_1st     = c_e_new;

c_a_new_vec     = c_a_new*ones(1,trans_t);
c_e_new_vec     = c_e_new*ones(1,trans_t);

e0_n_vec_1step  = e0_n_1st*ones(1,trans_t);
e0_n_1st_1step  = e0_n_1st;
e0_n_vec        = e0_n + (e0_n_1st-e0_n)*exp(linspace(0,-40,trans_t));

%% new tech ss(before observing the price shock)
% tech_dist   = (1+diff_gr)^diff_gr_t;

[trans_prob_o1,v_new_o1,v_new_resh_o1,dist_o1,trans_matrix_n1,p_e_n1,cap_contemp_n21,eff_n_final21,...
    trans_prob_n1,v_new_n1,v_new_resh_n1,dist_n1,trans_matrix_o1,p_e_o1,cap_contemp_o21,eff_o_final21,...
    age_g1,a_grid_o,a_prob_o,a_grid_n,a_prob_n,...
    pi_contemp_new1,p_E1,m_of_firms_new1,m_of_firms_old1,exit_n_final1,exit_o_final1] = ...
    Two_tech_ss_AC2(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new,mu,sigma,mu2,sigma2,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0*(1+d0_gr)^trans_t/(tech_dist^(1/(1-alpha))),rat*c_of_e,rat*c_e_new,dem_tol,tech_dist,...
    e0_n_1st/(tech_dist^(1/(1-alpha))),e0_o/(tech_dist^(1/(1-alpha))),e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,e_max,gamma);

% new tech ss (with two techs)
% tech_dist   = (1+diff_gr)^diff_gr_t;

[trans_prob_o,v_new_o,v_new_resh_o,dist_o,trans_matrix_n,p_e_n,cap_contemp_n2,eff_n_final2,...
    trans_prob_n,v_new_n,v_new_resh_n,dist_n,trans_matrix_o,p_e_o,cap_contemp_o2,eff_o_final2,...
    age_g,a_grid,a_prob,pi_contemp_new,p_E,m_of_firms_new,m_of_firms_old,exit_n_final,exit_o_final] = ...
    Two_tech_ss_AC2(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new,mu,sigma,mu2,sigma2,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0*(1+d0_gr)^trans_t/(tech_dist^(1/(1-alpha))),rat*c_of_e,rat*c_e_new,dem_tol,tech_dist,...
    e0_n/(tech_dist^(1/(1-alpha))),e0_o/(tech_dist^(1/(1-alpha))),e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,age_reduc,exo_exit,e_max,gamma);

save ss_gas_coal
%
% ScSz = get(0, 'ScreenSize');
% figure(1)
% surf(a_grid,age_g,v_new_resh_n);
% xlabel('productivity'), ylabel('age')
% title('value of firm in each state')
% set(gca,'Fontsize',32)
% set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
% 
% dist_resh = (reshape(dist_n',a_num_g,age_num))';
% figure(2)
% surf(a_grid,age_g(1:50),(dist_resh(1:50,:)));
% xlabel('productivity'), ylabel('age')
% title('mass of firms in each state ')
% set(gca,'Fontsize',32)
% set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
% 
% %%
% ScSz = get(0, 'ScreenSize');
% figure(6)
% temp            = reshape(trans_prob_n,a_num_g,age_num);
% temp(temp==0)   = NaN;
% surf(age_g,a_grid,temp,'edgecolor','none')
% %surface(age_g,a_grid,reshape(temp,a_num_g,age_num),'edgecolor','none')
% % colormap(map_color)
% % shading("interp")
% xlabel("age")
% ylabel("productivity")
% set(gca, 'FontSize', 32);
% colorbar
% title("probability of tech adoption for new-tech generators")
% set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
% % address = 'D:\AMR_github\graphs\transition_prob_n.png';
% % saveas(gcf,address)
% %%
% ScSz = get(0, 'ScreenSize');
% figure(7)
% temp            = reshape(trans_prob_o,a_num_g,age_num);
% temp(temp==0)   = NaN;
% surf(age_g,a_grid,temp,'edgecolor','none')
% % surface(age_g,a_grid,reshape(temp,a_num_g,age_num),'edgecolor','none')
% % colormap(map_color)
% % shading("interp")
% xlabel("age")
% ylabel("productivity")
% set(gca, 'FontSize', 32);
% title("probability of tech adoption for old")
% % colorbar
% % annotation('textarrow',[1,10],'String','y = x ')
% title("probability of tech adoption for old-tech generators")
% set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
% % address = 'D:\AMR_github\graphs\transition_prob_o.png';
% % saveas(gcf,address)
% 
% dist_resh = (reshape(dist_o',a_num_g,age_num))';
% figure(2)
% surf(a_grid,age_g,(dist_resh));
% xlabel('productivity'), ylabel('age')
% title('log of mass of firms in each state ')
% set(gca,'Fontsize',32)
% set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
% 
% figure(1)
% surf(a_grid,age_g,v_new_resh_o);
% xlabel('productivity'), ylabel('age')
% title('value of firm in each state')
% set(gca,'Fontsize',32)
% set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
%%
%%%% MIT transition 
%%% In the transition first the shock to efficiency is observed and then
%%% the shock to gas supply arrives

e0_n_vec_1step  = e0_n_1st*ones(1,trans_t);
e0_n_1st_1step  = e0_n_1st;
e0_n_vec        = e0_n + (e0_n_1st-e0_n)*exp(linspace(0,-40,trans_t));

final_dist_o    = dist_o1;
final_dist_n    = dist_n1;
final_p_E       = p_E1;
init_p_E        = p_E_old;
final_val2      = v_new_resh_n1;
final_val1      = v_new_resh_o1;
init_dist_o     = dist_old;
init_dist_n     = dist_n_1st; %%% be aware of the necessary changes when 
                            %%% a one-tech ss
c_conver        = 20;       %%% in the data about 200 w.r.t 500 overhead
conv_rate       = 0.15;
diff_gr_cons    = 0.9;
diff_gr         = 0.04;   %%%% here since the gas generators begin at a disadvantage
                          %%%% I set their growth rate for transition
                          %%%% higher so they would catch up with the 2nd
                          %%%% SS values for the efficiency

penalty_p       = 1; %%% demand is also less elastic in the transition
penalty_n       = 1;
penalty_o       = 1; %%% this is the effect of deviation from last year's input
                        %%% for the whole submarket, e.g. a 10% increase in
                        %%% demand would require 20% increase in supply

n_PE = 50;
n_pe = 10;
P_E_grid_norm = P_E_grid(n_PE,1);
p_e_n_grid_norm = p_input_grid(n_pe,1,sigma_p_n,rho_p_n);
p_e_o_grid_norm = p_input_grid(n_pe,1,sigma_p_o,rho_p_o);

a_eff_init      = a_grid' .* max(1 - a_grow .* age_g', 0);
[eff_n_vec, ~]  = static_solver(a_eff_init, p_E_old.*P_E_grid_norm, p_e_n_1st.*p_e_n_grid_norm, alpha, fco_n, 1./a_grid(:));
[eff_o_vec, ~]  = static_solver(a_eff_init, p_E_old.*P_E_grid_norm, p_e_o_1st.*p_e_o_grid_norm, alpha, fco_o, 1./a_grid(:));
init_input_n    = dist_n_1st * eff_n_vec(:)
init_input_o    = dist_old * eff_o_vec(:)

[trans_prob_o_all1,v_new_resh_o_all1,dist_o_all1,measure_vec_o1,p_e_o_vec1,input_all_o1,...
    trans_prob_n_all1,v_new_resh_n_all1,dist_n_all1,measure_vec_n1,p_e_n_vec1,input_all_n1,...
    age_g1,a_grid1,a_prob1,p_E_vec1,cap_old1,cap_new1] =...
    MIT_transition_AC(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new_vec,mu,sigma,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0,rat*c_of_e,rat*c_e_new_vec,dem_tol,init_dist_n,init_dist_o,final_val1,final_val2,...
    diff_gr,diff_gr_t,init_p_E,final_p_E,trans_t,final_dist_n,final_dist_o,...
    e0_n_vec_1step,e0_o,e_n_eps,e_o_eps,diff_gr_cons,p_e_n1,p_e_n_1st,p_e_o1,p_e_o_1st,...
    rho,age_reduc,rat*c_conver,conv_rate,exit_n_final1,exit_o_final1,exo_exit,...
    e_max,gamma,init_input_n,init_input_o,penalty_o,penalty_n,penalty_p,d0_gr,...
    rho_p_n,sigma_p_n,rho_p_o,sigma_p_o);

%%
%%%% I implement the transition as first the shock of efficiency is
%%%% observed and after that in the way of transition the shock of lower
%%%% input is realized
diff_gr_cons    = diff_gr_cons*(1+diff_gr)^(diff_gr_t);

final_dist_o    = dist_o;
final_dist_n    = dist_n;
final_p_E       = p_E;
init_p_E        = p_E_vec1(diff_gr_t);
final_val2      = v_new_resh_n;
final_val1      = v_new_resh_o;
init_dist_o     = dist_o_all1(diff_gr_t,:);
init_dist_n     = dist_n_all1(diff_gr_t,:); 

diff_gr         = 0.0;


a_eff_n2        = a_grid' .* max(1 - a_grow .* age_g', 0);
a_eff_o2        = (a_grid./diff_gr_cons)' .* max(1 - a_grow .* age_g', 0);
[eff_n_vec, ~]  = static_solver(a_eff_n2, p_E_vec1(diff_gr_t).*P_E_grid_norm, p_e_n_vec1(diff_gr_t).*p_e_n_grid_norm, alpha, fco_n, 1./a_grid(:));
[eff_o_vec, ~]  = static_solver(a_eff_o2, p_E_vec1(diff_gr_t).*P_E_grid_norm, p_e_o_vec1(diff_gr_t).*p_e_o_grid_norm, alpha, fco_o, 1./a_grid(:));
init_input_n    = init_dist_n * eff_n_vec(:)
init_input_o    = init_dist_o * eff_o_vec(:)

[trans_prob_o_all,v_new_resh_o_all,dist_o_all,measure_vec_o,p_e_o_vec,input_all_o2,...
    trans_prob_n_all,v_new_resh_n_all,dist_n_all,measure_vec_n,p_e_n_vec,input_all_n2,...
    age_g,a_grid,a_prob,p_E_vec,cap_old,cap_new] =...
    MIT_transition_AC(a_grow,alpha,a_bar,beta,rat*c_of_a,rat*c_a_new_vec,mu,sigma,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,rat*fco_o,rat*fco_n,e_p,d_0,rat*c_of_e,rat*c_e_new_vec(diff_gr_t+1:trans_t),dem_tol,init_dist_n,init_dist_o,final_val1,final_val2,...
    diff_gr,diff_gr_t,init_p_E,final_p_E,trans_t-diff_gr_t,final_dist_n,final_dist_o,...
    e0_n_vec,e0_o,e_n_eps,e_o_eps,diff_gr_cons,p_e_n,p_e_n_vec1(diff_gr_t),p_e_o,p_e_o_vec1(diff_gr_t),...
    rho,age_reduc,rat*c_conver,conv_rate,exit_n_final,exit_o_final,exo_exit,...
    e_max,gamma,init_input_n,init_input_o,penalty_o,penalty_n,penalty_p,d0_gr,...
    rho_p_n,sigma_p_n,rho_p_o,sigma_p_o);






save final_gas_coal1
%%

ScSz = get(0, 'ScreenSize');

figure(9)
plot([cap_new1(1:diff_gr_t)./(cap_old1(1:diff_gr_t)+cap_new1(1:diff_gr_t))...
    cap_new(2:end-diff_gr_t+1)./(cap_old(2:end-diff_gr_t+1)+cap_new(2:end-diff_gr_t+1))],LineWidth=2)
xlabel('periods into transition'), ylabel('share')
title('new tech share of capacity')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);


growth_t_line   = diff_gr_t*ones(1,trans_t);
growth_t_line(1:diff_gr_t) = linspace(1,diff_gr_t,diff_gr_t);
tech_dist_vec   = (1+diff_gr).^growth_t_line*diff_gr_cons;
figure(10)
plot(tech_dist_vec.^(1/(1-alpha)).*[(cap_old1(1:diff_gr_t)+cap_new1(1:diff_gr_t)) ...
    (cap_old(2:end-diff_gr_t+1)+cap_new(2:end-diff_gr_t+1))],LineWidth=2)
xlabel('periods into transition'), ylabel('capacity')
title('total capacity (detrended)')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

figure(11)
plot([p_E_vec1(1:diff_gr_t) p_E_vec(2:end-diff_gr_t+1)],LineWidth=2)
xlabel('periods into transition'), ylabel('price')
title('price path')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

diff_gr         = 0.015;
growth_t_line   = diff_gr_t*ones(1,trans_t);
growth_t_line(1:diff_gr_t) = linspace(1,diff_gr_t,diff_gr_t);
tech_dist_vec   = (1+diff_gr).^growth_t_line;
figure(12)
yyaxis left
plot(tech_dist_vec,'LineWidth',2)
ylabel('tech diff path')
yyaxis right
plot([e0_n_vec_1step(1:diff_gr_t) e0_n_vec(2:end-diff_gr_t+1)],'LineWidth',2)
ylabel('gas supply shock')
%xlim([pl1 pl2])
xlabel('periods into transition')
title('shock     path')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
%%
dist_reshaped = (reshape(dist_of_new',a_num_g,age_num))';
figure(3)
surf(a_grid,age_g,log(dist_reshaped));
xlabel('productivity'), ylabel('age')
title('log of mass of firms in each state ')
set(gca, 'FontSize', 24);

figure(8)
plot(cap_transition,LineWidth=2)
ylabel('Share of capacity produced by old'), xlabel('years in to transition')
title('Capacity transition pattern ')
set(gca, 'FontSize', 24);