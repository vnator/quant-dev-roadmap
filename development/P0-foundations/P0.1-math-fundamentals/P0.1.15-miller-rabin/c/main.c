
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>

static uint64_t add_mod(uint64_t a, uint64_t b, uint64_t m) {
  if (a >= m - b) {
    return a - (m - b);
  }

  return a + b;
}

static uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m) {
  uint64_t result = 0;
  a %= m;

  while (b > 0) {
    if (b % 2 != 0) {
      result = add_mod(result, a, m);
    }

    b /= 2;

    if (b > 0) {
      a = add_mod(a, a, m);
    }
  }

  return result;
}

static uint64_t mod_exp(uint64_t base, uint64_t exp, uint64_t m) {
  uint64_t result = 1;
  uint64_t b = base % m;

  while (exp > 0) {
    if (exp % 2 != 0) {
      result = mul_mod(result, b, m);
    }

    exp /= 2;

    if (exp > 0) {
      b = mul_mod(b, b, m);
    }
  }

  return result;
}

bool miller_rabin(uint64_t n, uint64_t a) {
  if (n == 2 || n == 3) {
    return true;
  }

  if (n < 2 || n % 2 == 0) {
    return false;
  }

  assert(a >= 2 && a <= n - 2);

  uint64_t d = n - 1;
  unsigned int s = 0;

  while (d % 2 == 0) {
    d /= 2;
    ++s;
  }

  uint64_t x = mod_exp(a, d, n);

  if (x == 1 || x == n - 1) {
    return true;
  }

  for (unsigned int r = 1; r < s; ++r) {
    x = mul_mod(x, x, n);

    if (x == n - 1) {
      return true;
    }
  }

  return false;
}
