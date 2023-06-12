//
// expinv.cpp
//
// Code generation for function 'expinv'
//

// Include files
#include "expinv.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtBCInfo w_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    33,       // lineNo
    32,       // colNo
    "",       // aName
    "expinv", // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expinv.m", // pName
    0 // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    56,       // lineNo
    11,       // colNo
    "",       // aName
    "expinv", // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expinv.m", // pName
    0 // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    43,       // lineNo
    15,       // colNo
    "",       // aName
    "expinv", // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expinv.m", // pName
    0 // checkKind
};

static emlrtBCInfo ab_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    40,       // lineNo
    19,       // colNo
    "",       // aName
    "expinv", // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expinv.m", // pName
    0 // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    38,       // lineNo
    19,       // colNo
    "",       // aName
    "expinv", // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expinv.m", // pName
    0 // checkKind
};

static emlrtRTEInfo jd_emlrtRTEI{
    27,                                                                // lineNo
    5,                                                                 // colNo
    "expinv",                                                          // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expinv.m" // pName
};

// Function Definitions
namespace coder {
void expinv(const emlrtStack *sp, const ::coder::array<real_T, 2U> &p,
            real_T mu, ::coder::array<real_T, 2U> &x)
{
  int32_T i;
  x.set_size(&jd_emlrtRTEI, sp, 1, p.size(1));
  i = p.size(1);
  for (int32_T k{0}; k < i; k++) {
    if (k + 1 > p.size(1)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, p.size(1), &w_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((mu > 0.0) && (p[k] <= 1.0)) {
      if (p[k] > 0.0) {
        if (p[k] < 1.0) {
          if (k + 1 > x.size(1)) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, x.size(1), &bb_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          x[k] = -mu * muDoubleScalarLog(1.0 - p[k]);
        } else {
          if (k + 1 > x.size(1)) {
            emlrtDynamicBoundsCheckR2012b(k + 1, 1, x.size(1), &ab_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          x[k] = rtInf;
        }
      } else {
        if (k + 1 > x.size(1)) {
          emlrtDynamicBoundsCheckR2012b(k + 1, 1, x.size(1), &y_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        x[k] = 0.0;
      }
    } else {
      if (k + 1 > x.size(1)) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, x.size(1), &x_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      x[k] = rtNaN;
    }
  }
}

} // namespace coder

// End of code generation (expinv.cpp)
