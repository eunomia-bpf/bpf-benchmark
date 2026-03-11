#include "common.h"

#define SPILL_PRESSURE_COUNT 64U
#define SPILL_PRESSURE_INPUT_SIZE (8U + SPILL_PRESSURE_COUNT * 8U)

static __always_inline int bench_spill_pressure(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);

    if (count != SPILL_PRESSURE_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, SPILL_PRESSURE_COUNT * 8U)) {
        return -1;
    }

    u64 a0 = (u64)seed ^ 0x0123456789ABCDEFULL;
    u64 a1 = (u64)seed ^ 0x89ABCDEF01234567ULL;
    u64 a2 = (u64)seed ^ 0x0F1E2D3C4B5A6978ULL;
    u64 a3 = (u64)seed ^ 0x13579BDF2468ACE0ULL;
    u64 a4 = (u64)seed ^ 0x55AA55AA55AA55AAULL;
    u64 a5 = (u64)seed ^ 0x1122334455667788ULL;
    u64 a6 = (u64)seed ^ 0x8877665544332211ULL;
    u64 a7 = (u64)seed ^ 0xA5A5A5A5A5A5A5A5ULL;

    for (u32 i = 0; i < SPILL_PRESSURE_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8U);

        a0 += value ^ a7;
        a1 ^= (value << 1) + a0;
        a2 += (value >> 3) ^ a1;
        a3 ^= (value << 2) + a2;
        a4 += (value >> 5) ^ a3;
        a5 ^= (value << 3) + a4;
        a6 += (value >> 7) ^ a5;
        a7 ^= (value << 4) + a6 + i;
        a0 ^= a4 >> 11;
        a3 += a1 << 2;
        a6 ^= a2 >> 9;
    }

    *out = a0 ^ a1 ^ a2 ^ a3 ^ a4 ^ a5 ^ a6 ^ a7;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    spill_pressure_xdp,
    bench_spill_pressure,
    spill_pressure_input_value,
    SPILL_PRESSURE_INPUT_SIZE)
