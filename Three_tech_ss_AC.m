function result = Three_tech_ss_AC(coal,gas,green,common)
%THREE_TECH_SS_AC Steady state with separate coal, gas, and green branches.
%
% Each technology is passed as a structure.  Fossil structures require
% mu/sigma (or grid/prob), fco, adopt_cost, entry_cost, e0, elasticity,
% rho_p, and sigma_p.  Green requires mu/sigma, fco, adopt_cost,
% entry_cost, solar_cap_mean, and solar_price_corr.  Optional fields are
% entry_guess and p_e_guess.  Shared parameters are in common.

common = common_defaults(common);
coal = prepare_tech(coal,common,false);
gas = prepare_tech(gas,common,false);
green = prepare_tech(green,common,true);

age_g = (0:common.age_num-1)';
age_factor = max(1-common.a_grow.*age_g',0);
coal.a_eff = coal.grid'.*age_factor;
gas.a_eff = gas.grid'.*age_factor;
green.a_eff = green.grid'.*age_factor;
coal.prob_matrix = auto_corr_prob(coal.grid,coal.prob,common.rho);
gas.prob_matrix = auto_corr_prob(gas.grid,gas.prob,common.rho);
green.prob_matrix = auto_corr_prob(green.grid,green.prob,common.rho);

PE = common.P_E_grid_norm(:);
dlog_PE = log_scale_weight_derivative(PE);
coal.pe_grid = p_input_grid(10,1,coal.sigma_p,coal.rho_p);
gas.pe_grid = p_input_grid(10,1,gas.sigma_p,gas.rho_p);
coal.dlog_pe = log_scale_weight_derivative(coal.pe_grid);
gas.dlog_pe = log_scale_weight_derivative(gas.pe_grid);
[solar_cap,~] = solar_availability_grid(PE,green.solar_cap_mean,...
    green.solar_price_corr);

p_E = field_or(common,"p_E_guess",35);
p_coal = field_or(coal,"p_e_guess",3.5);
p_gas = field_or(gas,"p_e_guess",3.5);
entry_coal = field_or(coal,"entry_guess",1);
entry_gas = field_or(gas,"entry_guess",1);
entry_green = field_or(green,"entry_guess",1);

p_E_prev = p_E;
p_coal_prev = p_coal;
p_gas_prev = p_gas;
price_err_prev = [1,1,1];
price_adjust = [0.1,0.2,0.2];
entry_prev = [entry_coal,entry_gas,entry_green];
value_err_prev = [0,0,0];
entry_adjust = 0.02*ones(1,3);
anchor_coal = [];
anchor_gas = [];
checkpoint_file = checkpoint_filename(field_or(common,"checkpoint_name",""));
use_checkpoint = strlength(checkpoint_file)>0;
checkpoint_freq = 50;
h_start = 1;
k_start = 1;
if use_checkpoint && isfile(checkpoint_file)
    try
        loaded = load(checkpoint_file,"checkpoint");
        [p_E,p_coal,p_gas,p_E_prev,p_coal_prev,p_gas_prev,price_err_prev,...
            price_adjust,entry_coal,entry_gas,entry_green,entry_prev,...
            value_err_prev,entry_adjust,anchor_coal,anchor_gas,h_start,k_start] = ...
            restore_ss_checkpoint(loaded.checkpoint);
        fprintf("Loaded three-tech SS checkpoint %s; resuming at h=%d, k=%d\n",...
            checkpoint_file,h_start,k_start);
    catch
        fprintf("No usable three-tech SS checkpoint at %s; starting from scratch\n",...
            checkpoint_file);
    end
elseif use_checkpoint
    fprintf("No three-tech SS checkpoint found at %s; starting from scratch\n",...
        checkpoint_file);
end
if h_start>common.max_iter
    h_start = common.max_iter;
    k_start = 1;
elseif k_start>common.max_iter
    k_start = 1;
end

price_err = zeros(1,3);
value_err = zeros(1,3);
for h=h_start:common.max_iter
    k_first = 1;
    if h==h_start, k_first = k_start; end
    for k=k_first:common.max_iter
        static_coal = static_solver_anchor(coal.a_eff,p_E,p_coal,PE,coal.pe_grid,...
            common.alpha,coal.fco,1./coal.grid(:),dlog_PE,coal.dlog_pe,...
            anchor_coal,0.01);
        static_gas = static_solver_anchor(gas.a_eff,p_E,p_gas,PE,gas.pe_grid,...
            common.alpha,gas.fco,1./gas.grid(:),dlog_PE,gas.dlog_pe,...
            anchor_gas,0.01);
        anchor_coal = static_coal;
        anchor_gas = static_gas;
        [green_eff,green_cap,green_pi] = solar_static_solver(green.a_eff,...
            p_E.*PE,solar_cap,green.fco);

        coal = solve_branch(coal,double(static_coal.pi)',common);
        gas = solve_branch(gas,double(static_gas.pi)',common);
        green = solve_branch(green,green_pi',common);
        coal = stationary_branch(coal,entry_coal,common);
        gas = stationary_branch(gas,entry_gas,common);
        green = stationary_branch(green,entry_green,common);

        coal.eff = double(static_coal.eff);
        coal.cap = double(static_coal.cap);
        gas.eff = double(static_gas.eff);
        gas.cap = double(static_gas.cap);
        green.eff = green_eff;
        green.cap = green_cap;

        total_cap = coal.dist*coal.cap(:)+gas.dist*gas.cap(:)+...
            green.dist*green.cap(:);
        demand_target = (common.d_0/max(total_cap,sqrt(eps)))^(1/common.e_p);
        coal_input = coal.dist*coal.eff(:);
        gas_input = gas.dist*gas.eff(:);
        coal_target = (max(coal_input,0)/max(coal.e0,sqrt(eps)))^(1/coal.elasticity);
        gas_target = (max(gas_input,0)/max(gas.e0,sqrt(eps)))^(1/gas.elasticity);
        price_err = max(min([demand_target-p_E,coal_target-p_coal,...
            gas_target-p_gas],25),-25);
        old_price = [p_E,p_coal,p_gas];
        previous_price = [p_E_prev,p_coal_prev,p_gas_prev];
        tentative = old_price+price_adjust.*price_err;
        oscill = sign(price_err)~=sign(price_err_prev);
        denominator = max(abs(price_err)+abs(price_err_prev),sqrt(eps));
        tentative(oscill) = (old_price(oscill).*abs(price_err_prev(oscill))+...
            previous_price(oscill).*abs(price_err(oscill)))./denominator(oscill);
        price_adjust = price_adjust.*(0.95.^double(oscill));
        p_E_prev = p_E;
        p_coal_prev = p_coal;
        p_gas_prev = p_gas;
        p_E = max(tentative(1),sqrt(eps));
        p_coal = max(tentative(2),sqrt(eps));
        p_gas = max(tentative(3),sqrt(eps));
        price_err_prev = price_err;
        if mod(k,50)==0
            fprintf("Three-tech SS h=%d, k=%d, market errors electricity=%g, coal fuel=%g, gas fuel=%g.\n",...
                h,k,price_err(1),price_err(2),price_err(3));
        end
        if use_checkpoint && mod(k,checkpoint_freq)==0
            save_ss_checkpoint(checkpoint_file,h,k+1,p_E,p_coal,p_gas,...
                p_E_prev,p_coal_prev,p_gas_prev,price_err_prev,price_adjust,...
                entry_coal,entry_gas,entry_green,entry_prev,value_err_prev,...
                entry_adjust,anchor_coal,anchor_gas);
        end
        if all(abs(price_err)<common.dem_tol) && ...
                max(abs(tentative-old_price))<5*common.v_tol
            break
        end
    end

    value_err = [coal.prob*coal.value(1,:)'-coal.entry_cost,...
        gas.prob*gas.value(1,:)'-gas.entry_cost,...
        green.prob*green.value(1,:)'-green.entry_cost];
    if mod(h,20)==0
        fprintf("Three-tech SS h=%d complete after k=%d, value errors coal=%g, gas=%g, green=%g.\n",...
            h,k,value_err(1),value_err(2),value_err(3));
    end
    entry = [entry_coal,entry_gas,entry_green];
    if all(abs(value_err)<5*common.dem_tol | entry<common.v_tol)
        break
    end
    lag = entry;
    entry = max(0,entry.*(1+0.2*entry_adjust.*value_err));
    oscill = h>1 & sign(value_err)~=sign(value_err_prev);
    denominator = max(abs(value_err)+abs(value_err_prev),sqrt(eps));
    entry(oscill) = (lag(oscill).*abs(value_err_prev(oscill))+...
        entry_prev(oscill).*abs(value_err(oscill)))./denominator(oscill);
    entry_adjust = entry_adjust.*(0.95.^double(oscill));
    entry_prev = lag;
    value_err_prev = value_err;
    entry_coal = entry(1);
    entry_gas = entry(2);
    entry_green = entry(3);
    if use_checkpoint
        save_ss_checkpoint(checkpoint_file,h+1,1,p_E,p_coal,p_gas,...
            p_E_prev,p_coal_prev,p_gas_prev,price_err_prev,price_adjust,...
            entry_coal,entry_gas,entry_green,entry_prev,value_err_prev,...
            entry_adjust,anchor_coal,anchor_gas);
    end
end

result = struct;
result.p_E = p_E;
result.age_g = age_g;
result.coal = finish_branch(coal,p_coal,entry_coal);
result.gas = finish_branch(gas,p_gas,entry_gas);
result.green = finish_branch(green,0,entry_green);
result.total_cap = coal.dist*coal.cap(:)+gas.dist*gas.cap(:)+...
    green.dist*green.cap(:);
result.iterations = struct("h",h,"k",k);
result.errors = struct("price",price_err,"entry",value_err);
fprintf("Three-tech SS finished at h=%d, k=%d; price errors [%g %g %g], entry errors [%g %g %g].\n",...
    h,k,price_err(1),price_err(2),price_err(3),value_err(1),value_err(2),value_err(3));
end

function common = common_defaults(common)
defaults = struct("a_grow",0.005,"alpha",1.9,"beta",0.97,"rho",0.6,...
    "exo_exit",0.01,"e_p",0.75,"d_0",100,"a_num_g",50,"age_num",80,...
    "max_iter",30000,"v_tol",1e-5,"dist_tol",1e-7,"dem_tol",0.01,...
    "age_reduc",10,"adoption_smoothing",2,...
    "P_E_grid_norm",P_E_grid(50,1));
names = string(fieldnames(defaults));
for name=names'
    if ~isfield(common,name) || isempty(common.(name))
        common.(name) = defaults.(name);
    end
end
end

function tech = prepare_tech(tech,common,is_green)
if isfield(tech,"grid") && ~isempty(tech.grid)
    tech.grid = tech.grid(:)';
else
    x = norminv(linspace(0,1,common.a_num_g+2),tech.mu,tech.sigma);
    tech.grid = x(2:common.a_num_g+1);
end
if isfield(tech,"prob") && ~isempty(tech.prob)
    tech.prob = max(tech.prob(:)',0);
else
    x = norminv(linspace(0,1,common.a_num_g+2),tech.mu,tech.sigma);
    tech.grid = x(2:common.a_num_g+1);
    cdf = normcdf(x,tech.mu,tech.sigma);
    tech.prob = cdf(2:common.a_num_g+1)-cdf(1:common.a_num_g);
end
tech.prob = tech.prob/sum(tech.prob);
assert(all(tech.grid>0),"Technology efficiency grids must be positive.");
if is_green
    tech.solar_cap_mean = field_or(tech,"solar_cap_mean",0.25);
    tech.solar_price_corr = field_or(tech,"solar_price_corr",0.6);
else
    tech.rho_p = field_or(tech,"rho_p",0.95);
    tech.sigma_p = field_or(tech,"sigma_p",0.2);
end
end

function tech = solve_branch(tech,profit,common)
[tech.value,tech.policy,tech.exit_vec,tech.value_converged,...
    tech.value_precision,tech.value_iterations] = branch_value(profit,...
    tech.prob_matrix,common.beta,tech.adopt_cost,common.v_tol,...
    common.max_iter,common.age_reduc,common.exo_exit,...
    common.adoption_smoothing,tech.grid);
tech.transition = plant_transition(tech.policy,tech.exit_vec,...
    tech.prob_matrix,common.age_reduc,common.exo_exit,tech.grid,tech.grid);
end

function tech = stationary_branch(tech,entry_mass,common)
[tech.dist,tech.exit_mass] = invariant_branch(tech.transition,entry_mass,...
    tech.prob,numel(tech.grid),common.age_num,common.dist_tol,common.max_iter);
end

function out = finish_branch(tech,p_e,entry_mass)
trans_prob = sum(tech.policy.*repmat(tech.prob_matrix,...
    numel(tech.dist)/numel(tech.grid),1),2);
out = rmfield_if_present(tech,["a_eff","prob_matrix","pe_grid","dlog_pe"]);
out.p_e = p_e;
out.entry_mass = entry_mass;
out.measure = sum(out.dist);
out.trans_prob = trans_prob;
end

function S = rmfield_if_present(S,names)
for name=names
    if isfield(S,name), S=rmfield(S,name); end
end
end

function [value,policy,exit_vec,converged,precision,iterations] = ...
        branch_value(profit,prob,beta,cost,tol,max_iter,age_reduc,exo_exit,smooth_rate,grid)
value = max(profit,0);
converged = false;
precision = inf;
iterations = 0;
[~,choice] = expected_adoption(value,prob,cost,age_reduc,smooth_rate,grid,grid);
exit_prob = zeros(size(value));
for ii=1:max_iter
    [expected,choice] = expected_adoption(value,prob,cost,age_reduc,smooth_rate,grid,grid);
    full_value = profit+beta*(1-exo_exit)*expected;
    negative = full_value<0;
    exit_prob = soft_exit(full_value,negative,smooth_rate);
    value_new = full_value;
    value_new(negative) = 0;
    precision = max(abs(value_new-value),[],"all");
    iterations = ii;
    value = value_new;
    if precision<tol, converged=true; break; end
end
exit_vec = reshape(exit_prob',[],1);
policy = pack_policy(choice,exit_vec);
end

function [expected,choice] = expected_adoption(next_value,prob,cost,age_reduc,...
        smooth_rate,grid_now,grid_next)
% Adopters draw a destination type from the autocorrelation kernel.
% Plants that do not adopt keep their efficiency and become one year older.
[age_num,n_type] = size(next_value);
[index,ratio] = grid_neighbors(grid_now,grid_next);
older = [next_value(2:end,:);zeros(1,n_type)];
continuation = older(:,index).*(1-ratio)'+older(:,max(index-1,1)).*ratio';
young = max((1:age_num)'-age_reduc,1);
adoption = next_value(young,:);
if isscalar(cost)
    adoption = adoption-cost;
else
    adoption = adoption-cost(:);
end
gain = reshape(adoption,age_num,1,n_type)-reshape(continuation,age_num,n_type,1);
choice = zeros(size(gain));
positive = gain>0;
choice(positive) = 1-exp(-smooth_rate*gain(positive));
best = reshape(continuation,age_num,n_type,1)+gain.*choice;
expected = reshape(sum(best.*reshape(prob,1,n_type,n_type),3),age_num,n_type);
end

function exit_prob = soft_exit(level,negative,smooth_rate)
exit_prob = double(negative)+(1-double(negative)).*exp(-level.*(10^smooth_rate));
exit_prob(isnan(exit_prob)) = 1;
end

function policy = pack_policy(choice,exit_vec)
[age_num,n_type,~] = size(choice);
policy = zeros(age_num*n_type,n_type);
for age=1:age_num
    rows = (age-1)*n_type+(1:n_type);
    block = reshape(choice(age,:,:),n_type,n_type);
    policy(rows,:) = block.*(1-exit_vec(rows));
end
end

function transition = plant_transition(policy,exit_vec,prob,age_reduc,exo_exit,...
        grid_now,grid_next)
% Maximum-age rows are removed, so that mass is part of exit. In the
% steady state the entrant distribution replaces every exit.
[n_state,n_type] = size(policy);
age_num = n_state/n_type;
[index,ratio] = grid_neighbors(grid_now,grid_next);
source = repelem((1:n_state)',n_type);
dest_type = repmat((1:n_type)',n_state,1);
state_age = repelem(repelem((1:age_num)',n_type),n_type);
adopt_prob = prob(sub2ind(size(prob),...
    repmat(repelem((1:n_type)',n_type),age_num,1),dest_type));
adopt_values = adopt_prob.*reshape(policy',[],1).*repelem(1-exit_vec,n_type)*(1-exo_exit);
adopt_target = (max(state_age-age_reduc,1)-1)*n_type+dest_type;
stay = sum((1-policy).*repmat(prob,age_num,1),2).*(1-exit_vec)*(1-exo_exit);
origin = repmat((1:n_type)',age_num,1);
plant_age = repelem((1:age_num)',n_type);
keep = plant_age<age_num;
next_age = plant_age+1;
high_type = index(origin);
low_type = max(high_type-1,1);
transition = sparse(source,adopt_target,adopt_values,n_state,n_state)+...
    sparse(find(keep),(next_age(keep)-1)*n_type+high_type(keep),...
        stay(keep).*(1-ratio(origin(keep))),n_state,n_state)+...
    sparse(find(keep),(next_age(keep)-1)*n_type+low_type(keep),...
        stay(keep).*ratio(origin(keep)),n_state,n_state);
transition((age_num-1)*n_type+1:n_state,:) = 0;
end

function [index,ratio] = grid_neighbors(grid_now,grid_next)
grid_now = grid_now(:);
grid_next = grid_next(:);
n = numel(grid_now);
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

function [dist,exit_mass] = invariant_branch(transition,entry_mass,prob,a_num_g,age_num,tol,max_iter)
entrant = zeros(1,age_num*a_num_g);
entrant(1:a_num_g) = prob;
deficit = max(1-full(sum(transition,2)),0);
kernel = transition+sparse(deficit)*sparse(entrant);
[unit,ok] = direct_invariant(kernel,tol);
if ~ok
    unit = entrant;
    for ii=1:max_iter
        next = unit*kernel;
        next = max(next,0)/sum(next);
        if max(abs(next-unit))<tol, break; end
        unit = next;
    end
end
dist = max(entry_mass,0)*unit;
exit_mass = sum(dist-dist*transition);
end

function [dist,ok] = direct_invariant(kernel,tol)
n = size(kernel,1);
A = kernel'-speye(n);
A(end,:) = 1;
b = zeros(n,1);
b(end) = 1;
ok = false;
dist = ones(1,n)/n;
try
    candidate = real(A\b);
catch
    return
end
if any(~isfinite(candidate)) || any(candidate<-1e-8), return; end
candidate = max(candidate,0);
dist = (candidate/sum(candidate))';
ok = max(abs(dist*kernel-dist))<=max(10*tol,1e-10);
end

function [cap,order] = solar_availability_grid(PE,mean_cap,corr)
[~,order] = sort(PE,"ascend");
sorted = linspace(1+corr,1-corr,numel(PE))';
cap = zeros(size(sorted));
cap(order) = sorted;
cap = max(min(mean_cap*cap/mean(cap),1),0);
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

function save_ss_checkpoint(file,h_start,k_start,p_E,p_coal,p_gas,...
        p_E_prev,p_coal_prev,p_gas_prev,price_err_prev,price_adjust,...
        entry_coal,entry_gas,entry_green,entry_prev,value_err_prev,...
        entry_adjust,anchor_coal,anchor_gas)
checkpoint = struct("h_start",h_start,"k_start",k_start,"p_E",p_E,...
    "p_coal",p_coal,"p_gas",p_gas,"p_E_prev",p_E_prev,...
    "p_coal_prev",p_coal_prev,"p_gas_prev",p_gas_prev,...
    "price_err_prev",price_err_prev,"price_adjust",price_adjust,...
    "entry_coal",entry_coal,"entry_gas",entry_gas,"entry_green",entry_green,...
    "entry_prev",entry_prev,"value_err_prev",value_err_prev,...
    "entry_adjust",entry_adjust,"anchor_coal",anchor_coal,"anchor_gas",anchor_gas);
save(file,"checkpoint");
end

function [p_E,p_coal,p_gas,p_E_prev,p_coal_prev,p_gas_prev,price_err_prev,...
        price_adjust,entry_coal,entry_gas,entry_green,entry_prev,...
        value_err_prev,entry_adjust,anchor_coal,anchor_gas,h_start,k_start] = ...
        restore_ss_checkpoint(checkpoint)
p_E = checkpoint.p_E;
p_coal = checkpoint.p_coal;
p_gas = checkpoint.p_gas;
p_E_prev = checkpoint.p_E_prev;
p_coal_prev = checkpoint.p_coal_prev;
p_gas_prev = checkpoint.p_gas_prev;
price_err_prev = checkpoint.price_err_prev;
price_adjust = checkpoint.price_adjust;
entry_coal = checkpoint.entry_coal;
entry_gas = checkpoint.entry_gas;
entry_green = checkpoint.entry_green;
entry_prev = checkpoint.entry_prev;
value_err_prev = checkpoint.value_err_prev;
entry_adjust = checkpoint.entry_adjust;
anchor_coal = checkpoint.anchor_coal;
anchor_gas = checkpoint.anchor_gas;
h_start = checkpoint.h_start;
k_start = checkpoint.k_start;
end
