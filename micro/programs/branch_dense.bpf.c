#include "common.h"

#define BRANCH_DENSE_COUNT 128U
#define BRANCH_DENSE_INPUT_SIZE (8U + BRANCH_DENSE_COUNT * 4U)

struct branch_dense_input_value {
    unsigned char data[BRANCH_DENSE_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct branch_dense_input_value);
} input_map SEC(".maps");

static __always_inline int bench_branch_dense(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 hot_threshold = micro_read_u32_le(data, 4);
    if (count != BRANCH_DENSE_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, BRANCH_DENSE_COUNT * 4U)) {
        return -1;
    }

    u64 acc = 0xC2B2AE3D27D4EB4FULL ^ hot_threshold;
    for (u32 i = 0; i < BRANCH_DENSE_COUNT; i++) {
        u32 value = micro_read_u32_le(data, 8U + i * 4U);

        if (value < hot_threshold) {
            acc += (u64)value * 3U + i;
        } else {
            acc ^= (u64)value + 0x9E3779B97F4A7C15ULL;
        }
        if ((value & 1U) != 0U) {
            acc ^= micro_rotl64(acc + value, 1U);
        } else {
            acc += value ^ 0x9E37U;
        }
        if ((value & 3U) == 2U) {
            acc += (u64)value << 2U;
        } else {
            acc ^= value >> 1U;
        }
        if ((value % 7U) < 3U) {
            acc ^= 0xD1342543DE82EF95ULL + value;
        } else {
            acc += 0x94D049BB133111EBULL ^ value;
        }
        if (value > 1000U) {
            acc += (u64)value * 11U;
        } else {
            acc ^= (u64)value * 5U;
        }
        if (((value + i) & 8U) != 0U) {
            acc = micro_rotl64(acc, 3U);
        } else {
            acc ^= acc >> 3U;
        }
        if (((value ^ i) & 16U) != 0U) {
            acc += 0xA5A5ULL + i;
        } else {
            acc ^= 0x5A5AULL + value;
        }
        if ((value & 31U) == 0U) {
            acc ^= 0x12345678ULL << (i & 7U);
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    branch_dense_xdp,
    bench_branch_dense,
    branch_dense_input_value,
    BRANCH_DENSE_INPUT_SIZE)
