//
// One_tech_ss.cpp
//
// Code generation for function 'One_tech_ss'
//

// Include files
#include "One_tech_ss.h"
#include "One_tech_ss_data.h"
#include "One_tech_ss_mexutil.h"
#include "abs.h"
#include "applyToMultipleDims.h"
#include "assertValidSizeArg.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "eml_mtimes_helper.h"
#include "expcdf.h"
#include "expinv.h"
#include "indexShapeCheck.h"
#include "ixfun.h"
#include "kron.h"
#include "linspace.h"
#include "mpower.h"
#include "mtimes.h"
#include "power.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "sparse1.h"
#include "sum.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <stdio.h>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    6,                              // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    7,                              // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    13,                             // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    17,                             // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    35,                             // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    66,                             // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    69,                             // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    92,                             // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    93,                             // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    102,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    105,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    113,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    115,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    116,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    121,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    125,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    143,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    144,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    145,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    146,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    147,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    148,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    162,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    150,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    161,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    170,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    171,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    172,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    174,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    181,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    183,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    188,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    195,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    197,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    207,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    15,    // lineNo
    "max", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" // pathName
};

static emlrtRSInfo
    dc_emlrtRSI{
        29,         // lineNo
        "minOrMax", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo
    ec_emlrtRSI{
        58,         // lineNo
        "maximum2", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo fc_emlrtRSI{
    63,               // lineNo
    "binaryMinOrMax", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\binaryMinOrMax.m" // pathName
};

static emlrtRSInfo gc_emlrtRSI{
    57,      // lineNo
    "ixfun", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    102,                          // lineNo
    "binaryImplicitExpansionFun", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" // pathName
};

static emlrtRSInfo ic_emlrtRSI{
    29,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo jc_emlrtRSI{
    109,               // lineNo
    "computeDimsData", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo
    oc_emlrtRSI{
        90,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

static emlrtRSInfo
    pc_emlrtRSI{
        69,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

static emlrtRSInfo
    uc_emlrtRSI{
        44,         // lineNo
        "minOrMax", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo
    vc_emlrtRSI{
        79,        // lineNo
        "maximum", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo wc_emlrtRSI{
    62,              // lineNo
    "unaryMinOrMax", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    38,        // lineNo
    "fprintf", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo
    hf_emlrtRSI{
        28,      // lineNo
        "colon", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pathName
    };

static emlrtRSInfo
    if_emlrtRSI{
        117,     // lineNo
        "colon", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pathName
    };

static emlrtMCInfo emlrtMCI{
    66,        // lineNo
    18,        // colNo
    "fprintf", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    8,                               // lineNo
    18,                              // colNo
    "a_cdf",                         // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo emlrtDCI{
    8,                               // lineNo
    20,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    8,                               // lineNo
    20,                              // colNo
    "a_cdf",                         // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo emlrtECI{
    2,                              // nDims
    8,                              // lineNo
    11,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtDCInfo b_emlrtDCI{
    21,                              // lineNo
    18,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtRTEInfo emlrtRTEI{
    64,                             // lineNo
    7,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    65,                             // lineNo
    11,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    77,                             // lineNo
    15,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtBCInfo c_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    80,                              // lineNo
    41,                              // colNo
    "v_p",                           // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    80,                              // lineNo
    43,                              // colNo
    "v_p",                           // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    80,                              // lineNo
    19,                              // colNo
    "v_p",                           // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    80,                              // lineNo
    21,                              // colNo
    "v_p",                           // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo b_emlrtECI{
    -1,                             // nDims
    80,                             // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtBCInfo g_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    81,                              // lineNo
    19,                              // colNo
    "v_p",                           // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    93,                              // lineNo
    56,                              // colNo
    "v",                             // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo c_emlrtECI{
    1,                              // nDims
    108,                            // lineNo
    32,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo d_emlrtECI{
    1,                              // nDims
    113,                            // lineNo
    31,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo e_emlrtECI{
    2,                              // nDims
    113,                            // lineNo
    31,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo f_emlrtECI{
    1,                              // nDims
    117,                            // lineNo
    27,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo g_emlrtECI{
    2,                              // nDims
    117,                            // lineNo
    27,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo h_emlrtECI{
    1,                              // nDims
    121,                            // lineNo
    35,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo i_emlrtECI{
    2,                              // nDims
    121,                            // lineNo
    35,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtBCInfo i_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    141,                             // lineNo
    50,                              // colNo
    "exit_vec",                      // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    141,                             // lineNo
    52,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    141,                             // lineNo
    52,                              // colNo
    "exit_vec",                      // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    141,                             // lineNo
    72,                              // colNo
    "exit_vec",                      // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo j_emlrtECI{
    1,                              // nDims
    144,                            // lineNo
    41,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo k_emlrtECI{
    2,                              // nDims
    144,                            // lineNo
    41,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo l_emlrtECI{
    1,                              // nDims
    145,                            // lineNo
    45,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo m_emlrtECI{
    2,                              // nDims
    145,                            // lineNo
    45,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo n_emlrtECI{
    2,                              // nDims
    146,                            // lineNo
    42,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtDCInfo d_emlrtDCI{
    148,                             // lineNo
    46,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    148,                             // lineNo
    46,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    148,                             // lineNo
    83,                              // colNo
    "prob_of_naot",                  // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    148,                             // lineNo
    85,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    148,                             // lineNo
    85,                              // colNo
    "prob_of_naot",                  // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo o_emlrtECI{
    1,                              // nDims
    148,                            // lineNo
    41,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtDCInfo g_emlrtDCI{
    149,                             // lineNo
    47,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtECInfo p_emlrtECI{
    1,                              // nDims
    149,                            // lineNo
    42,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo q_emlrtECI{
    1,                              // nDims
    150,                            // lineNo
    41,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtDCInfo h_emlrtDCI{
    162,                             // lineNo
    55,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    162,                             // lineNo
    55,                              // colNo
    "exit_vec",                      // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo i_emlrtDCI{
    162,                             // lineNo
    77,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    162,                             // lineNo
    77,                              // colNo
    "exit_vec",                      // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    162,                             // lineNo
    95,                              // colNo
    "exit_vec",                      // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo r_emlrtECI{
    1,                              // nDims
    162,                            // lineNo
    17,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    169,                            // lineNo
    15,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtBCInfo q_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    166,                             // lineNo
    18,                              // colNo
    "dist_ent",                      // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    166,                             // lineNo
    20,                              // colNo
    "dist_ent",                      // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo s_emlrtECI{
    2,                              // nDims
    171,                            // lineNo
    27,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtECInfo t_emlrtECI{
    2,                              // nDims
    172,                            // lineNo
    35,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtBCInfo s_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    195,                             // lineNo
    38,                              // colNo
    "v_new_resh",                    // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtRTEInfo e_emlrtRTEI{
    52,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    59,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

static emlrtDCInfo j_emlrtDCI{
    18,                              // lineNo
    27,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo k_emlrtDCI{
    18,                              // lineNo
    27,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtDCInfo l_emlrtDCI{
    20,                              // lineNo
    25,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo m_emlrtDCI{
    20,                              // lineNo
    25,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtDCInfo n_emlrtDCI{
    20,                              // lineNo
    33,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo o_emlrtDCI{
    20,                              // lineNo
    33,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtDCInfo p_emlrtDCI{
    24,                              // lineNo
    25,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo q_emlrtDCI{
    164,                             // lineNo
    41,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo r_emlrtDCI{
    165,                             // lineNo
    31,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo s_emlrtDCI{
    18,                              // lineNo
    1,                               // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo t_emlrtDCI{
    19,                              // lineNo
    1,                               // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo u_emlrtDCI{
    20,                              // lineNo
    1,                               // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo v_emlrtDCI{
    24,                              // lineNo
    1,                               // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    48,                              // lineNo
    1,                               // colNo
    "pi_contemp",                    // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    75,                              // lineNo
    9,                               // colNo
    "pi_contemp",                    // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo w_emlrtDCI{
    147,                             // lineNo
    49,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo x_emlrtDCI{
    147,                             // lineNo
    49,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    119,                             // lineNo
    13,                              // colNo
    "v_new_resh",                    // aName
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo y_emlrtDCI{
    164,                             // lineNo
    34,                              // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo ab_emlrtDCI{
    165,                             // lineNo
    9,                               // colNo
    "One_tech_ss",                   // fName
    "D:\\AMR_github\\One_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtRTEInfo db_emlrtRTEI{
    8,                              // lineNo
    11,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    8,                              // lineNo
    1,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
    13,                             // lineNo
    1,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    18,                             // lineNo
    1,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    19,                             // lineNo
    1,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    20,                             // lineNo
    1,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    21,                             // lineNo
    1,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    24,                             // lineNo
    1,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo lb_emlrtRTEI{
    35,                             // lineNo
    20,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    3,                              // lineNo
    5,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo nb_emlrtRTEI{
    55,                             // lineNo
    1,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    66,                             // lineNo
    28,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    69,                             // lineNo
    29,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    69,                             // lineNo
    9,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo rb_emlrtRTEI{
    74,                             // lineNo
    9,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo sb_emlrtRTEI{
    79,                             // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo tb_emlrtRTEI{
    80,                             // lineNo
    35,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ub_emlrtRTEI{
    92,                             // lineNo
    40,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo vb_emlrtRTEI{
    93,                             // lineNo
    32,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo wb_emlrtRTEI{
    93,                             // lineNo
    54,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo xb_emlrtRTEI{
    94,                             // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo yb_emlrtRTEI{
    102,                            // lineNo
    31,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ac_emlrtRTEI{
    102,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    105,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    108,                            // lineNo
    29,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    108,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    111,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo fc_emlrtRTEI{
    112,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo gc_emlrtRTEI{
    113,                            // lineNo
    38,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    113,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ic_emlrtRTEI{
    117,                            // lineNo
    40,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo jc_emlrtRTEI{
    117,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo kc_emlrtRTEI{
    121,                            // lineNo
    35,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo lc_emlrtRTEI{
    129,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo mc_emlrtRTEI{
    144,                            // lineNo
    41,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo
    nc_emlrtRTEI{
        28,      // lineNo
        9,       // colNo
        "colon", // fName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pName
    };

static emlrtRTEInfo oc_emlrtRTEI{
    145,                            // lineNo
    45,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo pc_emlrtRTEI{
    146,                            // lineNo
    61,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo qc_emlrtRTEI{
    146,                            // lineNo
    42,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo rc_emlrtRTEI{
    147,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo sc_emlrtRTEI{
    147,                            // lineNo
    42,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo tc_emlrtRTEI{
    147,                            // lineNo
    37,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo uc_emlrtRTEI{
    148,                            // lineNo
    9,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo vc_emlrtRTEI{
    149,                            // lineNo
    9,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo wc_emlrtRTEI{
    162,                            // lineNo
    44,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo xc_emlrtRTEI{
    162,                            // lineNo
    17,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo yc_emlrtRTEI{
    164,                            // lineNo
    34,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ad_emlrtRTEI{
    164,                            // lineNo
    9,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo bd_emlrtRTEI{
    165,                            // lineNo
    9,                              // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo cd_emlrtRTEI{
    171,                            // lineNo
    38,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo dd_emlrtRTEI{
    171,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ed_emlrtRTEI{
    172,                            // lineNo
    35,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo fd_emlrtRTEI{
    177,                            // lineNo
    13,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo gd_emlrtRTEI{
    195,                            // lineNo
    27,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ee_emlrtRTEI{
    171,                            // lineNo
    27,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo fe_emlrtRTEI{
    150,                            // lineNo
    41,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo ge_emlrtRTEI{
    148,                            // lineNo
    41,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRTEInfo he_emlrtRTEI{
    117,                            // lineNo
    27,                             // colNo
    "One_tech_ss",                  // fName
    "D:\\AMR_github\\One_tech_ss.m" // pName
};

static emlrtRSInfo bg_emlrtRSI{
    66,        // lineNo
    "fprintf", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo cg_emlrtRSI{
    68,        // lineNo
    "fprintf", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo dg_emlrtRSI{
    149,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo eg_emlrtRSI{
    117,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo fg_emlrtRSI{
    108,                            // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

static emlrtRSInfo gg_emlrtRSI{
    8,                              // lineNo
    "One_tech_ss",                  // fcnName
    "D:\\AMR_github\\One_tech_ss.m" // pathName
};

// Function Declarations
static void b_binary_expand_op(const emlrtStack *sp,
                               coder::array<real_T, 1U> &stay_alive_besideold,
                               real_T age_num, real_T a_num_g,
                               const coder::array<boolean_T, 2U> &exit_vec,
                               int32_T i1);

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[43]);

static void b_plus(const emlrtStack *sp, coder::array<real_T, 2U> &v_new_resh,
                   const coder::array<real_T, 2U> &pi_contemp);

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 2U> &a_cdf,
                             emlrtRSInfo ig_emlrtRSI,
                             const coder::array<real_T, 2U> &dist_new,
                             const coder::array<real_T, 2U> &dist);

static void binary_expand_op(const emlrtStack *sp, emlrtRSInfo ig_emlrtRSI,
                             coder::sparse *trans_matrix,
                             const coder::array<real_T, 2U> &v_adopt_p,
                             const coder::array<real_T, 1U> &v_p_expand,
                             const coder::array<real_T, 2U> &dist_ent,
                             const coder::array<real_T, 2U> &a_cdf);

static void
binary_expand_op(const emlrtStack *sp, emlrtRSInfo ig_emlrtRSI,
                 coder::sparse *trans_matrix,
                 const coder::array<real_T, 1U> &v_p_expand,
                 const coder::array<real_T, 1U> &stay_alive_besideold,
                 const coder::array<real_T, 2U> &dist_new,
                 const coder::array<real_T, 2U> &a_cdf);

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 1U> &v_p_expand,
                             real_T age_num, real_T a_num_g, int32_T i1);

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 1U> &v_p_expand,
                             emlrtRSInfo ig_emlrtRSI,
                             const coder::array<real_T, 2U> &v_p,
                             const coder::array<real_T, 2U> &v_adopt_p);

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 2U> &v_p,
                             const coder::array<real_T, 2U> &v_adopt);

static void c_binary_expand_op(const emlrtStack *sp, emlrtRSInfo ig_emlrtRSI,
                               coder::sparse *trans_matrix,
                               const coder::array<real_T, 2U> &v_adopt_p,
                               const coder::array<boolean_T, 2U> &exit_vec,
                               const coder::array<real_T, 2U> &dist_ent);

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[41]);

static void d_binary_expand_op(const emlrtStack *sp,
                               coder::array<real_T, 2U> &v_adopt,
                               emlrtRSInfo ig_emlrtRSI,
                               const coder::array<real_T, 2U> &v,
                               const coder::array<real_T, 2U> &v_new_resh);

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[77]);

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[67]);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const char_T u[7]);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, emlrtMCInfo *location);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            emlrtMCInfo *location);

static void minus(const emlrtStack *sp, coder::array<real_T, 2U> &a_prob,
                  const coder::array<real_T, 2U> &a_cdf);

static void plus(const emlrtStack *sp, coder::array<real_T, 2U> &dist_new,
                 const coder::array<real_T, 2U> &a_cdf);

static void times(const emlrtStack *sp, coder::array<real_T, 2U> &v_adopt_p,
                  const coder::array<real_T, 2U> &v_p);

// Function Definitions
static void b_binary_expand_op(const emlrtStack *sp,
                               coder::array<real_T, 1U> &stay_alive_besideold,
                               real_T age_num, real_T a_num_g,
                               const coder::array<boolean_T, 2U> &exit_vec,
                               int32_T i1)
{
  int32_T age_num_idx_0;
  int32_T i;
  int32_T stride_1_0;
  age_num_idx_0 = static_cast<int32_T>((age_num - 1.0) * a_num_g);
  if (i1 + 1 == 1) {
    i = age_num_idx_0;
  } else {
    i = i1 + 1;
  }
  stay_alive_besideold.set_size(&vc_emlrtRTEI, sp, i);
  stride_1_0 = (i1 + 1 != 1);
  if (i1 + 1 != 1) {
    age_num_idx_0 = i1 + 1;
  }
  for (i = 0; i < age_num_idx_0; i++) {
    stay_alive_besideold[i] =
        1.0 - static_cast<real_T>(exit_vec[i * stride_1_0]);
  }
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[43])
{
  static const int32_T iv[2]{1, 43};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 43, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void b_plus(const emlrtStack *sp, coder::array<real_T, 2U> &v_new_resh,
                   const coder::array<real_T, 2U> &pi_contemp)
{
  coder::array<real_T, 2U> b_pi_contemp;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (v_new_resh.size(0) == 1) {
    i = pi_contemp.size(0);
  } else {
    i = v_new_resh.size(0);
  }
  if (v_new_resh.size(1) == 1) {
    i1 = pi_contemp.size(1);
  } else {
    i1 = v_new_resh.size(1);
  }
  b_pi_contemp.set_size(&he_emlrtRTEI, sp, i, i1);
  stride_0_0 = (pi_contemp.size(0) != 1);
  stride_0_1 = (pi_contemp.size(1) != 1);
  stride_1_0 = (v_new_resh.size(0) != 1);
  stride_1_1 = (v_new_resh.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (v_new_resh.size(1) == 1) {
    loop_ub = pi_contemp.size(1);
  } else {
    loop_ub = v_new_resh.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    if (v_new_resh.size(0) == 1) {
      b_loop_ub = pi_contemp.size(0);
    } else {
      b_loop_ub = v_new_resh.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_pi_contemp[i1 + b_pi_contemp.size(0) * i] =
          pi_contemp[i1 * stride_0_0 + pi_contemp.size(0) * aux_0_1] +
          v_new_resh[i1 * stride_1_0 + v_new_resh.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  v_new_resh.set_size(&he_emlrtRTEI, sp, b_pi_contemp.size(0),
                      b_pi_contemp.size(1));
  loop_ub = b_pi_contemp.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_pi_contemp.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      v_new_resh[i1 + v_new_resh.size(0) * i] =
          b_pi_contemp[i1 + b_pi_contemp.size(0) * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 2U> &a_cdf,
                             emlrtRSInfo ig_emlrtRSI,
                             const coder::array<real_T, 2U> &dist_new,
                             const coder::array<real_T, 2U> &dist)
{
  coder::array<real_T, 2U> b_dist_new;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (dist.size(1) == 1) {
    i = dist_new.size(1);
  } else {
    i = dist.size(1);
  }
  b_dist_new.set_size(&ed_emlrtRTEI, sp, 1, i);
  stride_0_1 = (dist_new.size(1) != 1);
  stride_1_1 = (dist.size(1) != 1);
  if (dist.size(1) == 1) {
    loop_ub = dist_new.size(1);
  } else {
    loop_ub = dist.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_dist_new[i] = dist_new[i * stride_0_1] - dist[i * stride_1_1];
  }
  st.site = &ig_emlrtRSI;
  coder::c_abs(&st, b_dist_new, a_cdf);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, emlrtRSInfo ig_emlrtRSI,
                             coder::sparse *trans_matrix,
                             const coder::array<real_T, 2U> &v_adopt_p,
                             const coder::array<real_T, 1U> &v_p_expand,
                             const coder::array<real_T, 2U> &dist_ent,
                             const coder::array<real_T, 2U> &a_cdf)
{
  coder::array<real_T, 2U> b_v_adopt_p;
  emlrtStack st;
  int32_T b_v_p_expand_idx_0;
  int32_T loop_ub;
  int32_T stride_1_0;
  int32_T v_p_expand_idx_0;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  v_p_expand_idx_0 = v_p_expand.size(0);
  if (v_p_expand_idx_0 == 1) {
    b_v_p_expand_idx_0 = v_adopt_p.size(0);
  } else {
    b_v_p_expand_idx_0 = v_p_expand_idx_0;
  }
  b_v_adopt_p.set_size(&xc_emlrtRTEI, sp, b_v_p_expand_idx_0,
                       v_adopt_p.size(1));
  b_v_p_expand_idx_0 = (v_adopt_p.size(0) != 1);
  stride_1_0 = (v_p_expand_idx_0 != 1);
  loop_ub = v_adopt_p.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    int32_T b_loop_ub;
    if (v_p_expand_idx_0 == 1) {
      b_loop_ub = v_adopt_p.size(0);
    } else {
      b_loop_ub = v_p_expand_idx_0;
    }
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      b_v_adopt_p[i1 + b_v_adopt_p.size(0) * i] =
          v_adopt_p[i1 * b_v_p_expand_idx_0 + v_adopt_p.size(0) * i] *
          (1.0 - v_p_expand[i1 * stride_1_0]);
    }
  }
  st.site = &ig_emlrtRSI;
  trans_matrix->parenAssign(&st, b_v_adopt_p, dist_ent, a_cdf);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void
binary_expand_op(const emlrtStack *sp, emlrtRSInfo ig_emlrtRSI,
                 coder::sparse *trans_matrix,
                 const coder::array<real_T, 1U> &v_p_expand,
                 const coder::array<real_T, 1U> &stay_alive_besideold,
                 const coder::array<real_T, 2U> &dist_new,
                 const coder::array<real_T, 2U> &a_cdf)
{
  coder::array<real_T, 2U> b_dist_new;
  coder::array<real_T, 1U> b_v_p_expand;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (stay_alive_besideold.size(0) == 1) {
    i = v_p_expand.size(0);
  } else {
    i = stay_alive_besideold.size(0);
  }
  b_v_p_expand.set_size(&fe_emlrtRTEI, sp, i);
  stride_0_0 = (v_p_expand.size(0) != 1);
  stride_1_0 = (stay_alive_besideold.size(0) != 1);
  if (stay_alive_besideold.size(0) == 1) {
    loop_ub = v_p_expand.size(0);
  } else {
    loop_ub = stay_alive_besideold.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_v_p_expand[i] =
        v_p_expand[i * stride_0_0] * stay_alive_besideold[i * stride_1_0];
  }
  if (a_cdf.size(1) == 1) {
    i = dist_new.size(1);
  } else {
    i = a_cdf.size(1);
  }
  b_dist_new.set_size(&qc_emlrtRTEI, sp, 1, i);
  stride_0_0 = (dist_new.size(1) != 1);
  stride_1_0 = (a_cdf.size(1) != 1);
  if (a_cdf.size(1) == 1) {
    loop_ub = dist_new.size(1);
  } else {
    loop_ub = a_cdf.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_dist_new[i] = dist_new[i * stride_0_0] + a_cdf[i * stride_1_0];
  }
  st.site = &ig_emlrtRSI;
  trans_matrix->parenAssign(&st, b_v_p_expand, b_dist_new);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 1U> &v_p_expand,
                             real_T age_num, real_T a_num_g, int32_T i1)
{
  coder::array<real_T, 1U> r;
  int32_T age_num_idx_0;
  int32_T i;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  age_num_idx_0 = static_cast<int32_T>((age_num - 1.0) * a_num_g);
  if (i1 + 1 == 1) {
    i = age_num_idx_0;
  } else {
    i = i1 + 1;
  }
  r.set_size(&ge_emlrtRTEI, sp, i);
  stride_1_0 = (i1 + 1 != 1);
  if (i1 + 1 != 1) {
    age_num_idx_0 = i1 + 1;
  }
  for (i = 0; i < age_num_idx_0; i++) {
    r[i] = v_p_expand[i * stride_1_0];
  }
  v_p_expand.set_size(&ge_emlrtRTEI, sp, r.size(0));
  age_num_idx_0 = r.size(0);
  for (i = 0; i < age_num_idx_0; i++) {
    v_p_expand[i] = r[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 1U> &v_p_expand,
                             emlrtRSInfo ig_emlrtRSI,
                             const coder::array<real_T, 2U> &v_p,
                             const coder::array<real_T, 2U> &v_adopt_p)
{
  coder::array<real_T, 2U> r;
  emlrtStack st;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (v_adopt_p.size(0) == 1) {
    i = v_p.size(0);
  } else {
    i = v_adopt_p.size(0);
  }
  if (v_adopt_p.size(1) == 1) {
    i1 = v_p.size(1);
  } else {
    i1 = v_adopt_p.size(1);
  }
  r.set_size(&oc_emlrtRTEI, sp, i, i1);
  stride_0_0 = (v_p.size(0) != 1);
  stride_0_1 = (v_p.size(1) != 1);
  stride_1_0 = (v_adopt_p.size(0) != 1);
  stride_1_1 = (v_adopt_p.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (v_adopt_p.size(1) == 1) {
    loop_ub = v_p.size(1);
  } else {
    loop_ub = v_adopt_p.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    if (v_adopt_p.size(0) == 1) {
      b_loop_ub = v_p.size(0);
    } else {
      b_loop_ub = v_adopt_p.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      r[i1 + r.size(0) * i] =
          (1.0 - v_p[i1 * stride_0_0 + v_p.size(0) * aux_0_1]) *
          v_adopt_p[i1 * stride_1_0 + v_adopt_p.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = &ig_emlrtRSI;
  coder::sum(&st, r, v_p_expand);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 2U> &v_p,
                             const coder::array<real_T, 2U> &v_adopt)
{
  coder::array<real_T, 2U> r;
  int32_T b_loop_ub;
  int32_T b_v_p_idx_0;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_1_0;
  int32_T v_p_idx_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  v_p_idx_0 = v_p.size(0) * v_p.size(1);
  if (v_p_idx_0 == 1) {
    b_v_p_idx_0 = v_adopt.size(0);
  } else {
    b_v_p_idx_0 = v_p_idx_0;
  }
  r.set_size(&cc_emlrtRTEI, sp, b_v_p_idx_0, v_adopt.size(1));
  b_v_p_idx_0 = (v_adopt.size(0) != 1);
  stride_1_0 = (v_p_idx_0 != 1);
  loop_ub = v_adopt.size(1);
  for (i = 0; i < loop_ub; i++) {
    if (v_p_idx_0 == 1) {
      b_loop_ub = v_adopt.size(0);
    } else {
      b_loop_ub = v_p_idx_0;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      r[i1 + r.size(0) * i] =
          1.0 -
          static_cast<real_T>(v_adopt[i1 * b_v_p_idx_0 + v_adopt.size(0) * i] ==
                              v_p[i1 * stride_1_0]);
    }
  }
  v_p.set_size(&cc_emlrtRTEI, sp, r.size(0), r.size(1));
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = r.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      v_p[i1 + v_p.size(0) * i] = r[i1 + r.size(0) * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void c_binary_expand_op(const emlrtStack *sp, emlrtRSInfo ig_emlrtRSI,
                               coder::sparse *trans_matrix,
                               const coder::array<real_T, 2U> &v_adopt_p,
                               const coder::array<boolean_T, 2U> &exit_vec,
                               const coder::array<real_T, 2U> &dist_ent)
{
  coder::array<real_T, 2U> b_v_adopt_p;
  emlrtStack st;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (exit_vec.size(0) == 1) {
    i = v_adopt_p.size(0);
  } else {
    i = exit_vec.size(0);
  }
  if (exit_vec.size(1) == 1) {
    i1 = v_adopt_p.size(1);
  } else {
    i1 = exit_vec.size(1);
  }
  b_v_adopt_p.set_size(&mc_emlrtRTEI, sp, i, i1);
  stride_0_0 = (v_adopt_p.size(0) != 1);
  stride_0_1 = (v_adopt_p.size(1) != 1);
  stride_1_0 = (exit_vec.size(0) != 1);
  stride_1_1 = (exit_vec.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (exit_vec.size(1) == 1) {
    loop_ub = v_adopt_p.size(1);
  } else {
    loop_ub = exit_vec.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    if (exit_vec.size(0) == 1) {
      b_loop_ub = v_adopt_p.size(0);
    } else {
      b_loop_ub = exit_vec.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_v_adopt_p[i1 + b_v_adopt_p.size(0) * i] =
          v_adopt_p[i1 * stride_0_0 + v_adopt_p.size(0) * aux_0_1] *
          (1.0 - static_cast<real_T>(
                     exit_vec[i1 * stride_1_0 + exit_vec.size(0) * aux_1_1]));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = &ig_emlrtRSI;
  trans_matrix->parenAssign(&st, b_v_adopt_p, dist_ent);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[41])
{
  static const int32_T iv[2]{1, 41};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 41, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void d_binary_expand_op(const emlrtStack *sp,
                               coder::array<real_T, 2U> &v_adopt,
                               emlrtRSInfo ig_emlrtRSI,
                               const coder::array<real_T, 2U> &v,
                               const coder::array<real_T, 2U> &v_new_resh)
{
  coder::array<real_T, 2U> b_v;
  emlrtStack st;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (v_new_resh.size(0) == 1) {
    i = v.size(0);
  } else {
    i = v_new_resh.size(0);
  }
  if (v_new_resh.size(1) == 1) {
    i1 = v.size(1);
  } else {
    i1 = v_new_resh.size(1);
  }
  b_v.set_size(&kc_emlrtRTEI, sp, i, i1);
  stride_0_0 = (v.size(0) != 1);
  stride_0_1 = (v.size(1) != 1);
  stride_1_0 = (v_new_resh.size(0) != 1);
  stride_1_1 = (v_new_resh.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (v_new_resh.size(1) == 1) {
    loop_ub = v.size(1);
  } else {
    loop_ub = v_new_resh.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    if (v_new_resh.size(0) == 1) {
      b_loop_ub = v.size(0);
    } else {
      b_loop_ub = v_new_resh.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_v[i1 + b_v.size(0) * i] =
          v[i1 * stride_0_0 + v.size(0) * aux_0_1] -
          v_new_resh[i1 * stride_1_0 + v_new_resh.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = &ig_emlrtRSI;
  coder::b_abs(&st, b_v, v_adopt);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[77])
{
  static const int32_T iv[2]{1, 77};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 77, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[67])
{
  static const int32_T iv[2]{1, 67};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 67, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[7])
{
  static const int32_T iv[2]{1, 7};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  pArrays[3] = m4;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 4, &pArrays[0],
                               (const char_T *)"feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            emlrtMCInfo *location)
{
  const mxArray *pArrays[5];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  pArrays[3] = m4;
  pArrays[4] = m5;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 5, &pArrays[0],
                               (const char_T *)"feval", true, location);
}

static void minus(const emlrtStack *sp, coder::array<real_T, 2U> &a_prob,
                  const coder::array<real_T, 2U> &a_cdf)
{
  coder::array<real_T, 2U> b_a_prob;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (a_cdf.size(1) == 1) {
    i = a_prob.size(1);
  } else {
    i = a_cdf.size(1);
  }
  b_a_prob.set_size(&db_emlrtRTEI, sp, 1, i);
  stride_0_1 = (a_prob.size(1) != 1);
  stride_1_1 = (a_cdf.size(1) != 1);
  if (a_cdf.size(1) == 1) {
    loop_ub = a_prob.size(1);
  } else {
    loop_ub = a_cdf.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_a_prob[i] = a_prob[i * stride_0_1] - a_cdf[i * stride_1_1];
  }
  a_prob.set_size(&db_emlrtRTEI, sp, 1, b_a_prob.size(1));
  loop_ub = b_a_prob.size(1);
  for (i = 0; i < loop_ub; i++) {
    a_prob[i] = b_a_prob[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void plus(const emlrtStack *sp, coder::array<real_T, 2U> &dist_new,
                 const coder::array<real_T, 2U> &a_cdf)
{
  coder::array<real_T, 2U> b_dist_new;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (a_cdf.size(1) == 1) {
    i = dist_new.size(1);
  } else {
    i = a_cdf.size(1);
  }
  b_dist_new.set_size(&ee_emlrtRTEI, sp, 1, i);
  stride_0_1 = (dist_new.size(1) != 1);
  stride_1_1 = (a_cdf.size(1) != 1);
  if (a_cdf.size(1) == 1) {
    loop_ub = dist_new.size(1);
  } else {
    loop_ub = a_cdf.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_dist_new[i] = dist_new[i * stride_0_1] + a_cdf[i * stride_1_1];
  }
  dist_new.set_size(&ee_emlrtRTEI, sp, 1, b_dist_new.size(1));
  loop_ub = b_dist_new.size(1);
  for (i = 0; i < loop_ub; i++) {
    dist_new[i] = b_dist_new[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void times(const emlrtStack *sp, coder::array<real_T, 2U> &v_adopt_p,
                  const coder::array<real_T, 2U> &v_p)
{
  coder::array<real_T, 2U> b_v_p;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (v_adopt_p.size(0) == 1) {
    i = v_p.size(0);
  } else {
    i = v_adopt_p.size(0);
  }
  if (v_adopt_p.size(1) == 1) {
    i1 = v_p.size(1);
  } else {
    i1 = v_adopt_p.size(1);
  }
  b_v_p.set_size(&mc_emlrtRTEI, sp, i, i1);
  stride_0_0 = (v_p.size(0) != 1);
  stride_0_1 = (v_p.size(1) != 1);
  stride_1_0 = (v_adopt_p.size(0) != 1);
  stride_1_1 = (v_adopt_p.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (v_adopt_p.size(1) == 1) {
    loop_ub = v_p.size(1);
  } else {
    loop_ub = v_adopt_p.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    if (v_adopt_p.size(0) == 1) {
      b_loop_ub = v_p.size(0);
    } else {
      b_loop_ub = v_adopt_p.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_v_p[i1 + b_v_p.size(0) * i] =
          v_p[i1 * stride_0_0 + v_p.size(0) * aux_0_1] *
          v_adopt_p[i1 * stride_1_0 + v_adopt_p.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  v_adopt_p.set_size(&mc_emlrtRTEI, sp, b_v_p.size(0), b_v_p.size(1));
  loop_ub = b_v_p.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_v_p.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      v_adopt_p[i1 + v_adopt_p.size(0) * i] = b_v_p[i1 + b_v_p.size(0) * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void One_tech_ss(
    const emlrtStack *sp, real_T a_grow, real_T alpha, real_T, real_T beta,
    real_T c_of_a, real_T a_lamb, real_T p_e, real_T a_num_g, real_T age_num,
    real_T max_iter, real_T v_tol, real_T dist_tol, real_T fco, real_T e_p,
    real_T d_0, real_T c_of_e, real_T dem_tol,
    coder::array<real_T, 1U> &trans_prob, coder::array<real_T, 1U> &v_new,
    coder::array<real_T, 2U> &v_new_resh, coder::array<real_T, 2U> &dist,
    coder::sparse *trans_matrix, coder::array<real_T, 1U> &age_g,
    coder::array<real_T, 2U> &a_grid, coder::array<real_T, 2U> &a_prob,
    coder::array<real_T, 2U> &pi_contemp, real_T *p_E, real_T *m_of_firms)
{
  static const char_T cv2[77]{
      'd', 'e', 'm', 'a', 'n', 'd', ' ', 'a', 'n', 'd', ' ',  's', 'u',
      'p', 'p', 'l', 'y', ' ', 'h', 'a', 's', ' ', 'c', 'o',  'n', 'v',
      'e', 'r', 'g', 'e', 'd', ' ', 'a', 'n', 'd', ' ', 't',  'h', 'e',
      ' ', 'p', 'r', 'i', 'c', 'e', 's', ' ', 'i', 's', ' ',  '.', '.',
      '.', '%', '2', '.', '4', 'f', ' ', 'i', 'n', ' ', '%',  '2', '.',
      '1', 'f', ' ', 'p', 'e', 'r', 'i', 'o', 'd', 's', '\\', 'n'};
  static const char_T cv1[67]{
      'e', 'n', 't', 'r', 'y', ' ', 'a', 'n', 'd', ' ',  'e', 'x', 'i', 't',
      ' ', 'h', 'a', 'v', 'e', ' ', 'c', 'o', 'n', 'v',  'e', 'r', 'g', 'e',
      'd', ' ', 'a', 'n', 'd', ' ', 'E', '(', 'v', ')',  ' ', 'i', 's', ' ',
      '%', '2', '.', '4', 'f', ' ', 'i', 'n', ' ', '%',  '2', '.', '1', 'f',
      ' ', 'p', 'e', 'r', 'i', 'o', 'd', 's', ' ', '\\', 'n'};
  static const char_T cv3[43]{'v', 'a', 'l', 'u', 'e', ' ',  'f', 'u', 'n',
                              'c', 't', 'i', 'o', 'n', ' ',  'c', 'o', 'n',
                              'v', 'e', 'r', 'g', 'e', 'd',  ' ', 'i', 'n',
                              ' ', '%', '4', '.', '1', 'f',  ' ', 'p', 'e',
                              'r', 'i', 'o', 'd', 's', '\\', 'n'};
  static const char_T cv4[41]{
      'd', 'i', 's', 't', 'r', 'i', 'b', 'u', 't', 'i', 'o', 'n',  ' ', 'c',
      'o', 'n', 'v', 'e', 'r', 'g', 'e', 'd', ' ', 'i', 'n', ' ',  '%', '4',
      '.', '1', 'f', ' ', 'p', 'e', 'r', 'i', 'o', 'd', 's', '\\', 'n'};
  static const char_T cv[7]{'f', 'p', 'r', 'i', 'n', 't', 'f'};
  coder::array<real_T, 2U> a_cdf;
  coder::array<real_T, 2U> b_a_grid;
  coder::array<real_T, 2U> b_v;
  coder::array<real_T, 2U> cap_contemp;
  coder::array<real_T, 2U> dist_ent;
  coder::array<real_T, 2U> dist_new;
  coder::array<real_T, 2U> r2;
  coder::array<real_T, 2U> v;
  coder::array<real_T, 2U> v_adopt;
  coder::array<real_T, 2U> v_adopt_p;
  coder::array<real_T, 2U> v_p;
  coder::array<real_T, 1U> b_v_p;
  coder::array<real_T, 1U> stay_alive_besideold;
  coder::array<real_T, 1U> v_best;
  coder::array<real_T, 1U> v_p_expand;
  coder::array<int32_T, 1U> r;
  coder::array<int32_T, 1U> r1;
  coder::array<int32_T, 1U> r3;
  coder::array<boolean_T, 2U> exit_vec;
  coder::array<boolean_T, 2U> exiting_firm;
  coder::array<boolean_T, 2U> pi_contemp_neg;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  real_T b_error;
  real_T b_varargin_2;
  real_T d;
  real_T max_iter_price;
  real_T varargin_2;
  int32_T b_v_p_expand[2];
  int32_T iv[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T b_loop_ub_tmp;
  int32_T h;
  int32_T i;
  int32_T idx;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T nx;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &emlrtRSI;
  coder::linspace(&st, a_num_g, a_cdf);
  st.site = &emlrtRSI;
  coder::expinv(&st, a_cdf, a_lamb, a_grid);
  st.site = &b_emlrtRSI;
  coder::expcdf(&st, a_grid, a_lamb, a_cdf);
  if (2.0 > a_num_g) {
    k = 0;
    i = 0;
  } else {
    if (2 > a_cdf.size(1)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, a_cdf.size(1), &emlrtBCI,
                                    (emlrtCTX)sp);
    }
    k = 1;
    if (a_num_g != static_cast<int32_T>(muDoubleScalarFloor(a_num_g))) {
      emlrtIntegerCheckR2012b(a_num_g, &emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(a_num_g) < 1) ||
        (static_cast<int32_T>(a_num_g) > a_cdf.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a_num_g), 1,
                                    a_cdf.size(1), &b_emlrtBCI, (emlrtCTX)sp);
    }
    i = static_cast<int32_T>(a_num_g);
  }
  loop_ub = i - k;
  a_prob.set_size(&db_emlrtRTEI, sp, 1, loop_ub + 1);
  for (i = 0; i < loop_ub; i++) {
    a_prob[i] = a_cdf[k + i];
  }
  a_prob[loop_ub] = 1.0;
  if ((a_prob.size(1) != a_cdf.size(1)) &&
      ((a_prob.size(1) != 1) && (a_cdf.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(a_prob.size(1), a_cdf.size(1), &emlrtECI,
                                (emlrtCTX)sp);
  }
  if (a_prob.size(1) == a_cdf.size(1)) {
    loop_ub = a_prob.size(1) - 1;
    a_prob.set_size(&eb_emlrtRTEI, sp, 1, a_prob.size(1));
    for (k = 0; k <= loop_ub; k++) {
      a_prob[k] = a_prob[k] - a_cdf[k];
    }
  } else {
    st.site = &gg_emlrtRSI;
    minus(&st, a_prob, a_cdf);
  }
  max_iter_price = muDoubleScalarFloor(max_iter / 100.0);
  st.site = &c_emlrtRSI;
  coder::linspace(&st, age_num - 1.0, age_num, a_cdf);
  age_g.set_size(&fb_emlrtRTEI, sp, a_cdf.size(1));
  loop_ub = a_cdf.size(1);
  for (k = 0; k < loop_ub; k++) {
    age_g[k] = a_cdf[k];
  }
  // %%%% these should be predefined for mex purposes
  st.site = &d_emlrtRSI;
  coder::b_sparse(&st, age_num * a_num_g, age_num * a_num_g, trans_matrix);
  dist.set_size(&gb_emlrtRTEI, sp, 1, dist.size(1));
  varargin_2 = age_num * a_num_g;
  if (!(varargin_2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, &k_emlrtDCI, (emlrtCTX)sp);
  }
  d = static_cast<int32_T>(muDoubleScalarFloor(varargin_2));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &j_emlrtDCI, (emlrtCTX)sp);
  }
  dist.set_size(&gb_emlrtRTEI, sp, dist.size(0),
                static_cast<int32_T>(varargin_2));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &s_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(varargin_2);
  for (k = 0; k < loop_ub; k++) {
    dist[k] = 0.0;
  }
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &t_emlrtDCI, (emlrtCTX)sp);
  }
  v_new.set_size(&hb_emlrtRTEI, sp, static_cast<int32_T>(varargin_2));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &t_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(varargin_2);
  for (k = 0; k < loop_ub; k++) {
    v_new[k] = 0.0;
  }
  if (!(age_num >= 0.0)) {
    emlrtNonNegativeCheckR2012b(age_num, &m_emlrtDCI, (emlrtCTX)sp);
  }
  b_varargin_2 = static_cast<int32_T>(muDoubleScalarFloor(age_num));
  if (age_num != b_varargin_2) {
    emlrtIntegerCheckR2012b(age_num, &l_emlrtDCI, (emlrtCTX)sp);
  }
  v_new_resh.set_size(&ib_emlrtRTEI, sp, static_cast<int32_T>(age_num),
                      v_new_resh.size(1));
  if (!(a_num_g >= 0.0)) {
    emlrtNonNegativeCheckR2012b(a_num_g, &o_emlrtDCI, (emlrtCTX)sp);
  }
  b_error = static_cast<int32_T>(muDoubleScalarFloor(a_num_g));
  if (a_num_g != b_error) {
    emlrtIntegerCheckR2012b(a_num_g, &n_emlrtDCI, (emlrtCTX)sp);
  }
  v_new_resh.set_size(&ib_emlrtRTEI, sp, v_new_resh.size(0),
                      static_cast<int32_T>(a_num_g));
  if (age_num != b_varargin_2) {
    emlrtIntegerCheckR2012b(age_num, &u_emlrtDCI, (emlrtCTX)sp);
  }
  if (a_num_g != b_error) {
    emlrtIntegerCheckR2012b(a_num_g, &u_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub_tmp = static_cast<int32_T>(age_num) * static_cast<int32_T>(a_num_g);
  for (k = 0; k < loop_ub_tmp; k++) {
    v_new_resh[k] = 0.0;
  }
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &b_emlrtDCI, (emlrtCTX)sp);
  }
  exit_vec.set_size(&jb_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
                    static_cast<int32_T>(varargin_2));
  loop_ub = static_cast<int32_T>(varargin_2) * static_cast<int32_T>(varargin_2);
  for (k = 0; k < loop_ub; k++) {
    exit_vec[k] = false;
  }
  // %%%%
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &p_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(a_num_g);
  v_p.set_size(&kb_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
               static_cast<int32_T>(a_num_g));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &v_emlrtDCI, (emlrtCTX)sp);
  }
  b_loop_ub_tmp =
      static_cast<int32_T>(varargin_2) * static_cast<int32_T>(a_num_g);
  for (k = 0; k < b_loop_ub_tmp; k++) {
    v_p[k] = 0.0;
  }
  // %% Here we will have endogenous entry: this means that as long as value of
  // %% entrant - the cost of entry is positive there should be entrants. To
  // %% solve it I will loop over the whole soltuion till I find the
  // %% equilibrium price satisfying this condition; first I start with p_E = 1
  *p_E = 1.0;
  st.site = &e_emlrtRSI;
  coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_p_expand);
  st.site = &e_emlrtRSI;
  b_varargin_2 = coder::mpower(&st, alpha / p_e, alpha);
  b_a_grid.set_size(&lb_emlrtRTEI, sp, v_p_expand.size(0), a_grid.size(1));
  b_loop_ub = a_grid.size(1);
  for (k = 0; k < b_loop_ub; k++) {
    nx = v_p_expand.size(0);
    for (i = 0; i < nx; i++) {
      b_a_grid[i + b_a_grid.size(0) * k] =
          (a_grid[k] + 1.0) * b_varargin_2 * v_p_expand[i];
    }
  }
  st.site = &e_emlrtRSI;
  coder::power(&st, b_a_grid, 1.0 / (1.0 - alpha), pi_contemp);
  //  cap_contemp     =
  //  (((1+a_grid).*(alpha*p_E/p_e)^alpha.*(1/(1+a_grow)).^age_g)...
  //      .^(1/(1-alpha)))';
  // %% here I'm adding fixed cost of operation to implement exit decision: it
  // %% should be calibrated
  b_loop_ub = pi_contemp.size(0) * pi_contemp.size(1);
  for (k = 0; k < b_loop_ub; k++) {
    pi_contemp[k] = pi_contemp[k] * (1.0 - alpha) - fco;
  }
  // %% those with negative contemporary profit will exit
  idx = pi_contemp.size(0) * pi_contemp.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= idx; b_i++) {
    if (pi_contemp[b_i] < 0.0) {
      nx++;
    }
  }
  r.set_size(&mb_emlrtRTEI, sp, nx);
  nx = 0;
  for (b_i = 0; b_i <= idx; b_i++) {
    if (pi_contemp[b_i] < 0.0) {
      r[nx] = b_i + 1;
      nx++;
    }
  }
  b_loop_ub = r.size(0) - 1;
  nx = pi_contemp.size(0) * pi_contemp.size(1);
  for (k = 0; k <= b_loop_ub; k++) {
    if ((r[k] < 1) || (r[k] > nx)) {
      emlrtDynamicBoundsCheckR2012b(r[k], 1, nx, &t_emlrtBCI, (emlrtCTX)sp);
    }
    pi_contemp[r[k] - 1] = 0.0;
  }
  //  a_prob_3d           = zeros(1,1,a_num_g);
  //  a_prob_3d(1,1,:)    = a_prob;
  v.set_size(&nb_emlrtRTEI, sp, pi_contemp.size(0), pi_contemp.size(1));
  b_loop_ub = pi_contemp.size(0) * pi_contemp.size(1);
  for (k = 0; k < b_loop_ub; k++) {
    v[k] = pi_contemp[k];
  }
  // %%% also to have the entry and exit equal to each other the measure of the
  // %%% firms should be the correct number
  *m_of_firms = 1.0;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter_price, mxDOUBLE_CLASS,
                                static_cast<int32_T>(max_iter_price),
                                &emlrtRTEI, (emlrtCTX)sp);
  h = 0;
  exitg1 = false;
  while ((!exitg1) && (h <= static_cast<int32_T>(max_iter_price) - 1)) {
    int32_T b_k;
    boolean_T exitg2;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter_price, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(max_iter_price),
                                  &b_emlrtRTEI, (emlrtCTX)sp);
    b_k = 0;
    exitg2 = false;
    while ((!exitg2) && (b_k <= static_cast<int32_T>(max_iter_price) - 1)) {
      boolean_T exitg3;
      st.site = &f_emlrtRSI;
      coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_p_expand);
      st.site = &f_emlrtRSI;
      b_varargin_2 = coder::mpower(&st, alpha * *p_E / p_e, alpha);
      b_a_grid.set_size(&ob_emlrtRTEI, sp, v_p_expand.size(0), a_grid.size(1));
      b_loop_ub = a_grid.size(1);
      for (k = 0; k < b_loop_ub; k++) {
        nx = v_p_expand.size(0);
        for (i = 0; i < nx; i++) {
          b_a_grid[i + b_a_grid.size(0) * k] =
              (a_grid[k] + 1.0) * b_varargin_2 * v_p_expand[i];
        }
      }
      st.site = &f_emlrtRSI;
      coder::power(&st, b_a_grid, 1.0 / (1.0 - alpha), pi_contemp);
      st.site = &g_emlrtRSI;
      coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_p_expand);
      st.site = &g_emlrtRSI;
      b_varargin_2 = coder::mpower(&st, alpha * *p_E / p_e, alpha);
      b_a_grid.set_size(&pb_emlrtRTEI, sp, v_p_expand.size(0), a_grid.size(1));
      b_loop_ub = a_grid.size(1);
      for (k = 0; k < b_loop_ub; k++) {
        nx = v_p_expand.size(0);
        for (i = 0; i < nx; i++) {
          b_a_grid[i + b_a_grid.size(0) * k] =
              (a_grid[k] + 1.0) * b_varargin_2 * v_p_expand[i];
        }
      }
      st.site = &g_emlrtRSI;
      coder::power(&st, b_a_grid, 1.0 / (1.0 - alpha), v_adopt_p);
      cap_contemp.set_size(&qb_emlrtRTEI, sp, v_adopt_p.size(1),
                           v_adopt_p.size(0));
      b_loop_ub = v_adopt_p.size(0);
      for (k = 0; k < b_loop_ub; k++) {
        nx = v_adopt_p.size(1);
        for (i = 0; i < nx; i++) {
          cap_contemp[i + cap_contemp.size(0) * k] =
              v_adopt_p[k + v_adopt_p.size(0) * i];
        }
      }
      b_loop_ub = pi_contemp.size(0) * pi_contemp.size(1);
      for (k = 0; k < b_loop_ub; k++) {
        pi_contemp[k] = pi_contemp[k] * (1.0 - alpha) - fco;
      }
      pi_contemp_neg.set_size(&rb_emlrtRTEI, sp, pi_contemp.size(0),
                              pi_contemp.size(1));
      b_loop_ub = pi_contemp.size(0) * pi_contemp.size(1);
      idx = pi_contemp.size(0) * pi_contemp.size(1) - 1;
      nx = 0;
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        pi_contemp_neg[b_i] = (pi_contemp[b_i] < 0.0);
        if (pi_contemp[b_i] < 0.0) {
          nx++;
        }
      }
      r1.set_size(&mb_emlrtRTEI, sp, nx);
      nx = 0;
      for (b_i = 0; b_i <= idx; b_i++) {
        if (pi_contemp[b_i] < 0.0) {
          r1[nx] = b_i + 1;
          nx++;
        }
      }
      b_loop_ub = r1.size(0) - 1;
      nx = pi_contemp.size(0) * pi_contemp.size(1);
      for (k = 0; k <= b_loop_ub; k++) {
        if ((r1[k] < 1) || (r1[k] > nx)) {
          emlrtDynamicBoundsCheckR2012b(r1[k], 1, nx, &u_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        pi_contemp[r1[k] - 1] = 0.0;
      }
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter, mxDOUBLE_CLASS,
                                    static_cast<int32_T>(max_iter),
                                    &c_emlrtRTEI, (emlrtCTX)sp);
      b_i = 0;
      exitg3 = false;
      while ((!exitg3) && (b_i <= static_cast<int32_T>(max_iter) - 1)) {
        v_p.set_size(&sb_emlrtRTEI, sp, v.size(1), v.size(0));
        b_loop_ub = v.size(0);
        for (k = 0; k < b_loop_ub; k++) {
          nx = v.size(1);
          for (i = 0; i < nx; i++) {
            v_p[i + v_p.size(0) * k] = v[k + v.size(0) * i];
          }
        }
        if (2.0 > age_num) {
          k = -1;
          i = -1;
          idx = 0;
        } else {
          if (2 > v_p.size(1)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, v_p.size(1), &c_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          k = 0;
          if ((static_cast<int32_T>(age_num) < 1) ||
              (static_cast<int32_T>(age_num) > v_p.size(1))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num), 1,
                                          v_p.size(1), &d_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          i = static_cast<int32_T>(age_num) - 1;
          if (1 > v_p.size(1)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, v_p.size(1), &e_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if ((static_cast<int32_T>(age_num) - 1 < 1) ||
              (static_cast<int32_T>(age_num) - 1 > v_p.size(1))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num) - 1, 1,
                                          v_p.size(1), &f_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          idx = static_cast<int32_T>(age_num) - 1;
        }
        b_v_p_expand[0] = v_p.size(0);
        b_v_p_expand[1] = idx;
        iv[0] = v_p.size(0);
        b_loop_ub = i - k;
        iv[1] = b_loop_ub;
        emlrtSubAssignSizeCheckR2012b(&b_v_p_expand[0], 2, &iv[0], 2,
                                      &b_emlrtECI, (emlrtCTX)sp);
        nx = v_p.size(0) - 1;
        b_a_grid.set_size(&tb_emlrtRTEI, sp, v_p.size(0), b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          for (idx = 0; idx <= nx; idx++) {
            b_a_grid[idx + b_a_grid.size(0) * i] =
                v_p[idx + v_p.size(0) * ((k + i) + 1)];
          }
        }
        b_loop_ub = b_a_grid.size(1);
        for (k = 0; k < b_loop_ub; k++) {
          nx = b_a_grid.size(0);
          for (i = 0; i < nx; i++) {
            v_p[i + v_p.size(0) * k] = b_a_grid[i + b_a_grid.size(0) * k];
          }
        }
        if ((static_cast<int32_T>(age_num) < 1) ||
            (static_cast<int32_T>(age_num) > v_p.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num), 1,
                                        v_p.size(1), &g_emlrtBCI, (emlrtCTX)sp);
        }
        b_loop_ub = v_p.size(0);
        for (k = 0; k < b_loop_ub; k++) {
          v_p[k + v_p.size(0) * (static_cast<int32_T>(age_num) - 1)] = 0.0;
        }
        // %% setting the
        // %% value of those who don't adopt
        // %% at the highest age to zero; it
        // %% should also be noted that if a
        // %% firm is not adopting, in the
        // %% next period it would get the
        // %% value of v(age+1,a_i)
        nx = v_p.size(0) * v_p.size(1);
        v_best.set_size(&ub_emlrtRTEI, sp, static_cast<int32_T>(a_num_g));
        for (k = 0; k < loop_ub; k++) {
          v_best[k] = 1.0;
        }
        b_v_p = v_p.reshape(nx);
        st.site = &h_emlrtRSI;
        coder::kron(&st, b_v_p, v_best, v_p_expand);
        if (1 > v.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, v.size(0), &h_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_a_grid.set_size(&vb_emlrtRTEI, sp, static_cast<int32_T>(age_num),
                          static_cast<int32_T>(a_num_g));
        for (k = 0; k < loop_ub_tmp; k++) {
          b_a_grid[k] = 1.0;
        }
        b_loop_ub = v.size(1);
        b_v.set_size(&wb_emlrtRTEI, sp, 1, v.size(1));
        for (k = 0; k < b_loop_ub; k++) {
          b_v[k] = v[v.size(0) * k];
        }
        st.site = &i_emlrtRSI;
        coder::kron(&st, b_a_grid, b_v, v_adopt);
        v_adopt_p.set_size(&xb_emlrtRTEI, sp, v_adopt.size(1), v_adopt.size(0));
        b_loop_ub = v_adopt.size(0);
        for (k = 0; k < b_loop_ub; k++) {
          nx = v_adopt.size(1);
          for (i = 0; i < nx; i++) {
            v_adopt_p[i + v_adopt_p.size(0) * k] =
                v_adopt[k + v_adopt.size(0) * i];
          }
        }
        //      v_best      =
        //      max(v_adopt_vec-c_of_a*(1+(kron([1:age_num],ones(1,a_num_g^2)))'/a_bar)...
        //          ,v_p_expand);
        // %%% with fixed cost of operation I'm not sure if we need the
        // %%% increasing with time cost of adoptation
        st.site = &j_emlrtRSI;
        stay_alive_besideold.set_size(&yb_emlrtRTEI, &st,
                                      v_adopt_p.size(0) * v_adopt_p.size(1));
        b_loop_ub = v_adopt_p.size(0) * v_adopt_p.size(1);
        for (k = 0; k < b_loop_ub; k++) {
          stay_alive_besideold[k] = v_adopt_p[k] - c_of_a;
        }
        b_st.site = &cc_emlrtRSI;
        c_st.site = &dc_emlrtRSI;
        e_st.site = &ec_emlrtRSI;
        f_st.site = &fc_emlrtRSI;
        g_st.site = &gc_emlrtRSI;
        if (stay_alive_besideold.size(0) == v_p_expand.size(0)) {
          v_best.set_size(&ac_emlrtRTEI, &g_st, stay_alive_besideold.size(0));
          b_loop_ub = stay_alive_besideold.size(0);
          for (k = 0; k < b_loop_ub; k++) {
            b_error = stay_alive_besideold[k];
            b_varargin_2 = v_p_expand[k];
            v_best[k] = muDoubleScalarMax(b_error, b_varargin_2);
          }
        } else {
          h_st.site = &hc_emlrtRSI;
          coder::internal::expand_max(&h_st, stay_alive_besideold, v_p_expand,
                                      v_best);
        }
        st.site = &k_emlrtRSI;
        nx = v_best.size(0);
        b_st.site = &ic_emlrtRSI;
        c_st.site = &jc_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, a_num_g);
        c_st.site = &jc_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, varargin_2);
        idx = v_best.size(0);
        if (1 > v_best.size(0)) {
          idx = 1;
        }
        nx = muIntScalarMax_sint32(nx, idx);
        if (static_cast<int32_T>(a_num_g) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (static_cast<int32_T>(varargin_2) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (b_loop_ub_tmp != v_best.size(0)) {
          emlrtErrorWithMessageIdR2018a(
              &st, &f_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
              "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }
        v_adopt.set_size(&bc_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
                         static_cast<int32_T>(a_num_g));
        for (k = 0; k < loop_ub; k++) {
          b_loop_ub = static_cast<int32_T>(varargin_2);
          for (i = 0; i < b_loop_ub; i++) {
            v_adopt[i + v_adopt.size(0) * k] =
                v_best[k + static_cast<int32_T>(a_num_g) * i];
          }
        }
        k = v_p.size(0) * v_p.size(1);
        if ((v_adopt.size(0) != k) && ((v_adopt.size(0) != 1) && (k != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_adopt.size(0), k, &c_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if (v_adopt.size(0) == v_p.size(0) * v_p.size(1)) {
          b_a_grid.set_size(&cc_emlrtRTEI, sp, v_adopt.size(0),
                            v_adopt.size(1));
          b_loop_ub = v_adopt.size(1);
          for (k = 0; k < b_loop_ub; k++) {
            nx = v_adopt.size(0);
            for (i = 0; i < nx; i++) {
              b_a_grid[i + b_a_grid.size(0) * k] =
                  1.0 - static_cast<real_T>(v_adopt[i + v_adopt.size(0) * k] ==
                                            v_p[i]);
            }
          }
          v_p.set_size(&dc_emlrtRTEI, sp, b_a_grid.size(0), b_a_grid.size(1));
          b_loop_ub = b_a_grid.size(0) * b_a_grid.size(1);
          for (k = 0; k < b_loop_ub; k++) {
            v_p[k] = b_a_grid[k];
          }
        } else {
          st.site = &fg_emlrtRSI;
          binary_expand_op(&st, v_p, v_adopt);
        }
        // %% those who couldn't pay the fco should exit
        exiting_firm.set_size(&ec_emlrtRTEI, sp, pi_contemp_neg.size(1),
                              pi_contemp_neg.size(0));
        b_loop_ub = pi_contemp_neg.size(0);
        for (k = 0; k < b_loop_ub; k++) {
          nx = pi_contemp_neg.size(1);
          for (i = 0; i < nx; i++) {
            exiting_firm[i + exiting_firm.size(0) * k] =
                pi_contemp_neg[k + pi_contemp_neg.size(0) * i];
          }
        }
        exit_vec.set_size(&fc_emlrtRTEI, sp,
                          exiting_firm.size(0) * exiting_firm.size(1), 1);
        b_loop_ub = exiting_firm.size(0) * exiting_firm.size(1);
        for (k = 0; k < b_loop_ub; k++) {
          exit_vec[k] = exiting_firm[k];
        }
        b_v_p_expand[0] = exiting_firm.size(0) * exiting_firm.size(1);
        r2.set_size(&gc_emlrtRTEI, sp, b_v_p_expand[0], 1);
        b_loop_ub = b_v_p_expand[0];
        for (k = 0; k < b_loop_ub; k++) {
          r2[k] = 1.0 - static_cast<real_T>(exiting_firm[k]);
        }
        st.site = &l_emlrtRSI;
        coder::repmat(&st, r2, a_num_g, v_adopt_p);
        if ((v_adopt_p.size(0) != v_p.size(0)) &&
            ((v_adopt_p.size(0) != 1) && (v_p.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_adopt_p.size(0), v_p.size(0),
                                      &d_emlrtECI, (emlrtCTX)sp);
        }
        if ((v_adopt_p.size(1) != v_p.size(1)) &&
            ((v_adopt_p.size(1) != 1) && (v_p.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_adopt_p.size(1), v_p.size(1),
                                      &e_emlrtECI, (emlrtCTX)sp);
        }
        if ((v_adopt_p.size(0) == v_p.size(0)) &&
            (v_adopt_p.size(1) == v_p.size(1))) {
          b_loop_ub = v_adopt_p.size(0) * v_adopt_p.size(1);
          v_p.set_size(&hc_emlrtRTEI, sp, v_adopt_p.size(0), v_adopt_p.size(1));
          for (k = 0; k < b_loop_ub; k++) {
            v_p[k] = v_adopt_p[k] * v_p[k];
          }
        } else {
          st.site = &l_emlrtRSI;
          times(&st, v_p, v_adopt_p);
        }
        st.site = &m_emlrtRSI;
        b_st.site = &pc_emlrtRSI;
        coder::dynamic_size_checks(&b_st, v_adopt, a_prob, v_adopt.size(1),
                                   a_prob.size(1));
        b_st.site = &oc_emlrtRSI;
        coder::internal::blas::mtimes(&b_st, v_adopt, a_prob, v_new);
        st.site = &n_emlrtRSI;
        nx = v_new.size(0);
        b_st.site = &ic_emlrtRSI;
        c_st.site = &jc_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, a_num_g);
        c_st.site = &jc_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, age_num);
        idx = v_new.size(0);
        if (1 > v_new.size(0)) {
          idx = 1;
        }
        nx = muIntScalarMax_sint32(nx, idx);
        if (static_cast<int32_T>(a_num_g) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (static_cast<int32_T>(age_num) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &e_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (loop_ub_tmp != v_new.size(0)) {
          emlrtErrorWithMessageIdR2018a(
              &st, &f_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
              "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }
        v_new_resh.set_size(&ic_emlrtRTEI, sp, static_cast<int32_T>(age_num),
                            static_cast<int32_T>(a_num_g));
        for (k = 0; k < loop_ub; k++) {
          b_loop_ub = static_cast<int32_T>(age_num);
          for (i = 0; i < b_loop_ub; i++) {
            v_new_resh[i + v_new_resh.size(0) * k] =
                beta * v_new[k + static_cast<int32_T>(a_num_g) * i];
          }
        }
        if ((pi_contemp.size(0) != v_new_resh.size(0)) &&
            ((pi_contemp.size(0) != 1) && (v_new_resh.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(pi_contemp.size(0), v_new_resh.size(0),
                                      &f_emlrtECI, (emlrtCTX)sp);
        }
        if ((pi_contemp.size(1) != v_new_resh.size(1)) &&
            ((pi_contemp.size(1) != 1) && (v_new_resh.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(pi_contemp.size(1), v_new_resh.size(1),
                                      &g_emlrtECI, (emlrtCTX)sp);
        }
        if ((pi_contemp.size(0) == v_new_resh.size(0)) &&
            (pi_contemp.size(1) == v_new_resh.size(1))) {
          b_loop_ub = pi_contemp.size(0) * pi_contemp.size(1);
          v_new_resh.set_size(&jc_emlrtRTEI, sp, pi_contemp.size(0),
                              pi_contemp.size(1));
          for (k = 0; k < b_loop_ub; k++) {
            v_new_resh[k] = pi_contemp[k] + v_new_resh[k];
          }
        } else {
          st.site = &eg_emlrtRSI;
          b_plus(&st, v_new_resh, pi_contemp);
        }
        idx = pi_contemp_neg.size(0) * pi_contemp_neg.size(1) - 1;
        nx = 0;
        for (i = 0; i <= idx; i++) {
          if (pi_contemp_neg[i]) {
            nx++;
          }
        }
        r3.set_size(&mb_emlrtRTEI, sp, nx);
        nx = 0;
        for (i = 0; i <= idx; i++) {
          if (pi_contemp_neg[i]) {
            r3[nx] = i + 1;
            nx++;
          }
        }
        b_loop_ub = r3.size(0) - 1;
        nx = v_new_resh.size(0) * v_new_resh.size(1);
        for (k = 0; k <= b_loop_ub; k++) {
          if ((r3[k] < 1) || (r3[k] > nx)) {
            emlrtDynamicBoundsCheckR2012b(r3[k], 1, nx, &v_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          v_new_resh[r3[k] - 1] = 0.0;
        }
        if ((v.size(0) != v_new_resh.size(0)) &&
            ((v.size(0) != 1) && (v_new_resh.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(v.size(0), v_new_resh.size(0),
                                      &h_emlrtECI, (emlrtCTX)sp);
        }
        if ((v.size(1) != v_new_resh.size(1)) &&
            ((v.size(1) != 1) && (v_new_resh.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(v.size(1), v_new_resh.size(1),
                                      &i_emlrtECI, (emlrtCTX)sp);
        }
        st.site = &o_emlrtRSI;
        if ((v.size(0) == v_new_resh.size(0)) &&
            (v.size(1) == v_new_resh.size(1))) {
          b_a_grid.set_size(&kc_emlrtRTEI, &st, v.size(0), v.size(1));
          b_loop_ub = v.size(0) * v.size(1);
          for (k = 0; k < b_loop_ub; k++) {
            b_a_grid[k] = v[k] - v_new_resh[k];
          }
          b_st.site = &o_emlrtRSI;
          coder::b_abs(&b_st, b_a_grid, v_adopt);
        } else {
          b_st.site = &o_emlrtRSI;
          d_binary_expand_op(&b_st, v_adopt, o_emlrtRSI, v, v_new_resh);
        }
        b_st.site = &cc_emlrtRSI;
        c_st.site = &uc_emlrtRSI;
        e_st.site = &vc_emlrtRSI;
        f_st.site = &wc_emlrtRSI;
        b_error = coder::internal::applyToMultipleDims(&f_st, v_adopt);
        if (b_error < v_tol) {
          st.site = &p_emlrtRSI;
          b_st.site = &hd_emlrtRSI;
          c_st.site = &bg_emlrtRSI;
          d_st.site = &cg_emlrtRSI;
          emlrt_marshallIn(
              &c_st,
              feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                    b_emlrt_marshallOut(&d_st, cv3),
                    emlrt_marshallOut(static_cast<real_T>(b_i) + 1.0),
                    &emlrtMCI),
              "<output of feval>");
          exitg3 = true;
        } else {
          v.set_size(&lc_emlrtRTEI, sp, v_new_resh.size(0), v_new_resh.size(1));
          b_loop_ub = v_new_resh.size(0) * v_new_resh.size(1);
          for (k = 0; k < b_loop_ub; k++) {
            v[k] = v_new_resh[k];
          }
          b_i++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtCTX)sp);
          }
        }
      }
      //         %%
      // %% Here I derive the transition matrix; first those who don't adopt go
      // to
      // %% the same technology state with a higher age, those who adopt go the
      // %% technology they adopt with the age zero meaning we have:
      //          p_of_naot_besideold           = zeros((age_num-1)*a_num_g,1);
      b_error = (age_num - 1.0) * a_num_g;
      if (1.0 > b_error) {
        k = 0;
      } else {
        if (1 > exit_vec.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec.size(0), &i_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (b_error != static_cast<int32_T>(muDoubleScalarFloor(b_error))) {
          emlrtIntegerCheckR2012b(b_error, &c_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error) < 1) ||
            (static_cast<int32_T>(b_error) > exit_vec.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error), 1,
                                        exit_vec.size(0), &j_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        k = static_cast<int32_T>(b_error);
      }
      if (1 > exit_vec.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec.size(1), &k_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      st.site = &q_emlrtRSI;
      coder::b_sparse(&st, a_num_g * age_num, a_num_g * age_num, trans_matrix);
      st.site = &r_emlrtRSI;
      coder::b_repmat(&st, a_prob, age_num * a_num_g, v_adopt_p);
      if ((v_p.size(0) != v_adopt_p.size(0)) &&
          ((v_p.size(0) != 1) && (v_adopt_p.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p.size(0), v_adopt_p.size(0), &j_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if ((v_p.size(1) != v_adopt_p.size(1)) &&
          ((v_p.size(1) != 1) && (v_adopt_p.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p.size(1), v_adopt_p.size(1), &k_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if ((v_p.size(0) == v_adopt_p.size(0)) &&
          (v_p.size(1) == v_adopt_p.size(1))) {
        b_loop_ub = v_p.size(0) * v_p.size(1);
        v_adopt_p.set_size(&mc_emlrtRTEI, sp, v_p.size(0), v_p.size(1));
        for (i = 0; i < b_loop_ub; i++) {
          v_adopt_p[i] = v_p[i] * v_adopt_p[i];
        }
      } else {
        st.site = &r_emlrtRSI;
        times(&st, v_adopt_p, v_p);
      }
      if ((v_adopt_p.size(0) != exit_vec.size(0)) &&
          ((v_adopt_p.size(0) != 1) && (exit_vec.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_adopt_p.size(0), exit_vec.size(0),
                                    &j_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_adopt_p.size(1) != exit_vec.size(1)) &&
          ((v_adopt_p.size(1) != 1) && (exit_vec.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_adopt_p.size(1), exit_vec.size(1),
                                    &k_emlrtECI, (emlrtCTX)sp);
      }
      if (a_num_g < 1.0) {
        dist_ent.set_size(&nc_emlrtRTEI, sp, 1, 0);
      } else {
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        dist_ent.set_size(&nc_emlrtRTEI, sp, 1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      if ((v_adopt_p.size(0) == exit_vec.size(0)) &&
          (v_adopt_p.size(1) == exit_vec.size(1))) {
        b_a_grid.set_size(&mc_emlrtRTEI, sp, v_adopt_p.size(0),
                          v_adopt_p.size(1));
        b_loop_ub = v_adopt_p.size(0) * v_adopt_p.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          b_a_grid[i] = v_adopt_p[i] * (1.0 - static_cast<real_T>(exit_vec[i]));
        }
        st.site = &r_emlrtRSI;
        trans_matrix->parenAssign(&st, b_a_grid, dist_ent);
      } else {
        st.site = &r_emlrtRSI;
        c_binary_expand_op(&st, r_emlrtRSI, trans_matrix, v_adopt_p, exit_vec,
                           dist_ent);
      }
      st.site = &s_emlrtRSI;
      coder::b_repmat(&st, a_prob, age_num * a_num_g, v_adopt_p);
      if ((v_p.size(0) != v_adopt_p.size(0)) &&
          ((v_p.size(0) != 1) && (v_adopt_p.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p.size(0), v_adopt_p.size(0), &l_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if ((v_p.size(1) != v_adopt_p.size(1)) &&
          ((v_p.size(1) != 1) && (v_adopt_p.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p.size(1), v_adopt_p.size(1), &m_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if ((v_p.size(0) == v_adopt_p.size(0)) &&
          (v_p.size(1) == v_adopt_p.size(1))) {
        b_a_grid.set_size(&oc_emlrtRTEI, sp, v_p.size(0), v_p.size(1));
        b_loop_ub = v_p.size(0) * v_p.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          b_a_grid[i] = (1.0 - v_p[i]) * v_adopt_p[i];
        }
        st.site = &s_emlrtRSI;
        coder::sum(&st, b_a_grid, v_p_expand);
      } else {
        st.site = &s_emlrtRSI;
        binary_expand_op(&st, v_p_expand, s_emlrtRSI, v_p, v_adopt_p);
      }
      if (age_num - 1.0 < 1.0) {
        dist_ent.set_size(&nc_emlrtRTEI, sp, 1, 0);
      } else if (muDoubleScalarIsInf(age_num - 1.0) && (1.0 == age_num - 1.0)) {
        dist_ent.set_size(&nc_emlrtRTEI, sp, 1, 1);
        dist_ent[0] = rtNaN;
      } else {
        b_loop_ub =
            static_cast<int32_T>(muDoubleScalarFloor((age_num - 1.0) - 1.0));
        dist_ent.set_size(&nc_emlrtRTEI, sp, 1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      b_v.set_size(&pc_emlrtRTEI, sp, 1, static_cast<int32_T>(a_num_g));
      for (i = 0; i < loop_ub; i++) {
        b_v[i] = 1.0;
      }
      st.site = &t_emlrtRSI;
      coder::b_kron(&st, dist_ent, b_v, dist_new);
      st.site = &t_emlrtRSI;
      b_st.site = &pb_emlrtRSI;
      c_st.site = &qb_emlrtRSI;
      b_varargin_2 = a_num_g * a_num_g;
      dist_new.set_size(&qc_emlrtRTEI, sp, 1, dist_new.size(1));
      b_loop_ub = dist_new.size(1) - 1;
      for (i = 0; i <= b_loop_ub; i++) {
        dist_new[i] = dist_new[i] * age_num * b_varargin_2;
      }
      if (muDoubleScalarIsNaN(b_error)) {
        a_cdf.set_size(&rc_emlrtRTEI, sp, 1, 1);
        a_cdf[0] = rtNaN;
      } else if (b_error < 1.0) {
        a_cdf.set_size(&rc_emlrtRTEI, sp, 1, 0);
      } else if (muDoubleScalarIsInf(b_error) && (1.0 == b_error)) {
        a_cdf.set_size(&rc_emlrtRTEI, sp, 1, 1);
        a_cdf[0] = rtNaN;
      } else {
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(b_error - 1.0));
        a_cdf.set_size(&rc_emlrtRTEI, sp, 1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          a_cdf[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      if ((dist_new.size(1) != a_cdf.size(1)) &&
          ((dist_new.size(1) != 1) && (a_cdf.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(dist_new.size(1), a_cdf.size(1),
                                    &n_emlrtECI, (emlrtCTX)sp);
      }
      if (dist_new.size(1) == a_cdf.size(1)) {
        b_loop_ub = dist_new.size(1) - 1;
        dist_new.set_size(&qc_emlrtRTEI, sp, 1, dist_new.size(1));
        for (i = 0; i <= b_loop_ub; i++) {
          dist_new[i] = dist_new[i] + a_cdf[i];
        }
      } else {
        st.site = &t_emlrtRSI;
        plus(&st, dist_new, a_cdf);
      }
      if (a_num_g - 1.0 < 0.0) {
        dist_ent.set_size(&nc_emlrtRTEI, sp, 1, 0);
      } else {
        dist_ent.set_size(
            &nc_emlrtRTEI, sp, 1,
            static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0)) + 1);
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = i;
        }
      }
      if (!(age_num - 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(age_num - 1.0, &x_emlrtDCI, (emlrtCTX)sp);
      }
      if (age_num - 1.0 !=
          static_cast<int32_T>(muDoubleScalarFloor(age_num - 1.0))) {
        emlrtIntegerCheckR2012b(age_num - 1.0, &w_emlrtDCI, (emlrtCTX)sp);
      }
      nx = static_cast<int32_T>(age_num - 1.0);
      b_v.set_size(&sc_emlrtRTEI, sp, 1, nx);
      for (i = 0; i < nx; i++) {
        b_v[i] = 1.0;
      }
      st.site = &u_emlrtRSI;
      coder::b_kron(&st, b_v, dist_ent, a_cdf);
      a_cdf.set_size(&tc_emlrtRTEI, sp, 1, a_cdf.size(1));
      b_loop_ub = a_cdf.size(1) - 1;
      for (i = 0; i <= b_loop_ub; i++) {
        a_cdf[i] = a_cdf[i] * age_num * a_num_g;
      }
      if ((dist_new.size(1) != a_cdf.size(1)) &&
          ((dist_new.size(1) != 1) && (a_cdf.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(dist_new.size(1), a_cdf.size(1),
                                    &n_emlrtECI, (emlrtCTX)sp);
      }
      if (1.0 > b_error) {
        i = 0;
      } else {
        if (1 > v_p_expand.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, v_p_expand.size(0), &l_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (b_error != static_cast<int32_T>(muDoubleScalarFloor(b_error))) {
          emlrtIntegerCheckR2012b(b_error, &f_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error) < 1) ||
            (static_cast<int32_T>(b_error) > v_p_expand.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error), 1,
                                        v_p_expand.size(0), &m_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        i = static_cast<int32_T>(b_error);
      }
      iv[0] = 1;
      iv[1] = i;
      st.site = &v_emlrtRSI;
      coder::internal::indexShapeCheck(&st, v_p_expand.size(0), iv);
      if (!(b_error >= 0.0)) {
        emlrtNonNegativeCheckR2012b(b_error, &d_emlrtDCI, (emlrtCTX)sp);
      }
      b_varargin_2 = static_cast<int32_T>(muDoubleScalarFloor(b_error));
      if (b_error != b_varargin_2) {
        emlrtIntegerCheckR2012b(b_error, &e_emlrtDCI, (emlrtCTX)sp);
      }
      b_loop_ub = static_cast<int32_T>((age_num - 1.0) * a_num_g);
      if ((b_loop_ub != i) && ((b_loop_ub != 1) && (i != 1))) {
        emlrtDimSizeImpxCheckR2021b(b_loop_ub, i, &o_emlrtECI, (emlrtCTX)sp);
      }
      if (b_loop_ub == i) {
        v_p_expand.set_size(&uc_emlrtRTEI, sp, b_loop_ub);
      } else {
        st.site = &v_emlrtRSI;
        binary_expand_op(&st, v_p_expand, age_num, a_num_g, i - 1);
      }
      if (b_error != b_varargin_2) {
        emlrtIntegerCheckR2012b(b_error, &g_emlrtDCI, (emlrtCTX)sp);
      }
      if ((b_loop_ub != k) && ((b_loop_ub != 1) && (k != 1))) {
        emlrtDimSizeImpxCheckR2021b(b_loop_ub, k, &p_emlrtECI, (emlrtCTX)sp);
      }
      if (b_loop_ub == k) {
        stay_alive_besideold.set_size(&vc_emlrtRTEI, sp, b_loop_ub);
        for (k = 0; k < b_loop_ub; k++) {
          stay_alive_besideold[k] = 1.0 - static_cast<real_T>(exit_vec[k]);
        }
      } else {
        st.site = &dg_emlrtRSI;
        b_binary_expand_op(&st, stay_alive_besideold, age_num, a_num_g,
                           exit_vec, k - 1);
      }
      if ((v_p_expand.size(0) != stay_alive_besideold.size(0)) &&
          ((v_p_expand.size(0) != 1) && (stay_alive_besideold.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_expand.size(0),
                                    stay_alive_besideold.size(0), &q_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if ((v_p_expand.size(0) == stay_alive_besideold.size(0)) &&
          (dist_new.size(1) == a_cdf.size(1))) {
        b_loop_ub = v_p_expand.size(0);
        for (k = 0; k < b_loop_ub; k++) {
          v_p_expand[k] = v_p_expand[k] * stay_alive_besideold[k];
        }
        b_v.set_size(&qc_emlrtRTEI, sp, 1, dist_new.size(1));
        b_loop_ub = dist_new.size(1);
        for (k = 0; k < b_loop_ub; k++) {
          b_v[k] = dist_new[k] + a_cdf[k];
        }
        st.site = &x_emlrtRSI;
        trans_matrix->parenAssign(&st, v_p_expand, b_v);
      } else {
        st.site = &x_emlrtRSI;
        binary_expand_op(&st, x_emlrtRSI, trans_matrix, v_p_expand,
                         stay_alive_besideold, dist_new, a_cdf);
      }
      // %% also those who are at the last period would die if they don't adopt
      // to
      // %% any technology and a new firm would enter with a random technology
      // %% meaning for those states with the highest age the transition would
      // be
      // %% randomly to age 0 and tech in [0, a_max]
      if (b_error + 1.0 > varargin_2) {
        k = 0;
        i = 0;
      } else {
        if (b_error + 1.0 !=
            static_cast<int32_T>(muDoubleScalarFloor(b_error + 1.0))) {
          emlrtIntegerCheckR2012b(b_error + 1.0, &h_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error + 1.0) < 1) ||
            (static_cast<int32_T>(b_error + 1.0) > exit_vec.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error + 1.0), 1,
                                        exit_vec.size(0), &n_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        k = static_cast<int32_T>(b_error + 1.0) - 1;
        if (varargin_2 != d) {
          emlrtIntegerCheckR2012b(varargin_2, &i_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(varargin_2) < 1) ||
            (static_cast<int32_T>(varargin_2) > exit_vec.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(varargin_2), 1,
                                        exit_vec.size(0), &o_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        i = static_cast<int32_T>(varargin_2);
      }
      st.site = &w_emlrtRSI;
      coder::b_repmat(&st, a_prob, a_num_g, v_adopt_p);
      if (1 > exit_vec.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec.size(1), &p_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_loop_ub = i - k;
      v_p_expand.set_size(&wc_emlrtRTEI, sp, b_loop_ub);
      for (i = 0; i < b_loop_ub; i++) {
        v_p_expand[i] = exit_vec[k + i];
      }
      if ((v_adopt_p.size(0) != v_p_expand.size(0)) &&
          ((v_adopt_p.size(0) != 1) && (v_p_expand.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_adopt_p.size(0), v_p_expand.size(0),
                                    &r_emlrtECI, (emlrtCTX)sp);
      }
      st.site = &y_emlrtRSI;
      b_st.site = &hf_emlrtRSI;
      if (varargin_2 < b_error + 1.0) {
        dist_ent.set_size(&nc_emlrtRTEI, &b_st, 1, 0);
      } else if ((muDoubleScalarIsInf(b_error + 1.0) ||
                  muDoubleScalarIsInf(varargin_2)) &&
                 (b_error + 1.0 == varargin_2)) {
        dist_ent.set_size(&nc_emlrtRTEI, &b_st, 1, 1);
        dist_ent[0] = rtNaN;
      } else if (b_error + 1.0 == b_error + 1.0) {
        b_loop_ub = static_cast<int32_T>(
            muDoubleScalarFloor(varargin_2 - (b_error + 1.0)));
        dist_ent.set_size(&nc_emlrtRTEI, &b_st, 1, b_loop_ub + 1);
        for (k = 0; k <= b_loop_ub; k++) {
          dist_ent[k] = (b_error + 1.0) + static_cast<real_T>(k);
        }
      } else {
        c_st.site = &if_emlrtRSI;
        coder::eml_float_colon(&c_st, b_error + 1.0, varargin_2, dist_ent);
      }
      if (a_num_g < 1.0) {
        a_cdf.set_size(&nc_emlrtRTEI, sp, 1, 0);
      } else {
        a_cdf.set_size(
            &nc_emlrtRTEI, sp, 1,
            static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0)) + 1);
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        for (k = 0; k <= b_loop_ub; k++) {
          a_cdf[k] = static_cast<real_T>(k) + 1.0;
        }
      }
      if (v_adopt_p.size(0) == v_p_expand.size(0)) {
        b_a_grid.set_size(&xc_emlrtRTEI, sp, v_adopt_p.size(0),
                          v_adopt_p.size(1));
        b_loop_ub = v_adopt_p.size(1);
        for (k = 0; k < b_loop_ub; k++) {
          nx = v_adopt_p.size(0);
          for (i = 0; i < nx; i++) {
            b_a_grid[i + b_a_grid.size(0) * k] =
                v_adopt_p[i + v_adopt_p.size(0) * k] * (1.0 - v_p_expand[i]);
          }
        }
        v_adopt_p.set_size(&xc_emlrtRTEI, sp, b_a_grid.size(0),
                           b_a_grid.size(1));
        b_loop_ub = b_a_grid.size(1);
        for (k = 0; k < b_loop_ub; k++) {
          nx = b_a_grid.size(0);
          for (i = 0; i < nx; i++) {
            v_adopt_p[i + v_adopt_p.size(0) * k] =
                b_a_grid[i + b_a_grid.size(0) * k];
          }
        }
        st.site = &y_emlrtRSI;
        trans_matrix->parenAssign(&st, v_adopt_p, dist_ent, a_cdf);
      } else {
        st.site = &y_emlrtRSI;
        binary_expand_op(&st, y_emlrtRSI, trans_matrix, v_adopt_p, v_p_expand,
                         dist_ent, a_cdf);
      }
      dist.set_size(&yc_emlrtRTEI, sp, 1, dist.size(1));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &q_emlrtDCI, (emlrtCTX)sp);
      }
      dist.set_size(&yc_emlrtRTEI, sp, dist.size(0),
                    static_cast<int32_T>(varargin_2));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &y_emlrtDCI, (emlrtCTX)sp);
      }
      b_loop_ub = static_cast<int32_T>(varargin_2);
      for (k = 0; k < b_loop_ub; k++) {
        dist[k] = 1.0;
      }
      dist.set_size(&ad_emlrtRTEI, sp, 1, dist.size(1));
      b_loop_ub = dist.size(1) - 1;
      for (k = 0; k <= b_loop_ub; k++) {
        dist[k] = *m_of_firms * dist[k] / varargin_2;
      }
      dist_ent.set_size(&bd_emlrtRTEI, sp, 1, dist_ent.size(1));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &r_emlrtDCI, (emlrtCTX)sp);
      }
      dist_ent.set_size(&bd_emlrtRTEI, sp, dist_ent.size(0),
                        static_cast<int32_T>(varargin_2));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &ab_emlrtDCI, (emlrtCTX)sp);
      }
      b_loop_ub = static_cast<int32_T>(varargin_2);
      for (k = 0; k < b_loop_ub; k++) {
        dist_ent[k] = 0.0;
      }
      if (1.0 > a_num_g) {
        b_loop_ub = 0;
      } else {
        if (1 > static_cast<int32_T>(varargin_2)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, static_cast<int32_T>(varargin_2),
                                        &q_emlrtBCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(a_num_g) < 1) ||
            (static_cast<int32_T>(a_num_g) >
             static_cast<int32_T>(varargin_2))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a_num_g), 1,
                                        static_cast<int32_T>(varargin_2),
                                        &r_emlrtBCI, (emlrtCTX)sp);
        }
        b_loop_ub = static_cast<int32_T>(a_num_g);
      }
      for (k = 0; k < b_loop_ub; k++) {
        dist_ent[k] = 1.0 / a_num_g;
      }
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter, mxDOUBLE_CLASS,
                                    static_cast<int32_T>(max_iter),
                                    &d_emlrtRTEI, (emlrtCTX)sp);
      i = 0;
      exitg3 = false;
      while ((!exitg3) && (i <= static_cast<int32_T>(max_iter) - 1)) {
        st.site = &ab_emlrtRSI;
        trans_matrix->mtimes(&st, dist, dist_new);
        st.site = &bb_emlrtRSI;
        b_error = *m_of_firms - coder::sum(&st, dist_new);
        a_cdf.set_size(&cd_emlrtRTEI, sp, 1, dist_ent.size(1));
        b_loop_ub = dist_ent.size(1);
        for (k = 0; k < b_loop_ub; k++) {
          a_cdf[k] = b_error * dist_ent[k];
        }
        if ((dist_new.size(1) != a_cdf.size(1)) &&
            ((dist_new.size(1) != 1) && (a_cdf.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(dist_new.size(1), a_cdf.size(1),
                                      &s_emlrtECI, (emlrtCTX)sp);
        }
        if (dist_new.size(1) == a_cdf.size(1)) {
          b_loop_ub = dist_new.size(1) - 1;
          dist_new.set_size(&dd_emlrtRTEI, sp, 1, dist_new.size(1));
          for (k = 0; k <= b_loop_ub; k++) {
            dist_new[k] = dist_new[k] + a_cdf[k];
          }
        } else {
          st.site = &bb_emlrtRSI;
          plus(&st, dist_new, a_cdf);
        }
        if ((dist_new.size(1) != dist.size(1)) &&
            ((dist_new.size(1) != 1) && (dist.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(dist_new.size(1), dist.size(1),
                                      &t_emlrtECI, (emlrtCTX)sp);
        }
        st.site = &cb_emlrtRSI;
        if (dist_new.size(1) == dist.size(1)) {
          b_v.set_size(&ed_emlrtRTEI, &st, 1, dist_new.size(1));
          b_loop_ub = dist_new.size(1);
          for (k = 0; k < b_loop_ub; k++) {
            b_v[k] = dist_new[k] - dist[k];
          }
          b_st.site = &cb_emlrtRSI;
          coder::c_abs(&b_st, b_v, a_cdf);
        } else {
          b_st.site = &cb_emlrtRSI;
          binary_expand_op(&b_st, a_cdf, cb_emlrtRSI, dist_new, dist);
        }
        b_st.site = &cc_emlrtRSI;
        c_st.site = &uc_emlrtRSI;
        e_st.site = &vc_emlrtRSI;
        if (a_cdf.size(1) < 1) {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &h_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        f_st.site = &bd_emlrtRSI;
        g_st.site = &cd_emlrtRSI;
        nx = a_cdf.size(1);
        if (a_cdf.size(1) <= 2) {
          if (a_cdf.size(1) == 1) {
            b_error = a_cdf[0];
          } else if ((a_cdf[0] < a_cdf[1]) ||
                     (muDoubleScalarIsNaN(a_cdf[0]) &&
                      (!muDoubleScalarIsNaN(a_cdf[1])))) {
            b_error = a_cdf[1];
          } else {
            b_error = a_cdf[0];
          }
        } else {
          h_st.site = &ed_emlrtRSI;
          if (!muDoubleScalarIsNaN(a_cdf[0])) {
            idx = 1;
          } else {
            boolean_T exitg4;
            idx = 0;
            i_st.site = &fd_emlrtRSI;
            if (a_cdf.size(1) > 2147483646) {
              j_st.site = &vb_emlrtRSI;
              coder::check_forloop_overflow_error(&j_st);
            }
            k = 2;
            exitg4 = false;
            while ((!exitg4) && (k <= nx)) {
              if (!muDoubleScalarIsNaN(a_cdf[k - 1])) {
                idx = k;
                exitg4 = true;
              } else {
                k++;
              }
            }
          }
          if (idx == 0) {
            b_error = a_cdf[0];
          } else {
            h_st.site = &dd_emlrtRSI;
            b_error = a_cdf[idx - 1];
            b_loop_ub = idx + 1;
            i_st.site = &gd_emlrtRSI;
            if ((idx + 1 <= a_cdf.size(1)) && (a_cdf.size(1) > 2147483646)) {
              j_st.site = &vb_emlrtRSI;
              coder::check_forloop_overflow_error(&j_st);
            }
            for (k = b_loop_ub; k <= nx; k++) {
              b_varargin_2 = a_cdf[k - 1];
              if (b_error < b_varargin_2) {
                b_error = b_varargin_2;
              }
            }
          }
        }
        if (b_error < dist_tol) {
          st.site = &db_emlrtRSI;
          b_st.site = &hd_emlrtRSI;
          c_st.site = &bg_emlrtRSI;
          d_st.site = &cg_emlrtRSI;
          emlrt_marshallIn(
              &c_st,
              feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                    c_emlrt_marshallOut(&d_st, cv4),
                    emlrt_marshallOut(static_cast<real_T>(i) + 1.0), &emlrtMCI),
              "<output of feval>");
          exitg3 = true;
        } else {
          dist.set_size(&fd_emlrtRTEI, sp, 1, dist_new.size(1));
          b_loop_ub = dist_new.size(1);
          for (k = 0; k < b_loop_ub; k++) {
            dist[k] = dist_new[k];
          }
          i++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtCTX)sp);
          }
        }
      }
      st.site = &eb_emlrtRSI;
      nx = cap_contemp.size(0) * cap_contemp.size(1);
      b_v_p = cap_contemp.reshape(nx);
      b_st.site = &pc_emlrtRSI;
      coder::dynamic_size_checks(&b_st, dist, b_v_p, dist.size(1),
                                 cap_contemp.size(0) * cap_contemp.size(1));
      nx = cap_contemp.size(0) * cap_contemp.size(1);
      b_v_p = cap_contemp.reshape(nx);
      st.site = &fb_emlrtRSI;
      b_error = coder::mpower(
          &st, d_0 / coder::internal::blas::mtimes(dist, b_v_p), 1.0 / e_p);
      b_error -= *p_E;
      if (muDoubleScalarAbs(b_error) < dem_tol) {
        st.site = &gb_emlrtRSI;
        b_st.site = &hd_emlrtRSI;
        c_st.site = &bg_emlrtRSI;
        d_st.site = &cg_emlrtRSI;
        emlrt_marshallIn(
            &c_st,
            feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                  d_emlrt_marshallOut(&d_st, cv2), emlrt_marshallOut(*p_E),
                  emlrt_marshallOut(static_cast<real_T>(b_k) + 1.0), &emlrtMCI),
            "<output of feval>");
        exitg2 = true;
      } else {
        *p_E += 0.2 * b_error /
                muDoubleScalarCeil((static_cast<real_T>(b_k) + 1.0) / 10.0);
        b_k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtCTX)sp);
        }
      }
    }
    if (1 > v_new_resh.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, v_new_resh.size(0), &s_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &hb_emlrtRSI;
    b_loop_ub = v_new_resh.size(1);
    b_v.set_size(&gd_emlrtRTEI, &st, 1, v_new_resh.size(1));
    for (k = 0; k < b_loop_ub; k++) {
      b_v[k] = v_new_resh[v_new_resh.size(0) * k];
    }
    b_st.site = &pc_emlrtRSI;
    coder::b_dynamic_size_checks(&b_st, a_prob, b_v, a_prob.size(1),
                                 v_new_resh.size(1));
    b_loop_ub = v_new_resh.size(1);
    b_v.set_size(&gd_emlrtRTEI, sp, 1, v_new_resh.size(1));
    for (k = 0; k < b_loop_ub; k++) {
      b_v[k] = v_new_resh[v_new_resh.size(0) * k];
    }
    b_error = coder::internal::blas::mtimes(a_prob, b_v) - c_of_e;
    if (muDoubleScalarAbs(b_error) < dem_tol) {
      st.site = &ib_emlrtRSI;
      b_st.site = &hd_emlrtRSI;
      c_st.site = &bg_emlrtRSI;
      d_st.site = &cg_emlrtRSI;
      emlrt_marshallIn(
          &c_st,
          feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                e_emlrt_marshallOut(&d_st, cv1), emlrt_marshallOut(b_error),
                emlrt_marshallOut(static_cast<real_T>(h) + 1.0), &emlrtMCI),
          "<output of feval>");
      exitg1 = true;
    } else {
      if (b_error > -5.0) {
        *m_of_firms *= 0.1 * b_error + 1.0;
      } else {
        *m_of_firms *= 0.05 * b_error + 1.0;
      }
      h++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
  }
  st.site = &jb_emlrtRSI;
  b_st.site = &pc_emlrtRSI;
  coder::dynamic_size_checks(&b_st, v_p, a_prob, v_p.size(1), a_prob.size(1));
  b_st.site = &oc_emlrtRSI;
  coder::internal::blas::mtimes(&b_st, v_p, a_prob, trans_prob);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (One_tech_ss.cpp)
