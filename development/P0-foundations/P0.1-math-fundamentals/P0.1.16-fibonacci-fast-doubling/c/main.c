#include "main.h"

#include <stdlib.h>

static FibonacciPair fibonacci_recursive(u128 n) {
  if (n == 0) {
    return (FibonacciPair){0, 1};
  }

  const FibonacciPair half = fibonacci_recursive(n / 2);

  const u128 a = half.current;
  const u128 b = half.next;

  const u128 c = a * (2 * b - a);
  const u128 d = a * a + b * b;

  if (n % 2 == 0) {
    return (FibonacciPair){c, d};
  }

  return (FibonacciPair){d, c + d};
}

FibonacciPair fibonacci_fast_doubling(u128 n) {
  if (n > 185) {
    abort();
  }

  return fibonacci_recursive(n);
}
