//
// _coder_Two_tech_ss_api.cpp
//
// Code generation for function '_coder_Two_tech_ss_api'
//

// Include files
#include "_coder_Two_tech_ss_api.h"
#include "Two_tech_ss.h"
#include "Two_tech_ss_data.h"
#include "Two_tech_ss_mexutil.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "coder_array.h"

// Function Declarations
static const mxArray *emlrt_marshallOut(const coder::sparse *u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

// Function Definitions
static const mxArray *emlrt_marshallOut(const coder::sparse *u)
{
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateSparse(
                      &(((coder::array<real_T, 1U> *)&u->d)->data())[0],
                      &(((coder::array<int32_T, 1U> *)&u->colidx)->data())[0],
                      &(((coder::array<int32_T, 1U> *)&u->rowidx)->data())[0],
                      u->m, u->n, u->maxnz, mxDOUBLE_CLASS, mxREAL));
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 1U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 1U> *)&u)->size(), 1);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

void Two_tech_ss_api(const mxArray *const prhs[20], int32_T nlhs,
                     const mxArray *plhs[17])
{
  coder::sparse trans_matrix_n;
  coder::sparse trans_matrix_o;
  coder::array<real_T, 2U> a_grid;
  coder::array<real_T, 2U> a_prob;
  coder::array<real_T, 2U> dist_n;
  coder::array<real_T, 2U> dist_o;
  coder::array<real_T, 2U> pi_contemp_new;
  coder::array<real_T, 2U> v_new_resh_n;
  coder::array<real_T, 2U> v_new_resh_o;
  coder::array<real_T, 1U> age_g;
  coder::array<real_T, 1U> trans_prob_n;
  coder::array<real_T, 1U> trans_prob_o;
  coder::array<real_T, 1U> v_new_n;
  coder::array<real_T, 1U> v_new_o;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T a_bar;
  real_T a_grow;
  real_T a_lamb;
  real_T a_num_g;
  real_T age_num;
  real_T alpha;
  real_T beta;
  real_T c_a_new;
  real_T c_e_new;
  real_T c_of_a;
  real_T c_of_e;
  real_T d_0;
  real_T dem_tol;
  real_T dist_tol;
  real_T e_p;
  real_T fco;
  real_T m_of_firms_new;
  real_T m_of_firms_old;
  real_T max_iter;
  real_T p_E;
  real_T p_e;
  real_T tech_dist;
  real_T v_tol;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  a_grow = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "a_grow");
  alpha = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "alpha");
  a_bar = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "a_bar");
  beta = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "beta");
  c_of_a = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "c_of_a");
  c_a_new = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "c_a_new");
  a_lamb = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "a_lamb");
  p_e = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "p_e");
  a_num_g = emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "a_num_g");
  age_num = emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "age_num");
  max_iter = emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "max_iter");
  v_tol = emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "v_tol");
  dist_tol = emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "dist_tol");
  fco = emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "fco");
  e_p = emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "e_p");
  d_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "d_0");
  c_of_e = emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "c_of_e");
  c_e_new = emlrt_marshallIn(&st, emlrtAliasP(prhs[17]), "c_e_new");
  dem_tol = emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "dem_tol");
  tech_dist = emlrt_marshallIn(&st, emlrtAliasP(prhs[19]), "tech_dist");
  // Invoke the target function
  Two_tech_ss(&st, a_grow, alpha, a_bar, beta, c_of_a, c_a_new, a_lamb, p_e,
              a_num_g, age_num, max_iter, v_tol, dist_tol, fco, e_p, d_0,
              c_of_e, c_e_new, dem_tol, tech_dist, trans_prob_o, v_new_o,
              v_new_resh_o, dist_o, &trans_matrix_n, trans_prob_n, v_new_n,
              v_new_resh_n, dist_n, &trans_matrix_o, age_g, a_grid, a_prob,
              pi_contemp_new, &p_E, &m_of_firms_new, &m_of_firms_old);
  // Marshall function outputs
  trans_prob_o.no_free();
  plhs[0] = emlrt_marshallOut(trans_prob_o);
  if (nlhs > 1) {
    v_new_o.no_free();
    plhs[1] = emlrt_marshallOut(v_new_o);
  }
  if (nlhs > 2) {
    v_new_resh_o.no_free();
    plhs[2] = emlrt_marshallOut(v_new_resh_o);
  }
  if (nlhs > 3) {
    dist_o.no_free();
    plhs[3] = emlrt_marshallOut(dist_o);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(&trans_matrix_n);
  }
  if (nlhs > 5) {
    trans_prob_n.no_free();
    plhs[5] = emlrt_marshallOut(trans_prob_n);
  }
  if (nlhs > 6) {
    v_new_n.no_free();
    plhs[6] = emlrt_marshallOut(v_new_n);
  }
  if (nlhs > 7) {
    v_new_resh_n.no_free();
    plhs[7] = emlrt_marshallOut(v_new_resh_n);
  }
  if (nlhs > 8) {
    dist_n.no_free();
    plhs[8] = emlrt_marshallOut(dist_n);
  }
  if (nlhs > 9) {
    plhs[9] = emlrt_marshallOut(&trans_matrix_o);
  }
  if (nlhs > 10) {
    age_g.no_free();
    plhs[10] = emlrt_marshallOut(age_g);
  }
  if (nlhs > 11) {
    a_grid.no_free();
    plhs[11] = emlrt_marshallOut(a_grid);
  }
  if (nlhs > 12) {
    a_prob.no_free();
    plhs[12] = emlrt_marshallOut(a_prob);
  }
  if (nlhs > 13) {
    pi_contemp_new.no_free();
    plhs[13] = emlrt_marshallOut(pi_contemp_new);
  }
  if (nlhs > 14) {
    plhs[14] = emlrt_marshallOut(p_E);
  }
  if (nlhs > 15) {
    plhs[15] = emlrt_marshallOut(m_of_firms_new);
  }
  if (nlhs > 16) {
    plhs[16] = emlrt_marshallOut(m_of_firms_old);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_Two_tech_ss_api.cpp)
