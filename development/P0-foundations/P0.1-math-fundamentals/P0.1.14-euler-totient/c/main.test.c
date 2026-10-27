#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

uint64_t euler_phi(uint64_t n);

typedef struct {
  uint64_t input;
  uint64_t expected;
} TestCase;

static void check_cases(const TestCase *cases, size_t count) {
  for (size_t i = 0; i < count; ++i) {
    assert(euler_phi(cases[i].input) == cases[i].expected);
  }
}

static void should_compute_known_values(void) {
  const TestCase cases[] = {
      {2, 1},           {7, 6},
      {9, 6},           {12, 4},
      {30, 8},          {36, 12},
      {49, 42},         {60, 16},
      {97, 96},         {360, 96},
      {999983, 999982}, {UINT64_C(600851475143), UINT64_C(591194251200)},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static void should_handle_boundary_cases(void) {
  const TestCase cases[] = {
      {0, 0},
      {1, 1},
      {UINT64_C(1) << 63, UINT64_C(1) << 62},
      {UINT64_C(3) << 60, UINT64_C(1) << 60},
  };

  check_cases(cases, sizeof(cases) / sizeof(cases[0]));
}

static uint64_t gcd_reference(uint64_t a, uint64_t b) {
  while (b != 0) {
    uint64_t remainder = a % b;
    a = b;
    b = remainder;
  }

  return a;
}

static void should_match_definition_for_small_values(void) {
  for (uint64_t n = 1; n <= 300; ++n) {
    uint64_t count = 0;

    for (uint64_t k = 1; k <= n; ++k) {
      if (gcd_reference(k, n) == 1) {
        ++count;
      }
    }

    assert(euler_phi(n) == count);
  }
}

static void should_preserve_multiplicativity(void) {
  assert(euler_phi(5 * 8) == euler_phi(5) * euler_phi(8));
  assert(euler_phi(9 * 10) == euler_phi(9) * euler_phi(10));
  assert(euler_phi(16 * 15) == euler_phi(16) * euler_phi(15));
}

int main(void) {
  should_compute_known_values();
  puts("[PASS] Known Euler totient values");

  should_handle_boundary_cases();
  puts("[PASS] Boundary cases");

  should_match_definition_for_small_values();
  puts("[PASS] Defining relation against GCD");

  should_preserve_multiplicativity();
  puts("[PASS] Multiplicativity for coprime inputs");

  return 0;
}
