#include <math.h>
#include <stddef.h>

double simpsons_rule(double (*f)(double), double a, double b, size_t n) {
  if (f == NULL || n < 2 || n % 2 != 0 || !isfinite(a) || !isfinite(b)) {
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

  double sum = fa + fb;

  for (size_t i = 1; i < n; ++i) {
    const double x = a + (double)i * h;
    if (!isfinite(x)) {
      return NAN;
    }

    const double y = f(x);
    if (!isfinite(y)) {
      return NAN;
    }

    const double weight = i % 2 == 0 ? 2.0 : 4.0;
    sum += weight * y;
  }

  const double result = (h / 3.0) * sum;
  return isfinite(result) ? result : NAN;
}
