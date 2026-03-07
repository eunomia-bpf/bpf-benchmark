#include "common.h"

#define LOAD_BYTE_COUNT 256U
#define LOAD_BYTE_BYTES_PER_ITER 4U
#define LOAD_BYTE_INPUT_SIZE (8U + LOAD_BYTE_COUNT * LOAD_BYTE_BYTES_PER_ITER)

struct load_byte_input_value {
    unsigned char data[LOAD_BYTE_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct load_byte_input_value);
} input_map SEC(".maps");

static __always_inline int bench_load_byte(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 bytes_per_iter = micro_read_u32_le(data, 4);
    if (count != LOAD_BYTE_COUNT || bytes_per_iter != LOAD_BYTE_BYTES_PER_ITER) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, LOAD_BYTE_COUNT * LOAD_BYTE_BYTES_PER_ITER)) {
        return -1;
    }

    /* Volatile keeps clang from coalescing the byte-at-a-time control loads. */
    const volatile u8 *values = (const volatile u8 *)(const void *)(data + 8U);
    u64 acc = 0;
    for (u32 i = 0; i < LOAD_BYTE_COUNT; i++) {
        u32 base = i * LOAD_BYTE_BYTES_PER_ITER;
        u32 lane_sum = (u32)values[base] + (u32)values[base + 1U] +
                       (u32)values[base + 2U] + (u32)values[base + 3U];
        acc += lane_sum;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(load_byte_xdp, bench_load_byte, load_byte_input_value, LOAD_BYTE_INPUT_SIZE)
