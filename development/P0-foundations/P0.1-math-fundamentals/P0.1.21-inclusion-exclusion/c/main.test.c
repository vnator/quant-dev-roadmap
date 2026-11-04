#include "main.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>

static void test_empty_input(void) {
  size_t result = 99;

  assert(inclusion_exclusion(NULL, 0, &result));
  assert(result == 0);
}

static void test_single_set(void) {
  const int64_t a[] = {1, 2, 3};

  const IntSet sets[] = {{a, 3}};

  size_t result = 0;

  assert(inclusion_exclusion(sets, 1, &result));
  assert(result == 3);
}

static void test_disjoint_sets(void) {
  const int64_t a[] = {1, 2};
  const int64_t b[] = {3, 4};
  const int64_t c[] = {5};

  const IntSet sets[] = {{a, 2}, {b, 2}, {c, 1}};

  size_t result = 0;

  assert(inclusion_exclusion(sets, 3, &result));
  assert(result == 5);
}

static void test_two_overlapping_sets(void) {
  const int64_t a[] = {1, 2, 3};
  const int64_t b[] = {3, 4};

  const IntSet sets[] = {{a, 3}, {b, 2}};

  size_t result = 0;

  assert(inclusion_exclusion(sets, 2, &result));
  assert(result == 4);
}

static void test_three_overlapping_sets(void) {
  const int64_t a[] = {1, 2, 3};
  const int64_t b[] = {2, 3, 4};
  const int64_t c[] = {3, 4, 5};

  const IntSet sets[] = {{a, 3}, {b, 3}, {c, 3}};

  size_t result = 0;

  assert(inclusion_exclusion(sets, 3, &result));
  assert(result == 5);
}

static void test_identical_sets(void) {
  const int64_t a[] = {1, 2};

  const IntSet sets[] = {{a, 2}, {a, 2}};

  size_t result = 0;

  assert(inclusion_exclusion(sets, 2, &result));
  assert(result == 2);
}

static void test_empty_set_in_collection(void) {
  const int64_t a[] = {1, 2};

  const IntSet sets[] = {{NULL, 0}, {a, 2}};

  size_t result = 0;

  assert(inclusion_exclusion(sets, 2, &result));
  assert(result == 2);
}

static void test_invalid_arguments(void) {
  size_t result = 0;

  const IntSet invalid = {NULL, 1};

  assert(!inclusion_exclusion(NULL, 1, &result));
  assert(!inclusion_exclusion(&invalid, 1, &result));
  assert(!inclusion_exclusion(NULL, 0, NULL));

  IntSet many[sizeof(size_t) * CHAR_BIT] = {0};

  assert(!inclusion_exclusion(many, sizeof(many) / sizeof(many[0]), &result));
}

int main(void) {
  test_empty_input();
  puts("[PASS] Empty input");

  test_single_set();
  puts("[PASS] Single set");

  test_disjoint_sets();
  puts("[PASS] Disjoint sets");

  test_two_overlapping_sets();
  puts("[PASS] Two overlapping sets");

  test_three_overlapping_sets();
  puts("[PASS] Three overlapping sets");

  test_identical_sets();
  puts("[PASS] Identical sets");

  test_empty_set_in_collection();
  puts("[PASS] Empty set in collection");

  test_invalid_arguments();
  puts("[PASS] Invalid arguments");

  return 0;
}
