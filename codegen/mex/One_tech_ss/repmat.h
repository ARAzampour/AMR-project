//
// repmat.h
//
// Code generation for function 'repmat'
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
void b_repmat(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
              real_T varargin_1, ::coder::array<real_T, 2U> &b);

void repmat(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
            real_T varargin_2, ::coder::array<real_T, 2U> &b);

} // namespace coder

// End of code generation (repmat.h)
