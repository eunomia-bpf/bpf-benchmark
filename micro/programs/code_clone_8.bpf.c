#include "common.h"

#define CODE_CLONE_8_COUNT 128U
#define CODE_CLONE_8_INPUT_SIZE (8U + CODE_CLONE_8_COUNT * 8U)

#define CODE_CLONE_HEAVY_STEP(SALT)                                             \
    do {                                                                        \
        acc += value ^ ((u64)(SALT) + ((u64)i << (i & 7U)));                    \
        acc ^= acc >> (((SALT) >> 1) & 15U);                                    \
        acc = (acc << (((SALT) & 7U) + 1U)) |                                   \
              (acc >> (64U - (((SALT) & 7U) + 1U)));                            \
    } while (0)

static __always_inline int bench_code_clone_8(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);
    if (count != CODE_CLONE_8_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, CODE_CLONE_8_COUNT * 8U)) {
        return -1;
    }

    u64 acc = ((u64)seed << 23) ^ 0x369DEA0F31A53F85ULL;
    for (u32 i = 0; i < CODE_CLONE_8_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8U);
        CODE_CLONE_HEAVY_STEP(3U);
        CODE_CLONE_HEAVY_STEP(11U);
        CODE_CLONE_HEAVY_STEP(19U);
        CODE_CLONE_HEAVY_STEP(27U);
        CODE_CLONE_HEAVY_STEP(35U);
        CODE_CLONE_HEAVY_STEP(43U);
        CODE_CLONE_HEAVY_STEP(51U);
        CODE_CLONE_HEAVY_STEP(59U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    code_clone_8_xdp,
    bench_code_clone_8,
    code_clone_8_input_value,
    CODE_CLONE_8_INPUT_SIZE)
