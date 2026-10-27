#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

long long factorial_binomial(long long n, long long k);

typedef struct {
  long long n;
  long long k;
  long long expected;
} TestCase;

static void check_cases(const TestCase *cases, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    assert(factorial_binomial(cases[i].n, cases[i].k) == cases[i].expected);
  }
}

static void should_compute_binomial_coefficients(void) {
  const TestCase cases[] = {
      {5, 2, 10},   {6, 3, 20},       {8, 4, 70},
      {10, 3, 120}, {20, 10, 184756}, {30, 15, 155117520},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_handle_boundary_cases(void) {
  const TestCase cases[] = {
      {0, 0, 1},
      {1, 0, 1},
      {1, 1, 1},
      {5, 0, 1},
      {5, 5, 1},
      {10, 1, 10},
      {10, 10, 1},
      {LLONG_MAX, 0, 1},
      {LLONG_MAX, 1, LLONG_MAX},
      {LLONG_MAX, LLONG_MAX, 1},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_return_zero_when_k_exceeds_n(void) {
  const TestCase cases[] = {
      {0, 1, 0},
      {2, 3, 0},
      {3, 5, 0},
      {10, 11, 0},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_preserve_binomial_symmetry(void) {
  const long long cases[][2] = {
      {5, 2},
      {10, 3},
      {20, 5},
      {30, 12},
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    long long n = cases[i][0];
    long long k = cases[i][1];

    assert(factorial_binomial(n, k) == factorial_binomial(n, n - k));
  }
}

static void should_satisfy_pascals_identity(void) {
  const long long cases[][2] = {
      {5, 2},
      {10, 4},
      {20, 8},
      {30, 12},
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    long long n = cases[i][0];
    long long k = cases[i][1];

    long long left = factorial_binomial(n - 1, k - 1);
    long long right = factorial_binomial(n - 1, k);

    assert(factorial_binomial(n, k) == left + right);
  }
}

static void should_handle_large_coefficients(void) {
  const TestCase cases[] = {
      {40, 20, 137846528820LL},
      {50, 25, 126410606437752LL},
      {52, 26, 495918532948104LL},
      {66, 33, 7219428434016265740LL},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_reject_overflow(void) {
  const TestCase cases[] = {
      {67, 33, -1},
      {68, 34, -1},
      {100, 50, -1},
      {LLONG_MAX, 2, -1},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_reject_negative_inputs(void) {
  const TestCase cases[] = {
      {-1, 0, -1},
      {5, -1, -1},
      {-1, -1, -1},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

int main(void) {
  should_compute_binomial_coefficients();
  puts("[PASS] Binomial coefficients");

  should_handle_boundary_cases();
  puts("[PASS] Boundary cases");

  should_return_zero_when_k_exceeds_n();
  puts("[PASS] k > n");

  should_preserve_binomial_symmetry();
  puts("[PASS] Symmetry");

  should_satisfy_pascals_identity();
  puts("[PASS] Pascal's identity");

  should_handle_large_coefficients();
  puts("[PASS] Large coefficients");

  should_reject_overflow();
  puts("[PASS] Overflow detection");

  should_reject_negative_inputs();
  puts("[PASS] Negative input rejection");

  return 0;
}
