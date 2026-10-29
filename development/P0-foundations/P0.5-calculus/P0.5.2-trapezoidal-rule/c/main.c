#include <math.h>
#include <stddef.h>

double trapezoidal_rule(double (*f)(double), double a, double b, size_t n) {
  if (f == NULL || n == 0 || !isfinite(a) || !isfinite(b)) {
    return NAN;
  }

  const double h = (b - a) / (double)n;

  if (!isfinite(h)) {
    return NAN;
  }

  const double fa = f(a);
  const double fb = f(b);

  if (!isfinite(fa) || !isfinite(fb)) {
    return NAN;
  }

  if (a == b) {
    return 0.0;
  }

  double sum = (fa + fb) / 2.0;

  for (size_t i = 1; i < n; ++i) {
    const double x = a + (double)i * h;

    if (!isfinite(x)) {
      return NAN;
    }

    const double y = f(x);

    if (!isfinite(y)) {
      return NAN;
    }

    sum += y;
  }

  const double result = h * sum;

  return isfinite(result) ? result : NAN;
}
