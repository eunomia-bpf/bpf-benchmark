#include "common.h"

/*
 * rotate64_hash: SipHash-like hash using 64-bit rotations.
 *
 * Uses micro_rotl64() exclusively in the hot path so clang emits
 * the clean 4-insn rotate pattern (mov+lsh+rsh+or) without masking.
 * This exercises the ROTATE rewrite's 4-insn variant.
 *
 * Input: 8 u64 words (64 bytes) from the packet payload.
 * Output: 64-bit hash result.
 */

/*
 * SipHash-like round: 4 adds, 4 rotates, 2 xors per round.
 * Uses 64-bit rotations with varying amounts to create multiple
 * distinct rotate sites.
 */
#define SIPROUND(v0, v1, v2, v3)                \
    do {                                        \
        (v0) += (v1);                           \
        (v1) = micro_rotl64((v1), 13U);         \
        (v1) ^= (v0);                           \
        (v0) = micro_rotl64((v0), 32U);         \
        (v2) += (v3);                           \
        (v3) = micro_rotl64((v3), 16U);         \
        (v3) ^= (v2);                           \
        (v0) += (v3);                           \
        (v3) = micro_rotl64((v3), 21U);         \
        (v3) ^= (v0);                           \
        (v2) += (v1);                           \
        (v1) = micro_rotl64((v1), 17U);         \
        (v1) ^= (v2);                           \
        (v2) = micro_rotl64((v2), 32U);         \
    } while (0)

static __always_inline int
bench_rotate64_hash(const u8 *data, u32 len, u64 *out)
{
    u64 v0 = 0x736F6D6570736575ULL;
    u64 v1 = 0x646F72616E646F6DULL;
    u64 v2 = 0x6C7967656E657261ULL;
    u64 v3 = 0x7465646279746573ULL;

    /* Read 8 input words */
    u64 m0 = micro_read_u64_le(data, 0);
    u64 m1 = micro_read_u64_le(data, 8);
    u64 m2 = micro_read_u64_le(data, 16);
    u64 m3 = micro_read_u64_le(data, 24);
    u64 m4 = micro_read_u64_le(data, 32);
    u64 m5 = micro_read_u64_le(data, 40);
    u64 m6 = micro_read_u64_le(data, 48);
    u64 m7 = micro_read_u64_le(data, 56);

    /* Process each word: xor into v3, do 2 rounds, xor into v0 */
    v3 ^= m0;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m0;

    v3 ^= m1;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m1;

    v3 ^= m2;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m2;

    v3 ^= m3;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m3;

    v3 ^= m4;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m4;

    v3 ^= m5;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m5;

    v3 ^= m6;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m6;

    v3 ^= m7;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    v0 ^= m7;

    /* Finalization: 4 rounds */
    v2 ^= 0xFF;
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);
    SIPROUND(v0, v1, v2, v3);

    *out = v0 ^ v1 ^ v2 ^ v3;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(rotate64_hash_xdp, bench_rotate64_hash,
                              rotate64_hash_input, 64)
