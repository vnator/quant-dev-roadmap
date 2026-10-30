#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool matrix_multiply(const int32_t *a, const int32_t *b, size_t n,
                     int32_t *out);

bool matrix_power(const int32_t *matrix, size_t n, uint64_t exponent,
                  int32_t *out);

static void assert_matrix_equals(const int32_t *actual, const int32_t *expected,
                                 size_t n) {
  for (size_t i = 0; i < n * n; ++i) {
    assert(actual[i] == expected[i]);
  }
}

static void should_multiply_matrices(void) {
  const int32_t a[4] = {1, 2, 3, 4};
  const int32_t b[4] = {5, 6, 7, 8};
  const int32_t expected[4] = {19, 22, 43, 50};

  int32_t out[4] = {0};

  assert(matrix_multiply(a, b, 2, out));
  assert_matrix_equals(out, expected, 2);

  assert_matrix_equals(a, (const int32_t[4]){1, 2, 3, 4}, 2);
}

static void should_compute_fibonacci_matrix_powers(void) {
  const int32_t a[4] = {1, 1, 1, 0};

  typedef struct {
    uint64_t exponent;
    int32_t expected[4];
  } TestCase;

  const TestCase cases[] = {
      {0, {1, 0, 0, 1}},
      {1, {1, 1, 1, 0}},
      {2, {2, 1, 1, 1}},
      {5, {8, 5, 5, 3}},
      {10, {89, 55, 55, 34}},
      {45, {1836311903, 1134903170, 1134903170, 701408733}},
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    int32_t out[4] = {0};

    assert(matrix_power(a, 2, cases[i].exponent, out));

    assert_matrix_equals(out, cases[i].expected, 2);
  }
}

static void should_support_negative_elements(void) {
  const int32_t a[4] = {1, -1, 1, 0};
  const int32_t expected[4] = {-1, 0, 0, -1};

  int32_t out[4];

  assert(matrix_power(a, 2, 3, out));
  assert_matrix_equals(out, expected, 2);
}

static void should_support_one_by_one_and_three_by_three(void) {
  const int32_t scalar[1] = {-2};
  int32_t scalar_out[1] = {0};

  assert(matrix_power(scalar, 1, 3, scalar_out));
  assert(scalar_out[0] == -8);

  const int32_t a[9] = {1, 1, 0, 0, 1, 1, 0, 0, 1};

  const int32_t expected[9] = {1, 3, 3, 0, 1, 3, 0, 0, 1};

  int32_t out[9];

  assert(matrix_power(a, 3, 3, out));
  assert_matrix_equals(out, expected, 3);
}

static void should_preserve_power_addition_law(void) {
  const int32_t a[4] = {1, 1, 1, 0};

  int32_t a3[4];
  int32_t a4[4];
  int32_t a7[4];
  int32_t product[4];

  assert(matrix_power(a, 2, 3, a3));
  assert(matrix_power(a, 2, 4, a4));
  assert(matrix_power(a, 2, 7, a7));

  assert(matrix_multiply(a3, a4, 2, product));
  assert_matrix_equals(product, a7, 2);
}

static void
should_reject_multiplication_overflow_without_changing_output(void) {
  const int32_t a[1] = {50000};
  int32_t out[1] = {123};

  assert(!matrix_multiply(a, a, 1, out));
  assert(out[0] == 123);

  const int32_t b[4] = {INT32_MAX, INT32_MAX, 1, 1};

  const int32_t c[4] = {1, 0, 1, 0};

  int32_t out2[4] = {11, 22, 33, 44};

  assert(!matrix_multiply(b, c, 2, out2));

  assert_matrix_equals(out2, (const int32_t[4]){11, 22, 33, 44}, 2);
}

static void should_reject_power_overflow_without_changing_output(void) {
  const int32_t a[4] = {1, 1, 1, 0};
  int32_t out[4] = {7, 8, 9, 10};

  assert(!matrix_power(a, 2, 46, out));

  assert_matrix_equals(out, (const int32_t[4]){7, 8, 9, 10}, 2);
}

static void should_support_input_output_aliasing(void) {
  int32_t a[4] = {1, 1, 1, 0};
  const int32_t squared[4] = {2, 1, 1, 1};

  assert(matrix_multiply(a, a, 2, a));
  assert_matrix_equals(a, squared, 2);

  int32_t b[4] = {1, 1, 1, 0};
  const int32_t fifth[4] = {8, 5, 5, 3};

  assert(matrix_power(b, 2, 5, b));
  assert_matrix_equals(b, fifth, 2);
}

static void should_reject_invalid_inputs(void) {
  const int32_t a[1] = {1};
  int32_t out[1] = {42};

  assert(!matrix_power(NULL, 1, 1, out));
  assert(!matrix_power(a, 0, 1, out));
  assert(!matrix_power(a, SIZE_MAX, 1, out));
  assert(!matrix_power(a, 1, 1, NULL));

  assert(!matrix_multiply(NULL, a, 1, out));
  assert(!matrix_multiply(a, NULL, 1, out));
  assert(!matrix_multiply(a, a, 0, out));
  assert(!matrix_multiply(a, a, 1, NULL));

  assert(out[0] == 42);
}

int main(void) {
  should_multiply_matrices();
  puts("[PASS] Matrix multiplication");

  should_compute_fibonacci_matrix_powers();
  puts("[PASS] Fibonacci matrix powers");

  should_support_negative_elements();
  puts("[PASS] Negative elements");

  should_support_one_by_one_and_three_by_three();
  puts("[PASS] One-by-one and three-by-three");

  should_preserve_power_addition_law();
  puts("[PASS] Exponent addition property");

  should_reject_multiplication_overflow_without_changing_output();
  puts("[PASS] Multiplication overflow");

  should_reject_power_overflow_without_changing_output();
  puts("[PASS] Power overflow");

  should_support_input_output_aliasing();
  puts("[PASS] Input/output aliasing");

  should_reject_invalid_inputs();
  puts("[PASS] Invalid inputs");

  return 0;
}
