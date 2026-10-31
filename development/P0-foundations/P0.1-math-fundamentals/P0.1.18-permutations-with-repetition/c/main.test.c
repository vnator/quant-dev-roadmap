#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

__extension__ typedef unsigned __int128 u128;

bool factorial_binomial(uint64_t n, uint64_t k, u128 *out);

bool permutations_with_repetition(uint64_t n, const uint64_t *multiplicities,
                                  size_t count, u128 *out);

static void should_compute_binomial_coefficients(void) {
  u128 result = 0;

  assert(factorial_binomial(5, 2, &result));
  assert(result == 10);

  assert(factorial_binomial(5, 0, &result));
  assert(result == 1);

  assert(factorial_binomial(5, 5, &result));
  assert(result == 1);

  assert(factorial_binomial(5, 6, &result));
  assert(result == 0);
}

static void should_compute_permutations_with_repetition(void) {
  const uint64_t banana[] = {3, 2, 1};
  const uint64_t all_distinct[] = {1, 1, 1};
  const uint64_t with_zero_groups[] = {0, 2, 0, 1};

  u128 result = 0;

  assert(permutations_with_repetition(6, banana, 3, &result));
  assert(result == 60);

  assert(permutations_with_repetition(3, all_distinct, 3, &result));
  assert(result == 6);

  assert(permutations_with_repetition(3, with_zero_groups, 4, &result));
  assert(result == 3);

  assert(permutations_with_repetition(0, NULL, 0, &result));
  assert(result == 1);
}

static void should_reject_invalid_multiplicities(void) {
  const uint64_t too_many[] = {3, 3};
  const uint64_t too_few[] = {2, 2};

  u128 result = 123;

  assert(!permutations_with_repetition(5, too_many, 2, &result));
  assert(result == 123);

  assert(!permutations_with_repetition(5, too_few, 2, &result));
  assert(result == 123);

  assert(!permutations_with_repetition(3, NULL, 1, &result));
  assert(result == 123);
}

static void should_detect_overflow(void) {
  u128 result = 123;

  const uint64_t all_distinct[35] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

  assert(!factorial_binomial(135, 67, &result));
  assert(result == 123);

  assert(!permutations_with_repetition(35, all_distinct, 35, &result));
  assert(result == 123);
}

int main(void) {
  should_compute_binomial_coefficients();
  puts("[PASS] Binomial coefficients");

  should_compute_permutations_with_repetition();
  puts("[PASS] Permutations with repetition");

  should_reject_invalid_multiplicities();
  puts("[PASS] Invalid multiplicities");

  should_detect_overflow();
  puts("[PASS] Overflow detection");

  return 0;
}
