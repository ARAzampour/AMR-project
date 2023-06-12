//
// validateNumericIndex.cpp
//
// Code generation for function 'validateNumericIndex'
//

// Include files
#include "validateNumericIndex.h"
#include "Two_tech_ss_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder {
void sparse_validateNumericIndex(const emlrtStack *sp, int32_T upperBound,
                                 const ::coder::array<real_T, 2U> &idx)
{
  int32_T i;
  i = idx.size(1);
  for (int32_T k{0}; k < i; k++) {
    real_T d;
    d = idx[k];
    if ((!(muDoubleScalarFloor(d) == d)) || muDoubleScalarIsInf(d) ||
        (!(d > 0.0))) {
      emlrtErrorWithMessageIdR2018a(sp, &u_emlrtRTEI,
                                    "Coder:MATLAB:badsubscript",
                                    "Coder:MATLAB:badsubscript", 0);
    }
    if (!(d <= upperBound)) {
      emlrtErrorWithMessageIdR2018a(
          sp, &v_emlrtRTEI, "Coder:builtins:IndexOutOfBounds",
          "Coder:builtins:IndexOutOfBounds", 6, 6, d, 12, 1, 12, upperBound);
    }
  }
}

} // namespace coder

// End of code generation (validateNumericIndex.cpp)
