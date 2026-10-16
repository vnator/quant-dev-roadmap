#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

bool mod_exp(long long base, long long exp, long long modulus, long long *out);

typedef struct {
  long long base;
  long long exp;
  long long modulus;
  long long expected;
} TestCase;

static void check_cases(const TestCase *cases, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    long long actual = -1;

    assert(mod_exp(cases[i].base, cases[i].exp, cases[i].modulus, &actual));
    assert(actual == cases[i].expected);
  }
}

static void should_compute_modular_powers(void) {
  const TestCase cases[] = {
      {2, 3, 5, 3},
      {2, 10, 1000, 24},
      {3, 13, 7, 3},
      {10, 2, 6, 4},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_handle_negative_bases(void) {
  const TestCase cases[] = {
      {-2, 3, 5, 2},
      {-2, 2, 5, 4},
      {-1, 7, 7, 6},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_handle_boundary_cases(void) {
  const TestCase cases[] = {
      {7, 0, 5, 1}, {0, 0, 5, 1}, {0, 5, 7, 0}, {123, 100, 1, 0}, {0, 0, 1, 0},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_avoid_intermediate_overflow(void) {
  const TestCase cases[] = {
      {LLONG_MAX - 2, 2, LLONG_MAX, 4},
      {LLONG_MIN, 1, LLONG_MAX, LLONG_MAX - 1},
      {2, LLONG_MAX, 7, 2},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_reject_invalid_input(void) {
  long long out = -1;

  assert(!mod_exp(2, -1, 7, &out));
  assert(!mod_exp(2, 3, 0, &out));
  assert(!mod_exp(2, 3, -7, &out));
  assert(!mod_exp(2, 3, 7, NULL));
}

int main(void) {
  should_compute_modular_powers();
  puts("[PASS] Positive modular powers");

  should_handle_negative_bases();
  puts("[PASS] Negative bases");

  should_handle_boundary_cases();
  puts("[PASS] Boundary cases");

  should_avoid_intermediate_overflow();
  puts("[PASS] Overflow regression");

  should_reject_invalid_input();
  puts("[PASS] Invalid input");

  return 0;
}
