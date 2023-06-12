//
// sparse.cpp
//
// Code generation for function 'sparse'
//

// Include files
#include "sparse.h"
#include "Two_tech_ss_data.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo kc_emlrtRSI{
    13,       // lineNo
    "sparse", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    84,              // lineNo
    "sparse/sparse", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo mc_emlrtRSI{
    85,              // lineNo
    "sparse/sparse", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    1610,              // lineNo
    "assertValidSize", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRTEInfo l_emlrtRTEI{
    1612,              // lineNo
    9,                 // colNo
    "assertValidSize", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    1615,              // lineNo
    31,                // colNo
    "assertValidSize", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtDCInfo ob_emlrtDCI{
    13,       // lineNo
    1,        // colNo
    "sparse", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m", // pName
    4 // checkKind
};

static emlrtRTEInfo if_emlrtRTEI{
    13,       // lineNo
    1,        // colNo
    "sparse", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" // pName
};

// Function Definitions
namespace coder {
void b_sparse(const emlrtStack *sp, real_T varargin_1, real_T varargin_2,
              sparse *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T b_varargin_1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &lc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) ||
      muDoubleScalarIsInf(varargin_1) || (varargin_1 < -2.147483648E+9) ||
      (varargin_1 > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &n_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }
  if (!(b_varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if (varargin_1 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (!(varargin_1 < 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  b_st.site = &mc_emlrtRSI;
  c_st.site = &nc_emlrtRSI;
  if ((varargin_2 != muDoubleScalarFloor(varargin_2)) ||
      muDoubleScalarIsInf(varargin_2) || (varargin_2 < -2.147483648E+9) ||
      (varargin_2 > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &n_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (varargin_2 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_2;
  }
  if (!(b_varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if (varargin_2 < 0.0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &l_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (!(varargin_2 < 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &m_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  y->m = static_cast<int32_T>(varargin_1);
  y->n = static_cast<int32_T>(varargin_2);
  y->d.set_size(&if_emlrtRTEI, &st, 1);
  y->d[0] = 0.0;
  if (static_cast<int32_T>(varargin_2) + 1 < 0) {
    emlrtNonNegativeCheckR2012b(
        static_cast<real_T>(static_cast<int32_T>(varargin_2) + 1), &ob_emlrtDCI,
        &st);
  }
  y->colidx.set_size(&if_emlrtRTEI, &st, static_cast<int32_T>(varargin_2) + 1);
  if (static_cast<int32_T>(varargin_2) + 1 < 0) {
    emlrtNonNegativeCheckR2012b(
        static_cast<real_T>(static_cast<int32_T>(varargin_2) + 1), &ob_emlrtDCI,
        &st);
  }
  loop_ub = static_cast<int32_T>(varargin_2) + 1;
  for (int32_T i{0}; i < loop_ub; i++) {
    y->colidx[i] = 1;
  }
  y->rowidx.set_size(&if_emlrtRTEI, &st, 1);
  y->rowidx[0] = 1;
  y->maxnz = 1;
}

} // namespace coder

// End of code generation (sparse.cpp)
