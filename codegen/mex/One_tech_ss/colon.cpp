//
// colon.cpp
//
// Code generation for function 'colon'
//

// Include files
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo
    jf_emlrtRSI{
        311,               // lineNo
        "eml_float_colon", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pathName
    };

static emlrtRTEInfo
    u_emlrtRTEI{
        411,               // lineNo
        15,                // colNo
        "assert_pmaxsize", // fName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pName
    };

static emlrtRTEInfo
    wd_emlrtRTEI{
        312,     // lineNo
        20,      // colNo
        "colon", // fName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pName
    };

// Function Definitions
namespace coder {
void eml_float_colon(const emlrtStack *sp, real_T a, real_T b,
                     ::coder::array<real_T, 2U> &y)
{
  emlrtStack st;
  real_T apnd;
  real_T cdiff;
  real_T ndbl;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  ndbl = muDoubleScalarFloor((b - a) + 0.5);
  apnd = a + ndbl;
  cdiff = apnd - b;
  if (muDoubleScalarAbs(cdiff) <
      4.4408920985006262E-16 *
          muDoubleScalarMax(muDoubleScalarAbs(a), muDoubleScalarAbs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = a + (ndbl - 1.0);
  } else {
    ndbl++;
  }
  if (ndbl >= 0.0) {
    n = static_cast<int32_T>(ndbl);
  } else {
    n = 0;
  }
  st.site = &jf_emlrtRSI;
  if (ndbl > 2.147483647E+9) {
    emlrtErrorWithMessageIdR2018a(&st, &u_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  y.set_size(&wd_emlrtRTEI, sp, 1, n);
  if (n > 0) {
    y[0] = a;
    if (n > 1) {
      int32_T nm1d2;
      y[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (int32_T k{0}; k <= nm1d2 - 2; k++) {
        y[k + 1] = a + (static_cast<real_T>(k) + 1.0);
        y[(n - k) - 2] = apnd - (static_cast<real_T>(k) + 1.0);
      }
      if (nm1d2 << 1 == n - 1) {
        y[nm1d2] = (a + apnd) / 2.0;
      } else {
        y[nm1d2] = a + static_cast<real_T>(nm1d2);
        y[nm1d2 + 1] = apnd - static_cast<real_T>(nm1d2);
      }
    }
  }
}

} // namespace coder

// End of code generation (colon.cpp)
