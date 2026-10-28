#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

bool miller_rabin(uint64_t n, uint64_t a);

typedef struct {
  uint64_t n;
  uint64_t base;
  bool expected;
} TestCase;

static void check_cases(const TestCase *cases, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    assert(miller_rabin(cases[i].n, cases[i].base) == cases[i].expected);
  }
}

static void should_handle_small_and_known_values(void) {
  const TestCase cases[] = {
      {0, 2, false},   {1, 2, false},    {2, 2, true},    {3, 2, true},
      {4, 2, false},   {5, 2, true},     {13, 2, true},   {21, 2, false},
      {97, 2, true},   {97, 3, true},    {341, 2, false}, {561, 2, false},
      {2047, 2, true}, {2047, 3, false},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_handle_large_inputs(void) {
  const TestCase cases[] = {
      {(UINT64_C(1) << 61) - 1, 2, true},
      {UINT64_MAX, 2, false},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static bool is_prime_reference(uint64_t n) {
  if (n < 2) {
    return false;
  }

  for (uint64_t d = 2; d <= n / d; ++d) {
    if (n % d == 0) {
      return false;
    }
  }

  return true;
}

static void should_accept_every_base_for_small_primes(void) {
  for (uint64_t n = 5; n <= 200; ++n) {
    if (!is_prime_reference(n)) {
      continue;
    }

    for (uint64_t a = 2; a <= n - 2; ++a) {
      assert(miller_rabin(n, a));
    }
  }
}

static void should_find_witness_for_small_odd_composites(void) {
  for (uint64_t n = 5; n <= 200; n += 2) {
    if (is_prime_reference(n)) {
      continue;
    }

    bool found_witness = false;

    for (uint64_t a = 2; a <= n - 2; ++a) {
      if (!miller_rabin(n, a)) {
        found_witness = true;
        break;
      }
    }

    assert(found_witness);
  }
}

int main(void) {
  should_handle_small_and_known_values();
  puts("[PASS] Small and known values");

  should_handle_large_inputs();
  puts("[PASS] Large inputs and overflow safety");

  should_accept_every_base_for_small_primes();
  puts("[PASS] Every base for small primes");

  should_find_witness_for_small_odd_composites();
  puts("[PASS] Witness exists for small odd composites");

  return 0;
}
