#include "common.h"

#define TC_BITCOUNT_MAX_COUNT 256U
#define TC_BITCOUNT_INPUT_SIZE (8U + TC_BITCOUNT_MAX_COUNT * 8U)

static __always_inline u64 micro_popcount64(u64 value)
{
    u64 count = 0;
    for (u32 bit = 0; bit < 64U && value != 0; bit++) {
        value &= value - 1;
        count++;
    }
    return count;
}

static __always_inline int bench_bitcount(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);

    if (count != TC_BITCOUNT_MAX_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, TC_BITCOUNT_MAX_COUNT * 8U)) {
        return -1;
    }

    u64 acc = seed;
    for (u32 i = 0; i < TC_BITCOUNT_MAX_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8U);
        acc += micro_popcount64(value ^ acc);
        acc ^= value >> (i & 7U);
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_TC_BENCH(
    tc_bitcount_prog,
    bench_bitcount,
    tc_bitcount_input_value,
    TC_BITCOUNT_INPUT_SIZE)
