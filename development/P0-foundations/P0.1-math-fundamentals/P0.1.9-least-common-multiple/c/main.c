#include "main.h"

#include <stdint.h>
#include <stdlib.h>

static uint64_t magnitude(int64_t value) {
  if (value >= 0) {
    return (uint64_t)value;
  }

  return (uint64_t)(-(value + 1)) + UINT64_C(1);
}

static uint64_t gcd(uint64_t a, uint64_t b) {
  while (b != 0) {
    uint64_t remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}

uint64_t lcm(int64_t a, int64_t b) {
  uint64_t abs_a = magnitude(a);
  uint64_t abs_b = magnitude(b);

  if (abs_a == 0 || abs_b == 0) {
    return 0;
  }

  uint64_t divisor = gcd(abs_a, abs_b);
  uint64_t reduced_a = abs_a / divisor;

  if (reduced_a > UINT64_MAX / abs_b) {
    abort();
  }

  return reduced_a * abs_b;
}
