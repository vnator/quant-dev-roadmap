#include "main.h"

#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
  double n;
  double d;
  bool expected;
} TestCase;

int main(void) {
  const TestCase cases[] = {
      {4.0, 2.0, true},        {4.0, 0.0, false},      {3.0, 5.0, false},
      {0.0, 5.0, true},        {0.0, 0.0, false},      {-4.0, 2.0, true},
      {4.0, -2.0, true},       {-4.0, -2.0, true},     {4.5, 1.5, true},
      {0.5, 0.25, true},       {0.75, 0.5, false},     {2.5, 1.0, false},
      {1.0, 0.5, true},        {1.0, -0.0, false},     {NAN, 2.0, false},
      {2.0, NAN, false},       {INFINITY, 2.0, false}, {2.0, INFINITY, false},
      {-INFINITY, 2.0, false},
  };

  size_t count = sizeof(cases) / sizeof(cases[0]);

  for (size_t i = 0; i < count; ++i) {
    assert(is_divisible(cases[i].n, cases[i].d) == cases[i].expected);
  }

  printf("[PASS] Divisibility: %zu cases\n", count);

  return 0;
}
