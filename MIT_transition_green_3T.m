function result = MIT_transition_green_3T(coal,gas,green,common)
%MIT_TRANSITION_GREEN_3T Simultaneous coal, gas, and intermittent-green MIT.
%
% coal and gas contain paths for mu, sigma, entry_cost, adopt_cost, fco,
% e0, price, and the initial distribution.  Their elasticity fields are
% scalars and stay fixed through the green transition.  green contains its
% mu, sigma, entry/adoption/fixed-cost paths and intermittency parameters.
% Terminal value/distribution objects are supplied in each tech.final field.

common  = common_defaults(common);
T       = common.trans_t;
coal    = prepare_path(coal,common,false);
gas     = prepare_path(gas,common,false);
green   = prepare_path(green,common,true);
tech    = {coal,gas,green};
names   = ["coal","gas","green"];
age_g   = (0:common.age_num-1)';
age_factor = max(1-common.a_grow.*age_g',0);

for bb=1:3
    [tech{bb}.grid,tech{bb}.prob] = normal_path(tech{bb}.mu,tech{bb}.sigma,...
        common.a_num_g,T);
    tech{bb}.prob_matrix    = cell(T,1);
    tech{bb}.entry_prob     = zeros(common.a_num_g,T);
    for tt=1:T
        next    = min(tt+1,T);
        tech{bb}.prob_matrix{tt} = auto_corr_prob_transition2(...
            tech{bb}.grid(:,tt),tech{bb}.prob(:,next),common.rho,...
            tech{bb}.grid(:,next));
        tech{bb}.entry_prob(:,tt) = tech{bb}.prob(:,next);
    end
    tech{bb}.value      = zeros(common.age_num,common.a_num_g,T);
    tech{bb}.policy     = zeros(common.age_num*common.a_num_g,common.a_num_g,T);
    tech{bb}.exit_vec   = zeros(common.age_num*common.a_num_g,T);
    tech{bb}.trans_prob = zeros(common.age_num*common.a_num_g,T);
    tech{bb}.dist_path  = zeros(T,common.age_num*common.a_num_g);
    tech{bb}.measure    = zeros(1,T);
    tech{bb}.cap_path   = zeros(1,T);
    tech{bb}.adopt_path = zeros(1,T);
    tech{bb}.entry      = initial_entry_path(tech{bb},T);
    tech{bb}.entry_prev = tech{bb}.entry;
    tech{bb}.value_err_prev = zeros(T,1);
    tech{bb}.entry_adjust   = 0.1*ones(1,T);
end

PE      = common.P_E_grid_norm(:);
dlog_PE = log_scale_weight_derivative(PE);
for bb=1:2
    tech{bb}.pe_grid    = p_input_grid(10,1,tech{bb}.sigma_p,tech{bb}.rho_p);
    tech{bb}.dlog_pe    = log_scale_weight_derivative(tech{bb}.pe_grid);
    tech{bb}.p_e        = linspace(tech{bb}.init_price,tech{bb}.final.p_e,T);
    tech{bb}.p_e_prev   = tech{bb}.p_e;
    tech{bb}.input_path = tech{bb}.init_input*ones(1,T+1);
    tech{bb}.input_err_prev = ones(1,T);
    tech{bb}.input_adjust   = 0.5*ones(1,T);
    tech{bb}.anchor         = cell(T,1);
    tech{bb}.tax_revenue    = zeros(1,T);
end
[solar_cap,~] = solar_availability_grid(PE,green.solar_cap_mean,...
    green.solar_price_corr);

p_E         = linspace(common.init_p_E,common.final_p_E,T);
p_E_prev    = p_E;
demand_err_prev = ones(1,T);
output_adjust   = 0.1/max(common.e_p,sqrt(eps))*ones(1,T);
d0_vec          = common.d_0*(1+common.d0_gr).^(1:T);
max_iter_price  = max(1,floor(common.max_iter/10));
workers         = common.static_solver_workers;
checkpoint_file = checkpoint_filename(field_or(common,"checkpoint_name",""));
use_checkpoint  = strlength(checkpoint_file)>0;
checkpoint_freq = 50;
h_start = 1;
k_start = 1;
loaded_checkpoint = false;
if use_checkpoint && isfile(checkpoint_file)
    try
        loaded  = load(checkpoint_file,"checkpoint");
        [p_E,p_E_prev,demand_err_prev,output_adjust,tech,h_start,k_start] = ...
            restore_checkpoint(loaded.checkpoint,tech);
        loaded_checkpoint = true;
        fprintf("Loaded green 3T checkpoint %s; resuming at h=%d, k=%d\n",...
            checkpoint_file,h_start,k_start);
    catch
        fprintf("No usable green 3T checkpoint at %s\n",checkpoint_file);
    end
end
if ~loaded_checkpoint
    warm = field_or(common,"warm_start",[]);
    if ~isempty(warm)
        [p_E,p_E_prev,demand_err_prev,tech] = warm_start_from_baseline(...
            warm,tech,names,T);
        h_start = 1;
        k_start = 1;
        fprintf("Warm-started green 3T from the baseline transition at h=1, k=1\n");
    elseif use_checkpoint
        fprintf("No green 3T checkpoint found at %s; starting from scratch\n",...
            checkpoint_file);
    end
end

demand_err  = zeros(1,T);
total_cap   = zeros(1,T);
for bb=1:2, tech{bb}.input_err = zeros(1,T); end
for bb=1:3, tech{bb}.value_err = zeros(T,1); end

for h=h_start:common.max_iter
    if ~(h==h_start && k_start>1)

        output_adjust(:) = 0.2/max(common.e_p,sqrt(eps));
        for bb=1:2, tech{bb}.input_adjust(:)=0.25; end
    end
    k_first = 1;

    if h==h_start, k_first = k_start; end

    for k=k_first:max_iter_price
        static = cell(3,T);
        if workers>1
            parfor (tt=1:T,workers)
                static(:,tt) = static_period(tech,tt,age_factor,p_E,PE,...
                    dlog_PE,solar_cap,common);
            end
        else
            for tt=1:T
                static(:,tt) = static_period(tech,tt,age_factor,p_E,PE,...
                    dlog_PE,solar_cap,common);
            end
        end
        for bb=1:2
            tech{bb}.anchor = static(bb,:);
        end

        for bb=1:3
            value_next = tech{bb}.final.value;
            for tt=T:-1:1
                next_period = min(tt+1,T);
                if bb==2
                    adopt_cost = birth_year_cost(tech{bb}.adopt_cost,tt,common.age_num);
                else
                    adopt_cost = tech{bb}.adopt_cost(tt);
                end
                %%% value function is called
                [value,policy,exit_vec] = value_step(double(static{bb,tt}.pi)',...
                    value_next,tech{bb}.prob_matrix{tt},common.beta,adopt_cost,...
                    common.age_reduc,common.exo_exit,common.adoption_smoothing,...
                    tech{bb}.grid(:,tt),tech{bb}.grid(:,next_period));
                tech{bb}.value(:,:,tt)  = value;
                tech{bb}.policy(:,:,tt) = policy;
                tech{bb}.exit_vec(:,tt) = exit_vec;
                tech{bb}.trans_prob(:,tt) = sum(policy.*repmat(...
                    tech{bb}.prob_matrix{tt},common.age_num,1),2);
                value_next = value;
            end
        end

        dist = {coal.init_dist,gas.init_dist,green.init_dist};
        input_implied = zeros(2,T);
        for tt=1:T
            for bb=1:3
                next_period     = min(tt+1,T);
                %%% transition function is called
                transition      = plant_transition(tech{bb}.policy(:,:,tt),...
                    tech{bb}.exit_vec(:,tt),tech{bb}.prob_matrix{tt},...
                    common.age_reduc,common.exo_exit,...
                    tech{bb}.grid(:,tt),tech{bb}.grid(:,next_period));

                cap     = double(static{bb,tt}.cap);
                tech{bb}.cap_path(tt)   = dist{bb}*cap(:);
                tech{bb}.adopt_path(tt) = dist{bb}*tech{bb}.trans_prob(:,tt);

                if bb<=2
                    input       = dist{bb}*double(static{bb,tt}.eff(:));
                    tech{bb}.input_path(tt+1)   = input;
                    %%% the price that fuel suply is willing to accept considering that it
                    %%% will incure losses from changes in the changes between periods
                    input_implied(bb,tt)        = (max(input,0)/max(tech{bb}.e0(tt),sqrt(eps))*...
                        (max(input,0)/max(tech{bb}.input_path(tt),sqrt(eps)))^...
                        tech{bb}.fuel_penalty)^(1/tech{bb}.elasticity);

                    tech{bb}.tax_revenue(tt)    = tech{bb}.tax(tt)*input;
                end
                dist{bb}    = dist{bb}*transition+tech{bb}.entry(tt)*...
                    entrant_dist(tech{bb}.entry_prob(:,tt)',common);

                tech{bb}.dist_path(tt,:)    = dist{bb};
                tech{bb}.measure(tt)        = sum(dist{bb});
            end
        end

        total_cap       = tech{1}.cap_path+tech{2}.cap_path+tech{3}.cap_path;
        cap_lag         = [common.d_0/common.init_p_E^common.e_p,total_cap(1:end-1)];
        %%% the price that demand side is willing to pay considering that it
        %%% will incure losses from changes in the changes between periods
        supply_price    = (d0_vec./max(total_cap.*...
            (total_cap./max(cap_lag,sqrt(eps))).^common.demand_penalty,...
            sqrt(eps))).^(1/common.e_p);
        demand_err      = max(min(supply_price-p_E,25),-25);
        %%% update electricity prices
        [p_E,p_E_prev,demand_err_prev,output_adjust] = update_price(...
            p_E,p_E_prev,demand_err,demand_err_prev,output_adjust);

        fuel_converged = true;
        for bb=1:2
            input_err   = max(min(input_implied(bb,:)-tech{bb}.p_e,25),-25);
            %%% update input fuel prices
            [tech{bb}.p_e,tech{bb}.p_e_prev,tech{bb}.input_err_prev,...
                tech{bb}.input_adjust] = update_price(tech{bb}.p_e,...
                tech{bb}.p_e_prev,input_err,tech{bb}.input_err_prev,...
                tech{bb}.input_adjust);

            tech{bb}.input_err  = input_err;
            fuel_converged      = fuel_converged && mean(abs(input_err)<common.dem_tol |...
                (abs(tech{bb}.p_e-tech{bb}.p_e_prev)<5*common.v_tol & ...
                k>max_iter_price/5))>0.99;
        end
        if mod(k,50)==0
            fprintf("green 3T MIT h=%d, k=%d, mean errors demand=%g coal fuel=%g gas fuel=%g\n",...
                h,k,mean(abs(demand_err)),mean(abs(tech{1}.input_err)),...
                mean(abs(tech{2}.input_err)));
            [p_E,p_E_prev,notch_dates] = smooth_notched_price(p_E,p_E_prev,total_cap);
            for bb=1:2
                [tech{bb}.p_e,tech{bb}.p_e_prev,fuel_notches] = ...
                    smooth_notched_price(tech{bb}.p_e,tech{bb}.p_e_prev,total_cap);
                notch_dates = union(notch_dates,fuel_notches);
            end
            if ~isempty(notch_dates)
                fprintf("green 3T MIT smoothed price notches at dates %s\n",...
                    strjoin(string(notch_dates)," "));
            end
        end

        demand_converged    = mean(abs(demand_err)<common.dem_tol |...
            (abs(p_E-p_E_prev)<5*common.v_tol & k>max_iter_price/5))>0.99;

        if use_checkpoint && mod(k,checkpoint_freq)==0
            save_3t_checkpoint(checkpoint_file,h,k+1,p_E,p_E_prev,...
                demand_err_prev,output_adjust,tech);
        end
        
        if demand_converged && fuel_converged, break; end

    end

    active          = 1:max(T-1,1);
    entry_converged = true;
    terminal_converged = true;

    for bb=1:3
        err = zeros(T,1);
        if T>1
            next_value      = reshape(tech{bb}.value(1,:,2:end),common.a_num_g,T-1);
            err(1:end-1)    = sum(tech{bb}.entry_prob(:,1:end-1).*next_value,1)'-...
                tech{bb}.entry_cost(1:end-1)';
        end
        err(end)    = tech{bb}.entry_prob(:,end)'*tech{bb}.final.value(1,:)'-...
            tech{bb}.entry_cost(end);
        tech{bb}.value_err  = err;
        entry_converged     = entry_converged && mean(abs(err(active))<common.dem_tol |...
            tech{bb}.entry(active)'<common.v_tol)>=0.99;
        terminal_converged  = terminal_converged && ...
            abs(sum(tech{bb}.final.dist)-tech{bb}.measure(end))<common.dem_tol;
    end
    if mod(h,10)==0
        fprintf("green 3T MIT h=%d after k=%d, mean entry errors coal=%g gas=%g green=%g\n",...
            h,k,mean(abs(tech{1}.value_err(active))),...
            mean(abs(tech{2}.value_err(active))),...
            mean(abs(tech{3}.value_err(active))));
    end
    if entry_converged && terminal_converged, break; end

    for bb=1:3
        %%% will update entry of each tech in each period
        [tech{bb}.entry,tech{bb}.entry_prev,tech{bb}.entry_adjust] = ...
            update_entry(tech{bb}.entry,tech{bb}.value_err,...
            tech{bb}.value_err_prev,tech{bb}.entry_prev,...
            tech{bb}.entry_adjust,common.v_tol);
        tech{bb}.value_err_prev = tech{bb}.value_err;
        if T>1
            tech{bb}.entry(end) = sum(tech{bb}.final.dist)-...
                (1-common.exo_exit)*tech{bb}.measure(end-1);
        end
    end
    if use_checkpoint
        save_3t_checkpoint(checkpoint_file,h+1,1,p_E,p_E_prev,...
            demand_err_prev,output_adjust,tech);
    end
end

result = struct("p_E",p_E,"total_cap",total_cap,"age_g",age_g,...
    "iterations",struct("h",h,"k",k));
for bb=1:3
    tech{bb}.input_path = tech{bb}.input_path(1:T);
    result.(names(bb))  = clean_result(tech{bb});
end
result.tax_revenue  = tech{1}.tax_revenue+tech{2}.tax_revenue;
result.errors       = struct("demand",demand_err,"coal_fuel",tech{1}.input_err,...
    "gas_fuel",tech{2}.input_err,"coal_entry",tech{1}.value_err,...
    "gas_entry",tech{2}.value_err,"green_entry",tech{3}.value_err);
fprintf("green 3T MIT finished at h=%d, k=%d; mean errors demand=%g, coal fuel=%g, gas fuel=%g.\n",...
    h,k,mean(abs(demand_err)),mean(abs(tech{1}.input_err)),...
    mean(abs(tech{2}.input_err)));
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%% Auxiliary Functions %%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function common = common_defaults(common)
defaults = struct("a_grow",0.005,"alpha",1.9,"beta",0.97,"rho",0.6,...
    "exo_exit",0.01,"e_p",0.75,"d_0",100,"d0_gr",0.01,...
    "a_num_g",50,"age_num",80,"max_iter",30000,"v_tol",1e-5,...
    "dem_tol",0.01,"age_reduc",10,"adoption_smoothing",2,...
    "demand_penalty",1,"init_p_E",35,"final_p_E",35,...
    "P_E_grid_norm",P_E_grid(50,1),"static_solver_workers",0);
for name=string(fieldnames(defaults))'
    if ~isfield(common,name)||isempty(common.(name)), common.(name)=defaults.(name); end
end
end


function tech = prepare_path(tech,common,is_green)
T       = common.trans_t;
fields  = ["mu","sigma","fco","adopt_cost","entry_cost"];
for name=fields, tech.(name)=fit_row(tech.(name),T); end
tech.init_dist      = reshape(tech.init_dist,1,[]);
tech.final.value    = tech.final.value;
tech.final.dist     = reshape(tech.final.dist,1,[]);
if is_green
    tech.solar_cap_mean     = field_or(tech,"solar_cap_mean",0.25);
    tech.solar_price_corr   = field_or(tech,"solar_price_corr",0.6);
    tech.tax                = zeros(1,T);
    tech.init_input         = 0;
    tech.input_path         = zeros(1,T+1);
else
    tech.e0         = fit_row(tech.e0,T);
    tech.elasticity = tech.elasticity(1);
    tech.rho_p      = tech.rho_p(1);
    tech.sigma_p    = tech.sigma_p(1);
    tech.fuel_penalty = field_or(tech,"fuel_penalty",1);
    tech.tax        = fit_row(field_or(tech,"tax",0),T);
end
end

function [grid,prob] = normal_path(mu,sigma,N,T)
grid = zeros(N,T);
prob = zeros(N,T);
for tt=1:T
    x   = norminv(linspace(0,1,N+2),mu(tt),sigma(tt));
    grid(:,tt)  = x(2:N+1)';
    cdf         = normcdf(x,mu(tt),sigma(tt));
    p           = (cdf(2:N+1)-cdf(1:N))';
    prob(:,tt)  = p/sum(p);
end
assert(all(grid>0,"all"),"Efficiency grids must be positive.");
end

%%%%%%%%%%%%%%% Solves for the period generation and profits %%%%%%%%%%%%%%%
function out = static_period(tech,tt,age_factor,p_E,PE,dlog_PE,solar_cap,common)
out = cell(3,1);
for bb=1:2
    a_eff   = tech{bb}.grid(:,tt).*age_factor;
    %%%% profit maximizing of fossil generators
    out{bb} = static_solver_anchor(a_eff,p_E(tt),tech{bb}.p_e(tt)+tech{bb}.tax(tt),...
        PE,tech{bb}.pe_grid,common.alpha,tech{bb}.fco(tt),...
        1./tech{bb}.grid(:,tt),dlog_PE,tech{bb}.dlog_pe,...
        tech{bb}.anchor{tt},0.02);
end
a_eff   = tech{3}.grid(:,tt).*age_factor;
%%% expected profit of the solar plants
[eff,cap,pi] = solar_static_solver(a_eff,p_E(tt).*PE,solar_cap,tech{3}.fco(tt));
out{3} = struct("eff",single(eff),"cap",single(cap),"pi",single(pi));
end

%%%%%%%%%%%%%%% solving for the value function in each step %%%%%%%%%%%%%%%
function [value,policy,exit_vec] = value_step(profit,next_value,prob,beta,cost,...
        age_reduc,exo_exit,smooth_rate,grid_now,grid_next)
% Exit uses the expected continuation before current profit is added,
% matching the coal-gas transition. A negative continuation exits for
% sure; a positive one exits with probability exp(-continuation * 10^rate).
[expected,choice] = expected_adoption(next_value,prob,cost,age_reduc,...
    smooth_rate,grid_now,grid_next);
negative    = expected<0;
exit_prob   = soft_exit(expected,negative,smooth_rate);
value       = profit+beta*(1-exo_exit)*expected;
value(negative) = 0;
exit_vec    = reshape(exit_prob',[],1);
policy      = pack_policy(choice,exit_vec);
end

function cost = birth_year_cost(adopt_path,period,age_num)
% Age 0 pays this period's adoption cost. Age a pays the cost from the
% year that cohort entered, or the first transition cost if it is older.
birth   = max(period-(0:age_num-1),1);
cost    = reshape(adopt_path(birth),[],1);
end

function [expected,choice] = expected_adoption(next_value,prob,cost,age_reduc,...
        smooth_rate,grid_now,grid_next)
% Adopters draw a destination type. Plants that do not adopt keep their
% efficiency; a moving grid only interpolates that point onto the next grid.
[age_num,n_type]    = size(next_value);
[index,ratio]       = grid_neighbors(grid_now,grid_next);
older               = [next_value(2:end,:);zeros(1,n_type)];
continuation        = older(:,index).*(1-ratio)'+older(:,max(index-1,1)).*ratio';
young               = max((1:age_num)'-age_reduc,1);
adoption            = next_value(young,:);
if isscalar(cost)
    adoption = adoption-cost;
else
    adoption = adoption-cost(:);
end
gain        = reshape(adoption,age_num,1,n_type)-reshape(continuation,age_num,n_type,1);
choice      = zeros(size(gain));
positive    = gain>0;
choice(positive) = 1-exp(-smooth_rate*gain(positive));
best        = reshape(continuation,age_num,n_type,1)+gain.*choice;
expected    = reshape(sum(best.*reshape(prob,1,n_type,n_type),3),age_num,n_type);
end

function exit_prob = soft_exit(level,negative,smooth_rate)
exit_prob = double(negative)+(1-double(negative)).*exp(-level.*(10^smooth_rate));
exit_prob(isnan(exit_prob)) = 1;
end

function policy = pack_policy(choice,exit_vec)
[age_num,n_type,~] = size(choice);
policy  = zeros(age_num*n_type,n_type);
for age=1:age_num
    rows    = (age-1)*n_type+(1:n_type);
    block   = reshape(choice(age,:,:),n_type,n_type);
    policy(rows,:) = block.*(1-exit_vec(rows));
end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%% transition function %%%%%%%%%%%%%%%%%%%%%%%%%%%
function transition = plant_transition(policy,exit_vec,prob,age_reduc,exo_exit,...
        grid_now,grid_next)
% Maximum-age plants exit. Their mass is not replaced inside the transition.
[n_state,n_type]    = size(policy);
age_num             = n_state/n_type;
[index,ratio]       = grid_neighbors(grid_now,grid_next);
source              = repelem((1:n_state)',n_type);
dest_type           = repmat((1:n_type)',n_state,1);
state_age           = repelem(repelem((1:age_num)',n_type),n_type);
origin_expanded     = repmat(repelem((1:n_type)',n_type),age_num,1);
adopt_prob          = prob(sub2ind(size(prob),origin_expanded,dest_type));
adopt_values        = adopt_prob.*reshape(policy',[],1).*...
    repelem(1-exit_vec,n_type)*(1-exo_exit);
adopt_target        = (max(state_age-age_reduc,1)-1)*n_type+dest_type;
stay                = sum((1-policy).*repmat(prob,age_num,1),2).*(1-exit_vec)*(1-exo_exit);
origin              = repmat((1:n_type)',age_num,1);
plant_age           = repelem((1:age_num)',n_type);
keep                = plant_age<age_num;
next_age            = plant_age+1;
high_type           = index(origin);
low_type            = max(high_type-1,1);
transition          = sparse(source,adopt_target,adopt_values,n_state,n_state)+...
    sparse(find(keep),(next_age(keep)-1)*n_type+high_type(keep),...
        stay(keep).*(1-ratio(origin(keep))),n_state,n_state)+...
    sparse(find(keep),(next_age(keep)-1)*n_type+low_type(keep),...
        stay(keep).*ratio(origin(keep)),n_state,n_state);

transition((age_num-1)*n_type+1:n_state,:) = 0;
end

function [index,ratio] = grid_neighbors(grid_now,grid_next)
grid_now    = grid_now(:);
grid_next   = grid_next(:);
n           = numel(grid_now);
index = zeros(n,1);
for ii=1:n
    found = find(grid_now(ii)<=grid_next,1,"first");
    if isempty(found), found = n; end
    index(ii) = found;
end
index = min(max(index,2),n);
span = grid_next(index)-grid_next(index-1);
ratio = (grid_next(index)-grid_now)./span;
ratio(~isfinite(ratio)) = 0;
ratio = min(max(ratio,0),1);
end

function dist = entrant_dist(prob,common)
dist = zeros(1,common.a_num_g*common.age_num);
dist(1:common.a_num_g) = prob;
end

function path = initial_entry_path(tech,T)
if isfield(tech,"entry_guess_path") && ~isempty(tech.entry_guess_path)
    path = max(fit_row(tech.entry_guess_path,T),0);
    return
end
base    = 1+exp(linspace(0,-10,T));
target  = (sum(tech.final.dist)-sum(tech.init_dist))/T+max(tech.final.exit_mass,0);
path    = max(target,1e-8)*T*base/sum(base);
end


function [path,previous,adjust] = update_entry(path,error,error_previous,previous,adjust,tol)
lag     = path;
active  = 1:max(numel(path)-1,1);
restart = path(active)==0 & error(active)'>0;
path(active(restart)) = max(10*tol,1e-8);
step    = 0.1*(abs(error(active)')>50)+0.2*(abs(error(active)')<=50)+...
    0.2*(abs(error(active)')<=1);

path(active)    = path(active).*(1+step.*adjust(active).*error(active)');
oscill          = false(size(path));
oscill(active)  = sign(error(active)')~=sign(error_previous(active)');

den         = max(abs(error(active)')+abs(error_previous(active)'),sqrt(eps));
idx         = active(oscill(active));
path(idx)   = (lag(idx).*abs(error_previous(idx)')+...
    previous(idx).*abs(error(idx)'))./den(oscill(active));

adjust      = max(adjust.*(0.99.^double(oscill)),0.05);
path(active) = max(path(active),0);
previous    = lag;
end

function [price,previous,notch_dates] = smooth_notched_price(price,previous,total_cap)
% A one-period capacity drop that reverses is not produced by entry. If the
% price at that date is also away from its neighbors, replace it by their average.
price       = reshape(price,1,[]);
previous    = reshape(previous,1,[]);
total_cap   = reshape(total_cap,1,[]);
notch_dates = [];
repaired    = price;
for t=2:numel(total_cap)-1
    reference   = total_cap(t-1);
    if reference<=0, continue; end
    
    drop        = reference-total_cap(t);
    if drop<=0.01*reference, continue; end

    if total_cap(t+1)-total_cap(t)<0.5*drop, continue; end

    neighbor    = 0.5*(price(t-1)+price(t+1));
    if neighbor<=0 || abs(price(t)-neighbor)<=0.01*neighbor, continue; end

    repaired(t) = neighbor;
    notch_dates(end+1) = t; %
end
price = repaired;
previous(notch_dates) = price(notch_dates);
end

function [path,previous,error_previous,adjust] = update_price(path,previous,error,error_previous,adjust)
tentative   = path+0.1*adjust.*error;
oscill      = sign(error)~=sign(error_previous);
den         = max(abs(error)+abs(error_previous),sqrt(eps));
tentative(oscill) = (path(oscill).*abs(error_previous(oscill))+...
    previous(oscill).*abs(error(oscill)))./den(oscill);
adjust      = max(adjust.*(0.99.^double(oscill)),0.05);
previous    = path;
path        = max(tentative,sqrt(eps));
error_previous = error;
end

function out = clean_result(tech)
drop = ["prob_matrix","policy","exit_vec","pe_grid","dlog_pe","anchor",...
    "entry_prev","value_err_prev","entry_adjust","input_err_prev","input_adjust"];
out = tech;
for name=drop, if isfield(out,name), out=rmfield(out,name); end, end
end

function [cap,order] = solar_availability_grid(PE,mean_cap,corr)
[~,order]   = sort(PE,"ascend");
sorted      = linspace(1+corr,1-corr,numel(PE))';
cap = zeros(size(sorted)); cap(order)=sorted;
cap = max(min(mean_cap*cap/mean(cap),1),0);
end

function out = fit_row(value,T)
value = reshape(value,1,[]);
if numel(value)>=T, out=value(1:T); else, out=[value,repmat(value(end),1,T-numel(value))]; end
end

function value = field_or(S,name,fallback)
if isfield(S,name)&&~isempty(S.(name)), value=S.(name); else, value=fallback; end
end

function file = checkpoint_filename(name)
if ~(isstring(name) || ischar(name))
    file = "";
    return
end
file = string(name);
if strlength(file)>0 && ~endsWith(file,".mat")
    file = file+".mat";
end
end

function save_3t_checkpoint(file,h_start,k_start,p_E,p_E_prev,demand_err_prev,...
        output_adjust,tech)
checkpoint = struct("h_start",h_start,"k_start",k_start,"p_E",p_E,...
    "p_E_prev",p_E_prev,"demand_err_prev",demand_err_prev,...
    "output_adjust",output_adjust);
for bb=1:3
    checkpoint.tech(bb).entry = tech{bb}.entry;
    checkpoint.tech(bb).entry_prev = tech{bb}.entry_prev;
    checkpoint.tech(bb).value_err_prev = tech{bb}.value_err_prev;
    checkpoint.tech(bb).entry_adjust = tech{bb}.entry_adjust;
end
for bb=1:2
    checkpoint.tech(bb).p_e = tech{bb}.p_e;
    checkpoint.tech(bb).p_e_prev = tech{bb}.p_e_prev;
    checkpoint.tech(bb).input_err_prev = tech{bb}.input_err_prev;
    checkpoint.tech(bb).input_adjust = tech{bb}.input_adjust;
end
save(file,"checkpoint");
end

function [p_E,p_E_prev,demand_err_prev,tech] = warm_start_from_baseline(...
        baseline,tech,names,T)
% Copy solved prices and entry. Step sizes and the iteration counter stay at
% their initial values so the policy shock can still move the path.
p_E         = fit_row(baseline.p_E,T);
p_E_prev    = p_E;
demand_err_prev = zeros(1,T);
if isfield(baseline,"errors") && isfield(baseline.errors,"demand")
    demand_err_prev = fit_row(baseline.errors.demand,T);
end
fuel_err_name   = ["coal_fuel","gas_fuel"];
entry_err_name  = ["coal_entry","gas_entry","green_entry"];
for bb=1:3
    tech{bb}.entry      = fit_row(baseline.(names(bb)).entry,T);
    tech{bb}.entry_prev = tech{bb}.entry;
    if isfield(baseline,"errors") && isfield(baseline.errors,entry_err_name(bb))
        err = baseline.errors.(entry_err_name(bb));
        tech{bb}.value_err_prev = reshape(err(1:min(end,T)),[],1);
        if numel(tech{bb}.value_err_prev)<T
            tech{bb}.value_err_prev(end+1:T,1) = tech{bb}.value_err_prev(end);
        end
    end
end
for bb=1:2
    tech{bb}.p_e        = fit_row(baseline.(names(bb)).p_e,T);
    tech{bb}.p_e_prev   = tech{bb}.p_e;
    if isfield(baseline,"errors") && isfield(baseline.errors,fuel_err_name(bb))
        tech{bb}.input_err_prev = fit_row(baseline.errors.(fuel_err_name(bb)),T);
    end
end
end

function [p_E,p_E_prev,demand_err_prev,output_adjust,tech,h_start,k_start] = ...
        restore_checkpoint(checkpoint,tech)
p_E         = checkpoint.p_E;
p_E_prev    = checkpoint.p_E_prev;
demand_err_prev = checkpoint.demand_err_prev;
output_adjust   = checkpoint.output_adjust;
h_start = checkpoint.h_start;
k_start = checkpoint.k_start;
for bb=1:3
    tech{bb}.entry      = checkpoint.tech(bb).entry;
    tech{bb}.entry_prev = checkpoint.tech(bb).entry_prev;
    tech{bb}.value_err_prev = checkpoint.tech(bb).value_err_prev;
    tech{bb}.entry_adjust   = checkpoint.tech(bb).entry_adjust;
end
for bb=1:2
    tech{bb}.p_e        = checkpoint.tech(bb).p_e;
    tech{bb}.p_e_prev   = checkpoint.tech(bb).p_e_prev;
    tech{bb}.input_err_prev = checkpoint.tech(bb).input_err_prev;
    tech{bb}.input_adjust   = checkpoint.tech(bb).input_adjust;
end
end
