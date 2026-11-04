#include "main.h"

#include <limits.h>

static bool contains(const IntSet *set, int64_t value) {
  for (size_t i = 0; i < set->len; ++i) {
    if (set->items[i] == value) {
      return true;
    }
  }

  return false;
}

bool inclusion_exclusion(const IntSet *sets, size_t set_count, size_t *out) {
  if (out == NULL) {
    return false;
  }

  if (set_count > 0 && sets == NULL) {
    return false;
  }

  const size_t bit_width = sizeof(size_t) * CHAR_BIT;

  if (set_count >= bit_width) {
    return false;
  }

  for (size_t i = 0; i < set_count; ++i) {
    if (sets[i].len > 0 && sets[i].items == NULL) {
      return false;
    }
  }

  const size_t subset_count = (size_t)1 << set_count;
  int64_t total = 0;

  for (size_t mask = 1; mask < subset_count; ++mask) {
    size_t base_index = SIZE_MAX;
    size_t selected_count = 0;

    for (size_t i = 0; i < set_count; ++i) {
      const size_t bit = (size_t)1 << i;

      if ((mask & bit) != 0) {
        selected_count++;

        if (base_index == SIZE_MAX || sets[i].len < sets[base_index].len) {
          base_index = i;
        }
      }
    }

    const IntSet *base_set = &sets[base_index];
    size_t intersection = 0;

    for (size_t i = 0; i < base_set->len; ++i) {
      const int64_t candidate = base_set->items[i];
      bool present_in_all = true;

      for (size_t j = 0; j < set_count; ++j) {
        const size_t bit = (size_t)1 << j;

        if ((mask & bit) != 0 && !contains(&sets[j], candidate)) {
          present_in_all = false;
          break;
        }
      }

      if (present_in_all) {
        if (intersection == SIZE_MAX) {
          return false;
        }

        intersection++;
      }
    }

    if ((uintmax_t)intersection > (uintmax_t)INT64_MAX) {
      return false;
    }

    const int64_t term = (int64_t)intersection;

    if (selected_count % 2 == 1) {
      if (total > INT64_MAX - term) {
        return false;
      }

      total += term;
    } else {
      if (total < INT64_MIN + term) {
        return false;
      }

      total -= term;
    }
  }

  if (total < 0) {
    return false;
  }

  if ((uintmax_t)total > (uintmax_t)SIZE_MAX) {
    return false;
  }

  *out = (size_t)total;

  return true;
}
