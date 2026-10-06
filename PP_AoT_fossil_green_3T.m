%%%% Coal, gas, and green transition dynamics.
%%%% Coal and gas remain separate branches; green is intermittent.

if exist("coal_gas_paths_for_green.mat","file")~=2
    error("Missing coal_gas_paths_for_green.mat. Re-run PP_AoT_coal_gas.m.");
end
S = load("coal_gas_paths_for_green.mat","three_tech_paths");
P = S.three_tech_paths;
if ~isfield(P,"common")
    error("The coal-gas export predates the common/coal/gas structure. Re-run PP_AoT_coal_gas.m.");
end
C = P.common;
start = C.green_start_index;

%%% Green-transition-specific controls.
trans_t = 120;
static_solver_workers = 1; % Set above 1 to enable parfor.

coal_path = extend_branch(slice_branch(P.coal,start),trans_t);
gas_path = extend_branch(slice_branch(P.gas,start),trans_t);
a_num_g = C.a_num_g;
age_num = C.age_num;

green_cost_scale = C.rat;
green = struct;
green.mu = ones(1,trans_t);
green.sigma = 0.12*ones(1,trans_t);
green.fco = green_cost_scale*ones(1,trans_t);
green.entry_cost = green_cost_scale*(30+90*exp(linspace(0,-20,trans_t)));
green.adopt_cost = green_cost_scale*(0.3+0.9*exp(linspace(0,-20,trans_t)));
green.solar_cap_mean = 0.25;
green.solar_price_corr = 0.6;

common_ss = struct("a_grow",C.a_grow,"alpha",C.alpha,"beta",C.beta,...
    "rho",C.rho,"exo_exit",C.exo_exit,"e_p",C.e_p,...
    "d_0",C.d_0*(1+C.d0_gr)^trans_t,"a_num_g",a_num_g,...
    "age_num",age_num,"max_iter",C.max_iter,"v_tol",C.v_tol,...
    "dist_tol",C.dist_tol,"dem_tol",C.dem_tol,"age_reduc",C.age_reduc,...
    "adoption_smoothing",C.adoption_smoothing,...
    "P_E_grid_norm",C.P_E_grid_norm,"p_E_guess",C.p_E(end));

coal_terminal = terminal_tech(coal_path);
gas_terminal = terminal_tech(gas_path);
green_terminal = struct("mu",green.mu(end),"sigma",green.sigma(end),...
    "fco",green.fco(end),"adopt_cost",green.adopt_cost(end),...
    "entry_cost",green.entry_cost(end),"entry_guess",1,...
    "solar_cap_mean",green.solar_cap_mean,...
    "solar_price_corr",green.solar_price_corr);

try
    load ss_coal_gas_green_final three_tech_ss_result three_tech_ss_version
    if three_tech_ss_version~=1, error("Outdated three-tech steady state."); end
catch
    three_tech_ss_result = Three_tech_ss_AC(coal_terminal,gas_terminal,...
        green_terminal,common_ss);
    three_tech_ss_version = 1;
    save ss_coal_gas_green_final three_tech_ss_result three_tech_ss_version
end

coal = transition_tech(coal_path,three_tech_ss_result.coal);
gas = transition_tech(gas_path,three_tech_ss_result.gas);
green.init_dist = zeros(1,age_num*a_num_g);
green.final = terminal_from_ss(three_tech_ss_result.green);

common = struct("a_grow",C.a_grow,"alpha",C.alpha,"beta",C.beta,...
    "rho",C.rho,"exo_exit",C.exo_exit,"e_p",C.e_p,"d_0",C.d_0,...
    "d0_gr",C.d0_gr,"a_num_g",a_num_g,"age_num",age_num,...
    "max_iter",C.max_iter,"v_tol",C.v_tol,"dem_tol",C.dem_tol,...
    "age_reduc",C.age_reduc,...
    "adoption_smoothing",C.adoption_smoothing,...
    "demand_penalty",C.demand_penalty,"init_p_E",C.p_E(start),...
    "final_p_E",three_tech_ss_result.p_E,"trans_t",trans_t,...
    "P_E_grid_norm",C.P_E_grid_norm,...
    "static_solver_workers",static_solver_workers);

try
    load transition_coal_gas_green_baseline baseline_result three_tech_mit_version
    if three_tech_mit_version~=1, error("Outdated three-tech transition."); end
catch
    baseline_result = MIT_transition_green_3T(coal,gas,green,common);
    three_tech_mit_version = 1;
    save transition_coal_gas_green_baseline baseline_result three_tech_mit_version
end

baseline = policy_summary(baseline_result,common);
subsidy_cases = struct(...
    "name",{"subsidy_small_once","subsidy_small_10period","subsidy_large_once"},...
    "amount",{0.05*green.entry_cost(end),0.05*green.entry_cost(end),...
    0.20*green.entry_cost(end)},"duration",{1,10,1});
subsidy_results = struct([]);
for pp=1:numel(subsidy_cases)
    subsidy = zeros(1,trans_t);
    subsidy(1:subsidy_cases(pp).duration) = subsidy_cases(pp).amount;
    green_policy = green;
    green_policy.entry_cost = max(green.entry_cost-subsidy,0);
    green_policy.adopt_cost = max(green.adopt_cost-subsidy,0);
    policy = MIT_transition_green_3T(coal,gas,green_policy,common);
    summary = policy_summary(policy,common);
    subsidy_outlay = sum(subsidy.*(policy.green.entry+policy.green.adopt_path));
    lower_electricity_cost = sum(max(baseline.expenditure-summary.expenditure,0));
    subsidy_results(pp).name = subsidy_cases(pp).name;
    subsidy_results(pp).subsidy = subsidy;
    subsidy_results(pp).result = policy;
    subsidy_results(pp).green_share_response = summary.green_share-baseline.green_share;
    subsidy_results(pp).subsidy_outlay = subsidy_outlay;
    subsidy_results(pp).lower_electricity_cost = lower_electricity_cost;
    subsidy_results(pp).net_consumer_cost = subsidy_outlay-lower_electricity_cost;
end
save transition_coal_gas_green_subsidies subsidy_results baseline subsidy_cases

tax_cases = struct(...
    "name",{"tax_small_once","tax_small_10period","tax_large_once"},...
    "rate",{0.05,0.05,0.20},"duration",{1,10,1});
tax_results = struct([]);
for pp=1:numel(tax_cases)
    coal_policy = coal;
    gas_policy = gas;
    coal_policy.tax = zeros(1,trans_t);
    gas_policy.tax = zeros(1,trans_t);
    active = 1:tax_cases(pp).duration;
    coal_policy.tax(active) = tax_cases(pp).rate*coal.init_price;
    gas_policy.tax(active) = tax_cases(pp).rate*gas.init_price;
    policy = MIT_transition_green_3T(coal_policy,gas_policy,green,common);
    summary = policy_summary(policy,common);
    higher_electricity_cost = sum(max(summary.expenditure-baseline.expenditure,0));
    tax_revenue = sum(policy.tax_revenue);
    tax_results(pp).name = tax_cases(pp).name;
    tax_results(pp).coal_tax = coal_policy.tax;
    tax_results(pp).gas_tax = gas_policy.tax;
    tax_results(pp).result = policy;
    tax_results(pp).green_share_response = summary.green_share-baseline.green_share;
    tax_results(pp).higher_electricity_cost = higher_electricity_cost;
    tax_results(pp).tax_revenue = tax_revenue;
    tax_results(pp).net_consumer_cost = higher_electricity_cost-tax_revenue;
end
save transition_coal_gas_green_taxes tax_results baseline tax_cases

total_cap = baseline_result.coal.cap_path+baseline_result.gas.cap_path+...
    baseline_result.green.cap_path;
green_share = baseline_result.green.cap_path./total_cap;
figure(1)
plot(green_share,LineWidth=2)
xlabel("periods into transition"), ylabel("share")
title("green share of capacity")
figure(2)
plot(baseline_result.p_E,LineWidth=2)
xlabel("periods into transition"), ylabel("electricity price")
title("electricity price path")

function out = slice_branch(branch,start)
out = branch;
row_fields = ["measure","entry","mu","sigma","price","quantity","e0",...
    "fco","entry_cost","adopt_cost"];
for name=row_fields
    if isfield(out,name), out.(name)=reshape(out.(name),1,[]); out.(name)=out.(name)(start:end); end
end
if isfield(out,"grid"), out.grid=out.grid(:,start:end); end
if isfield(out,"prob"), out.prob=out.prob(:,start:end); end
if isfield(out,"dist"), out.dist=out.dist(start:end,:); end
end

function out = extend_branch(branch,T)
out = branch;
row_fields = ["measure","entry","mu","sigma","price","quantity","e0",...
    "fco","entry_cost","adopt_cost"];
for name=row_fields
    if isfield(out,name)
        value=reshape(out.(name),1,[]);
        out.(name)=[value(1:min(end,T)),repmat(value(end),1,max(T-numel(value),0))];
    end
end
for name=["grid","prob"]
    if isfield(out,name)
        value=out.(name);
        out.(name)=[value(:,1:min(size(value,2),T)),...
            repmat(value(:,end),1,max(T-size(value,2),0))];
    end
end
if isfield(out,"dist")
    value=out.dist;
    out.dist=[value(1:min(size(value,1),T),:);...
        repmat(value(end,:),max(T-size(value,1),0),1)];
end
end

function tech = terminal_tech(path)
tech = struct("mu",path.mu(end),"sigma",path.sigma(end),...
    "fco",path.fco(end),"adopt_cost",path.adopt_cost(end),...
    "entry_cost",path.entry_cost(end),"e0",path.e0(end),...
    "elasticity",path.elasticity,"rho_p",path.rho_p,...
    "sigma_p",path.sigma_p,"p_e_guess",path.price(end),...
    "entry_guess",max(path.entry(end),1e-8));
end

function tech = transition_tech(path,terminal)
tech = struct("mu",path.mu,"sigma",path.sigma,"fco",path.fco,...
    "adopt_cost",path.adopt_cost,"entry_cost",path.entry_cost,...
    "e0",path.e0,"elasticity",path.elasticity,"rho_p",path.rho_p,...
    "sigma_p",path.sigma_p,"fuel_penalty",path.fuel_penalty,...
    "init_price",path.price(1),...
    "init_input",max(path.quantity(1),sqrt(eps)),...
    "init_dist",path.dist(1,:),"entry_guess_path",path.entry,...
    "tax",zeros(size(path.mu)),"final",terminal_from_ss(terminal));
end

function final = terminal_from_ss(tech)
final = struct("value",tech.value,"dist",tech.dist,...
    "p_e",tech.p_e,"exit_mass",tech.exit_mass);
end

function summary = policy_summary(result,common)
total = result.coal.cap_path+result.gas.cap_path+result.green.cap_path;
summary.green_share = result.green.cap_path./max(total,sqrt(eps));
d0 = common.d_0*(1+common.d0_gr).^(1:common.trans_t);
quantity = d0./result.p_E.^common.e_p;
summary.expenditure = result.p_E.*quantity;
end

