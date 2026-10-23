#ifndef P0_1_10_SIEVE_OF_ERATOSTHENES_H
#define P0_1_10_SIEVE_OF_ERATOSTHENES_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
  int64_t *values;
  size_t count;
} PrimeList;

PrimeList sieve(int64_t limit);

void prime_list_free(PrimeList *list);

#endif
