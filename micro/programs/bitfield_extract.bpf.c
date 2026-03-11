#include "common.h"

#define BITFIELD_EXTRACT_RECORDS 32U
#define BITFIELD_EXTRACT_RECORD_WORDS 2U
#define BITFIELD_EXTRACT_HEADER_SIZE 8U
#define BITFIELD_EXTRACT_RECORD_SIZE 16U
#define BITFIELD_EXTRACT_INPUT_SIZE \
    (BITFIELD_EXTRACT_HEADER_SIZE + BITFIELD_EXTRACT_RECORDS * BITFIELD_EXTRACT_RECORD_SIZE)

struct bitfield_extract_input_value {
    unsigned char data[BITFIELD_EXTRACT_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct bitfield_extract_input_value);
} input_map SEC(".maps");

static __always_inline int
bench_bitfield_extract(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BITFIELD_EXTRACT_HEADER_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0);
    u32 record_words = micro_read_u32_le(data, 4);
    if (record_count != BITFIELD_EXTRACT_RECORDS ||
        record_words != BITFIELD_EXTRACT_RECORD_WORDS) {
        return -1;
    }
    if (!micro_has_bytes(len, BITFIELD_EXTRACT_HEADER_SIZE,
                         record_count * BITFIELD_EXTRACT_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    for (u32 index = 0; index < BITFIELD_EXTRACT_RECORDS; index++) {
        u32 base = BITFIELD_EXTRACT_HEADER_SIZE + index * BITFIELD_EXTRACT_RECORD_SIZE;
        u64 word0 = micro_read_u64_le(data, base);
        u64 word1 = micro_read_u64_le(data, base + 8U);
        u32 lane0 = (u32)word0;
        u32 lane1 = (u32)(word1 >> 32U);

        u64 field0 = (word0 >> 0U) & 0x3FULL;
        u64 field1 = (word0 >> 6U) & 0x1FULL;
        u64 field2 = (word0 >> 11U) & 0x7FFULL;
        u64 field3 = (word0 >> 22U) & 0xFFULL;
        u64 field4 = (word0 >> 30U) & 0x3FFFULL;
        u64 field5 = (word0 >> 44U) & 0x3FFULL;
        u64 field6 = (word0 >> 54U) & 0x3FFULL;

        u64 field7 = (word1 >> 0U) & 0xFULL;
        u64 field8 = (word1 >> 4U) & 0xFFULL;
        u64 field9 = (word1 >> 12U) & 0xFFFULL;
        u64 field10 = (word1 >> 24U) & 0xFFFFULL;
        u64 field11 = (word1 >> 40U) & 0xFFFFFFULL;
        u64 field12 = (lane0 >> 9U) & 0x1FULL;
        u64 field13 = (lane1 >> 6U) & 0x7FULL;

        u64 sum0 = field0 + field1 + field2 + field3 + field4 + field5 + field6;
        u64 sum1 = field7 + field8 + field9 + field10 + field11 + field12 +
                   field13 + (u64)index;
        u64 mix0 = (field2 * 3U) ^ (field4 * 5U) ^ (field8 * 7U);
        u64 mix1 = (field6 * 11U) ^ (field10 * 13U) ^ (field11 * 9U) ^
                   (field12 * 17U) ^ (field13 * 19U);

        acc += sum0 ^ micro_rotl64(sum1, (field0 & 7U) + 1U);
        acc ^= mix0 + mix1;
        acc = micro_rotl64(acc + field4 + field11 + field12,
                           ((field6 ^ field11) & 15U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bitfield_extract_xdp,
    bench_bitfield_extract,
    bitfield_extract_input_value,
    BITFIELD_EXTRACT_INPUT_SIZE)
