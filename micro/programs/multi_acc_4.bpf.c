#include "common.h"

#define MULTI_ACC_4_COUNT 128U
#define MULTI_ACC_4_INPUT_SIZE (8U + MULTI_ACC_4_COUNT * 8U)

struct multi_acc_4_input_value {
    unsigned char data[MULTI_ACC_4_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct multi_acc_4_input_value);
} input_map SEC(".maps");

static __always_inline int bench_multi_acc_4(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);
    if (count != MULTI_ACC_4_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, MULTI_ACC_4_COUNT * 8U)) {
        return -1;
    }

    u64 a0 = (u64)seed ^ 0x0123456789ABCDEFULL;
    u64 a1 = (u64)seed ^ 0x89ABCDEF01234567ULL;
    u64 a2 = (u64)seed ^ 0x0F1E2D3C4B5A6978ULL;
    u64 a3 = (u64)seed ^ 0x13579BDF2468ACE0ULL;

    for (u32 i = 0; i < MULTI_ACC_4_COUNT; i++) {
        u64 value = micro_read_u64_le(data, 8 + i * 8U);
        a0 += value ^ a1;
        a1 ^= (value << 1) + a2;
        a2 += (value >> 3) ^ a3;
        a3 ^= (value << 2) + a0 + i;
        a0 ^= a2 >> 7;
        a1 += a3 << 1;
    }

    *out = a0 ^ a1 ^ a2 ^ a3;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    multi_acc_4_xdp,
    bench_multi_acc_4,
    multi_acc_4_input_value,
    MULTI_ACC_4_INPUT_SIZE)
