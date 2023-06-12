//
// ixfun.cpp
//
// Code generation for function 'ixfun'
//

// Include files
#include "ixfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo o_emlrtRTEI{
    160,          // lineNo
    23,           // colNo
    "expand_max", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" // pName
};

static emlrtRTEInfo od_emlrtRTEI{
    169,     // lineNo
    20,      // colNo
    "ixfun", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void expand_max(const emlrtStack *sp, const ::coder::array<real_T, 1U> &a,
                const ::coder::array<real_T, 1U> &b,
                ::coder::array<real_T, 1U> &c)
{
  int32_T sak;
  int32_T sbk;
  sak = a.size(0);
  sbk = b.size(0);
  if (b.size(0) == 1) {
    sak = a.size(0);
  } else if (a.size(0) == 1) {
    sak = b.size(0);
  } else {
    sak = muIntScalarMin_sint32(sak, sbk);
    if (a.size(0) != b.size(0)) {
      emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
                                    "MATLAB:sizeDimensionsMustMatch",
                                    "MATLAB:sizeDimensionsMustMatch", 0);
    }
  }
  c.set_size(&od_emlrtRTEI, sp, sak);
  if (sak != 0) {
    int32_T bcoef;
    sbk = (a.size(0) != 1);
    bcoef = (b.size(0) != 1);
    sak--;
    for (int32_T k{0}; k <= sak; k++) {
      c[k] = muDoubleScalarMax(a[sbk * k], b[bcoef * k]);
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (ixfun.cpp)
