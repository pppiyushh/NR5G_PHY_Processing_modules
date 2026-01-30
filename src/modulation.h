#ifndef MODULATION_H
#define MODULATION_H

#include <stddef.h>
#include <stdint.h>
#include "phy_types.h"

/* Modulate input bits into complex Q15 symbols */
void nr_modulate(
    const uint8_t *bits,
    size_t num_bits,
    modulation_t mod,
    cq15_t *symbols,
    size_t *num_symbols
);

#endif /* MODULATION_H */
