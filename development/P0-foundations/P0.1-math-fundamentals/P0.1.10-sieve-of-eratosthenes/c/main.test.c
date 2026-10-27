#include "main.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static void assert_primes(int64_t limit, const int64_t *expected,
                          size_t expected_count) {
  PrimeList result = sieve(limit);

  assert(result.count == expected_count);

  for (size_t i = 0; i < expected_count; ++i) {
    assert(result.values[i] == expected[i]);
  }

  prime_list_free(&result);

  assert(result.values == NULL);
  assert(result.count == 0);
}

static void should_handle_boundary_limits(void) {
  assert_primes(-10, NULL, 0);
  assert_primes(-1, NULL, 0);
  assert_primes(0, NULL, 0);
  assert_primes(1, NULL, 0);

  const int64_t two[] = {2};
  const int64_t three[] = {2, 3};

  assert_primes(2, two, 1);
  assert_primes(3, three, 2);
  assert_primes(4, three, 2);
}

static void should_generate_known_prime_sets(void) {
  const int64_t ten[] = {2, 3, 5, 7};

  const int64_t twenty_five[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

  const int64_t thirty[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

  assert_primes(10, ten, sizeof(ten) / sizeof(ten[0]));

  assert_primes(25, twenty_five, sizeof(twenty_five) / sizeof(twenty_five[0]));

  assert_primes(30, thirty, sizeof(thirty) / sizeof(thirty[0]));
}

static void should_compute_prime_count(void) {
  const struct {
    int64_t limit;
    size_t expected_count;
    int64_t last_prime;
  } cases[] = {
      {100, 25, 97},
      {1000, 168, 997},
      {10000, 1229, 9973},
      {100000, 9592, 99991},
  };

  size_t count = sizeof(cases) / sizeof(cases[0]);

  for (size_t i = 0; i < count; ++i) {
    PrimeList result = sieve(cases[i].limit);

    assert(result.count == cases[i].expected_count);

    assert(result.values[result.count - 1] == cases[i].last_prime);

    for (size_t j = 1; j < result.count; ++j) {
      assert(result.values[j] > result.values[j - 1]);
    }

    prime_list_free(&result);
  }
}

static void should_release_memory(void) {
  PrimeList empty = sieve(1);

  prime_list_free(&empty);
  prime_list_free(&empty);
  prime_list_free(NULL);
}

int main(void) {
  should_handle_boundary_limits();
  should_generate_known_prime_sets();
  should_compute_prime_count();
  should_release_memory();

  puts("[PASS] P0.1.10 - Sieve of Eratosthenes");

  return 0;
}
