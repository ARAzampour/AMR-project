//
// mtimes.cpp
//
// Code generation for function 'mtimes'
//

// Include files
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "coder_array.h"
#include <cstddef>

// Variable Definitions
static emlrtRSInfo ld_emlrtRSI{
    142,      // lineNo
    "mtimes", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

static emlrtRSInfo md_emlrtRSI{
    178,           // lineNo
    "mtimes_blas", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

static emlrtRTEInfo mf_emlrtRTEI{
    218,      // lineNo
    20,       // colNo
    "mtimes", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pName
};

static emlrtRTEInfo nf_emlrtRTEI{
    140,      // lineNo
    5,        // colNo
    "mtimes", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
real_T mtimes(const ::coder::array<real_T, 2U> &A,
              const ::coder::array<real_T, 2U> &B)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T C;
  if (A.size(1) < 1) {
    C = 0.0;
  } else {
    n_t = (ptrdiff_t)A.size(1);
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    C = ddot(&n_t, (real_T *)&A[0], &incx_t, (real_T *)&B[0], &incy_t);
  }
  return C;
}

real_T mtimes(const ::coder::array<real_T, 2U> &A,
              const ::coder::array<real_T, 1U> &B)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T C;
  if (A.size(1) < 1) {
    C = 0.0;
  } else {
    n_t = (ptrdiff_t)A.size(1);
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    C = ddot(&n_t, (real_T *)&A[0], &incx_t,
             &(((::coder::array<real_T, 1U> *)&B)->data())[0], &incy_t);
  }
  return C;
}

void mtimes(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
            const ::coder::array<real_T, 2U> &B, ::coder::array<real_T, 1U> &C)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if ((A.size(0) == 0) || (A.size(1) == 0) || (B.size(1) == 0)) {
    int32_T loop_ub;
    C.set_size(&nf_emlrtRTEI, sp, A.size(0));
    loop_ub = A.size(0);
    for (int32_T i{0}; i < loop_ub; i++) {
      C[i] = 0.0;
    }
  } else {
    st.site = &ld_emlrtRSI;
    b_st.site = &md_emlrtRSI;
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    alpha1 = 1.0;
    beta1 = 0.0;
    m_t = (ptrdiff_t)A.size(0);
    n_t = (ptrdiff_t)1;
    k_t = (ptrdiff_t)A.size(1);
    lda_t = (ptrdiff_t)A.size(0);
    ldb_t = (ptrdiff_t)1;
    ldc_t = (ptrdiff_t)A.size(0);
    C.set_size(&mf_emlrtRTEI, &b_st, A.size(0));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
          &(((::coder::array<real_T, 2U> *)&A)->data())[0], &lda_t,
          (real_T *)&B[0], &ldb_t, &beta1, &(C.data())[0], &ldc_t);
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (mtimes.cpp)
