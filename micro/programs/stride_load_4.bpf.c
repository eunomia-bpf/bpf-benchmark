#include "common.h"

#define STRIDE_LOAD_4_COUNT 128U
#define STRIDE_LOAD_4_INPUT_SIZE (8U + STRIDE_LOAD_4_COUNT * 8U)
#define STRIDE_LOAD_4_STRIDE 4U

static __always_inline int bench_stride_load_4(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 stride = micro_read_u32_le(data, 4);
    if (count != STRIDE_LOAD_4_COUNT || stride != STRIDE_LOAD_4_STRIDE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, STRIDE_LOAD_4_COUNT * 8U)) {
        return -1;
    }

    u32 index = 0;
    u64 acc = 0;
    for (u32 i = 0; i < STRIDE_LOAD_4_COUNT; i++) {
        index = (index + STRIDE_LOAD_4_STRIDE) & (STRIDE_LOAD_4_COUNT - 1U);
        u64 value = micro_read_u64_le(data, 8 + index * 8U);
        acc += value ^ ((u64)i << (i & 7U));
        acc ^= value >> (i & 15U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    stride_load_4_xdp,
    bench_stride_load_4,
    stride_load_4_input_value,
    STRIDE_LOAD_4_INPUT_SIZE)
