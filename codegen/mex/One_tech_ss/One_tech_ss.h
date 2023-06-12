//
// One_tech_ss.h
//
// Code generation for function 'One_tech_ss'
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
void One_tech_ss(
    const emlrtStack *sp, real_T a_grow, real_T alpha, real_T a__1, real_T beta,
    real_T c_of_a, real_T a_lamb, real_T p_e, real_T a_num_g, real_T age_num,
    real_T max_iter, real_T v_tol, real_T dist_tol, real_T fco, real_T e_p,
    real_T d_0, real_T c_of_e, real_T dem_tol,
    coder::array<real_T, 1U> &trans_prob, coder::array<real_T, 1U> &v_new,
    coder::array<real_T, 2U> &v_new_resh, coder::array<real_T, 2U> &dist,
    coder::sparse *trans_matrix, coder::array<real_T, 1U> &age_g,
    coder::array<real_T, 2U> &a_grid, coder::array<real_T, 2U> &a_prob,
    coder::array<real_T, 2U> &pi_contemp, real_T *p_E, real_T *m_of_firms);

// End of code generation (One_tech_ss.h)
