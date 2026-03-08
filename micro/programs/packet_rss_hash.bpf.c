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

static __always_inline int bench_packet_rss_hash(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 14U)) {
        return -1;
    }

    if (micro_read_u16_be(data, 12U) != 0x0800U) {
        return -1;
    }
    if (!micro_has_bytes(len, 14U, 20U)) {
        return -1;
    }

    u32 ip = 14U;
    u8 ver_ihl = data[ip];
    u8 version = ver_ihl >> 4;
    u8 ihl_words = ver_ihl & 0x0FU;
    if (version != 4U || ihl_words < 5U) {
        return -1;
    }

    u32 ip_header_len = (u32)ihl_words * 4U;
    if (!micro_has_bytes(len, ip, ip_header_len)) {
        return -1;
    }

    u16 total_len = micro_read_u16_be(data, ip + 2U);
    u8 protocol = data[ip + 9U];
    if (protocol != 6U && protocol != 17U) {
        return -1;
    }

    u32 src_ip = micro_read_u32_be(data, ip + 12U);
    u32 dst_ip = micro_read_u32_be(data, ip + 16U);
    u32 l4 = ip + ip_header_len;
    if (!micro_has_bytes(len, l4, 4U)) {
        return -1;
    }

    u16 src_port = micro_read_u16_be(data, l4);
    u16 dst_port = micro_read_u16_be(data, l4 + 2U);

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

DEFINE_PACKET_BACKED_XDP_BENCH(packet_rss_hash_xdp, bench_packet_rss_hash)
