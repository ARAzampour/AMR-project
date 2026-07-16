%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  Sobol Calibration
%  Alireza Azampour, Maija Kaartinen
%  29/05/2026
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Runing iterations of the sobol random points around  the best
% parametrization to get the a proper calibration
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear
close all
clc
file_num = 1;
%% choose the parameters and setup
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


load('AMRsobol.mat')

n_iter_all  = 3000;
nfiles      = 300;


%%% calibration targets
p_E_m = 35; p_e_n_m = 12; p_e_o_m = 3.4;  %%% these numbers come from the papers
%%% in the literature (cited withthe help of gpt)
inp_ratio = 7; m_ratio = 3;
mean_eff = 0.37; tech_dist   = 1; feul_ce_ratio = 0.085; M_cap_age = 6.1;
mu_old = mu;
mu_new = mu-0.05;

%%% search bounds

lb  = [1.00,0.75,45,0.15,1.50,2.5,4.5];
ub  = [1.50,1.25,50,0.35,2.50,3.5,6.5];
%% VFI

%fmincoc(error,x1,x2

j   = file_num

params      = {};
FEs         = zeros(n_iter_all/nfiles,2);
first_id    = 1+(file_num-1) * n_iter_all/nfiles;
last_id     = file_num * n_iter_all/nfiles;



% [x,fval,exitflag,output]    = simulannealbnd(@(x)simulator(pr,phi_mode,grids,max_iter_vfi,tol_vfi,max_iter_tm,...
%     tol_tm,k,b,nl,mu,sigma,tol_vfi_offg,mode,x,policy,cc2,phi_m,phi_l),x0,lb,ub,options);
for i=first_id:last_id
    X   = zeros(1,length(lb)); %%% inputs to the simulator which are w, phi_m, cc2, zeta
                        %%% phi_l, fco, alpha, gamma, negdiv, cld
    iter_start = tic; 

    filename = fullfile('server-results',['results_tik_' num2str(j) '_' num2str(i)]);


    fprintf('---------------------------------------------------------------------------------------------------------\n')
    fprintf('Iteration %d of global search\n',i)
    

    try
        par_path    = fullfile('Results', strcat('params_', num2str(file_num), '.mat'));
        try
            load(par_path);
            X           = params{i};
        catch
            X(1)    = lb(1) + (AMRsobol(i ,1)+rand(1)*0.001)  * (ub(1) - lb(1));
            X(2)    = lb(2) + (AMRsobol(i ,2)+rand(1)*0.001)  * (ub(2) - lb(2));
            X(3)    = lb(3) + (AMRsobol(i ,3)+rand(1)*0.001)  * (ub(3) - lb(3));
            X(4)    = lb(4) + (AMRsobol(i ,4)+rand(1)*0.001)  * (ub(4) - lb(4));
            X(5)    = lb(5) + (AMRsobol(i ,5)+rand(1)*0.001)  * (ub(5) - lb(5));
            X(6)    = lb(6) + (AMRsobol(i ,6)+rand(1)*0.001)  * (ub(6) - lb(6));
            X(7)    = lb(7) + (AMRsobol(i ,7)+rand(1)*0.001)  * (ub(7) - lb(7));
           



        end
        
        [F]=simulatorNoSol(a_grow,alpha,a_bar...
                ,beta,X(1),X(2),mu_old,sigma,mu_new,sigma,a_num_g,age_num,max_iter,...
                    v_tol,dist_tol,fco_o,fco_n,e_p,X(3),c_of_e,c_e_new,dem_tol,tech_dist,...
                    X(4),X(5),e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,X(7),exo_exit,e_max,gamma,X(6),...
                    p_E_m,p_e_n_m,p_e_o_m,inp_ratio,m_ratio,mean_eff,feul_ce_ratio,M_cap_age,filename);
        
        
        
    catch

        X(1)    = lb(1) + (AMRsobol(i ,1)+rand(1)*0.001)  * (ub(1) - lb(1));
        X(2)    = lb(2) + (AMRsobol(i ,2)+rand(1)*0.001)  * (ub(2) - lb(2));
        X(3)    = lb(3) + (AMRsobol(i ,3)+rand(1)*0.001)  * (ub(3) - lb(3));
        X(4)    = lb(4) + (AMRsobol(i ,4)+rand(1)*0.001)  * (ub(4) - lb(4));
        X(5)    = lb(5) + (AMRsobol(i ,5)+rand(1)*0.001)  * (ub(5) - lb(5));
        X(6)    = lb(6) + (AMRsobol(i ,6)+rand(1)*0.001)  * (ub(6) - lb(6));
        X(7)    = lb(7) + (AMRsobol(i ,7)+rand(1)*0.001)  * (ub(7) - lb(7));
        
        if ~exist('server-results', 'dir')
            mkdir('server-results');
        end
        
        % Produce distance model vs data using fixed parameters (p), to be estimated parameters (params), weighting function (Weight), and data (Mdata) as input.
        try
           [F] = simulator(a_grow,alpha,a_bar...
                ,beta,X(1),X(2),mu_old,sigma,mu_new,sigma,a_num_g,age_num,max_iter,...
                    v_tol,dist_tol,fco_o,fco_n,e_p,X(3),c_of_e,c_e_new,dem_tol,tech_dist,...
                    X(4),X(5),e_n_eps,e_o_eps,rho_p_n,sigma_p_n,rho_p_o,sigma_p_o,rho,X(7),exo_exit,e_max,gamma,X(6),...
                    p_E_m,p_e_n_m,p_e_o_m,inp_ratio,m_ratio,mean_eff,feul_ce_ratio,M_cap_age,filename);
        catch
            warning('Error during iteration. Skipping current parameter set.')
            F = NaN;
        end
    end

   
    params{i} = X;
    FEs(i, :) = [i F];
    fprintf('ID: %5.0f\n', i)
    fprintf('Residual: %.4f\n',F)
    fprintf('Time Elapsed: %.0fs \n', toc(iter_start))
end

% 1.2. Save results

if ~exist('Results', 'dir')
    mkdir('Results');
end 

FE_path = fullfile('Results', strcat('FE_', num2str(file_num), '.mat'));
save(FE_path, 'FEs');
par_path = fullfile('Results', strcat('params_', num2str(file_num), '.mat'));
save(par_path, 'params');




fprintf("%6.6f \n",clock);
%% simulation



fprintf("%6.6f \n",clock);

%% figures









