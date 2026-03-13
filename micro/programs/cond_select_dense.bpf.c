#include "common.h"

#define COND_SELECT_DENSE_GROUPS 13U
#define COND_SELECT_DENSE_LANES 8U
#define COND_SELECT_DENSE_COUNT \
    (COND_SELECT_DENSE_GROUPS * COND_SELECT_DENSE_LANES)
#define COND_SELECT_DENSE_INPUT_SIZE (COND_SELECT_DENSE_COUNT * 8U * 4U)

struct cond_select_dense_input {
    u64 a[COND_SELECT_DENSE_COUNT];
    u64 b[COND_SELECT_DENSE_COUNT];
    u64 on_true[COND_SELECT_DENSE_COUNT];
    u64 on_false[COND_SELECT_DENSE_COUNT];
};

#define COND_SELECT_DENSE_BIAS(INDEX)                                          \
    (0x9E3779B97F4A7C15ULL +                                                   \
     ((u64)(INDEX) * 0xD1342543DE82EF95ULL))

static __always_inline int
bench_cond_select_dense(const u8 *data, u32 len, u64 *out)
{
    const struct cond_select_dense_input *input =
        (const struct cond_select_dense_input *)data;
    u64 acc = 0x243F6A8885A308D3ULL ^ len;

#pragma unroll
    for (u32 group = 0; group < COND_SELECT_DENSE_GROUPS; group++) {
        u32 base = group * COND_SELECT_DENSE_LANES;

#define COND_SELECT_DENSE_STEP(OFFSET)                                         \
        do {                                                                   \
            const u32 index = base + (OFFSET);                                 \
            u64 lhs = input->a[index];                                         \
            u64 rhs = input->b[index];                                         \
            u64 on_true = input->on_true[index];                               \
            u64 on_false = input->on_false[index];                             \
            u64 selected = on_true;                                            \
            if (lhs <= rhs)                                                    \
                selected = on_false;                                           \
            asm volatile(""                                                    \
                         : "+r"(selected), "+r"(on_true), "+r"(on_false)      \
                         :                                                      \
                         : "memory");                                          \
            acc += selected ^ COND_SELECT_DENSE_BIAS(index);                   \
            asm volatile("" : "+r"(acc) : "r"(selected) : "memory");         \
        } while (0)

        COND_SELECT_DENSE_STEP(0U);
        COND_SELECT_DENSE_STEP(1U);
        COND_SELECT_DENSE_STEP(2U);
        COND_SELECT_DENSE_STEP(3U);
        COND_SELECT_DENSE_STEP(4U);
        COND_SELECT_DENSE_STEP(5U);
        COND_SELECT_DENSE_STEP(6U);
        COND_SELECT_DENSE_STEP(7U);

#undef COND_SELECT_DENSE_STEP
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cond_select_dense_xdp,
    bench_cond_select_dense,
    cond_select_dense_input_value,
    COND_SELECT_DENSE_INPUT_SIZE)
