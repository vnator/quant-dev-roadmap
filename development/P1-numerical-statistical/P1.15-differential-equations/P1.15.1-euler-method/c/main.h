#ifndef EULER_METHOD_MAIN_H
#define EULER_METHOD_MAIN_H

typedef struct {
    double t;
    double y;
} EulerState;

typedef double (*EulerDerivative)(double t, double y);

// The derivative callback must be non-null.
EulerState euler_step(EulerDerivative f, EulerState current, double h);

#endif
