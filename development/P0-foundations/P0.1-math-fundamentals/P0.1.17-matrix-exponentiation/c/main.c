#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Validates the dimension and calculates allocation size.
static bool matrix_bytes(size_t n, size_t *bytes) {
  if (n == 0 || n > SIZE_MAX / n) {
    return false;
  }

  const size_t count = n * n;

  if (count > SIZE_MAX / sizeof(int32_t)) {
    return false;
  }

  *bytes = count * sizeof(int32_t);
  return true;
}

// Internal multiplication.
// The result buffer must not overlap the inputs.
static bool multiply_into(const int32_t *a, const int32_t *b, size_t n,
                          int32_t *result) {
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      int32_t sum = 0;

      for (size_t k = 0; k < n; ++k) {
        // Every int32_t product fits in int64_t.
        const int64_t product = (int64_t)a[i * n + k] * b[k * n + j];

        if (product < INT32_MIN || product > INT32_MAX) {
          return false;
        }

        const int64_t next = (int64_t)sum + product;

        if (next < INT32_MIN || next > INT32_MAX) {
          return false;
        }

        sum = (int32_t)next;
      }

      result[i * n + j] = sum;
    }
  }

  return true;
}

// Matrix multiplication: C = A * B.
// Returns false on invalid input, overflow or allocation failure.
// The output remains unchanged on failure.
bool matrix_multiply(const int32_t *a, const int32_t *b, size_t n,
                     int32_t *out) {
  size_t bytes;

  if (a == NULL || b == NULL || out == NULL || !matrix_bytes(n, &bytes)) {
    return false;
  }

  int32_t *scratch = malloc(bytes);

  if (scratch == NULL) {
    return false;
  }

  const bool ok = multiply_into(a, b, n, scratch);

  if (ok) {
    memcpy(out, scratch, bytes);
  }

  free(scratch);
  return ok;
}

// Matrix exponentiation by repeated squaring.
// Computes A^exponent, including A^0 = I.
bool matrix_power(const int32_t *matrix, size_t n, uint64_t exponent,
                  int32_t *out) {
  size_t bytes;

  if (matrix == NULL || out == NULL || !matrix_bytes(n, &bytes)) {
    return false;
  }

  int32_t *base = malloc(bytes);
  int32_t *result = calloc(n * n, sizeof(int32_t));
  int32_t *scratch = malloc(bytes);

  if (base == NULL || result == NULL || scratch == NULL) {
    free(base);
    free(result);
    free(scratch);
    return false;
  }

  memcpy(base, matrix, bytes);

  // Initialize the identity matrix.
  for (size_t i = 0; i < n; ++i) {
    result[i * n + i] = 1;
  }

  bool ok = true;

  while (exponent > 0) {
    if (exponent % 2 != 0) {
      if (!multiply_into(result, base, n, scratch)) {
        ok = false;
        break;
      }

      memcpy(result, scratch, bytes);
    }

    exponent /= 2;

    if (exponent > 0) {
      if (!multiply_into(base, base, n, scratch)) {
        ok = false;
        break;
      }

      memcpy(base, scratch, bytes);
    }
  }

  if (ok) {
    memcpy(out, result, bytes);
  }

  free(base);
  free(result);
  free(scratch);

  return ok;
}
