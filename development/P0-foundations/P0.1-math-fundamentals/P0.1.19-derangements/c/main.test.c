#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

__extension__ typedef unsigned __int128 u128;

bool derangement(u128 n, u128 *out);

static u128 from_decimal(const char *text) {
  u128 result = 0;

  while (*text != '\0') {
    assert(*text >= '0' && *text <= '9');

    result = result * 10 + (u128)(*text - '0');
    ++text;
  }

  return result;
}

static void should_compute_known_derangements(void) {
  const struct {
    u128 n;
    u128 expected;
  } cases[] = {{0, 1},      {1, 0},        {2, 1},
               {3, 2},      {4, 9},        {5, 44},
               {6, 265},    {7, 1854},     {8, 14833},
               {9, 133496}, {10, 1334961}, {20, UINT64_C(895014631192902121)}};

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    u128 result = 0;

    assert(derangement(cases[i].n, &result));
    assert(result == cases[i].expected);
  }

  u128 result = 0;

  assert(derangement(34, &result));

  assert(result == from_decimal("108610077126170304674801654684367969729"));
}

static void should_reject_overflow(void) {
  u128 result = 123;

  assert(!derangement(35, &result));
  assert(result == 123);

  assert(!derangement(0, NULL));
}

int main(void) {
  should_compute_known_derangements();
  puts("[PASS] Known derangement values");

  should_reject_overflow();
  puts("[PASS] Derangement overflow and invalid output");

  return 0;
}
