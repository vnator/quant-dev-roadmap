#include "main.h"

#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

typedef struct {
  int64_t a;
  int64_t b;
  uint64_t expected;
} TestCase;

static void should_compute_lcm(void) {
  const TestCase cases[] = {
      {0, 0, 0},
      {0, 5, 0},
      {5, 0, 0},
      {1, 1, 1},
      {1, 99, 99},
      {99, 1, 99},
      {4, 6, 12},
      {6, 4, 12},
      {12, 18, 36},
      {18, 12, 36},
      {21, 6, 42},
      {7, 13, 91},
      {-4, 6, 12},
      {4, -6, 12},
      {-4, -6, 12},
      {-7, 3, 21},
      {42, 56, 168},
      {INT64_MAX, 1, (uint64_t)INT64_MAX},
      {INT64_MAX, 2, UINT64_C(18446744073709551614)},
      {INT64_MIN, 1, UINT64_C(9223372036854775808)},
      {INT64_MIN, -1, UINT64_C(9223372036854775808)},
      {INT64_MIN, 2, UINT64_C(9223372036854775808)},
      {INT64_MIN, -2, UINT64_C(9223372036854775808)},
      {INT64_MIN, INT64_MIN / 2, UINT64_C(9223372036854775808)},
      {INT64_MIN, INT64_MIN, UINT64_C(9223372036854775808)},
      {3000000000LL, 6000000000LL, UINT64_C(6000000000)},
  };

  for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
    assert(lcm(cases[i].a, cases[i].b) == cases[i].expected);
  }

  puts("[PASS] LCM values, signs, zero and limits (26 cases)");
}

static void should_reject_overflow(int64_t a, int64_t b) {
  pid_t child = fork();
  assert(child >= 0);

  if (child == 0) {
    (void)freopen("/dev/null", "w", stderr);
    (void)lcm(a, b);
    _exit(0);
  }

  int status = 0;

  assert(waitpid(child, &status, 0) == child);
  assert(WIFSIGNALED(status));
  assert(WTERMSIG(status) == SIGABRT);
}

int main(void) {
  should_compute_lcm();

  should_reject_overflow(INT64_MIN, 3);
  should_reject_overflow(INT64_MAX, 3);
  should_reject_overflow(INT64_MIN, INT64_MAX);

  puts("[PASS] LCM overflow detection (3 cases)");

  return 0;
}
