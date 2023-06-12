//
// expcdf.cpp
//
// Code generation for function 'expcdf'
//

// Include files
#include "expcdf.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtBCInfo cb_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    42,       // lineNo
    32,       // colNo
    "",       // aName
    "expcdf", // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expcdf.m", // pName
    0 // checkKind
};

static emlrtBCInfo db_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    70,       // lineNo
    11,       // colNo
    "",       // aName
    "expcdf", // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expcdf.m", // pName
    0 // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    52,       // lineNo
    15,       // colNo
    "",       // aName
    "expcdf", // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expcdf.m", // pName
    0 // checkKind
};

static emlrtRTEInfo kd_emlrtRTEI{
    36,                                                                // lineNo
    5,                                                                 // colNo
    "expcdf",                                                          // fName
    "D:\\Program Files\\MATLAB\\R2021b\\toolbox\\stats\\eml\\expcdf.m" // pName
};

// Function Definitions
namespace coder {
void expcdf(const emlrtStack *sp, const ::coder::array<real_T, 2U> &x,
            real_T varargin_1, ::coder::array<real_T, 2U> &p)
{
  int32_T i;
  p.set_size(&kd_emlrtRTEI, sp, 1, x.size(1));
  i = x.size(1);
  for (int32_T k{0}; k < i; k++) {
    if (k + 1 > x.size(1)) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, x.size(1), &cb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((varargin_1 > 0.0) && (!muDoubleScalarIsNaN(x[k]))) {
      real_T b_x;
      real_T u;
      real_T zk_tmp;
      zk_tmp = x[k] / varargin_1;
      b_x = -zk_tmp;
      u = muDoubleScalarExp(-zk_tmp);
      if ((u < 1.1102230246251565E-16) || muDoubleScalarIsNaN(u)) {
        b_x = u - 1.0;
      } else if (u < 0.5) {
        b_x = (u - 1.0) * (-zk_tmp / muDoubleScalarLog(u));
      } else if (u != 1.0) {
        b_x = u - 1.0;
        if (muDoubleScalarIsNaN(u - 1.0)) {
          b_x = muDoubleScalarLog((u - 1.0) + 1.0);
        } else if (!(muDoubleScalarAbs(u - 1.0) < 2.2204460492503131E-16)) {
          b_x = muDoubleScalarLog((u - 1.0) + 1.0) *
                ((u - 1.0) / (((u - 1.0) + 1.0) - 1.0));
        }
        b_x = (u - 1.0) * (-zk_tmp / b_x);
      }
      if (k + 1 > p.size(1)) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, p.size(1), &eb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      p[k] = -b_x;
    } else {
      if (k + 1 > p.size(1)) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, p.size(1), &db_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      p[k] = rtNaN;
    }
  }
}

} // namespace coder

// End of code generation (expcdf.cpp)
