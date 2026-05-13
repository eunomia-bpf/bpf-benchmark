#include "common.h"

#define KATRAN_BE_ETH_P_IP 8
#define KATRAN_BE_ETH_P_IPV6 56710
#define KATRAN_FURTHER_PROCESSING -1
#define KATRAN_PCKT_FRAGMENTED 65343
#define KATRAN_IPV4_HDR_LEN_NO_OPT 20U
#define KATRAN_RING_SIZE 65537U
#define KATRAN_MAX_VIPS 512U
#define KATRAN_CH_RINGS_SIZE (KATRAN_MAX_VIPS * KATRAN_RING_SIZE)
#define KATRAN_F_HASH_NO_SRC_PORT (1U << 0)
#define KATRAN_F_LRU_BYPASS (1U << 1)
#define KATRAN_F_HASH_DPORT_ONLY (1U << 3)
#define KATRAN_F_HASH_SRC_DST_PORT (1U << 7)
#define KATRAN_F_ICMP (1U << 0)
#define KATRAN_F_SYN_SET (1U << 1)
#define KATRAN_F_RST_SET (1U << 2)
#define KATRAN_F_IPV6 (1U << 0)
#define KATRAN_DEFAULT_TTL 64U
#define KATRAN_MAX_PCKT_SIZE 1514U
#define KATRAN_IPIP_V4_PREFIX 4268U
#define KATRAN_INIT_JHASH_SEED KATRAN_CH_RINGS_SIZE
#define KATRAN_INIT_JHASH_SEED_V6 KATRAN_MAX_VIPS
#define KATRAN_JHASH_INITVAL 0xdeadbeefU
#define KATRAN_IPPROTO_ICMP 1U
#define KATRAN_IPPROTO_IPIP 4U
#define KATRAN_IPPROTO_TCP 6U
#define KATRAN_IPPROTO_UDP 17U
#define KATRAN_IPPROTO_IPV6 41U
#define KATRAN_IPPROTO_FRAGMENT 44U
#define KATRAN_IPPROTO_ICMPV6 58U
#define KATRAN_VIP_V4 0x0101640aU
#define KATRAN_REAL_V4 0x0200c80aU
#define KATRAN_VIP_PORT 0x901fU
#define KATRAN_VIP_PROTO KATRAN_IPPROTO_TCP
#define KATRAN_VIP_FLAGS KATRAN_F_LRU_BYPASS
#define KATRAN_VIP_NUM 0U
#define KATRAN_REAL_NUM 1U
#define KATRAN_RESULT_MIX 0x9e3779b97f4a7c15ULL

struct katran_flow_key {
    union {
        u32 src;
        u32 srcv6[4];
    };
    union {
        u32 dst;
        u32 dstv6[4];
    };
    union {
        u32 ports;
        u16 port16[2];
    };
    u8 proto;
};

struct katran_packet_description {
    struct katran_flow_key flow;
    u32 real_index;
    u32 ch_hash;
    u8 flags;
    u8 tos;
};

struct katran_ctl_value {
    union {
        u64 value;
        u32 ifindex;
        u8 mac[6];
    };
};

struct katran_vip_definition {
    union {
        u32 vip;
        u32 vipv6[4];
    };
    u16 port;
    u8 proto;
};

struct katran_vip_meta {
    u32 flags;
    u32 vip_num;
};

struct katran_real_pos_lru {
    u32 pos;
    u64 atime;
};

struct katran_real_definition {
    union {
        u32 dst;
        u32 dstv6[4];
    };
    u8 flags;
};

static __always_inline u32 katran_rol32(u32 word, unsigned int shift)
{
    return (word << shift) | (word >> ((-shift) & 31));
}

#define katran_jhash_mix(a, b, c)                                               \
    {                                                                           \
        a -= c;                                                                 \
        a ^= katran_rol32(c, 4);                                                \
        c += b;                                                                 \
        b -= a;                                                                 \
        b ^= katran_rol32(a, 6);                                                \
        a += c;                                                                 \
        c -= b;                                                                 \
        c ^= katran_rol32(b, 8);                                                \
        b += a;                                                                 \
        a -= c;                                                                 \
        a ^= katran_rol32(c, 16);                                               \
        c += b;                                                                 \
        b -= a;                                                                 \
        b ^= katran_rol32(a, 19);                                               \
        a += c;                                                                 \
        c -= b;                                                                 \
        c ^= katran_rol32(b, 4);                                                \
        b += a;                                                                 \
    }

#define katran_jhash_final(a, b, c)                                             \
    {                                                                           \
        c ^= b;                                                                 \
        c -= katran_rol32(b, 14);                                               \
        a ^= c;                                                                 \
        a -= katran_rol32(c, 11);                                               \
        b ^= a;                                                                 \
        b -= katran_rol32(a, 25);                                               \
        c ^= b;                                                                 \
        c -= katran_rol32(b, 16);                                               \
        a ^= c;                                                                 \
        a -= katran_rol32(c, 4);                                                \
        b ^= a;                                                                 \
        b -= katran_rol32(a, 14);                                               \
        c ^= b;                                                                 \
        c -= katran_rol32(b, 24);                                               \
    }

static __always_inline u32
katran_jhash(const void *key, u32 length, u32 initval)
{
    u32 a, b, c;
    const unsigned char *k = key;

    a = b = c = KATRAN_JHASH_INITVAL + length + initval;

    while (length > 12) {
        a += *(u32 *)(k);
        b += *(u32 *)(k + 4);
        c += *(u32 *)(k + 8);
        katran_jhash_mix(a, b, c);
        length -= 12;
        k += 12;
    }
    switch (length) {
    case 12:
        c += (u32)k[11] << 24;
    case 11:
        c += (u32)k[10] << 16;
    case 10:
        c += (u32)k[9] << 8;
    case 9:
        c += k[8];
    case 8:
        b += (u32)k[7] << 24;
    case 7:
        b += (u32)k[6] << 16;
    case 6:
        b += (u32)k[5] << 8;
    case 5:
        b += k[4];
    case 4:
        a += (u32)k[3] << 24;
    case 3:
        a += (u32)k[2] << 16;
    case 2:
        a += (u32)k[1] << 8;
    case 1:
        a += k[0];
        katran_jhash_final(a, b, c);
    case 0:
        break;
    }

    return c;
}

static __always_inline u32
katran_jhash_nwords(u32 a, u32 b, u32 c, u32 initval)
{
    a += initval;
    b += initval;
    c += initval;
    katran_jhash_final(a, b, c);
    return c;
}

static __always_inline u32
katran_jhash_2words(u32 a, u32 b, u32 initval)
{
    return katran_jhash_nwords(
        a, b, 0, initval + KATRAN_JHASH_INITVAL + (2U << 2));
}

static __always_inline u16 katran_bswap16(u16 value)
{
    return (u16)((value << 8) | (value >> 8));
}

static __always_inline u32 katran_get_packet_hash(
    struct katran_packet_description *pckt,
    int hash_16bytes)
{
    if (hash_16bytes) {
        return katran_jhash_2words(
            katran_jhash(
                pckt->flow.srcv6, 16, KATRAN_INIT_JHASH_SEED_V6),
            pckt->flow.ports,
            KATRAN_INIT_JHASH_SEED);
    } else {
        return katran_jhash_2words(
            pckt->flow.src, pckt->flow.ports, KATRAN_INIT_JHASH_SEED);
    }
}

static __always_inline int katran_is_under_flood(u64 *cur_time)
{
    *cur_time = 1;
    return 0;
}

static __always_inline void katran_ctl_lookup(struct katran_ctl_value *cval)
{
    cval->mac[0] = 0x02;
    cval->mac[1] = 0x00;
    cval->mac[2] = 0x00;
    cval->mac[3] = 0x00;
    cval->mac[4] = 0x00;
    cval->mac[5] = 0x0b;
}

static __always_inline int
katran_vip_lookup(struct katran_vip_definition *vip,
                  struct katran_vip_meta *vip_info)
{
    if (vip->vip == KATRAN_VIP_V4 && vip->port == KATRAN_VIP_PORT &&
        vip->proto == KATRAN_VIP_PROTO) {
        vip_info->flags = KATRAN_VIP_FLAGS;
        vip_info->vip_num = KATRAN_VIP_NUM;
        return 1;
    }

    return 0;
}

static __always_inline int katran_ch_ring_lookup(u32 key, u32 *real_pos)
{
    if (key < KATRAN_RING_SIZE) {
        *real_pos = KATRAN_REAL_NUM;
        return 1;
    }
    return 0;
}

static __always_inline int
katran_real_lookup(u32 key, struct katran_real_definition *real)
{
    if (key == KATRAN_REAL_NUM) {
        real->dst = KATRAN_REAL_V4;
        real->flags = 0;
        return 1;
    }
    return 0;
}

static __always_inline u64
katran_calc_offset(int is_ipv6, int is_icmp)
{
    u64 off = 14U;
    if (is_ipv6) {
        off += 40U;
        if (is_icmp) {
            off += 48U;
        }
    } else {
        off += 20U;
        if (is_icmp) {
            off += 28U;
        }
    }
    return off;
}

static __always_inline int
katran_parse_tcp(const u8 *data, const u8 *data_end, int is_ipv6,
                 struct katran_packet_description *pckt)
{
    int is_icmp = !((pckt->flags & KATRAN_F_ICMP) == 0);
    u64 off = katran_calc_offset(is_ipv6, is_icmp);
    const u8 *tcp = data + off;

    if (tcp + 20U > data_end) {
        return 0;
    }

    if (tcp[13] & 0x02U) {
        pckt->flags |= KATRAN_F_SYN_SET;
    }

    if (tcp[13] & 0x04U) {
        pckt->flags |= KATRAN_F_RST_SET;
    }

    if (!is_icmp) {
        pckt->flow.port16[0] = micro_read_u16_le(tcp, 0);
        pckt->flow.port16[1] = micro_read_u16_le(tcp, 2);
    } else {
        pckt->flow.port16[0] = micro_read_u16_le(tcp, 2);
        pckt->flow.port16[1] = micro_read_u16_le(tcp, 0);
    }
    return 1;
}

static __always_inline int
katran_parse_udp(const u8 *data, const u8 *data_end, int is_ipv6,
                 struct katran_packet_description *pckt)
{
    int is_icmp = !((pckt->flags & KATRAN_F_ICMP) == 0);
    u64 off = katran_calc_offset(is_ipv6, is_icmp);
    const u8 *udp = data + off;

    if (udp + 8U > data_end) {
        return 0;
    }

    if (!is_icmp) {
        pckt->flow.port16[0] = micro_read_u16_le(udp, 0);
        pckt->flow.port16[1] = micro_read_u16_le(udp, 2);
    } else {
        pckt->flow.port16[0] = micro_read_u16_le(udp, 2);
        pckt->flow.port16[1] = micro_read_u16_le(udp, 0);
    }
    return 1;
}

static __always_inline int
katran_parse_l3_headers(struct katran_packet_description *pckt,
                        u8 *protocol,
                        u64 nh_off,
                        u64 *th_off,
                        u16 *pkt_bytes,
                        const u8 *data,
                        const u8 *data_end,
                        int is_ipv6)
{
    const u8 *iph = data + nh_off;

    if (is_ipv6) {
        if (iph + 40U > data_end) {
            return XDP_DROP;
        }

        *protocol = iph[6];
        pckt->flow.proto = *protocol;
        pckt->tos = ((iph[0] & 0x0fU) << 4) | ((iph[1] >> 4) & 0x0fU);
        *pkt_bytes = micro_read_u16_be(iph, 4);
        *th_off += nh_off + 40U;

        if (*protocol == KATRAN_IPPROTO_FRAGMENT) {
            return XDP_DROP;
        } else if (*protocol == KATRAN_IPPROTO_ICMPV6) {
            return KATRAN_FURTHER_PROCESSING;
        } else {
            pckt->flow.srcv6[0] = micro_read_u32_le(iph, 8);
            pckt->flow.srcv6[1] = micro_read_u32_le(iph, 12);
            pckt->flow.srcv6[2] = micro_read_u32_le(iph, 16);
            pckt->flow.srcv6[3] = micro_read_u32_le(iph, 20);
            pckt->flow.dstv6[0] = micro_read_u32_le(iph, 24);
            pckt->flow.dstv6[1] = micro_read_u32_le(iph, 28);
            pckt->flow.dstv6[2] = micro_read_u32_le(iph, 32);
            pckt->flow.dstv6[3] = micro_read_u32_le(iph, 36);
        }
    } else {
        if (iph + 20U > data_end) {
            return XDP_DROP;
        }
        if ((iph[0] & 0x0fU) != 5U) {
            return XDP_DROP;
        }
        pckt->tos = iph[1];
        *protocol = iph[9];
        pckt->flow.proto = *protocol;
        *pkt_bytes = micro_read_u16_be(iph, 2);
        *th_off += nh_off + KATRAN_IPV4_HDR_LEN_NO_OPT;

        if (micro_read_u16_le(iph, 6) & KATRAN_PCKT_FRAGMENTED) {
            return XDP_DROP;
        }
        if (*protocol == KATRAN_IPPROTO_ICMP) {
            return KATRAN_FURTHER_PROCESSING;
        } else {
            pckt->flow.src = micro_read_u32_le(iph, 12);
            pckt->flow.dst = micro_read_u32_le(iph, 16);
        }
    }
    return KATRAN_FURTHER_PROCESSING;
}

static __always_inline int
katran_get_packet_dst(struct katran_real_definition *real,
                      struct katran_packet_description *pckt,
                      struct katran_vip_meta *vip_info,
                      int is_ipv6)
{
    struct katran_real_pos_lru new_dst_lru = {};
    int under_flood = 0;
    int src_found = 0;
    u32 real_pos = 0;
    u64 cur_time = 0;
    u32 hash;
    u32 key = 0;

    under_flood = katran_is_under_flood(&cur_time);

    if (!src_found) {
        int hash_16bytes = is_ipv6;

        if (vip_info->flags & KATRAN_F_HASH_DPORT_ONLY) {
            pckt->flow.port16[0] = pckt->flow.port16[1];
            pckt->flow.srcv6[0] = 0;
            pckt->flow.srcv6[1] = 0;
            pckt->flow.srcv6[2] = 0;
            pckt->flow.srcv6[3] = 0;
        }
        hash = katran_get_packet_hash(pckt, hash_16bytes) % KATRAN_RING_SIZE;
        pckt->ch_hash = hash;
        key = KATRAN_RING_SIZE * (vip_info->vip_num) + hash;

        if (!katran_ch_ring_lookup(key, &real_pos)) {
            return 0;
        }
        key = real_pos;
        if (key == 0) {
            return 0;
        }
    }
    pckt->real_index = key;
    if (!katran_real_lookup(key, real)) {
        return 0;
    }
    if (!(vip_info->flags & KATRAN_F_LRU_BYPASS) && !under_flood &&
        !(pckt->flags & KATRAN_F_RST_SET)) {
        if (pckt->flow.proto == KATRAN_IPPROTO_UDP) {
            new_dst_lru.atime = cur_time;
        }
        new_dst_lru.pos = key;
    }
    return 1;
}

static __always_inline u16 katran_csum_fold_helper(u64 csum)
{
    int i;
#pragma unroll
    for (i = 0; i < 4; i++) {
        if (csum >> 16) {
            csum = (csum & 0xffffU) + (csum >> 16);
        }
    }
    return ~csum;
}

static __always_inline u32 katran_create_encap_ipv4_src(u16 port, u32 src)
{
    u32 ip_suffix = katran_bswap16(port);
    ip_suffix <<= 16;
    ip_suffix ^= src;
    return ((0xffff0000U & ip_suffix) | KATRAN_IPIP_V4_PREFIX);
}

static __always_inline u16
katran_create_v4_hdr_checksum(u8 tos, u32 saddr, u32 daddr, u16 pkt_bytes,
                              u8 proto)
{
    u64 csum = 0;
    u16 tot_len = katran_bswap16(pkt_bytes + 20U);

    csum += 0x0045U;
    csum += (u16)tos;
    csum += tot_len;
    csum += 0;
    csum += 0;
    csum += (u16)((proto << 8) | KATRAN_DEFAULT_TTL);
    csum += 0;
    csum += (u16)saddr;
    csum += (u16)(saddr >> 16);
    csum += (u16)daddr;
    csum += (u16)(daddr >> 16);
    return katran_csum_fold_helper(csum);
}

static __always_inline u64
katran_encap_v4_digest(struct katran_ctl_value *cval,
                       struct katran_packet_description *pckt,
                       struct katran_real_definition *dst,
                       u16 pkt_bytes)
{
    u32 ip_src = katran_create_encap_ipv4_src(pckt->flow.port16[0],
                                              pckt->flow.src);
    u16 check = katran_create_v4_hdr_checksum(
        pckt->tos, ip_src, dst->dst, pkt_bytes, KATRAN_IPPROTO_IPIP);
    u64 eth_mix = ((u64)cval->mac[0] << 40) | ((u64)cval->mac[1] << 32) |
                  ((u64)cval->mac[2] << 24) | ((u64)cval->mac[3] << 16) |
                  ((u64)cval->mac[4] << 8) | cval->mac[5];

    return ((u64)ip_src << 32) ^ dst->dst ^ ((u64)check << 16) ^
           pkt_bytes ^ eth_mix;
}

static __always_inline u64 katran_mix_result(u64 acc, u64 value)
{
    acc ^= value + KATRAN_RESULT_MIX + (acc << 6) + (acc >> 2);
    return acc;
}

static __always_inline int
katran_process_packet(const u8 *data, const u8 *data_end, u64 nh_off,
                      int is_ipv6, u64 *out)
{
    struct katran_ctl_value cval = {};
    struct katran_real_definition dst = {};
    struct katran_packet_description pckt = {};
    struct katran_vip_definition vip = {};
    struct katran_vip_meta vip_info = {};
    u64 th_off = 0;
    u16 pkt_bytes = 0;
    u16 original_sport = 0;
    u8 protocol = 0;
    int action;
    u32 vip_num;
    u64 acc = 0;

    action = katran_parse_l3_headers(
        &pckt, &protocol, nh_off, &th_off, &pkt_bytes, data, data_end, is_ipv6);
    if (action >= 0) {
        *out = action;
        return action;
    }

    protocol = pckt.flow.proto;

    if (protocol == KATRAN_IPPROTO_TCP) {
        if (!katran_parse_tcp(data, data_end, is_ipv6, &pckt)) {
            *out = XDP_DROP;
            return XDP_DROP;
        }
    } else if (protocol == KATRAN_IPPROTO_UDP) {
        if (!katran_parse_udp(data, data_end, is_ipv6, &pckt)) {
            *out = XDP_DROP;
            return XDP_DROP;
        }
    } else {
        *out = XDP_PASS;
        return XDP_PASS;
    }

    if (is_ipv6) {
        vip.vipv6[0] = pckt.flow.dstv6[0];
        vip.vipv6[1] = pckt.flow.dstv6[1];
        vip.vipv6[2] = pckt.flow.dstv6[2];
        vip.vipv6[3] = pckt.flow.dstv6[3];
    } else {
        vip.vip = pckt.flow.dst;
    }

    vip.port = pckt.flow.port16[1];
    vip.proto = pckt.flow.proto;
    if (!katran_vip_lookup(&vip, &vip_info)) {
        vip.port = 0;
        if (!katran_vip_lookup(&vip, &vip_info)) {
            *out = XDP_PASS;
            return XDP_PASS;
        }

        if (!(vip_info.flags & KATRAN_F_HASH_DPORT_ONLY) &&
            !(vip_info.flags & KATRAN_F_HASH_SRC_DST_PORT)) {
            pckt.flow.port16[1] = 0;
        }
    }

    if (data_end - data > KATRAN_MAX_PCKT_SIZE) {
        *out = XDP_DROP;
        return XDP_DROP;
    }

    if (vip_info.flags & KATRAN_F_HASH_NO_SRC_PORT) {
        pckt.flow.port16[0] = 0;
    }

    vip_num = vip_info.vip_num;
    original_sport = pckt.flow.port16[0];

    if (!katran_get_packet_dst(&dst, &pckt, &vip_info, is_ipv6)) {
        *out = XDP_DROP;
        return XDP_DROP;
    }

    katran_ctl_lookup(&cval);
    pckt.flow.port16[0] = original_sport;

    acc = katran_mix_result(acc, pckt.flow.src);
    acc = katran_mix_result(acc, pckt.flow.dst);
    acc = katran_mix_result(acc, pckt.flow.ports);
    acc = katran_mix_result(acc, pckt.ch_hash);
    acc = katran_mix_result(acc, pckt.real_index);
    acc = katran_mix_result(acc, vip_num);
    acc = katran_mix_result(acc, pkt_bytes);
    if (dst.flags & KATRAN_F_IPV6) {
        acc = katran_mix_result(acc, dst.dstv6[0]);
        action = XDP_TX;
    } else {
        acc = katran_mix_result(acc,
                                katran_encap_v4_digest(&cval, &pckt, &dst,
                                                       pkt_bytes));
        action = XDP_TX;
    }

    *out = katran_mix_result(acc, action);
    return action;
}

static __always_inline int
bench_katran_like(const u8 *data, const u8 *data_end, u64 *out)
{
    u64 data_len = data_end - data;
    u32 nh_off = 14U;
    u32 eth_proto;
    int action;
    u64 result = 0;

    if (data + nh_off > data_end) {
        return -1;
    }

    result = katran_mix_result(result, data_len);
    eth_proto = micro_read_u16_le(data, 12);

    if (eth_proto == KATRAN_BE_ETH_P_IP) {
        action = katran_process_packet(data, data_end, nh_off, 0, &result);
    } else if (eth_proto == KATRAN_BE_ETH_P_IPV6) {
        action = katran_process_packet(data, data_end, nh_off, 1, &result);
    } else {
        action = XDP_PASS;
        result = katran_mix_result(result, action);
    }

    *out = katran_mix_result(result, action);
    return 0;
}

SEC("xdp") int katran_like_xdp(struct xdp_md *ctx)
{
    u8 *data = (u8 *)(long)ctx->data;
    u8 *data_end = (u8 *)(long)ctx->data_end;
    u8 *payload;
    u64 result = 0;

    if (data > data_end) {
        return XDP_ABORTED;
    }

    payload = data + MICRO_RESULT_PREFIX_SIZE;
    if (payload > data_end) {
        return XDP_ABORTED;
    }

    if (bench_katran_like(payload, data_end, &result) < 0) {
        return XDP_ABORTED;
    }

    micro_write_u64_le(data, result);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
