//
// Two_tech_ss_initialize.cpp
//
// Code generation for function 'Two_tech_ss_initialize'
//

// Include files
#include "Two_tech_ss_initialize.h"
#include "Two_tech_ss_data.h"
#include "_coder_Two_tech_ss_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void Two_tech_ss_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, (const char_T *)"statistics_toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (Two_tech_ss_initialize.cpp)
