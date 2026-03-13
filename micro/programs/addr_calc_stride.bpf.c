#include "common.h"

#define ADDR_CALC_STRIDE_GROUPS 32U
#define ADDR_CALC_STRIDE_LANES 8U
#define ADDR_CALC_STRIDE_VALUE_COUNT 256U
#define ADDR_CALC_STRIDE_INPUT_SIZE (ADDR_CALC_STRIDE_VALUE_COUNT * 8U)

struct addr_calc_stride_input {
    u64 values[ADDR_CALC_STRIDE_VALUE_COUNT];
};

#define ADDR_CALC_STRIDE_CONST(INDEX)                                          \
    (0xD1342543DE82EF95ULL +                                                   \
     ((u64)(INDEX) * 0x9E3779B97F4A7C15ULL))

#define ADDR_CALC_STRIDE_STEP(ADVANCE, TAG)                                    \
    do {                                                                       \
        u64 index = cursor;                                                    \
        asm volatile("" : "+r"(index) : : "memory");                         \
        u64 addr = index;                                                      \
        addr <<= 3;                                                            \
        addr += base_addr;                                                     \
        u64 value = *(__u64 *)(const void *)(unsigned long)addr;               \
        acc += value ^ ADDR_CALC_STRIDE_CONST(TAG);                            \
        cursor = (cursor + (ADVANCE)) & (ADDR_CALC_STRIDE_VALUE_COUNT - 1U);   \
        asm volatile(""                                                        \
                     : "+r"(acc), "+r"(cursor)                                 \
                     : "r"(value), "r"(addr)                                   \
                     : "memory");                                              \
    } while (0)

static __always_inline int
bench_addr_calc_stride(const u8 *data, u32 len, u64 *out)
{
    const struct addr_calc_stride_input *input =
        (const struct addr_calc_stride_input *)data;
    const u64 *base = input->values;
    u64 base_addr = (u64)(unsigned long)base;
    u64 cursor = 3U;
    u64 acc = 0x6A09E667F3BCC909ULL ^ len;

#pragma clang loop unroll(disable)
    for (u32 group = 0; group < ADDR_CALC_STRIDE_GROUPS; group++) {
        ADDR_CALC_STRIDE_STEP(5U, group * ADDR_CALC_STRIDE_LANES + 0U);
        ADDR_CALC_STRIDE_STEP(11U, group * ADDR_CALC_STRIDE_LANES + 1U);
        ADDR_CALC_STRIDE_STEP(7U, group * ADDR_CALC_STRIDE_LANES + 2U);
        ADDR_CALC_STRIDE_STEP(13U, group * ADDR_CALC_STRIDE_LANES + 3U);
        ADDR_CALC_STRIDE_STEP(3U, group * ADDR_CALC_STRIDE_LANES + 4U);
        ADDR_CALC_STRIDE_STEP(19U, group * ADDR_CALC_STRIDE_LANES + 5U);
        ADDR_CALC_STRIDE_STEP(23U, group * ADDR_CALC_STRIDE_LANES + 6U);
        ADDR_CALC_STRIDE_STEP(29U, group * ADDR_CALC_STRIDE_LANES + 7U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    addr_calc_stride_xdp,
    bench_addr_calc_stride,
    addr_calc_stride_input_value,
    ADDR_CALC_STRIDE_INPUT_SIZE)
