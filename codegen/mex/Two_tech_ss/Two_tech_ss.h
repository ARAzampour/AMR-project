//
// Two_tech_ss.h
//
// Code generation for function 'Two_tech_ss'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "sparse1.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void Two_tech_ss(
    const emlrtStack *sp, real_T a_grow, real_T alpha, real_T a_bar,
    real_T beta, real_T c_of_a, real_T c_a_new, real_T a_lamb, real_T p_e,
    real_T a_num_g, real_T age_num, real_T max_iter, real_T v_tol,
    real_T dist_tol, real_T fco, real_T e_p, real_T d_0, real_T c_of_e,
    real_T c_e_new, real_T dem_tol, real_T tech_dist,
    coder::array<real_T, 1U> &trans_prob_o, coder::array<real_T, 1U> &v_new_o,
    coder::array<real_T, 2U> &v_new_resh_o, coder::array<real_T, 2U> &dist_o,
    coder::sparse *trans_matrix_n, coder::array<real_T, 1U> &trans_prob_n,
    coder::array<real_T, 1U> &v_new_n, coder::array<real_T, 2U> &v_new_resh_n,
    coder::array<real_T, 2U> &dist_n, coder::sparse *trans_matrix_o,
    coder::array<real_T, 1U> &age_g, coder::array<real_T, 2U> &a_grid,
    coder::array<real_T, 2U> &a_prob, coder::array<real_T, 2U> &pi_contemp_new,
    real_T *p_E, real_T *m_of_firms_new, real_T *m_of_firms_old);

// End of code generation (Two_tech_ss.h)
