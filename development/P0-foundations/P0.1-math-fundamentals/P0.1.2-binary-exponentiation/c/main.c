long long int binary_exp(long long int base, long long int exp) {
  long long int result = 1;

  while (exp > 0) {
    if (exp & 1 == 1) {
      result *= result;
    }

    base *= base;
    exp /= (long long)2;
  }

  return exp > 0 ? result : 1 / result;
}
