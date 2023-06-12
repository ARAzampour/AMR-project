//
// abs.h
//
// Code generation for function 'abs'
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
void b_abs(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
           ::coder::array<real_T, 2U> &y);

void c_abs(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
           ::coder::array<real_T, 2U> &y);

} // namespace coder

// End of code generation (abs.h)
