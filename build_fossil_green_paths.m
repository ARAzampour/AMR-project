function fossil = build_fossil_green_paths(raw)
%BUILD_FOSSIL_GREEN_PATHS Aggregate coal and gas paths for the green model.
% Mixed grids are constructed by efficiency rank, but coal and gas masses
% remain on their source grids until conservative interpolation allocates
% each source point to its two neighboring mixed-grid points.

required = ["dist_coal","dist_gas","measure_coal","measure_gas",...
    "entry_coal","entry_gas","grid_coal","grid_gas","prob_coal","prob_gas",...
    "price_coal","price_gas","quantity_coal","quantity_gas",...
    "fco_coal","fco_gas","entry_cost_coal","entry_cost_gas",...
    "adopt_cost_coal","adopt_cost_gas"];
for name = required
    if ~isfield(raw,name)
        error("build_fossil_green_paths:MissingField","Missing raw.%s.",name);
    end
end

T = numel(raw.measure_coal);
row_fields = ["measure_coal","measure_gas","entry_coal","entry_gas",...
    "price_coal","price_gas","quantity_coal","quantity_gas"];
for name = row_fields
    raw.(name) = reshape(raw.(name),1,[]);
    if numel(raw.(name))~=T
        error("build_fossil_green_paths:Length","raw.%s must have %d elements.",name,T);
    end
end

raw.grid_coal = expand_path(raw.grid_coal,T);
raw.grid_gas = expand_path(raw.grid_gas,T);
raw.prob_coal = normalize_columns(expand_path(raw.prob_coal,T));
raw.prob_gas = normalize_columns(expand_path(raw.prob_gas,T));

entry_coal = smooth_nonnegative_preserve_total(raw.entry_coal,5);
entry_gas = smooth_nonnegative_preserve_total(raw.entry_gas,5);

stock_total = raw.measure_coal+raw.measure_gas;
stock_weight_coal = safe_share(raw.measure_coal,stock_total,0.5);
entry_total = entry_coal+entry_gas;
entry_weight_coal = safe_share(entry_coal,entry_total,stock_weight_coal);

fossil = struct;
fossil.measure_coal = raw.measure_coal;
fossil.measure_gas = raw.measure_gas;
fossil.stock_weight_coal = stock_weight_coal;
fossil.entry_weight_coal = entry_weight_coal;
fossil.entry_coal_raw = raw.entry_coal;
fossil.entry_gas_raw = raw.entry_gas;
fossil.entry_coal = entry_coal;
fossil.entry_gas = entry_gas;

a_num_g = size(raw.grid_coal,1);
if mod(size(raw.dist_coal,2),a_num_g)~=0 || size(raw.dist_gas,2)~=size(raw.dist_coal,2)
    error("build_fossil_green_paths:DistributionSize",...
        "Coal and gas distributions must share an age-by-grid state dimension.");
end
age_num = size(raw.dist_coal,2)/a_num_g;
fossil.grid_stock = zeros(a_num_g,T);
fossil.prob_stock = zeros(a_num_g,T);
fossil.grid_entry = zeros(a_num_g,T);
fossil.prob_entry = zeros(a_num_g,T);
fossil.dist = zeros(T,age_num*a_num_g);
fossil.stock_mass_coal_by_grid = zeros(a_num_g,T);
fossil.stock_mass_gas_by_grid = zeros(a_num_g,T);
fossil.entry_mass_coal_by_grid = zeros(a_num_g,T);
fossil.entry_mass_gas_by_grid = zeros(a_num_g,T);
fossil.stock_map_coal = cell(T,1);
fossil.stock_map_gas = cell(T,1);
fossil.entry_map_coal = cell(T,1);
fossil.entry_map_gas = cell(T,1);

for tt=1:T
    coal_grid = raw.grid_coal(:,tt);
    gas_grid = raw.grid_gas(:,tt);
    stock_grid = common_mixed_grid(coal_grid,gas_grid,stock_weight_coal(tt));
    entry_grid = common_mixed_grid(coal_grid,gas_grid,entry_weight_coal(tt));

    stock_map_coal = allocation_matrix(coal_grid,stock_grid);
    stock_map_gas = allocation_matrix(gas_grid,stock_grid);
    entry_map_coal = allocation_matrix(coal_grid,entry_grid);
    entry_map_gas = allocation_matrix(gas_grid,entry_grid);

    coal_dist_age = reshape(raw.dist_coal(tt,:),a_num_g,age_num)';
    gas_dist_age = reshape(raw.dist_gas(tt,:),a_num_g,age_num)';
    mixed_dist_age = coal_dist_age*stock_map_coal+gas_dist_age*stock_map_gas;

    stock_prob_mass = stock_weight_coal(tt)*(raw.prob_coal(:,tt)'*stock_map_coal) + ...
        (1-stock_weight_coal(tt))*(raw.prob_gas(:,tt)'*stock_map_gas);
    coal_entry_mass = entry_coal(tt)*raw.prob_coal(:,tt);
    gas_entry_mass = entry_gas(tt)*raw.prob_gas(:,tt);
    mixed_entry_mass = coal_entry_mass'*entry_map_coal+gas_entry_mass'*entry_map_gas;
    if sum(mixed_entry_mass)<=sqrt(eps)
        mixed_entry_mass = stock_prob_mass;
    end

    fossil.grid_stock(:,tt) = stock_grid;
    fossil.prob_stock(:,tt) = stock_prob_mass'/sum(stock_prob_mass);
    fossil.grid_entry(:,tt) = entry_grid;
    fossil.prob_entry(:,tt) = mixed_entry_mass'/sum(mixed_entry_mass);
    fossil.dist(tt,:) = reshape(mixed_dist_age',1,[]);
    fossil.stock_mass_coal_by_grid(:,tt) = sum(coal_dist_age,1)';
    fossil.stock_mass_gas_by_grid(:,tt) = sum(gas_dist_age,1)';
    fossil.entry_mass_coal_by_grid(:,tt) = coal_entry_mass;
    fossil.entry_mass_gas_by_grid(:,tt) = gas_entry_mass;
    fossil.stock_map_coal{tt} = stock_map_coal;
    fossil.stock_map_gas{tt} = stock_map_gas;
    fossil.entry_map_coal{tt} = entry_map_coal;
    fossil.entry_map_gas{tt} = entry_map_gas;

    source_stock_mass = sum(coal_dist_age,"all")+sum(gas_dist_age,"all");
    source_stock_moment = sum(sum(coal_dist_age,1)'.*coal_grid) + ...
        sum(sum(gas_dist_age,1)'.*gas_grid);
    mapped_stock_moment = sum(sum(mixed_dist_age,1)'.*stock_grid);
    assert(abs(sum(mixed_dist_age,"all")-source_stock_mass)<=1e-10*max(source_stock_mass,1),...
        "Stock-grid allocation did not preserve mass.");
    assert(abs(mapped_stock_moment-source_stock_moment)<=1e-10*max(abs(source_stock_moment),1),...
        "Stock-grid allocation did not preserve the efficiency moment.");
    source_entry_mass = entry_coal(tt)+entry_gas(tt);
    if source_entry_mass>sqrt(eps)
        source_entry_moment = sum(coal_entry_mass.*coal_grid)+sum(gas_entry_mass.*gas_grid);
        mapped_entry_moment = sum(mixed_entry_mass'.*entry_grid);
        assert(abs(sum(mixed_entry_mass)-source_entry_mass)<=1e-10*max(source_entry_mass,1),...
            "Entry-grid allocation did not preserve mass.");
        assert(abs(mapped_entry_moment-source_entry_moment)<=1e-10*max(abs(source_entry_moment),1),...
            "Entry-grid allocation did not preserve the efficiency moment.");
    end
end

fossil.fco = weighted_path(raw.fco_coal,raw.fco_gas,stock_weight_coal,T);
fossil.entry_cost = weighted_path(raw.entry_cost_coal,raw.entry_cost_gas,entry_weight_coal,T);
fossil.entry_cost_stock = weighted_path(raw.entry_cost_coal,raw.entry_cost_gas,stock_weight_coal,T);
fossil.adopt_cost = weighted_path(raw.adopt_cost_coal,raw.adopt_cost_gas,stock_weight_coal,T);
if isfield(raw,"rho_p_coal") && isfield(raw,"rho_p_gas")
    fossil.rho_p = weighted_path(raw.rho_p_coal,raw.rho_p_gas,stock_weight_coal,T);
end
if isfield(raw,"sigma_p_coal") && isfield(raw,"sigma_p_gas")
    fossil.sigma_p = weighted_path(raw.sigma_p_coal,raw.sigma_p_gas,stock_weight_coal,T);
end

Q_coal = max(raw.quantity_coal,0);
Q_gas = max(raw.quantity_gas,0);
Q = Q_coal+Q_gas;
expenditure = raw.price_coal.*Q_coal + raw.price_gas.*Q_gas;
price = nan(1,T);
positive_q = Q>sqrt(eps);
price(positive_q) = expenditure(positive_q)./Q(positive_q);
price = fill_nearest_positive(price);

penalty = get_field(raw,"fuel_penalty",1);
Q_lag = [Q(1),Q(1:end-1)];
quantity_ratio = max(Q./max(Q_lag,sqrt(eps)),sqrt(eps));
x = log(max(Q,sqrt(eps))) + penalty*log(quantity_ratio);
y = log(max(price,sqrt(eps)));
valid = isfinite(x)&isfinite(y)&positive_q;
[intercept,slope] = robust_line(x(valid),y(valid));
fallback_eps = get_field(raw,"fallback_elasticity",1);
if ~isfinite(slope) || slope<=0
    elasticity = fallback_eps;
else
    elasticity = min(max(1/slope,0.05),10);
end

e0_raw = Q.*quantity_ratio.^penalty./max(price,sqrt(eps)).^elasticity;
e0_raw = fill_nearest_positive(e0_raw);
e0 = exp(movmean(log(max(e0_raw,sqrt(eps))),5,"Endpoints","shrink"));

fossil.quantity_coal = Q_coal;
fossil.quantity_gas = Q_gas;
fossil.quantity = Q;
fossil.expenditure = expenditure;
fossil.price = price;
fossil.fuel_elasticity = elasticity;
fossil.e0_raw = e0_raw;
fossil.e0 = e0;
fossil.fuel_regression = struct("intercept",intercept,"slope",slope,"penalty",penalty);

if isfield(raw,"p_E")
    fossil.p_E = reshape(raw.p_E,1,[]);
end
if isfield(raw,"P_E_grid_norm")
    fossil.P_E_grid_norm = raw.P_E_grid_norm(:);
end
if isfield(raw,"green_start_index")
    fossil.green_start_index = min(max(round(raw.green_start_index),1),T);
else
    fossil.green_start_index = 1;
end
fossil.terminal_stock_weight_coal = stock_weight_coal(end);
fossil.terminal_grid = fossil.grid_stock(:,end);
fossil.terminal_prob = fossil.prob_stock(:,end);
end

function out = expand_path(value,T)
if isvector(value)
    out = repmat(value(:),1,T);
elseif size(value,2)==T
    out = value;
elseif size(value,1)==T
    out = value';
else
    error("build_fossil_green_paths:PathSize","Path must be a vector or have %d columns.",T);
end
end

function out = normalize_columns(value)
den = sum(value,1);
den(den<=0) = 1;
out = max(value,0)./den;
end

function target_grid = common_mixed_grid(coal_grid,gas_grid,coal_weight)
% Keep the rank-weighted interior grid while expanding its support so every
% source point can be allocated without losing the first efficiency moment.
coal_grid = coal_grid(:);
gas_grid = gas_grid(:);
if numel(coal_grid)~=numel(gas_grid)
    error("build_fossil_green_paths:GridSize","Coal and gas grids must have equal lengths.");
end
if any(diff(coal_grid)<0) || any(diff(gas_grid)<0)
    error("build_fossil_green_paths:GridOrder","Source efficiency grids must be increasing.");
end
if coal_weight<=sqrt(eps)
    target_grid = gas_grid;
    return
elseif coal_weight>=1-sqrt(eps)
    target_grid = coal_grid;
    return
end
target_grid = coal_weight*coal_grid+(1-coal_weight)*gas_grid;
target_grid(1) = min(coal_grid(1),gas_grid(1));
target_grid(end) = max(coal_grid(end),gas_grid(end));
if numel(target_grid)>1
    lower = target_grid(1);
    upper = target_grid(end);
    if upper<=lower
        scale = max(abs(lower),1);
        target_grid = lower+scale*1e-10*linspace(-0.5,0.5,numel(target_grid))';
    else
        % A tiny strictly increasing component resolves coincident ranks
        % without materially changing the weighted grid.
        target_grid = (1-1e-12)*target_grid+1e-12*linspace(lower,upper,numel(target_grid))';
        target_grid(1) = lower;
        target_grid(end) = upper;
    end
end
end

function allocation = allocation_matrix(source_grid,target_grid)
% Rows are source points and columns are target points. Every row sums to
% one and, inside target support, preserves the source efficiency exactly.
n_source = numel(source_grid);
n_target = numel(target_grid);
rows = zeros(2*n_source,1);
cols = zeros(2*n_source,1);
values = zeros(2*n_source,1);
used = 0;
for ii=1:n_source
    x = source_grid(ii);
    if x<=target_grid(1)
        used = used+1;
        rows(used) = ii;
        cols(used) = 1;
        values(used) = 1;
    elseif x>=target_grid(end)
        used = used+1;
        rows(used) = ii;
        cols(used) = n_target;
        values(used) = 1;
    else
        hi = sum(target_grid<x)+1;
        lo = hi-1;
        weight_hi = (x-target_grid(lo))/(target_grid(hi)-target_grid(lo));
        used = used+1;
        rows(used) = ii;
        cols(used) = lo;
        values(used) = 1-weight_hi;
        used = used+1;
        rows(used) = ii;
        cols(used) = hi;
        values(used) = weight_hi;
    end
end
allocation = sparse(rows(1:used),cols(1:used),values(1:used),n_source,n_target);
end

function share = safe_share(numerator,denominator,fallback)
share = zeros(size(denominator));
good = denominator>sqrt(eps);
share(good) = numerator(good)./denominator(good);
if isscalar(fallback)
    share(~good) = fallback;
else
    share(~good) = fallback(~good);
end
share = min(max(share,0),1);
end

function out = weighted_path(coal,gas,weight,T)
coal = reshape(coal,1,[]);
gas = reshape(gas,1,[]);
if isscalar(coal), coal = repmat(coal,1,T); end
if isscalar(gas), gas = repmat(gas,1,T); end
out = coal.*weight+gas.*(1-weight);
end

function path = smooth_nonnegative_preserve_total(path,window)
path = max(reshape(path,1,[]),0);
target = sum(path);
path = movmean(path,window,"Endpoints","shrink");
if target>0 && sum(path)>0
    path = path*(target/sum(path));
end
end

function value = fill_nearest_positive(value)
value = reshape(value,1,[]);
good = isfinite(value)&value>0;
if ~any(good)
    value(:) = 1;
    return
end
first = find(good,1,"first");
last = find(good,1,"last");
value(1:first-1) = value(first);
value(last+1:end) = value(last);
for ii=first+1:last
    if ~isfinite(value(ii)) || value(ii)<=0
        value(ii) = value(ii-1);
    end
end
end

function [intercept,slope] = robust_line(x,y)
x = x(:);
y = y(:);
if numel(x)<3 || max(x)-min(x)<sqrt(eps)
    intercept = mean(y,"omitnan");
    slope = NaN;
    return
end
X = [ones(size(x)),x];
b = X\y;
for ii=1:30
    residual = y-X*b;
    scale = 1.4826*median(abs(residual-median(residual)))+sqrt(eps);
    u = residual/(1.345*scale);
    weight = ones(size(u));
    large = abs(u)>1;
    weight(large) = 1./abs(u(large));
    Xw = X.*sqrt(weight);
    yw = y.*sqrt(weight);
    b_new = Xw\yw;
    if max(abs(b_new-b))<1e-10
        b = b_new;
        break
    end
    b = b_new;
end
intercept = b(1);
slope = b(2);
end

function value = get_field(S,name,fallback)
if isfield(S,name) && ~isempty(S.(name))
    value = S.(name);
else
    value = fallback;
end
end
