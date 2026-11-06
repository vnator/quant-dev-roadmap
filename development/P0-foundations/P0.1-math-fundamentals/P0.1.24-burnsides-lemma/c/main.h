#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stddef.h>

bool burnside_orbits(const size_t *group_actions, size_t group_count,
                     size_t set_size, size_t *out);

#endif
