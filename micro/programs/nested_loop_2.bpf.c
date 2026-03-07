#include "common.h"

#define NESTED_LOOP_2_OUTER 16U
#define NESTED_LOOP_2_INNER 16U
#define NESTED_LOOP_2_VALUES (NESTED_LOOP_2_OUTER * NESTED_LOOP_2_INNER)
#define NESTED_LOOP_2_INPUT_SIZE (16U + NESTED_LOOP_2_VALUES * 8U)

struct nested_loop_2_input_value {
    unsigned char data[NESTED_LOOP_2_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct nested_loop_2_input_value);
} input_map SEC(".maps");

static __always_inline int bench_nested_loop_2(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 16U)) {
        return -1;
    }

    u32 outer = micro_read_u32_le(data, 0);
    u32 inner = micro_read_u32_le(data, 4);
    u64 seed = micro_read_u64_le(data, 8);

    if (outer != NESTED_LOOP_2_OUTER || inner != NESTED_LOOP_2_INNER) {
        return -1;
    }
    if (!micro_has_bytes(len, 16U, NESTED_LOOP_2_VALUES * 8U)) {
        return -1;
    }

    u64 acc = seed ^ 0xD1B54A32D192ED03ULL;
    for (u32 i = 0; i < NESTED_LOOP_2_OUTER; i++) {
        for (u32 j = 0; j < NESTED_LOOP_2_INNER; j++) {
            u32 index = i * NESTED_LOOP_2_INNER + j;
            u64 value = micro_read_u64_le(data, 16U + index * 8U);
            acc += value ^ (((u64)i << 32) | (u64)j);
            acc ^= micro_rotl64(value + acc, ((i + j) & 7U) + 1U);
            acc = micro_rotl64(acc, ((i ^ j) & 7U) + 1U);
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    nested_loop_2_xdp,
    bench_nested_loop_2,
    nested_loop_2_input_value,
    NESTED_LOOP_2_INPUT_SIZE)
