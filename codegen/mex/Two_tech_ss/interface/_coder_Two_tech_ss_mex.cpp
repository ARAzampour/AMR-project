//
// _coder_Two_tech_ss_mex.cpp
//
// Code generation for function '_coder_Two_tech_ss_mex'
//

// Include files
#include "_coder_Two_tech_ss_mex.h"
#include "Two_tech_ss_data.h"
#include "Two_tech_ss_initialize.h"
#include "Two_tech_ss_terminate.h"
#include "_coder_Two_tech_ss_api.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void Two_tech_ss_mexFunction(int32_T nlhs, mxArray *plhs[17], int32_T nrhs,
                             const mxArray *prhs[20])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[17];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 20) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 20, 4,
                        11, "Two_tech_ss");
  }
  if (nlhs > 17) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "Two_tech_ss");
  }
  // Call the function.
  Two_tech_ss_api(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Two_tech_ss_atexit);
  // Module initialization.
  Two_tech_ss_initialize();
  try {
    emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
    // Dispatch the entry-point.
    Two_tech_ss_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    Two_tech_ss_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_Two_tech_ss_mex.cpp)
