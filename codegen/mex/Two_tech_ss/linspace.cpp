//
// linspace.cpp
//
// Code generation for function 'linspace'
//

// Include files
#include "linspace.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo k_emlrtRTEI{
    33,         // lineNo
    37,         // colNo
    "linspace", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" // pName
};

static emlrtRTEInfo ef_emlrtRTEI{
    49,         // lineNo
    20,         // colNo
    "linspace", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" // pName
};

static emlrtRTEInfo ff_emlrtRTEI{
    34,         // lineNo
    5,          // colNo
    "linspace", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\linspace.m" // pName
};

// Function Definitions
namespace coder {
void linspace(const emlrtStack *sp, real_T d2, real_T n,
              ::coder::array<real_T, 2U> &y)
{
  if (!(n >= 0.0)) {
    if (muDoubleScalarIsNaN(n)) {
      emlrtErrorWithMessageIdR2018a(sp, &k_emlrtRTEI,
                                    "Coder:toolbox:MustNotBeNaN",
                                    "Coder:toolbox:MustNotBeNaN", 3, 4, 1, "N");
    }
    y.set_size(&ff_emlrtRTEI, sp, 1, 0);
  } else {
    real_T delta1;
    delta1 = muDoubleScalarFloor(n);
    y.set_size(&ef_emlrtRTEI, sp, 1, static_cast<int32_T>(delta1));
    if (static_cast<int32_T>(delta1) >= 1) {
      int32_T y_tmp;
      y_tmp = static_cast<int32_T>(delta1) - 1;
      y[static_cast<int32_T>(delta1) - 1] = d2;
      if (y.size(1) >= 2) {
        y[0] = 0.0;
        if (y.size(1) >= 3) {
          if ((0.0 == -d2) && (static_cast<int32_T>(delta1) > 2)) {
            real_T d2scaled;
            d2scaled =
                d2 / (static_cast<real_T>(static_cast<int32_T>(delta1)) - 1.0);
            for (int32_T k{2}; k <= y_tmp; k++) {
              y[k - 1] = static_cast<real_T>(
                             ((k << 1) - static_cast<int32_T>(delta1)) - 1) *
                         d2scaled;
            }
            if ((static_cast<int32_T>(delta1) & 1) == 1) {
              y[static_cast<int32_T>(delta1) >> 1] = 0.0;
            }
          } else if ((d2 < 0.0) &&
                     (muDoubleScalarAbs(d2) > 8.9884656743115785E+307)) {
            delta1 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
            y_tmp = y.size(1);
            for (int32_T k{0}; k <= y_tmp - 3; k++) {
              y[k + 1] = delta1 * (static_cast<real_T>(k) + 1.0);
            }
          } else {
            delta1 = d2 / (static_cast<real_T>(y.size(1)) - 1.0);
            y_tmp = y.size(1);
            for (int32_T k{0}; k <= y_tmp - 3; k++) {
              y[k + 1] = (static_cast<real_T>(k) + 1.0) * delta1;
            }
          }
        }
      }
    }
  }
}

void linspace(const emlrtStack *sp, real_T n, ::coder::array<real_T, 2U> &y)
{
  if (!(n >= 0.0)) {
    if (muDoubleScalarIsNaN(n)) {
      emlrtErrorWithMessageIdR2018a(sp, &k_emlrtRTEI,
                                    "Coder:toolbox:MustNotBeNaN",
                                    "Coder:toolbox:MustNotBeNaN", 3, 4, 1, "N");
    }
    y.set_size(&ff_emlrtRTEI, sp, 1, 0);
  } else {
    real_T delta1;
    delta1 = muDoubleScalarFloor(n);
    y.set_size(&ef_emlrtRTEI, sp, 1, static_cast<int32_T>(delta1));
    if (static_cast<int32_T>(delta1) >= 1) {
      y[static_cast<int32_T>(delta1) - 1] = 0.999;
      if (y.size(1) >= 2) {
        y[0] = 0.0;
        if (y.size(1) >= 3) {
          int32_T i;
          delta1 = 0.999 / (static_cast<real_T>(y.size(1)) - 1.0);
          i = y.size(1);
          for (int32_T k{0}; k <= i - 3; k++) {
            y[k + 1] = (static_cast<real_T>(k) + 1.0) * delta1;
          }
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (linspace.cpp)
