//
// _coder_One_tech_ss_api.cpp
//
// Code generation for function '_coder_One_tech_ss_api'
//

// Include files
#include "_coder_One_tech_ss_api.h"
#include "One_tech_ss.h"
#include "One_tech_ss_data.h"
#include "One_tech_ss_mexutil.h"
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

void One_tech_ss_api(const mxArray *const prhs[17], int32_T nlhs,
                     const mxArray *plhs[11])
{
  coder::sparse trans_matrix;
  coder::array<real_T, 2U> a_grid;
  coder::array<real_T, 2U> a_prob;
  coder::array<real_T, 2U> dist;
  coder::array<real_T, 2U> pi_contemp;
  coder::array<real_T, 2U> v_new_resh;
  coder::array<real_T, 1U> age_g;
  coder::array<real_T, 1U> trans_prob;
  coder::array<real_T, 1U> v_new;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T a__1;
  real_T a_grow;
  real_T a_lamb;
  real_T a_num_g;
  real_T age_num;
  real_T alpha;
  real_T beta;
  real_T c_of_a;
  real_T c_of_e;
  real_T d_0;
  real_T dem_tol;
  real_T dist_tol;
  real_T e_p;
  real_T fco;
  real_T m_of_firms;
  real_T max_iter;
  real_T p_E;
  real_T p_e;
  real_T v_tol;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  a_grow = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "a_grow");
  alpha = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "alpha");
  a__1 = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "~1");
  beta = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "beta");
  c_of_a = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "c_of_a");
  a_lamb = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "a_lamb");
  p_e = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "p_e");
  a_num_g = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "a_num_g");
  age_num = emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "age_num");
  max_iter = emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "max_iter");
  v_tol = emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "v_tol");
  dist_tol = emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "dist_tol");
  fco = emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "fco");
  e_p = emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "e_p");
  d_0 = emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "d_0");
  c_of_e = emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "c_of_e");
  dem_tol = emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "dem_tol");
  // Invoke the target function
  One_tech_ss(&st, a_grow, alpha, a__1, beta, c_of_a, a_lamb, p_e, a_num_g,
              age_num, max_iter, v_tol, dist_tol, fco, e_p, d_0, c_of_e,
              dem_tol, trans_prob, v_new, v_new_resh, dist, &trans_matrix,
              age_g, a_grid, a_prob, pi_contemp, &p_E, &m_of_firms);
  // Marshall function outputs
  trans_prob.no_free();
  plhs[0] = emlrt_marshallOut(trans_prob);
  if (nlhs > 1) {
    v_new.no_free();
    plhs[1] = emlrt_marshallOut(v_new);
  }
  if (nlhs > 2) {
    v_new_resh.no_free();
    plhs[2] = emlrt_marshallOut(v_new_resh);
  }
  if (nlhs > 3) {
    dist.no_free();
    plhs[3] = emlrt_marshallOut(dist);
  }
  if (nlhs > 4) {
    plhs[4] = emlrt_marshallOut(&trans_matrix);
  }
  if (nlhs > 5) {
    age_g.no_free();
    plhs[5] = emlrt_marshallOut(age_g);
  }
  if (nlhs > 6) {
    a_grid.no_free();
    plhs[6] = emlrt_marshallOut(a_grid);
  }
  if (nlhs > 7) {
    a_prob.no_free();
    plhs[7] = emlrt_marshallOut(a_prob);
  }
  if (nlhs > 8) {
    pi_contemp.no_free();
    plhs[8] = emlrt_marshallOut(pi_contemp);
  }
  if (nlhs > 9) {
    plhs[9] = emlrt_marshallOut(p_E);
  }
  if (nlhs > 10) {
    plhs[10] = emlrt_marshallOut(m_of_firms);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_One_tech_ss_api.cpp)
