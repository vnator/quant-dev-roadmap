
#ifndef P0_1_26_BEZOUT_COEFFICIENTS_H
#define P0_1_26_BEZOUT_COEFFICIENTS_H

#include <stdint.h>

typedef struct {
  uint64_t gcd;
  int64_t x;
  int64_t y;
} BezoutResult;

BezoutResult extended_gcd(int64_t a, int64_t b);

#endif
