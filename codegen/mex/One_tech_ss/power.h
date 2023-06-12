//
// power.h
//
// Code generation for function 'power'
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
void power(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a, real_T b,
           ::coder::array<real_T, 2U> &y);

void power(const emlrtStack *sp, real_T a, const ::coder::array<real_T, 1U> &b,
           ::coder::array<real_T, 1U> &y);

} // namespace coder

// End of code generation (power.h)
