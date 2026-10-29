#include <assert.h>
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

double simpsons_rule(double (*f)(double), double a, double b, size_t n);

static double constant(double x) {
  (void)x;
  return 5.0;
}

static double linear(double x) { return 2.0 * x + 3.0; }
static double quadratic(double x) { return x * x; }
static double cubic(double x) { return x * x * x; }
static double quartic(double x) { return x * x * x * x; }

static double infinite_endpoint(double x) { return x == 0.0 ? INFINITY : x; }

static double nan_interior(double x) { return x == 0.5 ? NAN : x; }

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

static void should_integrate_polynomials_of_degree_at_most_three(void) {
  const TestCase cases[] = {
      {constant, 0.0, 1.0, 2, 5.0},        {constant, -2.0, 3.0, 10, 25.0},
      {linear, 0.0, 2.0, 4, 10.0},         {linear, -1.0, 1.0, 2, 6.0},
      {quadratic, 0.0, 2.0, 2, 8.0 / 3.0}, {quadratic, 0.0, 2.0, 4, 8.0 / 3.0},
      {cubic, 0.0, 2.0, 2, 4.0},           {cubic, -1.0, 2.0, 6, 3.75},
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    const TestCase *test = &cases[i];
    assert_close(simpsons_rule(test->f, test->a, test->b, test->n),
                 test->expected, 1e-12);
  }
}

static void should_approximate_sine(void) {
  assert_close(simpsons_rule(sin, 0.0, acos(-1.0), 100), 2.0, 1e-7);
}

static void should_handle_reversed_and_zero_width_intervals(void) {
  assert_close(simpsons_rule(quadratic, 2.0, 0.0, 4), -8.0 / 3.0, 1e-12);
  assert_close(simpsons_rule(quadratic, 1.5, 1.5, 4), 0.0, 0.0);
  assert_close(simpsons_rule(constant, 1.5, 1.5, 4), 0.0, 0.0);
}

static void should_reject_invalid_subinterval_counts(void) {
  assert(isnan(simpsons_rule(quadratic, 0.0, 1.0, 0)));
  assert(isnan(simpsons_rule(quadratic, 0.0, 1.0, 1)));
  assert(isnan(simpsons_rule(quadratic, 0.0, 1.0, 3)));
}

static void should_reject_invalid_inputs_and_function_values(void) {
  assert(isnan(simpsons_rule(NULL, 0.0, 1.0, 4)));
  assert(isnan(simpsons_rule(quadratic, NAN, 1.0, 4)));
  assert(isnan(simpsons_rule(quadratic, 0.0, INFINITY, 4)));
  assert(isnan(simpsons_rule(quadratic, -DBL_MAX, DBL_MAX, 4)));
  assert(isnan(simpsons_rule(infinite_endpoint, 0.0, 1.0, 4)));
  assert(isnan(simpsons_rule(nan_interior, 0.0, 1.0, 2)));
}

static void should_converge_for_quartic(void) {
  const double exact = 0.2;
  const double coarse = simpsons_rule(quartic, 0.0, 1.0, 2);
  const double fine = simpsons_rule(quartic, 0.0, 1.0, 4);

  assert(fabs(fine - exact) < fabs(coarse - exact));
  assert_close(coarse, 0.20833333333333334, 1e-12);
  assert_close(fine, 0.20052083333333334, 1e-12);
}

int main(void) {
  should_integrate_polynomials_of_degree_at_most_three();
  puts("[PASS] Polynomials (degree <= 3)");

  should_approximate_sine();
  puts("[PASS] Sine approximation");

  should_handle_reversed_and_zero_width_intervals();
  puts("[PASS] Interval boundaries");

  should_reject_invalid_subinterval_counts();
  puts("[PASS] Invalid subinterval counts");

  should_reject_invalid_inputs_and_function_values();
  puts("[PASS] Invalid inputs and function values");

  should_converge_for_quartic();
  puts("[PASS] Quartic convergence");

  return 0;
}
