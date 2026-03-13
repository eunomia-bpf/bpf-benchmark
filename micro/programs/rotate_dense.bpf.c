#include "common.h"

#define ROTATE_DENSE_GROUPS 8U
#define ROTATE_DENSE_INPUT_SIZE (8U * 8U)

struct rotate_dense_input {
    u64 seeds[8];
};

#define ROTATE_DENSE_CONST(INDEX)                                              \
    (0x9E3779B97F4A7C15ULL +                                                   \
     ((u64)(INDEX) * 0xA0761D6478BD642FULL))

#define ROTATE_DENSE_ROUND(TAG, R0, R1, R2, R3)                                \
    do {                                                                       \
        a += micro_rotl64((b ^ c) + ROTATE_DENSE_CONST((TAG) + 0U), (R0));     \
        b ^= micro_rotl64((c + d) ^ ROTATE_DENSE_CONST((TAG) + 1U), (R1));     \
        c += micro_rotl64((d ^ a) + ROTATE_DENSE_CONST((TAG) + 2U), (R2));     \
        d ^= micro_rotl64((a + b) ^ ROTATE_DENSE_CONST((TAG) + 3U), (R3));     \
        asm volatile(""                                                        \
                     : "+r"(a), "+r"(b), "+r"(c), "+r"(d)                     \
                     :                                                          \
                     : "memory");                                              \
    } while (0)

static __always_inline int bench_rotate_dense(const u8 *data, u32 len, u64 *out)
{
    const struct rotate_dense_input *input =
        (const struct rotate_dense_input *)data;
    u64 a = input->seeds[0] ^ 0x736F6D6570736575ULL;
    u64 b = input->seeds[1] ^ 0x646F72616E646F6DULL;
    u64 c = input->seeds[2] ^ 0x6C7967656E657261ULL;
    u64 d = input->seeds[3] ^ 0x7465646279746573ULL;
    u64 e = input->seeds[4] ^ 0xA4093822299F31D0ULL;
    u64 f = input->seeds[5] ^ 0x082EFA98EC4E6C89ULL;
    u64 g = input->seeds[6] ^ 0x452821E638D01377ULL;
    u64 h = input->seeds[7] ^ 0xBE5466CF34E90C6CULL;

#pragma unroll
    for (u32 group = 0; group < ROTATE_DENSE_GROUPS; group++) {
        ROTATE_DENSE_ROUND(group * 32U + 0U, 13U, 17U, 29U, 43U);
        ROTATE_DENSE_ROUND(group * 32U + 4U, 11U, 19U, 31U, 47U);
        ROTATE_DENSE_ROUND(group * 32U + 8U, 7U, 23U, 37U, 53U);
        ROTATE_DENSE_ROUND(group * 32U + 12U, 5U, 27U, 41U, 59U);
        ROTATE_DENSE_ROUND(group * 32U + 16U, 3U, 13U, 29U, 61U);
        ROTATE_DENSE_ROUND(group * 32U + 20U, 17U, 31U, 43U, 11U);
        ROTATE_DENSE_ROUND(group * 32U + 24U, 19U, 37U, 47U, 7U);
        ROTATE_DENSE_ROUND(group * 32U + 28U, 23U, 41U, 53U, 5U);

        a += e ^ ROTATE_DENSE_CONST(group + 0U);
        b ^= f + ROTATE_DENSE_CONST(group + 1U);
        c += g ^ ROTATE_DENSE_CONST(group + 2U);
        d ^= h + ROTATE_DENSE_CONST(group + 3U);
        asm volatile("" : "+r"(a), "+r"(b), "+r"(c), "+r"(d) : : "memory");
    }

    *out = a ^ b ^ c ^ d ^ e ^ f ^ g ^ h ^ len;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    rotate_dense_xdp,
    bench_rotate_dense,
    rotate_dense_input_value,
    ROTATE_DENSE_INPUT_SIZE)
