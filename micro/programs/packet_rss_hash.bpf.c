#include "common.h"

#define JHASH_MIX(a, b, c)                                                      \
    do {                                                                        \
        (a) -= (c);                                                             \
        (a) ^= micro_rotl32((c), 4U);                                           \
        (c) += (b);                                                             \
        (b) -= (a);                                                             \
        (b) ^= micro_rotl32((a), 6U);                                           \
        (a) += (c);                                                             \
        (c) -= (b);                                                             \
        (c) ^= micro_rotl32((b), 8U);                                           \
        (b) += (a);                                                             \
        (a) -= (c);                                                             \
        (a) ^= micro_rotl32((c), 16U);                                          \
        (c) += (b);                                                             \
        (b) -= (a);                                                             \
        (b) ^= micro_rotl32((a), 19U);                                          \
        (a) += (c);                                                             \
        (c) -= (b);                                                             \
        (c) ^= micro_rotl32((b), 4U);                                           \
        (b) += (a);                                                             \
    } while (0)

#define JHASH_FINAL(a, b, c)                                                    \
    do {                                                                        \
        (c) ^= (b);                                                             \
        (c) -= micro_rotl32((b), 14U);                                          \
        (a) ^= (c);                                                             \
        (a) -= micro_rotl32((c), 11U);                                          \
        (b) ^= (a);                                                             \
        (b) -= micro_rotl32((a), 25U);                                          \
        (c) ^= (b);                                                             \
        (c) -= micro_rotl32((b), 16U);                                          \
        (a) ^= (c);                                                             \
        (a) -= micro_rotl32((c), 4U);                                           \
        (b) ^= (a);                                                             \
        (b) -= micro_rotl32((a), 14U);                                          \
        (c) ^= (b);                                                             \
        (c) -= micro_rotl32((b), 24U);                                          \
    } while (0)

static __always_inline int
bench_packet_rss_hash(const u8 *data, const u8 *data_end, u64 *out)
{
    if (data + 14U > data_end) {
        return -1;
    }

    const u8 *eth = data;
    if (micro_read_u16_be(eth, 12U) != 0x0800U) {
        return -1;
    }

    const u8 *ip = eth + 14U;
    if (ip + 20U > data_end) {
        return -1;
    }

    u8 ver_ihl = ip[0];
    u8 version = ver_ihl >> 4;
    u8 ihl_words = ver_ihl & 0x0FU;
    if (version != 4U || ihl_words < 5U) {
        return -1;
    }

    u32 ip_header_len = (u32)ihl_words * 4U;
    if (ip + ip_header_len > data_end) {
        return -1;
    }

    u16 total_len = micro_read_u16_be(ip, 2U);
    u8 protocol = ip[9U];
    if (protocol != 6U && protocol != 17U) {
        return -1;
    }

    u32 src_ip = micro_read_u32_be(ip, 12U);
    u32 dst_ip = micro_read_u32_be(ip, 16U);
    const u8 *l4 = ip + ip_header_len;
    if (l4 + 4U > data_end) {
        return -1;
    }

    u16 src_port = micro_read_u16_be(l4, 0U);
    u16 dst_port = micro_read_u16_be(l4, 2U);

    u32 a = 0xDEADBEEFU + total_len + src_ip;
    u32 b = 0x9E3779B9U + dst_ip;
    u32 c = 0x12345678U + (((u32)src_port << 16U) | dst_port) + protocol;

    JHASH_MIX(a, b, c);
    a += micro_rotl32(src_ip ^ dst_ip, 7U);
    b += ((u32)src_port << 16U) | dst_port;
    c += total_len ^ ((u32)protocol << 24U);
    JHASH_FINAL(a, b, c);

    *out = ((u64)c << 32U) ^
           ((u64)total_len << 16U) ^
           ((u64)src_port << 8U) ^
           dst_port ^
           protocol;
    return 0;
}

SEC("xdp") int packet_rss_hash_xdp(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    u8 *payload;
    u64 result = 0;

    if (data > data_end) {
        return XDP_ABORTED;
    }

    payload = data + 8U;
    if (payload > data_end) {
        return XDP_ABORTED;
    }

    if (bench_packet_rss_hash(payload, data_end, &result) < 0) {
        return XDP_ABORTED;
    }

    micro_write_u64_le(data, result);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
