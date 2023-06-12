//
// sparse1.cpp
//
// Code generation for function 'sparse1'
//

// Include files
#include "sparse1.h"
#include "Two_tech_ss_data.h"
#include "Two_tech_ss_types.h"
#include "bigProduct.h"
#include "eml_int_forloop_overflow_check.h"
#include "locBsearch.h"
#include "rt_nonfinite.h"
#include "validateNumericIndex.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>

// Variable Definitions
static emlrtRSInfo qe_emlrtRSI{
    264,                  // lineNo
    "sparse/parenAssign", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo re_emlrtRSI{
    56,                     // lineNo
    "sparse/parenAssign2D", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo se_emlrtRSI{
    132,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo te_emlrtRSI{
    137,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ue_emlrtRSI{
    174,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ve_emlrtRSI{
    184,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo we_emlrtRSI{
    186,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo xe_emlrtRSI{
    188,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ye_emlrtRSI{
    189,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo af_emlrtRSI{
    192,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo bf_emlrtRSI{
    198,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo cf_emlrtRSI{
    199,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo df_emlrtRSI{
    435,                  // lineNo
    "countNumnzInColumn", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ef_emlrtRSI{
    329,       // lineNo
    "realloc", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ff_emlrtRSI{
    337,       // lineNo
    "realloc", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo gf_emlrtRSI{
    342,       // lineNo
    "realloc", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo hf_emlrtRSI{
    245,                  // lineNo
    "shiftRowidxAndData", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo if_emlrtRSI{
    246,                  // lineNo
    "shiftRowidxAndData", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo jf_emlrtRSI{
    300,                 // lineNo
    "copyNonzeroValues", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo kf_emlrtRSI{
    264,          // lineNo
    "incrColIdx", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo lf_emlrtRSI{
    271,          // lineNo
    "decrColIdx", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo mf_emlrtRSI{
    262,                  // lineNo
    "sparse/parenAssign", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo nf_emlrtRSI{
    22,                     // lineNo
    "sparse/parenAssign1D", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign1D.m" // pathName
};

static emlrtRSInfo of_emlrtRSI{
    36,                     // lineNo
    "parenAssign1DNumeric", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign1D.m" // pathName
};

static emlrtRSInfo pf_emlrtRSI{
    38,                     // lineNo
    "parenAssign1DNumeric", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign1D.m" // pathName
};

static emlrtRSInfo qf_emlrtRSI{
    42,                     // lineNo
    "parenAssign1DNumeric", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign1D.m" // pathName
};

static emlrtRSInfo rf_emlrtRSI{
    44,                     // lineNo
    "parenAssign1DNumeric", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign1D.m" // pathName
};

static emlrtRSInfo sf_emlrtRSI{
    50,                     // lineNo
    "parenAssign1DNumeric", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign1D.m" // pathName
};

static emlrtRSInfo tf_emlrtRSI{
    19,        // lineNo
    "ind2sub", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pathName
};

static emlrtRSInfo uf_emlrtRSI{
    66,                     // lineNo
    "sparse/parenAssign2D", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo vf_emlrtRSI{
    77,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo wf_emlrtRSI{
    78,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo xf_emlrtRSI{
    81,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo yf_emlrtRSI{
    110,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ag_emlrtRSI{
    115,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo bg_emlrtRSI{
    119,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo cg_emlrtRSI{
    123,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo dg_emlrtRSI{
    124,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ig_emlrtRSI{
    87,                         // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo jg_emlrtRSI{
    89,                         // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo kg_emlrtRSI{
    41,              // lineNo
    "sparse/mtimes", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\mtimes.m" // pathName
};

static emlrtRSInfo lg_emlrtRSI{
    145,        // lineNo
    "fsmtimes", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\mtimes.m" // pathName
};

static emlrtRSInfo mg_emlrtRSI{
    192,                  // lineNo
    "sfmtimes_vector_at", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\mtimes.m" // pathName
};

static emlrtRSInfo ng_emlrtRSI{
    195,                  // lineNo
    "sfmtimes_vector_at", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\mtimes.m" // pathName
};

static emlrtRTEInfo x_emlrtRTEI{
    29,              // lineNo
    23,              // colNo
    "sparse/mtimes", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\mtimes.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    237,            // lineNo
    13,             // colNo
    "sparse/numel", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    36,                     // lineNo
    23,                     // colNo
    "sparse/parenAssign2D", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    11,                     // lineNo
    23,                     // colNo
    "sparse/parenAssign1D", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign1D.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    40,                   // lineNo
    15,                   // colNo
    "ind2sub_indexClass", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pName
};

static emlrtRTEInfo uf_emlrtRTEI{
    41,       // lineNo
    5,        // colNo
    "mtimes", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\mtimes.m" // pName
};

static emlrtRTEInfo vf_emlrtRTEI{
    325,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo wf_emlrtRTEI{
    326,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo xf_emlrtRTEI{
    264,      // lineNo
    17,       // colNo
    "sparse", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo yf_emlrtRTEI{
    333,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo ag_emlrtRTEI{
    334,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRSInfo
    hh_emlrtRSI{
        19,            // lineNo
        "indexDivide", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\indexDivide.m" // pathName
    };

// Function Declarations
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator);

// Function Definitions
namespace coder {
void sparse::b_realloc(const emlrtStack *sp, sparse *b_this,
                       int32_T numAllocRequested, int32_T ub1, int32_T lb2,
                       int32_T ub2)
{
  array<real_T, 1U> dt;
  array<int32_T, 1U> rowidxt;
  emlrtStack b_st;
  emlrtStack st;
  int32_T numAlloc;
  int32_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  rowidxt.set_size(&vf_emlrtRTEI, sp, b_this->rowidx.size(0));
  numAlloc = b_this->rowidx.size(0);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    rowidxt[overflow] = b_this->rowidx[overflow];
  }
  dt.set_size(&wf_emlrtRTEI, sp, b_this->d.size(0));
  numAlloc = b_this->d.size(0);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    dt[overflow] = b_this->d[overflow];
  }
  internal::bigProduct(b_this->m, b_this->n, &numAlloc, &overflow);
  if (overflow == 0) {
    st.site = &ef_emlrtRSI;
    internal::bigProduct(b_this->m, b_this->n, &numAlloc, &overflow);
    if (overflow != 0) {
      emlrtErrorWithMessageIdR2018a(&st, &bb_emlrtRTEI,
                                    "Coder:toolbox:SparseNumelTooBig",
                                    "Coder:toolbox:SparseNumelTooBig", 0);
    }
    numAlloc = b_this->m * b_this->n;
    numAlloc = muIntScalarMin_sint32(numAllocRequested, numAlloc);
    numAlloc = muIntScalarMax_sint32(1, numAlloc);
  } else {
    numAlloc = muIntScalarMax_sint32(1, numAllocRequested);
  }
  b_this->rowidx.set_size(&yf_emlrtRTEI, sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    b_this->rowidx[overflow] = 0;
  }
  b_this->d.set_size(&ag_emlrtRTEI, sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    b_this->d[overflow] = 0.0;
  }
  b_this->maxnz = numAlloc;
  st.site = &ff_emlrtRSI;
  if ((1 <= ub1) && (ub1 > 2147483646)) {
    b_st.site = &uc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (numAlloc = 0; numAlloc < ub1; numAlloc++) {
    b_this->rowidx[numAlloc] = rowidxt[numAlloc];
    b_this->d[numAlloc] = dt[numAlloc];
  }
  st.site = &gf_emlrtRSI;
  if ((lb2 <= ub2) && (ub2 > 2147483646)) {
    b_st.site = &uc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (numAlloc = lb2; numAlloc <= ub2; numAlloc++) {
    b_this->rowidx[numAlloc] = rowidxt[numAlloc - 1];
    b_this->d[numAlloc] = dt[numAlloc - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

int32_T sparse::copyNonzeroValues(const emlrtStack *sp, sparse *b_this,
                                  struct_T *rhsIter, int32_T outStart,
                                  const ::coder::array<real_T, 2U> &rhs)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T outIdx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  outIdx = outStart;
  b = b_this->m;
  st.site = &jf_emlrtRSI;
  if ((1 <= b_this->m) && (b_this->m > 2147483646)) {
    b_st.site = &uc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T k{0}; k < b; k++) {
    real_T rhsv;
    rhsv = rhs[rhsIter->idx - 1];
    rhsIter->idx++;
    rhsIter->row++;
    if (rhsv != 0.0) {
      b_this->rowidx[outIdx - 1] = k + 1;
      b_this->d[outIdx - 1] = rhsv;
      outIdx++;
    }
  }
  return outIdx;
}

void sparse::decrColIdx(const emlrtStack *sp, sparse *b_this, int32_T col,
                        int32_T offs)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T b_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a = col + 1;
  b_tmp = b_this->n + 1;
  st.site = &lf_emlrtRSI;
  if ((col + 1 <= b_tmp) && (b_tmp > 2147483646)) {
    b_st.site = &uc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T k{a}; k <= b_tmp; k++) {
    b_this->colidx[k - 1] = b_this->colidx[k - 1] - offs;
  }
}

void sparse::incrColIdx(const emlrtStack *sp, sparse *b_this, int32_T col,
                        int32_T offs)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T b_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  a = col + 1;
  b_tmp = b_this->n + 1;
  st.site = &kf_emlrtRSI;
  if ((col + 1 <= b_tmp) && (b_tmp > 2147483646)) {
    b_st.site = &uc_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (int32_T k{a}; k <= b_tmp; k++) {
    b_this->colidx[k - 1] = b_this->colidx[k - 1] + offs;
  }
}

} // namespace coder
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(nullptr, (emlrtCTX)sp);
  } else {
    uint32_T b_denominator;
    uint32_T b_numerator;
    if (numerator < 0) {
      b_numerator = ~static_cast<uint32_T>(numerator) + 1U;
    } else {
      b_numerator = static_cast<uint32_T>(numerator);
    }
    if (denominator < 0) {
      b_denominator = ~static_cast<uint32_T>(denominator) + 1U;
    } else {
      b_denominator = static_cast<uint32_T>(denominator);
    }
    b_numerator /= b_denominator;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -static_cast<int32_T>(b_numerator);
    } else {
      quotient = static_cast<int32_T>(b_numerator);
    }
  }
  return quotient;
}

namespace coder {
void sparse::mtimes(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a,
                    ::coder::array<real_T, 2U> &c) const
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T apend_tmp;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (a.size(1) != m) {
    emlrtErrorWithMessageIdR2018a(sp, &x_emlrtRTEI, "MATLAB:innerdim",
                                  "MATLAB:innerdim", 0);
  }
  st.site = &kg_emlrtRSI;
  c.set_size(&uf_emlrtRTEI, &st, 1, n);
  loop_ub = n;
  for (apend_tmp = 0; apend_tmp < loop_ub; apend_tmp++) {
    c[apend_tmp] = 0.0;
  }
  if ((a.size(1) != 0) && (n != 0) && (colidx[colidx.size(0) - 1] - 1 != 0)) {
    b_st.site = &lg_emlrtRSI;
    loop_ub = n;
    c_st.site = &mg_emlrtRSI;
    if ((1 <= n) && (n > 2147483646)) {
      d_st.site = &uc_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (int32_T k{0}; k < loop_ub; k++) {
      real_T cd;
      int32_T b_a;
      cd = 0.0;
      apend_tmp = colidx[k + 1] - 1;
      b_a = colidx[k];
      c_st.site = &ng_emlrtRSI;
      if ((colidx[k] <= apend_tmp) && (apend_tmp > 2147483646)) {
        d_st.site = &uc_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      for (int32_T ap{b_a}; ap <= apend_tmp; ap++) {
        cd += d[ap - 1] * a[rowidx[ap - 1] - 1];
      }
      c[k] = cd;
    }
  }
}

void sparse::parenAssign(const emlrtStack *sp,
                         const ::coder::array<real_T, 2U> &rhs,
                         const ::coder::array<real_T, 2U> &varargin_2)
{
  array<real_T, 1U> dt;
  array<int32_T, 1U> rowidxt;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  struct_T rhsIter;
  int32_T k;
  int32_T nzColAlloc;
  int32_T sm;
  int32_T sn;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &qe_emlrtRSI;
  if ((m != rhs.size(0)) || (varargin_2.size(1) != rhs.size(1))) {
    emlrtErrorWithMessageIdR2018a(&st, &cb_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &re_emlrtRSI;
  c_st.site = &se_emlrtRSI;
  sparse_validateNumericIndex(&c_st, n, varargin_2);
  sm = m;
  sn = varargin_2.size(1);
  rhsIter.idx = 1;
  rhsIter.col = 1;
  rhsIter.row = 1;
  c_st.site = &te_emlrtRSI;
  if ((1 <= varargin_2.size(1)) && (varargin_2.size(1) > 2147483646)) {
    d_st.site = &uc_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (int32_T cidx{0}; cidx < sn; cidx++) {
    int32_T b_n;
    int32_T b_nzColAlloc_tmp;
    int32_T col_tmp;
    int32_T nz;
    int32_T nzColAlloc_tmp;
    int32_T nzRhs;
    col_tmp = static_cast<int32_T>(varargin_2[cidx]);
    b_n = colidx[colidx.size(0) - 1] - 1;
    nz = colidx[colidx.size(0) - 1] - 1;
    nzColAlloc_tmp = colidx[col_tmp];
    b_nzColAlloc_tmp = colidx[col_tmp - 1];
    nzColAlloc = nzColAlloc_tmp - b_nzColAlloc_tmp;
    c_st.site = &ue_emlrtRSI;
    nzRhs = 0;
    d_st.site = &df_emlrtRSI;
    if ((1 <= sm) && (sm > 2147483646)) {
      e_st.site = &uc_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (k = 0; k < sm; k++) {
      if (!(rhs[(rhsIter.idx + k) - 1] == 0.0)) {
        nzRhs++;
      }
    }
    if (nzColAlloc < nzRhs) {
      int32_T extraCol;
      extraCol = nzRhs - nzColAlloc;
      nzColAlloc = (maxnz - colidx[colidx.size(0) - 1]) + 1;
      if (nzColAlloc < extraCol) {
        int32_T i;
        c_st.site = &ve_emlrtRSI;
        nzRhs = (maxnz + extraCol) - nzColAlloc;
        rowidxt.set_size(&vf_emlrtRTEI, &c_st, rowidx.size(0));
        k = rowidx.size(0);
        for (i = 0; i < k; i++) {
          rowidxt[i] = rowidx[i];
        }
        dt.set_size(&wf_emlrtRTEI, &c_st, d.size(0));
        k = d.size(0);
        for (i = 0; i < k; i++) {
          dt[i] = d[i];
        }
        internal::bigProduct(m, n, &k, &nzColAlloc);
        if (nzColAlloc == 0) {
          d_st.site = &ef_emlrtRSI;
          internal::bigProduct(m, n, &k, &nzColAlloc);
          if (nzColAlloc != 0) {
            emlrtErrorWithMessageIdR2018a(&d_st, &bb_emlrtRTEI,
                                          "Coder:toolbox:SparseNumelTooBig",
                                          "Coder:toolbox:SparseNumelTooBig", 0);
          }
          nzColAlloc = m * n;
          nzColAlloc = muIntScalarMin_sint32(nzRhs, nzColAlloc);
          nzColAlloc = muIntScalarMax_sint32(1, nzColAlloc);
        } else {
          nzColAlloc = muIntScalarMax_sint32(1, nzRhs);
        }
        rowidx.set_size(&xf_emlrtRTEI, &c_st, nzColAlloc);
        for (i = 0; i < nzColAlloc; i++) {
          rowidx[i] = 0;
        }
        d.set_size(&xf_emlrtRTEI, &c_st, nzColAlloc);
        for (i = 0; i < nzColAlloc; i++) {
          d[i] = 0.0;
        }
        maxnz = nzColAlloc;
        d_st.site = &ff_emlrtRSI;
        i = colidx[static_cast<int32_T>(varargin_2[cidx]) - 1] - 1;
        if ((1 <= i) && (i > 2147483646)) {
          e_st.site = &uc_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        for (k = 0; k <= b_nzColAlloc_tmp - 2; k++) {
          rowidx[k] = rowidxt[k];
          d[k] = dt[k];
        }
        d_st.site = &gf_emlrtRSI;
        if ((colidx[col_tmp] <= b_n) && (b_n > 2147483646)) {
          e_st.site = &uc_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        for (k = nzColAlloc_tmp; k <= nz; k++) {
          i = (k + extraCol) - 1;
          rowidx[i] = rowidxt[k - 1];
          d[i] = dt[k - 1];
        }
      } else {
        c_st.site = &we_emlrtRSI;
        nzColAlloc = (colidx[col_tmp] + extraCol) - 1;
        nzRhs = colidx[colidx.size(0) - 1] - colidx[col_tmp];
        if (nzRhs > 0) {
          d_st.site = &hf_emlrtRSI;
          std::memmove((void *)&rowidx[nzColAlloc],
                       (void *)&rowidx[nzColAlloc_tmp - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(int32_T)));
          d_st.site = &if_emlrtRSI;
          std::memmove((void *)&d[nzColAlloc], (void *)&d[nzColAlloc_tmp - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(real_T)));
        }
      }
      c_st.site = &xe_emlrtRSI;
      sparse::copyNonzeroValues(&c_st, this, &rhsIter, colidx[col_tmp - 1],
                                rhs);
      c_st.site = &ye_emlrtRSI;
      sparse::incrColIdx(&c_st, this, static_cast<int32_T>(varargin_2[cidx]),
                         extraCol);
    } else {
      c_st.site = &af_emlrtRSI;
      k = sparse::copyNonzeroValues(&c_st, this, &rhsIter, colidx[col_tmp - 1],
                                    rhs) -
          1;
      nzColAlloc -= nzRhs;
      if (nzColAlloc > 0) {
        c_st.site = &bf_emlrtRSI;
        nzRhs = (b_n - colidx[col_tmp]) + 1;
        if (nzRhs > 0) {
          d_st.site = &hf_emlrtRSI;
          std::memmove((void *)&rowidx[k], (void *)&rowidx[colidx[col_tmp] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(int32_T)));
          d_st.site = &if_emlrtRSI;
          std::memmove((void *)&d[k], (void *)&d[colidx[col_tmp] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(real_T)));
        }
        c_st.site = &cf_emlrtRSI;
        sparse::decrColIdx(&c_st, this, static_cast<int32_T>(varargin_2[cidx]),
                           nzColAlloc);
      }
    }
    rhsIter.col++;
    rhsIter.row = 1;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void sparse::parenAssign(const emlrtStack *sp,
                         const ::coder::array<real_T, 1U> &rhs,
                         const ::coder::array<real_T, 2U> &varargin_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T highOrderA;
  int32_T highOrderSize;
  int32_T nidx;
  int32_T partialResults_idx_1;
  int32_T tmp;
  int32_T v1;
  int32_T vk;
  boolean_T found;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &mf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  highOrderA = m >> 16;
  partialResults_idx_1 = m & 65535;
  v1 = n >> 16;
  nidx = n & 65535;
  vk = partialResults_idx_1 * nidx;
  tmp = partialResults_idx_1 * v1;
  partialResults_idx_1 = tmp << 16;
  highOrderSize = tmp >> 16;
  tmp = highOrderA * nidx;
  highOrderSize += tmp >> 16;
  highOrderSize += highOrderA * v1;
  if (vk > MAX_int32_T - partialResults_idx_1) {
    partialResults_idx_1 = (vk + partialResults_idx_1) - MAX_int32_T;
    highOrderSize++;
  } else {
    partialResults_idx_1 += vk;
  }
  if (partialResults_idx_1 > MAX_int32_T - (tmp << 16)) {
    highOrderSize++;
  }
  if (rhs.size(0) != varargin_1.size(1)) {
    emlrtErrorWithMessageIdR2018a(&st, &db_emlrtRTEI,
                                  "MATLAB:subsassignnumelmismatch",
                                  "MATLAB:subsassignnumelmismatch", 0);
  }
  b_st.site = &nf_emlrtRSI;
  if (highOrderSize == 0) {
    c_st.site = &of_emlrtRSI;
    sparse_validateNumericIndex(&c_st, m * n, varargin_1);
  } else {
    c_st.site = &pf_emlrtRSI;
    sparse_validateNumericIndex(&c_st, MAX_int32_T, varargin_1);
  }
  nidx = varargin_1.size(1);
  c_st.site = &qf_emlrtRSI;
  if ((1 <= varargin_1.size(1)) && (varargin_1.size(1) > 2147483646)) {
    d_st.site = &uc_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (tmp = 0; tmp < nidx; tmp++) {
    real_T thisv;
    partialResults_idx_1 = m;
    c_st.site = &rf_emlrtRSI;
    d_st.site = &tf_emlrtRSI;
    thisv = varargin_1[tmp];
    if (static_cast<int32_T>(thisv) > partialResults_idx_1 * n) {
      emlrtErrorWithMessageIdR2018a(&d_st, &eb_emlrtRTEI,
                                    "Coder:MATLAB:ind2sub_IndexOutOfRange",
                                    "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }
    e_st.site = &hh_emlrtRSI;
    vk = div_s32(&e_st, static_cast<int32_T>(thisv) - 1, partialResults_idx_1) +
         1;
    v1 = static_cast<int32_T>(thisv) - (vk - 1) * partialResults_idx_1;
    c_st.site = &sf_emlrtRSI;
    d_st.site = &uf_emlrtRSI;
    e_st.site = &vf_emlrtRSI;
    partialResults_idx_1 = m;
    if (v1 <= 0) {
      emlrtErrorWithMessageIdR2018a(&e_st, &u_emlrtRTEI,
                                    "Coder:MATLAB:badsubscript",
                                    "Coder:MATLAB:badsubscript", 0);
    }
    if (v1 > partialResults_idx_1) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &v_emlrtRTEI, "Coder:builtins:IndexOutOfBounds",
          "Coder:builtins:IndexOutOfBounds", 6, 6, static_cast<real_T>(v1), 12,
          1, 12, partialResults_idx_1);
    }
    e_st.site = &wf_emlrtRSI;
    partialResults_idx_1 = n;
    if (vk <= 0) {
      emlrtErrorWithMessageIdR2018a(&e_st, &u_emlrtRTEI,
                                    "Coder:MATLAB:badsubscript",
                                    "Coder:MATLAB:badsubscript", 0);
    }
    if (vk > partialResults_idx_1) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &v_emlrtRTEI, "Coder:builtins:IndexOutOfBounds",
          "Coder:builtins:IndexOutOfBounds", 6, 6, static_cast<real_T>(vk), 12,
          1, 12, partialResults_idx_1);
    }
    e_st.site = &xf_emlrtRSI;
    sparse_locBsearch(rowidx, v1, colidx[vk - 1], colidx[vk],
                      &partialResults_idx_1, &found);
    if (found) {
      thisv = d[partialResults_idx_1 - 1];
    } else {
      thisv = 0.0;
    }
    if ((!(thisv == 0.0)) || (!(rhs[tmp] == 0.0))) {
      if ((thisv != 0.0) && (rhs[tmp] != 0.0)) {
        d[partialResults_idx_1 - 1] = rhs[tmp];
      } else if (thisv == 0.0) {
        if (colidx[colidx.size(0) - 1] - 1 == maxnz) {
          f_st.site = &yf_emlrtRSI;
          sparse::b_realloc(&f_st, this, colidx[colidx.size(0) - 1] + 9,
                            partialResults_idx_1, partialResults_idx_1 + 1,
                            colidx[colidx.size(0) - 1] - 1);
          rowidx[partialResults_idx_1] = v1;
          d[partialResults_idx_1] = rhs[tmp];
        } else {
          highOrderA = (colidx[colidx.size(0) - 1] - partialResults_idx_1) - 1;
          if (highOrderA > 0) {
            std::memmove((void *)&rowidx[partialResults_idx_1 + 1],
                         (void *)&rowidx[partialResults_idx_1],
                         (uint32_T)((size_t)highOrderA * sizeof(int32_T)));
            std::memmove((void *)&d[partialResults_idx_1 + 1],
                         (void *)&d[partialResults_idx_1],
                         (uint32_T)((size_t)highOrderA * sizeof(real_T)));
          }
          d[partialResults_idx_1] = rhs[tmp];
          rowidx[partialResults_idx_1] = v1;
        }
        f_st.site = &bg_emlrtRSI;
        sparse::incrColIdx(&f_st, this, vk, 1);
      } else {
        highOrderA = (colidx[colidx.size(0) - 1] - partialResults_idx_1) - 1;
        if (highOrderA > 0) {
          std::memmove((void *)&rowidx[partialResults_idx_1 - 1],
                       (void *)&rowidx[partialResults_idx_1],
                       (uint32_T)((size_t)highOrderA * sizeof(int32_T)));
          std::memmove((void *)&d[partialResults_idx_1 - 1],
                       (void *)&d[partialResults_idx_1],
                       (uint32_T)((size_t)highOrderA * sizeof(real_T)));
        }
        f_st.site = &dg_emlrtRSI;
        sparse::decrColIdx(&f_st, this, vk, 1);
      }
    }
  }
}

void sparse::parenAssign(const emlrtStack *sp,
                         const ::coder::array<real_T, 2U> &rhs,
                         const ::coder::array<real_T, 2U> &varargin_1,
                         const ::coder::array<real_T, 2U> &varargin_2)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T rhsIter_idx;
  int32_T sm;
  int32_T sn;
  int32_T vidx;
  boolean_T found;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qe_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if ((rhs.size(0) != varargin_1.size(1)) ||
      (varargin_2.size(1) != rhs.size(1))) {
    emlrtErrorWithMessageIdR2018a(&st, &cb_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &uf_emlrtRSI;
  c_st.site = &vf_emlrtRSI;
  sparse_validateNumericIndex(&c_st, m, varargin_1);
  c_st.site = &wf_emlrtRSI;
  sparse_validateNumericIndex(&c_st, n, varargin_2);
  sm = varargin_1.size(1);
  sn = varargin_2.size(1);
  c_st.site = &xf_emlrtRSI;
  rhsIter_idx = 0;
  d_st.site = &ig_emlrtRSI;
  if ((1 <= varargin_2.size(1)) && (varargin_2.size(1) > 2147483646)) {
    e_st.site = &uc_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (int32_T cidx{0}; cidx < sn; cidx++) {
    real_T nt;
    nt = varargin_2[cidx];
    d_st.site = &jg_emlrtRSI;
    if ((1 <= sm) && (sm > 2147483646)) {
      e_st.site = &uc_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    for (int32_T ridx{0}; ridx < sm; ridx++) {
      real_T b_nt;
      real_T rhsv;
      real_T thisv;
      b_nt = varargin_1[ridx];
      sparse_locBsearch(rowidx, static_cast<int32_T>(b_nt),
                        colidx[static_cast<int32_T>(nt) - 1],
                        colidx[static_cast<int32_T>(nt)], &vidx, &found);
      if (found) {
        thisv = d[vidx - 1];
      } else {
        thisv = 0.0;
      }
      rhsv = rhs[rhsIter_idx + ridx];
      if ((!(thisv == 0.0)) || (!(rhsv == 0.0))) {
        if ((thisv != 0.0) && (rhsv != 0.0)) {
          d[vidx - 1] = rhsv;
        } else if (thisv == 0.0) {
          if (colidx[colidx.size(0) - 1] - 1 == maxnz) {
            d_st.site = &yf_emlrtRSI;
            sparse::b_realloc(&d_st, this, colidx[colidx.size(0) - 1] + 9, vidx,
                              vidx + 1, colidx[colidx.size(0) - 1] - 1);
            rowidx[vidx] = static_cast<int32_T>(b_nt);
            d[vidx] = rhsv;
          } else {
            int32_T nelem;
            d_st.site = &ag_emlrtRSI;
            nelem = (colidx[colidx.size(0) - 1] - vidx) - 1;
            if (nelem > 0) {
              std::memmove((void *)&rowidx[vidx + 1], (void *)&rowidx[vidx],
                           (uint32_T)((size_t)nelem * sizeof(int32_T)));
              std::memmove((void *)&d[vidx + 1], (void *)&d[vidx],
                           (uint32_T)((size_t)nelem * sizeof(real_T)));
            }
            d[vidx] = rhsv;
            rowidx[vidx] = static_cast<int32_T>(b_nt);
          }
          d_st.site = &bg_emlrtRSI;
          sparse::incrColIdx(&d_st, this, static_cast<int32_T>(nt), 1);
        } else {
          int32_T nelem;
          d_st.site = &cg_emlrtRSI;
          nelem = (colidx[colidx.size(0) - 1] - vidx) - 1;
          if (nelem > 0) {
            std::memmove((void *)&rowidx[vidx - 1], (void *)&rowidx[vidx],
                         (uint32_T)((size_t)nelem * sizeof(int32_T)));
            std::memmove((void *)&d[vidx - 1], (void *)&d[vidx],
                         (uint32_T)((size_t)nelem * sizeof(real_T)));
          }
          d_st.site = &dg_emlrtRSI;
          sparse::decrColIdx(&d_st, this, static_cast<int32_T>(nt), 1);
        }
      }
    }
    rhsIter_idx += sm;
  }
}

} // namespace coder

// End of code generation (sparse1.cpp)
