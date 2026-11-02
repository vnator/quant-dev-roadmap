#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

__extension__ typedef unsigned __int128 u128;

static bool multiply_u128(u128 a, u128 b, u128 *out) {
  const u128 max = (u128)-1;

  if (out == NULL || (a != 0 && b > max / a)) {
    return false;
  }

  *out = a * b;
  return true;
}

static u128 gcd_u128(u128 a, u128 b) {
  while (b != 0) {
    const u128 remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}

bool catalan_number(uint64_t n, u128 *out) {
  if (out == NULL) {
    return false;
  }

  u128 result = 1;

  for (uint64_t index = 0; index < n; ++index) {
    const u128 i = (u128)index;

    // Safe because index is limited to uint64_t.
    u128 numerator = 2 * (2 * i + 1);
    u128 denominator = i + 2;

    const u128 divisor = gcd_u128(numerator, denominator);

    numerator /= divisor;
    denominator /= divisor;

    if (result % denominator != 0) {
      return false;
    }

    result /= denominator;

    if (!multiply_u128(result, numerator, &result)) {
      return false;
    }
  }

  *out = result;
  return true;
}
