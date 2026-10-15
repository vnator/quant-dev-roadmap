#include <assert.h>
#include <stdio.h>

long long int binary_exp(long long base, long long exp);

static void should_compute_positive_powers(void) {
  assert(binary_exp(2, 1) == 2LL);
  assert(binary_exp(2, 2) == 4LL);
  assert(binary_exp(2, 3) == 8LL);
  assert(binary_exp(2, 10) == 1024LL);
  assert(binary_exp(3, 5) == 243);
}

static void should_handle_negative_bases(void) {
  assert(binary_exp(-2, 3) == -8LL);
  assert(binary_exp(-2, 4) == 16LL);
  assert(binary_exp(-1, 7) == -1LL);
}

static void should_handle_boundary_cases(void) {
  assert(binary_exp(7, 0) == 1LL);
  assert(binary_exp(0, 0) == 1LL);
  assert(binary_exp(0, 5) == 0LL);
  assert(binary_exp(1, 12) == 1LL);
}

int main() {
  should_compute_positive_powers();
  puts("[PASS] Positive powers");

  should_handle_negative_bases();
  puts("[PASS] Negative powers");

  should_handle_boundary_cases();
  puts("[PASS] Boundary cases");

  return 0;
}
