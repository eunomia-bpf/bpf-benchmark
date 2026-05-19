#include "common.h"

#define HASH_CHAIN_ROUNDS 16U
#define HASH_CHAIN_WORDS 8U
#define HASH_CHAIN_INPUT_SIZE (8U + HASH_CHAIN_WORDS * 8U)

static __always_inline int bench_hash_chain(const u8 *data, u32 len, u64 *out)
{
#ifdef MICRO_NATIVE
    if (!micro_native_has_data_bytes(data, len, 0, 8)) {
#else
    if (!micro_has_bytes(len, 0, 8)) {
#endif
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 word_count = micro_read_u32_le(data, 4);

    if (rounds != HASH_CHAIN_ROUNDS || word_count != HASH_CHAIN_WORDS) {
        return -1;
    }
#ifdef MICRO_NATIVE
    if (!micro_native_has_data_bytes(data, len, 8, HASH_CHAIN_WORDS * 8U)) {
#else
    if (!micro_has_bytes(len, 8, HASH_CHAIN_WORDS * 8U)) {
#endif
        return -1;
    }

    u64 acc = 0xCBF29CE484222325ULL;
    for (u32 round = 0; round < HASH_CHAIN_ROUNDS; round++) {
        for (u32 i = 0; i < HASH_CHAIN_WORDS; i++) {
            u64 word = micro_read_u64_le(data, 8 + i * 8U);
            u64 salt = ((u64)(round + 1U) * 0x9E3779B97F4A7C15ULL) ^
                       ((u64)(i + 1U) * 0xD1342543DE82EF95ULL);

            acc ^= word + salt;
            acc = micro_rotl64(acc, (round * 5U + i * 11U + 7U) & 63U);
            acc *= 0x100000001B3ULL;
            acc ^= acc >> 29U;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_CGROUP_SKB_BENCH(
    cgroup_skb_hash_chain_prog,
    bench_hash_chain,
    cgroup_skb_hash_chain_input_value,
    HASH_CHAIN_INPUT_SIZE)
