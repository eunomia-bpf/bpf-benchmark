#include "common.h"

#define EXTRACT_DENSE_GROUPS 32U
#define EXTRACT_DENSE_LANES 8U
#define EXTRACT_DENSE_COUNT (EXTRACT_DENSE_GROUPS * EXTRACT_DENSE_LANES)
#define EXTRACT_DENSE_INPUT_SIZE (EXTRACT_DENSE_COUNT * 8U)

struct extract_dense_input {
    u64 vals[EXTRACT_DENSE_COUNT];
};

static __always_inline int bench_extract_dense(const u8 *data, u32 len, u64 *out)
{
    const struct extract_dense_input *input =
        (const struct extract_dense_input *)data;
    u64 acc = 0xBB67AE8584CAA73BULL ^ len;

#pragma unroll
    for (u32 group = 0; group < EXTRACT_DENSE_GROUPS; group++) {
        u32 base = group * EXTRACT_DENSE_LANES;

#define EXTRACT_DENSE_STEP(OFFSET)                                             \
        do {                                                                   \
            const u32 index = base + (OFFSET);                                 \
            u64 word = input->vals[index];                                     \
            u64 f0 = (word >> 5U) & 0x1FULL;                                   \
            u64 f1 = (word >> 17U) & 0x3FFULL;                                 \
            acc += f0 + f1 + index;                                            \
            asm volatile("" : "+r"(acc) : "r"(word), "r"(f0), "r"(f1)        \
                         : "memory");                                          \
        } while (0)

        EXTRACT_DENSE_STEP(0U);
        EXTRACT_DENSE_STEP(1U);
        EXTRACT_DENSE_STEP(2U);
        EXTRACT_DENSE_STEP(3U);
        EXTRACT_DENSE_STEP(4U);
        EXTRACT_DENSE_STEP(5U);
        EXTRACT_DENSE_STEP(6U);
        EXTRACT_DENSE_STEP(7U);

#undef EXTRACT_DENSE_STEP
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    extract_dense_xdp,
    bench_extract_dense,
    extract_dense_input_value,
    EXTRACT_DENSE_INPUT_SIZE)
