#include "common.h"

#define LARGE_MIXED_500_COUNT 32U
#define LARGE_MIXED_500_INPUT_SIZE (8U + LARGE_MIXED_500_COUNT * 8U)

struct large_mixed_500_input_value {
    unsigned char data[LARGE_MIXED_500_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct large_mixed_500_input_value);
} input_map SEC(".maps");

#define LARGE_MIXED_STEP(SALT)                                                  \
    do {                                                                        \
        tmp += value ^ ((u64)(SALT) * 0x9E3779B97F4A7C15ULL);                   \
        tmp ^= micro_read_u64_le(                                               \
            data,                                                               \
            8U + ((((i) + (SALT)) & (LARGE_MIXED_500_COUNT - 1U)) * 8U));      \
        if (((tmp >> ((SALT) & 7U)) & 1ULL) != 0) {                            \
            acc += tmp + ((u64)(SALT) << 19U);                                  \
        } else {                                                                \
            acc ^= tmp + ((u64)i << (((SALT) >> 2) & 7U));                      \
        }                                                                       \
        acc ^= acc >> ((((SALT) >> 1) & 15U) + 1U);                             \
        acc = micro_rotl64(acc, ((SALT) & 7U) + 1U);                            \
    } while (0)

#define LARGE_MIXED_BLOCK_2(BASE)                                               \
    LARGE_MIXED_STEP((BASE) + 0U);                                              \
    LARGE_MIXED_STEP((BASE) + 1U)

#define LARGE_MIXED_BLOCK_8(BASE)                                               \
    LARGE_MIXED_STEP((BASE) + 0U);                                              \
    LARGE_MIXED_STEP((BASE) + 1U);                                              \
    LARGE_MIXED_STEP((BASE) + 2U);                                              \
    LARGE_MIXED_STEP((BASE) + 3U);                                              \
    LARGE_MIXED_STEP((BASE) + 4U);                                              \
    LARGE_MIXED_STEP((BASE) + 5U);                                              \
    LARGE_MIXED_STEP((BASE) + 6U);                                              \
    LARGE_MIXED_STEP((BASE) + 7U)

static __always_inline int bench_large_mixed_500(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);
    if (count != LARGE_MIXED_500_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, LARGE_MIXED_500_COUNT * 8U)) {
        return -1;
    }

    u64 acc = ((u64)seed << 29) ^ 0xA0761D6478BD642FULL;
    for (u32 i = 0; i < LARGE_MIXED_500_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8U + i * 8U);
        u64 tmp = value ^ acc ^ ((u64)i << (i & 7U));
        LARGE_MIXED_BLOCK_8(0U);
        acc ^= tmp + value + ((u64)i << 11U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    large_mixed_500_xdp,
    bench_large_mixed_500,
    large_mixed_500_input_value,
    LARGE_MIXED_500_INPUT_SIZE)
