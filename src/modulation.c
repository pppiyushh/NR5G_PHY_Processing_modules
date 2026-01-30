#include "modulation.h"

/* Q15 constants */
#define Q15_ONE        32767
#define Q15_INV_SQRT2  23170   /* 1/sqrt(2) in Q15 */
#define Q15_INV_SQRT10 10362   /* 1/sqrt(10) in Q15 */

/* Saturation helper */
static inline q15_t sat_q15(int32_t x)
{
    if (x > 32767)  return 32767;
    if (x < -32768) return -32768;
    return (q15_t)x;
}

static void modulate_qpsk(
    const uint8_t *bits,
    size_t num_bits,
    cq15_t *symbols,
    size_t *num_symbols
)
{
    size_t sym_idx = 0;

    for (size_t i = 0; i + 1 < num_bits; i += 2) {
        q15_t i_val = bits[i]   ?  Q15_INV_SQRT2 : -Q15_INV_SQRT2;
        q15_t q_val = bits[i+1] ?  Q15_INV_SQRT2 : -Q15_INV_SQRT2;

        symbols[sym_idx].i = i_val;
        symbols[sym_idx].q = q_val;
        sym_idx++;
    }

    *num_symbols = sym_idx;
}

static void modulate_16qam(
    const uint8_t *bits,
    size_t num_bits,
    cq15_t *symbols,
    size_t *num_symbols
)
{
    size_t sym_idx = 0;

    for (size_t i = 0; i + 3 < num_bits; i += 4) {
        int32_t i_level = (bits[i]   ? 1 : -1) * (bits[i+2] ? 3 : 1);
        int32_t q_level = (bits[i+1] ? 1 : -1) * (bits[i+3] ? 3 : 1);

        symbols[sym_idx].i = sat_q15(i_level * Q15_INV_SQRT10);
        symbols[sym_idx].q = sat_q15(q_level * Q15_INV_SQRT10);
        sym_idx++;
    }

    *num_symbols = sym_idx;
}

void nr_modulate(
    const uint8_t *bits,
    size_t num_bits,
    modulation_t mod,
    cq15_t *symbols,
    size_t *num_symbols
)
{
    switch (mod) {
    case MOD_QPSK:
        modulate_qpsk(bits, num_bits, symbols, num_symbols);
        break;
    case MOD_16QAM:
        modulate_16qam(bits, num_bits, symbols, num_symbols);
        break;
    default:
        *num_symbols = 0;
        break;
    }
}
