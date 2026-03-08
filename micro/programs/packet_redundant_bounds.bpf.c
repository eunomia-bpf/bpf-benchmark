#include "common.h"

#define PACKET_REDUNDANT_BOUNDS_RECORDS 32U
#define PACKET_REDUNDANT_BOUNDS_RECORD_SIZE 24U
#define PACKET_REDUNDANT_BOUNDS_INPUT_SIZE \
    (8U + PACKET_REDUNDANT_BOUNDS_RECORDS * PACKET_REDUNDANT_BOUNDS_RECORD_SIZE)

static __always_inline int
bench_packet_redundant_bounds(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != PACKET_REDUNDANT_BOUNDS_RECORDS ||
        record_size != PACKET_REDUNDANT_BOUNDS_RECORD_SIZE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, PACKET_REDUNDANT_BOUNDS_RECORDS * PACKET_REDUNDANT_BOUNDS_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0xD6E8FEB86659FD93ULL;
    for (u32 index = 0; index < PACKET_REDUNDANT_BOUNDS_RECORDS; index++) {
        u32 base = 8U + index * PACKET_REDUNDANT_BOUNDS_RECORD_SIZE;
        u32 slack;
        u32 selector;
        u32 lane0;
        u32 lane1;
        u32 lane2;
        u32 lane3;
        u16 tail0;
        u16 tail1;

        if (!micro_has_bytes(len, base, 4U)) {
            continue;
        }

        slack = data[base + 0U] & 3U;
        selector = data[base + 1U];

        /* This dominating window makes the narrower checks below redundant. */
        if (!micro_has_bytes(len, base, PACKET_REDUNDANT_BOUNDS_RECORD_SIZE + slack)) {
            continue;
        }
        if (!micro_has_bytes(len, base + 4U, 4U)) {
            continue;
        }
        lane0 = micro_read_u32_le(data, base + 4U);
        if (!micro_has_bytes(len, base + 8U, 4U)) {
            continue;
        }
        lane1 = micro_read_u32_le(data, base + 8U);
        if (!micro_has_bytes(len, base + 12U, 4U)) {
            continue;
        }
        lane2 = micro_read_u32_le(data, base + 12U);
        if (!micro_has_bytes(len, base + 16U, 4U)) {
            continue;
        }
        lane3 = micro_read_u32_le(data, base + 16U);
        if (!micro_has_bytes(len, base + 20U, 2U)) {
            continue;
        }
        tail0 = micro_read_u16_le(data, base + 20U);
        if (!micro_has_bytes(len, base + 22U, 2U)) {
            continue;
        }
        tail1 = micro_read_u16_le(data, base + 22U);

        acc += (u64)lane0 + lane1 + tail0;
        if ((selector & 1U) != 0U) {
            if (!micro_has_bytes(len, base + 12U, 8U)) {
                continue;
            }
            acc ^= ((u64)lane2 << 32U) | lane3;
        } else {
            if (!micro_has_bytes(len, base + 8U, 8U)) {
                continue;
            }
            acc += ((u64)lane1 << 32U) | lane2;
        }
        acc ^= (u64)lane3 << ((selector & 7U) * 4U);
        acc += (u64)tail1 << ((index & 3U) * 8U);
        acc = micro_rotl64(acc, ((selector ^ slack) & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(
    packet_redundant_bounds_xdp,
    bench_packet_redundant_bounds,
    PACKET_REDUNDANT_BOUNDS_INPUT_SIZE)
