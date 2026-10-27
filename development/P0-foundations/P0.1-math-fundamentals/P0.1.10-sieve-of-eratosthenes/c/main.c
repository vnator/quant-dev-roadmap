
#include "main.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

PrimeList sieve(int64_t limit) {
  PrimeList result = {NULL, 0};

  if (limit < 2) {
    return result;
  }

  if ((uint64_t)limit >= (uint64_t)SIZE_MAX) {
    abort();
  }

  size_t n = (size_t)limit;
  uint8_t *is_prime = malloc(n + 1);

  if (is_prime == NULL) {
    abort();
  }

  memset(is_prime, 1, n + 1);

  is_prime[0] = 0;
  is_prime[1] = 0;

  for (size_t p = 2; p <= n / p; ++p) {
    if (is_prime[p] == 1) {
      for (size_t i = p * p; i <= n;) {
        is_prime[i] = 0;

        if (i > n - p) {
          break;
        }

        i += p;
      }
    }
  }

  // Count prime numbers.
  for (size_t i = 2; i <= n; ++i) {
    if (is_prime[i] == 1) {
      ++result.count;
    }
  }

  if (result.count > SIZE_MAX / sizeof(*result.values)) {
    free(is_prime);
    abort();
  }

  result.values = malloc(result.count * sizeof(*result.values));

  if (result.values == NULL) {
    free(is_prime);
    abort();
  }

  size_t index = 0;

  // Collect prime numbers.
  for (size_t i = 2; i <= n; ++i) {
    if (is_prime[i] == 1) {
      result.values[index++] = (int64_t)i;
    }
  }

  free(is_prime);

  return result;
}

void prime_list_free(PrimeList *list) {
  if (list == NULL) {
    return;
  }

  free(list->values);

  list->values = NULL;
  list->count = 0;
}
