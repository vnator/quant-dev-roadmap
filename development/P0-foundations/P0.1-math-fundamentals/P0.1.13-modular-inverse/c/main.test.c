#include "main.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
  int64_t a;
  int64_t m;
  int64_t expected;
} TestCase;

static void should_compute_known_inverses(void) {
  const TestCase cases[] = {
      {3, 11, 4},
      {10, 17, 12},
      {-3, 11, 7},
      {1, 13, 1},
      {12, 13, 12},
      {7, 26, 15},
      {2, 5, 3},
      {17, 3120, 2753},
      {37, 100, 73},
      {-1, INT64_MAX, INT64_MAX - 1},
      {INT64_MIN, INT64_MAX, INT64_MAX - 1},
      {INT64_MIN, 3, 1},
      {6, 9, 0},
      {4, 8, 0},
      {0, 13, 0},
      {11, 11, 0},
      {3, 1, 0},
      {3, 0, 0},
      {3, -11, 0},
      {INT64_MIN, 2, 0},
      {INT64_MAX, INT64_MAX, 0},
  };

  size_t count = sizeof(cases) / sizeof(cases[0]);

  for (size_t i = 0; i < count; ++i) {
    assert(inverse_mod(cases[i].a, cases[i].m) == cases[i].expected);
  }
}

static int64_t gcd_reference(int64_t a, int64_t b) {
  while (b != 0) {
    int64_t r = a % b;
    a = b;
    b = r;
  }

  return a;
}

// Both operands must be smaller than modulus.
static uint64_t add_mod(uint64_t lhs, uint64_t rhs, uint64_t modulus) {
  return lhs >= modulus - rhs ? lhs - (modulus - rhs) : lhs + rhs;
}

// Modular multiplication without overflowing uint64_t.
static uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t modulus) {
  uint64_t product = 0;

  while (b != 0) {
    if (b % 2 != 0) {
      product = add_mod(product, a, modulus);
    }

    b /= 2;

    if (b != 0) {
      a = add_mod(a, a, modulus);
    }
  }

  return product;
}

static void assert_inverse_property(int64_t a, int64_t m) {
  assert(m > 1);

  int64_t normalized_a = a % m;

  if (normalized_a < 0) {
    normalized_a += m;
  }

  int64_t inverse = inverse_mod(a, m);
  int64_t gcd = gcd_reference(normalized_a, m);

  if (gcd != 1) {
    assert(inverse == 0);
  } else {
    assert(inverse > 0 && inverse < m);

    assert(mul_mod((uint64_t)normalized_a, (uint64_t)inverse, (uint64_t)m) ==
           1);
  }
}

static void should_verify_inverse_property(void) {
  for (int64_t m = 2; m <= 200; ++m) {
    for (int64_t a = -200; a <= 200; ++a) {
      assert_inverse_property(a, m);
    }
  }

  assert_inverse_property(INT64_MIN, INT64_MAX);
  assert_inverse_property(-1, INT64_MAX);
  assert_inverse_property(INT64_MAX - 1, INT64_MAX);
  assert_inverse_property(INT64_MIN, 3);
}

int main(void) {
  should_compute_known_inverses();
  should_verify_inverse_property();

  puts("[PASS] P0.1.13 - Modular Inverse");

  return 0;
}
