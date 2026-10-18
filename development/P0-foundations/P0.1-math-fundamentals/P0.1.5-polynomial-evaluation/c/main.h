#ifndef POLYNOMIAL_EVALUATION_H
#define POLYNOMIAL_EVALUATION_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
  bool ok;
  int64_t value;
} CheckedI64;

CheckedI64 eval_polynomial(const int64_t *coefficients, size_t length,
                           int64_t x);

#endif
