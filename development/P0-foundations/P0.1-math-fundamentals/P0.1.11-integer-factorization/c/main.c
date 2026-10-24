#include "main.h"

PrimeFactors prime_factors(int64_t n) {
  PrimeFactors factors = {0};

  if (n < 2) {
    return factors;
  }

  int64_t d = 2;

  while (d <= n / d) {
    while (n % d == 0) {
      factors.values[factors.count++] = d;
      n /= d;
    }

    if (d == 2) {
      d = 3;
    } else {
      d += 2;
    }
  }

  if (n > 1) {
    factors.values[factors.count++] = n;
  }

  return factors;
}
