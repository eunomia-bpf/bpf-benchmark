#include "common.h"

#define BRANCH_LAYOUT_MAX_COUNT 512U
#define BRANCH_LAYOUT_INPUT_SIZE (8U + BRANCH_LAYOUT_MAX_COUNT * 8U)

struct branch_layout_input_value {
    unsigned char data[BRANCH_LAYOUT_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct branch_layout_input_value);
} input_map SEC(".maps");

static __always_inline int bench_branch_layout(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 hot_threshold = micro_read_u32_le(data, 4);
    u64 result = 0;

    if (count != BRANCH_LAYOUT_MAX_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, BRANCH_LAYOUT_MAX_COUNT * 8U)) {
        return -1;
    }

    for (u32 i = 0; i < BRANCH_LAYOUT_MAX_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8);
        if (value < hot_threshold) {
            result += value;
        } else {
            result += value * value;
            result ^= value >> 3;
        }
    }

    *out = result;
    return 0;
}

DEFINE_MAP_BACKED_XDP_BENCH(
    branch_layout_xdp,
    bench_branch_layout,
    branch_layout_input_value,
    BRANCH_LAYOUT_INPUT_SIZE)
