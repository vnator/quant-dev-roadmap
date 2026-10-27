#include "main.h"
#include <assert.h>
#include <stdio.h>

typedef struct {
  const int64_t *coefficients;
  size_t length;
  int64_t x;
  int64_t expected;
} TestCase;

#define CASE(x_value, expected_value, ...)                                     \
  {(const int64_t[]){__VA_ARGS__},                                             \
   sizeof((const int64_t[]){__VA_ARGS__}) / sizeof(int64_t), (x_value),        \
   (expected_value)}

static void check_cases(const TestCase *cases, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    CheckedI64 actual =
        eval_polynomial(cases[i].coefficients, cases[i].length, cases[i].x);

    assert(actual.ok);
    assert(actual.value == cases[i].expected);
  }
}

static void should_evaluate_polynomials(void) {
  const TestCase cases[] = {
      CASE(2, 24, 2, 3, 4),   CASE(3, 10, -5, 2, 1), CASE(10, 321, 1, 2, 3),
      CASE(-2, 27, 3, -2, 5), CASE(3, 8, -1, 0, 1),  CASE(2, 1, 1, -2, 1),
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_handle_boundary_cases(void) {
  const TestCase cases[] = {
      {NULL, 0, 2, 0},      CASE(2, 0, 0),        CASE(42, 7, 7),
      CASE(0, 2, 2, 3, 4),  CASE(-3, 0, 0, 0, 0), CASE(1, 0, 1, -2, 1),
      CASE(-3, 9, 0, 0, 1),
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_handle_integer_limits(void) {
  const TestCase cases[] = {
      CASE(2, INT64_MAX, INT64_MAX),
      CASE(2, INT64_MIN, INT64_MIN),
      CASE(1, INT64_MAX, INT64_MAX, 0),
      CASE(1, INT64_MIN, 0, INT64_MIN),
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_detect_overflow(void) {
  const TestCase cases[] = {
      CASE(2, 0, 0, INT64_MAX),
      CASE(1, 0, 1, INT64_MAX),
      CASE(-1, 0, 0, INT64_MIN),
      CASE(1, 0, -1, INT64_MIN),
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    CheckedI64 actual =
        eval_polynomial(cases[i].coefficients, cases[i].length, cases[i].x);

    assert(!actual.ok);
  }
}

static void should_reject_invalid_input(void) {
  CheckedI64 invalid = eval_polynomial(NULL, 1, 2);
  assert(!invalid.ok);

  CheckedI64 empty = eval_polynomial(NULL, 0, 2);
  assert(empty.ok);
  assert(empty.value == 0);
}

static void should_leave_coefficients_unchanged(void) {
  int64_t coefficients[] = {2, 3, 4};

  CheckedI64 actual = eval_polynomial(coefficients, 3, 2);

  assert(actual.ok && actual.value == 24);
  assert(coefficients[0] == 2);
  assert(coefficients[1] == 3);
  assert(coefficients[2] == 4);
}

int main(void) {
  should_evaluate_polynomials();
  puts("[PASS] Polynomial values");

  should_handle_boundary_cases();
  puts("[PASS] Boundary cases");

  should_handle_integer_limits();
  puts("[PASS] Integer limits");

  should_detect_overflow();
  puts("[PASS] Overflow detection");

  should_reject_invalid_input();
  puts("[PASS] Invalid input");

  should_leave_coefficients_unchanged();
  puts("[PASS] No coefficient mutation");

  return 0;
}
