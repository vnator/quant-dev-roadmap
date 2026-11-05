#include "main.h"

#include <math.h>

bool shoelace(const Vector *vector, double *out) {
  // Validate pointers.
  if (vector == NULL || out == NULL) {
    return false;
  }

  if (vector->x == NULL || vector->y == NULL) {
    return false;
  }

  // A polygon needs at least three vertices.
  if (vector->len < 3) {
    return false;
  }

  double sum = 0.0;

  // Iterate through every vertex.
  for (size_t i = 0; i < vector->len; ++i) {
    // Select the next vertex.
    // Connect the last vertex back to the first.
    const size_t j = (i + 1) % vector->len;

    // Calculate the cross-product contribution.
    sum += (vector->x[i] * vector->y[j]) - (vector->x[j] * vector->y[i]);
  }

  // Reject non-finite results.
  if (!isfinite(sum)) {
    return false;
  }

  // Calculate the absolute area.
  *out = fabs(sum) / 2.0;

  return true;
}
