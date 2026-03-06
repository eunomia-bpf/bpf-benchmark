#include "common.h"

#define STRIDE_LOAD_16_COUNT 128U
#define STRIDE_LOAD_16_INPUT_SIZE (8U + STRIDE_LOAD_16_COUNT * 8U)
#define STRIDE_LOAD_16_STRIDE 16U

struct stride_load_16_input_value {
    unsigned char data[STRIDE_LOAD_16_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct stride_load_16_input_value);
} input_map SEC(".maps");

static __always_inline int bench_stride_load_16(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 stride = micro_read_u32_le(data, 4);
    if (count != STRIDE_LOAD_16_COUNT || stride != STRIDE_LOAD_16_STRIDE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, STRIDE_LOAD_16_COUNT * 8U)) {
        return -1;
    }

    u32 index = 0;
    u64 acc = 0;
    for (u32 i = 0; i < STRIDE_LOAD_16_COUNT; i++) {
        index = (index + STRIDE_LOAD_16_STRIDE) & (STRIDE_LOAD_16_COUNT - 1U);
        u64 value = micro_read_u64_le(data, 8 + index * 8U);
        acc += value ^ ((u64)i << (i & 9U));
        acc ^= value >> (i & 11U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    stride_load_16_xdp,
    bench_stride_load_16,
    stride_load_16_input_value,
    STRIDE_LOAD_16_INPUT_SIZE)
