//
// locBsearch.cpp
//
// Code generation for function 'locBsearch'
//

// Include files
#include "locBsearch.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void sparse_locBsearch(const ::coder::array<int32_T, 1U> &x, int32_T xi,
                       int32_T xstart, int32_T xend, int32_T *n,
                       boolean_T *found)
{
  if (xstart < xend) {
    if (xi < x[xstart - 1]) {
      *n = xstart - 1;
      *found = false;
    } else {
      int32_T high_i;
      int32_T low_ip1;
      high_i = xend;
      *n = xstart;
      low_ip1 = xstart;
      while (high_i > low_ip1 + 1) {
        int32_T mid_i;
        mid_i = (*n >> 1) + (high_i >> 1);
        if (((*n & 1) == 1) && ((high_i & 1) == 1)) {
          mid_i++;
        }
        if (xi >= x[mid_i - 1]) {
          *n = mid_i;
          low_ip1 = mid_i;
        } else {
          high_i = mid_i;
        }
      }
      *found = (x[*n - 1] == xi);
    }
  } else if (xstart == xend) {
    *n = xstart - 1;
    *found = false;
  } else {
    *n = 0;
    *found = false;
  }
}

} // namespace coder

// End of code generation (locBsearch.cpp)
