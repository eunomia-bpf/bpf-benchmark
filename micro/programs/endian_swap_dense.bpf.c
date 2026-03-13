#include "common.h"

#define ENDIAN_SWAP_DENSE_GROUPS 32U
#define ENDIAN_SWAP_DENSE_LANES 8U
#define ENDIAN_SWAP_DENSE_COUNT \
    (ENDIAN_SWAP_DENSE_GROUPS * ENDIAN_SWAP_DENSE_LANES)
#define ENDIAN_SWAP_DENSE_INPUT_SIZE (ENDIAN_SWAP_DENSE_COUNT * 4U)

struct endian_swap_dense_input {
    __u32 vals[ENDIAN_SWAP_DENSE_COUNT];
};

static __always_inline int
bench_endian_swap_dense(const u8 *data, u32 len, u64 *out)
{
    const struct endian_swap_dense_input *input =
        (const struct endian_swap_dense_input *)data;
    u64 acc = 0x3C6EF372FE94F82BULL ^ len;

#pragma unroll
    for (u32 group = 0; group < ENDIAN_SWAP_DENSE_GROUPS; group++) {
        u32 base = group * ENDIAN_SWAP_DENSE_LANES;

#define ENDIAN_SWAP_DENSE_STEP(OFFSET)                                         \
        do {                                                                   \
            const u32 index = base + (OFFSET);                                 \
            __u32 value = __builtin_bswap32(input->vals[index]);               \
            acc += (u64)value + ((u64)index << 16U);                           \
            asm volatile("" : "+r"(acc) : "r"(value) : "memory");            \
        } while (0)

        ENDIAN_SWAP_DENSE_STEP(0U);
        ENDIAN_SWAP_DENSE_STEP(1U);
        ENDIAN_SWAP_DENSE_STEP(2U);
        ENDIAN_SWAP_DENSE_STEP(3U);
        ENDIAN_SWAP_DENSE_STEP(4U);
        ENDIAN_SWAP_DENSE_STEP(5U);
        ENDIAN_SWAP_DENSE_STEP(6U);
        ENDIAN_SWAP_DENSE_STEP(7U);

#undef ENDIAN_SWAP_DENSE_STEP
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    endian_swap_dense_xdp,
    bench_endian_swap_dense,
    endian_swap_dense_input_value,
    ENDIAN_SWAP_DENSE_INPUT_SIZE)
