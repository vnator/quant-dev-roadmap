#include "main.h"

#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
  uint64_t n;
  double a;
  double step;
  double expected;
} TestCase;

static void assert_approx(double actual, double expected) {
  const double tolerance = 1e-10 * fmax(1.0, fabs(expected));

  assert(isfinite(actual));
  assert(fabs(actual - expected) <= tolerance);
}

static void should_sum_arithmetic_progressions(void) {
  const TestCase cases[] = {
      {0, 2.0, 3.0, 0.0},   {1, 2.0, 3.0, 2.0},      {5, 2.0, 3.0, 40.0},
      {4, -3.0, 2.0, 0.0},  {100, 1.0, 1.0, 5050.0}, {4, 10.0, -2.0, 28.0},
      {3, 0.5, 0.25, 2.25}, {5, 7.0, 0.0, 35.0},
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    assert_approx(summ_pa(cases[i].n, cases[i].a, cases[i].step),
                  cases[i].expected);
  }
}

static void should_sum_geometric_progressions(void) {
  const TestCase cases[] = {
      {0, 2.0, 3.0, 0.0},    {1, 2.0, 3.0, 2.0},     {3, 2.0, 2.0, 14.0},
      {4, 2.0, 3.0, 80.0},   {5, 3.0, 1.0, 15.0},    {4, 2.0, 0.0, 2.0},
      {4, 2.0, -2.0, -10.0}, {4, 2.0, 0.5, 3.75},    {4, 2.0, -1.0, 0.0},
      {5, 2.0, -1.0, 2.0},   {10, 1.0, 2.0, 1023.0}, {1, 6.0, -5.0, 6.0},
      {3, 2.0, -2.0, 6.0},   {0, 3.0, 1.0, 0.0},     {3, 0.0, 2.0, 0.0},
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    assert_approx(summ_pg(cases[i].n, cases[i].a, cases[i].step),
                  cases[i].expected);
  }
}

int main(void) {
  should_sum_arithmetic_progressions();
  puts("[PASS] Arithmetic progressions (8 cases)");

  should_sum_geometric_progressions();
  puts("[PASS] Geometric progressions (15 cases)");

  return 0;
}
