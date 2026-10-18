#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

bool eval_polynomial(const int64_t *coefficients, size_t length, int64_t x,
                     int64_t *out);

typedef struct {
  const int64_t *coefficients;
  size_t length;
  int64_t x;
  int64_t expected;
} TestCase;

#define POLY(...)                                                              \
  (const int64_t[]) { __VA_ARGS__ }

#define CASE(x_value, expected_value, ...)                                     \
  {POLY(__VA_ARGS__), sizeof((int64_t[]){__VA_ARGS__}) / sizeof(int64_t),      \
   (x_value), (expected_value)}

static void check_cases(const TestCase *cases, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    int64_t actual = 0;

    assert(eval_polynomial(cases[i].coefficients, cases[i].length, cases[i].x,
                           &actual));

    assert(actual == cases[i].expected);
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
    int64_t result = 777;

    assert(!eval_polynomial(cases[i].coefficients, cases[i].length, cases[i].x,
                            &result));

    assert(result == 777);
  }
}

static void should_reject_invalid_pointers(void) {
  const int64_t coefficients[] = {1, 2, 3};
  int64_t result = 777;

  assert(!eval_polynomial(NULL, 1, 2, &result));
  assert(result == 777);

  assert(!eval_polynomial(coefficients, 3, 2, NULL));

  assert(eval_polynomial(NULL, 0, 2, &result));
  assert(result == 0);
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

  should_reject_invalid_pointers();
  puts("[PASS] Pointer validation");

  return 0;
}
