#ifndef MAX_SUBARRAY_H
#define MAX_SUBARRAY_H

#include <stddef.h>
#include <stdint.h>

// Simula o Option<i128> do Rust para lidar com arrays vazios e evitar overflow.
// Usa __int128 (extensão do GCC/Clang) para segurança matemática absoluta.
typedef struct {
  int is_some; // 0 = None, 1 = Some
  __int128 value;
} OptionI128;

OptionI128 max_subarray_sum(const int64_t *list, size_t length);
OptionI128 max_subarray_sum_brute_force(const int64_t *list, size_t length);

#endif // MAX_SUBARRAY_H
