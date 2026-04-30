#include "common.h"

#ifndef BRANCH_FLIP_DENSE_GROUPS
#define BRANCH_FLIP_DENSE_GROUPS 32U
#endif

#ifndef BRANCH_FLIP_DENSE_LANES
#define BRANCH_FLIP_DENSE_LANES 8U
#endif
#define BRANCH_FLIP_DENSE_COUNT \
    (BRANCH_FLIP_DENSE_GROUPS * BRANCH_FLIP_DENSE_LANES)
#define BRANCH_FLIP_DENSE_INPUT_SIZE (BRANCH_FLIP_DENSE_COUNT * 8U)

struct branch_flip_dense_input {
    u64 vals[BRANCH_FLIP_DENSE_COUNT];
};

#define BRANCH_FLIP_DENSE_MASK(INDEX)                                          \
    (1ULL << (((INDEX) * 3U) & 31U))
#define BRANCH_FLIP_DENSE_C1(INDEX)                                            \
    ((u64)(0x013579BDU + ((INDEX) * 0x11U)))
#define BRANCH_FLIP_DENSE_C2(INDEX)                                            \
    ((u64)(0x02468ACEU + ((INDEX) * 0x1BU)))

static __always_inline int
bench_branch_flip_dense(const u8 *data, u32 len, u64 *out)
{
    const struct branch_flip_dense_input *input =
        (const struct branch_flip_dense_input *)data;
    u64 acc = 0x510E527FADE682D1ULL ^ len;

#pragma unroll
    for (u32 group = 0; group < BRANCH_FLIP_DENSE_GROUPS; group++) {
        u32 base = group * BRANCH_FLIP_DENSE_LANES;

#define BRANCH_FLIP_DENSE_STEP(OFFSET)                                         \
        do {                                                                   \
            const u32 index = base + (OFFSET);                                 \
            u64 value = input->vals[index];                                    \
            if ((value & BRANCH_FLIP_DENSE_MASK(index)) != 0) {                \
                acc += value + BRANCH_FLIP_DENSE_C1(index);                    \
                acc ^= value >> 3U;                                            \
            } else {                                                           \
                acc ^= value + BRANCH_FLIP_DENSE_C2(index);                    \
                acc += value << 1U;                                            \
            }                                                                  \
            asm volatile("" : "+r"(acc) : "r"(value) : "memory");            \
        } while (0)

#if BRANCH_FLIP_DENSE_LANES > 0U
        BRANCH_FLIP_DENSE_STEP(0U);
#endif
#if BRANCH_FLIP_DENSE_LANES > 1U
        BRANCH_FLIP_DENSE_STEP(1U);
#endif
#if BRANCH_FLIP_DENSE_LANES > 2U
        BRANCH_FLIP_DENSE_STEP(2U);
#endif
#if BRANCH_FLIP_DENSE_LANES > 3U
        BRANCH_FLIP_DENSE_STEP(3U);
#endif
#if BRANCH_FLIP_DENSE_LANES > 4U
        BRANCH_FLIP_DENSE_STEP(4U);
#endif
#if BRANCH_FLIP_DENSE_LANES > 5U
        BRANCH_FLIP_DENSE_STEP(5U);
#endif
#if BRANCH_FLIP_DENSE_LANES > 6U
        BRANCH_FLIP_DENSE_STEP(6U);
#endif
#if BRANCH_FLIP_DENSE_LANES > 7U
        BRANCH_FLIP_DENSE_STEP(7U);
#endif

#undef BRANCH_FLIP_DENSE_STEP
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    branch_flip_dense_xdp,
    bench_branch_flip_dense,
    branch_flip_dense_input_value,
    BRANCH_FLIP_DENSE_INPUT_SIZE)
