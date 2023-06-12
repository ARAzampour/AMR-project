//
// sum.h
//
// Code generation for function 'sum'
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
real_T sum(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x);

void sum(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
         ::coder::array<real_T, 1U> &y);

} // namespace coder

// End of code generation (sum.h)
