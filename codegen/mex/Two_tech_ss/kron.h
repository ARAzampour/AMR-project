//
// kron.h
//
// Code generation for function 'kron'
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
void b_kron(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
            const ::coder::array<real_T, 2U> &B, ::coder::array<real_T, 2U> &K);

void kron(const emlrtStack *sp, const ::coder::array<real_T, 2U> &A,
          const ::coder::array<real_T, 2U> &B, ::coder::array<real_T, 2U> &K);

void kron(const emlrtStack *sp, const ::coder::array<real_T, 1U> &A,
          const ::coder::array<real_T, 1U> &B, ::coder::array<real_T, 1U> &K);

} // namespace coder

// End of code generation (kron.h)
