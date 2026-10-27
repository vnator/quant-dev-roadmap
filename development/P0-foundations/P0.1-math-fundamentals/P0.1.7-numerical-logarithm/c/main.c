
#include "main.h"

#include <math.h>

#define MAX_TERMS 512

static double ln_series(double x, double epsilon) {
  double z = (x - 1.0) / (x + 1.0);
  double z_squared = z * z;

  double power = z;
  double sum = 0.0;

  for (int k = 0; k < MAX_TERMS; ++k) {
    double next_sum = sum + 2.0 * power / (2.0 * k + 1.0);

    power *= z_squared;

    double remainder_bound =
        2.0 * fabs(power) / ((2.0 * k + 3.0) * (1.0 - z_squared));

    if (remainder_bound <= epsilon) {
      return next_sum;
    }

    if (next_sum == sum) {
      return NAN;
    }

    sum = next_sum;
  }

  return NAN;
}

double natural_log(double x, double epsilon) {
  if (!isfinite(x) || x <= 0.0 || !isfinite(epsilon) || epsilon <= 0.0) {
    return NAN;
  }

  if (x == 1.0) {
    return 0.0;
  }

  double mantissa = x;
  int exponent = 0;

  // x = 2^exponent * mantissa
  while (mantissa > 2.0) {
    mantissa *= 0.5;
    ++exponent;
  }

  while (mantissa < 0.5) {
    mantissa *= 2.0;
    --exponent;
  }

  double component_epsilon =
      epsilon / ((double)(exponent < 0 ? -exponent : exponent) + 1.0);

  if (component_epsilon == 0.0) {
    return NAN;
  }

  double ln_mantissa = ln_series(mantissa, component_epsilon);

  if (!isfinite(ln_mantissa)) {
    return NAN;
  }

  if (exponent == 0) {
    return ln_mantissa;
  }

  double ln_two = ln_series(2.0, component_epsilon);

  if (!isfinite(ln_two)) {
    return NAN;
  }

  return (double)exponent * ln_two + ln_mantissa;
}

double log_base(double x, double base, double epsilon) {
  if (!isfinite(x) || x <= 0.0 || !isfinite(base) || base <= 0.0 ||
      base == 1.0 || !isfinite(epsilon) || epsilon <= 0.0) {
    return NAN;
  }

  if (x == 1.0) {
    return 0.0;
  }

  if (x == base) {
    return 1.0;
  }

  double numerator = natural_log(x, epsilon);
  double denominator = natural_log(base, epsilon);

  if (!isfinite(numerator) || !isfinite(denominator) || denominator == 0.0) {
    return NAN;
  }

  return numerator / denominator;
}
