#include "scrambling.h"

static uint32_t lfsr_step(uint32_t state)
{
    /* x^31 + x^28 + 1 (simplified) */
    uint32_t new_bit = ((state >> 0) ^ (state >> 3)) & 0x1;
    return (state >> 1) | (new_bit << 30);
}

void nr_ul_scramble(uint8_t *bits, size_t len, uint32_t seed)
{
    uint32_t lfsr = seed;

    for (size_t i = 0; i < len; i++) {
        bits[i] ^= (lfsr & 0x1);
        lfsr = lfsr_step(lfsr);
    }
}
