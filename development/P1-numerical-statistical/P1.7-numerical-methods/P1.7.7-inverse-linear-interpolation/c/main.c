#include <math.h>

double inverse_linear_interpolation(double x0, double y0, double x1, double y1, double target) {
    if (!isfinite(x0) || !isfinite(y0) || !isfinite(x1) || !isfinite(y1) || !isfinite(target) ||
        x0 == x1 || y0 == y1 || target < fmin(y0, y1) || target > fmax(y0, y1)) {
        return NAN;
    }

    if (target == y0) {
        return x0;
    }
    if (target == y1) {
        return x1;
    }

    if (!isfinite(y1 - y0)) {
        y0 *= 0.5;
        y1 *= 0.5;
        target *= 0.5;
    }

    // Measure the fraction from the nearer endpoint to preserve small weights.
    if (fabs(target - y1) < fabs(target - y0)) {
        const double old_x0 = x0;
        const double old_y0 = y0;
        x0 = x1;
        y0 = y1;
        x1 = old_x0;
        y1 = old_y0;
    }

    const double fraction = (target - y0) / (y1 - y0);
    if (!!signbit(x0) != !!signbit(x1)) {
        return (1.0 - fraction) * x0 + fraction * x1;
    }

    return fma(fraction, x1 - x0, x0);
}
