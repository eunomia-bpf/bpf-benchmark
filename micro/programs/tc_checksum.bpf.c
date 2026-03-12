#include "common.h"

#define TC_CHECKSUM_MAX_ROUNDS 32U
#define TC_CHECKSUM_MAX_WORDS 512U
#define TC_CHECKSUM_INPUT_SIZE (8U + TC_CHECKSUM_MAX_WORDS * 2U)

static __always_inline int bench_checksum(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 word_count = micro_read_u32_le(data, 4);
    u64 acc = 0;

    if (rounds != TC_CHECKSUM_MAX_ROUNDS || word_count != TC_CHECKSUM_MAX_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, TC_CHECKSUM_MAX_WORDS * 2U)) {
        return -1;
    }

    for (u32 round = 0; round < TC_CHECKSUM_MAX_ROUNDS; round++) {
        u32 sum = 0;
        for (u32 i = 0; i < TC_CHECKSUM_MAX_WORDS; i++) {
            sum += micro_read_u16_le(data, 8 + i * 2U);
            sum = (sum & 0xFFFFU) + (sum >> 16);
        }
        sum = (sum & 0xFFFFU) + (sum >> 16);
        /*
         * The same checksum value is folded into four 16-bit lanes. With 32
         * rounds each lane toggles eight times, so the final accumulator is
         * intentionally zero even though the staged input is non-zero.
         */
        acc ^= (u64)(~sum & 0xFFFFU) << ((round & 3U) * 16U);
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_TC_BENCH(
    tc_checksum_prog,
    bench_checksum,
    tc_checksum_input_value,
    TC_CHECKSUM_INPUT_SIZE)
