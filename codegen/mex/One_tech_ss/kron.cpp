//
// kron.cpp
//
// Code generation for function 'kron'
//

// Include files
#include "kron.h"
#include "One_tech_ss_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    xb_emlrtRSI{
        34,     // lineNo
        "kron", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" // pathName
    };

static emlrtRSInfo
    yb_emlrtRSI{
        35,     // lineNo
        "kron", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" // pathName
    };

static emlrtRSInfo
    ac_emlrtRSI{
        32,     // lineNo
        "kron", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" // pathName
    };

static emlrtRSInfo
    bc_emlrtRSI{
        33,     // lineNo
        "kron", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" // pathName
    };

static emlrtRTEInfo
    nd_emlrtRTEI{
        30,     // lineNo
        20,     // colNo
        "kron", // fName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\kron.m" // pName
    };

// Function Definitions
namespace coder {
void b_kron(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
            const ::coder::array<real_T, 2U> &B, ::coder::array<real_T, 2U> &K)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T kidx;
  int32_T na;
  int32_T nb;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  na = A.size(1);
  nb = B.size(1);
  K.set_size(&nd_emlrtRTEI, sp, 1, A.size(1) * B.size(1));
  kidx = -1;
  st.site = &ac_emlrtRSI;
  if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
    b_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T b_j1{0}; b_j1 < na; b_j1++) {
    st.site = &bc_emlrtRSI;
    if ((1 <= nb) && (nb > 2147483646)) {
      b_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T j2{0}; j2 < nb; j2++) {
      K[(kidx + j2) + 1] = A[b_j1] * B[j2];
    }
    kidx += nb;
  }
}

void kron(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
          const ::coder::array<real_T, 2U> &B, ::coder::array<real_T, 2U> &K)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T kidx;
  int32_T ma;
  int32_T na;
  int32_T nb;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ma = A.size(0);
  na = A.size(1);
  nb = B.size(1);
  K.set_size(&nd_emlrtRTEI, sp, A.size(0), A.size(1) * B.size(1));
  kidx = -1;
  st.site = &ac_emlrtRSI;
  if ((1 <= A.size(1)) && (A.size(1) > 2147483646)) {
    b_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T b_j1{0}; b_j1 < na; b_j1++) {
    st.site = &bc_emlrtRSI;
    if ((1 <= nb) && (nb > 2147483646)) {
      b_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T j2{0}; j2 < nb; j2++) {
      st.site = &xb_emlrtRSI;
      if ((1 <= ma) && (ma > 2147483646)) {
        b_st.site = &vb_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }
      for (int32_T i1{0}; i1 < ma; i1++) {
        K[(kidx + i1) + 1] = B[j2];
      }
      kidx += ma;
    }
  }
}

void kron(const emlrtStack *sp, const ::coder::array<real_T, 1U> &A,
          const ::coder::array<real_T, 1U> &B, ::coder::array<real_T, 1U> &K)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T kidx;
  int32_T ma;
  int32_T mb;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ma = A.size(0);
  mb = B.size(0);
  K.set_size(&nd_emlrtRTEI, sp, A.size(0) * B.size(0));
  kidx = -1;
  st.site = &xb_emlrtRSI;
  if ((1 <= A.size(0)) && (A.size(0) > 2147483646)) {
    b_st.site = &vb_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T i1{0}; i1 < ma; i1++) {
    st.site = &yb_emlrtRSI;
    if ((1 <= mb) && (mb > 2147483646)) {
      b_st.site = &vb_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (int32_T i2{0}; i2 < mb; i2++) {
      K[(kidx + i2) + 1] = A[i1];
    }
    kidx += mb;
  }
}

} // namespace coder

// End of code generation (kron.cpp)
