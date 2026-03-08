#include "common.h"

#define MEMCMP_PREFIX_SCENARIOS 3U
#define MEMCMP_PREFIX_LEN 64U
#define MEMCMP_PREFIX_INPUT_SIZE (4U + MEMCMP_PREFIX_SCENARIOS * MEMCMP_PREFIX_LEN)

struct memcmp_prefix_64_input_value {
    unsigned char data[MEMCMP_PREFIX_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct memcmp_prefix_64_input_value);
} input_map SEC(".maps");

static __always_inline u8 memcmp_prefix_pattern_byte(u32 index)
{
    return (u8)((((index * 29U) ^ (index << 2U) ^ 0xA5U) + 0x11U) & 0xFFU);
}

static __always_inline int bench_memcmp_prefix_64(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, MEMCMP_PREFIX_INPUT_SIZE)) {
        return -1;
    }

    u32 scenario_count = micro_read_u32_le(data, 0);
    if (scenario_count != MEMCMP_PREFIX_SCENARIOS) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    for (u32 scenario = 0; scenario < MEMCMP_PREFIX_SCENARIOS; scenario++) {
        u32 base = 4U + scenario * MEMCMP_PREFIX_LEN;
        u32 mismatch = MEMCMP_PREFIX_LEN;
        u8 observed = 0;
        u8 expected = 0;

        for (u32 index = 0; index < MEMCMP_PREFIX_LEN; index++) {
            observed = data[base + index];
            expected = memcmp_prefix_pattern_byte(index);
            if (observed != expected) {
                mismatch = index;
                break;
            }
        }

        if (mismatch == MEMCMP_PREFIX_LEN) {
            acc ^= 0x9E3779B97F4A7C15ULL + scenario;
            acc += (u64)data[base + MEMCMP_PREFIX_LEN - 1U] << (scenario * 8U);
        } else {
            acc += (u64)(mismatch + 1U) * (u64)(scenario + 5U);
            acc ^= (u64)observed << ((scenario & 7U) * 8U);
            acc += expected;
        }

        acc = micro_rotl64(acc, 5U + scenario);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    memcmp_prefix_64_xdp,
    bench_memcmp_prefix_64,
    memcmp_prefix_64_input_value,
    MEMCMP_PREFIX_INPUT_SIZE)
