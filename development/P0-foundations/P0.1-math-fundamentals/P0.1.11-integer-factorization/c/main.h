
#ifndef P0_1_11_PRIME_FACTORIZATION_H
#define P0_1_11_PRIME_FACTORIZATION_H

#include <stddef.h>
#include <stdint.h>

#define PRIME_FACTORS_CAPACITY 62

typedef struct {
  int64_t values[PRIME_FACTORS_CAPACITY];
  size_t count;
} PrimeFactors;

PrimeFactors prime_factors(int64_t n);

#endif
