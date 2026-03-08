#include "common.h"

#define LOCAL_CALL_FANOUT_RECORDS 16U
#define LOCAL_CALL_FANOUT_RECORD_SIZE 24U
#define LOCAL_CALL_FANOUT_INPUT_SIZE (8U + LOCAL_CALL_FANOUT_RECORDS * LOCAL_CALL_FANOUT_RECORD_SIZE)

struct local_call_fanout_input_value {
    unsigned char data[LOCAL_CALL_FANOUT_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct local_call_fanout_input_value);
} input_map SEC(".maps");

static __noinline u64 local_call_linear(u64 acc, const u8 *data, u32 offset, u32 tag)
{
    u64 left = micro_read_u64_le(data, offset + 8U);
    u64 right = micro_read_u64_le(data, offset + 16U);
    u64 mixed = acc + left * 3U + right + tag;
    mixed ^= micro_rotl64(mixed + ((u64)tag << 11U), (tag & 7U) + 1U);
    return mixed + (left >> 3U);
}

static __noinline u64 local_call_pressure(u64 acc, const u8 *data, u32 offset, u32 tag)
{
    u64 a = micro_read_u64_le(data, offset + 8U);
    u64 b = micro_read_u64_le(data, offset + 16U);
    u64 c = acc ^ a;
    u64 d = b + ((u64)tag << 17U);
    u64 e = (c << 3U) ^ (b >> 2U);
    u64 f = micro_rotl64(d ^ a, 5U);
    u64 g = micro_rotl64(e + c, 11U);
    u64 h = (f + g) ^ (d >> 7U);
    return (h + e) ^ c ^ d;
}

static __noinline u64 local_call_crossload(u64 acc, const u8 *data, u32 offset, u32 tag)
{
    u32 selector = micro_read_u32_le(data, offset);
    u32 record_tag = micro_read_u32_le(data, offset + 4U);
    u64 left = micro_read_u64_le(data, offset + 8U);
    u64 right = micro_read_u64_le(data, offset + 16U);
    u64 lane0 = acc + left;
    u64 lane1 = micro_rotl64(right ^ lane0, (selector & 7U) + 1U);
    u64 lane2 = lane0 ^ lane1 ^ ((u64)record_tag << 9U);
    u64 lane3 = lane2 + ((u64)tag << (selector & 7U));
    return (lane3 ^ (lane1 >> 5U)) + lane0;
}

static __noinline u64 local_call_bytes(u64 acc, const u8 *data, u32 offset, u32 tag)
{
    u64 mixed = acc ^ 0x94D049BB133111EBULL;
    for (u32 index = 0; index < 8U; index++) {
        mixed ^= (u64)data[offset + index] << ((index & 7U) * 8U);
        mixed = micro_rotl64(mixed + tag + index, index + 1U);
    }
    mixed += micro_read_u64_le(data, offset + 8U);
    mixed ^= micro_read_u64_le(data, offset + 16U);
    return mixed;
}

static __always_inline int bench_local_call_fanout(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0);
    u32 record_size = micro_read_u32_le(data, 4);
    if (record_count != LOCAL_CALL_FANOUT_RECORDS || record_size != LOCAL_CALL_FANOUT_RECORD_SIZE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, LOCAL_CALL_FANOUT_RECORDS * LOCAL_CALL_FANOUT_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0x243F6A8885A308D3ULL;
    for (u32 index = 0; index < LOCAL_CALL_FANOUT_RECORDS; index++) {
        u32 offset = 8U + index * LOCAL_CALL_FANOUT_RECORD_SIZE;
        u32 selector = micro_read_u32_le(data, offset) & 3U;
        u32 tag = micro_read_u32_le(data, offset + 4U) ^ (index << 4U);

        switch (selector) {
        case 0U:
            acc = local_call_linear(acc, data, offset, tag);
            break;
        case 1U:
            acc = local_call_pressure(acc, data, offset, tag);
            break;
        case 2U:
            acc = local_call_crossload(acc, data, offset, tag);
            break;
        default:
            acc = local_call_bytes(acc, data, offset, tag);
            break;
        }

        acc ^= ((u64)selector << ((index & 7U) * 8U)) + tag;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    local_call_fanout_xdp,
    bench_local_call_fanout,
    local_call_fanout_input_value,
    LOCAL_CALL_FANOUT_INPUT_SIZE)
