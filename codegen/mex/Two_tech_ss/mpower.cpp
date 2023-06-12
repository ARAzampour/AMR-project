//
// mpower.cpp
//
// Code generation for function 'mpower'
//

// Include files
#include "mpower.h"
#include "Two_tech_ss_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

// Function Definitions
namespace coder {
real_T mpower(const emlrtStack *sp, real_T a, real_T b)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &oc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &pc_emlrtRSI;
  if ((a < 0.0) && (!muDoubleScalarIsNaN(b)) && (muDoubleScalarFloor(b) != b)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
                                  "Coder:toolbox:power_domainError",
                                  "Coder:toolbox:power_domainError", 0);
  }
  return muDoubleScalarPower(a, b);
}

} // namespace coder

// End of code generation (mpower.cpp)
