//
// _coder_One_tech_ss_mex.cpp
//
// Code generation for function '_coder_One_tech_ss_mex'
//

// Include files
#include "_coder_One_tech_ss_mex.h"
#include "One_tech_ss_data.h"
#include "One_tech_ss_initialize.h"
#include "One_tech_ss_terminate.h"
#include "_coder_One_tech_ss_api.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void One_tech_ss_mexFunction(int32_T nlhs, mxArray *plhs[11], int32_T nrhs,
                             const mxArray *prhs[17])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[11];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 17) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 17, 4,
                        11, "One_tech_ss");
  }
  if (nlhs > 11) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "One_tech_ss");
  }
  // Call the function.
  One_tech_ss_api(prhs, nlhs, outputs);
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
  mexAtExit(&One_tech_ss_atexit);
  // Module initialization.
  One_tech_ss_initialize();
  try {
    emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
    // Dispatch the entry-point.
    One_tech_ss_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    One_tech_ss_terminate();
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

// End of code generation (_coder_One_tech_ss_mex.cpp)
