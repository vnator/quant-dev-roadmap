#include "main.h"

#include <assert.h>
#include <stdio.h>

static void test_picks_area(void) {
  // Triângulo retângulo unitário.
  assert(picks_area(0, 3) == 0.5);

  // Quadrado de lado 1.
  assert(picks_area(0, 4) == 1.0);

  // Quadrado de lado 2.
  assert(picks_area(1, 8) == 4.0);

  // Retângulo 3 x 2.
  assert(picks_area(2, 10) == 6.0);

  // Quadrado de lado 4.
  assert(picks_area(9, 16) == 16.0);

  // Triângulo retângulo com catetos 4.
  assert(picks_area(3, 12) == 8.0);
}

int main(void) {
  test_picks_area();

  puts("[PASS] Pick's theorem");

  return 0;
}
