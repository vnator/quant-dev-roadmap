
#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
  const int64_t *items;
  size_t len;
} IntSet;

/*
 * Calcula a cardinalidade da união dos conjuntos.
 *
 * Cada conjunto deve conter elementos distintos.
 *
 * Retorna false se:
 * - Os argumentos forem inválidos.
 * - A quantidade de conjuntos exceder a capacidade da máscara.
 * - Ocorrer overflow aritmético.
 *
 * O resultado é escrito em out somente em caso de sucesso.
 */
bool inclusion_exclusion(const IntSet *sets, size_t set_count, size_t *out);

#endif
