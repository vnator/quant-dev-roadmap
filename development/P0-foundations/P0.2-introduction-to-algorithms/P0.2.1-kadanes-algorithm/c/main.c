/* Implement the mathematical algorithm here. */
#include "main.h"

OptionI128 max_subarray_sum(const int64_t *list, size_t length) {
  OptionI128 result = {0, 0}; // Equivalente a None

  if (list == NULL || length == 0) {
    return result;
  }

  __int128 best_ending = (__int128)list[0];
  __int128 best_overall = best_ending;

  for (size_t i = 1; i < length; i++) {
    __int128 value = (__int128)list[i];

    if (best_ending > 0) {
      best_ending += value;
    } else {
      best_ending = value;
    }

    if (best_ending > best_overall) {
      best_overall = best_ending;
    }
  }

  result.is_some = 1;
  result.value = best_overall;
  return result;
}

OptionI128 max_subarray_sum_brute_force(const int64_t *list, size_t length) {
  OptionI128 result = {0, 0};

  if (list == NULL || length == 0) {
    return result;
  }

  __int128 best_overall = ((__int128)1 << 127);

  for (size_t i = 0; i < length; i++) {
    __int128 current_sum = 0;
    for (size_t j = i; j < length; j++) {
      current_sum += (__int128)list[j];
      if (current_sum > best_overall) {
        best_overall = current_sum;
      }
    }
  }

  result.is_some = 1;
  result.value = best_overall;
  return result;
}
