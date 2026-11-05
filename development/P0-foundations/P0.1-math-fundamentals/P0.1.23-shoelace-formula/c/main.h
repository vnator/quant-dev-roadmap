
#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
  const double *x;
  const double *y;
  size_t len;
} Vector;

bool shoelace(const Vector *vector, double *out);

#endif
