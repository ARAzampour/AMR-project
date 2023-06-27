function prob_matrix = auto_corr_prob(a_grid,a_prob,rho)
a_num_g     = length(a_grid);
prob_matrix = zeros(a_num_g,a_num_g);
for i=1:1:a_num_g
    temp_grid   = a_grid(i)*rho +(1-rho)*a_grid;
    for j=1:1:a_num_g
        [~,temp_index]  = max(temp_grid(j)<=a_grid);
        if temp_index>1
            prob_matrix(i,temp_index-1) = a_prob(j)*(-temp_grid(j)+a_grid(temp_index))...
                /(a_grid(temp_index)-a_grid(temp_index-1))+prob_matrix(i,temp_index-1);
            prob_matrix(i,temp_index)   = a_prob(j)*(temp_grid(j)-a_grid(temp_index-1))...
                /(a_grid(temp_index)-a_grid(temp_index-1))+prob_matrix(i,temp_index);
        else
            prob_matrix(i,temp_index) = a_prob(j) + prob_matrix(i,temp_index);
        end
    end
end
end