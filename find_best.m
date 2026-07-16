clc
clear
close all
%%
addpath('Results (batch run)');

nruns = 300;

par_keep = 20;

cFE = [];
for idr=1:nruns
       try
              temp_FE   = load(strcat('FE_', num2str(idr), '.mat')).FEs;
              temp_FE   = temp_FE(temp_FE(:, 1)>0, :);
              temp_par  = load(strcat('params_', num2str(idr), '.mat')).params;

              nonEmptyC = temp_par(~cellfun('isempty', temp_par));
              nonemptyP = vertcat(nonEmptyC{:});

              temp_all  = [temp_FE nonemptyP];
              cFE = [cFE; temp_all];
       catch ME
              fprintf('Missing Index: %4.0f\n', idr) 
              disp(ME.message);
       end
end

cFE = sortrows(cFE, 2, 'ascend');
cFE = cFE(1:par_keep, :);
% params_keep = cell(par_keep, 1);
% 
% for idp=1:par_keep
%         id_run = floor(cFE(idp, 1)/nk_runs);
%         if rem(cFE(idp, 1), nk_runs) ~=0
%                 id_run = id_run + 1;
%         end
%         temp_par = load(strcat('params_', num2str(id_run), '.mat')).params;
%         params_keep{idp} = temp_par{cFE(idp, 1)};
% end
% 
% save('params_keep.mat', 'params_keep');
save('cFE.mat', 'cFE');
colnames = {'#iter','error','c_of_a','c_a_new','d_0','e0_n','e0_o','ratio','age_reduc'};
T = array2table(cFE, 'VariableNames', colnames);
save('Restab',"T");


