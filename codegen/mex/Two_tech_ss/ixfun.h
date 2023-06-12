//
// ixfun.h
//
// Code generation for function 'ixfun'
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
namespace internal {
void expand_max(const emlrtStack *sp, const ::coder::array<real_T, 1U> &a,
                const ::coder::array<real_T, 1U> &b,
                ::coder::array<real_T, 1U> &c);

}
} // namespace coder

// End of code generation (ixfun.h)
