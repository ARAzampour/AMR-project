//
// Two_tech_ss_terminate.cpp
//
// Code generation for function 'Two_tech_ss_terminate'
//

// Include files
#include "Two_tech_ss_terminate.h"
#include "Two_tech_ss_data.h"
#include "_coder_Two_tech_ss_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void Two_tech_ss_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Two_tech_ss_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (Two_tech_ss_terminate.cpp)
