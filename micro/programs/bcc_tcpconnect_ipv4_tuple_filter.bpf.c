#include "common.h"

#define BCC_TCPCONNECT_RECORDS 32U
#define BCC_TCPCONNECT_RECORD_SIZE 24U
#define BCC_TCPCONNECT_INPUT_SIZE \
    (8U + BCC_TCPCONNECT_RECORDS * BCC_TCPCONNECT_RECORD_SIZE)

static __always_inline u32 bcc_tcpconnect_port_class(u16 dport)
{
    if (dport == 80U) {
        return 1U;
    }
    if (dport == 443U) {
        return 2U;
    }
    if (dport == 8080U || dport == 8443U) {
        return 3U;
    }
    if (dport >= 30000U && dport <= 32767U) {
        return 4U;
    }
    return 0U;
}

static __always_inline int
bench_bcc_tcpconnect_ipv4_tuple_filter(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BCC_TCPCONNECT_INPUT_SIZE)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0U);
    u32 record_size = micro_read_u32_le(data, 4U);
    if (record_count != BCC_TCPCONNECT_RECORDS ||
        record_size != BCC_TCPCONNECT_RECORD_SIZE) {
        return -1;
    }

    u64 acc = 0xA0761D6478BD642FULL;
    for (u32 index = 0; index < BCC_TCPCONNECT_RECORDS; index++) {
        u32 base = 8U + index * BCC_TCPCONNECT_RECORD_SIZE;
        u32 pid = micro_read_u32_le(data, base);
        u32 uid = micro_read_u32_le(data, base + 4U);
        u32 src = micro_read_u32_le(data, base + 8U);
        u32 dst = micro_read_u32_le(data, base + 12U);
        u16 sport = micro_read_u16_le(data, base + 16U);
        u16 dport = micro_read_u16_le(data, base + 18U);
        u8 family = data[base + 20U];
        u8 flags = data[base + 21U];
        u16 netns = micro_read_u16_le(data, base + 22U);
        u32 port_class = bcc_tcpconnect_port_class(dport);

        if (family != 2U) {
            acc ^= ((u64)family << 48U) | pid;
            continue;
        }
        if ((flags & 1U) == 0U || port_class == 0U) {
            acc += ((u64)uid << 32U) ^ dport;
            continue;
        }

        u32 tuple_hash = src ^ micro_rotl32(dst, 7U) ^
                         ((u32)sport << 16U) ^ dport ^ netns;
        if ((flags & 2U) != 0U) {
            tuple_hash ^= pid + uid;
        }
        if ((flags & 4U) != 0U) {
            tuple_hash = micro_rotl32(tuple_hash, port_class + 3U);
        }

        acc ^= micro_rotl64(((u64)tuple_hash << 32U) | pid,
                            (index & 7U) + 1U);
        acc += ((u64)port_class << 56U) ^ ((u64)netns << 16U) ^ uid;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bcc_tcpconnect_ipv4_tuple_filter_xdp,
    bench_bcc_tcpconnect_ipv4_tuple_filter,
    bcc_tcpconnect_ipv4_tuple_filter_input_value,
    BCC_TCPCONNECT_INPUT_SIZE)
