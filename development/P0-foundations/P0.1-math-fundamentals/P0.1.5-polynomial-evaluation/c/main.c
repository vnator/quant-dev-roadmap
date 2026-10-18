
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

static bool multiply_checked(int64_t a, int64_t b, int64_t *out) {
  if (a > 0) {
    if ((b > 0 && a > INT64_MAX / b) || (b < 0 && b < INT64_MIN / a)) {
      return false;
    }
  } else if (a < 0) {
    if ((b > 0 && a < INT64_MIN / b) || (b < 0 && a < INT64_MAX / b)) {
      return false;
    }
  }

  *out = a * b;
  return true;
}

static bool add_checked(int64_t a, int64_t b, int64_t *out) {
  if ((b > 0 && a > INT64_MAX - b) || (b < 0 && a < INT64_MIN - b)) {
    return false;
  }

  *out = a + b;
  return true;
}

bool eval_polynomial(const int64_t *coefficients, size_t length, int64_t x,
                     int64_t *out) {
  if (out == NULL || (length != 0 && coefficients == NULL)) {
    return false;
  }

  int64_t result = 0;

  for (size_t i = length; i > 0; --i) {
    if (!multiply_checked(result, x, &result) ||
        !add_checked(result, coefficients[i - 1], &result)) {
      return false;
    }
  }

  *out = result;
  return true;
}
