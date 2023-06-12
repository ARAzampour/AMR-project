//
// One_tech_ss_terminate.cpp
//
// Code generation for function 'One_tech_ss_terminate'
//

// Include files
#include "One_tech_ss_terminate.h"
#include "One_tech_ss_data.h"
#include "_coder_One_tech_ss_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void One_tech_ss_atexit()
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

void One_tech_ss_terminate()
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

// End of code generation (One_tech_ss_terminate.cpp)
