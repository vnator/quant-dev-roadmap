#include "main.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Verifica se uma linha representa uma permutação válida.
static bool is_valid_permutation(const size_t *permutation, size_t size,
                                 bool *seen) {
  if (size == 0) {
    return true;
  }

  memset(seen, 0, size * sizeof(bool));

  for (size_t i = 0; i < size; ++i) {
    const size_t image = permutation[i];

    if (image >= size || seen[image]) {
      return false;
    }

    seen[image] = true;
  }

  return true;
}

bool burnside_orbits(const size_t *group_actions, size_t group_count,
                     size_t set_size, size_t *out) {
  if (out == NULL || group_count == 0) {
    return false;
  }

  if (set_size > 0 && group_actions == NULL) {
    return false;
  }

  if (set_size > 0 && group_count > SIZE_MAX / set_size) {
    return false;
  }

  const size_t entry_count = group_count * set_size;

  if (entry_count > SIZE_MAX / sizeof(size_t)) {
    return false;
  }

  bool *seen = NULL;

  if (set_size > 0) {
    if (set_size > SIZE_MAX / sizeof(bool)) {
      return false;
    }

    seen = calloc(set_size, sizeof(bool));

    if (seen == NULL) {
      return false;
    }
  }

  uintmax_t total_fixed = 0;

  for (size_t g = 0; g < group_count; ++g) {
    const size_t *permutation = NULL;

    if (set_size > 0) {
      permutation = group_actions + (g * set_size);
    }

    if (!is_valid_permutation(permutation, set_size, seen)) {
      free(seen);
      return false;
    }

    size_t fixed_count = 0;

    for (size_t i = 0; i < set_size; ++i) {
      if (permutation[i] == i) {
        fixed_count++;
      }
    }

    if (total_fixed > UINTMAX_MAX - (uintmax_t)fixed_count) {
      free(seen);
      return false;
    }

    total_fixed += (uintmax_t)fixed_count;
  }

  free(seen);

  const uintmax_t group_size = (uintmax_t)group_count;

  if (total_fixed % group_size != 0) {
    return false;
  }

  const uintmax_t result = total_fixed / group_size;

  if (result > (uintmax_t)SIZE_MAX) {
    return false;
  }

  *out = (size_t)result;

  return true;
}
