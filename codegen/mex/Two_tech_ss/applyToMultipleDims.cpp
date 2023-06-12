//
// applyToMultipleDims.cpp
//
// Code generation for function 'applyToMultipleDims'
//

// Include files
#include "applyToMultipleDims.h"
#include "Two_tech_ss_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo sd_emlrtRSI{
    106,                   // lineNo
    "applyToMultipleDims", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyToMultipleDims.m" // pathName
};

static emlrtRSInfo td_emlrtRSI{
    63,                               // lineNo
    "function_handle/parenReference", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" // pathName
};

static emlrtRSInfo ud_emlrtRSI{
    61,                                                              // lineNo
    "@(x)coder.internal.unaryMinOrMax(opstr,x,ONE,varargin{2:end})", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

// Function Definitions
namespace coder {
namespace internal {
real_T applyToMultipleDims(const emlrtStack *sp,
                           const ::coder::array<real_T, 2U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T varargout_1;
  int32_T last;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  b_st.site = &td_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  if (x.size(0) * x.size(1) < 1) {
    emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  d_st.site = &vd_emlrtRSI;
  e_st.site = &wd_emlrtRSI;
  last = x.size(0) * x.size(1);
  if (x.size(0) * x.size(1) <= 2) {
    if (x.size(0) * x.size(1) == 1) {
      varargout_1 = x[0];
    } else if ((x[0] < x[x.size(0) * x.size(1) - 1]) ||
               (muDoubleScalarIsNaN(x[0]) &&
                (!muDoubleScalarIsNaN(x[x.size(0) * x.size(1) - 1])))) {
      varargout_1 = x[x.size(0) * x.size(1) - 1];
    } else {
      varargout_1 = x[0];
    }
  } else {
    int32_T idx;
    int32_T k;
    f_st.site = &yd_emlrtRSI;
    if (!muDoubleScalarIsNaN(x[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      g_st.site = &ae_emlrtRSI;
      if ((2 <= x.size(0) * x.size(1)) &&
          (x.size(0) * x.size(1) > 2147483646)) {
        h_st.site = &uc_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      varargout_1 = x[0];
    } else {
      int32_T a;
      f_st.site = &xd_emlrtRSI;
      varargout_1 = x[idx - 1];
      a = idx + 1;
      g_st.site = &be_emlrtRSI;
      if ((idx + 1 <= x.size(0) * x.size(1)) &&
          (x.size(0) * x.size(1) > 2147483646)) {
        h_st.site = &uc_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }
      for (k = a; k <= last; k++) {
        if (varargout_1 < x[k - 1]) {
          varargout_1 = x[k - 1];
        }
      }
    }
  }
  return varargout_1;
}

} // namespace internal
} // namespace coder

// End of code generation (applyToMultipleDims.cpp)
