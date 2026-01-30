#ifndef SCRAMBLING_H
#define SCRAMBLING_H

#include <stddef.h>
#include <stdint.h>

void nr_ul_scramble(uint8_t *bits, size_t len, uint32_t seed);

#endif /* SCRAMBLING_H */
