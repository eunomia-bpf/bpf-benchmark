#include "common.h"

/* Causal isolation: byte-load-recompose path.
 * Reads 128 u64 values via micro_read_u64_le (byte-by-byte reconstruction).
 * Kernel JIT translates each byte load to movzbq + shl + or (byte-recompose).
 * Paired with load_native_u64 which uses aligned struct access. */

#define LBR_COUNT 128U
#define LBR_INPUT_SIZE (8U + LBR_COUNT * 8U)

static __always_inline int bench_load_byte_recompose(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8))
        return -1;

    u32 count = micro_read_u32_le(data, 0);
    if (count != LBR_COUNT)
        return -1;
    if (!micro_has_bytes(len, 8, LBR_COUNT * 8U))
        return -1;

    u64 acc = 0;
    for (u32 i = 0; i < LBR_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8U);
        acc += value;
        acc ^= value >> (i & 15U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    load_byte_recompose_xdp,
    bench_load_byte_recompose,
    load_byte_recompose_input_value,
    LBR_INPUT_SIZE)
