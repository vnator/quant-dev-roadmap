#include "main.h"
#include <stdint.h>

static CheckedI64 multiply_checked(int64_t a, int64_t b) {
  if (a > 0) {
    if ((b > 0 && a > INT64_MAX / b) || (b < 0 && b < INT64_MIN / a)) {
      return (CheckedI64){false, 0};
    }
  } else if (a < 0) {
    if ((b > 0 && a < INT64_MIN / b) || (b < 0 && a < INT64_MAX / b)) {
      return (CheckedI64){false, 0};
    }
  }

  return (CheckedI64){true, a * b};
}

static CheckedI64 add_checked(int64_t a, int64_t b) {
  if ((b > 0 && a > INT64_MAX - b) || (b < 0 && a < INT64_MIN - b)) {
    return (CheckedI64){false, 0};
  }

  return (CheckedI64){true, a + b};
}

CheckedI64 eval_polynomial(const int64_t *coefficients, size_t length,
                           int64_t x) {
  if (length != 0 && coefficients == NULL) {
    return (CheckedI64){false, 0};
  }

  int64_t result = 0;

  for (size_t i = length; i > 0; --i) {
    CheckedI64 product = multiply_checked(result, x);

    if (!product.ok) {
      return product;
    }

    CheckedI64 sum = add_checked(product.value, coefficients[i - 1]);

    if (!sum.ok) {
      return sum;
    }

    result = sum.value;
  }

  return (CheckedI64){true, result};
}
