#include "common.h"

#define IMM64_STORM_INPUT_SIZE 32U

struct imm64_storm_input_value {
    unsigned char data[IMM64_STORM_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct imm64_storm_input_value);
} input_map SEC(".maps");

#define IMM64_STORM_STEP(ID)                                                    \
    do {                                                                        \
        const u64 k = 0x9E3779B97F4A7C15ULL +                                   \
                      ((u64)(ID) * 0xD1342543DE82EF95ULL);                      \
        a += k ^ micro_rotl64(d + k, ((ID) & 15U) + 1U);                        \
        b ^= a + (k >> (((ID) & 7U) + 1U));                                     \
        c += b ^ (k << (((ID) >> 3U) & 7U));                                    \
        d ^= c + ((u64)(ID) * 0x100000001B3ULL);                                \
    } while (0)

#define IMM64_STORM_BLOCK_2(BASE)                                               \
    IMM64_STORM_STEP((BASE) + 0U);                                              \
    IMM64_STORM_STEP((BASE) + 1U)

#define IMM64_STORM_BLOCK_4(BASE)                                               \
    IMM64_STORM_BLOCK_2(BASE);                                                  \
    IMM64_STORM_BLOCK_2((BASE) + 2U)

#define IMM64_STORM_BLOCK_8(BASE)                                               \
    IMM64_STORM_BLOCK_4(BASE);                                                  \
    IMM64_STORM_BLOCK_4((BASE) + 4U)

#define IMM64_STORM_BLOCK_16(BASE)                                              \
    IMM64_STORM_BLOCK_8(BASE);                                                  \
    IMM64_STORM_BLOCK_8((BASE) + 8U)

#define IMM64_STORM_BLOCK_32(BASE)                                              \
    IMM64_STORM_BLOCK_16(BASE);                                                 \
    IMM64_STORM_BLOCK_16((BASE) + 16U)

#define IMM64_STORM_BLOCK_64(BASE)                                              \
    IMM64_STORM_BLOCK_32(BASE);                                                 \
    IMM64_STORM_BLOCK_32((BASE) + 32U)

static __always_inline int bench_imm64_storm(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, IMM64_STORM_INPUT_SIZE)) {
        return -1;
    }

    u64 a = micro_read_u64_le(data, 0U);
    u64 b = micro_read_u64_le(data, 8U);
    u64 c = micro_read_u64_le(data, 16U);
    u64 d = micro_read_u64_le(data, 24U);

    IMM64_STORM_BLOCK_64(0U);

    *out = a ^ b ^ c ^ d;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    imm64_storm_xdp,
    bench_imm64_storm,
    imm64_storm_input_value,
    IMM64_STORM_INPUT_SIZE)
