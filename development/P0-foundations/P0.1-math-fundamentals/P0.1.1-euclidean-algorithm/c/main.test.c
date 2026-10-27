#include <assert.h>
#include <limits.h>
#include <stdio.h>

unsigned int gcd(int a, int b);

static void test_greastest_common_divisor(void) {
  assert(gcd(252, 105) == 21u);
}

static void should_return_zero(void) { assert(gcd(0, 0) == 0u); }

static void should_return_same_value_that_the_entries(void) {
  assert(gcd(2, 2) == 2u);
}

static void should_return_the_greatest_common_divisor_positive_number(void) {
  assert(gcd(-252, 105) == 21u);
  assert(gcd(252, -105) == 21u);
}

int main(void) {
  test_greastest_common_divisor();
  puts("[PASS] Greatest common divisor");

  should_return_zero();
  puts("[PASS] Should return zero");

  should_return_same_value_that_the_entries();
  puts("[PASS] Should return same value that the entries");

  should_return_the_greatest_common_divisor_positive_number();
  puts("[PASS] Should return the greastest common divisor positive number");

  return 0;
}
