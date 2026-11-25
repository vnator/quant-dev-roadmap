#include "main.h"

EulerState euler_step(EulerDerivative f, EulerState current, double h) {
    const double slope = f(current.t, current.y);

    return (EulerState){
        .t = current.t + h,
        .y = current.y + h * slope,
    };
}
