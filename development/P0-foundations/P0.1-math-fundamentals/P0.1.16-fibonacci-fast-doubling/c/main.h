

#ifndef P0_1_16_FIBONACCI_FAST_DOUBLING_H
#define P0_1_16_FIBONACCI_FAST_DOUBLING_H

#if !defined(__SIZEOF_INT128__)
#error "This exercise requires unsigned __int128 support"
#endif

__extension__ typedef unsigned __int128 u128;

typedef struct {
  u128 current;
  u128 next;
} FibonacciPair;

FibonacciPair fibonacci_fast_doubling(u128 n);

#endif
