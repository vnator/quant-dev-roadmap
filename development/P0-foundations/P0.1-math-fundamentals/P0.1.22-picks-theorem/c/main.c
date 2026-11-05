#include "main.h"

double picks_area(uint64_t int_points, uint64_t border_points) {
  // Converte os pontos interiores para double.
  const double interior = (double)int_points;

  // Converte os pontos da fronteira para double
  // antes da divisão, evitando divisão inteira.
  const double border = (double)border_points / 2.0;

  // Aplica o Teorema de Pick:
  // A = I + B/2 - 1
  return interior + border - 1.0;
}
