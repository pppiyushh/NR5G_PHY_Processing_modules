#include <stdio.h>
#include <stdlib.h>
#include "phy_types.h"
#include "scrambling.h"
#include "modulation.h"
#include "resource_mapper.h"

#define NUM_BITS  128
#define NUM_SC    12
#define NUM_SYM   14

int main(void)
{
    uint8_t bits[NUM_BITS];
    cq15_t symbols[NUM_BITS / 2];
    size_t num_symbols;

    cq15_t grid_buf[NUM_SC * NUM_SYM];
    resource_grid_t grid = {
        .grid = grid_buf,
        .num_subcarriers = NUM_SC,
        .num_symbols = NUM_SYM
    };

    /* Dummy input */
    for (size_t i = 0; i < NUM_BITS; i++)
        bits[i] = i & 1;

    nr_ul_scramble(bits, NUM_BITS, 0xACE1u);
    nr_modulate(bits, NUM_BITS, MOD_QPSK, symbols, &num_symbols);
    nr_map_symbols_to_grid(symbols, num_symbols, &grid);

    printf("Mapped %zu symbols into grid\n", num_symbols);
    return 0;
}
