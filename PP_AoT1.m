%%%% Power plants' dynamics: Alireza and Maija

%%% let's start with only one technology, I assume that after 100 period a
%%% plant would for sure adopt a new technology meaning that we should have
%%% the policy of the plant for a set of [0 age_num] years * [a_l a_L] where small
%%% a's are the demeaned A's


clear
close
clc

%%
a_bar   = 80;
beta    = 0.97;
c_of_a  = 10;   %%%% we should think more about how to enforce the fix cost
                %%%% right now it's compared with the value of adoption
                %%%% which can get really high so we need compare it to
                %%%% some notion of contemporaneous profit
c_a_new = 10; %20;   %%%% setting a different adoption cost for the new tech 
                %%%% might be a solution to get a two tech SS; for gas and
                %%%% coal case they will be set to be the same

max_iter    = 10000;
v_tol       = 10^-5;
dist_tol    = 10^-7;

alpha   = 0.7; 
p_e     = 1;
a_lamb  = 0.5;
a_num_g = 50;
age_num = 200;

fco     = 0.1;
e_p     = 0.1;    %%% this demand elasticity is estimated around 0.1 but more 
                %%% papers should be read about it (in the long run it's 1
                %%% but I think we should use the short run estimate)

d_0     = 15;   %%% what should this value be?? it has profound effect on 
                %%% the final distribution of the firms due to low
                %%% elacticity of demand
c_of_e  = 5;
c_e_new = 5 ;%10;   %%%% setting a different entry cost for the new tech 
                %%%% might be a solution to get a two tech SS; for gas and
                %%%% coal case they will be set to be the same
dem_tol = 0.01;


trans_t  = 200;

%%% there can be also an efficiency wedge that has been there without any
%%% growth; this would be the case for solar and gas
diff_gr_t       = 10;
diff_gr         = 0.02;
a_grow          = 0.01;
% diff_gr_cons    = (1+0.4)^diff_gr_t;    %%% to be used for solar case
diff_gr_cons    = 1;                    %%% to be used for gas and coal


%%% let's define a supply curve for the effort used in different techs
e0_n    = 1.2;
e0_o    = 1;
e_n_eps = 0.15;
e_o_eps = 0.1;

%%% let's define a high fixed cost a starting point for the new_tech guys
%%% and it's transition in a declining exponential phase; in this case
%%% e0_n_vec would be a constant.
% c_a_new_1st     = 40;
% c_e_new_1st     = 20;
% 
% c_a_new_vec     = c_a_new + (c_a_new_1st-c_a_new)*exp(linspace(0,-20,trans_t));
% c_e_new_vec     = c_e_new + (c_e_new_1st-c_e_new)*exp(linspace(0,-20,trans_t));
% e0_n_vec        = e0_n*ones(1,trans_t);

%%% if the tech transition combined with supply expansion (for gas
%%% transition) is in mind then the fix cost vectors are a constant and the
%%% supply side would increase from on level to another one

c_a_new_1st     = c_a_new;
c_e_new_1st     = c_e_new;

c_a_new_vec     = c_a_new*ones(1,trans_t);
c_e_new_vec     = c_e_new*ones(1,trans_t);

e0_n_1st        = 0.8;
e0_n_vec        = e0_n + (e0_n_1st-e0_n)*exp(linspace(0,-40,trans_t));



%%% auto correlation case parameters
rho         = 0.75;
age_reduc   = 20;
%% old tech ss


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

[trans_prob_old,v_new_old,v_new_resh_old,dist_old,trans_matrix_n_1st,p_e_n_1st,...
    trans_prob_n_1st,v_new_n_1st,v_new_resh_n_1st,dist_n_1st,trans_matrix_old,p_e_o_1st,...
    age_g,a_grid,a_prob,pi_contemp_new_1st,p_E_old,m_of_firms_new_1st,m_of_firms_old_1st] = ...
    Two_tech_ss_AC(a_grow,alpha,a_bar,beta,c_of_a,c_a_new_1st,a_lamb,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,fco,e_p,d_0/tech_dist,c_of_e,c_e_new_1st,dem_tol,tech_dist,...
    e0_n_1st,e0_o,e_n_eps,e_o_eps,rho,age_reduc);

%%

ScSz = get(0, 'ScreenSize');

figure(1)
surf(1+a_grid,age_g,v_new_resh_old);
xlabel('productivity'), ylabel('age')
title('value of firm in each state')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
%%
dist_resh = (reshape(dist_old',a_num_g,age_num))';
figure(22)
surf(1+a_grid,age_g,log(dist_resh));
xlabel('productivity'), ylabel('age')
title('log of mass of firms in each state ')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
%%
figure(6)
temp            = reshape(trans_prob_old,a_num_g,age_num);
temp(temp==0)   = NaN;
surface(age_g,1+a_grid,temp,'edgecolor','none')
% colormap(map_color)
% shading("interp")
colorbar
xlabel("age")
ylabel("productivity")
set(gca, 'FontSize', 24);
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
title("probability of tech adoption");
address = 'D:\AMR_github\graphs\transition_prob.png';
% saveas(gcf,address)
% annotation('textarrow',[1,10],'String','y = x ')
%% new tech ss (with two techs)
tech_dist   = (1+diff_gr)^diff_gr_t;

[trans_prob_o,v_new_o,v_new_resh_o,dist_o,trans_matrix_n,p_e_n,...
    trans_prob_n,v_new_n,v_new_resh_n,dist_n,trans_matrix_o,p_e_o,...
    age_g,a_grid,a_prob,pi_contemp_new,p_E,m_of_firms_new,m_of_firms_old] = ...
    Two_tech_ss_AC(a_grow,alpha,a_bar,beta,c_of_a,c_a_new,a_lamb,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,fco,e_p,d_0/tech_dist,c_of_e,c_e_new,dem_tol,tech_dist,...
    e0_n,e0_o,e_n_eps,e_o_eps,rho,age_reduc);
%%
ScSz = get(0, 'ScreenSize');
figure(1)
surf(1+a_grid,age_g,v_new_resh_n);
xlabel('productivity'), ylabel('age')
title('value of firm in each state')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

dist_resh = (reshape(dist_n',a_num_g,age_num))';
figure(2)
surf(1+a_grid,age_g,log(dist_resh));
xlabel('productivity'), ylabel('age')
title('log of mass of firms in each state ')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

%%
ScSz = get(0, 'ScreenSize');
figure(6)
temp            = reshape(trans_prob_n,a_num_g,age_num);
temp(temp==0)   = NaN;
surface(age_g,1+a_grid,reshape(temp,a_num_g,age_num),'edgecolor','none')
% colormap(map_color)
% shading("interp")
xlabel("age")
ylabel("productivity")
set(gca, 'FontSize', 32);
colorbar
title("probability of tech adoption for new-tech generators")
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
% address = 'D:\AMR_github\graphs\transition_prob_n.png';
% saveas(gcf,address)
%%
ScSz = get(0, 'ScreenSize');
figure(7)
temp            = reshape(trans_prob_o,a_num_g,age_num);
temp(temp==0)   = NaN;
surface(age_g,1+a_grid,reshape(temp,a_num_g,age_num),'edgecolor','none')
% colormap(map_color)
% shading("interp")
xlabel("age")
ylabel("productivity")
set(gca, 'FontSize', 32);
title("probability of tech adoption for old")
colorbar
% annotation('textarrow',[1,10],'String','y = x ')
title("probability of tech adoption for old-tech generators")
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
% address = 'D:\AMR_github\graphs\transition_prob_o.png';
% saveas(gcf,address)

dist_resh = (reshape(dist_o',a_num_g,age_num))';
figure(2)
surf(1+a_grid,age_g,log(dist_resh));
xlabel('productivity'), ylabel('age')
title('log of mass of firms in each state ')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

figure(1)
surf(1+a_grid,age_g,v_new_resh_o);
xlabel('productivity'), ylabel('age')
title('value of firm in each state')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);
%%
%%%% MIT transition 
%%% In the transition each frim has firm on the old tech has would
%%% eventually in the transition but it can still update its facility in
%%% the path.
final_dist_o    = dist_o;
final_dist_n    = dist_n;
final_p_E       = p_E;
init_p_E        = p_E_old;
final_val2      = v_new_resh_n;
final_val1      = v_new_resh_o;
init_dist_o     = dist_old;
init_dist_n     = dist_n_1st; %%% be aware of the necessary changes when 
                            %%% a one-tech ss
c_conver        = 5;
conv_rate       = 0.2;

[trans_prob_o_all,v_new_resh_o_all,dist_o_all,measure_vec_o,p_e_o_vec,...
    trans_prob_n_all,v_new_resh_n_all,dist_n_all,measure_vec_n,p_e_n_vec,...
    age_g,a_grid,a_prob,p_E_vec,cap_old,cap_new] =...
    MIT_transition_AC(a_grow,alpha,a_bar,beta,c_of_a,c_a_new_vec,a_lamb,a_num_g,age_num,max_iter,...
    v_tol,dist_tol,fco,e_p,d_0,c_of_e,c_e_new_vec,dem_tol,init_dist_n,init_dist_o,final_val1,final_val2,...
    diff_gr,diff_gr_t,init_p_E,final_p_E,trans_t,final_dist_n,final_dist_o,...
    e0_n_vec,e0_o,e_n_eps,e_o_eps,diff_gr_cons,p_e_n,p_e_n_1st,p_e_o,p_e_o_1st,...
    rho,age_reduc,c_conver,conv_rate);





%%

ScSz = get(0, 'ScreenSize');

figure(9)
plot(cap_new./(cap_old+cap_new),LineWidth=2)
xlabel('periods into transition'), ylabel('share')
title('new tech share of capacity')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);


growth_t_line   = 20*ones(1,trans_t);
growth_t_line(1:diff_gr_t) = linspace(1,diff_gr_t,diff_gr_t);
tech_dist_vec   = (1+diff_gr).^growth_t_line;
figure(10)
plot(tech_dist_vec.*(cap_old+cap_new),LineWidth=2)
xlabel('periods into transition'), ylabel('capacity')
title('total capacity (detrended)')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

figure(11)
plot(p_E_vec,LineWidth=2)
xlabel('periods into transition'), ylabel('price')
title('price path')
set(gca,'Fontsize',32)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

%%
dist_reshaped = (reshape(dist_of_new',a_num_g,age_num))';
figure(3)
surf(1+a_grid,age_g,log(dist_reshaped));
xlabel('productivity'), ylabel('age')
title('log of mass of firms in each state ')
set(gca, 'FontSize', 24);

figure(8)
plot(cap_transition,LineWidth=2)
ylabel('Share of capacity produced by old'), xlabel('years in to transition')
title('Capacity transition pattern ')
set(gca, 'FontSize', 24);