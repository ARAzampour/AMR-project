//
// linspace.h
//
// Code generation for function 'linspace'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
void linspace(const emlrtStack *sp, real_T d2, real_T n,
              ::coder::array<real_T, 2U> &y);

void linspace(const emlrtStack *sp, real_T n, ::coder::array<real_T, 2U> &y);

} // namespace coder

// End of code generation (linspace.h)
