#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

double inverse_linear_interpolation(double x0, double y0, double x1, double y1, double target);

int main(void) {
    assert(fabs(inverse_linear_interpolation(20.0, 1.0, 30.0, 1.5, 1.2) - 24.0) < 1e-12);
    assert(fabs(inverse_linear_interpolation(30.0, 1.5, 20.0, 1.0, 1.2) - 24.0) < 1e-12);
    assert(inverse_linear_interpolation(20.0, 1.0, 30.0, 1.5, 1.0) == 20.0);
    assert(inverse_linear_interpolation(20.0, 1.0, 30.0, 1.5, 1.5) == 30.0);

    assert(isnan(inverse_linear_interpolation(20.0, 1.0, 30.0, 1.5, 0.5)));
    assert(isnan(inverse_linear_interpolation(20.0, 1.0, 30.0, 1.5, 2.0)));
    assert(isnan(inverse_linear_interpolation(20.0, 1.0, 20.0, 1.5, 1.2)));
    assert(isnan(inverse_linear_interpolation(20.0, 1.0, 30.0, 1.0, 1.0)));
    assert(isnan(inverse_linear_interpolation(20.0, 1.0, 30.0, 1.5, NAN)));
    assert(isnan(inverse_linear_interpolation(INFINITY, 1.0, 30.0, 1.5, 1.2)));

    assert(inverse_linear_interpolation(-DBL_MAX, -DBL_MAX, DBL_MAX, DBL_MAX, 0.0) == 0.0);

    const double target = nextafter(1.0, 0.0);
    const double near_endpoint = inverse_linear_interpolation(1e20, -1.0, 1.0, 1.0, target);
    const double expected = 1.0 + ((1.0 - target) / 2.0) * 1e20;
    assert(fabs(near_endpoint - expected) < 1e-12);

    puts("[PASS] Inverse linear interpolation");
    return 0;
}
