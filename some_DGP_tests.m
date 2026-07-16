m = 0.4; % mean
v = 0.015; % variance
mu = log((m^2)/sqrt(v+m^2));
sigma = sqrt(log(v/(m^2)+1));
% test = lognrnd(mu,sigma,[2000,1]);
% test(test>1) = 1;
% hist(test)
% m2 = 0.025;v2 = 0.0005; % variance
% mu2 = log((m2^2)/sqrt(v2+m2^2));
% sigma2 = sqrt(log(v2/(m2^2)+1));
% test2 = lognrnd(mu2,sigma2,[2000,1]);
% test2(test2>.1) = .1;
% test3 = test-test2;
% figure(2)
% hist(test2)
% 
% figure(3)
% hist(test3)
% 
% t_vec = randi(10,2000,1);
% 
% test22 = lognrnd(mu2,sigma2,[2000,1]);
% test22(test22>.1) = .1;
% 
% test4 = test3 - t_vec*0.01 - (t_vec.^2)*4.5*10^-6-test22;
% 
% t_vec(test4<0.05) = 0;
% test4(test4<0.05) = 0.05;

I   = 5000; %% number of plants 
T   = 100; %% periods
init_effs   =  lognrnd(mu,sigma,[I,1]);
init_effs(init_effs>0.75) = 0.75;
init_eff_al = zeros(I,T);
new_effs    = zeros(I,T);
new_effs(:,1)   = init_effs;
init_eff_al(:,1)= init_effs;
decay       = 0.015;
decay_squ   = 0.0015;%%25
t_vec       = ones(I,T);

eff_now     = init_effs;

for t=2:1:T
    eff_now         = init_effs .* exp(- t_vec(:,t-1)*decay - (t_vec(:,t-1).^2)*decay_squ) ...
        + normrnd(0,1.0*v,I,1)  ;
    updating        = (eff_now./init_effs)<0.75;
    t_vec(:,t)      = t_vec(:,t-1) + 1;
    
    update_Del_eff      = normrnd(0,0.8*v,I,1);
    update_Del_eff(abs(update_Del_eff)>0.05) = 0.05;
    init_effs(updating) = init_effs(updating) + update_Del_eff(updating);
    init_effs(init_effs>0.75) = 0.75;
    init_effs(init_effs<0.05) = 0.05;
    eff_now(updating)   = init_effs(updating);
    
    

    new_effs(:,t)       = eff_now .* (1+normrnd(0,1.0*v,I,1)+binornd(1,0.5,I,1).*normrnd(0,3.0*v,I,1));
    new_effs(new_effs(:,t)<0.01,t) = 0.01;

    all_updates = (new_effs(:,t)>(new_effs(:,t-1)+0.05))|updating;
    t_vec(all_updates,t)    = 1;
    init_eff_al(:,t)        = init_effs;


end

update_time     = t_vec==1;
update_time(:,1)    = 0;
update_time(:,end)  = 0;
after_update    = [zeros(I,1,"logical"),update_time(:,1:end-1)];
%%
update_effs     = new_effs(update_time);
after_up_effs   = new_effs(after_update);

t_vec_reg       = [zeros(I,1),t_vec(:,1:end-1)]; 
t_vec_reg(t_vec==1) = 0;

[b1,bint1,r1,rint1,stats1]   = regress(log(after_up_effs(:)),[ones(length(after_up_effs(:)),1),...
    log(update_effs(:))]); %%,t_vec(:).^2


[b,bint,r,rint,stats]   = regress(log(new_effs(:)),[ones(length(new_effs(:)),1),...
    log(init_eff_al(:)),t_vec_reg(:),t_vec_reg(:).^2]); %%,t_vec(:).^2


% %%
% eff_now         = init_effs .* exp(- t_vec(:,t-1)*decay - (t_vec(:,t-1).^2)*decay_squ) ...
%     + normrnd(0,1.0*v,I,1)  ;
% updating        = (eff_now./init_effs)<0.75;
% t_vec(:,t)      = t_vec(:,t-1) + 1;
% 
% update_Del_eff      = normrnd(0,0.8*v,I,1);
% update_Del_eff(abs(update_Del_eff)>0.05) = 0.05;
% init_effs(updating) = init_effs(updating) + update_Del_eff(updating);
% init_effs(init_effs>0.75) = 0.75;
% init_effs(init_effs<0.05) = 0.05;
% eff_now(updating)   = init_effs(updating);
% 
% 
% 
% new_effs(:,t)       = eff_now .* (1+normrnd(0,1.0*v,I,1)+binornd(1,0.5,I,1).*normrnd(0,3.0*v,I,1));
% new_effs(new_effs(:,t)<0.01,t) = 0.01;
% 
% all_updates = new_effs(:,t)>(new_effs(:,t-1)+0.05);
% t_vec(all_updates,t)    = 1;
% init_eff_al(:,t)        = init_effs;