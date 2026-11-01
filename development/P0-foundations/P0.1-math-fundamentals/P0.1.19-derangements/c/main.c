#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

__extension__ typedef unsigned __int128 u128;

static bool add_u128(u128 a, u128 b, u128 *out) {
  const u128 max = (u128)-1;

  if (out == NULL || b > max - a) {
    return false;
  }

  *out = a + b;
  return true;
}

static bool multiply_u128(u128 a, u128 b, u128 *out) {
  const u128 max = (u128)-1;

  if (out == NULL || (a != 0 && b > max / a)) {
    return false;
  }

  *out = a * b;
  return true;
}

bool derangement(u128 n, u128 *out) {
  if (out == NULL) {
    return false;
  }

  if (n == 0) {
    *out = 1;
    return true;
  }

  if (n == 1) {
    *out = 0;
    return true;
  }

  u128 d_prev2 = 1;
  u128 d_prev1 = 0;

  for (u128 i = 2; i <= n; ++i) {
    u128 sum;
    u128 current;

    if (!add_u128(d_prev1, d_prev2, &sum)) {
      return false;
    }

    if (!multiply_u128(i - 1, sum, &current)) {
      return false;
    }

    d_prev2 = d_prev1;
    d_prev1 = current;
  }

  *out = d_prev1;
  return true;
}
