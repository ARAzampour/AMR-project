//
// expinv.h
//
// Code generation for function 'expinv'
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
void expinv(const emlrtStack *sp, const ::coder::array<real_T, 2U> &p,
            real_T mu, ::coder::array<real_T, 2U> &x);

}

// End of code generation (expinv.h)
