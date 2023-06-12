//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "One_tech_ss_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo jd_emlrtRSI{
    20,    // lineNo
    "sum", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtRSInfo kd_emlrtRSI{
    99,        // lineNo
    "sumprod", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" // pathName
};

static emlrtRSInfo ld_emlrtRSI{
    74,                      // lineNo
    "combineVectorElements", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtRSInfo md_emlrtRSI{
    112,                // lineNo
    "blockedSummation", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo nd_emlrtRSI{
    173,                // lineNo
    "colMajorFlatIter", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    192,                // lineNo
    "colMajorFlatIter", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo pd_emlrtRSI{
    207,                // lineNo
    "colMajorFlatIter", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    227,                // lineNo
    "colMajorFlatIter", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo rd_emlrtRSI{
    238,                // lineNo
    "colMajorFlatIter", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo rf_emlrtRSI{
    99,                 // lineNo
    "blockedSummation", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRSInfo sf_emlrtRSI{
    22,                    // lineNo
    "sumMatrixIncludeNaN", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRSInfo tf_emlrtRSI{
    42,                 // lineNo
    "sumMatrixColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRSInfo uf_emlrtRSI{
    57,                 // lineNo
    "sumMatrixColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" // pathName
};

static emlrtRTEInfo td_emlrtRTEI{
    146,                // lineNo
    24,                 // colNo
    "blockedSummation", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pName
};

static emlrtRTEInfo ud_emlrtRTEI{
    153,                // lineNo
    23,                 // colNo
    "blockedSummation", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pName
};

static emlrtRTEInfo vd_emlrtRTEI{
    20,    // lineNo
    1,     // colNo
    "sum", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pName
};

// Function Definitions
namespace coder {
real_T sum(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x)
{
  array<real_T, 1U> c_x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jd_emlrtRSI;
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
  b_st.site = &kd_emlrtRSI;
  c_st.site = &ld_emlrtRSI;
  if (x.size(1) == 0) {
    y = 0.0;
  } else {
    d_st.site = &rf_emlrtRSI;
    e_st.site = &sf_emlrtRSI;
    if (x.size(1) < 4096) {
      int32_T b_x;
      b_x = x.size(1);
      c_x = x.reshape(b_x);
      f_st.site = &tf_emlrtRSI;
      y = sumColumnB(&f_st, c_x, x.size(1));
    } else {
      int32_T b_x;
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = x.size(1) / 4096;
      inb = nfb << 12;
      nleft = x.size(1) - inb;
      b_x = x.size(1);
      c_x = x.reshape(b_x);
      y = sumColumnB4(c_x, 1);
      if (2 <= nfb) {
        b_x = x.size(1);
      }
      for (int32_T ib{2}; ib <= nfb; ib++) {
        c_x = x.reshape(b_x);
        y += sumColumnB4(c_x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        b_x = x.size(1);
        c_x = x.reshape(b_x);
        f_st.site = &uf_emlrtRSI;
        y += sumColumnB(&f_st, c_x, nleft, inb + 1);
      }
    }
  }
  return y;
}

void sum(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
         ::coder::array<real_T, 1U> &y)
{
  array<real_T, 1U> bsum;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &jd_emlrtRSI;
  b_st.site = &kd_emlrtRSI;
  c_st.site = &ld_emlrtRSI;
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    int32_T firstBlockLength;
    y.set_size(&vd_emlrtRTEI, &c_st, x.size(0));
    firstBlockLength = x.size(0);
    for (int32_T hi{0}; hi < firstBlockLength; hi++) {
      y[hi] = 0.0;
    }
  } else {
    int32_T bvstride;
    int32_T firstBlockLength;
    int32_T k;
    int32_T lastBlockLength;
    int32_T nblocks;
    int32_T vstride;
    int32_T xj;
    int32_T xoffset;
    d_st.site = &md_emlrtRSI;
    vstride = x.size(0);
    bvstride = x.size(0) << 10;
    y.set_size(&td_emlrtRTEI, &d_st, x.size(0));
    bsum.set_size(&ud_emlrtRTEI, &d_st, x.size(0));
    if (x.size(1) <= 1024) {
      firstBlockLength = x.size(1);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = x.size(1) / 1024;
      lastBlockLength = x.size(1) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    e_st.site = &nd_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xj = 0; xj < vstride; xj++) {
      y[xj] = x[xj];
      bsum[xj] = 0.0;
    }
    for (k = 2; k <= firstBlockLength; k++) {
      xoffset = (k - 1) * vstride;
      e_st.site = &od_emlrtRSI;
      if (vstride > 2147483646) {
        f_st.site = &vb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }
      for (xj = 0; xj < vstride; xj++) {
        y[xj] = y[xj] + x[xoffset + xj];
      }
    }
    for (int32_T ib{2}; ib <= nblocks; ib++) {
      int32_T hi;
      firstBlockLength = (ib - 1) * bvstride;
      e_st.site = &pd_emlrtRSI;
      if (vstride > 2147483646) {
        f_st.site = &vb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }
      for (xj = 0; xj < vstride; xj++) {
        bsum[xj] = x[firstBlockLength + xj];
      }
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (k = 2; k <= hi; k++) {
        xoffset = firstBlockLength + (k - 1) * vstride;
        e_st.site = &qd_emlrtRSI;
        for (xj = 0; xj < vstride; xj++) {
          bsum[xj] = bsum[xj] + x[xoffset + xj];
        }
      }
      e_st.site = &rd_emlrtRSI;
      for (xj = 0; xj < vstride; xj++) {
        y[xj] = y[xj] + bsum[xj];
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

} // namespace coder

// End of code generation (sum.cpp)
