#include "main.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define EPSILON 1e-12

static void assert_approx(double actual, double expected) {
  double tolerance = 1e-12 + 1e-10 * fabs(expected);

  assert(isfinite(actual));
  assert(fabs(actual - expected) <= tolerance);
}

static void should_compute_natural_log(void) {
  assert_approx(natural_log(1.0, EPSILON), 0.0);
  assert_approx(natural_log(2.0, EPSILON), 0.6931471805599453);
  assert_approx(natural_log(0.5, EPSILON), -0.6931471805599453);
  assert_approx(natural_log(2.718281828459045, EPSILON), 1.0);
  assert_approx(natural_log(10.0, EPSILON), 2.302585092994046);

  assert_approx(natural_log(1e-300, EPSILON), -690.7755278982137);

  assert_approx(natural_log(1e300, EPSILON), 690.7755278982137);

  // Numerical accuracy close to 1.
  assert(fabs(natural_log(1.0 + 1e-12, EPSILON) - 1.000088900581841e-12) <
         1e-15);
}

static void should_compute_log_base(void) {
  assert_approx(log_base(8.0, 2.0, EPSILON), 3.0);
  assert_approx(log_base(1000.0, 10.0, EPSILON), 3.0);
  assert_approx(log_base(8.0, 0.5, EPSILON), -3.0);
  assert_approx(log_base(1.0, 7.0, EPSILON), 0.0);
  assert_approx(log_base(16.0, 4.0, EPSILON), 2.0);
  assert_approx(log_base(0.25, 0.5, EPSILON), 2.0);
  assert_approx(log_base(0.125, 2.0, EPSILON), -3.0);
  assert_approx(log_base(3.0, 3.0, EPSILON), 1.0);
}

static void should_reject_invalid_inputs(void) {
  assert(isnan(natural_log(0.0, EPSILON)));
  assert(isnan(natural_log(-1.0, EPSILON)));
  assert(isnan(natural_log(NAN, EPSILON)));
  assert(isnan(natural_log(INFINITY, EPSILON)));

  assert(isnan(natural_log(2.0, 0.0)));
  assert(isnan(natural_log(2.0, -1.0)));

  assert(isnan(log_base(2.0, 1.0, EPSILON)));
  assert(isnan(log_base(2.0, 0.0, EPSILON)));
  assert(isnan(log_base(2.0, -2.0, EPSILON)));
  assert(isnan(log_base(2.0, 2.0, 0.0)));
}

int main(void) {
  should_compute_natural_log();
  puts("[PASS] Natural logarithm");

  should_compute_log_base();
  puts("[PASS] Arbitrary-base logarithm");

  should_reject_invalid_inputs();
  puts("[PASS] Invalid inputs");

  return 0;
}
