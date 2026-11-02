
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

__extension__ typedef unsigned __int128 u128;

bool catalan_number(uint64_t n, u128 *out);

static u128 from_decimal(const char *text) {
  u128 result = 0;

  while (*text != '\0') {
    assert(*text >= '0' && *text <= '9');

    result = result * 10 + (u128)(*text - '0');
    ++text;
  }

  return result;
}

static void should_compute_known_catalan_numbers(void) {
  const u128 expected[] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796};

  for (uint64_t n = 0; n < sizeof(expected) / sizeof(expected[0]); ++n) {
    u128 result = 0;

    assert(catalan_number(n, &result));
    assert(result == expected[n]);
  }
}

static void should_compute_largest_catalan_number_in_u128(void) {
  u128 result = 0;

  assert(catalan_number(69, &result));

  assert(result == from_decimal("337485502510215975556783793455058624700"));
}

static void should_reject_overflow(void) {
  u128 result = 123;

  assert(!catalan_number(70, &result));
  assert(result == 123);

  assert(!catalan_number(0, NULL));
}

int main(void) {
  should_compute_known_catalan_numbers();
  puts("[PASS] Known Catalan numbers");

  should_compute_largest_catalan_number_in_u128();
  puts("[PASS] Largest Catalan number in u128");

  should_reject_overflow();
  puts("[PASS] Catalan overflow and invalid output");

  return 0;
}
