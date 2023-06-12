//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "One_tech_ss_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo kc_emlrtRSI{
    28,       // lineNo
    "repmat", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    64,       // lineNo
    "repmat", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtRSInfo mc_emlrtRSI{
    66,       // lineNo
    "repmat", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    71,       // lineNo
    "repmat", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    69,       // lineNo
    "repmat", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pathName
};

static emlrtDCInfo cb_emlrtDCI{
    31,       // lineNo
    14,       // colNo
    "repmat", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m", // pName
    4 // checkKind
};

static emlrtRTEInfo pd_emlrtRTEI{
    59,       // lineNo
    28,       // colNo
    "repmat", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" // pName
};

// Function Definitions
namespace coder {
void b_repmat(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
              real_T varargin_1, ::coder::array<real_T, 2U> &b)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_varargin_1;
  int32_T i;
  int32_T ncols;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) ||
      muDoubleScalarIsInf(varargin_1) || (varargin_1 < -2.147483648E+9) ||
      (varargin_1 > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &l_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (varargin_1 <= 0.0) {
    b_varargin_1 = 0.0;
  } else {
    b_varargin_1 = varargin_1;
  }
  if (!(b_varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &cb_emlrtDCI, (emlrtCTX)sp);
  }
  i = static_cast<int32_T>(varargin_1);
  b.set_size(&pd_emlrtRTEI, sp, i, a.size(1));
  ncols = a.size(1);
  st.site = &mc_emlrtRSI;
  if ((1 <= a.size(1)) && (a.size(1) > 2147483646)) {
    b_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T jcol{0}; jcol < ncols; jcol++) {
    int32_T ibmat;
    ibmat = jcol * static_cast<int32_T>(varargin_1);
    st.site = &id_emlrtRSI;
    if ((1 <= static_cast<int32_T>(varargin_1)) &&
        (static_cast<int32_T>(varargin_1) > 2147483646)) {
      b_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T itilerow{0}; itilerow < i; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

void repmat(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
            real_T varargin_2, ::coder::array<real_T, 2U> &b)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_varargin_2;
  int32_T i;
  int32_T nrows;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((varargin_2 != muDoubleScalarFloor(varargin_2)) ||
      muDoubleScalarIsInf(varargin_2) || (varargin_2 < -2.147483648E+9) ||
      (varargin_2 > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &l_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (varargin_2 <= 0.0) {
    b_varargin_2 = 0.0;
  } else {
    b_varargin_2 = varargin_2;
  }
  if (!(b_varargin_2 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  i = static_cast<int32_T>(varargin_2);
  b.set_size(&pd_emlrtRTEI, sp, a.size(0), i);
  nrows = a.size(0);
  st.site = &lc_emlrtRSI;
  if ((1 <= static_cast<int32_T>(varargin_2)) &&
      (static_cast<int32_T>(varargin_2) > 2147483646)) {
    b_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T jtilecol{0}; jtilecol < i; jtilecol++) {
    int32_T ibtile;
    ibtile = jtilecol * nrows;
    st.site = &mc_emlrtRSI;
    st.site = &nc_emlrtRSI;
    if ((1 <= nrows) && (nrows > 2147483646)) {
      b_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T k{0}; k < nrows; k++) {
      b[ibtile + k] = a[k];
    }
  }
}

} // namespace coder

// End of code generation (repmat.cpp)
