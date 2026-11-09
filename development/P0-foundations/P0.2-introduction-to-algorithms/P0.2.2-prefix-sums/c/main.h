
#ifndef PREFIX_SUMS_H
#define PREFIX_SUMS_H

#include <stddef.h>
#include <stdint.h>

__extension__ typedef __int128 prefix_sum_i128;
__extension__ typedef unsigned __int128 prefix_sum_u128;

typedef enum {
  PREFIX_SUM_OK,
  PREFIX_SUM_INVALID_RANGE,
  PREFIX_SUM_ARITHMETIC_OVERFLOW,
  PREFIX_SUM_ALLOCATION_FAILURE,
  PREFIX_SUM_INVALID_INPUT
} PrefixSumError;

typedef struct {
  prefix_sum_i128 *prefix;
  size_t length;
} PrefixSums;

PrefixSumError prefix_sums_new(const int64_t *values, size_t length,
                               PrefixSums *out);

PrefixSumError prefix_sums_sum(const PrefixSums *sums, size_t start, size_t end,
                               prefix_sum_i128 *out);

void prefix_sums_free(PrefixSums *sums);

#endif
