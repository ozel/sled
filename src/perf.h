
#include "types.h"
#include "timers.h"

#ifdef PERF
// one timer for each module, assuming there are never more than 64 modules loaded
ulong perf_timer[128];
#endif

inline void perf_start(int n) {
#ifdef PERF
  perf_timer[n*2] = udate();
  perf_timer[(n*2)+1] = perf_timer[n*2];
#endif
}

inline void perf_print(int n, char* msg) {
#ifdef PERF
  ulong cur = udate();
  printf("\t%02d: %16d %16d - %s\n", n, cur - perf_timer[n*2], cur - perf_timer[(n*2)+1], msg);
  perf_timer[(n*2)+1] = udate();
#endif
}
