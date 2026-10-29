#include <assert.h>
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

double trapezoidal_rule(double (*f)(double), double a, double b, size_t n);

static double constant(double x) {
  (void)x;
  return 5.0;
}

static double linear(double x) { return 2.0 * x + 3.0; }

static double square(double x) { return x * x; }

static double cubic(double x) { return x * x * x; }

static double invalid_endpoint(double x) { return x == 0.0 ? INFINITY : x; }

static double invalid_interior(double x) { return x == 0.5 ? NAN : x; }

static void assert_close(double actual, double expected, double tolerance) {
  assert(isfinite(actual));
  assert(fabs(actual - expected) <= tolerance);
}

typedef struct {
  double (*f)(double);
  double a;
  double b;
  size_t n;
  double expected;
} TestCase;

static void should_integrate_constant_and_linear_functions(void) {
  const TestCase cases[] = {
      {constant, 0.0, 1.0, 1, 5.0}, {constant, -2.0, 3.0, 10, 25.0},
      {linear, 0.0, 2.0, 1, 10.0},  {linear, 0.0, 2.0, 4, 10.0},
      {linear, -1.0, 1.0, 2, 6.0},
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    const TestCase *test = &cases[i];

    assert_close(trapezoidal_rule(test->f, test->a, test->b, test->n),
                 test->expected, 1e-12);
  }
}

static void should_approximate_curved_functions(void) {
  assert_close(trapezoidal_rule(square, 0.0, 2.0, 1), 4.0, 1e-12);
  assert_close(trapezoidal_rule(square, 0.0, 2.0, 2), 3.0, 1e-12);
  assert_close(trapezoidal_rule(square, 0.0, 2.0, 4), 2.75, 1e-12);
  assert_close(trapezoidal_rule(square, 0.0, 2.0, 8), 2.6875, 1e-12);

  assert_close(trapezoidal_rule(cubic, 0.0, 2.0, 4), 4.25, 1e-12);

  assert_close(trapezoidal_rule(sin, 0.0, acos(-1.0), 100), 2.0, 2e-4);
}

static void should_handle_reversed_and_zero_width_intervals(void) {
  assert_close(trapezoidal_rule(square, 2.0, 0.0, 4), -2.75, 1e-12);

  assert_close(trapezoidal_rule(square, 1.5, 1.5, 4), 0.0, 0.0);
}

static void should_reject_invalid_inputs(void) {
  assert(isnan(trapezoidal_rule(square, 0.0, 1.0, 0)));
  assert(isnan(trapezoidal_rule(NULL, 0.0, 1.0, 4)));
  assert(isnan(trapezoidal_rule(square, NAN, 1.0, 4)));
  assert(isnan(trapezoidal_rule(square, 0.0, INFINITY, 4)));
  assert(isnan(trapezoidal_rule(square, -DBL_MAX, DBL_MAX, 4)));
  assert(isnan(trapezoidal_rule(invalid_endpoint, 0.0, 1.0, 4)));
  assert(isnan(trapezoidal_rule(invalid_interior, 0.0, 1.0, 2)));
}

static void should_converge_quadratically(void) {
  const double exact = 8.0 / 3.0;

  const double e1 = fabs(trapezoidal_rule(square, 0.0, 2.0, 1) - exact);

  const double e2 = fabs(trapezoidal_rule(square, 0.0, 2.0, 2) - exact);

  const double e4 = fabs(trapezoidal_rule(square, 0.0, 2.0, 4) - exact);

  assert(e4 < e2 && e2 < e1);

  assert_close(e2, e1 / 4.0, 1e-12);
  assert_close(e4, e2 / 4.0, 1e-12);
}

int main(void) {
  should_integrate_constant_and_linear_functions();
  puts("[PASS] Constant and linear functions");

  should_approximate_curved_functions();
  puts("[PASS] Quadratic, cubic, and sine functions");

  should_handle_reversed_and_zero_width_intervals();
  puts("[PASS] Reversed and zero-width intervals");

  should_reject_invalid_inputs();
  puts("[PASS] Invalid inputs and nonfinite values");

  should_converge_quadratically();
  puts("[PASS] Quadratic convergence");

  return 0;
}
