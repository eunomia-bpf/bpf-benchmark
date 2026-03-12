#include "common.h"

#define PACKET_PARSE_MAX_COUNT 54U
#define PACKET_PARSE_MAX_SIZE 64U
#define PACKET_PARSE_INPUT_SIZE (8U + PACKET_PARSE_MAX_COUNT * PACKET_PARSE_MAX_SIZE)

static __always_inline int bench_packet_parse(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 packet_count = micro_read_u32_le(data, 0);
    u32 packet_size = micro_read_u32_le(data, 4);
    u64 acc = 0;

    if (packet_count != PACKET_PARSE_MAX_COUNT || packet_size != PACKET_PARSE_MAX_SIZE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, PACKET_PARSE_MAX_COUNT * PACKET_PARSE_MAX_SIZE)) {
        return -1;
    }

    for (u32 index = 0; index < PACKET_PARSE_MAX_COUNT; index++) {
        u32 base = 8 + index * PACKET_PARSE_MAX_SIZE;
        if (data[base + 12] != 0x08 || data[base + 13] != 0x00) {
            continue;
        }
        if ((data[base + 14] & 0x0F) != 5) {
            continue;
        }

        u16 total_len = micro_read_u16_be(data, base + 16);
        u8 protocol = data[base + 23];
        u16 src_port = micro_read_u16_be(data, base + 34);
        u16 dst_port = micro_read_u16_be(data, base + 36);

        acc += total_len;
        acc ^= (u64)protocol << ((index & 7) * 8);
        acc += src_port + dst_port;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    packet_parse_xdp,
    bench_packet_parse,
    packet_parse_input_value,
    PACKET_PARSE_INPUT_SIZE)
