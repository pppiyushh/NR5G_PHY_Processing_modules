#ifndef PHY_TYPES_H
#define PHY_TYPES_H

#include <stdint.h>
#include <stddef.h>

/* Fixed-point definitions */
typedef int16_t q15_t;
typedef int32_t q31_t;

typedef struct {
    q15_t i;
    q15_t q;
} cq15_t;

/* Supported modulation orders */
typedef enum {
    MOD_QPSK  = 2,
    MOD_16QAM = 4
} modulation_t;

/* Resource grid abstraction (time-frequency) */
typedef struct {
    cq15_t *grid;
    uint16_t num_subcarriers;
    uint16_t num_symbols;
} resource_grid_t;

#endif /* PHY_TYPES_H */
