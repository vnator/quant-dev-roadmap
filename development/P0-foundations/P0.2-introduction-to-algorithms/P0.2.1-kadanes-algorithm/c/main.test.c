#include "main.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static void assert_max_subarray(const int64_t *list, size_t length,
                                int expected_is_some, __int128 expected_value) {
  OptionI128 result = max_subarray_sum(list, length);

  assert(result.is_some == expected_is_some);

  if (expected_is_some) {
    assert(result.value == expected_value);
  }
}

static void should_handle_boundary_limits(void) {
  assert_max_subarray(NULL, 0, 0, 0);

  const int64_t single[] = {42};
  assert_max_subarray(single, 1, 1, 42);

  const int64_t max_val = INT64_MAX;
  const int64_t overflow[] = {max_val, max_val, -10, max_val};
  __int128 expected_overflow = ((__int128)max_val * 3) - 10;

  assert_max_subarray(overflow, 4, 1, expected_overflow);
}

static void should_compute_known_subarray_sums(void) {
  const int64_t all_pos[] = {1, 2, 3, 4, 5};
  assert_max_subarray(all_pos, 5, 1, 15);

  const int64_t all_neg[] = {-8, -3, -5, -2, -9};
  assert_max_subarray(all_neg, 5, 1,
                      -2); // Should pick the least negative number

  const int64_t mixed[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  assert_max_subarray(mixed, 9, 1, 6);
}

static void should_match_brute_force_implementation(void) {
  const int64_t case_1[] = {1, -2, 3, 4, -5, 8};
  const int64_t case_2[] = {-5, -1, -8, -9};
  const int64_t case_3[] = {10, -20, 30, -40, 50, -60, 70};
  const int64_t case_4[] = {0, 0, 0, 0};
  const int64_t case_5[] = {INT64_MIN, INT64_MAX};

  const struct {
    const int64_t *list;
    size_t length;
  } cases[] = {
      {case_1, sizeof(case_1) / sizeof(case_1[0])},
      {case_2, sizeof(case_2) / sizeof(case_2[0])},
      {case_3, sizeof(case_3) / sizeof(case_3[0])},
      {case_4, sizeof(case_4) / sizeof(case_4[0])},
      {case_5, sizeof(case_5) / sizeof(case_5[0])},
  };

  size_t count = sizeof(cases) / sizeof(cases[0]);

  for (size_t i = 0; i < count; ++i) {
    OptionI128 kadane = max_subarray_sum(cases[i].list, cases[i].length);
    OptionI128 brute =
        max_subarray_sum_brute_force(cases[i].list, cases[i].length);

    assert(kadane.is_some == brute.is_some);

    if (kadane.is_some) {
      assert(kadane.value == brute.value);
    }
  }
}

int main(void) {
  should_handle_boundary_limits();
  should_compute_known_subarray_sums();
  should_match_brute_force_implementation();

  puts("[PASS] Maximum Subarray Sum (Kadane)");

  return 0;
}
