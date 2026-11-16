function plot_transition_figures()
% Plot of the baseline and the cost-threshold policies from 1985.
%
% Year 0 of the coal-gas transition is 1985. The three-technology solution
% replaces that path at three_tech_paths.common.green_start_index. Baseline
% figures run through 2025 and include the EIA series in data/power_sector_annual.csv.
% Policy figures run through 2050. Prices are in 1985 dollars. The model fuel
% price is divided by 3.412, because the static problem measures fuel per unit
% of efficiency and that factor converts it to dollars per MMBtu.

root        = fileparts(mfilename("fullpath"));
out_root    = fullfile(root,"figures");
if ~exist(out_root,"dir"), mkdir(out_root); end

pre         = fossil_history(root);
baseline    = load_result(root,"transition_coal_gas_green_baseline.mat","baseline_result");
base        = scenario_series(pre,baseline,"Baseline");
data        = read_data(fullfile(root,"data","power_sector_annual.csv"));
demand      = demand_parameters(root);

subsidy_names = ["subsidy_5pct_once_par","subsidy_50pct_once_1p5", ...
    "subsidy_5pct_10period_par","subsidy_5pct_10period_1p5"];
tax_names = ["tax_5pct_once_par","tax_20pct_once_1p5", ...
    "tax_5pct_10period_par","tax_5pct_10period_1p5"];

draw_folder(fullfile(out_root,"baseline"), base, data, true, 2025);
write_baseline_note(fullfile(out_root,"baseline"), pre.green_start_year);

subsidies = cell(1,numel(subsidy_names));
for i = 1:numel(subsidy_names)
    packed = load_result(root,"transition_coal_gas_green_"+subsidy_names(i)+".mat","subsidy_result");
    subsidies{i}        = scenario_series(pre,packed.result,policy_label(subsidy_names(i)));
    subsidies{i}.packed = packed;
    subsidies{i}.kind   = "subsidy";
    draw_folder(fullfile(out_root,subsidy_names(i)), subsidies{i}, [], false, 2050);
    write_policy_note(fullfile(out_root,subsidy_names(i)), subsidies{i}, base, demand, pre);
end

taxes = cell(1,numel(tax_names));
for i = 1:numel(tax_names)
    packed      = load_result(root,"transition_coal_gas_green_"+tax_names(i)+".mat","tax_result");
    taxes{i}    = scenario_series(pre,packed.result,policy_label(tax_names(i)));
    taxes{i}.packed = packed;
    taxes{i}.kind   = "tax";
    draw_folder(fullfile(out_root,tax_names(i)), taxes{i}, [], false, 2050);
    write_policy_note(fullfile(out_root,tax_names(i)), taxes{i}, base, demand, pre);
end

draw_comparison(fullfile(out_root,"all_subsidies"), [{base},subsidies], 2050);
draw_comparison(fullfile(out_root,"all_taxes"), [{base},taxes], 2050);
fprintf("Figures written to %s\n", out_root);
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%% Auxilary Functions %%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function pre = fossil_history(root)
P   = load(fullfile(root,"coal_gas_paths_for_green.mat"),"three_tech_paths");
C   = P.three_tech_paths.common;
M1  = load(fullfile(root,"ss_gas_coal_1stMIT.mat"),"cap_old1","cap_new1");
M2  = load(fullfile(root,"ss_gas_coal_2stMIT.mat"),"cap_old2","cap_new2");
M3  = load(fullfile(root,"ss_gas_coal_3rdMIT.mat"),"cap_old3","cap_new3");
% Same splice as PP_AoT_coal_gas.m: 15 years of the first transition,
% then years 2:10 of the second, then year 2 onward of the third.
cap_coal    = splice_caps(M1.cap_old1,M2.cap_old2,M3.cap_old3);
cap_gas     = splice_caps(M1.cap_new1,M2.cap_new2,M3.cap_new3);
if numel(cap_coal) ~= numel(C.p_E)
    error("Fossil capacity splice has %d years and the exported price path has %d.", ...
        numel(cap_coal), numel(C.p_E));
end
pre.green_start         = C.green_start_index;
pre.green_start_year    = 1985+C.green_start_index-1;
pre.p_E     = row(C.p_E);
pre.p_coal  = row(P.three_tech_paths.coal.price);
pre.p_gas   = row(P.three_tech_paths.gas.price);
pre.fuel_coal   = row(P.three_tech_paths.coal.quantity);
pre.fuel_gas    = row(P.three_tech_paths.gas.quantity);
pre.e0_gas      = row(P.three_tech_paths.gas.e0);
pre.cap_coal    = cap_coal;
pre.cap_gas     = cap_gas;
end

function path = splice_caps(first,second,third)
first = row(first); second = row(second); third = row(third);
path = [first(1:15), second(2:10), third(2:end)];
end

function s = scenario_series(pre,result,label)
start   = pre.green_start;
n_pre   = start-1;
n_post  = numel(result.p_E);
year    = 1985+(0:n_pre+n_post-1);
coal_cap    = row(result.coal.cap_path);
gas_cap     = row(result.gas.cap_path);
green_cap   = row(result.green.cap_path);
total   = coal_cap+gas_cap+green_cap;
s.label = label;
s.year  = year;
s.green_share   = [zeros(1,n_pre), green_cap./max(total,eps)];
s.p_E           = [pre.p_E(1:n_pre), row(result.p_E)];
s.fossil_cap    = [pre.cap_coal(1:n_pre)+pre.cap_gas(1:n_pre), coal_cap+gas_cap];
s.p_coal        = [pre.p_coal(1:n_pre), row(result.coal.p_e)];
s.p_gas         = [pre.p_gas(1:n_pre), row(result.gas.p_e)];
s.fuel_coal     = [pre.fuel_coal(1:n_pre), row(result.coal.input_path)];
s.fuel_gas      = [pre.fuel_gas(1:n_pre), row(result.gas.input_path)];
s.green_entry   = [nan(1,n_pre), row(result.green.entry_cost)];
s.gas_e0 = [pre.e0_gas(1:n_pre), row(result.gas.e0)];
s.result = result;
end

function draw_folder(folder,s,data,with_data,last_year)
if ~exist(folder,"dir"), mkdir(folder); end
s = cut_series(s,last_year);
mmbtu = 3.412;
panels = {
    "green_share","Green share","Share"
    "electricity_price","Electricity price","Dollars per MWh, 1985 dollars"
    "fossil_capacity","Fossil output","Output"
    "fuel_prices","Fuel prices","Dollars per MMBtu, 1985 dollars"
    "fuel_use","Fuel use","Fuel use"
    "green_entry_cost","Green entry cost","Entry cost"
    "gas_baseline_supply","Gas baseline supply","Baseline supply"
    };
for i = 1:size(panels,1)
    fig = new_figure();
    ax = axes(fig);
    hold(ax,"on")
    switch panels{i,1}
        case "green_share"
            add_line(ax,s.year,s.green_share,[0 0 0],"-",1.4,"Model");
            if with_data
                add_line(ax,s.year,align_to(data.year,data.green_generation_share,s.year), ...
                    [0.45 0.45 0.45],"--",1.1,"Data");
            end
            yl = ylim(ax); ylim(ax,[0,max(yl(2),0.05)]);
        case "electricity_price"
            add_line(ax,s.year,s.p_E,[0 0 0],"-",1.4,"Model");
            if with_data
                add_line(ax,s.year,align_to(data.year,data.generator_mwh,s.year), ...
                    [0.45 0.45 0.45],"--",1.1,"Data");
            end
        case "fossil_capacity"
            add_line(ax,s.year,s.fossil_cap,[0 0 0],"-",1.4,"Model");
            if with_data
                observed = align_to(data.year,data.fossil_generation,s.year);
                add_line(ax,s.year,scale_to_model(s.year,s.fossil_cap,observed), ...
                    [0.45 0.45 0.45],"--",1.1,"Data, scaled to 1985");
            end
        case "fuel_prices"
            add_line(ax,s.year,s.p_coal/mmbtu,[0 0 0],"-",1.4,"Coal, model");
            add_line(ax,s.year,s.p_gas/mmbtu,[0 0.27 0.53],"-",1.4,"Gas, model");
            if with_data
                add_line(ax,s.year,align_to(data.year,data.coal_price_mmbtu,s.year), ...
                    [0.45 0.45 0.45],"--",1.1,"Coal, data");
                add_line(ax,s.year,align_to(data.year,data.gas_price_mmbtu,s.year), ...
                    [0.35 0.55 0.75],"--",1.1,"Gas, data");
            end
        case "fuel_use"
            add_line(ax,s.year,s.fuel_coal,[0 0 0],"-",1.4,"Coal, model");
            add_line(ax,s.year,s.fuel_gas,[0 0.27 0.53],"-",1.4,"Gas, model");
            if with_data
                coal_data = scale_to_model(s.year,s.fuel_coal, ...
                    align_to(data.year,data.coal_fuel_tons,s.year));
                gas_data = scale_to_model(s.year,s.fuel_gas, ...
                    align_to(data.year,data.gas_fuel_bcf,s.year));
                add_line(ax,s.year,coal_data,[0.45 0.45 0.45],"--",1.1,"Coal, data, scaled to 1985");
                add_line(ax,s.year,gas_data,[0.35 0.55 0.75],"--",1.1,"Gas, data, scaled to 1985");
            end
        case "green_entry_cost"
            add_line(ax,s.year,s.green_entry,[0 0 0],"-",1.4,"Model");
        case "gas_baseline_supply"
            add_line(ax,s.year,s.gas_e0,[0 0 0],"-",1.4,"Model");
            end
    xlim(ax,[s.year(1) s.year(end)])
    finish_axes(ax,panels{i,3},panels{i,2});
    save_figure(fig,fullfile(folder,panels{i,1}));
end
end

function draw_comparison(folder,group,last_year)
if ~exist(folder,"dir"), mkdir(folder); end
colors = [0 0 0; 0 0.35 0.60; 0.75 0.32 0.10; 0.15 0.50 0.35; 0.50 0.25 0.55];
styles = {"-","--","-.",":","-"};
panels = {
    "green_share","Green share","Share","green_share"
    "electricity_price","Electricity price","Dollars per MWh","p_E"
    "fossil_capacity","Fossil output","Output","fossil_cap"
    "green_entry_cost","Green entry cost","Entry cost","green_entry"
    "gas_baseline_supply","Gas baseline supply","Baseline supply","gas_e0"
    "fuel_price_coal","Coal price","Dollars per MMBtu","p_coal"
    "fuel_price_gas","Gas price","Dollars per MMBtu","p_gas"
    "fuel_use_coal","Coal use","Fuel use","fuel_coal"
    "fuel_use_gas","Gas use","Fuel use","fuel_gas"
    };
mmbtu_fields = ["p_coal","p_gas"];
for p = 1:size(panels,1)
    fig = new_figure();
    ax = axes(fig);
    hold(ax,"on")
    field = panels{p,4};
    scale = 1;
    if any(strcmp(field,mmbtu_fields)), scale = 1/3.412; end
    for i = 1:numel(group)
        s = cut_series(group{i},last_year);
        width = 1.15;
        if i == 1, width = 1.5; end
        add_line(ax,s.year,s.(field)*scale,colors(i,:),styles{i},width,s.label);
    end
    if panels{p,1} == "green_share"
        yl = ylim(ax); ylim(ax,[0,max(yl(2),0.05)]);
    end
    xlim(ax,[1985 last_year])
    finish_axes(ax,panels{p,3},panels{p,2});
    save_figure(fig,fullfile(folder,panels{p,1}));
end
end

function write_policy_note(folder,s,base,demand,pre)
last_green = 2050-pre.green_start_year+1;
last_green = min(last_green,numel(s.result.p_E));
last_year = pre.green_start_year+last_green-1;
if s.kind == "subsidy"
    instrument = row(s.packed.subsidy);
    active = find(instrument>0);
    cost = sum(row(instrument(active)).*row(s.result.green.entry(active)));
    bill_base = electricity_bill(base.result,demand);
    bill_pol = electricity_bill(s.result,demand);
    benefit = sum(bill_base(1:last_green)-bill_pol(1:last_green));
    cost_name = "Cost, total subsidy paid";
    benefit_name = "Benefit, reduction in electricity expenditure relative to the baseline";
else
    active = find(row(s.packed.coal_tax)>0 | row(s.packed.gas_tax)>0);
    revenue = sum(row(s.result.tax_revenue(active)));
    bill_base = electricity_bill(base.result,demand);
    bill_pol = electricity_bill(s.result,demand);
    cost = sum(bill_pol(1:last_green)-bill_base(1:last_green));
    benefit = revenue;
    cost_name = "Cost, increase in electricity expenditure relative to the baseline";
    benefit_name = "Benefit, tax revenue";
end
years = pre.green_start_year+active-1;
enact = years(1);
fuel_base = row(base.result.coal.input_path)+row(base.result.gas.input_path);
fuel_pol = row(s.result.coal.input_path)+row(s.result.gas.input_path);
window = enact-pre.green_start_year+1:last_green;
carbon = 100*(sum(fuel_pol(window))-sum(fuel_base(window)))/sum(fuel_base(window));
fid = fopen(fullfile(folder,"costs_and_benefits.txt"),"w");
fprintf(fid,"%s\n",s.label);
fprintf(fid,"Enacted in %d. Active years: %s.\n",enact,strjoin(string(years)," "));
fprintf(fid,"Electricity expenditure is summed from %d through %d.\n", ...
    pre.green_start_year,last_year);
fprintf(fid,"Fuel use is summed from the enactment year through %d.\n",last_year);
fprintf(fid,"Amounts are in model units.\n\n");
fprintf(fid,"%s: %.6g\n",cost_name,cost);
fprintf(fid,"%s: %.6g\n",benefit_name,benefit);
fprintf(fid,"Carbon benefit, percent change in coal plus gas fuel use: %.4f\n",carbon);
fprintf(fid,"Baseline fuel use over the carbon window: %.6g\n",sum(fuel_base(window)));
fprintf(fid,"Policy fuel use over the carbon window: %.6g\n",sum(fuel_pol(window)));
fclose(fid);
end

function write_baseline_note(folder,green_year)
fid = fopen(fullfile(folder,"notes.txt"),"w");
fprintf(fid,"The horizontal axis starts in 1985, the first year of the coal-gas transition.\n");
fprintf(fid,"The coal, gas, and green solution replaces that path in %d.\n",green_year);
fprintf(fid,"Figures for the baseline end in 2025.\n\n");
fprintf(fid,"Data prices are deflated to 1985 dollars with the CPI-U.\n");
fprintf(fid,"Coal and gas prices are receipts at electric generating plants, from EIA Monthly Energy Review Table 9.9.\n");
fprintf(fid,"The model fuel price is divided by 3.412 so that it is in dollars per MMBtu.\n");
fprintf(fid,"The electricity price in the data starts from the industrial retail price, Table 9.8, in 1985 dollars per MWh.\n");
fprintf(fid,"Each year subtracts 13 dollars per MWh for wires and then keeps 90 percent, for a 10 percent loss.\n");
fprintf(fid,"In 1985 that is (49.70 - 13) times 0.90, equal to 33 dollars per MWh, the price target.\n\n");
fprintf(fid,"Fossil output in the data is coal, petroleum, and gas net generation, from Table 7.2b, scaled to the model in 1985.\n");
fprintf(fid,"Fuel use in the data is coal consumption in tons and gas consumption in billion cubic feet, from Table 7.3b, each scaled to the model in 1985.\n");
fprintf(fid,"The green share in the data is wind plus solar generation divided by total generation.\n");
fprintf(fid,"Green entry cost and baseline gas supply are model inputs and have no data line.\n");
fclose(fid);
end

function bill = electricity_bill(result,demand)
p = row(result.p_E);
t = 1:numel(p);
d0 = demand.d_0*(1+demand.d0_gr).^t;
bill = d0.*p.^(1-demand.e_p);
end

function demand = demand_parameters(root)
P = load(fullfile(root,"coal_gas_paths_for_green.mat"),"three_tech_paths");
demand.d_0      = P.three_tech_paths.common.d_0;
demand.d0_gr    = P.three_tech_paths.common.d0_gr;
demand.e_p      = P.three_tech_paths.common.e_p;
end

function data = read_data(path)
if exist(path,"file") ~= 2
    error("Missing %s.",path);
end
T           = readtable(path);
data.year   = row(T.year);
data.coal_price_mmbtu   = row(T.coal_price_mmbtu);
data.gas_price_mmbtu    = row(T.gas_price_mmbtu);
data.electricity_mwh    = row(T.electricity_mwh);
data.generator_mwh      = (data.electricity_mwh-13)*0.90;
data.fossil_generation  = row(T.fossil_generation);
data.green_generation_share = row(T.green_generation_share);
data.coal_fuel_tons     = row(T.coal_fuel_tons);
data.gas_fuel_bcf       = row(T.gas_fuel_bcf);
end

function value = load_result(root,file,field)
loaded  = load(fullfile(root,file),field);
value   = loaded.(field);
end

function s = cut_series(s,last_year)
keep = s.year<=last_year;
fields = ["year","green_share","p_E","fossil_cap","p_coal","p_gas", ...
    "fuel_coal","fuel_gas","green_entry","gas_e0"];
for name = fields
    s.(name) = s.(name)(keep);
end
end

function y = align_to(data_year,data_value,years)
y = nan(size(years));
[ok,loc] = ismember(years,data_year);
y(ok) = data_value(loc(ok));
end

function y = scale_to_model(years,model,observed)
y = observed;
at = years==1985;
if ~any(at) || ~isfinite(observed(at)) || observed(at)==0
    return
end
y = observed*(model(at)/observed(at));
end

function add_line(ax,x,y,color,style,width,label)
plot(ax,x,y,"Color",color,"LineStyle",style,"LineWidth",width,"DisplayName",label);
end

function finish_axes(ax,y_label,title_text)
xlabel(ax,"Year")
ylabel(ax,y_label)
h = title(ax,title_text);
set(h,"FontWeight","normal","FontSize",12)
apply_style(ax)
legend(ax,"Location","best","Box","off")
end

function apply_style(ax)
set(ax,"FontName","Times New Roman","FontSize",11,"TickDir","out", ...
    "Box","on","LineWidth",0.6,"TickLength",[0.012 0.012], ...
    "XColor","k","YColor","k","Color","w")
set(ax.Title,"FontName","Times New Roman")
set(ax.XLabel,"FontName","Times New Roman")
set(ax.YLabel,"FontName","Times New Roman")
lg = legend(ax);
if ~isempty(lg)
    set(lg,"FontName","Times New Roman","FontSize",10)
end
end

function fig = new_figure()
fig = figure("Visible","off","Color","w","Units","inches","Position",[1 1 6.5 4.3]);
set(fig,"PaperPositionMode","auto","InvertHardcopy","off")
end

function save_figure(fig,path_no_ext)
exportgraphics(fig,path_no_ext+".pdf","ContentType","vector","BackgroundColor","white");
exportgraphics(fig,path_no_ext+".png","Resolution",300,"BackgroundColor","white");
close(fig)
end

function x = row(x)
x = reshape(x,1,[]);
end

function label = policy_label(name)
switch name
    case "subsidy_5pct_once_par"
        label = "Subsidy 5 percent, one year, parity";
    case "subsidy_50pct_once_1p5"
        label = "Subsidy 50 percent, one year, 1.5 times";
    case "subsidy_5pct_10period_par"
        label = "Subsidy 5 percent, ten years, parity";
    case "subsidy_5pct_10period_1p5"
        label = "Subsidy 5 percent, ten years, 1.5 times";
    case "tax_5pct_once_par"
        label = "Tax 5 percent, one year, parity";
    case "tax_20pct_once_1p5"
        label = "Tax 20 percent, one year, 1.5 times";
    case "tax_5pct_10period_par"
        label = "Tax 5 percent, ten years, parity";
    case "tax_5pct_10period_1p5"
        label = "Tax 5 percent, ten years, 1.5 times";
    otherwise
        label = char(name);
end
end
