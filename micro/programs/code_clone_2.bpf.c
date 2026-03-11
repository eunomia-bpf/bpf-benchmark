#include "common.h"

#define CODE_CLONE_2_COUNT 128U
#define CODE_CLONE_2_INPUT_SIZE (8U + CODE_CLONE_2_COUNT * 8U)

#define CODE_CLONE_STEP(SALT)                                                   \
    do {                                                                        \
        acc += value ^ ((u64)(SALT) + ((u64)i << (i & 7U)));                    \
        acc ^= acc >> (((SALT) >> 1) & 15U);                                    \
        acc = (acc << (((SALT) & 7U) + 1U)) |                                   \
              (acc >> (64U - (((SALT) & 7U) + 1U)));                            \
    } while (0)

static __always_inline int bench_code_clone_2(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);
    if (count != CODE_CLONE_2_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, CODE_CLONE_2_COUNT * 8U)) {
        return -1;
    }

    u64 acc = ((u64)seed << 19) ^ 0x94D049BB133111EBULL;
    for (u32 i = 0; i < CODE_CLONE_2_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8U);
        CODE_CLONE_STEP(3U);
        CODE_CLONE_STEP(11U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    code_clone_2_xdp,
    bench_code_clone_2,
    code_clone_2_input_value,
    CODE_CLONE_2_INPUT_SIZE)
