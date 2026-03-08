#include "common.h"

#define CONST_FOLD_CHAIN_COUNT 128U
#define CONST_FOLD_CHAIN_INPUT_SIZE (8U + CONST_FOLD_CHAIN_COUNT * 4U)

struct const_fold_chain_input_value {
    unsigned char data[CONST_FOLD_CHAIN_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct const_fold_chain_input_value);
} input_map SEC(".maps");

static __always_inline int
bench_const_fold_chain(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    u32 seed = micro_read_u32_le(data, 4U);
    if (count != CONST_FOLD_CHAIN_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, CONST_FOLD_CHAIN_COUNT * 4U)) {
        return -1;
    }

    u64 acc = ((u64)seed << 32U) ^ 0xA24BAED4963EE407ULL;
    for (u32 index = 0; index < CONST_FOLD_CHAIN_COUNT; index++) {
        u32 value = micro_read_u32_le(data, 8U + index * 4U);
        u32 lane = value + 0x13579BDFU;
        u64 wide = (u64)lane;

        wide += 0x10203040ULL;
        lane = (u32)wide;
        lane ^= 0x00FF00FFU;
        wide = (u64)lane;
        wide += 0x01010101ULL;
        lane = (u32)wide;
        lane += (seed ^ (index * 17U)) & 0xFFU;
        lane ^= 0x0F0F0F0FU;
        wide = (u64)lane;
        wide += 0x11223344ULL;
        wide ^= ((u64)(seed + index) << ((index & 3U) * 8U));

        acc += wide;
        acc ^= wide >> ((index & 7U) + 1U);
        acc += (u64)(u32)wide;
        acc = micro_rotl64(acc, (index & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    const_fold_chain_xdp,
    bench_const_fold_chain,
    const_fold_chain_input_value,
    CONST_FOLD_CHAIN_INPUT_SIZE)
