#include <stdbool.h>
#include <stddef.h>

static unsigned long long add_mod(unsigned long long a, unsigned long long b,
                                  unsigned long long modulus) {
  return a >= modulus - b ? a - (modulus - b) : a + b;
}

static unsigned long long mul_mod(unsigned long long a, unsigned long long b,
                                  unsigned long long modulus) {
  unsigned long long result = 0;

  while (b > 0) {
    if ((b & 1ULL) != 0) {
      result = add_mod(result, a, modulus);
    }

    b >>= 1;

    if (b > 0) {
      a = add_mod(a, a, modulus);
    }
  }

  return result;
}

bool mod_exp(long long base, long long exp, long long modulus, long long *out) {
  if (out == NULL || exp < 0 || modulus <= 0) {
    return false;
  }

  unsigned long long m = (unsigned long long)modulus;

  if (m == 1ULL) {
    *out = 0;
    return true;
  }

  long long reduced = base % modulus;

  if (reduced < 0) {
    reduced += modulus;
  }

  unsigned long long factor = (unsigned long long)reduced;
  unsigned long long result = 1;
  unsigned long long exponent = (unsigned long long)exp;

  while (exponent > 0) {
    if ((exponent & 1ULL) != 0) {
      result = mul_mod(result, factor, m);
    }

    exponent >>= 1;

    if (exponent > 0) {
      factor = mul_mod(factor, factor, m);
    }
  }

  *out = (long long)result;
  return true;
}
