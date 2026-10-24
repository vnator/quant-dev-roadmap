#include "main.h"

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
  int64_t input;
  int64_t expected[8];
  size_t expected_count;
} TestCase;

static void should_factorize_known_values(void) {
  const TestCase cases[] = {
      {INT64_MIN, {0}, 0},
      {-12, {0}, 0},
      {-1, {0}, 0},
      {0, {0}, 0},
      {1, {0}, 0},
      {2, {2}, 1},
      {3, {3}, 1},
      {4, {2, 2}, 2},
      {6, {2, 3}, 2},
      {8, {2, 2, 2}, 3},
      {9, {3, 3}, 2},
      {12, {2, 2, 3}, 3},
      {27, {3, 3, 3}, 3},
      {49, {7, 7}, 2},
      {72, {2, 2, 2, 3, 3}, 5},
      {97, {97}, 1},
      {121, {11, 11}, 2},
      {360, {2, 2, 2, 3, 3, 5}, 6},
      {999983, {999983}, 1},
      {999966000289LL, {999983, 999983}, 2},
      {600851475143LL, {71, 839, 1471, 6857}, 4},
      {INT64_MAX, {7, 7, 73, 127, 337, 92737, 649657}, 7},
  };

  const size_t count = sizeof(cases) / sizeof(cases[0]);

  for (size_t i = 0; i < count; ++i) {
    PrimeFactors actual = prime_factors(cases[i].input);

    assert(actual.count == cases[i].expected_count);

    for (size_t j = 0; j < actual.count; ++j) {
      assert(actual.values[j] == cases[i].expected[j]);
    }
  }
}

static bool is_prime_by_division(int64_t n) {
  if (n < 2) {
    return false;
  }

  for (int64_t d = 2; d <= n / d; ++d) {
    if (n % d == 0) {
      return false;
    }
  }

  return true;
}

static void should_preserve_prime_factor_properties(void) {
  for (int64_t n = 2; n <= 10000; ++n) {
    PrimeFactors factors = prime_factors(n);

    int64_t product = 1;

    assert(factors.count > 0);

    for (size_t i = 0; i < factors.count; ++i) {
      assert(is_prime_by_division(factors.values[i]));

      if (i > 0) {
        assert(factors.values[i - 1] <= factors.values[i]);
      }

      assert(product <= INT64_MAX / factors.values[i]);
      product *= factors.values[i];
    }

    assert(product == n);
  }
}

static void should_support_maximum_factor_count(void) {
  PrimeFactors factors = prime_factors(INT64_C(4611686018427387904));

  assert(factors.count == PRIME_FACTORS_CAPACITY);

  for (size_t i = 0; i < factors.count; ++i) {
    assert(factors.values[i] == 2);
  }
}

int main(void) {
  should_factorize_known_values();
  should_preserve_prime_factor_properties();
  should_support_maximum_factor_count();

  puts("[PASS] Prime factorization tests");

  return 0;
}
