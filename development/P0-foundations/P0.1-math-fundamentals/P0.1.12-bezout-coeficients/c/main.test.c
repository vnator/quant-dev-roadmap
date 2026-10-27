
#include "main.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

__extension__ typedef __int128 int128_t;

typedef struct {
  int64_t a;
  int64_t b;
  uint64_t gcd;
  int64_t x;
  int64_t y;
} TestCase;

static uint64_t gcd_reference(int64_t a, int64_t b) {
  uint64_t x = a < 0 ? (uint64_t)(-(a + 1)) + 1 : (uint64_t)a;

  uint64_t y = b < 0 ? (uint64_t)(-(b + 1)) + 1 : (uint64_t)b;

  while (y != 0) {
    uint64_t remainder = x % y;
    x = y;
    y = remainder;
  }

  return x;
}

static void assert_bezout_identity(int64_t a, int64_t b) {
  BezoutResult result = extended_gcd(a, b);

  int128_t lhs = (int128_t)a * result.x + (int128_t)b * result.y;

  assert(lhs == (int128_t)result.gcd);
  assert(result.gcd == gcd_reference(a, b));
}

static void should_compute_bezout_coefficients(void) {
  const TestCase cases[] = {
      {0, 0, 0, 0, 0},
      {0, 1, 1, 0, 1},
      {1, 0, 1, 1, 0},
      {0, -18, 18, 0, -1},
      {-18, 0, 18, -1, 0},
      {3, 11, 1, 4, -1},
      {11, 3, 1, -1, 4},
      {7, 26, 1, -11, 3},
      {18, 30, 6, 2, -1},
      {30, 18, 6, -1, 2},
      {12, 8, 4, 1, -1},
      {8, 12, 4, -1, 1},
      {12, 12, 12, 0, 1},
      {-3, 11, 1, -4, -1},
      {3, -11, 1, 4, 1},
      {-3, -11, 1, -4, 1},
      {6, 9, 3, -1, 1},
      {INT64_MIN, 0, UINT64_C(9223372036854775808), -1, 0},
      {0, INT64_MIN, UINT64_C(9223372036854775808), 0, -1},
      {INT64_MIN, INT64_MAX, 1, -1, -1},
      {INT64_MAX, INT64_MIN, 1, -1, -1},
  };

  const size_t count = sizeof(cases) / sizeof(cases[0]);

  for (size_t i = 0; i < count; ++i) {
    BezoutResult actual = extended_gcd(cases[i].a, cases[i].b);

    assert(actual.gcd == cases[i].gcd);
    assert(actual.x == cases[i].x);
    assert(actual.y == cases[i].y);

    assert_bezout_identity(cases[i].a, cases[i].b);
  }
}

static void should_preserve_bezout_identity(void) {
  for (int64_t a = -100; a <= 100; ++a) {
    for (int64_t b = -100; b <= 100; ++b) {
      assert_bezout_identity(a, b);
    }
  }
}

int main(void) {
  should_compute_bezout_coefficients();
  should_preserve_bezout_identity();

  puts("[PASS] P0.1.26 - Bezout coefficients");

  return 0;
}
