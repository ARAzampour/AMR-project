//
// abs.cpp
//
// Code generation for function 'abs'
//

// Include files
#include "abs.h"
#include "One_tech_ss_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    sc_emlrtRSI{
        18,    // lineNo
        "abs", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" // pathName
    };

static emlrtRSInfo tc_emlrtRSI{
    74,                    // lineNo
    "applyScalarFunction", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunction.m" // pathName
};

static emlrtRTEInfo sd_emlrtRTEI{
    30,                    // lineNo
    21,                    // colNo
    "applyScalarFunction", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunction.m" // pName
};

// Function Definitions
namespace coder {
void b_abs(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
           ::coder::array<real_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x.size(0) * x.size(1);
  y.set_size(&sd_emlrtRTEI, &st, x.size(0), x.size(1));
  b_st.site = &tc_emlrtRSI;
  if ((1 <= nx) && (nx > 2147483646)) {
    c_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    y[k] = muDoubleScalarAbs(x[k]);
  }
}

void c_abs(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
           ::coder::array<real_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x.size(1);
  y.set_size(&sd_emlrtRTEI, &st, 1, x.size(1));
  b_st.site = &tc_emlrtRSI;
  if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
    c_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    y[k] = muDoubleScalarAbs(x[k]);
  }
}

} // namespace coder

// End of code generation (abs.cpp)
