#include <stdbool.h>

long long int binary_exp(long long int base, long long int exp) {
  long long int result = 1;
  bool is_positive = exp > 0;

  while (exp > 0) {
    if (exp & 1 == 1) {
      result *= base;
    }

    base *= base;
    exp /= (long long)2;
  }

  return is_positive ? result : 1 / result;
}
