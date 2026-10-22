#include "main.h"

#include <math.h>

bool is_divisible(double n, double d) {
  if (!isfinite(n) || !isfinite(d) || d == 0.0) {
    return false;
  }

  return fmod(n, d) == 0.0;
}
