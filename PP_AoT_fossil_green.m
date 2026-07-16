%%%% Fossil to green transition dynamics
%%%% Old tech: capacity-weighted aggregate fossil branch from coal-gas transition
%%%% New tech: intermittent green/solar branch

clear
close
clc

%% Load fossil old state from coal-gas transition
fossil_state_file = "fossil_old_aggregated_for_green.mat";
if exist(fossil_state_file,"file") ~= 2
    error("Missing %s. Run PP_AoT_coal_gas.m first or update fossil_state_file.",fossil_state_file);
end
S = load(fossil_state_file);

dist_fossil_old = S.dist_fossil_old;
a_grid_fossil_old = S.a_grid_fossil_old(:)';
a_prob_fossil_old = S.a_prob_fossil_old(:)'/sum(S.a_prob_fossil_old);
p_E_initial = S.p_E_fossil_old;
p_e_fossil_initial = S.p_e_fossil_old;
fco_fossil = S.fco_fossil_old;
c_e_fossil = S.c_e_fossil_old;
c_a_fossil = S.c_a_fossil_old;
rho_p_fossil = S.rho_p_fossil_old;
sigma_p_fossil = S.sigma_p_fossil_old;

%% Core parameters
beta      = 0.97;
alpha     = 1.9;
a_grow    = 0.005;
rho       = 0.6;
exo_exit  = 0.01;
e_p       = 0.75;
e_o_eps   = 1.0;
dem_tol   = 0.01;
v_tol     = 1e-5;
dist_tol  = 1e-7;
max_iter  = 30000;
a_bar     = 1;

a_num_g = numel(a_grid_fossil_old);
age_num = numel(dist_fossil_old)/a_num_g;
if abs(age_num-round(age_num))>0
    error("dist_fossil_old length is not divisible by a_num_g.");
end
age_num = round(age_num);

d_0 = (sum(dist_fossil_old) * max(p_E_initial,1)^e_p);
e0_o = max(sum(dist_fossil_old),1);

%% Green/solar parameters
mu_green_initial    = 0.10;
sigma_green_initial = 0.02;
mu_green_final      = 0.10;
sigma_green_final   = 0.02;

fco_green       = 0.2;
c_e_green_high  = 60;
c_e_green_low   = 15;
c_a_green_high  = 8;
c_a_green_low   = 2;

solar_cap_mean   = 0.25;
solar_price_corr = 0.6;

trans_t = 120;
d0_gr   = 0.01;

mu_green_vec    = linspace(mu_green_initial,mu_green_final,trans_t);
sigma_green_vec = linspace(sigma_green_initial,sigma_green_final,trans_t);
c_e_green_vec   = c_e_green_low + (c_e_green_high-c_e_green_low)*exp(linspace(0,-20,trans_t));
c_a_green_vec   = c_a_green_low + (c_a_green_high-c_a_green_low)*exp(linspace(0,-20,trans_t));

%% Terminal steady state after green installation cost decline
try
    load ss_fossil_green_final
catch
    [trans_prob_o_final,v_new_o_final,v_new_resh_o_final,dist_o_final,trans_matrix_n_final,p_e_n_final,cap_contemp_green_final,eff_green_final,...
        trans_prob_n_final,v_new_n_final,v_new_resh_n_final,dist_n_final,trans_matrix_o_final,p_e_o_final,cap_contemp_fossil_final,eff_fossil_final,...
        age_g_final,a_grid_old_final,a_prob_old_final,a_grid_green_final,a_prob_green_final,pi_contemp_green_final,p_E_final,...
        m_of_firms_green_final,m_of_firms_fossil_final,exit_n_final,exit_o_final] = ...
        Two_tech_ss_AC3(a_grow,alpha,a_bar,beta,c_a_fossil,c_a_green_low,...
        mean(a_grid_fossil_old),std(a_grid_fossil_old),mu_green_final,sigma_green_final,...
        a_num_g,age_num,max_iter,v_tol,dist_tol,fco_fossil,fco_green,e_p,...
        d_0*(1+d0_gr)^trans_t,c_e_fossil,c_e_green_low,dem_tol,1,...
        e0_o,e_o_eps,rho_p_fossil,sigma_p_fossil,rho,10,exo_exit,...
        solar_cap_mean,solar_price_corr);
    save ss_fossil_green_final
end

%% No-policy green transition
init_dist_o = dist_fossil_old;
init_dist_n = zeros(1,age_num*a_num_g);
init_input_o = max(sum(init_dist_o),1);

try
    load transition_fossil_green_baseline
catch
    [trans_prob_o_all,v_new_resh_o_all,dist_o_all,measure_vec_o,p_e_o_vec,input_all_o,...
        trans_prob_n_all,v_new_resh_n_all,dist_n_all,measure_vec_n,p_E_vec,cap_old,cap_new,...
        age_g,a_grid_old,a_prob_old,a_grid_n_all,a_prob_n_all,entry_n_path,adopt_n_path,tax_revenue_path] = ...
        MIT_transition_green(a_grow,alpha,beta,c_a_fossil,c_a_green_vec,...
        a_grid_fossil_old,a_prob_fossil_old,mu_green_vec,sigma_green_vec,...
        a_num_g,age_num,max_iter,v_tol,fco_fossil,fco_green,e_p,d_0,...
        c_e_fossil,c_e_green_vec,dem_tol,init_dist_n,init_dist_o,...
        v_new_resh_o_final,v_new_resh_n_final,p_E_initial,p_E_final,trans_t,...
        dist_n_final,dist_o_final,e0_o,e_o_eps,p_e_o_final,p_e_fossil_initial,...
        rho,10,exit_n_final,exit_o_final,exo_exit,init_input_o,...
        1,1,d0_gr,rho_p_fossil,sigma_p_fossil,solar_cap_mean,solar_price_corr,zeros(1,trans_t));
    save transition_fossil_green_baseline
end

%% Temporary subsidy experiments
baseline.p_E_vec = p_E_vec;
baseline.green_share = cap_new./(cap_old+cap_new);
baseline.consumer_expenditure = electricity_expenditure_path(p_E_vec,d_0,d0_gr,e_p);

subsidy_cases = struct( ...
    "name",{"subsidy_small_once","subsidy_small_10period","subsidy_large_once"}, ...
    "amount",{0.05*c_e_green_low,0.05*c_e_green_low,0.20*c_e_green_low}, ...
    "duration",{1,10,1});

subsidy_results = struct([]);
for pp = 1:numel(subsidy_cases)
    subsidy_vec = zeros(1,trans_t);
    subsidy_vec(1:subsidy_cases(pp).duration) = subsidy_cases(pp).amount;
    c_e_policy = max(c_e_green_vec - subsidy_vec,0);
    c_a_policy = max(c_a_green_vec - subsidy_vec,0);

    [~,~,~,~,~,~,~,~,~,~,p_E_sub,cap_old_sub,cap_new_sub,...
        ~,~,~,~,~,entry_sub,adopt_sub,~] = ...
        MIT_transition_green(a_grow,alpha,beta,c_a_fossil,c_a_policy,...
        a_grid_fossil_old,a_prob_fossil_old,mu_green_vec,sigma_green_vec,...
        a_num_g,age_num,max_iter,v_tol,fco_fossil,fco_green,e_p,d_0,...
        c_e_fossil,c_e_policy,dem_tol,init_dist_n,init_dist_o,...
        v_new_resh_o_final,v_new_resh_n_final,p_E_initial,p_E_final,trans_t,...
        dist_n_final,dist_o_final,e0_o,e_o_eps,p_e_o_final,p_e_fossil_initial,...
        rho,10,exit_n_final,exit_o_final,exo_exit,init_input_o,...
        1,1,d0_gr,rho_p_fossil,sigma_p_fossil,solar_cap_mean,solar_price_corr,zeros(1,trans_t));

    green_share_sub = cap_new_sub./(cap_old_sub+cap_new_sub);
    subsidy_outlay = sum(subsidy_vec.*(entry_sub+adopt_sub));
    policy_expenditure = electricity_expenditure_path(p_E_sub,d_0,d0_gr,e_p);
    lower_electricity_cost = sum(max(baseline.consumer_expenditure-policy_expenditure,0));

    subsidy_results(pp).name = subsidy_cases(pp).name;
    subsidy_results(pp).subsidy_vec = subsidy_vec;
    subsidy_results(pp).p_E_vec = p_E_sub;
    subsidy_results(pp).green_share = green_share_sub;
    subsidy_results(pp).green_share_response = green_share_sub-baseline.green_share;
    subsidy_results(pp).entry_n_path = entry_sub;
    subsidy_results(pp).adopt_n_path = adopt_sub;
    subsidy_results(pp).subsidy_outlay = subsidy_outlay;
    subsidy_results(pp).lower_electricity_cost = lower_electricity_cost;
    subsidy_results(pp).net_consumer_cost = subsidy_outlay-lower_electricity_cost;
end
save transition_fossil_green_subsidy_experiments subsidy_results baseline subsidy_cases

%% Fossil fuel tax experiments
tax_cases = struct( ...
    "name",{"tax_small_once","tax_small_10period","tax_large_once"}, ...
    "amount",{0.05*p_e_fossil_initial,0.05*p_e_fossil_initial,0.20*p_e_fossil_initial}, ...
    "duration",{1,10,1});

tax_results = struct([]);
for pp = 1:numel(tax_cases)
    fossil_tax_vec = zeros(1,trans_t);
    fossil_tax_vec(1:tax_cases(pp).duration) = tax_cases(pp).amount;

    [~,~,~,~,~,input_old_tax,~,~,~,~,p_E_tax,cap_old_tax,cap_new_tax,...
        ~,~,~,~,~,~,~,tax_revenue] = ...
        MIT_transition_green(a_grow,alpha,beta,c_a_fossil,c_a_green_vec,...
        a_grid_fossil_old,a_prob_fossil_old,mu_green_vec,sigma_green_vec,...
        a_num_g,age_num,max_iter,v_tol,fco_fossil,fco_green,e_p,d_0,...
        c_e_fossil,c_e_green_vec,dem_tol,init_dist_n,init_dist_o,...
        v_new_resh_o_final,v_new_resh_n_final,p_E_initial,p_E_final,trans_t,...
        dist_n_final,dist_o_final,e0_o,e_o_eps,p_e_o_final,p_e_fossil_initial,...
        rho,10,exit_n_final,exit_o_final,exo_exit,init_input_o,...
        1,1,d0_gr,rho_p_fossil,sigma_p_fossil,solar_cap_mean,solar_price_corr,fossil_tax_vec);

    green_share_tax = cap_new_tax./(cap_old_tax+cap_new_tax);
    policy_expenditure = electricity_expenditure_path(p_E_tax,d_0,d0_gr,e_p);
    higher_electricity_cost = sum(max(policy_expenditure-baseline.consumer_expenditure,0));

    tax_results(pp).name = tax_cases(pp).name;
    tax_results(pp).fossil_tax_vec = fossil_tax_vec;
    tax_results(pp).p_E_vec = p_E_tax;
    tax_results(pp).green_share = green_share_tax;
    tax_results(pp).green_share_response = green_share_tax-baseline.green_share;
    tax_results(pp).input_old_path = input_old_tax;
    tax_results(pp).tax_revenue = sum(tax_revenue);
    tax_results(pp).tax_revenue_path = tax_revenue;
    tax_results(pp).higher_electricity_cost = higher_electricity_cost;
    tax_results(pp).net_consumer_cost = higher_electricity_cost-sum(tax_revenue);
end
save transition_fossil_green_tax_experiments tax_results baseline tax_cases

%% Summary plots
green_share = cap_new./(cap_old+cap_new);

ScSz = get(0,'ScreenSize');
figure(1)
plot(green_share,LineWidth=2)
xlabel('periods into transition'), ylabel('share')
title('green share of capacity')
set(gca,'Fontsize',24)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

figure(2)
plot(p_E_vec,LineWidth=2)
xlabel('periods into transition'), ylabel('electricity price')
title('electricity price path')
set(gca,'Fontsize',24)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

figure(3)
yyaxis left
plot(c_e_green_vec,LineWidth=2)
ylabel('green installation cost')
yyaxis right
plot(green_share,LineWidth=2)
ylabel('green share')
xlabel('periods into transition')
title('green installation cost shock and transition')
set(gca,'Fontsize',24)
set(gcf,'position',[0,0,ScSz(3),ScSz(4)]);

function expenditure = electricity_expenditure_path(p_E_vec,d_0,d0_gr,e_p)
d0_vec = d_0*(1+d0_gr).^(1:numel(p_E_vec));
quantity = d0_vec./(p_E_vec.^e_p);
expenditure = p_E_vec.*quantity;
end
