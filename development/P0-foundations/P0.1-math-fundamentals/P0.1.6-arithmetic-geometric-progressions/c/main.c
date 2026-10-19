#include "main.h"

static double binary_pow(double base, uint64_t exp) {
  double result = 1.0;

  while (exp > 0) {
    if (exp % 2 != 0) {
      result *= base;
    }

    exp /= 2;

    if (exp > 0) {
      base *= base;
    }
  }

  return result;
}

double summ_pa(uint64_t n, double a, double d) {
  if (n == 0) {
    return 0.0;
  }

  double count = (double)n;

  return count * (2.0 * a + (count - 1.0) * d) / 2.0;
}

double summ_pg(uint64_t n, double a, double r) {
  if (n == 0) {
    return 0.0;
  }

  if (r == 1.0) {
    return a * (double)n;
  }

  return a * (1.0 - binary_pow(r, n)) / (1.0 - r);
}
