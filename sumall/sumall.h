// Sample input 1, in CPP.

#include <cassert>

long long GetN() {
  return 14LL;
}

long long GetNumber(long long index) {
  switch ((int)index) {
    case 0: return 10LL;
    case 1: return -2LL;
    case 2: return 5LL;
    case 3: return -4LL;
    case 4: return 3LL;
    case 5: return -5LL;
    case 6: return 1LL;
    case 7+0: return 10LL;
    case 7+1: return -2LL;
    case 7+2: return 5LL;
    case 7+3: return -4LL;
    case 7+4: return 3LL;
    case 7+5: return -5LL;
    case 7+6: return 1LL;
    default: assert(0);
  }
}
