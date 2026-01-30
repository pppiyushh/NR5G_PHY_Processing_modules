#include "resource_mapper.h"

/*
 * Simple sequential resource mapping.
 * No DMRS, no puncturing, no scheduling.
 * Firmware-style deterministic placement.
 */
void nr_map_symbols_to_grid(
    const cq15_t *symbols,
    size_t num_symbols,
    resource_grid_t *grid
)
{
    size_t grid_size = (size_t)grid->num_subcarriers *
                       (size_t)grid->num_symbols;

    size_t max_symbols = (num_symbols < grid_size)
                           ? num_symbols
                           : grid_size;

    for (size_t idx = 0; idx < max_symbols; idx++) {
        grid->grid[idx] = symbols[idx];
    }

    /* Zero remaining REs (explicit, predictable) */
    for (size_t idx = max_symbols; idx < grid_size; idx++) {
        grid->grid[idx].i = 0;
        grid->grid[idx].q = 0;
    }
}
