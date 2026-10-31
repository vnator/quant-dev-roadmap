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

static uint64_t gcd_u64(uint64_t a, uint64_t b) {
  while (b != 0) {
    const uint64_t remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}

bool factorial_binomial(uint64_t n, uint64_t k, u128 *out) {
  if (out == NULL) {
    return false;
  }

  if (k > n) {
    *out = 0;
    return true;
  }

  if (k > n - k) {
    k = n - k;
  }

  u128 result = 1;

  for (uint64_t i = 1; i <= k; ++i) {
    uint64_t numerator = n - i + 1;
    uint64_t denominator = i;

    const uint64_t divisor = gcd_u64(numerator, denominator);

    numerator /= divisor;
    denominator /= divisor;

    const u128 wide_denominator = (u128)denominator;

    if (result % wide_denominator != 0) {
      return false;
    }

    result /= wide_denominator;

    if (!multiply_u128(result, (u128)numerator, &result)) {
      return false;
    }
  }

  *out = result;
  return true;
}

bool permutations_with_repetition(uint64_t n, const uint64_t *multiplicities,
                                  size_t count, u128 *out) {
  if (out == NULL || (count > 0 && multiplicities == NULL)) {
    return false;
  }

  u128 result = 1;
  uint64_t remaining = n;

  for (size_t i = 0; i < count; ++i) {
    const uint64_t quantity = multiplicities[i];

    if (quantity > remaining) {
      return false;
    }

    u128 combinations;

    if (!factorial_binomial(remaining, quantity, &combinations)) {
      return false;
    }

    if (!multiply_u128(result, combinations, &result)) {
      return false;
    }

    remaining -= quantity;
  }

  if (remaining != 0) {
    return false;
  }

  *out = result;
  return true;
}
