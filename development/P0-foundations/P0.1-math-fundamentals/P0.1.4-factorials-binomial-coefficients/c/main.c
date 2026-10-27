#include <limits.h>

static long long gcd_positive(long long a, long long b) {
  while (b != 0) {
    long long remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}

long long factorial_binomial(long long n, long long k) {
  if (n < 0 || k < 0) {
    return -1;
  }

  if (k > n) {
    return 0;
  }

  if (k > n - k) {
    k = n - k;
  }

  long long result = 1;

  for (long long i = 1; i <= k; ++i) {
    long long numerator = n - i + 1;
    long long denominator = i;

    long long divisor = gcd_positive(numerator, denominator);

    numerator /= divisor;
    denominator /= divisor;

    if (result % denominator != 0) {
      return -1;
    }

    result /= denominator;

    if (result > LLONG_MAX / numerator) {
      return -1;
    }

    result *= numerator;
  }

  return result;
}
