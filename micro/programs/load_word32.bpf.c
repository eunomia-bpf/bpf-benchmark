#include "common.h"

#define LOAD_WORD32_COUNT 256U
#define LOAD_WORD32_BYTES_PER_ITER 4U
#define LOAD_WORD32_INPUT_SIZE (8U + LOAD_WORD32_COUNT * LOAD_WORD32_BYTES_PER_ITER)

struct load_word32_input_value {
    unsigned char data[LOAD_WORD32_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct load_word32_input_value);
} input_map SEC(".maps");

static __always_inline int bench_load_word32(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 bytes_per_iter = micro_read_u32_le(data, 4);
    if (count != LOAD_WORD32_COUNT || bytes_per_iter != LOAD_WORD32_BYTES_PER_ITER) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, LOAD_WORD32_COUNT * LOAD_WORD32_BYTES_PER_ITER)) {
        return -1;
    }

    /* Volatile preserves the width-specific direct u32 loads we want to time. */
    const volatile u32 *values = (const volatile u32 *)(const void *)(data + 8U);
    u64 acc = 0;
    for (u32 i = 0; i < LOAD_WORD32_COUNT; i++) {
        acc += values[i];
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    load_word32_xdp,
    bench_load_word32,
    load_word32_input_value,
    LOAD_WORD32_INPUT_SIZE)
