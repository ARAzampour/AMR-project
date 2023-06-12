//
// power.cpp
//
// Code generation for function 'power'
//

// Include files
#include "power.h"
#include "Two_tech_ss_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    qc_emlrtRSI{
        81,         // lineNo
        "fltpower", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" // pathName
    };

static emlrtRSInfo
    rc_emlrtRSI{
        95,                      // lineNo
        "fltpower_domain_error", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" // pathName
    };

static emlrtRSInfo
    sc_emlrtRSI{
        44,          // lineNo
        "vAllOrAny", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" // pathName
    };

static emlrtRSInfo
    tc_emlrtRSI{
        103,                  // lineNo
        "flatVectorAllOrAny", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" // pathName
    };

static emlrtRSInfo
    vc_emlrtRSI{
        102,                     // lineNo
        "fltpower_domain_error", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" // pathName
    };

static emlrtRTEInfo
    jf_emlrtRTEI{
        71,      // lineNo
        5,       // colNo
        "power", // fName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" // pName
    };

// Function Definitions
namespace coder {
void power(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a, real_T b,
           ::coder::array<real_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pc_emlrtRSI;
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
  b_st.site = &qc_emlrtRSI;
  if ((a.size(0) == 1) && (a.size(1) == 1)) {
    if ((a[0] < 0.0) && (!muDoubleScalarIsNaN(b)) &&
        (muDoubleScalarFloor(b) != b)) {
      p = true;
    } else {
      p = false;
    }
  } else if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarFloor(b) != b)) {
    c_st.site = &vc_emlrtRSI;
    d_st.site = &sc_emlrtRSI;
    nx = a.size(0) * a.size(1);
    p = false;
    e_st.site = &tc_emlrtRSI;
    if ((1 <= nx) && (nx > 2147483646)) {
      f_st.site = &uc_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (k = 0; k < nx; k++) {
      if (p || (a[k] < 0.0)) {
        p = true;
      }
    }
  } else {
    p = false;
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &p_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  y.set_size(&jf_emlrtRTEI, &st, a.size(0), a.size(1));
  nx = a.size(0) * a.size(1);
  for (k = 0; k < nx; k++) {
    real_T varargin_1;
    varargin_1 = a[k];
    y[k] = muDoubleScalarPower(varargin_1, b);
  }
}

void power(const emlrtStack *sp, real_T a, const ::coder::array<real_T, 1U> &b,
           ::coder::array<real_T, 1U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T k;
  int32_T nx;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pc_emlrtRSI;
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
  b_st.site = &qc_emlrtRSI;
  if (a < 0.0) {
    c_st.site = &rc_emlrtRSI;
    d_st.site = &sc_emlrtRSI;
    nx = b.size(0);
    p = false;
    e_st.site = &tc_emlrtRSI;
    if ((1 <= b.size(0)) && (b.size(0) > 2147483646)) {
      f_st.site = &uc_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (k = 0; k < nx; k++) {
      if (p || ((!muDoubleScalarIsNaN(b[k])) &&
                (muDoubleScalarFloor(b[k]) != b[k]))) {
        p = true;
      }
    }
  } else {
    p = false;
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(&st, &p_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  y.set_size(&jf_emlrtRTEI, &st, b.size(0));
  nx = b.size(0);
  for (k = 0; k < nx; k++) {
    real_T varargin_2;
    varargin_2 = b[k];
    y[k] = muDoubleScalarPower(a, varargin_2);
  }
}

} // namespace coder

// End of code generation (power.cpp)
