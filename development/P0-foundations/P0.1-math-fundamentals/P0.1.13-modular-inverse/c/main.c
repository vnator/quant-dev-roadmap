#include "main.h"

typedef struct {
  int64_t gcd;
  int64_t x;
  int64_t y;
} ExtendedGcdResult;

// Preconditions: a >= 0 and b >= 0.
static ExtendedGcdResult extended_gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return (ExtendedGcdResult){a, 1, 0};
  }

  ExtendedGcdResult next = extended_gcd(b, a % b);

  return (ExtendedGcdResult){next.gcd, next.y, next.x - (a / b) * next.y};
}

int64_t inverse_mod(int64_t a, int64_t m) {
  if (m <= 1) {
    return 0;
  }

  // Equivalent to Rust's rem_euclid for m > 0.
  int64_t normalized_a = a % m;

  if (normalized_a < 0) {
    normalized_a += m;
  }

  ExtendedGcdResult result = extended_gcd(normalized_a, m);

  if (result.gcd != 1) {
    return 0;
  }

  int64_t inverse = result.x % m;

  if (inverse < 0) {
    inverse += m;
  }

  return inverse;
}
