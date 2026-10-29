#include "main.h"

#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

static u128 parse_u128(const char *digits) {
  u128 value = 0;
  const u128 max = (u128)-1;

  for (const char *p = digits; *p != '\0'; ++p) {
    assert(*p >= '0' && *p <= '9');

    const u128 digit = (u128)(*p - '0');

    assert(value <= (max - digit) / 10);

    value = value * 10 + digit;
  }

  return value;
}

static void should_match_known_values(void) {
  const struct {
    u128 n;
    const char *current;
    const char *next;
  } cases[] = {
      {0, "0", "1"},
      {1, "1", "1"},
      {2, "1", "2"},
      {3, "2", "3"},
      {5, "5", "8"},
      {10, "55", "89"},
      {20, "6765", "10946"},
      {50, "12586269025", "20365011074"},
      {92, "7540113804746346429", "12200160415121876738"},
      {93, "12200160415121876738", "19740274219868223167"},
      {100, "354224848179261915075", "573147844013817084101"},
      {184, "127127879743834334146972278486287885163",
       "205697230343233228174223751303346572685"},
      {185, "205697230343233228174223751303346572685",
       "332825110087067562321196029789634457848"},
  };

  const size_t count = sizeof(cases) / sizeof(cases[0]);

  for (size_t i = 0; i < count; ++i) {
    FibonacciPair result = fibonacci_fast_doubling(cases[i].n);

    assert(result.current == parse_u128(cases[i].current));

    assert(result.next == parse_u128(cases[i].next));
  }
}

static FibonacciPair fibonacci_iterative(u128 n) {
  u128 a = 0;
  u128 b = 1;

  for (u128 i = 0; i < n; ++i) {
    const u128 next = a + b;

    a = b;
    b = next;
  }

  return (FibonacciPair){a, b};
}

static void should_match_iterative_reference(void) {
  for (u128 n = 0; n <= 185; ++n) {
    const FibonacciPair actual = fibonacci_fast_doubling(n);

    const FibonacciPair expected = fibonacci_iterative(n);

    assert(actual.current == expected.current);
    assert(actual.next == expected.next);
  }
}

static void should_preserve_recurrence(void) {
  for (u128 n = 0; n < 185; ++n) {
    const FibonacciPair current = fibonacci_fast_doubling(n);

    const FibonacciPair following = fibonacci_fast_doubling(n + 1);

    assert(current.next == following.current);

    assert(current.current + current.next == following.next);
  }
}

static void should_reject_unrepresentable_result(void) {
  const pid_t child = fork();

  assert(child >= 0);

  if (child == 0) {
    (void)freopen("/dev/null", "w", stderr);

    (void)fibonacci_fast_doubling(186);

    _exit(0);
  }

  int status = 0;

  assert(waitpid(child, &status, 0) == child);
  assert(WIFSIGNALED(status));
  assert(WTERMSIG(status) == SIGABRT);
}

int main(void) {
  should_match_known_values();
  should_match_iterative_reference();
  should_preserve_recurrence();
  should_reject_unrepresentable_result();

  puts("[PASS] P0.1.16 Fibonacci Fast Doubling");

  return 0;
}
