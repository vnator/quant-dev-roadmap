#include <stdint.h>

uint64_t euler_phi(uint64_t n) {
  if (n == 0) {
    return 0;
  }

  uint64_t result = n;
  uint64_t rest = n;
  uint64_t divisor = 2;

  while (divisor <= rest / divisor) {
    if (rest % divisor == 0) {
      result -= result / divisor;

      while (rest % divisor == 0) {
        rest /= divisor;
      }
    }

    ++divisor;
  }

  if (rest > 1) {
    result -= result / rest;
  }

  return result;
}
