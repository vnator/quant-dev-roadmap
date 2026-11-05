#include "main.h"

#include <assert.h>
#include <stdio.h>

static void test_triangle(void) {
  const double x[] = {0.0, 4.0, 0.0};
  const double y[] = {0.0, 0.0, 3.0};

  const Vector vector = {x, y, 3};

  double result = 0.0;

  assert(shoelace(&vector, &result));
  assert(result == 6.0);
}

static void test_unit_square(void) {
  const double x[] = {0.0, 1.0, 1.0, 0.0};
  const double y[] = {0.0, 0.0, 1.0, 1.0};

  const Vector vector = {x, y, 4};

  double result = 0.0;

  assert(shoelace(&vector, &result));
  assert(result == 1.0);
}

static void test_rectangle(void) {
  const double x[] = {0.0, 3.0, 3.0, 0.0};
  const double y[] = {0.0, 0.0, 2.0, 2.0};

  const Vector vector = {x, y, 4};

  double result = 0.0;

  assert(shoelace(&vector, &result));
  assert(result == 6.0);
}

static void test_fractional_area(void) {
  const double x[] = {0.0, 0.0, 1.0};
  const double y[] = {0.0, 1.0, 1.0};

  const Vector vector = {x, y, 3};

  double result = 0.0;

  assert(shoelace(&vector, &result));
  assert(result == 0.5);
}

static void test_clockwise_ordering(void) {
  const double x[] = {0.0, 0.0, 1.0, 1.0};
  const double y[] = {0.0, 1.0, 1.0, 0.0};

  const Vector vector = {x, y, 4};

  double result = 0.0;

  assert(shoelace(&vector, &result));
  assert(result == 1.0);
}

static void test_invalid_input(void) {
  double result = 0.0;

  const Vector too_small = {(double[]){0.0, 1.0}, (double[]){0.0, 1.0}, 2};

  assert(!shoelace(&too_small, &result));
  assert(!shoelace(NULL, &result));
  assert(!shoelace(&too_small, NULL));
}

int main(void) {
  test_triangle();
  puts("[PASS] Triangle");

  test_unit_square();
  puts("[PASS] Unit square");

  test_rectangle();
  puts("[PASS] Rectangle");

  test_fractional_area();
  puts("[PASS] Fractional area");

  test_clockwise_ordering();
  puts("[PASS] Clockwise ordering");

  test_invalid_input();
  puts("[PASS] Invalid input");

  return 0;
}
