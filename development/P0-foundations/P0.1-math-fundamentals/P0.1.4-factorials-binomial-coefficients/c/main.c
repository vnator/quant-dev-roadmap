
static long long int factorial_binomial(long long n, long long k) {
  if (k > n)
    return 0;

  if (k > (n - k)) {
    k = n - k;
  }

  long long result = 1LL;

  for (int i = 1; i <= k; i++) {
    result = (result * (n - i + 1)) / i;
  }

  return result;
}
