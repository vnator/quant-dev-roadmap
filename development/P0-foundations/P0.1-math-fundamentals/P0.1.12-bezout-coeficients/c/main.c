
#include "main.h"

#include <limits.h>
#include <stdlib.h>

#if !defined(__SIZEOF_INT128__)
#error "This implementation requires GCC/Clang __int128 support"
#endif

__extension__ typedef __int128 int128_t;

typedef struct {
  int128_t gcd;
  int128_t x;
  int128_t y;
} WideBezoutResult;

static WideBezoutResult extended_gcd_nonnegative(int128_t a, int128_t b) {
  if (b == 0) {
    return (WideBezoutResult){a, 1, 0};
  }

  WideBezoutResult next = extended_gcd_nonnegative(b, a % b);

  return (WideBezoutResult){next.gcd, next.y, next.x - (a / b) * next.y};
}

BezoutResult extended_gcd(int64_t a, int64_t b) {
  if (a == 0 && b == 0) {
    return (BezoutResult){0, 0, 0};
  }

  int128_t abs_a = a < 0 ? -(int128_t)a : (int128_t)a;

  int128_t abs_b = b < 0 ? -(int128_t)b : (int128_t)b;

  WideBezoutResult result = extended_gcd_nonnegative(abs_a, abs_b);

  if (a < 0) {
    result.x = -result.x;
  }

  if (b < 0) {
    result.y = -result.y;
  }

  if (result.x < INT64_MIN || result.x > INT64_MAX || result.y < INT64_MIN ||
      result.y > INT64_MAX) {
    abort();
  }

  return (BezoutResult){(uint64_t)result.gcd, (int64_t)result.x,
                        (int64_t)result.y};
}
