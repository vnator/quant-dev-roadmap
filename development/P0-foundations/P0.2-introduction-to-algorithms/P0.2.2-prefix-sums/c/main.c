/* Implement the mathematical algorithm here. */

#include "main.h"

#include <stdlib.h>

static prefix_sum_i128 max_i128(void) {
  return (prefix_sum_i128)(((prefix_sum_u128)-1) >> 1);
}

static prefix_sum_i128 min_i128(void) { return -max_i128() - 1; }

static int checked_add_i64(prefix_sum_i128 left, int64_t right,
                           prefix_sum_i128 *out) {
  if (right > 0 && left > max_i128() - right) {
    return 0;
  }

  if (right < 0 && left < min_i128() - right) {
    return 0;
  }

  *out = left + right;
  return 1;
}

PrefixSumError prefix_sums_new(const int64_t *values, size_t length,
                               PrefixSums *out) {
  if (out == NULL || (length > 0 && values == NULL)) {
    return PREFIX_SUM_INVALID_INPUT;
  }

  out->prefix = NULL;
  out->length = 0;

  if (length > SIZE_MAX / sizeof(prefix_sum_i128) - 1) {
    return PREFIX_SUM_ALLOCATION_FAILURE;
  }

  prefix_sum_i128 *prefix = malloc((length + 1) * sizeof(prefix_sum_i128));

  if (prefix == NULL) {
    return PREFIX_SUM_ALLOCATION_FAILURE;
  }

  prefix[0] = 0;

  for (size_t i = 0; i < length; i++) {
    if (!checked_add_i64(prefix[i], values[i], &prefix[i + 1])) {
      free(prefix);
      return PREFIX_SUM_ARITHMETIC_OVERFLOW;
    }
  }

  out->prefix = prefix;
  out->length = length;

  return PREFIX_SUM_OK;
}

PrefixSumError prefix_sums_sum(const PrefixSums *sums, size_t start, size_t end,
                               prefix_sum_i128 *out) {
  if (sums == NULL || sums->prefix == NULL || out == NULL) {
    return PREFIX_SUM_INVALID_INPUT;
  }

  if (start > end || end > sums->length) {
    return PREFIX_SUM_INVALID_RANGE;
  }

  *out = sums->prefix[end] - sums->prefix[start];

  return PREFIX_SUM_OK;
}

void prefix_sums_free(PrefixSums *sums) {
  if (sums == NULL) {
    return;
  }

  free(sums->prefix);
  sums->prefix = NULL;
  sums->length = 0;
}
