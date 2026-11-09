#include "main.h"

#include <assert.h>
#include <stdio.h>

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof((array)[0]))

static void assert_sum(const PrefixSums *sums, size_t start, size_t end,
                       prefix_sum_i128 expected) {
  prefix_sum_i128 result = 0;

  assert(prefix_sums_sum(sums, start, end, &result) == PREFIX_SUM_OK);

  assert(result == expected);
}

static void should_calculate_range_sums(void) {
  const int64_t values[] = {3, -2, 5, 1, -6};
  PrefixSums sums = {0};

  assert(prefix_sums_new(values, ARRAY_LENGTH(values), &sums) == PREFIX_SUM_OK);

  assert_sum(&sums, 1, 4, 4);
  assert_sum(&sums, 0, 5, 1);
  assert_sum(&sums, 2, 4, 6);
  assert_sum(&sums, 0, 0, 0);
  assert_sum(&sums, 5, 5, 0);

  prefix_sums_free(&sums);
  printf("[PASS] should_calculate_range_sums\n");
}

static void should_handle_negative_values(void) {
  const int64_t values[] = {-5, -2, -8};
  PrefixSums sums = {0};

  assert(prefix_sums_new(values, ARRAY_LENGTH(values), &sums) == PREFIX_SUM_OK);

  assert_sum(&sums, 0, 3, -15);
  assert_sum(&sums, 1, 2, -2);
  assert_sum(&sums, 0, 1, -5);

  prefix_sums_free(&sums);
  printf("[PASS] should_handle_negative_values\n");
}

static void should_handle_empty_input(void) {
  PrefixSums sums = {0};

  assert(prefix_sums_new(NULL, 0, &sums) == PREFIX_SUM_OK);
  assert(sums.length == 0);

  assert_sum(&sums, 0, 0, 0);

  prefix_sums_free(&sums);
  printf("[PASS] should_handle_empty_input\n");
}

static void should_handle_single_element(void) {
  const int64_t values[] = {42};
  PrefixSums sums = {0};

  assert(prefix_sums_new(values, ARRAY_LENGTH(values), &sums) == PREFIX_SUM_OK);

  assert_sum(&sums, 0, 1, 42);
  assert_sum(&sums, 0, 0, 0);
  assert_sum(&sums, 1, 1, 0);

  prefix_sums_free(&sums);
  printf("[PASS] should_handle_single_element\n");
}

static void should_handle_i64_boundaries(void) {
  const int64_t values[] = {INT64_MAX, INT64_MIN, INT64_MAX};

  PrefixSums sums = {0};

  assert(prefix_sums_new(values, ARRAY_LENGTH(values), &sums) == PREFIX_SUM_OK);

  assert_sum(&sums, 0, 1, (prefix_sum_i128)INT64_MAX);
  assert_sum(&sums, 0, 2, -1);
  assert_sum(&sums, 0, 3, (prefix_sum_i128)INT64_MAX - 1);
  assert_sum(&sums, 1, 3, -1);

  prefix_sums_free(&sums);
  printf("[PASS] should_handle_i64_boundaries\n");
}

static void should_reject_invalid_ranges(void) {
  const int64_t values[] = {1, 2, 3};
  PrefixSums sums = {0};
  prefix_sum_i128 result = 0;

  assert(prefix_sums_new(values, ARRAY_LENGTH(values), &sums) == PREFIX_SUM_OK);

  assert(prefix_sums_sum(&sums, 2, 1, &result) == PREFIX_SUM_INVALID_RANGE);

  assert(prefix_sums_sum(&sums, 0, 4, &result) == PREFIX_SUM_INVALID_RANGE);

  assert(prefix_sums_sum(&sums, 4, 4, &result) == PREFIX_SUM_INVALID_RANGE);

  prefix_sums_free(&sums);
  printf("[PASS] should_reject_invalid_ranges\n");
}

static void should_reject_invalid_inputs(void) {
  PrefixSums sums = {0};
  prefix_sum_i128 result = 0;

  assert(prefix_sums_new(NULL, 1, &sums) == PREFIX_SUM_INVALID_INPUT);

  assert(prefix_sums_sum(NULL, 0, 0, &result) == PREFIX_SUM_INVALID_INPUT);

  assert(prefix_sums_sum(&sums, 0, 0, &result) == PREFIX_SUM_INVALID_INPUT);

  assert(prefix_sums_sum(&sums, 0, 0, NULL) == PREFIX_SUM_INVALID_INPUT);

  printf("[PASS] should_reject_invalid_inputs\n");
}

static void should_match_direct_sum_for_every_range(void) {
  const int64_t values[] = {3, -2, 5, 1, -6, 10, -20, 30};

  const size_t length = ARRAY_LENGTH(values);
  PrefixSums sums = {0};

  assert(prefix_sums_new(values, length, &sums) == PREFIX_SUM_OK);

  for (size_t start = 0; start <= length; start++) {
    for (size_t end = start; end <= length; end++) {
      prefix_sum_i128 expected = 0;
      prefix_sum_i128 actual = 0;

      for (size_t i = start; i < end; i++) {
        expected += (prefix_sum_i128)values[i];
      }

      assert(prefix_sums_sum(&sums, start, end, &actual) == PREFIX_SUM_OK);

      assert(actual == expected);
    }
  }

  prefix_sums_free(&sums);
  printf("[PASS] should_match_direct_sum_for_every_range\n");
}

int main(void) {
  should_calculate_range_sums();
  should_handle_negative_values();
  should_handle_empty_input();
  should_handle_single_element();
  should_handle_i64_boundaries();
  should_reject_invalid_ranges();
  should_reject_invalid_inputs();
  should_match_direct_sum_for_every_range();

  printf("\nAll PrefixSums tests passed.\n");

  return 0;
}
