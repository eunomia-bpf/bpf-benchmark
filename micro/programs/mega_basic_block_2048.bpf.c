#include "common.h"

#define MEGA_BASIC_BLOCK_2048_INPUT_SIZE 64U

struct mega_basic_block_2048_input_value {
    unsigned char data[MEGA_BASIC_BLOCK_2048_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct mega_basic_block_2048_input_value);
} input_map SEC(".maps");

#define MEGA_BASIC_BLOCK_STEP(ID)                                               \
    do {                                                                        \
        const u64 k0 = 0x9E3779B97F4A7C15ULL +                                  \
                       ((u64)(ID) * 0x100000001B3ULL);                          \
        const u64 k1 = 0xD1342543DE82EF95ULL ^ ((u64)(ID) << 32U);              \
        a += k0 ^ (b >> (((ID) & 7U) + 1U));                                    \
        c ^= a + micro_rotl64(d ^ k1, ((ID) & 15U) + 1U);                       \
        e += c ^ ((u64)(ID) * 0xA5A5A5A5ULL);                                   \
        g ^= e + (f << (((ID) >> 2U) & 7U));                                    \
        b += g ^ (h >> (((ID) >> 1U) & 7U));                                    \
        d ^= b + k1;                                                            \
        f += d ^ micro_rotl64(a, (((ID) + 3U) & 15U) + 1U);                     \
        h ^= f + k0;                                                            \
    } while (0)

#define MEGA_BASIC_BLOCK_2(BASE)                                                \
    MEGA_BASIC_BLOCK_STEP((BASE) + 0U);                                         \
    MEGA_BASIC_BLOCK_STEP((BASE) + 1U)

#define MEGA_BASIC_BLOCK_4(BASE)                                                \
    MEGA_BASIC_BLOCK_2(BASE);                                                   \
    MEGA_BASIC_BLOCK_2((BASE) + 2U)

#define MEGA_BASIC_BLOCK_8(BASE)                                                \
    MEGA_BASIC_BLOCK_4(BASE);                                                   \
    MEGA_BASIC_BLOCK_4((BASE) + 4U)

#define MEGA_BASIC_BLOCK_16(BASE)                                               \
    MEGA_BASIC_BLOCK_8(BASE);                                                   \
    MEGA_BASIC_BLOCK_8((BASE) + 8U)

#define MEGA_BASIC_BLOCK_32(BASE)                                               \
    MEGA_BASIC_BLOCK_16(BASE);                                                  \
    MEGA_BASIC_BLOCK_16((BASE) + 16U)

#define MEGA_BASIC_BLOCK_64(BASE)                                               \
    MEGA_BASIC_BLOCK_32(BASE);                                                  \
    MEGA_BASIC_BLOCK_32((BASE) + 32U)

#define MEGA_BASIC_BLOCK_128(BASE)                                              \
    MEGA_BASIC_BLOCK_64(BASE);                                                  \
    MEGA_BASIC_BLOCK_64((BASE) + 64U)

#define MEGA_BASIC_BLOCK_256(BASE)                                              \
    MEGA_BASIC_BLOCK_128(BASE);                                                 \
    MEGA_BASIC_BLOCK_128((BASE) + 128U)

static __always_inline int bench_mega_basic_block_2048(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, MEGA_BASIC_BLOCK_2048_INPUT_SIZE)) {
        return -1;
    }

    u64 a = micro_read_u64_le(data, 0U);
    u64 b = micro_read_u64_le(data, 8U);
    u64 c = micro_read_u64_le(data, 16U);
    u64 d = micro_read_u64_le(data, 24U);
    u64 e = micro_read_u64_le(data, 32U);
    u64 f = micro_read_u64_le(data, 40U);
    u64 g = micro_read_u64_le(data, 48U);
    u64 h = micro_read_u64_le(data, 56U);

    MEGA_BASIC_BLOCK_256(0U);

    *out = a ^ b ^ c ^ d ^ e ^ f ^ g ^ h;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    mega_basic_block_2048_xdp,
    bench_mega_basic_block_2048,
    mega_basic_block_2048_input_value,
    MEGA_BASIC_BLOCK_2048_INPUT_SIZE)
