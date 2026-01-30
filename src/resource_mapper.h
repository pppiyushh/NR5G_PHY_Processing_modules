#ifndef RESOURCE_MAPPER_H
#define RESOURCE_MAPPER_H

#include <stddef.h>
#include "phy_types.h"

/*
 * Maps modulated symbols sequentially into a time-frequency grid.
 * Grid layout: grid[symbol * num_subcarriers + subcarrier]
 */
void nr_map_symbols_to_grid(
    const cq15_t *symbols,
    size_t num_symbols,
    resource_grid_t *grid
);

#endif /* RESOURCE_MAPPER_H */
