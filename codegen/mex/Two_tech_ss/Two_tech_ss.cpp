//
// Two_tech_ss.cpp
//
// Code generation for function 'Two_tech_ss'
//

// Include files
#include "Two_tech_ss.h"
#include "Two_tech_ss_data.h"
#include "Two_tech_ss_mexutil.h"
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
    7,                              // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    8,                              // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    14,                             // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    23,                             // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    30,                             // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    48,                             // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    53,                             // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    87,                             // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    90,                             // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    98,                             // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    101,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    125,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    126,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    130,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    133,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    143,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    144,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    149,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    153,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    174,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    175,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    179,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    182,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    192,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    193,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    198,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    202,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    214,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    215,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    216,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    217,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    218,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    219,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    222,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    223,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    224,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    225,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    226,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    227,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo ob_emlrtRSI{
    236,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo pb_emlrtRSI{
    239,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo qb_emlrtRSI{
    235,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo rb_emlrtRSI{
    248,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    249,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    250,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo ub_emlrtRSI{
    252,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo vb_emlrtRSI{
    238,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo wb_emlrtRSI{
    260,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo xb_emlrtRSI{
    261,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    262,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    264,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    271,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    273,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo dc_emlrtRSI{
    278,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo ec_emlrtRSI{
    285,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo fc_emlrtRSI{
    287,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo gc_emlrtRSI{
    290,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    307,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo ic_emlrtRSI{
    308,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo bd_emlrtRSI{
    15,    // lineNo
    "max", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" // pathName
};

static emlrtRSInfo
    cd_emlrtRSI{
        29,         // lineNo
        "minOrMax", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo
    dd_emlrtRSI{
        58,         // lineNo
        "maximum2", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo ed_emlrtRSI{
    63,               // lineNo
    "binaryMinOrMax", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\binaryMinOrMax.m" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    57,      // lineNo
    "ixfun", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" // pathName
};

static emlrtRSInfo gd_emlrtRSI{
    102,                          // lineNo
    "binaryImplicitExpansionFun", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    29,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    109,               // lineNo
    "computeDimsData", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

static emlrtRSInfo
    jd_emlrtRSI{
        90,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

static emlrtRSInfo
    kd_emlrtRSI{
        69,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

static emlrtRSInfo
    pd_emlrtRSI{
        44,         // lineNo
        "minOrMax", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo
    qd_emlrtRSI{
        79,        // lineNo
        "maximum", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" // pathName
    };

static emlrtRSInfo rd_emlrtRSI{
    62,              // lineNo
    "unaryMinOrMax", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" // pathName
};

static emlrtRSInfo ce_emlrtRSI{
    38,        // lineNo
    "fprintf", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo
    eg_emlrtRSI{
        28,      // lineNo
        "colon", // fcnName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pathName
    };

static emlrtRSInfo
    fg_emlrtRSI{
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
    9,                               // lineNo
    18,                              // colNo
    "a_cdf",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo emlrtDCI{
    9,                               // lineNo
    20,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    9,                               // lineNo
    20,                              // colNo
    "a_cdf",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo emlrtECI{
    2,                              // nDims
    9,                              // lineNo
    11,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtDCInfo b_emlrtDCI{
    27,                              // lineNo
    26,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    34,                              // lineNo
    26,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtRTEInfo emlrtRTEI{
    85,                             // lineNo
    7,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    86,                             // lineNo
    11,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    110,                            // lineNo
    16,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtBCInfo c_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    113,                             // lineNo
    45,                              // colNo
    "v_p_n",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    113,                             // lineNo
    47,                              // colNo
    "v_p_n",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    113,                             // lineNo
    21,                              // colNo
    "v_p_n",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    113,                             // lineNo
    23,                              // colNo
    "v_p_n",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo b_emlrtECI{
    -1,                             // nDims
    113,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtBCInfo g_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    114,                             // lineNo
    21,                              // colNo
    "v_p_n",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    126,                             // lineNo
    65,                              // colNo
    "v_of_new",                      // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo c_emlrtECI{
    1,                              // nDims
    136,                            // lineNo
    34,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo d_emlrtECI{
    1,                              // nDims
    141,                            // lineNo
    33,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo e_emlrtECI{
    1,                              // nDims
    145,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo f_emlrtECI{
    2,                              // nDims
    145,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo g_emlrtECI{
    1,                              // nDims
    149,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo h_emlrtECI{
    2,                              // nDims
    149,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    160,                            // lineNo
    16,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtBCInfo i_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    162,                             // lineNo
    45,                              // colNo
    "v_p_o",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    162,                             // lineNo
    47,                              // colNo
    "v_p_o",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    162,                             // lineNo
    21,                              // colNo
    "v_p_o",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    162,                             // lineNo
    23,                              // colNo
    "v_p_o",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo i_emlrtECI{
    -1,                             // nDims
    162,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtBCInfo m_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    163,                             // lineNo
    21,                              // colNo
    "v_p_o",                         // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    175,                             // lineNo
    65,                              // colNo
    "v_of_old",                      // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo j_emlrtECI{
    1,                              // nDims
    185,                            // lineNo
    34,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo k_emlrtECI{
    1,                              // nDims
    190,                            // lineNo
    33,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo l_emlrtECI{
    1,                              // nDims
    194,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo m_emlrtECI{
    2,                              // nDims
    194,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo n_emlrtECI{
    1,                              // nDims
    198,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo o_emlrtECI{
    2,                              // nDims
    198,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo p_emlrtECI{
    1,                              // nDims
    215,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo q_emlrtECI{
    2,                              // nDims
    215,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo r_emlrtECI{
    1,                              // nDims
    216,                            // lineNo
    47,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo s_emlrtECI{
    2,                              // nDims
    216,                            // lineNo
    47,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo t_emlrtECI{
    2,                              // nDims
    217,                            // lineNo
    44,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtBCInfo o_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    219,                             // lineNo
    60,                              // colNo
    "prob_of_naot_n",                // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    219,                             // lineNo
    62,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    219,                             // lineNo
    62,                              // colNo
    "prob_of_naot_n",                // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    220,                             // lineNo
    29,                              // colNo
    "exit_vec_n",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    220,                             // lineNo
    31,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    220,                             // lineNo
    31,                              // colNo
    "exit_vec_n",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    220,                             // lineNo
    51,                              // colNo
    "exit_vec_n",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo u_emlrtECI{
    1,                              // nDims
    219,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo v_emlrtECI{
    1,                              // nDims
    223,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo w_emlrtECI{
    2,                              // nDims
    223,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo x_emlrtECI{
    1,                              // nDims
    224,                            // lineNo
    47,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo y_emlrtECI{
    2,                              // nDims
    224,                            // lineNo
    47,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo ab_emlrtECI{
    2,                              // nDims
    225,                            // lineNo
    44,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtBCInfo t_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    227,                             // lineNo
    60,                              // colNo
    "prob_of_naot_o",                // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    227,                             // lineNo
    62,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    227,                             // lineNo
    62,                              // colNo
    "prob_of_naot_o",                // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    228,                             // lineNo
    29,                              // colNo
    "exit_vec_o",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo g_emlrtDCI{
    228,                             // lineNo
    31,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    228,                             // lineNo
    31,                              // colNo
    "exit_vec_o",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    228,                             // lineNo
    51,                              // colNo
    "exit_vec_o",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo bb_emlrtECI{
    1,                              // nDims
    227,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtDCInfo h_emlrtDCI{
    236,                             // lineNo
    57,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    236,                             // lineNo
    57,                              // colNo
    "exit_vec_n",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo i_emlrtDCI{
    236,                             // lineNo
    79,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo ab_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    236,                             // lineNo
    79,                              // colNo
    "exit_vec_n",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    236,                             // lineNo
    97,                              // colNo
    "exit_vec_n",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo cb_emlrtECI{
    1,                              // nDims
    236,                            // lineNo
    17,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtDCInfo j_emlrtDCI{
    239,                             // lineNo
    57,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo cb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    239,                             // lineNo
    57,                              // colNo
    "exit_vec_o",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo k_emlrtDCI{
    239,                             // lineNo
    79,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo db_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    239,                             // lineNo
    79,                              // colNo
    "exit_vec_o",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    239,                             // lineNo
    97,                              // colNo
    "exit_vec_o",                    // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo db_emlrtECI{
    1,                              // nDims
    239,                            // lineNo
    17,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo e_emlrtRTEI{
    247,                            // lineNo
    15,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtBCInfo fb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    244,                             // lineNo
    18,                              // colNo
    "dist_ent",                      // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo gb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    244,                             // lineNo
    20,                              // colNo
    "dist_ent",                      // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtECInfo eb_emlrtECI{
    2,                              // nDims
    249,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo fb_emlrtECI{
    2,                              // nDims
    250,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    259,                            // lineNo
    15,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo gb_emlrtECI{
    2,                              // nDims
    261,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtECInfo hb_emlrtECI{
    2,                              // nDims
    262,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtBCInfo hb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    285,                             // lineNo
    42,                              // colNo
    "v_new_resh_n",                  // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo ib_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    287,                             // lineNo
    42,                              // colNo
    "v_new_resh_o",                  // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtRTEInfo g_emlrtRTEI{
    52,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo h_emlrtRTEI{
    59,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

static emlrtDCInfo l_emlrtDCI{
    18,                              // lineNo
    27,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo m_emlrtDCI{
    18,                              // lineNo
    27,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtDCInfo n_emlrtDCI{
    18,                              // lineNo
    43,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo o_emlrtDCI{
    18,                              // lineNo
    43,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtDCInfo p_emlrtDCI{
    19,                              // lineNo
    27,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo q_emlrtDCI{
    24,                              // lineNo
    28,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo r_emlrtDCI{
    26,                              // lineNo
    26,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo s_emlrtDCI{
    26,                              // lineNo
    26,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtDCInfo t_emlrtDCI{
    31,                              // lineNo
    28,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo u_emlrtDCI{
    33,                              // lineNo
    26,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo v_emlrtDCI{
    241,                             // lineNo
    49,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo w_emlrtDCI{
    242,                             // lineNo
    49,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo x_emlrtDCI{
    243,                             // lineNo
    35,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo y_emlrtDCI{
    18,                              // lineNo
    1,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo ab_emlrtDCI{
    19,                              // lineNo
    1,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo bb_emlrtDCI{
    24,                              // lineNo
    1,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo cb_emlrtDCI{
    25,                              // lineNo
    1,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo db_emlrtDCI{
    26,                              // lineNo
    1,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo eb_emlrtDCI{
    31,                              // lineNo
    1,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo fb_emlrtDCI{
    32,                              // lineNo
    1,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo gb_emlrtDCI{
    33,                              // lineNo
    1,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtBCInfo jb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    66,                              // lineNo
    1,                               // colNo
    "pi_contemp_new",                // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo kb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    69,                              // lineNo
    1,                               // colNo
    "pi_contemp_old",                // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo lb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    96,                              // lineNo
    9,                               // colNo
    "pi_contemp_new",                // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo mb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    106,                             // lineNo
    9,                               // colNo
    "pi_contemp_old",                // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo hb_emlrtDCI{
    218,                             // lineNo
    49,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo ib_emlrtDCI{
    218,                             // lineNo
    49,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtBCInfo nb_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    147,                             // lineNo
    13,                              // colNo
    "v_new_resh_n",                  // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtBCInfo ob_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    196,                             // lineNo
    13,                              // colNo
    "v_new_resh_o",                  // aName
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    0                                // checkKind
};

static emlrtDCInfo jb_emlrtDCI{
    226,                             // lineNo
    49,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo kb_emlrtDCI{
    226,                             // lineNo
    49,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    4                                // checkKind
};

static emlrtDCInfo lb_emlrtDCI{
    241,                             // lineNo
    42,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo mb_emlrtDCI{
    242,                             // lineNo
    42,                              // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtDCInfo nb_emlrtDCI{
    243,                             // lineNo
    9,                               // colNo
    "Two_tech_ss",                   // fName
    "D:\\AMR_github\\Two_tech_ss.m", // pName
    1                                // checkKind
};

static emlrtRTEInfo fb_emlrtRTEI{
    9,                              // lineNo
    11,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    9,                              // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    14,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    18,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    19,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    24,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo lb_emlrtRTEI{
    25,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    26,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo nb_emlrtRTEI{
    27,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    31,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    32,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    33,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo rb_emlrtRTEI{
    34,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo sb_emlrtRTEI{
    48,                             // lineNo
    24,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo tb_emlrtRTEI{
    53,                             // lineNo
    24,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ub_emlrtRTEI{
    4,                              // lineNo
    5,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo vb_emlrtRTEI{
    74,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo wb_emlrtRTEI{
    75,                             // lineNo
    1,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo xb_emlrtRTEI{
    87,                             // lineNo
    32,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo yb_emlrtRTEI{
    90,                             // lineNo
    33,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ac_emlrtRTEI{
    90,                             // lineNo
    9,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    95,                             // lineNo
    9,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    98,                             // lineNo
    32,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    101,                            // lineNo
    33,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    101,                            // lineNo
    9,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo fc_emlrtRTEI{
    105,                            // lineNo
    9,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo gc_emlrtRTEI{
    112,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    113,                            // lineNo
    37,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ic_emlrtRTEI{
    125,                            // lineNo
    44,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo jc_emlrtRTEI{
    126,                            // lineNo
    34,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo kc_emlrtRTEI{
    126,                            // lineNo
    56,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo lc_emlrtRTEI{
    127,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo mc_emlrtRTEI{
    130,                            // lineNo
    33,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo nc_emlrtRTEI{
    130,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo oc_emlrtRTEI{
    133,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo pc_emlrtRTEI{
    136,                            // lineNo
    31,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo qc_emlrtRTEI{
    136,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo rc_emlrtRTEI{
    139,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo sc_emlrtRTEI{
    140,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo tc_emlrtRTEI{
    141,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo uc_emlrtRTEI{
    145,                            // lineNo
    46,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo vc_emlrtRTEI{
    145,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo wc_emlrtRTEI{
    149,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo xc_emlrtRTEI{
    157,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo yc_emlrtRTEI{
    161,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ad_emlrtRTEI{
    162,                            // lineNo
    37,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo bd_emlrtRTEI{
    174,                            // lineNo
    44,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo cd_emlrtRTEI{
    175,                            // lineNo
    34,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo dd_emlrtRTEI{
    175,                            // lineNo
    56,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ed_emlrtRTEI{
    176,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo fd_emlrtRTEI{
    179,                            // lineNo
    33,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo gd_emlrtRTEI{
    179,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo hd_emlrtRTEI{
    182,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo id_emlrtRTEI{
    185,                            // lineNo
    31,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo jd_emlrtRTEI{
    185,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo kd_emlrtRTEI{
    188,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ld_emlrtRTEI{
    189,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo md_emlrtRTEI{
    190,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo nd_emlrtRTEI{
    194,                            // lineNo
    46,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo od_emlrtRTEI{
    194,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo pd_emlrtRTEI{
    198,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo qd_emlrtRTEI{
    206,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo rd_emlrtRTEI{
    215,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo
    sd_emlrtRTEI{
        28,      // lineNo
        9,       // colNo
        "colon", // fName
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" // pName
    };

static emlrtRTEInfo td_emlrtRTEI{
    216,                            // lineNo
    47,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ud_emlrtRTEI{
    217,                            // lineNo
    63,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo vd_emlrtRTEI{
    217,                            // lineNo
    44,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo wd_emlrtRTEI{
    218,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo xd_emlrtRTEI{
    218,                            // lineNo
    42,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo yd_emlrtRTEI{
    218,                            // lineNo
    37,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ae_emlrtRTEI{
    220,                            // lineNo
    16,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo be_emlrtRTEI{
    219,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ce_emlrtRTEI{
    223,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo de_emlrtRTEI{
    224,                            // lineNo
    47,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ee_emlrtRTEI{
    225,                            // lineNo
    63,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo fe_emlrtRTEI{
    225,                            // lineNo
    44,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ge_emlrtRTEI{
    226,                            // lineNo
    42,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo he_emlrtRTEI{
    226,                            // lineNo
    37,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ie_emlrtRTEI{
    228,                            // lineNo
    16,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo je_emlrtRTEI{
    227,                            // lineNo
    43,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ke_emlrtRTEI{
    236,                            // lineNo
    44,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo le_emlrtRTEI{
    236,                            // lineNo
    17,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo me_emlrtRTEI{
    239,                            // lineNo
    44,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ne_emlrtRTEI{
    239,                            // lineNo
    17,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo oe_emlrtRTEI{
    241,                            // lineNo
    42,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo pe_emlrtRTEI{
    241,                            // lineNo
    9,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo qe_emlrtRTEI{
    242,                            // lineNo
    42,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo re_emlrtRTEI{
    242,                            // lineNo
    9,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo se_emlrtRTEI{
    243,                            // lineNo
    9,                              // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo te_emlrtRTEI{
    249,                            // lineNo
    42,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ue_emlrtRTEI{
    249,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ve_emlrtRTEI{
    250,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo we_emlrtRTEI{
    255,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo xe_emlrtRTEI{
    261,                            // lineNo
    42,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo ye_emlrtRTEI{
    261,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo af_emlrtRTEI{
    262,                            // lineNo
    35,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo bf_emlrtRTEI{
    267,                            // lineNo
    13,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo cf_emlrtRTEI{
    285,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo df_emlrtRTEI{
    287,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo bg_emlrtRTEI{
    261,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo cg_emlrtRTEI{
    194,                            // lineNo
    29,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRTEInfo dg_emlrtRTEI{
    190,                            // lineNo
    33,                             // colNo
    "Two_tech_ss",                  // fName
    "D:\\AMR_github\\Two_tech_ss.m" // pName
};

static emlrtRSInfo xg_emlrtRSI{
    66,        // lineNo
    "fprintf", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo yg_emlrtRSI{
    68,        // lineNo
    "fprintf", // fcnName
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo ah_emlrtRSI{
    145,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo bh_emlrtRSI{
    194,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo ch_emlrtRSI{
    141,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo dh_emlrtRSI{
    190,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo eh_emlrtRSI{
    136,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo fh_emlrtRSI{
    185,                            // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

static emlrtRSInfo gh_emlrtRSI{
    9,                              // lineNo
    "Two_tech_ss",                  // fcnName
    "D:\\AMR_github\\Two_tech_ss.m" // pathName
};

// Function Declarations
static void b_binary_expand_op(const emlrtStack *sp, emlrtRSInfo ih_emlrtRSI,
                               coder::sparse *trans_matrix_o,
                               const coder::array<real_T, 2U> &v_n_adopt,
                               const coder::array<boolean_T, 2U> &exit_vec_o,
                               const coder::array<real_T, 2U> &dist_ent);

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[50]);

static void b_plus(const emlrtStack *sp, coder::array<real_T, 2U> &v_new_resh_o,
                   const coder::array<real_T, 2U> &pi_contemp_old);

static void binary_expand_op(const emlrtStack *sp, coder::array<real_T, 2U> &a,
                             emlrtRSInfo ih_emlrtRSI,
                             const coder::array<real_T, 2U> &a_cdf,
                             const coder::array<real_T, 2U> &dist_o);

static void binary_expand_op(const emlrtStack *sp, emlrtRSInfo ih_emlrtRSI,
                             coder::sparse *trans_matrix_o,
                             const coder::array<real_T, 2U> &v_n_adopt,
                             const coder::array<real_T, 1U> &v_n_best,
                             const coder::array<real_T, 2U> &dist_ent,
                             const coder::array<real_T, 2U> &a_cdf);

static void binary_expand_op(const emlrtStack *sp, emlrtRSInfo ih_emlrtRSI,
                             coder::sparse *trans_matrix_o,
                             const coder::array<real_T, 1U> &v_p_n_expand,
                             int32_T i1,
                             const coder::array<real_T, 1U> &v_n_best,
                             const coder::array<real_T, 2U> &a_cdf,
                             const coder::array<real_T, 2U> &a);

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 1U> &v_p_n_expand,
                             emlrtRSInfo ih_emlrtRSI,
                             const coder::array<real_T, 2U> &v_p_o,
                             const coder::array<real_T, 2U> &v_n_adopt);

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 2U> &v_p_o,
                             const coder::array<real_T, 2U> &v_n_adopt);

static void c_binary_expand_op(const emlrtStack *sp,
                               coder::array<real_T, 2U> &v_n_adopt,
                               emlrtRSInfo ih_emlrtRSI,
                               const coder::array<real_T, 2U> &v_of_old,
                               const coder::array<real_T, 2U> &v_new_resh_o);

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[48]);

static void
d_binary_expand_op(const emlrtStack *sp, coder::array<real_T, 2U> &v_p_o,
                   const coder::array<boolean_T, 2U> &pi_contemp_neg_new);

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[77]);

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[97]);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const char_T u[7]);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, emlrtMCInfo *location);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            emlrtMCInfo *location);

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            const mxArray *m6, emlrtMCInfo *location);

static void minus(const emlrtStack *sp, coder::array<real_T, 2U> &a_prob,
                  const coder::array<real_T, 2U> &a_cdf);

static void plus(const emlrtStack *sp, coder::array<real_T, 2U> &a_cdf,
                 const coder::array<real_T, 2U> &r);

static void times(const emlrtStack *sp, coder::array<real_T, 2U> &v_n_adopt,
                  const coder::array<real_T, 2U> &v_p_o);

// Function Definitions
static void b_binary_expand_op(const emlrtStack *sp, emlrtRSInfo ih_emlrtRSI,
                               coder::sparse *trans_matrix_o,
                               const coder::array<real_T, 2U> &v_n_adopt,
                               const coder::array<boolean_T, 2U> &exit_vec_o,
                               const coder::array<real_T, 2U> &dist_ent)
{
  coder::array<real_T, 2U> b_v_n_adopt;
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
  if (exit_vec_o.size(0) == 1) {
    i = v_n_adopt.size(0);
  } else {
    i = exit_vec_o.size(0);
  }
  if (exit_vec_o.size(1) == 1) {
    i1 = v_n_adopt.size(1);
  } else {
    i1 = exit_vec_o.size(1);
  }
  b_v_n_adopt.set_size(&ce_emlrtRTEI, sp, i, i1);
  stride_0_0 = (v_n_adopt.size(0) != 1);
  stride_0_1 = (v_n_adopt.size(1) != 1);
  stride_1_0 = (exit_vec_o.size(0) != 1);
  stride_1_1 = (exit_vec_o.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (exit_vec_o.size(1) == 1) {
    loop_ub = v_n_adopt.size(1);
  } else {
    loop_ub = exit_vec_o.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    if (exit_vec_o.size(0) == 1) {
      b_loop_ub = v_n_adopt.size(0);
    } else {
      b_loop_ub = exit_vec_o.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_v_n_adopt[i1 + b_v_n_adopt.size(0) * i] =
          v_n_adopt[i1 * stride_0_0 + v_n_adopt.size(0) * aux_0_1] *
          (1.0 -
           static_cast<real_T>(
               exit_vec_o[i1 * stride_1_0 + exit_vec_o.size(0) * aux_1_1]));
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = &ih_emlrtRSI;
  trans_matrix_o->parenAssign(&st, b_v_n_adopt, dist_ent);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[50])
{
  static const int32_T iv[2]{1, 50};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 50, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void b_plus(const emlrtStack *sp, coder::array<real_T, 2U> &v_new_resh_o,
                   const coder::array<real_T, 2U> &pi_contemp_old)
{
  coder::array<real_T, 2U> b_pi_contemp_old;
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
  if (v_new_resh_o.size(0) == 1) {
    i = pi_contemp_old.size(0);
  } else {
    i = v_new_resh_o.size(0);
  }
  if (v_new_resh_o.size(1) == 1) {
    i1 = pi_contemp_old.size(1);
  } else {
    i1 = v_new_resh_o.size(1);
  }
  b_pi_contemp_old.set_size(&cg_emlrtRTEI, sp, i, i1);
  stride_0_0 = (pi_contemp_old.size(0) != 1);
  stride_0_1 = (pi_contemp_old.size(1) != 1);
  stride_1_0 = (v_new_resh_o.size(0) != 1);
  stride_1_1 = (v_new_resh_o.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (v_new_resh_o.size(1) == 1) {
    loop_ub = pi_contemp_old.size(1);
  } else {
    loop_ub = v_new_resh_o.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    if (v_new_resh_o.size(0) == 1) {
      b_loop_ub = pi_contemp_old.size(0);
    } else {
      b_loop_ub = v_new_resh_o.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_pi_contemp_old[i1 + b_pi_contemp_old.size(0) * i] =
          pi_contemp_old[i1 * stride_0_0 + pi_contemp_old.size(0) * aux_0_1] +
          v_new_resh_o[i1 * stride_1_0 + v_new_resh_o.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  v_new_resh_o.set_size(&cg_emlrtRTEI, sp, b_pi_contemp_old.size(0),
                        b_pi_contemp_old.size(1));
  loop_ub = b_pi_contemp_old.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_pi_contemp_old.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      v_new_resh_o[i1 + v_new_resh_o.size(0) * i] =
          b_pi_contemp_old[i1 + b_pi_contemp_old.size(0) * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, coder::array<real_T, 2U> &a,
                             emlrtRSInfo ih_emlrtRSI,
                             const coder::array<real_T, 2U> &a_cdf,
                             const coder::array<real_T, 2U> &dist_o)
{
  coder::array<real_T, 2U> b_a_cdf;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (dist_o.size(1) == 1) {
    i = a_cdf.size(1);
  } else {
    i = dist_o.size(1);
  }
  b_a_cdf.set_size(&af_emlrtRTEI, sp, 1, i);
  stride_0_1 = (a_cdf.size(1) != 1);
  stride_1_1 = (dist_o.size(1) != 1);
  if (dist_o.size(1) == 1) {
    loop_ub = a_cdf.size(1);
  } else {
    loop_ub = dist_o.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_a_cdf[i] = a_cdf[i * stride_0_1] - dist_o[i * stride_1_1];
  }
  st.site = &ih_emlrtRSI;
  coder::c_abs(&st, b_a_cdf, a);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, emlrtRSInfo ih_emlrtRSI,
                             coder::sparse *trans_matrix_o,
                             const coder::array<real_T, 2U> &v_n_adopt,
                             const coder::array<real_T, 1U> &v_n_best,
                             const coder::array<real_T, 2U> &dist_ent,
                             const coder::array<real_T, 2U> &a_cdf)
{
  coder::array<real_T, 2U> b_v_n_adopt;
  emlrtStack st;
  int32_T b_v_n_best_idx_0;
  int32_T loop_ub;
  int32_T stride_1_0;
  int32_T v_n_best_idx_0;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  v_n_best_idx_0 = v_n_best.size(0);
  if (v_n_best_idx_0 == 1) {
    b_v_n_best_idx_0 = v_n_adopt.size(0);
  } else {
    b_v_n_best_idx_0 = v_n_best_idx_0;
  }
  b_v_n_adopt.set_size(&ne_emlrtRTEI, sp, b_v_n_best_idx_0, v_n_adopt.size(1));
  b_v_n_best_idx_0 = (v_n_adopt.size(0) != 1);
  stride_1_0 = (v_n_best_idx_0 != 1);
  loop_ub = v_n_adopt.size(1);
  for (int32_T i{0}; i < loop_ub; i++) {
    int32_T b_loop_ub;
    if (v_n_best_idx_0 == 1) {
      b_loop_ub = v_n_adopt.size(0);
    } else {
      b_loop_ub = v_n_best_idx_0;
    }
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      b_v_n_adopt[i1 + b_v_n_adopt.size(0) * i] =
          v_n_adopt[i1 * b_v_n_best_idx_0 + v_n_adopt.size(0) * i] *
          (1.0 - v_n_best[i1 * stride_1_0]);
    }
  }
  st.site = &ih_emlrtRSI;
  trans_matrix_o->parenAssign(&st, b_v_n_adopt, dist_ent, a_cdf);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, emlrtRSInfo ih_emlrtRSI,
                             coder::sparse *trans_matrix_o,
                             const coder::array<real_T, 1U> &v_p_n_expand,
                             int32_T i1,
                             const coder::array<real_T, 1U> &v_n_best,
                             const coder::array<real_T, 2U> &a_cdf,
                             const coder::array<real_T, 2U> &a)
{
  coder::array<real_T, 2U> b_a_cdf;
  coder::array<real_T, 1U> b_v_p_n_expand;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (v_n_best.size(0) == 1) {
    i = i1 + 1;
  } else {
    i = v_n_best.size(0);
  }
  b_v_p_n_expand.set_size(&je_emlrtRTEI, sp, i);
  stride_0_0 = (i1 + 1 != 1);
  stride_1_0 = (v_n_best.size(0) != 1);
  if (v_n_best.size(0) == 1) {
    loop_ub = i1 + 1;
  } else {
    loop_ub = v_n_best.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_v_p_n_expand[i] =
        v_p_n_expand[i * stride_0_0] * (1.0 - v_n_best[i * stride_1_0]);
  }
  if (a.size(1) == 1) {
    i = a_cdf.size(1);
  } else {
    i = a.size(1);
  }
  b_a_cdf.set_size(&fe_emlrtRTEI, sp, 1, i);
  stride_0_0 = (a_cdf.size(1) != 1);
  stride_1_0 = (a.size(1) != 1);
  if (a.size(1) == 1) {
    loop_ub = a_cdf.size(1);
  } else {
    loop_ub = a.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_a_cdf[i] = a_cdf[i * stride_0_0] + a[i * stride_1_0];
  }
  st.site = &ih_emlrtRSI;
  trans_matrix_o->parenAssign(&st, b_v_p_n_expand, b_a_cdf);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 1U> &v_p_n_expand,
                             emlrtRSInfo ih_emlrtRSI,
                             const coder::array<real_T, 2U> &v_p_o,
                             const coder::array<real_T, 2U> &v_n_adopt)
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
  if (v_n_adopt.size(0) == 1) {
    i = v_p_o.size(0);
  } else {
    i = v_n_adopt.size(0);
  }
  if (v_n_adopt.size(1) == 1) {
    i1 = v_p_o.size(1);
  } else {
    i1 = v_n_adopt.size(1);
  }
  r.set_size(&de_emlrtRTEI, sp, i, i1);
  stride_0_0 = (v_p_o.size(0) != 1);
  stride_0_1 = (v_p_o.size(1) != 1);
  stride_1_0 = (v_n_adopt.size(0) != 1);
  stride_1_1 = (v_n_adopt.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (v_n_adopt.size(1) == 1) {
    loop_ub = v_p_o.size(1);
  } else {
    loop_ub = v_n_adopt.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    if (v_n_adopt.size(0) == 1) {
      b_loop_ub = v_p_o.size(0);
    } else {
      b_loop_ub = v_n_adopt.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      r[i1 + r.size(0) * i] =
          (1.0 - v_p_o[i1 * stride_0_0 + v_p_o.size(0) * aux_0_1]) *
          v_n_adopt[i1 * stride_1_0 + v_n_adopt.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = &ih_emlrtRSI;
  coder::sum(&st, r, v_p_n_expand);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp,
                             coder::array<real_T, 2U> &v_p_o,
                             const coder::array<real_T, 2U> &v_n_adopt)
{
  coder::array<real_T, 2U> r;
  int32_T b_loop_ub;
  int32_T b_v_p_o_idx_0;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_1_0;
  int32_T v_p_o_idx_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  v_p_o_idx_0 = v_p_o.size(0) * v_p_o.size(1);
  if (v_p_o_idx_0 == 1) {
    b_v_p_o_idx_0 = v_n_adopt.size(0);
  } else {
    b_v_p_o_idx_0 = v_p_o_idx_0;
  }
  r.set_size(&id_emlrtRTEI, sp, b_v_p_o_idx_0, v_n_adopt.size(1));
  b_v_p_o_idx_0 = (v_n_adopt.size(0) != 1);
  stride_1_0 = (v_p_o_idx_0 != 1);
  loop_ub = v_n_adopt.size(1);
  for (i = 0; i < loop_ub; i++) {
    if (v_p_o_idx_0 == 1) {
      b_loop_ub = v_n_adopt.size(0);
    } else {
      b_loop_ub = v_p_o_idx_0;
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      r[i1 + r.size(0) * i] =
          1.0 - static_cast<real_T>(
                    v_n_adopt[i1 * b_v_p_o_idx_0 + v_n_adopt.size(0) * i] ==
                    v_p_o[i1 * stride_1_0]);
    }
  }
  v_p_o.set_size(&id_emlrtRTEI, sp, r.size(0), r.size(1));
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = r.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      v_p_o[i1 + v_p_o.size(0) * i] = r[i1 + r.size(0) * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void c_binary_expand_op(const emlrtStack *sp,
                               coder::array<real_T, 2U> &v_n_adopt,
                               emlrtRSInfo ih_emlrtRSI,
                               const coder::array<real_T, 2U> &v_of_old,
                               const coder::array<real_T, 2U> &v_new_resh_o)
{
  coder::array<real_T, 2U> b_v_of_old;
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
  if (v_new_resh_o.size(0) == 1) {
    i = v_of_old.size(0);
  } else {
    i = v_new_resh_o.size(0);
  }
  if (v_new_resh_o.size(1) == 1) {
    i1 = v_of_old.size(1);
  } else {
    i1 = v_new_resh_o.size(1);
  }
  b_v_of_old.set_size(&pd_emlrtRTEI, sp, i, i1);
  stride_0_0 = (v_of_old.size(0) != 1);
  stride_0_1 = (v_of_old.size(1) != 1);
  stride_1_0 = (v_new_resh_o.size(0) != 1);
  stride_1_1 = (v_new_resh_o.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (v_new_resh_o.size(1) == 1) {
    loop_ub = v_of_old.size(1);
  } else {
    loop_ub = v_new_resh_o.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int32_T b_loop_ub;
    if (v_new_resh_o.size(0) == 1) {
      b_loop_ub = v_of_old.size(0);
    } else {
      b_loop_ub = v_new_resh_o.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_v_of_old[i1 + b_v_of_old.size(0) * i] =
          v_of_old[i1 * stride_0_0 + v_of_old.size(0) * aux_0_1] -
          v_new_resh_o[i1 * stride_1_0 + v_new_resh_o.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = &ih_emlrtRSI;
  coder::b_abs(&st, b_v_of_old, v_n_adopt);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static const mxArray *c_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[48])
{
  static const int32_T iv[2]{1, 48};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 48, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void
d_binary_expand_op(const emlrtStack *sp, coder::array<real_T, 2U> &v_p_o,
                   const coder::array<boolean_T, 2U> &pi_contemp_neg_new)
{
  coder::array<real_T, 2U> r;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T pi_contemp_neg_new_idx_0;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  pi_contemp_neg_new_idx_0 =
      pi_contemp_neg_new.size(0) * pi_contemp_neg_new.size(1);
  if (v_p_o.size(0) == 1) {
    i = pi_contemp_neg_new_idx_0;
  } else {
    i = v_p_o.size(0);
  }
  if (v_p_o.size(1) == 1) {
    i1 = 1;
  } else {
    i1 = v_p_o.size(1);
  }
  r.set_size(&dg_emlrtRTEI, sp, i, i1);
  stride_0_0 = (pi_contemp_neg_new_idx_0 != 1);
  stride_1_0 = (v_p_o.size(0) != 1);
  stride_1_1 = (v_p_o.size(1) != 1);
  aux_1_1 = 0;
  if (v_p_o.size(1) == 1) {
    loop_ub = 1;
  } else {
    loop_ub = v_p_o.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    if (v_p_o.size(0) == 1) {
      b_loop_ub = pi_contemp_neg_new_idx_0;
    } else {
      b_loop_ub = v_p_o.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      r[i1 + r.size(0) * i] =
          (1.0 - static_cast<real_T>(pi_contemp_neg_new[i1 * stride_0_0])) *
          v_p_o[i1 * stride_1_0 + v_p_o.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
  }
  v_p_o.set_size(&dg_emlrtRTEI, sp, r.size(0), r.size(1));
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = r.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      v_p_o[i1 + v_p_o.size(0) * i] = r[i1 + r.size(0) * i];
    }
  }
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
                                          const char_T u[97])
{
  static const int32_T iv[2]{1, 97};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 97, m, &u[0]);
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

static const mxArray *feval(const emlrtStack *sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            const mxArray *m6, emlrtMCInfo *location)
{
  const mxArray *pArrays[6];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  pArrays[3] = m4;
  pArrays[4] = m5;
  pArrays[5] = m6;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 6, &pArrays[0],
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
  b_a_prob.set_size(&fb_emlrtRTEI, sp, 1, i);
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
  a_prob.set_size(&fb_emlrtRTEI, sp, 1, b_a_prob.size(1));
  loop_ub = b_a_prob.size(1);
  for (i = 0; i < loop_ub; i++) {
    a_prob[i] = b_a_prob[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void plus(const emlrtStack *sp, coder::array<real_T, 2U> &a_cdf,
                 const coder::array<real_T, 2U> &r)
{
  coder::array<real_T, 2U> b_a_cdf;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (r.size(1) == 1) {
    i = a_cdf.size(1);
  } else {
    i = r.size(1);
  }
  b_a_cdf.set_size(&bg_emlrtRTEI, sp, 1, i);
  stride_0_1 = (a_cdf.size(1) != 1);
  stride_1_1 = (r.size(1) != 1);
  if (r.size(1) == 1) {
    loop_ub = a_cdf.size(1);
  } else {
    loop_ub = r.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_a_cdf[i] = a_cdf[i * stride_0_1] + r[i * stride_1_1];
  }
  a_cdf.set_size(&bg_emlrtRTEI, sp, 1, b_a_cdf.size(1));
  loop_ub = b_a_cdf.size(1);
  for (i = 0; i < loop_ub; i++) {
    a_cdf[i] = b_a_cdf[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void times(const emlrtStack *sp, coder::array<real_T, 2U> &v_n_adopt,
                  const coder::array<real_T, 2U> &v_p_o)
{
  coder::array<real_T, 2U> b_v_p_o;
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
  if (v_n_adopt.size(0) == 1) {
    i = v_p_o.size(0);
  } else {
    i = v_n_adopt.size(0);
  }
  if (v_n_adopt.size(1) == 1) {
    i1 = v_p_o.size(1);
  } else {
    i1 = v_n_adopt.size(1);
  }
  b_v_p_o.set_size(&ce_emlrtRTEI, sp, i, i1);
  stride_0_0 = (v_p_o.size(0) != 1);
  stride_0_1 = (v_p_o.size(1) != 1);
  stride_1_0 = (v_n_adopt.size(0) != 1);
  stride_1_1 = (v_n_adopt.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (v_n_adopt.size(1) == 1) {
    loop_ub = v_p_o.size(1);
  } else {
    loop_ub = v_n_adopt.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    if (v_n_adopt.size(0) == 1) {
      b_loop_ub = v_p_o.size(0);
    } else {
      b_loop_ub = v_n_adopt.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_v_p_o[i1 + b_v_p_o.size(0) * i] =
          v_p_o[i1 * stride_0_0 + v_p_o.size(0) * aux_0_1] *
          v_n_adopt[i1 * stride_1_0 + v_n_adopt.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  v_n_adopt.set_size(&ce_emlrtRTEI, sp, b_v_p_o.size(0), b_v_p_o.size(1));
  loop_ub = b_v_p_o.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_v_p_o.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      v_n_adopt[i1 + v_n_adopt.size(0) * i] = b_v_p_o[i1 + b_v_p_o.size(0) * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void Two_tech_ss(
    const emlrtStack *sp, real_T a_grow, real_T alpha, real_T, real_T beta,
    real_T c_of_a, real_T c_a_new, real_T a_lamb, real_T p_e, real_T a_num_g,
    real_T age_num, real_T max_iter, real_T v_tol, real_T dist_tol, real_T fco,
    real_T e_p, real_T d_0, real_T c_of_e, real_T c_e_new, real_T dem_tol,
    real_T tech_dist, coder::array<real_T, 1U> &trans_prob_o,
    coder::array<real_T, 1U> &v_new_o, coder::array<real_T, 2U> &v_new_resh_o,
    coder::array<real_T, 2U> &dist_o, coder::sparse *trans_matrix_n,
    coder::array<real_T, 1U> &trans_prob_n, coder::array<real_T, 1U> &v_new_n,
    coder::array<real_T, 2U> &v_new_resh_n, coder::array<real_T, 2U> &dist_n,
    coder::sparse *trans_matrix_o, coder::array<real_T, 1U> &age_g,
    coder::array<real_T, 2U> &a_grid, coder::array<real_T, 2U> &a_prob,
    coder::array<real_T, 2U> &pi_contemp_new, real_T *p_E,
    real_T *m_of_firms_new, real_T *m_of_firms_old)
{
  static const char_T cv1[97]{
      'e', 'n', 't', 'r', 'y', ' ', 'a', 'n', 'd', ' ', 'e', 'x',  'i', 't',
      ' ', 'h', 'a', 'v', 'e', ' ', 'c', 'o', 'n', 'v', 'e', 'r',  'g', 'e',
      'd', ' ', 'a', 'n', 'd', ' ', 'E', '(', 'v', '_', 'n', 'e',  'w', ')',
      ' ', 'a', 'n', 'd', ' ', 'E', '(', 'v', '_', 'o', 'l', 'd',  ')', ' ',
      '.', '.', '.', 'i', 's', ' ', '%', '2', '.', '4', 'f', ' ',  'a', 'n',
      'd', ' ', '%', '2', '.', '4', 'f', ' ', 'i', 'n', ' ', '%',  '2', '.',
      '1', 'f', ' ', 'p', 'e', 'r', 'i', 'o', 'd', 's', ' ', '\\', 'n'};
  static const char_T cv4[77]{
      'd', 'e', 'm', 'a', 'n', 'd', ' ', 'a', 'n', 'd', ' ',  's', 'u',
      'p', 'p', 'l', 'y', ' ', 'h', 'a', 's', ' ', 'c', 'o',  'n', 'v',
      'e', 'r', 'g', 'e', 'd', ' ', 'a', 'n', 'd', ' ', 't',  'h', 'e',
      ' ', 'p', 'r', 'i', 'c', 'e', 's', ' ', 'i', 's', ' ',  '.', '.',
      '.', '%', '2', '.', '4', 'f', ' ', 'i', 'n', ' ', '%',  '2', '.',
      '1', 'f', ' ', 'p', 'e', 'r', 'i', 'o', 'd', 's', '\\', 'n'};
  static const char_T cv2[50]{
      'v', 'a', 'l', 'u', 'e', ' ', 'f', 'u', 'n', 'c',  't', 'i', 'o',
      'n', ' ', 'o', 'f', ' ', 'n', 'e', 'w', ' ', 'c',  'o', 'n', 'v',
      'e', 'r', 'g', 'e', 'd', ' ', 'i', 'n', ' ', '%',  '4', '.', '1',
      'f', ' ', 'p', 'e', 'r', 'i', 'o', 'd', 's', '\\', 'n'};
  static const char_T cv3[50]{
      'v', 'a', 'l', 'u', 'e', ' ', 'f', 'u', 'n', 'c',  't', 'i', 'o',
      'n', ' ', 'o', 'f', ' ', 'o', 'l', 'd', ' ', 'c',  'o', 'n', 'v',
      'e', 'r', 'g', 'e', 'd', ' ', 'i', 'n', ' ', '%',  '4', '.', '1',
      'f', ' ', 'p', 'e', 'r', 'i', 'o', 'd', 's', '\\', 'n'};
  static const char_T cv5[48]{'d', 'i', 's', 't', 'r', 'i', 'b',  'u', 't', 'i',
                              'o', 'n', ' ', 'o', 'f', ' ', 'n',  'e', 'w', ' ',
                              'c', 'o', 'n', 'v', 'e', 'r', 'g',  'e', 'd', ' ',
                              'i', 'n', ' ', '%', '4', '.', '1',  'f', ' ', 'p',
                              'e', 'r', 'i', 'o', 'd', 's', '\\', 'n'};
  static const char_T cv6[48]{'d', 'i', 's', 't', 'r', 'i', 'b',  'u', 't', 'i',
                              'o', 'n', ' ', 'o', 'f', ' ', 'o',  'l', 'd', ' ',
                              'c', 'o', 'n', 'v', 'e', 'r', 'g',  'e', 'd', ' ',
                              'i', 'n', ' ', '%', '4', '.', '1',  'f', ' ', 'p',
                              'e', 'r', 'i', 'o', 'd', 's', '\\', 'n'};
  static const char_T cv[7]{'f', 'p', 'r', 'i', 'n', 't', 'f'};
  coder::array<real_T, 2U> a;
  coder::array<real_T, 2U> a_cdf;
  coder::array<real_T, 2U> b_v_of_new;
  coder::array<real_T, 2U> cap_contemp_new;
  coder::array<real_T, 2U> cap_contemp_old;
  coder::array<real_T, 2U> dist_ent;
  coder::array<real_T, 2U> pi_contemp_old;
  coder::array<real_T, 2U> r;
  coder::array<real_T, 2U> v_n_adopt;
  coder::array<real_T, 2U> v_n_adopt_p;
  coder::array<real_T, 2U> v_of_new;
  coder::array<real_T, 2U> v_of_old;
  coder::array<real_T, 2U> v_p_n;
  coder::array<real_T, 2U> v_p_o;
  coder::array<real_T, 1U> b_cap_contemp_old;
  coder::array<real_T, 1U> b_v_p_n;
  coder::array<real_T, 1U> v_n_best;
  coder::array<real_T, 1U> v_p_n_expand;
  coder::array<real_T, 1U> varargin_1;
  coder::array<int32_T, 1U> r1;
  coder::array<int32_T, 1U> r2;
  coder::array<int32_T, 1U> r3;
  coder::array<int32_T, 1U> r4;
  coder::array<int32_T, 1U> r5;
  coder::array<int32_T, 1U> r6;
  coder::array<boolean_T, 2U> exit_vec_n;
  coder::array<boolean_T, 2U> exit_vec_o;
  coder::array<boolean_T, 2U> exiting_firm_n;
  coder::array<boolean_T, 2U> pi_contemp_neg_new;
  coder::array<boolean_T, 2U> pi_contemp_neg_old;
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
  real_T d;
  real_T max_iter_price;
  real_T suply_price;
  real_T varargin_2;
  int32_T b_v_n_best[2];
  int32_T iv[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T b_loop_ub_tmp;
  int32_T c_loop_ub_tmp;
  int32_T h;
  int32_T i;
  int32_T idx;
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
  coder::linspace(&st, a_num_g, r);
  st.site = &emlrtRSI;
  coder::expinv(&st, r, a_lamb, a_grid);
  st.site = &b_emlrtRSI;
  coder::expcdf(&st, a_grid, a_lamb, a_cdf);
  if (2.0 > a_num_g) {
    i = 0;
    b_i = 0;
  } else {
    if (2 > a_cdf.size(1)) {
      emlrtDynamicBoundsCheckR2012b(2, 1, a_cdf.size(1), &emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i = 1;
    if (a_num_g != static_cast<int32_T>(muDoubleScalarFloor(a_num_g))) {
      emlrtIntegerCheckR2012b(a_num_g, &emlrtDCI, (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(a_num_g) < 1) ||
        (static_cast<int32_T>(a_num_g) > a_cdf.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a_num_g), 1,
                                    a_cdf.size(1), &b_emlrtBCI, (emlrtCTX)sp);
    }
    b_i = static_cast<int32_T>(a_num_g);
  }
  loop_ub = b_i - i;
  a_prob.set_size(&fb_emlrtRTEI, sp, 1, loop_ub + 1);
  for (b_i = 0; b_i < loop_ub; b_i++) {
    a_prob[b_i] = a_cdf[i + b_i];
  }
  a_prob[loop_ub] = 1.0;
  if ((a_prob.size(1) != a_cdf.size(1)) &&
      ((a_prob.size(1) != 1) && (a_cdf.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(a_prob.size(1), a_cdf.size(1), &emlrtECI,
                                (emlrtCTX)sp);
  }
  if (a_prob.size(1) == a_cdf.size(1)) {
    loop_ub = a_prob.size(1) - 1;
    a_prob.set_size(&gb_emlrtRTEI, sp, 1, a_prob.size(1));
    for (i = 0; i <= loop_ub; i++) {
      a_prob[i] = a_prob[i] - a_cdf[i];
    }
  } else {
    st.site = &gh_emlrtRSI;
    minus(&st, a_prob, a_cdf);
  }
  max_iter_price = muDoubleScalarFloor(max_iter / 100.0);
  st.site = &c_emlrtRSI;
  coder::linspace(&st, age_num - 1.0, age_num, r);
  age_g.set_size(&hb_emlrtRTEI, sp, r.size(1));
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    age_g[i] = r[i];
  }
  varargin_2 = age_num * a_num_g;
  if (!(varargin_2 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_2, &m_emlrtDCI, (emlrtCTX)sp);
  }
  d = static_cast<int32_T>(muDoubleScalarFloor(varargin_2));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &l_emlrtDCI, (emlrtCTX)sp);
  }
  v_p_n.set_size(&ib_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
                 v_p_n.size(1));
  if (!(a_num_g >= 0.0)) {
    emlrtNonNegativeCheckR2012b(a_num_g, &o_emlrtDCI, (emlrtCTX)sp);
  }
  suply_price = static_cast<int32_T>(muDoubleScalarFloor(a_num_g));
  if (a_num_g != suply_price) {
    emlrtIntegerCheckR2012b(a_num_g, &n_emlrtDCI, (emlrtCTX)sp);
  }
  v_p_n.set_size(&ib_emlrtRTEI, sp, v_p_n.size(0),
                 static_cast<int32_T>(a_num_g));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &y_emlrtDCI, (emlrtCTX)sp);
  }
  if (a_num_g != suply_price) {
    emlrtIntegerCheckR2012b(a_num_g, &y_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub_tmp =
      static_cast<int32_T>(varargin_2) * static_cast<int32_T>(a_num_g);
  for (i = 0; i < loop_ub_tmp; i++) {
    v_p_n[i] = 0.0;
  }
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &p_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(a_num_g);
  v_p_o.set_size(&jb_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
                 static_cast<int32_T>(a_num_g));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &ab_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < loop_ub_tmp; i++) {
    v_p_o[i] = 0.0;
  }
  // %%%% these should be predefined for mex purposes
  st.site = &d_emlrtRSI;
  coder::b_sparse(&st, age_num * a_num_g, age_num * a_num_g, trans_matrix_n);
  dist_n.set_size(&kb_emlrtRTEI, sp, 1, dist_n.size(1));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &q_emlrtDCI, (emlrtCTX)sp);
  }
  dist_n.set_size(&kb_emlrtRTEI, sp, dist_n.size(0),
                  static_cast<int32_T>(varargin_2));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &bb_emlrtDCI, (emlrtCTX)sp);
  }
  b_loop_ub = static_cast<int32_T>(varargin_2);
  for (i = 0; i < b_loop_ub; i++) {
    dist_n[i] = 0.0;
  }
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &cb_emlrtDCI, (emlrtCTX)sp);
  }
  v_new_n.set_size(&lb_emlrtRTEI, sp, static_cast<int32_T>(varargin_2));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &cb_emlrtDCI, (emlrtCTX)sp);
  }
  b_loop_ub = static_cast<int32_T>(varargin_2);
  for (i = 0; i < b_loop_ub; i++) {
    v_new_n[i] = 0.0;
  }
  if (!(age_num >= 0.0)) {
    emlrtNonNegativeCheckR2012b(age_num, &s_emlrtDCI, (emlrtCTX)sp);
  }
  i = static_cast<int32_T>(muDoubleScalarFloor(age_num));
  if (age_num != i) {
    emlrtIntegerCheckR2012b(age_num, &r_emlrtDCI, (emlrtCTX)sp);
  }
  v_new_resh_n.set_size(&mb_emlrtRTEI, sp, static_cast<int32_T>(age_num),
                        static_cast<int32_T>(a_num_g));
  if (age_num != i) {
    emlrtIntegerCheckR2012b(age_num, &db_emlrtDCI, (emlrtCTX)sp);
  }
  b_loop_ub = static_cast<int32_T>(age_num) * static_cast<int32_T>(a_num_g);
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    v_new_resh_n[b_i] = 0.0;
  }
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &b_emlrtDCI, (emlrtCTX)sp);
  }
  exit_vec_n.set_size(&nb_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
                      static_cast<int32_T>(varargin_2));
  nx = static_cast<int32_T>(varargin_2) * static_cast<int32_T>(varargin_2);
  for (b_i = 0; b_i < nx; b_i++) {
    exit_vec_n[b_i] = false;
  }
  st.site = &e_emlrtRSI;
  coder::b_sparse(&st, age_num * a_num_g, age_num * a_num_g, trans_matrix_o);
  dist_o.set_size(&ob_emlrtRTEI, sp, 1, dist_o.size(1));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &t_emlrtDCI, (emlrtCTX)sp);
  }
  dist_o.set_size(&ob_emlrtRTEI, sp, dist_o.size(0),
                  static_cast<int32_T>(varargin_2));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &eb_emlrtDCI, (emlrtCTX)sp);
  }
  b_loop_ub = static_cast<int32_T>(varargin_2);
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    dist_o[b_i] = 0.0;
  }
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &fb_emlrtDCI, (emlrtCTX)sp);
  }
  v_new_o.set_size(&pb_emlrtRTEI, sp, static_cast<int32_T>(varargin_2));
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &fb_emlrtDCI, (emlrtCTX)sp);
  }
  b_loop_ub = static_cast<int32_T>(varargin_2);
  for (b_i = 0; b_i < b_loop_ub; b_i++) {
    v_new_o[b_i] = 0.0;
  }
  if (age_num != i) {
    emlrtIntegerCheckR2012b(age_num, &u_emlrtDCI, (emlrtCTX)sp);
  }
  b_loop_ub_tmp = static_cast<int32_T>(age_num);
  v_new_resh_o.set_size(&qb_emlrtRTEI, sp, b_loop_ub_tmp,
                        static_cast<int32_T>(a_num_g));
  if (b_loop_ub_tmp != i) {
    emlrtIntegerCheckR2012b(age_num, &gb_emlrtDCI, (emlrtCTX)sp);
  }
  c_loop_ub_tmp = static_cast<int32_T>(age_num) * static_cast<int32_T>(a_num_g);
  for (i = 0; i < c_loop_ub_tmp; i++) {
    v_new_resh_o[i] = 0.0;
  }
  if (varargin_2 != d) {
    emlrtIntegerCheckR2012b(varargin_2, &c_emlrtDCI, (emlrtCTX)sp);
  }
  exit_vec_o.set_size(&rb_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
                      static_cast<int32_T>(varargin_2));
  for (i = 0; i < nx; i++) {
    exit_vec_o[i] = false;
  }
  // %%%%
  // %% Here we will have endogenous entry: this means that as long as value of
  // %% entrant - the cost of entry is positive there should be entrants. To
  // %% solve it I will loop over the whole soltuion till I find the
  // %% equilibrium price satisfying this condition; first I start with p_E = 1
  *p_E = 1.0;
  st.site = &f_emlrtRSI;
  coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_n_best);
  st.site = &f_emlrtRSI;
  suply_price = coder::mpower(&st, alpha / p_e, alpha);
  v_n_adopt_p.set_size(&sb_emlrtRTEI, sp, v_n_best.size(0), a_grid.size(1));
  b_loop_ub = a_grid.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    idx = v_n_best.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
          (a_grid[i] + 1.0) * suply_price * v_n_best[b_i];
    }
  }
  st.site = &f_emlrtRSI;
  coder::power(&st, v_n_adopt_p, 1.0 / (1.0 - alpha), pi_contemp_new);
  // %% I also consider the remainder of the firms that have not transitioned
  st.site = &g_emlrtRSI;
  coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_n_best);
  st.site = &g_emlrtRSI;
  suply_price = coder::mpower(&st, alpha / p_e, alpha);
  v_n_adopt_p.set_size(&tb_emlrtRTEI, sp, v_n_best.size(0), a_grid.size(1));
  b_loop_ub = a_grid.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    idx = v_n_best.size(0);
    for (b_i = 0; b_i < idx; b_i++) {
      v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
          (a_grid[i] + 1.0) / tech_dist * suply_price * v_n_best[b_i];
    }
  }
  st.site = &g_emlrtRSI;
  coder::power(&st, v_n_adopt_p, 1.0 / (1.0 - alpha), pi_contemp_old);
  // %% here I'm adding fixed cost of operation to implement exit decision: it
  // %% should be calibrated
  b_loop_ub = pi_contemp_new.size(0) * pi_contemp_new.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    pi_contemp_new[i] = pi_contemp_new[i] * (1.0 - alpha) - fco;
  }
  b_loop_ub = pi_contemp_old.size(0) * pi_contemp_old.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    pi_contemp_old[i] = pi_contemp_old[i] * (1.0 - alpha) - fco;
  }
  // %% those with negative contemporary profit will exit
  idx = pi_contemp_new.size(0) * pi_contemp_new.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= idx; b_i++) {
    if (pi_contemp_new[b_i] < 0.0) {
      nx++;
    }
  }
  r1.set_size(&ub_emlrtRTEI, sp, nx);
  nx = 0;
  for (b_i = 0; b_i <= idx; b_i++) {
    if (pi_contemp_new[b_i] < 0.0) {
      r1[nx] = b_i + 1;
      nx++;
    }
  }
  b_loop_ub = r1.size(0) - 1;
  nx = pi_contemp_new.size(0) * pi_contemp_new.size(1);
  for (i = 0; i <= b_loop_ub; i++) {
    if ((r1[i] < 1) || (r1[i] > nx)) {
      emlrtDynamicBoundsCheckR2012b(r1[i], 1, nx, &jb_emlrtBCI, (emlrtCTX)sp);
    }
    pi_contemp_new[r1[i] - 1] = 0.0;
  }
  idx = pi_contemp_old.size(0) * pi_contemp_old.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= idx; b_i++) {
    if (pi_contemp_old[b_i] < 0.0) {
      nx++;
    }
  }
  r2.set_size(&ub_emlrtRTEI, sp, nx);
  nx = 0;
  for (b_i = 0; b_i <= idx; b_i++) {
    if (pi_contemp_old[b_i] < 0.0) {
      r2[nx] = b_i + 1;
      nx++;
    }
  }
  b_loop_ub = r2.size(0) - 1;
  nx = pi_contemp_old.size(0) * pi_contemp_old.size(1);
  for (i = 0; i <= b_loop_ub; i++) {
    if ((r2[i] < 1) || (r2[i] > nx)) {
      emlrtDynamicBoundsCheckR2012b(r2[i], 1, nx, &kb_emlrtBCI, (emlrtCTX)sp);
    }
    pi_contemp_old[r2[i] - 1] = 0.0;
  }
  v_of_new.set_size(&vb_emlrtRTEI, sp, pi_contemp_new.size(0),
                    pi_contemp_new.size(1));
  b_loop_ub = pi_contemp_new.size(0) * pi_contemp_new.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    v_of_new[i] = pi_contemp_new[i];
  }
  v_of_old.set_size(&wb_emlrtRTEI, sp, pi_contemp_old.size(0),
                    pi_contemp_old.size(1));
  b_loop_ub = pi_contemp_old.size(0) * pi_contemp_old.size(1);
  for (i = 0; i < b_loop_ub; i++) {
    v_of_old[i] = pi_contemp_old[i];
  }
  // %%% also to have the entry and exit equal to each other the measure of the
  // %%% firms should be the correct number
  *m_of_firms_new = 1.0;
  *m_of_firms_old = 1.0;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter_price, mxDOUBLE_CLASS,
                                static_cast<int32_T>(max_iter_price),
                                &emlrtRTEI, (emlrtCTX)sp);
  h = 0;
  exitg1 = false;
  while ((!exitg1) && (h <= static_cast<int32_T>(max_iter_price) - 1)) {
    real_T b_error;
    int32_T k;
    boolean_T exitg2;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter_price, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(max_iter_price),
                                  &b_emlrtRTEI, (emlrtCTX)sp);
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k <= static_cast<int32_T>(max_iter_price) - 1)) {
      int32_T i1;
      int32_T i2;
      boolean_T exitg3;
      boolean_T exitg4;
      st.site = &h_emlrtRSI;
      coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_n_best);
      st.site = &h_emlrtRSI;
      suply_price = coder::mpower(&st, alpha * *p_E / p_e, alpha);
      v_n_adopt_p.set_size(&xb_emlrtRTEI, sp, v_n_best.size(0), a_grid.size(1));
      b_loop_ub = a_grid.size(1);
      for (i = 0; i < b_loop_ub; i++) {
        idx = v_n_best.size(0);
        for (b_i = 0; b_i < idx; b_i++) {
          v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
              (a_grid[i] + 1.0) * suply_price * v_n_best[b_i];
        }
      }
      st.site = &h_emlrtRSI;
      coder::power(&st, v_n_adopt_p, 1.0 / (1.0 - alpha), pi_contemp_new);
      st.site = &i_emlrtRSI;
      coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_n_best);
      st.site = &i_emlrtRSI;
      suply_price = coder::mpower(&st, alpha * *p_E / p_e, alpha);
      v_n_adopt_p.set_size(&yb_emlrtRTEI, sp, v_n_best.size(0), a_grid.size(1));
      b_loop_ub = a_grid.size(1);
      for (i = 0; i < b_loop_ub; i++) {
        idx = v_n_best.size(0);
        for (b_i = 0; b_i < idx; b_i++) {
          v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
              (a_grid[i] + 1.0) * suply_price * v_n_best[b_i];
        }
      }
      st.site = &i_emlrtRSI;
      coder::power(&st, v_n_adopt_p, 1.0 / (1.0 - alpha), v_n_adopt);
      cap_contemp_new.set_size(&ac_emlrtRTEI, sp, v_n_adopt.size(1),
                               v_n_adopt.size(0));
      b_loop_ub = v_n_adopt.size(0);
      for (i = 0; i < b_loop_ub; i++) {
        idx = v_n_adopt.size(1);
        for (b_i = 0; b_i < idx; b_i++) {
          cap_contemp_new[b_i + cap_contemp_new.size(0) * i] =
              v_n_adopt[i + v_n_adopt.size(0) * b_i];
        }
      }
      b_loop_ub = pi_contemp_new.size(0) * pi_contemp_new.size(1);
      for (i = 0; i < b_loop_ub; i++) {
        pi_contemp_new[i] = pi_contemp_new[i] * (1.0 - alpha) - fco;
      }
      pi_contemp_neg_new.set_size(&bc_emlrtRTEI, sp, pi_contemp_new.size(0),
                                  pi_contemp_new.size(1));
      b_loop_ub = pi_contemp_new.size(0) * pi_contemp_new.size(1);
      idx = pi_contemp_new.size(0) * pi_contemp_new.size(1) - 1;
      nx = 0;
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        pi_contemp_neg_new[b_i] = (pi_contemp_new[b_i] < 0.0);
        if (pi_contemp_new[b_i] < 0.0) {
          nx++;
        }
      }
      r3.set_size(&ub_emlrtRTEI, sp, nx);
      nx = 0;
      for (b_i = 0; b_i <= idx; b_i++) {
        if (pi_contemp_new[b_i] < 0.0) {
          r3[nx] = b_i + 1;
          nx++;
        }
      }
      b_loop_ub = r3.size(0) - 1;
      nx = pi_contemp_new.size(0) * pi_contemp_new.size(1);
      for (i = 0; i <= b_loop_ub; i++) {
        if ((r3[i] < 1) || (r3[i] > nx)) {
          emlrtDynamicBoundsCheckR2012b(r3[i], 1, nx, &lb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        pi_contemp_new[r3[i] - 1] = 0.0;
      }
      st.site = &j_emlrtRSI;
      coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_n_best);
      st.site = &j_emlrtRSI;
      suply_price = coder::mpower(&st, alpha * *p_E / p_e, alpha);
      v_n_adopt_p.set_size(&cc_emlrtRTEI, sp, v_n_best.size(0), a_grid.size(1));
      b_loop_ub = a_grid.size(1);
      for (i = 0; i < b_loop_ub; i++) {
        idx = v_n_best.size(0);
        for (b_i = 0; b_i < idx; b_i++) {
          v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
              (a_grid[i] + 1.0) / tech_dist * suply_price * v_n_best[b_i];
        }
      }
      st.site = &j_emlrtRSI;
      coder::power(&st, v_n_adopt_p, 1.0 / (1.0 - alpha), pi_contemp_old);
      st.site = &k_emlrtRSI;
      coder::power(&st, 1.0 / (a_grow + 1.0), age_g, v_n_best);
      st.site = &k_emlrtRSI;
      suply_price = coder::mpower(&st, alpha * *p_E / p_e, alpha);
      v_n_adopt_p.set_size(&dc_emlrtRTEI, sp, v_n_best.size(0), a_grid.size(1));
      b_loop_ub = a_grid.size(1);
      for (i = 0; i < b_loop_ub; i++) {
        idx = v_n_best.size(0);
        for (b_i = 0; b_i < idx; b_i++) {
          v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
              (a_grid[i] + 1.0) / tech_dist * suply_price * v_n_best[b_i];
        }
      }
      st.site = &k_emlrtRSI;
      coder::power(&st, v_n_adopt_p, 1.0 / (1.0 - alpha), v_n_adopt);
      cap_contemp_old.set_size(&ec_emlrtRTEI, sp, v_n_adopt.size(1),
                               v_n_adopt.size(0));
      b_loop_ub = v_n_adopt.size(0);
      for (i = 0; i < b_loop_ub; i++) {
        idx = v_n_adopt.size(1);
        for (b_i = 0; b_i < idx; b_i++) {
          cap_contemp_old[b_i + cap_contemp_old.size(0) * i] =
              v_n_adopt[i + v_n_adopt.size(0) * b_i];
        }
      }
      b_loop_ub = pi_contemp_old.size(0) * pi_contemp_old.size(1);
      for (i = 0; i < b_loop_ub; i++) {
        pi_contemp_old[i] = pi_contemp_old[i] * (1.0 - alpha) - fco;
      }
      pi_contemp_neg_old.set_size(&fc_emlrtRTEI, sp, pi_contemp_old.size(0),
                                  pi_contemp_old.size(1));
      b_loop_ub = pi_contemp_old.size(0) * pi_contemp_old.size(1);
      idx = pi_contemp_old.size(0) * pi_contemp_old.size(1) - 1;
      nx = 0;
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        pi_contemp_neg_old[b_i] = (pi_contemp_old[b_i] < 0.0);
        if (pi_contemp_old[b_i] < 0.0) {
          nx++;
        }
      }
      r4.set_size(&ub_emlrtRTEI, sp, nx);
      nx = 0;
      for (b_i = 0; b_i <= idx; b_i++) {
        if (pi_contemp_old[b_i] < 0.0) {
          r4[nx] = b_i + 1;
          nx++;
        }
      }
      b_loop_ub = r4.size(0) - 1;
      nx = pi_contemp_old.size(0) * pi_contemp_old.size(1);
      for (i = 0; i <= b_loop_ub; i++) {
        if ((r4[i] < 1) || (r4[i] > nx)) {
          emlrtDynamicBoundsCheckR2012b(r4[i], 1, nx, &mb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        pi_contemp_old[r4[i] - 1] = 0.0;
      }
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter, mxDOUBLE_CLASS,
                                    static_cast<int32_T>(max_iter),
                                    &c_emlrtRTEI, (emlrtCTX)sp);
      i1 = 0;
      exitg3 = false;
      while ((!exitg3) && (i1 <= static_cast<int32_T>(max_iter) - 1)) {
        v_p_n.set_size(&gc_emlrtRTEI, sp, v_of_new.size(1), v_of_new.size(0));
        b_loop_ub = v_of_new.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_of_new.size(1);
          for (b_i = 0; b_i < idx; b_i++) {
            v_p_n[b_i + v_p_n.size(0) * i] =
                v_of_new[i + v_of_new.size(0) * b_i];
          }
        }
        if (2.0 > age_num) {
          i = -1;
          b_i = -1;
          idx = 0;
        } else {
          if (2 > v_p_n.size(1)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, v_p_n.size(1), &c_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          i = 0;
          if (b_loop_ub_tmp > v_p_n.size(1)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num), 1,
                                          v_p_n.size(1), &d_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_i = b_loop_ub_tmp - 1;
          if (1 > v_p_n.size(1)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, v_p_n.size(1), &e_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (b_loop_ub_tmp - 1 > v_p_n.size(1)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num) - 1, 1,
                                          v_p_n.size(1), &f_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          idx = b_loop_ub_tmp - 1;
        }
        b_v_n_best[0] = v_p_n.size(0);
        b_v_n_best[1] = idx;
        iv[0] = v_p_n.size(0);
        b_loop_ub = b_i - i;
        iv[1] = b_loop_ub;
        emlrtSubAssignSizeCheckR2012b(&b_v_n_best[0], 2, &iv[0], 2, &b_emlrtECI,
                                      (emlrtCTX)sp);
        nx = v_p_n.size(0) - 1;
        v_n_adopt_p.set_size(&hc_emlrtRTEI, sp, v_p_n.size(0), b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (idx = 0; idx <= nx; idx++) {
            v_n_adopt_p[idx + v_n_adopt_p.size(0) * b_i] =
                v_p_n[idx + v_p_n.size(0) * ((i + b_i) + 1)];
          }
        }
        b_loop_ub = v_n_adopt_p.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_n_adopt_p.size(0);
          for (b_i = 0; b_i < idx; b_i++) {
            v_p_n[b_i + v_p_n.size(0) * i] =
                v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i];
          }
        }
        if ((age_num < 1.0) || (b_loop_ub_tmp > v_p_n.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num), 1,
                                        v_p_n.size(1), &g_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_loop_ub = v_p_n.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          v_p_n[i + v_p_n.size(0) * (static_cast<int32_T>(age_num) - 1)] = 0.0;
        }
        // %% setting the
        // %% value of those who don't adopt
        // %% at the highest age to zero; it
        // %% should also be noted that if a
        // %% firm is not adopting, in the
        // %% next period it would get the
        // %% value of v(age+1,a_i)
        idx = v_p_n.size(0) * v_p_n.size(1);
        v_n_best.set_size(&ic_emlrtRTEI, sp, static_cast<int32_T>(a_num_g));
        for (i = 0; i < loop_ub; i++) {
          v_n_best[i] = 1.0;
        }
        b_v_p_n = v_p_n.reshape(idx);
        st.site = &l_emlrtRSI;
        coder::kron(&st, b_v_p_n, v_n_best, v_p_n_expand);
        if (1 > v_of_new.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, v_of_new.size(0), &h_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        v_n_adopt_p.set_size(&jc_emlrtRTEI, sp, b_loop_ub_tmp,
                             static_cast<int32_T>(a_num_g));
        for (i = 0; i < c_loop_ub_tmp; i++) {
          v_n_adopt_p[i] = 1.0;
        }
        b_loop_ub = v_of_new.size(1);
        b_v_of_new.set_size(&kc_emlrtRTEI, sp, 1, v_of_new.size(1));
        for (i = 0; i < b_loop_ub; i++) {
          b_v_of_new[i] = v_of_new[v_of_new.size(0) * i];
        }
        st.site = &m_emlrtRSI;
        coder::kron(&st, v_n_adopt_p, b_v_of_new, v_n_adopt);
        v_n_adopt_p.set_size(&lc_emlrtRTEI, sp, v_n_adopt.size(1),
                             v_n_adopt.size(0));
        b_loop_ub = v_n_adopt.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_n_adopt.size(1);
          for (b_i = 0; b_i < idx; b_i++) {
            v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
                v_n_adopt[i + v_n_adopt.size(0) * b_i];
          }
        }
        st.site = &n_emlrtRSI;
        varargin_1.set_size(&mc_emlrtRTEI, &st,
                            v_n_adopt_p.size(0) * v_n_adopt_p.size(1));
        b_loop_ub = v_n_adopt_p.size(0) * v_n_adopt_p.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          varargin_1[i] = v_n_adopt_p[i] - c_a_new;
        }
        b_st.site = &bd_emlrtRSI;
        c_st.site = &cd_emlrtRSI;
        e_st.site = &dd_emlrtRSI;
        f_st.site = &ed_emlrtRSI;
        g_st.site = &fd_emlrtRSI;
        if (varargin_1.size(0) == v_p_n_expand.size(0)) {
          v_n_best.set_size(&nc_emlrtRTEI, &g_st, varargin_1.size(0));
          b_loop_ub = varargin_1.size(0);
          for (i = 0; i < b_loop_ub; i++) {
            suply_price = varargin_1[i];
            b_error = v_p_n_expand[i];
            v_n_best[i] = muDoubleScalarMax(suply_price, b_error);
          }
        } else {
          h_st.site = &gd_emlrtRSI;
          coder::internal::expand_max(&h_st, varargin_1, v_p_n_expand,
                                      v_n_best);
        }
        // %% let's try different adoption costs
        st.site = &o_emlrtRSI;
        nx = v_n_best.size(0);
        b_st.site = &hd_emlrtRSI;
        c_st.site = &id_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, a_num_g);
        c_st.site = &id_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, varargin_2);
        idx = v_n_best.size(0);
        if (1 > v_n_best.size(0)) {
          idx = 1;
        }
        nx = muIntScalarMax_sint32(nx, idx);
        if (static_cast<int32_T>(a_num_g) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (static_cast<int32_T>(varargin_2) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (loop_ub_tmp != v_n_best.size(0)) {
          emlrtErrorWithMessageIdR2018a(
              &st, &h_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
              "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }
        v_n_adopt.set_size(&oc_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
                           static_cast<int32_T>(a_num_g));
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = static_cast<int32_T>(varargin_2);
          for (b_i = 0; b_i < b_loop_ub; b_i++) {
            v_n_adopt[b_i + v_n_adopt.size(0) * i] =
                v_n_best[i + static_cast<int32_T>(a_num_g) * b_i];
          }
        }
        i = v_p_n.size(0) * v_p_n.size(1);
        if ((v_n_adopt.size(0) != i) &&
            ((v_n_adopt.size(0) != 1) && (i != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_n_adopt.size(0), i, &c_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if (v_n_adopt.size(0) == v_p_n.size(0) * v_p_n.size(1)) {
          v_n_adopt_p.set_size(&pc_emlrtRTEI, sp, v_n_adopt.size(0),
                               v_n_adopt.size(1));
          b_loop_ub = v_n_adopt.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            idx = v_n_adopt.size(0);
            for (b_i = 0; b_i < idx; b_i++) {
              v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
                  1.0 -
                  static_cast<real_T>(v_n_adopt[b_i + v_n_adopt.size(0) * i] ==
                                      v_p_n[b_i]);
            }
          }
          v_p_n.set_size(&qc_emlrtRTEI, sp, v_n_adopt_p.size(0),
                         v_n_adopt_p.size(1));
          b_loop_ub = v_n_adopt_p.size(0) * v_n_adopt_p.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            v_p_n[i] = v_n_adopt_p[i];
          }
        } else {
          st.site = &eh_emlrtRSI;
          binary_expand_op(&st, v_p_n, v_n_adopt);
        }
        // %% those who couldn't pay the fco should exit
        exiting_firm_n.set_size(&rc_emlrtRTEI, sp, pi_contemp_neg_new.size(1),
                                pi_contemp_neg_new.size(0));
        b_loop_ub = pi_contemp_neg_new.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          idx = pi_contemp_neg_new.size(1);
          for (b_i = 0; b_i < idx; b_i++) {
            exiting_firm_n[b_i + exiting_firm_n.size(0) * i] =
                pi_contemp_neg_new[i + pi_contemp_neg_new.size(0) * b_i];
          }
        }
        exit_vec_n.set_size(&sc_emlrtRTEI, sp,
                            exiting_firm_n.size(0) * exiting_firm_n.size(1), 1);
        b_loop_ub = exiting_firm_n.size(0) * exiting_firm_n.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          exit_vec_n[i] = exiting_firm_n[i];
        }
        i = exiting_firm_n.size(0) * exiting_firm_n.size(1);
        if ((i != v_p_n.size(0)) && ((i != 1) && (v_p_n.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(i, v_p_n.size(0), &d_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if ((exiting_firm_n.size(0) * exiting_firm_n.size(1) ==
             v_p_n.size(0)) &&
            (1 == v_p_n.size(1))) {
          b_v_n_best[0] = exiting_firm_n.size(0) * exiting_firm_n.size(1);
          b_loop_ub = b_v_n_best[0];
          v_p_n.set_size(&tc_emlrtRTEI, sp, b_v_n_best[0], 1);
          for (i = 0; i < b_loop_ub; i++) {
            v_p_n[i] =
                (1.0 - static_cast<real_T>(exiting_firm_n[i])) * v_p_n[i];
          }
        } else {
          st.site = &ch_emlrtRSI;
          d_binary_expand_op(&st, v_p_n, exiting_firm_n);
        }
        st.site = &p_emlrtRSI;
        b_st.site = &kd_emlrtRSI;
        coder::dynamic_size_checks(&b_st, v_n_adopt, a_prob, v_n_adopt.size(1),
                                   a_prob.size(1));
        b_st.site = &jd_emlrtRSI;
        coder::internal::blas::mtimes(&b_st, v_n_adopt, a_prob, v_new_n);
        st.site = &q_emlrtRSI;
        nx = v_new_n.size(0);
        b_st.site = &hd_emlrtRSI;
        c_st.site = &id_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, a_num_g);
        c_st.site = &id_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, age_num);
        idx = v_new_n.size(0);
        if (1 > v_new_n.size(0)) {
          idx = 1;
        }
        nx = muIntScalarMax_sint32(nx, idx);
        if (static_cast<int32_T>(a_num_g) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (b_loop_ub_tmp > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (c_loop_ub_tmp != v_new_n.size(0)) {
          emlrtErrorWithMessageIdR2018a(
              &st, &h_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
              "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }
        v_new_resh_n.set_size(&uc_emlrtRTEI, sp, b_loop_ub_tmp,
                              static_cast<int32_T>(a_num_g));
        for (i = 0; i < loop_ub; i++) {
          for (b_i = 0; b_i < b_loop_ub_tmp; b_i++) {
            v_new_resh_n[b_i + v_new_resh_n.size(0) * i] =
                beta * v_new_n[i + static_cast<int32_T>(a_num_g) * b_i];
          }
        }
        if ((pi_contemp_new.size(0) != v_new_resh_n.size(0)) &&
            ((pi_contemp_new.size(0) != 1) && (v_new_resh_n.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(pi_contemp_new.size(0),
                                      v_new_resh_n.size(0), &e_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if ((pi_contemp_new.size(1) != v_new_resh_n.size(1)) &&
            ((pi_contemp_new.size(1) != 1) && (v_new_resh_n.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(pi_contemp_new.size(1),
                                      v_new_resh_n.size(1), &f_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if ((pi_contemp_new.size(0) == v_new_resh_n.size(0)) &&
            (pi_contemp_new.size(1) == v_new_resh_n.size(1))) {
          b_loop_ub = pi_contemp_new.size(0) * pi_contemp_new.size(1);
          v_new_resh_n.set_size(&vc_emlrtRTEI, sp, pi_contemp_new.size(0),
                                pi_contemp_new.size(1));
          for (i = 0; i < b_loop_ub; i++) {
            v_new_resh_n[i] = pi_contemp_new[i] + v_new_resh_n[i];
          }
        } else {
          st.site = &ah_emlrtRSI;
          b_plus(&st, v_new_resh_n, pi_contemp_new);
        }
        idx = pi_contemp_neg_new.size(0) * pi_contemp_neg_new.size(1) - 1;
        nx = 0;
        for (b_i = 0; b_i <= idx; b_i++) {
          if (pi_contemp_neg_new[b_i]) {
            nx++;
          }
        }
        r5.set_size(&ub_emlrtRTEI, sp, nx);
        nx = 0;
        for (b_i = 0; b_i <= idx; b_i++) {
          if (pi_contemp_neg_new[b_i]) {
            r5[nx] = b_i + 1;
            nx++;
          }
        }
        b_loop_ub = r5.size(0) - 1;
        nx = v_new_resh_n.size(0) * v_new_resh_n.size(1);
        for (i = 0; i <= b_loop_ub; i++) {
          if ((r5[i] < 1) || (r5[i] > nx)) {
            emlrtDynamicBoundsCheckR2012b(r5[i], 1, nx, &nb_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          v_new_resh_n[r5[i] - 1] = 0.0;
        }
        if ((v_of_new.size(0) != v_new_resh_n.size(0)) &&
            ((v_of_new.size(0) != 1) && (v_new_resh_n.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_of_new.size(0), v_new_resh_n.size(0),
                                      &g_emlrtECI, (emlrtCTX)sp);
        }
        if ((v_of_new.size(1) != v_new_resh_n.size(1)) &&
            ((v_of_new.size(1) != 1) && (v_new_resh_n.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_of_new.size(1), v_new_resh_n.size(1),
                                      &h_emlrtECI, (emlrtCTX)sp);
        }
        st.site = &r_emlrtRSI;
        if ((v_of_new.size(0) == v_new_resh_n.size(0)) &&
            (v_of_new.size(1) == v_new_resh_n.size(1))) {
          v_n_adopt_p.set_size(&wc_emlrtRTEI, &st, v_of_new.size(0),
                               v_of_new.size(1));
          b_loop_ub = v_of_new.size(0) * v_of_new.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            v_n_adopt_p[i] = v_of_new[i] - v_new_resh_n[i];
          }
          b_st.site = &r_emlrtRSI;
          coder::b_abs(&b_st, v_n_adopt_p, v_n_adopt);
        } else {
          b_st.site = &r_emlrtRSI;
          c_binary_expand_op(&b_st, v_n_adopt, r_emlrtRSI, v_of_new,
                             v_new_resh_n);
        }
        b_st.site = &bd_emlrtRSI;
        c_st.site = &pd_emlrtRSI;
        e_st.site = &qd_emlrtRSI;
        f_st.site = &rd_emlrtRSI;
        b_error = coder::internal::applyToMultipleDims(&f_st, v_n_adopt);
        if (b_error < v_tol) {
          st.site = &s_emlrtRSI;
          b_st.site = &ce_emlrtRSI;
          c_st.site = &xg_emlrtRSI;
          d_st.site = &yg_emlrtRSI;
          emlrt_marshallIn(
              &c_st,
              feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                    b_emlrt_marshallOut(&d_st, cv2),
                    emlrt_marshallOut(static_cast<real_T>(i1) + 1.0),
                    &emlrtMCI),
              "<output of feval>");
          exitg3 = true;
        } else {
          v_of_new.set_size(&xc_emlrtRTEI, sp, v_new_resh_n.size(0),
                            v_new_resh_n.size(1));
          b_loop_ub = v_new_resh_n.size(0) * v_new_resh_n.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            v_of_new[i] = v_new_resh_n[i];
          }
          i1++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtCTX)sp);
          }
        }
      }
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter, mxDOUBLE_CLASS,
                                    static_cast<int32_T>(max_iter),
                                    &d_emlrtRTEI, (emlrtCTX)sp);
      i2 = 0;
      exitg3 = false;
      while ((!exitg3) && (i2 <= static_cast<int32_T>(max_iter) - 1)) {
        v_p_o.set_size(&yc_emlrtRTEI, sp, v_of_old.size(1), v_of_old.size(0));
        b_loop_ub = v_of_old.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_of_old.size(1);
          for (b_i = 0; b_i < idx; b_i++) {
            v_p_o[b_i + v_p_o.size(0) * i] =
                v_of_old[i + v_of_old.size(0) * b_i];
          }
        }
        if (2.0 > age_num) {
          i = -1;
          b_i = -1;
          idx = 0;
        } else {
          if (2 > v_p_o.size(1)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, v_p_o.size(1), &i_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          i = 0;
          if (b_loop_ub_tmp > v_p_o.size(1)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num), 1,
                                          v_p_o.size(1), &j_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_i = static_cast<int32_T>(age_num) - 1;
          if (1 > v_p_o.size(1)) {
            emlrtDynamicBoundsCheckR2012b(1, 1, v_p_o.size(1), &k_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (b_i > v_p_o.size(1)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num) - 1, 1,
                                          v_p_o.size(1), &l_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          idx = b_i;
        }
        b_v_n_best[0] = v_p_o.size(0);
        b_v_n_best[1] = idx;
        iv[0] = v_p_o.size(0);
        b_loop_ub = b_i - i;
        iv[1] = b_loop_ub;
        emlrtSubAssignSizeCheckR2012b(&b_v_n_best[0], 2, &iv[0], 2, &i_emlrtECI,
                                      (emlrtCTX)sp);
        nx = v_p_o.size(0) - 1;
        v_n_adopt_p.set_size(&ad_emlrtRTEI, sp, v_p_o.size(0), b_loop_ub);
        for (b_i = 0; b_i < b_loop_ub; b_i++) {
          for (idx = 0; idx <= nx; idx++) {
            v_n_adopt_p[idx + v_n_adopt_p.size(0) * b_i] =
                v_p_o[idx + v_p_o.size(0) * ((i + b_i) + 1)];
          }
        }
        b_loop_ub = v_n_adopt_p.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_n_adopt_p.size(0);
          for (b_i = 0; b_i < idx; b_i++) {
            v_p_o[b_i + v_p_o.size(0) * i] =
                v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i];
          }
        }
        if ((age_num < 1.0) || (b_loop_ub_tmp > v_p_o.size(1))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(age_num), 1,
                                        v_p_o.size(1), &m_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_loop_ub = v_p_o.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          v_p_o[i + v_p_o.size(0) * (static_cast<int32_T>(age_num) - 1)] = 0.0;
        }
        // %% setting the
        // %% value of those who don't adopt
        // %% at the highest age to zero; it
        // %% should also be noted that if a
        // %% firm is not adopting, in the
        // %% next period it would get the
        // %% value of v(age+1,a_i)
        idx = v_p_o.size(0) * v_p_o.size(1);
        v_n_best.set_size(&bd_emlrtRTEI, sp, static_cast<int32_T>(a_num_g));
        for (i = 0; i < loop_ub; i++) {
          v_n_best[i] = 1.0;
        }
        b_v_p_n = v_p_o.reshape(idx);
        st.site = &t_emlrtRSI;
        coder::kron(&st, b_v_p_n, v_n_best, v_p_n_expand);
        if (1 > v_of_old.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, v_of_old.size(0), &n_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        v_n_adopt_p.set_size(&cd_emlrtRTEI, sp, b_loop_ub_tmp,
                             static_cast<int32_T>(a_num_g));
        for (i = 0; i < c_loop_ub_tmp; i++) {
          v_n_adopt_p[i] = 1.0;
        }
        b_loop_ub = v_of_old.size(1);
        b_v_of_new.set_size(&dd_emlrtRTEI, sp, 1, v_of_old.size(1));
        for (i = 0; i < b_loop_ub; i++) {
          b_v_of_new[i] = v_of_old[v_of_old.size(0) * i];
        }
        st.site = &u_emlrtRSI;
        coder::kron(&st, v_n_adopt_p, b_v_of_new, v_n_adopt);
        v_n_adopt_p.set_size(&ed_emlrtRTEI, sp, v_n_adopt.size(1),
                             v_n_adopt.size(0));
        b_loop_ub = v_n_adopt.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_n_adopt.size(1);
          for (b_i = 0; b_i < idx; b_i++) {
            v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
                v_n_adopt[i + v_n_adopt.size(0) * b_i];
          }
        }
        st.site = &v_emlrtRSI;
        varargin_1.set_size(&fd_emlrtRTEI, &st,
                            v_n_adopt_p.size(0) * v_n_adopt_p.size(1));
        b_loop_ub = v_n_adopt_p.size(0) * v_n_adopt_p.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          varargin_1[i] = v_n_adopt_p[i] - c_of_a;
        }
        b_st.site = &bd_emlrtRSI;
        c_st.site = &cd_emlrtRSI;
        e_st.site = &dd_emlrtRSI;
        f_st.site = &ed_emlrtRSI;
        g_st.site = &fd_emlrtRSI;
        if (varargin_1.size(0) == v_p_n_expand.size(0)) {
          v_n_best.set_size(&gd_emlrtRTEI, &g_st, varargin_1.size(0));
          b_loop_ub = varargin_1.size(0);
          for (i = 0; i < b_loop_ub; i++) {
            suply_price = varargin_1[i];
            b_error = v_p_n_expand[i];
            v_n_best[i] = muDoubleScalarMax(suply_price, b_error);
          }
        } else {
          h_st.site = &gd_emlrtRSI;
          coder::internal::expand_max(&h_st, varargin_1, v_p_n_expand,
                                      v_n_best);
        }
        st.site = &w_emlrtRSI;
        nx = v_n_best.size(0);
        b_st.site = &hd_emlrtRSI;
        c_st.site = &id_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, a_num_g);
        c_st.site = &id_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, varargin_2);
        idx = v_n_best.size(0);
        if (1 > v_n_best.size(0)) {
          idx = 1;
        }
        nx = muIntScalarMax_sint32(nx, idx);
        if (static_cast<int32_T>(a_num_g) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (static_cast<int32_T>(varargin_2) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (loop_ub_tmp != v_n_best.size(0)) {
          emlrtErrorWithMessageIdR2018a(
              &st, &h_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
              "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }
        v_n_adopt.set_size(&hd_emlrtRTEI, sp, static_cast<int32_T>(varargin_2),
                           static_cast<int32_T>(a_num_g));
        for (i = 0; i < loop_ub; i++) {
          b_loop_ub = static_cast<int32_T>(varargin_2);
          for (b_i = 0; b_i < b_loop_ub; b_i++) {
            v_n_adopt[b_i + v_n_adopt.size(0) * i] =
                v_n_best[i + static_cast<int32_T>(a_num_g) * b_i];
          }
        }
        i = v_p_o.size(0) * v_p_o.size(1);
        if ((v_n_adopt.size(0) != i) &&
            ((v_n_adopt.size(0) != 1) && (i != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_n_adopt.size(0), i, &j_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if (v_n_adopt.size(0) == v_p_o.size(0) * v_p_o.size(1)) {
          v_n_adopt_p.set_size(&id_emlrtRTEI, sp, v_n_adopt.size(0),
                               v_n_adopt.size(1));
          b_loop_ub = v_n_adopt.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            idx = v_n_adopt.size(0);
            for (b_i = 0; b_i < idx; b_i++) {
              v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
                  1.0 -
                  static_cast<real_T>(v_n_adopt[b_i + v_n_adopt.size(0) * i] ==
                                      v_p_o[b_i]);
            }
          }
          v_p_o.set_size(&jd_emlrtRTEI, sp, v_n_adopt_p.size(0),
                         v_n_adopt_p.size(1));
          b_loop_ub = v_n_adopt_p.size(0) * v_n_adopt_p.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            v_p_o[i] = v_n_adopt_p[i];
          }
        } else {
          st.site = &fh_emlrtRSI;
          binary_expand_op(&st, v_p_o, v_n_adopt);
        }
        // %% those who couldn't pay the fco should exit
        pi_contemp_neg_new.set_size(&kd_emlrtRTEI, sp,
                                    pi_contemp_neg_old.size(1),
                                    pi_contemp_neg_old.size(0));
        b_loop_ub = pi_contemp_neg_old.size(0);
        for (i = 0; i < b_loop_ub; i++) {
          idx = pi_contemp_neg_old.size(1);
          for (b_i = 0; b_i < idx; b_i++) {
            pi_contemp_neg_new[b_i + pi_contemp_neg_new.size(0) * i] =
                pi_contemp_neg_old[i + pi_contemp_neg_old.size(0) * b_i];
          }
        }
        exit_vec_o.set_size(
            &ld_emlrtRTEI, sp,
            pi_contemp_neg_new.size(0) * pi_contemp_neg_new.size(1), 1);
        b_loop_ub = pi_contemp_neg_new.size(0) * pi_contemp_neg_new.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          exit_vec_o[i] = pi_contemp_neg_new[i];
        }
        i = pi_contemp_neg_new.size(0) * pi_contemp_neg_new.size(1);
        if ((i != v_p_o.size(0)) && ((i != 1) && (v_p_o.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(i, v_p_o.size(0), &k_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if ((pi_contemp_neg_new.size(0) * pi_contemp_neg_new.size(1) ==
             v_p_o.size(0)) &&
            (1 == v_p_o.size(1))) {
          b_v_n_best[0] =
              pi_contemp_neg_new.size(0) * pi_contemp_neg_new.size(1);
          b_loop_ub = b_v_n_best[0];
          v_p_o.set_size(&md_emlrtRTEI, sp, b_v_n_best[0], 1);
          for (i = 0; i < b_loop_ub; i++) {
            v_p_o[i] =
                (1.0 - static_cast<real_T>(pi_contemp_neg_new[i])) * v_p_o[i];
          }
        } else {
          st.site = &dh_emlrtRSI;
          d_binary_expand_op(&st, v_p_o, pi_contemp_neg_new);
        }
        st.site = &x_emlrtRSI;
        b_st.site = &kd_emlrtRSI;
        coder::dynamic_size_checks(&b_st, v_n_adopt, a_prob, v_n_adopt.size(1),
                                   a_prob.size(1));
        b_st.site = &jd_emlrtRSI;
        coder::internal::blas::mtimes(&b_st, v_n_adopt, a_prob, v_new_o);
        st.site = &y_emlrtRSI;
        nx = v_new_o.size(0);
        b_st.site = &hd_emlrtRSI;
        c_st.site = &id_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, a_num_g);
        c_st.site = &id_emlrtRSI;
        coder::internal::assertValidSizeArg(&c_st, age_num);
        idx = v_new_o.size(0);
        if (1 > v_new_o.size(0)) {
          idx = 1;
        }
        nx = muIntScalarMax_sint32(nx, idx);
        if (static_cast<int32_T>(a_num_g) > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (b_loop_ub_tmp > nx) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
              "Coder:toolbox:reshape_emptyReshapeLimit", 0);
        }
        if (c_loop_ub_tmp != v_new_o.size(0)) {
          emlrtErrorWithMessageIdR2018a(
              &st, &h_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
              "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
        }
        v_new_resh_o.set_size(&nd_emlrtRTEI, sp, b_loop_ub_tmp,
                              static_cast<int32_T>(a_num_g));
        for (i = 0; i < loop_ub; i++) {
          for (b_i = 0; b_i < b_loop_ub_tmp; b_i++) {
            v_new_resh_o[b_i + v_new_resh_o.size(0) * i] =
                beta * v_new_o[i + static_cast<int32_T>(a_num_g) * b_i];
          }
        }
        if ((pi_contemp_old.size(0) != v_new_resh_o.size(0)) &&
            ((pi_contemp_old.size(0) != 1) && (v_new_resh_o.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(pi_contemp_old.size(0),
                                      v_new_resh_o.size(0), &l_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if ((pi_contemp_old.size(1) != v_new_resh_o.size(1)) &&
            ((pi_contemp_old.size(1) != 1) && (v_new_resh_o.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(pi_contemp_old.size(1),
                                      v_new_resh_o.size(1), &m_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if ((pi_contemp_old.size(0) == v_new_resh_o.size(0)) &&
            (pi_contemp_old.size(1) == v_new_resh_o.size(1))) {
          b_loop_ub = pi_contemp_old.size(0) * pi_contemp_old.size(1);
          v_new_resh_o.set_size(&od_emlrtRTEI, sp, pi_contemp_old.size(0),
                                pi_contemp_old.size(1));
          for (i = 0; i < b_loop_ub; i++) {
            v_new_resh_o[i] = pi_contemp_old[i] + v_new_resh_o[i];
          }
        } else {
          st.site = &bh_emlrtRSI;
          b_plus(&st, v_new_resh_o, pi_contemp_old);
        }
        idx = pi_contemp_neg_old.size(0) * pi_contemp_neg_old.size(1) - 1;
        nx = 0;
        for (b_i = 0; b_i <= idx; b_i++) {
          if (pi_contemp_neg_old[b_i]) {
            nx++;
          }
        }
        r6.set_size(&ub_emlrtRTEI, sp, nx);
        nx = 0;
        for (b_i = 0; b_i <= idx; b_i++) {
          if (pi_contemp_neg_old[b_i]) {
            r6[nx] = b_i + 1;
            nx++;
          }
        }
        b_loop_ub = r6.size(0) - 1;
        nx = v_new_resh_o.size(0) * v_new_resh_o.size(1);
        for (i = 0; i <= b_loop_ub; i++) {
          if ((r6[i] < 1) || (r6[i] > nx)) {
            emlrtDynamicBoundsCheckR2012b(r6[i], 1, nx, &ob_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          v_new_resh_o[r6[i] - 1] = 0.0;
        }
        if ((v_of_old.size(0) != v_new_resh_o.size(0)) &&
            ((v_of_old.size(0) != 1) && (v_new_resh_o.size(0) != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_of_old.size(0), v_new_resh_o.size(0),
                                      &n_emlrtECI, (emlrtCTX)sp);
        }
        if ((v_of_old.size(1) != v_new_resh_o.size(1)) &&
            ((v_of_old.size(1) != 1) && (v_new_resh_o.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(v_of_old.size(1), v_new_resh_o.size(1),
                                      &o_emlrtECI, (emlrtCTX)sp);
        }
        st.site = &ab_emlrtRSI;
        if ((v_of_old.size(0) == v_new_resh_o.size(0)) &&
            (v_of_old.size(1) == v_new_resh_o.size(1))) {
          v_n_adopt_p.set_size(&pd_emlrtRTEI, &st, v_of_old.size(0),
                               v_of_old.size(1));
          b_loop_ub = v_of_old.size(0) * v_of_old.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            v_n_adopt_p[i] = v_of_old[i] - v_new_resh_o[i];
          }
          b_st.site = &ab_emlrtRSI;
          coder::b_abs(&b_st, v_n_adopt_p, v_n_adopt);
        } else {
          b_st.site = &ab_emlrtRSI;
          c_binary_expand_op(&b_st, v_n_adopt, ab_emlrtRSI, v_of_old,
                             v_new_resh_o);
        }
        b_st.site = &bd_emlrtRSI;
        c_st.site = &pd_emlrtRSI;
        e_st.site = &qd_emlrtRSI;
        f_st.site = &rd_emlrtRSI;
        b_error = coder::internal::applyToMultipleDims(&f_st, v_n_adopt);
        if (b_error < v_tol) {
          st.site = &bb_emlrtRSI;
          b_st.site = &ce_emlrtRSI;
          c_st.site = &xg_emlrtRSI;
          d_st.site = &yg_emlrtRSI;
          emlrt_marshallIn(
              &c_st,
              feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                    b_emlrt_marshallOut(&d_st, cv3),
                    emlrt_marshallOut(static_cast<real_T>(i2) + 1.0),
                    &emlrtMCI),
              "<output of feval>");
          exitg3 = true;
        } else {
          v_of_old.set_size(&qd_emlrtRTEI, sp, v_new_resh_o.size(0),
                            v_new_resh_o.size(1));
          b_loop_ub = v_new_resh_o.size(0) * v_new_resh_o.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            v_of_old[i] = v_new_resh_o[i];
          }
          i2++;
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
      st.site = &cb_emlrtRSI;
      coder::b_sparse(&st, a_num_g * age_num, a_num_g * age_num,
                      trans_matrix_n);
      st.site = &db_emlrtRSI;
      coder::repmat(&st, a_prob, age_num * a_num_g, v_n_adopt);
      if ((v_p_n.size(0) != v_n_adopt.size(0)) &&
          ((v_p_n.size(0) != 1) && (v_n_adopt.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_n.size(0), v_n_adopt.size(0),
                                    &p_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_p_n.size(1) != v_n_adopt.size(1)) &&
          ((v_p_n.size(1) != 1) && (v_n_adopt.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_n.size(1), v_n_adopt.size(1),
                                    &q_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_p_n.size(0) == v_n_adopt.size(0)) &&
          (v_p_n.size(1) == v_n_adopt.size(1))) {
        b_loop_ub = v_p_n.size(0) * v_p_n.size(1);
        v_n_adopt.set_size(&rd_emlrtRTEI, sp, v_p_n.size(0), v_p_n.size(1));
        for (i = 0; i < b_loop_ub; i++) {
          v_n_adopt[i] = v_p_n[i] * v_n_adopt[i];
        }
      } else {
        st.site = &db_emlrtRSI;
        times(&st, v_n_adopt, v_p_n);
      }
      if ((v_n_adopt.size(0) != exit_vec_n.size(0)) &&
          ((v_n_adopt.size(0) != 1) && (exit_vec_n.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_n_adopt.size(0), exit_vec_n.size(0),
                                    &p_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_n_adopt.size(1) != exit_vec_n.size(1)) &&
          ((v_n_adopt.size(1) != 1) && (exit_vec_n.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_n_adopt.size(1), exit_vec_n.size(1),
                                    &q_emlrtECI, (emlrtCTX)sp);
      }
      if (a_num_g < 1.0) {
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, 0);
      } else {
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      if ((v_n_adopt.size(0) == exit_vec_n.size(0)) &&
          (v_n_adopt.size(1) == exit_vec_n.size(1))) {
        v_n_adopt_p.set_size(&rd_emlrtRTEI, sp, v_n_adopt.size(0),
                             v_n_adopt.size(1));
        b_loop_ub = v_n_adopt.size(0) * v_n_adopt.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          v_n_adopt_p[i] =
              v_n_adopt[i] * (1.0 - static_cast<real_T>(exit_vec_n[i]));
        }
        st.site = &db_emlrtRSI;
        trans_matrix_n->parenAssign(&st, v_n_adopt_p, dist_ent);
      } else {
        st.site = &db_emlrtRSI;
        b_binary_expand_op(&st, db_emlrtRSI, trans_matrix_n, v_n_adopt,
                           exit_vec_n, dist_ent);
      }
      st.site = &eb_emlrtRSI;
      coder::repmat(&st, a_prob, age_num * a_num_g, v_n_adopt);
      if ((v_p_n.size(0) != v_n_adopt.size(0)) &&
          ((v_p_n.size(0) != 1) && (v_n_adopt.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_n.size(0), v_n_adopt.size(0),
                                    &r_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_p_n.size(1) != v_n_adopt.size(1)) &&
          ((v_p_n.size(1) != 1) && (v_n_adopt.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_n.size(1), v_n_adopt.size(1),
                                    &s_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_p_n.size(0) == v_n_adopt.size(0)) &&
          (v_p_n.size(1) == v_n_adopt.size(1))) {
        v_n_adopt_p.set_size(&td_emlrtRTEI, sp, v_p_n.size(0), v_p_n.size(1));
        b_loop_ub = v_p_n.size(0) * v_p_n.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          v_n_adopt_p[i] = (1.0 - v_p_n[i]) * v_n_adopt[i];
        }
        st.site = &eb_emlrtRSI;
        coder::sum(&st, v_n_adopt_p, v_p_n_expand);
      } else {
        st.site = &eb_emlrtRSI;
        binary_expand_op(&st, v_p_n_expand, eb_emlrtRSI, v_p_n, v_n_adopt);
      }
      if (age_num - 1.0 < 1.0) {
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, 0);
      } else {
        b_loop_ub = b_loop_ub_tmp - 2;
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, b_loop_ub_tmp - 1);
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      r.set_size(&ud_emlrtRTEI, sp, 1, static_cast<int32_T>(a_num_g));
      for (i = 0; i < loop_ub; i++) {
        r[i] = 1.0;
      }
      st.site = &fb_emlrtRSI;
      coder::b_kron(&st, dist_ent, r, a_cdf);
      st.site = &fb_emlrtRSI;
      b_st.site = &oc_emlrtRSI;
      c_st.site = &pc_emlrtRSI;
      suply_price = a_num_g * a_num_g;
      a_cdf.set_size(&vd_emlrtRTEI, sp, 1, a_cdf.size(1));
      b_loop_ub = a_cdf.size(1) - 1;
      for (i = 0; i <= b_loop_ub; i++) {
        a_cdf[i] = a_cdf[i] * age_num * suply_price;
      }
      b_error = (age_num - 1.0) * a_num_g;
      if (muDoubleScalarIsNaN(b_error)) {
        r.set_size(&wd_emlrtRTEI, sp, 1, 1);
        r[0] = rtNaN;
      } else if (b_error < 1.0) {
        r.set_size(&wd_emlrtRTEI, sp, 1, 0);
      } else if (muDoubleScalarIsInf(b_error) && (1.0 == b_error)) {
        r.set_size(&wd_emlrtRTEI, sp, 1, 1);
        r[0] = rtNaN;
      } else {
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(b_error - 1.0));
        r.set_size(&wd_emlrtRTEI, sp, 1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          r[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      if ((a_cdf.size(1) != r.size(1)) &&
          ((a_cdf.size(1) != 1) && (r.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(a_cdf.size(1), r.size(1), &t_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if (a_cdf.size(1) == r.size(1)) {
        b_loop_ub = a_cdf.size(1) - 1;
        a_cdf.set_size(&vd_emlrtRTEI, sp, 1, a_cdf.size(1));
        for (i = 0; i <= b_loop_ub; i++) {
          a_cdf[i] = a_cdf[i] + r[i];
        }
      } else {
        st.site = &fb_emlrtRSI;
        plus(&st, a_cdf, r);
      }
      if (a_num_g - 1.0 < 0.0) {
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, 0);
      } else {
        dist_ent.set_size(
            &sd_emlrtRTEI, sp, 1,
            static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0)) + 1);
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = i;
        }
      }
      if (!(age_num - 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(age_num - 1.0, &ib_emlrtDCI, (emlrtCTX)sp);
      }
      if (age_num - 1.0 != age_num - 1.0) {
        emlrtIntegerCheckR2012b(age_num - 1.0, &hb_emlrtDCI, (emlrtCTX)sp);
      }
      nx = static_cast<int32_T>(age_num) - 1;
      b_v_of_new.set_size(&xd_emlrtRTEI, sp, 1, nx);
      for (i = 0; i < nx; i++) {
        b_v_of_new[i] = 1.0;
      }
      st.site = &gb_emlrtRSI;
      coder::b_kron(&st, b_v_of_new, dist_ent, a);
      a.set_size(&yd_emlrtRTEI, sp, 1, a.size(1));
      b_loop_ub = a.size(1) - 1;
      for (i = 0; i <= b_loop_ub; i++) {
        a[i] = a[i] * age_num * a_num_g;
      }
      if ((a_cdf.size(1) != a.size(1)) &&
          ((a_cdf.size(1) != 1) && (a.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(a_cdf.size(1), a.size(1), &t_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if (1.0 > b_error) {
        b_loop_ub = 0;
      } else {
        if (1 > v_p_n_expand.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, v_p_n_expand.size(0), &o_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (b_error != static_cast<int32_T>(muDoubleScalarFloor(b_error))) {
          emlrtIntegerCheckR2012b(b_error, &d_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error) < 1) ||
            (static_cast<int32_T>(b_error) > v_p_n_expand.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error), 1,
                                        v_p_n_expand.size(0), &p_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_loop_ub = static_cast<int32_T>(b_error);
      }
      iv[0] = 1;
      iv[1] = b_loop_ub;
      st.site = &hb_emlrtRSI;
      coder::internal::indexShapeCheck(&st, v_p_n_expand.size(0), iv);
      if (1.0 > b_error) {
        idx = 0;
      } else {
        if (1 > exit_vec_n.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec_n.size(0), &q_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (b_error != static_cast<int32_T>(muDoubleScalarFloor(b_error))) {
          emlrtIntegerCheckR2012b(b_error, &e_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error) < 1) ||
            (static_cast<int32_T>(b_error) > exit_vec_n.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error), 1,
                                        exit_vec_n.size(0), &r_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        idx = static_cast<int32_T>(b_error);
      }
      if (1 > exit_vec_n.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec_n.size(1), &s_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      v_n_best.set_size(&ae_emlrtRTEI, sp, idx);
      for (i = 0; i < idx; i++) {
        v_n_best[i] = exit_vec_n[i];
      }
      if ((b_loop_ub != v_n_best.size(0)) &&
          ((b_loop_ub != 1) && (v_n_best.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(b_loop_ub, v_n_best.size(0), &u_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if ((b_loop_ub == v_n_best.size(0)) && (a_cdf.size(1) == a.size(1))) {
        v_n_best.set_size(&be_emlrtRTEI, sp, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          v_n_best[i] = v_p_n_expand[i] * (1.0 - v_n_best[i]);
        }
        b_v_of_new.set_size(&vd_emlrtRTEI, sp, 1, a_cdf.size(1));
        b_loop_ub = a_cdf.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          b_v_of_new[i] = a_cdf[i] + a[i];
        }
        st.site = &hb_emlrtRSI;
        trans_matrix_n->parenAssign(&st, v_n_best, b_v_of_new);
      } else {
        st.site = &hb_emlrtRSI;
        binary_expand_op(&st, hb_emlrtRSI, trans_matrix_n, v_p_n_expand,
                         b_loop_ub - 1, v_n_best, a_cdf, a);
      }
      st.site = &ib_emlrtRSI;
      coder::b_sparse(&st, a_num_g * age_num, a_num_g * age_num,
                      trans_matrix_o);
      st.site = &jb_emlrtRSI;
      coder::repmat(&st, a_prob, age_num * a_num_g, v_n_adopt);
      if ((v_p_o.size(0) != v_n_adopt.size(0)) &&
          ((v_p_o.size(0) != 1) && (v_n_adopt.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_o.size(0), v_n_adopt.size(0),
                                    &v_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_p_o.size(1) != v_n_adopt.size(1)) &&
          ((v_p_o.size(1) != 1) && (v_n_adopt.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_o.size(1), v_n_adopt.size(1),
                                    &w_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_p_o.size(0) == v_n_adopt.size(0)) &&
          (v_p_o.size(1) == v_n_adopt.size(1))) {
        b_loop_ub = v_p_o.size(0) * v_p_o.size(1);
        v_n_adopt.set_size(&ce_emlrtRTEI, sp, v_p_o.size(0), v_p_o.size(1));
        for (i = 0; i < b_loop_ub; i++) {
          v_n_adopt[i] = v_p_o[i] * v_n_adopt[i];
        }
      } else {
        st.site = &jb_emlrtRSI;
        times(&st, v_n_adopt, v_p_o);
      }
      if ((v_n_adopt.size(0) != exit_vec_o.size(0)) &&
          ((v_n_adopt.size(0) != 1) && (exit_vec_o.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_n_adopt.size(0), exit_vec_o.size(0),
                                    &v_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_n_adopt.size(1) != exit_vec_o.size(1)) &&
          ((v_n_adopt.size(1) != 1) && (exit_vec_o.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_n_adopt.size(1), exit_vec_o.size(1),
                                    &w_emlrtECI, (emlrtCTX)sp);
      }
      if (a_num_g < 1.0) {
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, 0);
      } else {
        dist_ent.set_size(
            &sd_emlrtRTEI, sp, 1,
            static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0)) + 1);
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      if ((v_n_adopt.size(0) == exit_vec_o.size(0)) &&
          (v_n_adopt.size(1) == exit_vec_o.size(1))) {
        v_n_adopt_p.set_size(&ce_emlrtRTEI, sp, v_n_adopt.size(0),
                             v_n_adopt.size(1));
        b_loop_ub = v_n_adopt.size(0) * v_n_adopt.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          v_n_adopt_p[i] =
              v_n_adopt[i] * (1.0 - static_cast<real_T>(exit_vec_o[i]));
        }
        st.site = &jb_emlrtRSI;
        trans_matrix_o->parenAssign(&st, v_n_adopt_p, dist_ent);
      } else {
        st.site = &jb_emlrtRSI;
        b_binary_expand_op(&st, jb_emlrtRSI, trans_matrix_o, v_n_adopt,
                           exit_vec_o, dist_ent);
      }
      st.site = &kb_emlrtRSI;
      coder::repmat(&st, a_prob, age_num * a_num_g, v_n_adopt);
      if ((v_p_o.size(0) != v_n_adopt.size(0)) &&
          ((v_p_o.size(0) != 1) && (v_n_adopt.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_o.size(0), v_n_adopt.size(0),
                                    &x_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_p_o.size(1) != v_n_adopt.size(1)) &&
          ((v_p_o.size(1) != 1) && (v_n_adopt.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_p_o.size(1), v_n_adopt.size(1),
                                    &y_emlrtECI, (emlrtCTX)sp);
      }
      if ((v_p_o.size(0) == v_n_adopt.size(0)) &&
          (v_p_o.size(1) == v_n_adopt.size(1))) {
        v_n_adopt_p.set_size(&de_emlrtRTEI, sp, v_p_o.size(0), v_p_o.size(1));
        b_loop_ub = v_p_o.size(0) * v_p_o.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          v_n_adopt_p[i] = (1.0 - v_p_o[i]) * v_n_adopt[i];
        }
        st.site = &kb_emlrtRSI;
        coder::sum(&st, v_n_adopt_p, v_p_n_expand);
      } else {
        st.site = &kb_emlrtRSI;
        binary_expand_op(&st, v_p_n_expand, kb_emlrtRSI, v_p_o, v_n_adopt);
      }
      if (age_num - 1.0 < 1.0) {
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, 0);
      } else {
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, nx);
        b_loop_ub = static_cast<int32_T>(age_num) - 2;
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      b_v_of_new.set_size(&ee_emlrtRTEI, sp, 1, static_cast<int32_T>(a_num_g));
      for (i = 0; i < loop_ub; i++) {
        b_v_of_new[i] = 1.0;
      }
      st.site = &lb_emlrtRSI;
      coder::b_kron(&st, dist_ent, b_v_of_new, a_cdf);
      st.site = &lb_emlrtRSI;
      b_st.site = &oc_emlrtRSI;
      c_st.site = &pc_emlrtRSI;
      a_cdf.set_size(&fe_emlrtRTEI, sp, 1, a_cdf.size(1));
      b_loop_ub = a_cdf.size(1) - 1;
      for (i = 0; i <= b_loop_ub; i++) {
        a_cdf[i] = a_cdf[i] * age_num * suply_price;
      }
      if ((a_cdf.size(1) != r.size(1)) &&
          ((a_cdf.size(1) != 1) && (r.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(a_cdf.size(1), r.size(1), &ab_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if (a_cdf.size(1) == r.size(1)) {
        b_loop_ub = a_cdf.size(1) - 1;
        a_cdf.set_size(&fe_emlrtRTEI, sp, 1, a_cdf.size(1));
        for (i = 0; i <= b_loop_ub; i++) {
          a_cdf[i] = a_cdf[i] + r[i];
        }
      } else {
        st.site = &lb_emlrtRSI;
        plus(&st, a_cdf, r);
      }
      if (a_num_g - 1.0 < 0.0) {
        dist_ent.set_size(&sd_emlrtRTEI, sp, 1, 0);
      } else {
        dist_ent.set_size(
            &sd_emlrtRTEI, sp, 1,
            static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0)) + 1);
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = i;
        }
      }
      if (!(age_num - 1.0 >= 0.0)) {
        emlrtNonNegativeCheckR2012b(age_num - 1.0, &kb_emlrtDCI, (emlrtCTX)sp);
      }
      if (age_num - 1.0 != age_num - 1.0) {
        emlrtIntegerCheckR2012b(age_num - 1.0, &jb_emlrtDCI, (emlrtCTX)sp);
      }
      r.set_size(&ge_emlrtRTEI, sp, 1, nx);
      for (i = 0; i < nx; i++) {
        r[i] = 1.0;
      }
      st.site = &mb_emlrtRSI;
      coder::b_kron(&st, r, dist_ent, a);
      a.set_size(&he_emlrtRTEI, sp, 1, a.size(1));
      b_loop_ub = a.size(1) - 1;
      for (i = 0; i <= b_loop_ub; i++) {
        a[i] = a[i] * age_num * a_num_g;
      }
      if ((a_cdf.size(1) != a.size(1)) &&
          ((a_cdf.size(1) != 1) && (a.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(a_cdf.size(1), a.size(1), &ab_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if (1.0 > b_error) {
        b_loop_ub = 0;
      } else {
        if (1 > v_p_n_expand.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, v_p_n_expand.size(0), &t_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (b_error != static_cast<int32_T>(muDoubleScalarFloor(b_error))) {
          emlrtIntegerCheckR2012b(b_error, &f_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error) < 1) ||
            (static_cast<int32_T>(b_error) > v_p_n_expand.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error), 1,
                                        v_p_n_expand.size(0), &u_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_loop_ub = static_cast<int32_T>(b_error);
      }
      iv[0] = 1;
      iv[1] = b_loop_ub;
      st.site = &nb_emlrtRSI;
      coder::internal::indexShapeCheck(&st, v_p_n_expand.size(0), iv);
      if (1.0 > b_error) {
        idx = 0;
      } else {
        if (1 > exit_vec_o.size(0)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec_o.size(0), &v_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (b_error != static_cast<int32_T>(muDoubleScalarFloor(b_error))) {
          emlrtIntegerCheckR2012b(b_error, &g_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error) < 1) ||
            (static_cast<int32_T>(b_error) > exit_vec_o.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error), 1,
                                        exit_vec_o.size(0), &w_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        idx = static_cast<int32_T>(b_error);
      }
      if (1 > exit_vec_o.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec_o.size(1), &x_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      v_n_best.set_size(&ie_emlrtRTEI, sp, idx);
      for (i = 0; i < idx; i++) {
        v_n_best[i] = exit_vec_o[i];
      }
      if ((b_loop_ub != v_n_best.size(0)) &&
          ((b_loop_ub != 1) && (v_n_best.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(b_loop_ub, v_n_best.size(0), &bb_emlrtECI,
                                    (emlrtCTX)sp);
      }
      if ((b_loop_ub == v_n_best.size(0)) && (a_cdf.size(1) == a.size(1))) {
        v_n_best.set_size(&je_emlrtRTEI, sp, b_loop_ub);
        for (i = 0; i < b_loop_ub; i++) {
          v_n_best[i] = v_p_n_expand[i] * (1.0 - v_n_best[i]);
        }
        b_v_of_new.set_size(&fe_emlrtRTEI, sp, 1, a_cdf.size(1));
        b_loop_ub = a_cdf.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          b_v_of_new[i] = a_cdf[i] + a[i];
        }
        st.site = &nb_emlrtRSI;
        trans_matrix_o->parenAssign(&st, v_n_best, b_v_of_new);
      } else {
        st.site = &nb_emlrtRSI;
        binary_expand_op(&st, nb_emlrtRSI, trans_matrix_o, v_p_n_expand,
                         b_loop_ub - 1, v_n_best, a_cdf, a);
      }
      // %% also those who are at the last period would die if they don't adopt
      // to
      // %% any technology and a new firm would enter with a random technology
      // %% meaning for those states with the highest age the transition would
      // be
      // %% randomly to age 0 and tech in [0, a_max]
      if (b_error + 1.0 > varargin_2) {
        i = 0;
        b_i = 0;
      } else {
        if (b_error + 1.0 !=
            static_cast<int32_T>(muDoubleScalarFloor(b_error + 1.0))) {
          emlrtIntegerCheckR2012b(b_error + 1.0, &h_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error + 1.0) < 1) ||
            (static_cast<int32_T>(b_error + 1.0) > exit_vec_n.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error + 1.0), 1,
                                        exit_vec_n.size(0), &y_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        i = static_cast<int32_T>(b_error + 1.0) - 1;
        if (varargin_2 != d) {
          emlrtIntegerCheckR2012b(varargin_2, &i_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(varargin_2) < 1) ||
            (static_cast<int32_T>(varargin_2) > exit_vec_n.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(varargin_2), 1,
                                        exit_vec_n.size(0), &ab_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_i = static_cast<int32_T>(varargin_2);
      }
      st.site = &ob_emlrtRSI;
      coder::repmat(&st, a_prob, a_num_g, v_n_adopt);
      if (1 > exit_vec_n.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec_n.size(1), &bb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_loop_ub = b_i - i;
      v_n_best.set_size(&ke_emlrtRTEI, sp, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        v_n_best[b_i] = exit_vec_n[i + b_i];
      }
      if ((v_n_adopt.size(0) != v_n_best.size(0)) &&
          ((v_n_adopt.size(0) != 1) && (v_n_best.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_n_adopt.size(0), v_n_best.size(0),
                                    &cb_emlrtECI, (emlrtCTX)sp);
      }
      st.site = &qb_emlrtRSI;
      b_st.site = &eg_emlrtRSI;
      if (muDoubleScalarIsNaN(b_error + 1.0)) {
        dist_ent.set_size(&sd_emlrtRTEI, &b_st, 1, 1);
        dist_ent[0] = rtNaN;
      } else if (varargin_2 < b_error + 1.0) {
        dist_ent.set_size(&sd_emlrtRTEI, &b_st, 1, 0);
      } else if ((muDoubleScalarIsInf(b_error + 1.0) ||
                  muDoubleScalarIsInf(varargin_2)) &&
                 (b_error + 1.0 == varargin_2)) {
        dist_ent.set_size(&sd_emlrtRTEI, &b_st, 1, 1);
        dist_ent[0] = rtNaN;
      } else if (b_error + 1.0 == b_error + 1.0) {
        b_loop_ub = static_cast<int32_T>(
            muDoubleScalarFloor(varargin_2 - (b_error + 1.0)));
        dist_ent.set_size(&sd_emlrtRTEI, &b_st, 1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = (b_error + 1.0) + static_cast<real_T>(i);
        }
      } else {
        c_st.site = &fg_emlrtRSI;
        coder::eml_float_colon(&c_st, b_error + 1.0, varargin_2, dist_ent);
      }
      if (a_num_g < 1.0) {
        a_cdf.set_size(&sd_emlrtRTEI, sp, 1, 0);
      } else {
        a_cdf.set_size(
            &sd_emlrtRTEI, sp, 1,
            static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0)) + 1);
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        for (i = 0; i <= b_loop_ub; i++) {
          a_cdf[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      if (v_n_adopt.size(0) == v_n_best.size(0)) {
        v_n_adopt_p.set_size(&le_emlrtRTEI, sp, v_n_adopt.size(0),
                             v_n_adopt.size(1));
        b_loop_ub = v_n_adopt.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_n_adopt.size(0);
          for (b_i = 0; b_i < idx; b_i++) {
            v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
                v_n_adopt[b_i + v_n_adopt.size(0) * i] * (1.0 - v_n_best[b_i]);
          }
        }
        v_n_adopt.set_size(&le_emlrtRTEI, sp, v_n_adopt_p.size(0),
                           v_n_adopt_p.size(1));
        b_loop_ub = v_n_adopt_p.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_n_adopt_p.size(0);
          for (b_i = 0; b_i < idx; b_i++) {
            v_n_adopt[b_i + v_n_adopt.size(0) * i] =
                v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i];
          }
        }
        st.site = &qb_emlrtRSI;
        trans_matrix_n->parenAssign(&st, v_n_adopt, dist_ent, a_cdf);
      } else {
        st.site = &qb_emlrtRSI;
        binary_expand_op(&st, qb_emlrtRSI, trans_matrix_n, v_n_adopt, v_n_best,
                         dist_ent, a_cdf);
      }
      if (b_error + 1.0 > varargin_2) {
        i = 0;
        b_i = 0;
      } else {
        if (b_error + 1.0 !=
            static_cast<int32_T>(muDoubleScalarFloor(b_error + 1.0))) {
          emlrtIntegerCheckR2012b(b_error + 1.0, &j_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_error + 1.0) < 1) ||
            (static_cast<int32_T>(b_error + 1.0) > exit_vec_o.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_error + 1.0), 1,
                                        exit_vec_o.size(0), &cb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        i = static_cast<int32_T>(b_error + 1.0) - 1;
        if (varargin_2 != d) {
          emlrtIntegerCheckR2012b(varargin_2, &k_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(varargin_2) < 1) ||
            (static_cast<int32_T>(varargin_2) > exit_vec_o.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(varargin_2), 1,
                                        exit_vec_o.size(0), &db_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_i = static_cast<int32_T>(varargin_2);
      }
      st.site = &pb_emlrtRSI;
      coder::repmat(&st, a_prob, a_num_g, v_n_adopt);
      if (1 > exit_vec_o.size(1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, exit_vec_o.size(1), &eb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_loop_ub = b_i - i;
      v_n_best.set_size(&me_emlrtRTEI, sp, b_loop_ub);
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        v_n_best[b_i] = exit_vec_o[i + b_i];
      }
      if ((v_n_adopt.size(0) != v_n_best.size(0)) &&
          ((v_n_adopt.size(0) != 1) && (v_n_best.size(0) != 1))) {
        emlrtDimSizeImpxCheckR2021b(v_n_adopt.size(0), v_n_best.size(0),
                                    &db_emlrtECI, (emlrtCTX)sp);
      }
      st.site = &vb_emlrtRSI;
      b_st.site = &eg_emlrtRSI;
      if (muDoubleScalarIsNaN(b_error + 1.0)) {
        dist_ent.set_size(&sd_emlrtRTEI, &b_st, 1, 1);
        dist_ent[0] = rtNaN;
      } else if (varargin_2 < b_error + 1.0) {
        dist_ent.set_size(&sd_emlrtRTEI, &b_st, 1, 0);
      } else if ((muDoubleScalarIsInf(b_error + 1.0) ||
                  muDoubleScalarIsInf(varargin_2)) &&
                 (b_error + 1.0 == varargin_2)) {
        dist_ent.set_size(&sd_emlrtRTEI, &b_st, 1, 1);
        dist_ent[0] = rtNaN;
      } else if (b_error + 1.0 == b_error + 1.0) {
        b_loop_ub = static_cast<int32_T>(
            muDoubleScalarFloor(varargin_2 - (b_error + 1.0)));
        dist_ent.set_size(&sd_emlrtRTEI, &b_st, 1, b_loop_ub + 1);
        for (i = 0; i <= b_loop_ub; i++) {
          dist_ent[i] = (b_error + 1.0) + static_cast<real_T>(i);
        }
      } else {
        c_st.site = &fg_emlrtRSI;
        coder::eml_float_colon(&c_st, b_error + 1.0, varargin_2, dist_ent);
      }
      if (a_num_g < 1.0) {
        a_cdf.set_size(&sd_emlrtRTEI, sp, 1, 0);
      } else {
        a_cdf.set_size(
            &sd_emlrtRTEI, sp, 1,
            static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0)) + 1);
        b_loop_ub = static_cast<int32_T>(muDoubleScalarFloor(a_num_g - 1.0));
        for (i = 0; i <= b_loop_ub; i++) {
          a_cdf[i] = static_cast<real_T>(i) + 1.0;
        }
      }
      if (v_n_adopt.size(0) == v_n_best.size(0)) {
        v_n_adopt_p.set_size(&ne_emlrtRTEI, sp, v_n_adopt.size(0),
                             v_n_adopt.size(1));
        b_loop_ub = v_n_adopt.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_n_adopt.size(0);
          for (b_i = 0; b_i < idx; b_i++) {
            v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i] =
                v_n_adopt[b_i + v_n_adopt.size(0) * i] * (1.0 - v_n_best[b_i]);
          }
        }
        v_n_adopt.set_size(&ne_emlrtRTEI, sp, v_n_adopt_p.size(0),
                           v_n_adopt_p.size(1));
        b_loop_ub = v_n_adopt_p.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          idx = v_n_adopt_p.size(0);
          for (b_i = 0; b_i < idx; b_i++) {
            v_n_adopt[b_i + v_n_adopt.size(0) * i] =
                v_n_adopt_p[b_i + v_n_adopt_p.size(0) * i];
          }
        }
        st.site = &vb_emlrtRSI;
        trans_matrix_o->parenAssign(&st, v_n_adopt, dist_ent, a_cdf);
      } else {
        st.site = &vb_emlrtRSI;
        binary_expand_op(&st, vb_emlrtRSI, trans_matrix_o, v_n_adopt, v_n_best,
                         dist_ent, a_cdf);
      }
      dist_n.set_size(&oe_emlrtRTEI, sp, 1, dist_n.size(1));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &v_emlrtDCI, (emlrtCTX)sp);
      }
      dist_n.set_size(&oe_emlrtRTEI, sp, dist_n.size(0),
                      static_cast<int32_T>(varargin_2));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &lb_emlrtDCI, (emlrtCTX)sp);
      }
      b_loop_ub = static_cast<int32_T>(varargin_2);
      for (i = 0; i < b_loop_ub; i++) {
        dist_n[i] = 1.0;
      }
      dist_n.set_size(&pe_emlrtRTEI, sp, 1, dist_n.size(1));
      b_loop_ub = dist_n.size(1) - 1;
      for (i = 0; i <= b_loop_ub; i++) {
        dist_n[i] = *m_of_firms_new * dist_n[i] / varargin_2;
      }
      dist_o.set_size(&qe_emlrtRTEI, sp, 1, dist_o.size(1));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &w_emlrtDCI, (emlrtCTX)sp);
      }
      dist_o.set_size(&qe_emlrtRTEI, sp, dist_o.size(0),
                      static_cast<int32_T>(varargin_2));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &mb_emlrtDCI, (emlrtCTX)sp);
      }
      b_loop_ub = static_cast<int32_T>(varargin_2);
      for (i = 0; i < b_loop_ub; i++) {
        dist_o[i] = 1.0;
      }
      dist_o.set_size(&re_emlrtRTEI, sp, 1, dist_o.size(1));
      b_loop_ub = dist_o.size(1) - 1;
      for (i = 0; i <= b_loop_ub; i++) {
        dist_o[i] = *m_of_firms_old * dist_o[i] / varargin_2;
      }
      dist_ent.set_size(&se_emlrtRTEI, sp, 1, dist_ent.size(1));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &x_emlrtDCI, (emlrtCTX)sp);
      }
      dist_ent.set_size(&se_emlrtRTEI, sp, dist_ent.size(0),
                        static_cast<int32_T>(varargin_2));
      if (varargin_2 != d) {
        emlrtIntegerCheckR2012b(varargin_2, &nb_emlrtDCI, (emlrtCTX)sp);
      }
      b_loop_ub = static_cast<int32_T>(varargin_2);
      for (i = 0; i < b_loop_ub; i++) {
        dist_ent[i] = 0.0;
      }
      if (1.0 > a_num_g) {
        b_loop_ub = 0;
      } else {
        if (1 > static_cast<int32_T>(varargin_2)) {
          emlrtDynamicBoundsCheckR2012b(1, 1, static_cast<int32_T>(varargin_2),
                                        &fb_emlrtBCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(a_num_g) < 1) ||
            (static_cast<int32_T>(a_num_g) >
             static_cast<int32_T>(varargin_2))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(a_num_g), 1,
                                        static_cast<int32_T>(varargin_2),
                                        &gb_emlrtBCI, (emlrtCTX)sp);
        }
        b_loop_ub = static_cast<int32_T>(a_num_g);
      }
      for (i = 0; i < b_loop_ub; i++) {
        dist_ent[i] = 1.0 / a_num_g;
      }
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter, mxDOUBLE_CLASS,
                                    static_cast<int32_T>(max_iter),
                                    &e_emlrtRTEI, (emlrtCTX)sp);
      i2 = 0;
      exitg3 = false;
      while ((!exitg3) && (i2 <= static_cast<int32_T>(max_iter) - 1)) {
        st.site = &rb_emlrtRSI;
        trans_matrix_n->mtimes(&st, dist_n, a_cdf);
        st.site = &sb_emlrtRSI;
        suply_price = *m_of_firms_new - coder::sum(&st, a_cdf);
        r.set_size(&te_emlrtRTEI, sp, 1, dist_ent.size(1));
        b_loop_ub = dist_ent.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          r[i] = suply_price * dist_ent[i];
        }
        if ((a_cdf.size(1) != r.size(1)) &&
            ((a_cdf.size(1) != 1) && (r.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(a_cdf.size(1), r.size(1), &eb_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if (a_cdf.size(1) == r.size(1)) {
          b_loop_ub = a_cdf.size(1) - 1;
          a_cdf.set_size(&ue_emlrtRTEI, sp, 1, a_cdf.size(1));
          for (i = 0; i <= b_loop_ub; i++) {
            a_cdf[i] = a_cdf[i] + r[i];
          }
        } else {
          st.site = &sb_emlrtRSI;
          plus(&st, a_cdf, r);
        }
        if ((a_cdf.size(1) != dist_n.size(1)) &&
            ((a_cdf.size(1) != 1) && (dist_n.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(a_cdf.size(1), dist_n.size(1),
                                      &fb_emlrtECI, (emlrtCTX)sp);
        }
        st.site = &tb_emlrtRSI;
        if (a_cdf.size(1) == dist_n.size(1)) {
          b_v_of_new.set_size(&ve_emlrtRTEI, &st, 1, a_cdf.size(1));
          b_loop_ub = a_cdf.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            b_v_of_new[i] = a_cdf[i] - dist_n[i];
          }
          b_st.site = &tb_emlrtRSI;
          coder::c_abs(&b_st, b_v_of_new, a);
        } else {
          b_st.site = &tb_emlrtRSI;
          binary_expand_op(&b_st, a, tb_emlrtRSI, a_cdf, dist_n);
        }
        b_st.site = &bd_emlrtRSI;
        c_st.site = &pd_emlrtRSI;
        e_st.site = &qd_emlrtRSI;
        if (a.size(1) < 1) {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &j_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        f_st.site = &vd_emlrtRSI;
        g_st.site = &wd_emlrtRSI;
        nx = a.size(1);
        if (a.size(1) <= 2) {
          if (a.size(1) == 1) {
            b_error = a[0];
          } else if ((a[0] < a[1]) || (muDoubleScalarIsNaN(a[0]) &&
                                       (!muDoubleScalarIsNaN(a[1])))) {
            b_error = a[1];
          } else {
            b_error = a[0];
          }
        } else {
          h_st.site = &yd_emlrtRSI;
          if (!muDoubleScalarIsNaN(a[0])) {
            idx = 1;
          } else {
            idx = 0;
            i_st.site = &ae_emlrtRSI;
            if (a.size(1) > 2147483646) {
              j_st.site = &uc_emlrtRSI;
              coder::check_forloop_overflow_error(&j_st);
            }
            b_loop_ub = 2;
            exitg4 = false;
            while ((!exitg4) && (b_loop_ub <= nx)) {
              if (!muDoubleScalarIsNaN(a[b_loop_ub - 1])) {
                idx = b_loop_ub;
                exitg4 = true;
              } else {
                b_loop_ub++;
              }
            }
          }
          if (idx == 0) {
            b_error = a[0];
          } else {
            h_st.site = &xd_emlrtRSI;
            b_error = a[idx - 1];
            i1 = idx + 1;
            i_st.site = &be_emlrtRSI;
            if ((idx + 1 <= a.size(1)) && (a.size(1) > 2147483646)) {
              j_st.site = &uc_emlrtRSI;
              coder::check_forloop_overflow_error(&j_st);
            }
            for (b_loop_ub = i1; b_loop_ub <= nx; b_loop_ub++) {
              suply_price = a[b_loop_ub - 1];
              if (b_error < suply_price) {
                b_error = suply_price;
              }
            }
          }
        }
        if (b_error < dist_tol) {
          st.site = &ub_emlrtRSI;
          b_st.site = &ce_emlrtRSI;
          c_st.site = &xg_emlrtRSI;
          d_st.site = &yg_emlrtRSI;
          emlrt_marshallIn(
              &c_st,
              feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                    c_emlrt_marshallOut(&d_st, cv5),
                    emlrt_marshallOut(static_cast<real_T>(i2) + 1.0),
                    &emlrtMCI),
              "<output of feval>");
          exitg3 = true;
        } else {
          dist_n.set_size(&we_emlrtRTEI, sp, 1, a_cdf.size(1));
          b_loop_ub = a_cdf.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            dist_n[i] = a_cdf[i];
          }
          i2++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtCTX)sp);
          }
        }
      }
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, max_iter, mxDOUBLE_CLASS,
                                    static_cast<int32_T>(max_iter),
                                    &f_emlrtRTEI, (emlrtCTX)sp);
      i2 = 0;
      exitg3 = false;
      while ((!exitg3) && (i2 <= static_cast<int32_T>(max_iter) - 1)) {
        st.site = &wb_emlrtRSI;
        trans_matrix_o->mtimes(&st, dist_o, a_cdf);
        st.site = &xb_emlrtRSI;
        suply_price = *m_of_firms_old - coder::sum(&st, a_cdf);
        r.set_size(&xe_emlrtRTEI, sp, 1, dist_ent.size(1));
        b_loop_ub = dist_ent.size(1);
        for (i = 0; i < b_loop_ub; i++) {
          r[i] = suply_price * dist_ent[i];
        }
        if ((a_cdf.size(1) != r.size(1)) &&
            ((a_cdf.size(1) != 1) && (r.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(a_cdf.size(1), r.size(1), &gb_emlrtECI,
                                      (emlrtCTX)sp);
        }
        if (a_cdf.size(1) == r.size(1)) {
          b_loop_ub = a_cdf.size(1) - 1;
          a_cdf.set_size(&ye_emlrtRTEI, sp, 1, a_cdf.size(1));
          for (i = 0; i <= b_loop_ub; i++) {
            a_cdf[i] = a_cdf[i] + r[i];
          }
        } else {
          st.site = &xb_emlrtRSI;
          plus(&st, a_cdf, r);
        }
        if ((a_cdf.size(1) != dist_o.size(1)) &&
            ((a_cdf.size(1) != 1) && (dist_o.size(1) != 1))) {
          emlrtDimSizeImpxCheckR2021b(a_cdf.size(1), dist_o.size(1),
                                      &hb_emlrtECI, (emlrtCTX)sp);
        }
        st.site = &yb_emlrtRSI;
        if (a_cdf.size(1) == dist_o.size(1)) {
          b_v_of_new.set_size(&af_emlrtRTEI, &st, 1, a_cdf.size(1));
          b_loop_ub = a_cdf.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            b_v_of_new[i] = a_cdf[i] - dist_o[i];
          }
          b_st.site = &yb_emlrtRSI;
          coder::c_abs(&b_st, b_v_of_new, a);
        } else {
          b_st.site = &yb_emlrtRSI;
          binary_expand_op(&b_st, a, yb_emlrtRSI, a_cdf, dist_o);
        }
        b_st.site = &bd_emlrtRSI;
        c_st.site = &pd_emlrtRSI;
        e_st.site = &qd_emlrtRSI;
        if (a.size(1) < 1) {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &j_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        f_st.site = &vd_emlrtRSI;
        g_st.site = &wd_emlrtRSI;
        nx = a.size(1);
        if (a.size(1) <= 2) {
          if (a.size(1) == 1) {
            b_error = a[0];
          } else if ((a[0] < a[1]) || (muDoubleScalarIsNaN(a[0]) &&
                                       (!muDoubleScalarIsNaN(a[1])))) {
            b_error = a[1];
          } else {
            b_error = a[0];
          }
        } else {
          h_st.site = &yd_emlrtRSI;
          if (!muDoubleScalarIsNaN(a[0])) {
            idx = 1;
          } else {
            idx = 0;
            i_st.site = &ae_emlrtRSI;
            if (a.size(1) > 2147483646) {
              j_st.site = &uc_emlrtRSI;
              coder::check_forloop_overflow_error(&j_st);
            }
            b_loop_ub = 2;
            exitg4 = false;
            while ((!exitg4) && (b_loop_ub <= nx)) {
              if (!muDoubleScalarIsNaN(a[b_loop_ub - 1])) {
                idx = b_loop_ub;
                exitg4 = true;
              } else {
                b_loop_ub++;
              }
            }
          }
          if (idx == 0) {
            b_error = a[0];
          } else {
            h_st.site = &xd_emlrtRSI;
            b_error = a[idx - 1];
            i1 = idx + 1;
            i_st.site = &be_emlrtRSI;
            if ((idx + 1 <= a.size(1)) && (a.size(1) > 2147483646)) {
              j_st.site = &uc_emlrtRSI;
              coder::check_forloop_overflow_error(&j_st);
            }
            for (b_loop_ub = i1; b_loop_ub <= nx; b_loop_ub++) {
              suply_price = a[b_loop_ub - 1];
              if (b_error < suply_price) {
                b_error = suply_price;
              }
            }
          }
        }
        if (b_error < dist_tol) {
          st.site = &ac_emlrtRSI;
          b_st.site = &ce_emlrtRSI;
          c_st.site = &xg_emlrtRSI;
          d_st.site = &yg_emlrtRSI;
          emlrt_marshallIn(
              &c_st,
              feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                    c_emlrt_marshallOut(&d_st, cv6),
                    emlrt_marshallOut(static_cast<real_T>(i2) + 1.0),
                    &emlrtMCI),
              "<output of feval>");
          exitg3 = true;
        } else {
          dist_o.set_size(&bf_emlrtRTEI, sp, 1, a_cdf.size(1));
          b_loop_ub = a_cdf.size(1);
          for (i = 0; i < b_loop_ub; i++) {
            dist_o[i] = a_cdf[i];
          }
          i2++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtCTX)sp);
          }
        }
      }
      st.site = &bc_emlrtRSI;
      idx = cap_contemp_new.size(0) * cap_contemp_new.size(1);
      b_v_p_n = cap_contemp_new.reshape(idx);
      b_st.site = &kd_emlrtRSI;
      coder::dynamic_size_checks(&b_st, dist_n, b_v_p_n, dist_n.size(1),
                                 cap_contemp_new.size(0) *
                                     cap_contemp_new.size(1));
      st.site = &bc_emlrtRSI;
      nx = cap_contemp_old.size(0) * cap_contemp_old.size(1);
      b_cap_contemp_old = cap_contemp_old.reshape(nx);
      b_st.site = &kd_emlrtRSI;
      coder::dynamic_size_checks(
          &b_st, dist_o, b_cap_contemp_old, dist_o.size(1),
          cap_contemp_old.size(0) * cap_contemp_old.size(1));
      idx = cap_contemp_new.size(0) * cap_contemp_new.size(1);
      nx = cap_contemp_old.size(0) * cap_contemp_old.size(1);
      b_v_p_n = cap_contemp_new.reshape(idx);
      b_cap_contemp_old = cap_contemp_old.reshape(nx);
      st.site = &cc_emlrtRSI;
      suply_price = coder::mpower(
          &st,
          d_0 / (coder::internal::blas::mtimes(dist_n, b_v_p_n) +
                 coder::internal::blas::mtimes(dist_o, b_cap_contemp_old)),
          1.0 / e_p);
      suply_price -= *p_E;
      if (muDoubleScalarAbs(suply_price) < dem_tol) {
        st.site = &dc_emlrtRSI;
        b_st.site = &ce_emlrtRSI;
        c_st.site = &xg_emlrtRSI;
        d_st.site = &yg_emlrtRSI;
        emlrt_marshallIn(
            &c_st,
            feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                  d_emlrt_marshallOut(&d_st, cv4), emlrt_marshallOut(*p_E),
                  emlrt_marshallOut(static_cast<real_T>(k) + 1.0), &emlrtMCI),
            "<output of feval>");
        exitg2 = true;
      } else {
        *p_E += 0.2 * suply_price /
                muDoubleScalarCeil((static_cast<real_T>(k) + 1.0) / 10.0);
        k++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtCTX)sp);
        }
      }
    }
    if (1 > v_new_resh_n.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, v_new_resh_n.size(0), &hb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &ec_emlrtRSI;
    b_loop_ub = v_new_resh_n.size(1);
    b_v_of_new.set_size(&cf_emlrtRTEI, &st, 1, v_new_resh_n.size(1));
    for (i = 0; i < b_loop_ub; i++) {
      b_v_of_new[i] = v_new_resh_n[v_new_resh_n.size(0) * i];
    }
    b_st.site = &kd_emlrtRSI;
    coder::b_dynamic_size_checks(&b_st, a_prob, b_v_of_new, a_prob.size(1),
                                 v_new_resh_n.size(1));
    b_loop_ub = v_new_resh_n.size(1);
    b_v_of_new.set_size(&cf_emlrtRTEI, sp, 1, v_new_resh_n.size(1));
    for (i = 0; i < b_loop_ub; i++) {
      b_v_of_new[i] = v_new_resh_n[v_new_resh_n.size(0) * i];
    }
    suply_price = coder::internal::blas::mtimes(a_prob, b_v_of_new) - c_e_new;
    // %% let's try
    // %%% different entry cost for techs
    if (1 > v_new_resh_o.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, v_new_resh_o.size(0), &ib_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    st.site = &fc_emlrtRSI;
    b_loop_ub = v_new_resh_o.size(1);
    b_v_of_new.set_size(&df_emlrtRTEI, &st, 1, v_new_resh_o.size(1));
    for (i = 0; i < b_loop_ub; i++) {
      b_v_of_new[i] = v_new_resh_o[v_new_resh_o.size(0) * i];
    }
    b_st.site = &kd_emlrtRSI;
    coder::b_dynamic_size_checks(&b_st, a_prob, b_v_of_new, a_prob.size(1),
                                 v_new_resh_o.size(1));
    b_loop_ub = v_new_resh_o.size(1);
    b_v_of_new.set_size(&df_emlrtRTEI, sp, 1, v_new_resh_o.size(1));
    for (i = 0; i < b_loop_ub; i++) {
      b_v_of_new[i] = v_new_resh_o[v_new_resh_o.size(0) * i];
    }
    b_error = coder::internal::blas::mtimes(a_prob, b_v_of_new) - c_of_e;
    if (((muDoubleScalarAbs(suply_price) < dem_tol) ||
         (*m_of_firms_new < v_tol)) &&
        ((muDoubleScalarAbs(b_error) < dem_tol) || (*m_of_firms_old < v_tol))) {
      st.site = &gc_emlrtRSI;
      b_st.site = &ce_emlrtRSI;
      c_st.site = &xg_emlrtRSI;
      d_st.site = &yg_emlrtRSI;
      emlrt_marshallIn(
          &c_st,
          feval(&c_st, emlrt_marshallOut(&c_st, cv), emlrt_marshallOut(1.0),
                e_emlrt_marshallOut(&d_st, cv1), emlrt_marshallOut(suply_price),
                emlrt_marshallOut(b_error),
                emlrt_marshallOut(static_cast<real_T>(h) + 1.0), &emlrtMCI),
          "<output of feval>");
      exitg1 = true;
    } else {
      if (suply_price > -5.0) {
        *m_of_firms_new *= 0.1 * suply_price + 1.0;
      } else {
        *m_of_firms_new *= 0.05 * suply_price + 1.0;
      }
      if (b_error > -5.0) {
        *m_of_firms_old *= 0.1 * b_error + 1.0;
      } else {
        *m_of_firms_old *= 0.05 * b_error + 1.0;
      }
      h++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
  }
  st.site = &hc_emlrtRSI;
  b_st.site = &kd_emlrtRSI;
  coder::dynamic_size_checks(&b_st, v_p_n, a_prob, v_p_n.size(1),
                             a_prob.size(1));
  b_st.site = &jd_emlrtRSI;
  coder::internal::blas::mtimes(&b_st, v_p_n, a_prob, trans_prob_n);
  st.site = &ic_emlrtRSI;
  b_st.site = &kd_emlrtRSI;
  coder::dynamic_size_checks(&b_st, v_p_o, a_prob, v_p_o.size(1),
                             a_prob.size(1));
  b_st.site = &jd_emlrtRSI;
  coder::internal::blas::mtimes(&b_st, v_p_o, a_prob, trans_prob_o);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (Two_tech_ss.cpp)
