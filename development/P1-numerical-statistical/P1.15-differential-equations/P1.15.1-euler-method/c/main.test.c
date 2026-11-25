#include "main.h"

#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

static int slope_calls;

static double slope(double t, double y) {
    ++slope_calls;
    return t + 2.0 * y;
}

static double cooling(double t, double y) {
    (void)t;
    return -0.1 * (y - 20.0);
}

int main(void) {
    const EulerState next = euler_step(slope, (EulerState){2.0, 3.0}, 0.25);
    assert(slope_calls == 1);
    assert(next.t == 2.25);
    assert(next.y == 5.0);

    EulerState state = {0.0, 80.0};
    const double expected[] = {74.0, 68.6, 63.74};
    for (size_t i = 0; i < sizeof expected / sizeof expected[0]; ++i) {
        state = euler_step(cooling, state, 1.0);
        assert(fabs(state.y - expected[i]) < 1e-12);
    }
    assert(state.t == 3.0);

    puts("[PASS] Euler method");
    return 0;
}
