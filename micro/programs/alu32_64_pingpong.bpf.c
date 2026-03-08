#include "common.h"

#define ALU32_64_PINGPONG_COUNT 64U
#define ALU32_64_PINGPONG_INPUT_SIZE (8U + ALU32_64_PINGPONG_COUNT * 8U)

struct alu32_64_pingpong_input_value {
    unsigned char data[ALU32_64_PINGPONG_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct alu32_64_pingpong_input_value);
} input_map SEC(".maps");

static __always_inline int bench_alu32_64_pingpong(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    u32 seed = micro_read_u32_le(data, 4U);
    if (count != ALU32_64_PINGPONG_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, ALU32_64_PINGPONG_COUNT * 8U)) {
        return -1;
    }

    u64 acc = 0xA24BAED4963EE407ULL ^ ((u64)seed << 32U);
    u32 acc32 = seed ^ 0x13579BDFU;

    for (u32 index = 0; index < ALU32_64_PINGPONG_COUNT; index++) {
        u64 value = micro_read_u64_le(data, 8U + index * 8U);
        u32 lo = (u32)value;
        u32 hi = (u32)(value >> 32U);
        u32 folded;

        acc32 += lo ^ (u32)acc;
        acc32 = micro_rotl32(acc32, 7U);
        acc += (u64)acc32 + hi;
        acc ^= (u64)(acc32 ^ hi) << ((index & 3U) * 8U);

        folded = (u32)(acc ^ (acc >> 32U));
        folded += hi + index;
        folded ^= folded >> ((index & 7U) + 1U);

        acc = micro_rotl64(acc + folded + value, (folded & 15U) + 1U);
        acc32 = folded ^ (u32)acc;
    }

    *out = acc ^ acc32;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    alu32_64_pingpong_xdp,
    bench_alu32_64_pingpong,
    alu32_64_pingpong_input_value,
    ALU32_64_PINGPONG_INPUT_SIZE)
