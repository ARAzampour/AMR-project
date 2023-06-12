//
// One_tech_ss_initialize.cpp
//
// Code generation for function 'One_tech_ss_initialize'
//

// Include files
#include "One_tech_ss_initialize.h"
#include "One_tech_ss_data.h"
#include "_coder_One_tech_ss_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void One_tech_ss_initialize()
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

// End of code generation (One_tech_ss_initialize.cpp)
