# katran_lb_consistent_hash_select

## Original C
```c
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
bench_katran_lb_consistent_hash_select(const u8 *data, const u8 *data_end, u64 *out)
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

SEC("xdp") int katran_lb_consistent_hash_select_xdp(struct xdp_md *ctx)
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

    if (bench_katran_lb_consistent_hash_select(payload, data_end, &result) < 0) {
        return XDP_ABORTED;
    }

    micro_write_u64_le(data, result);
    return XDP_PASS;
}

char LICENSE[] SEC("license") = "GPL";
```

## Native ASM
```asm
Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 c1 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fc1]        # 3fd0 <__gmon_start__@Base>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 ca 2f 00 00    	push   QWORD PTR [rip+0x2fca]        # 3ff0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 cc 2f 00 00    	jmp    QWORD PTR [rip+0x2fcc]        # 3ff8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

Disassembly of section .plt.got:

0000000000001030 <__cxa_finalize@plt>:
    1030:	ff 25 aa 2f 00 00    	jmp    QWORD PTR [rip+0x2faa]        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    1036:	66 90                	xchg   ax,ax

Disassembly of section .text:

0000000000001040 <deregister_tm_clones>:
    1040:	48 8d 3d c9 2f 00 00 	lea    rdi,[rip+0x2fc9]        # 4010 <__TMC_END__>
    1047:	48 8d 05 c2 2f 00 00 	lea    rax,[rip+0x2fc2]        # 4010 <__TMC_END__>
    104e:	48 39 f8             	cmp    rax,rdi
    1051:	74 15                	je     1068 <deregister_tm_clones+0x28>
    1053:	48 8b 05 6e 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f6e]        # 3fc8 <_ITM_deregisterTMCloneTable@Base>
    105a:	48 85 c0             	test   rax,rax
    105d:	74 09                	je     1068 <deregister_tm_clones+0x28>
    105f:	ff e0                	jmp    rax
    1061:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1068:	c3                   	ret
    1069:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001070 <register_tm_clones>:
    1070:	48 8d 3d 99 2f 00 00 	lea    rdi,[rip+0x2f99]        # 4010 <__TMC_END__>
    1077:	48 8d 35 92 2f 00 00 	lea    rsi,[rip+0x2f92]        # 4010 <__TMC_END__>
    107e:	48 29 fe             	sub    rsi,rdi
    1081:	48 89 f0             	mov    rax,rsi
    1084:	48 c1 ee 3f          	shr    rsi,0x3f
    1088:	48 c1 f8 03          	sar    rax,0x3
    108c:	48 01 c6             	add    rsi,rax
    108f:	48 d1 fe             	sar    rsi,1
    1092:	74 14                	je     10a8 <register_tm_clones+0x38>
    1094:	48 8b 05 3d 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f3d]        # 3fd8 <_ITM_registerTMCloneTable@Base>
    109b:	48 85 c0             	test   rax,rax
    109e:	74 08                	je     10a8 <register_tm_clones+0x38>
    10a0:	ff e0                	jmp    rax
    10a2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    10a8:	c3                   	ret
    10a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010b0 <__do_global_dtors_aux>:
    10b0:	f3 0f 1e fa          	endbr64
    10b4:	80 3d 51 2f 00 00 00 	cmp    BYTE PTR [rip+0x2f51],0x0        # 400c <completed.0>
    10bb:	75 2b                	jne    10e8 <__do_global_dtors_aux+0x38>
    10bd:	55                   	push   rbp
    10be:	48 83 3d 1a 2f 00 00 	cmp    QWORD PTR [rip+0x2f1a],0x0        # 3fe0 <__cxa_finalize@GLIBC_2.2.5>
    10c5:	00 
    10c6:	48 89 e5             	mov    rbp,rsp
    10c9:	74 0c                	je     10d7 <__do_global_dtors_aux+0x27>
    10cb:	48 8b 3d 2e 2f 00 00 	mov    rdi,QWORD PTR [rip+0x2f2e]        # 4000 <__dso_handle>
    10d2:	e8 59 ff ff ff       	call   1030 <__cxa_finalize@plt>
    10d7:	e8 64 ff ff ff       	call   1040 <deregister_tm_clones>
    10dc:	c6 05 29 2f 00 00 01 	mov    BYTE PTR [rip+0x2f29],0x1        # 400c <completed.0>
    10e3:	5d                   	pop    rbp
    10e4:	c3                   	ret
    10e5:	0f 1f 00             	nop    DWORD PTR [rax]
    10e8:	c3                   	ret
    10e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000010f0 <frame_dummy>:
    10f0:	f3 0f 1e fa          	endbr64
    10f4:	e9 77 ff ff ff       	jmp    1070 <register_tm_clones>
    10f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001100 <katran_lb_consistent_hash_select_xdp>:
    1100:	55                   	push   rbp
    1101:	41 57                	push   r15
    1103:	41 56                	push   r14
    1105:	41 55                	push   r13
    1107:	41 54                	push   r12
    1109:	53                   	push   rbx
    110a:	50                   	push   rax
    110b:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    110e:	48 8b 5f 08          	mov    rbx,QWORD PTR [rdi+0x8]
    1112:	31 c0                	xor    eax,eax
    1114:	48 39 d9             	cmp    rcx,rbx
    1117:	0f 87 f3 04 00 00    	ja     1610 <katran_lb_consistent_hash_select_xdp+0x510>
    111d:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1121:	48 39 de             	cmp    rsi,rbx
    1124:	0f 87 e6 04 00 00    	ja     1610 <katran_lb_consistent_hash_select_xdp+0x510>
    112a:	48 8d 51 16          	lea    rdx,[rcx+0x16]
    112e:	48 39 da             	cmp    rdx,rbx
    1131:	0f 87 d9 04 00 00    	ja     1610 <katran_lb_consistent_hash_select_xdp+0x510>
    1137:	48 b8 15 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c15
    113e:	79 37 9e 
    1141:	49 89 da             	mov    r10,rbx
    1144:	49 29 f2             	sub    r10,rsi
    1147:	0f b7 71 14          	movzx  esi,WORD PTR [rcx+0x14]
    114b:	81 fe 86 dd 00 00    	cmp    esi,0xdd86
    1151:	0f 84 8f 00 00 00    	je     11e6 <katran_lb_consistent_hash_select_xdp+0xe6>
    1157:	83 fe 08             	cmp    esi,0x8
    115a:	0f 85 b5 00 00 00    	jne    1215 <katran_lb_consistent_hash_select_xdp+0x115>
    1160:	48 8d 71 2a          	lea    rsi,[rcx+0x2a]
    1164:	41 b9 01 00 00 00    	mov    r9d,0x1
    116a:	48 39 de             	cmp    rsi,rbx
    116d:	0f 87 76 04 00 00    	ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9>
    1173:	0f b6 12             	movzx  edx,BYTE PTR [rdx]
    1176:	80 e2 0f             	and    dl,0xf
    1179:	80 fa 05             	cmp    dl,0x5
    117c:	0f 85 67 04 00 00    	jne    15e9 <katran_lb_consistent_hash_select_xdp+0x4e9>
    1182:	0f b6 51 1c          	movzx  edx,BYTE PTR [rcx+0x1c]
    1186:	0f b6 71 1d          	movzx  esi,BYTE PTR [rcx+0x1d]
    118a:	83 e2 3f             	and    edx,0x3f
    118d:	66 09 f2             	or     dx,si
    1190:	0f 85 53 04 00 00    	jne    15e9 <katran_lb_consistent_hash_select_xdp+0x4e9>
    1196:	44 0f b6 71 1f       	movzx  r14d,BYTE PTR [rcx+0x1f]
    119b:	be 02 00 00 00       	mov    esi,0x2
    11a0:	41 83 fe 01          	cmp    r14d,0x1
    11a4:	0f 84 89 00 00 00    	je     1233 <katran_lb_consistent_hash_select_xdp+0x133>
    11aa:	0f b6 79 17          	movzx  edi,BYTE PTR [rcx+0x17]
    11ae:	0f b7 69 18          	movzx  ebp,WORD PTR [rcx+0x18]
    11b2:	44 0f b7 59 22       	movzx  r11d,WORD PTR [rcx+0x22]
    11b7:	44 0f b6 41 24       	movzx  r8d,BYTE PTR [rcx+0x24]
    11bc:	0f b6 51 25          	movzx  edx,BYTE PTR [rcx+0x25]
    11c0:	44 8b 79 26          	mov    r15d,DWORD PTR [rcx+0x26]
    11c4:	41 83 fe 11          	cmp    r14d,0x11
    11c8:	0f 84 12 04 00 00    	je     15e0 <katran_lb_consistent_hash_select_xdp+0x4e0>
    11ce:	41 83 fe 06          	cmp    r14d,0x6
    11d2:	75 5f                	jne    1233 <katran_lb_consistent_hash_select_xdp+0x133>
    11d4:	4c 8d 61 3e          	lea    r12,[rcx+0x3e]
    11d8:	49 39 dc             	cmp    r12,rbx
    11db:	0f 87 08 04 00 00    	ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9>
    11e1:	e9 39 04 00 00       	jmp    161f <katran_lb_consistent_hash_select_xdp+0x51f>
    11e6:	48 8d 51 3e          	lea    rdx,[rcx+0x3e]
    11ea:	41 b9 01 00 00 00    	mov    r9d,0x1
    11f0:	48 39 da             	cmp    rdx,rbx
    11f3:	0f 87 f0 03 00 00    	ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9>
    11f9:	44 0f b6 61 1c       	movzx  r12d,BYTE PTR [rcx+0x1c]
    11fe:	41 83 fc 2c          	cmp    r12d,0x2c
    1202:	0f 84 e1 03 00 00    	je     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9>
    1208:	41 83 fc 3a          	cmp    r12d,0x3a
    120c:	75 30                	jne    123e <katran_lb_consistent_hash_select_xdp+0x13e>
    120e:	be 02 00 00 00       	mov    esi,0x2
    1213:	eb 1e                	jmp    1233 <katran_lb_consistent_hash_select_xdp+0x133>
    1215:	49 01 c2             	add    r10,rax
    1218:	4c 89 d2             	mov    rdx,r10
    121b:	48 c1 e2 06          	shl    rdx,0x6
    121f:	48 01 c2             	add    rdx,rax
    1222:	4c 89 d6             	mov    rsi,r10
    1225:	48 c1 ee 02          	shr    rsi,0x2
    1229:	48 01 d6             	add    rsi,rdx
    122c:	48 83 c6 02          	add    rsi,0x2
    1230:	4c 31 d6             	xor    rsi,r10
    1233:	41 b9 02 00 00 00    	mov    r9d,0x2
    1239:	e9 b0 03 00 00       	jmp    15ee <katran_lb_consistent_hash_select_xdp+0x4ee>
    123e:	0f b6 51 16          	movzx  edx,BYTE PTR [rcx+0x16]
    1242:	44 0f b6 79 17       	movzx  r15d,BYTE PTR [rcx+0x17]
    1247:	44 0f b7 71 1a       	movzx  r14d,WORD PTR [rcx+0x1a]
    124c:	8b 79 1e             	mov    edi,DWORD PTR [rcx+0x1e]
    124f:	44 8b 59 26          	mov    r11d,DWORD PTR [rcx+0x26]
    1253:	8b 69 2a             	mov    ebp,DWORD PTR [rcx+0x2a]
    1256:	44 8b 69 2e          	mov    r13d,DWORD PTR [rcx+0x2e]
    125a:	41 b8 ff c0 ad de    	mov    r8d,0xdeadc0ff
    1260:	44 03 41 22          	add    r8d,DWORD PTR [rcx+0x22]
    1264:	be 02 00 00 00       	mov    esi,0x2
    1269:	41 83 fc 11          	cmp    r12d,0x11
    126d:	74 19                	je     1288 <katran_lb_consistent_hash_select_xdp+0x188>
    126f:	41 83 fc 06          	cmp    r12d,0x6
    1273:	75 be                	jne    1233 <katran_lb_consistent_hash_select_xdp+0x133>
    1275:	48 89 3c 24          	mov    QWORD PTR [rsp],rdi
    1279:	48 8d 79 52          	lea    rdi,[rcx+0x52]
    127d:	48 39 df             	cmp    rdi,rbx
    1280:	0f 87 63 03 00 00    	ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9>
    1286:	eb 11                	jmp    1299 <katran_lb_consistent_hash_select_xdp+0x199>
    1288:	48 89 3c 24          	mov    QWORD PTR [rsp],rdi
    128c:	48 8d 79 46          	lea    rdi,[rcx+0x46]
    1290:	48 39 df             	cmp    rdi,rbx
    1293:	0f 87 50 03 00 00    	ja     15e9 <katran_lb_consistent_hash_select_xdp+0x4e9>
    1299:	41 83 fc 06          	cmp    r12d,0x6
    129d:	75 94                	jne    1233 <katran_lb_consistent_hash_select_xdp+0x133>
    129f:	41 81 fd 0a 64 01 01 	cmp    r13d,0x101640a
    12a6:	75 8b                	jne    1233 <katran_lb_consistent_hash_select_xdp+0x133>
    12a8:	0f b7 79 40          	movzx  edi,WORD PTR [rcx+0x40]
    12ac:	41 b9 02 00 00 00    	mov    r9d,0x2
    12b2:	81 ff 1f 90 00 00    	cmp    edi,0x901f
    12b8:	0f 85 30 03 00 00    	jne    15ee <katran_lb_consistent_hash_select_xdp+0x4ee>
    12be:	be 01 00 00 00       	mov    esi,0x1
    12c3:	41 b9 01 00 00 00    	mov    r9d,0x1
    12c9:	49 81 fa ea 05 00 00 	cmp    r10,0x5ea
    12d0:	0f 8f 18 03 00 00    	jg     15ee <katran_lb_consistent_hash_select_xdp+0x4ee>
    12d6:	41 c0 ef 04          	shr    r15b,0x4
    12da:	41 89 d4             	mov    r12d,edx
    12dd:	41 c0 e4 04          	shl    r12b,0x4
    12e1:	45 08 fc             	or     r12b,r15b
    12e4:	66 41 c1 c6 08       	rol    r14w,0x8
    12e9:	41 0f b7 f6          	movzx  esi,r14w
    12ed:	89 ef                	mov    edi,ebp
    12ef:	81 e7 00 00 00 ff    	and    edi,0xff000000
    12f5:	45 8d 8b ff c0 ad de 	lea    r9d,[r11-0x21523f01]
    12fc:	41 89 ea             	mov    r10d,ebp
    12ff:	41 81 e2 00 00 ff 00 	and    r10d,0xff0000
    1306:	41 01 fa             	add    r10d,edi
    1309:	89 ef                	mov    edi,ebp
    130b:	81 e7 00 ff 00 00    	and    edi,0xff00
    1311:	44 01 d7             	add    edi,r10d
    1314:	40 0f b6 dd          	movzx  ebx,bpl
    1318:	01 fb                	add    ebx,edi
    131a:	48 8b 14 24          	mov    rdx,QWORD PTR [rsp]
    131e:	89 d7                	mov    edi,edx
    1320:	44 29 df             	sub    edi,r11d
    1323:	45 89 ce             	mov    r14d,r9d
    1326:	41 c1 c6 04          	rol    r14d,0x4
    132a:	41 31 fe             	xor    r14d,edi
    132d:	45 01 c1             	add    r9d,r8d
    1330:	45 29 f0             	sub    r8d,r14d
    1333:	45 89 f2             	mov    r10d,r14d
    1336:	41 c1 c2 06          	rol    r10d,0x6
    133a:	45 31 c2             	xor    r10d,r8d
    133d:	45 01 ce             	add    r14d,r9d
    1340:	43 8d 3c 32          	lea    edi,[r10+r14*1]
    1344:	45 29 d1             	sub    r9d,r10d
    1347:	41 c1 c2 08          	rol    r10d,0x8
    134b:	44 0f b7 41 3e       	movzx  r8d,WORD PTR [rcx+0x3e]
    1350:	45 31 ca             	xor    r10d,r9d
    1353:	45 29 d6             	sub    r14d,r10d
    1356:	45 89 d3             	mov    r11d,r10d
    1359:	41 c1 c3 10          	rol    r11d,0x10
    135d:	45 31 f3             	xor    r11d,r14d
    1360:	41 01 fa             	add    r10d,edi
    1363:	44 29 df             	sub    edi,r11d
    1366:	45 89 de             	mov    r14d,r11d
    1369:	41 c1 c6 13          	rol    r14d,0x13
    136d:	41 31 fe             	xor    r14d,edi
    1370:	45 01 d3             	add    r11d,r10d
    1373:	47 8d 0c 1e          	lea    r9d,[r14+r11*1]
    1377:	45 29 f2             	sub    r10d,r14d
    137a:	41 c1 c6 04          	rol    r14d,0x4
    137e:	41 01 db             	add    r11d,ebx
    1381:	45 31 ca             	xor    r10d,r9d
    1384:	45 31 f2             	xor    r10d,r14d
    1387:	44 89 cf             	mov    edi,r9d
    138a:	c1 c7 0e             	rol    edi,0xe
    138d:	41 29 fa             	sub    r10d,edi
    1390:	44 89 d7             	mov    edi,r10d
    1393:	c1 c7 0b             	rol    edi,0xb
    1396:	45 31 d3             	xor    r11d,r10d
    1399:	41 29 fb             	sub    r11d,edi
    139c:	45 31 d9             	xor    r9d,r11d
    139f:	44 89 df             	mov    edi,r11d
    13a2:	c1 c7 19             	rol    edi,0x19
    13a5:	41 29 f9             	sub    r9d,edi
    13a8:	45 31 ca             	xor    r10d,r9d
    13ab:	44 89 cf             	mov    edi,r9d
    13ae:	c1 c7 10             	rol    edi,0x10
    13b1:	41 29 fa             	sub    r10d,edi
    13b4:	45 31 d3             	xor    r11d,r10d
    13b7:	44 89 d7             	mov    edi,r10d
    13ba:	c1 c7 04             	rol    edi,0x4
    13bd:	41 29 fb             	sub    r11d,edi
    13c0:	45 31 d9             	xor    r9d,r11d
    13c3:	41 c1 c3 0e          	rol    r11d,0xe
    13c7:	45 29 d9             	sub    r9d,r11d
    13ca:	44 89 cf             	mov    edi,r9d
    13cd:	c1 c7 18             	rol    edi,0x18
    13d0:	45 31 d1             	xor    r9d,r10d
    13d3:	41 29 f9             	sub    r9d,edi
    13d6:	41 81 c1 f7 c0 ad e0 	add    r9d,0xe0adc0f7
    13dd:	45 89 c3             	mov    r11d,r8d
    13e0:	41 81 c3 f7 c0 cc 70 	add    r11d,0x70ccc0f7
    13e7:	45 89 da             	mov    r10d,r11d
    13ea:	41 81 f2 f7 c0 ad e0 	xor    r10d,0xe0adc0f7
    13f1:	bf 00 00 cc 70       	mov    edi,0x70cc0000
    13f6:	44 0f ac df 12       	shrd   edi,r11d,0x12
    13fb:	41 29 fa             	sub    r10d,edi
    13fe:	45 31 d1             	xor    r9d,r10d
    1401:	44 89 d7             	mov    edi,r10d
    1404:	c1 c7 0b             	rol    edi,0xb
    1407:	41 29 f9             	sub    r9d,edi
    140a:	45 31 cb             	xor    r11d,r9d
    140d:	44 89 cf             	mov    edi,r9d
    1410:	c1 c7 19             	rol    edi,0x19
    1413:	41 29 fb             	sub    r11d,edi
    1416:	44 89 df             	mov    edi,r11d
    1419:	c1 c7 10             	rol    edi,0x10
    141c:	45 31 da             	xor    r10d,r11d
    141f:	41 29 fa             	sub    r10d,edi
    1422:	45 31 d1             	xor    r9d,r10d
    1425:	44 89 d7             	mov    edi,r10d
    1428:	c1 c7 04             	rol    edi,0x4
    142b:	41 29 f9             	sub    r9d,edi
    142e:	45 31 cb             	xor    r11d,r9d
    1431:	41 c1 c1 0e          	rol    r9d,0xe
    1435:	45 29 cb             	sub    r11d,r9d
    1438:	45 31 da             	xor    r10d,r11d
    143b:	41 c1 c3 18          	rol    r11d,0x18
    143f:	45 29 da             	sub    r10d,r11d
    1442:	bf 01 00 ff ff       	mov    edi,0xffff0001
    1447:	49 0f af fa          	imul   rdi,r10
    144b:	48 c1 ef 30          	shr    rdi,0x30
    144f:	41 89 f9             	mov    r9d,edi
    1452:	41 c1 e1 10          	shl    r9d,0x10
    1456:	41 09 f9             	or     r9d,edi
    1459:	45 29 ca             	sub    r10d,r9d
    145c:	48 89 d7             	mov    rdi,rdx
    145f:	48 01 c7             	add    rdi,rax
    1462:	49 89 f9             	mov    r9,rdi
    1465:	49 c1 e1 06          	shl    r9,0x6
    1469:	49 01 c1             	add    r9,rax
    146c:	49 89 fb             	mov    r11,rdi
    146f:	49 c1 eb 02          	shr    r11,0x2
    1473:	4d 01 d9             	add    r9,r11
    1476:	49 81 c1 0a 64 01 01 	add    r9,0x101640a
    147d:	49 31 f9             	xor    r9,rdi
    1480:	4d 89 cb             	mov    r11,r9
    1483:	49 c1 e3 06          	shl    r11,0x6
    1487:	4d 01 c3             	add    r11,r8
    148a:	49 01 c3             	add    r11,rax
    148d:	4c 89 cf             	mov    rdi,r9
    1490:	48 c1 ef 02          	shr    rdi,0x2
    1494:	bb 00 00 1f 90       	mov    ebx,0x901f0000
    1499:	48 01 fb             	add    rbx,rdi
    149c:	4c 01 db             	add    rbx,r11
    149f:	4c 31 cb             	xor    rbx,r9
    14a2:	48 89 df             	mov    rdi,rbx
    14a5:	48 c1 e7 06          	shl    rdi,0x6
    14a9:	49 89 d9             	mov    r9,rbx
    14ac:	49 c1 e9 02          	shr    r9,0x2
    14b0:	48 01 c7             	add    rdi,rax
    14b3:	4c 01 cf             	add    rdi,r9
    14b6:	4c 01 d7             	add    rdi,r10
    14b9:	48 31 df             	xor    rdi,rbx
    14bc:	49 89 f9             	mov    r9,rdi
    14bf:	49 c1 e1 06          	shl    r9,0x6
    14c3:	49 01 c1             	add    r9,rax
    14c6:	49 89 fa             	mov    r10,rdi
    14c9:	49 c1 ea 02          	shr    r10,0x2
    14cd:	4d 01 d1             	add    r9,r10
    14d0:	49 ff c1             	inc    r9
    14d3:	49 31 f9             	xor    r9,rdi
    14d6:	4c 89 cf             	mov    rdi,r9
    14d9:	48 c1 e7 06          	shl    rdi,0x6
    14dd:	48 01 c7             	add    rdi,rax
    14e0:	4d 89 ca             	mov    r10,r9
    14e3:	49 c1 ea 02          	shr    r10,0x2
    14e7:	49 01 fa             	add    r10,rdi
    14ea:	4d 31 ca             	xor    r10,r9
    14ed:	4d 89 d3             	mov    r11,r10
    14f0:	49 c1 e3 06          	shl    r11,0x6
    14f4:	49 01 f3             	add    r11,rsi
    14f7:	49 01 c3             	add    r11,rax
    14fa:	4d 89 d1             	mov    r9,r10
    14fd:	49 c1 e9 02          	shr    r9,0x2
    1501:	4d 01 d9             	add    r9,r11
    1504:	66 41 c1 c0 08       	rol    r8w,0x8
    1509:	41 c1 e0 10          	shl    r8d,0x10
    150d:	81 e2 00 00 ff ff    	and    edx,0xffff0000
    1513:	44 31 c2             	xor    edx,r8d
    1516:	89 f7                	mov    edi,esi
    1518:	83 c7 14             	add    edi,0x14
    151b:	66 c1 c7 08          	rol    di,0x8
    151f:	45 0f b6 c4          	movzx  r8d,r12b
    1523:	0f b7 ff             	movzx  edi,di
    1526:	41 89 d3             	mov    r11d,edx
    1529:	41 c1 eb 10          	shr    r11d,0x10
    152d:	4c 01 c7             	add    rdi,r8
    1530:	4c 01 df             	add    rdi,r11
    1533:	48 81 c7 3b df 00 00 	add    rdi,0xdf3b
    153a:	41 89 f8             	mov    r8d,edi
    153d:	41 c1 e8 10          	shr    r8d,0x10
    1541:	44 0f b7 df          	movzx  r11d,di
    1545:	4d 01 c3             	add    r11,r8
    1548:	48 81 ff 00 00 01 00 	cmp    rdi,0x10000
    154f:	4c 0f 42 df          	cmovb  r11,rdi
    1553:	44 89 df             	mov    edi,r11d
    1556:	c1 ef 10             	shr    edi,0x10
    1559:	45 0f b7 c3          	movzx  r8d,r11w
    155d:	49 01 f8             	add    r8,rdi
    1560:	49 81 fb 00 00 01 00 	cmp    r11,0x10000
    1567:	4d 0f 42 c3          	cmovb  r8,r11
    156b:	44 89 c7             	mov    edi,r8d
    156e:	c1 ef 10             	shr    edi,0x10
    1571:	45 0f b7 d8          	movzx  r11d,r8w
    1575:	49 01 fb             	add    r11,rdi
    1578:	49 81 f8 00 00 01 00 	cmp    r8,0x10000
    157f:	4d 0f 42 d8          	cmovb  r11,r8
    1583:	44 89 df             	mov    edi,r11d
    1586:	c1 ef 10             	shr    edi,0x10
    1589:	44 01 df             	add    edi,r11d
    158c:	4d 31 d1             	xor    r9,r10
    158f:	81 ca ac 10 00 00    	or     edx,0x10ac
    1595:	48 c1 e2 20          	shl    rdx,0x20
    1599:	48 81 ca 0a c8 00 02 	or     rdx,0x200c80a
    15a0:	49 81 fb 00 00 01 00 	cmp    r11,0x10000
    15a7:	41 0f 42 fb          	cmovb  edi,r11d
    15ab:	c1 e7 10             	shl    edi,0x10
    15ae:	48 31 f2             	xor    rdx,rsi
    15b1:	48 be 0b 00 ff ff 00 	movabs rsi,0x200ffff000b
    15b8:	02 00 00 
    15bb:	48 31 d6             	xor    rsi,rdx
    15be:	48 31 fe             	xor    rsi,rdi
    15c1:	4c 89 ca             	mov    rdx,r9
    15c4:	48 c1 e2 06          	shl    rdx,0x6
    15c8:	4c 89 cf             	mov    rdi,r9
    15cb:	48 c1 ef 02          	shr    rdi,0x2
    15cf:	48 01 f7             	add    rdi,rsi
    15d2:	48 01 c2             	add    rdx,rax
    15d5:	48 01 fa             	add    rdx,rdi
    15d8:	4c 31 ca             	xor    rdx,r9
    15db:	e9 95 02 00 00       	jmp    1875 <katran_lb_consistent_hash_select_xdp+0x775>
    15e0:	4c 8d 61 32          	lea    r12,[rcx+0x32]
    15e4:	49 39 dc             	cmp    r12,rbx
    15e7:	76 36                	jbe    161f <katran_lb_consistent_hash_select_xdp+0x51f>
    15e9:	be 01 00 00 00       	mov    esi,0x1
    15ee:	48 89 f2             	mov    rdx,rsi
    15f1:	48 c1 e2 06          	shl    rdx,0x6
    15f5:	48 89 f7             	mov    rdi,rsi
    15f8:	48 c1 ef 02          	shr    rdi,0x2
    15fc:	4c 01 cf             	add    rdi,r9
    15ff:	48 01 c2             	add    rdx,rax
    1602:	48 01 fa             	add    rdx,rdi
    1605:	48 31 f2             	xor    rdx,rsi
    1608:	48 89 11             	mov    QWORD PTR [rcx],rdx
    160b:	b8 02 00 00 00       	mov    eax,0x2
    1610:	48 83 c4 08          	add    rsp,0x8
    1614:	5b                   	pop    rbx
    1615:	41 5c                	pop    r12
    1617:	41 5d                	pop    r13
    1619:	41 5e                	pop    r14
    161b:	41 5f                	pop    r15
    161d:	5d                   	pop    rbp
    161e:	c3                   	ret
    161f:	41 81 ff 0a 64 01 01 	cmp    r15d,0x101640a
    1626:	0f 85 07 fc ff ff    	jne    1233 <katran_lb_consistent_hash_select_xdp+0x133>
    162c:	44 0f b7 49 2c       	movzx  r9d,WORD PTR [rcx+0x2c]
    1631:	41 81 f9 1f 90 00 00 	cmp    r9d,0x901f
    1638:	0f 85 f5 fb ff ff    	jne    1233 <katran_lb_consistent_hash_select_xdp+0x133>
    163e:	41 b9 02 00 00 00    	mov    r9d,0x2
    1644:	41 80 fe 06          	cmp    r14b,0x6
    1648:	75 a4                	jne    15ee <katran_lb_consistent_hash_select_xdp+0x4ee>
    164a:	be 01 00 00 00       	mov    esi,0x1
    164f:	41 b9 01 00 00 00    	mov    r9d,0x1
    1655:	49 81 fa ea 05 00 00 	cmp    r10,0x5ea
    165c:	7f 90                	jg     15ee <katran_lb_consistent_hash_select_xdp+0x4ee>
    165e:	66 c1 c5 08          	rol    bp,0x8
    1662:	0f b7 f5             	movzx  esi,bp
    1665:	41 c1 e0 10          	shl    r8d,0x10
    1669:	c1 e2 18             	shl    edx,0x18
    166c:	45 09 c3             	or     r11d,r8d
    166f:	41 09 d3             	or     r11d,edx
    1672:	44 0f b7 49 2a       	movzx  r9d,WORD PTR [rcx+0x2a]
    1677:	44 89 cb             	mov    ebx,r9d
    167a:	81 c3 f7 c0 cc 70    	add    ebx,0x70ccc0f7
    1680:	41 89 da             	mov    r10d,ebx
    1683:	41 81 f2 f7 c0 ad e0 	xor    r10d,0xe0adc0f7
    168a:	bd 00 00 cc 70       	mov    ebp,0x70cc0000
    168f:	0f ac dd 12          	shrd   ebp,ebx,0x12
    1693:	41 29 ea             	sub    r10d,ebp
    1696:	41 8d ab f7 c0 ad e0 	lea    ebp,[r11-0x1f523f09]
    169d:	44 31 d5             	xor    ebp,r10d
    16a0:	45 89 d6             	mov    r14d,r10d
    16a3:	41 c1 c6 0b          	rol    r14d,0xb
    16a7:	44 29 f5             	sub    ebp,r14d
    16aa:	41 89 ee             	mov    r14d,ebp
    16ad:	41 c1 c6 19          	rol    r14d,0x19
    16b1:	31 eb                	xor    ebx,ebp
    16b3:	44 29 f3             	sub    ebx,r14d
    16b6:	41 31 da             	xor    r10d,ebx
    16b9:	41 89 de             	mov    r14d,ebx
    16bc:	41 c1 c6 10          	rol    r14d,0x10
    16c0:	45 29 f2             	sub    r10d,r14d
    16c3:	44 31 d5             	xor    ebp,r10d
    16c6:	45 89 d6             	mov    r14d,r10d
    16c9:	41 c1 c6 04          	rol    r14d,0x4
    16cd:	44 29 f5             	sub    ebp,r14d
    16d0:	31 eb                	xor    ebx,ebp
    16d2:	c1 c5 0e             	rol    ebp,0xe
    16d5:	29 eb                	sub    ebx,ebp
    16d7:	41 31 da             	xor    r10d,ebx
    16da:	c1 c3 18             	rol    ebx,0x18
    16dd:	41 29 da             	sub    r10d,ebx
    16e0:	bb 01 00 ff ff       	mov    ebx,0xffff0001
    16e5:	49 0f af da          	imul   rbx,r10
    16e9:	48 c1 eb 30          	shr    rbx,0x30
    16ed:	89 dd                	mov    ebp,ebx
    16ef:	c1 e5 10             	shl    ebp,0x10
    16f2:	09 dd                	or     ebp,ebx
    16f4:	41 29 ea             	sub    r10d,ebp
    16f7:	45 89 db             	mov    r11d,r11d
    16fa:	49 01 c3             	add    r11,rax
    16fd:	4c 89 db             	mov    rbx,r11
    1700:	48 c1 e3 06          	shl    rbx,0x6
    1704:	4d 89 de             	mov    r14,r11
    1707:	49 c1 ee 02          	shr    r14,0x2
    170b:	49 01 c6             	add    r14,rax
    170e:	4c 01 f3             	add    rbx,r14
    1711:	48 81 c3 0a 64 01 01 	add    rbx,0x101640a
    1718:	4c 31 db             	xor    rbx,r11
    171b:	49 89 db             	mov    r11,rbx
    171e:	49 c1 e3 06          	shl    r11,0x6
    1722:	49 89 de             	mov    r14,rbx
    1725:	49 c1 ee 02          	shr    r14,0x2
    1729:	4d 01 ce             	add    r14,r9
    172c:	49 01 c3             	add    r11,rax
    172f:	4d 01 f3             	add    r11,r14
    1732:	41 be 00 00 1f 90    	mov    r14d,0x901f0000
    1738:	4d 01 de             	add    r14,r11
    173b:	49 31 de             	xor    r14,rbx
    173e:	4d 89 f3             	mov    r11,r14
    1741:	49 c1 e3 06          	shl    r11,0x6
    1745:	4c 89 f3             	mov    rbx,r14
    1748:	48 c1 eb 02          	shr    rbx,0x2
    174c:	49 01 c3             	add    r11,rax
    174f:	49 01 db             	add    r11,rbx
    1752:	4d 01 d3             	add    r11,r10
    1755:	4d 31 f3             	xor    r11,r14
    1758:	4d 89 da             	mov    r10,r11
    175b:	49 c1 e2 06          	shl    r10,0x6
    175f:	49 01 c2             	add    r10,rax
    1762:	4c 89 db             	mov    rbx,r11
    1765:	48 c1 eb 02          	shr    rbx,0x2
    1769:	49 01 da             	add    r10,rbx
    176c:	49 ff c2             	inc    r10
    176f:	4d 31 da             	xor    r10,r11
    1772:	4c 89 d3             	mov    rbx,r10
    1775:	48 c1 e3 06          	shl    rbx,0x6
    1779:	48 01 c3             	add    rbx,rax
    177c:	4d 89 d3             	mov    r11,r10
    177f:	49 c1 eb 02          	shr    r11,0x2
    1783:	49 01 db             	add    r11,rbx
    1786:	4d 31 d3             	xor    r11,r10
    1789:	4c 89 db             	mov    rbx,r11
    178c:	48 c1 e3 06          	shl    rbx,0x6
    1790:	48 01 f3             	add    rbx,rsi
    1793:	48 01 c3             	add    rbx,rax
    1796:	4d 89 da             	mov    r10,r11
    1799:	49 c1 ea 02          	shr    r10,0x2
    179d:	66 41 c1 c1 08       	rol    r9w,0x8
    17a2:	49 01 da             	add    r10,rbx
    17a5:	41 c1 e1 10          	shl    r9d,0x10
    17a9:	44 09 c2             	or     edx,r8d
    17ac:	44 31 ca             	xor    edx,r9d
    17af:	41 89 f0             	mov    r8d,esi
    17b2:	41 83 c0 14          	add    r8d,0x14
    17b6:	66 41 c1 c0 08       	rol    r8w,0x8
    17bb:	45 0f b7 c0          	movzx  r8d,r8w
    17bf:	41 89 d1             	mov    r9d,edx
    17c2:	41 c1 e9 10          	shr    r9d,0x10
    17c6:	49 01 f8             	add    r8,rdi
    17c9:	4b 8d 3c 01          	lea    rdi,[r9+r8*1]
    17cd:	48 81 c7 3b df 00 00 	add    rdi,0xdf3b
    17d4:	41 89 f8             	mov    r8d,edi
    17d7:	41 c1 e8 10          	shr    r8d,0x10
    17db:	44 0f b7 cf          	movzx  r9d,di
    17df:	4d 01 c1             	add    r9,r8
    17e2:	48 81 ff 00 00 01 00 	cmp    rdi,0x10000
    17e9:	4c 0f 42 cf          	cmovb  r9,rdi
    17ed:	44 89 cf             	mov    edi,r9d
    17f0:	c1 ef 10             	shr    edi,0x10
    17f3:	45 0f b7 c1          	movzx  r8d,r9w
    17f7:	49 01 f8             	add    r8,rdi
    17fa:	49 81 f9 00 00 01 00 	cmp    r9,0x10000
    1801:	4d 0f 42 c1          	cmovb  r8,r9
    1805:	44 89 c7             	mov    edi,r8d
    1808:	c1 ef 10             	shr    edi,0x10
    180b:	45 0f b7 c8          	movzx  r9d,r8w
    180f:	49 01 f9             	add    r9,rdi
    1812:	49 81 f8 00 00 01 00 	cmp    r8,0x10000
    1819:	4d 0f 42 c8          	cmovb  r9,r8
    181d:	44 89 cf             	mov    edi,r9d
    1820:	c1 ef 10             	shr    edi,0x10
    1823:	44 01 cf             	add    edi,r9d
    1826:	4d 31 da             	xor    r10,r11
    1829:	81 ca ac 10 00 00    	or     edx,0x10ac
    182f:	48 c1 e2 20          	shl    rdx,0x20
    1833:	48 81 ca 0a c8 00 02 	or     rdx,0x200c80a
    183a:	49 81 f9 00 00 01 00 	cmp    r9,0x10000
    1841:	41 0f 42 f9          	cmovb  edi,r9d
    1845:	c1 e7 10             	shl    edi,0x10
    1848:	48 31 f2             	xor    rdx,rsi
    184b:	48 be 0b 00 ff ff 00 	movabs rsi,0x200ffff000b
    1852:	02 00 00 
    1855:	48 31 d6             	xor    rsi,rdx
    1858:	48 31 fe             	xor    rsi,rdi
    185b:	4c 89 d2             	mov    rdx,r10
    185e:	48 c1 e2 06          	shl    rdx,0x6
    1862:	4c 89 d7             	mov    rdi,r10
    1865:	48 c1 ef 02          	shr    rdi,0x2
    1869:	48 01 f7             	add    rdi,rsi
    186c:	48 01 c2             	add    rdx,rax
    186f:	48 01 fa             	add    rdx,rdi
    1872:	4c 31 d2             	xor    rdx,r10
    1875:	48 89 d6             	mov    rsi,rdx
    1878:	48 c1 e6 06          	shl    rsi,0x6
    187c:	48 01 c6             	add    rsi,rax
    187f:	48 89 d7             	mov    rdi,rdx
    1882:	48 c1 ef 02          	shr    rdi,0x2
    1886:	48 01 fe             	add    rsi,rdi
    1889:	48 83 c6 03          	add    rsi,0x3
    188d:	48 31 d6             	xor    rsi,rdx
    1890:	41 b9 03 00 00 00    	mov    r9d,0x3
    1896:	e9 53 fd ff ff       	jmp    15ee <katran_lb_consistent_hash_select_xdp+0x4ee>

Disassembly of section .fini:

000000000000189c <_fini>:
    189c:	f3 0f 1e fa          	endbr64
    18a0:	48 83 ec 08          	sub    rsp,0x8
    18a4:	48 83 c4 08          	add    rsp,0x8
    18a8:	c3                   	ret
```

## Original Kernel JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   5:	0f 1f 00             	nop    DWORD PTR [rax]
   8:	55                   	push   rbp
   9:	48 89 e5             	mov    rbp,rsp
   c:	48 81 ec a8 00 00 00 	sub    rsp,0xa8
  13:	53                   	push   rbx
  14:	41 55                	push   r13
  16:	41 56                	push   r14
  18:	41 57                	push   r15
  1a:	31 c0                	xor    eax,eax
  1c:	48 8b 5f 08          	mov    rbx,QWORD PTR [rdi+0x8]
  20:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  24:	48 39 df             	cmp    rdi,rbx
  27:	0f 87 0c 05 00 00    	ja     0x539
  2d:	48 89 f9             	mov    rcx,rdi
  30:	48 83 c1 08          	add    rcx,0x8
  34:	48 39 d9             	cmp    rcx,rbx
  37:	0f 87 fc 04 00 00    	ja     0x539
  3d:	48 89 fa             	mov    rdx,rdi
  40:	48 83 c2 16          	add    rdx,0x16
  44:	48 39 da             	cmp    rdx,rbx
  47:	0f 87 ec 04 00 00    	ja     0x539
  4d:	48 89 de             	mov    rsi,rbx
  50:	48 29 ce             	sub    rsi,rcx
  53:	4c 0f b6 47 14       	movzx  r8,BYTE PTR [rdi+0x14]
  58:	48 0f b6 4f 15       	movzx  rcx,BYTE PTR [rdi+0x15]
  5d:	c1 e1 08             	shl    ecx,0x8
  60:	44 09 c1             	or     ecx,r8d
  63:	81 e1 ff ff 00 00    	and    ecx,0xffff
  69:	81 f9 86 dd 00 00    	cmp    ecx,0xdd86
  6f:	0f 84 e4 03 00 00    	je     0x459
  75:	83 f9 08             	cmp    ecx,0x8
  78:	0f 85 16 04 00 00    	jne    0x494
  7e:	48 89 f9             	mov    rcx,rdi
  81:	48 83 c1 2a          	add    rcx,0x2a
  85:	48 39 d9             	cmp    rcx,rbx
  88:	0f 87 f8 03 00 00    	ja     0x486
  8e:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
  93:	83 e2 0f             	and    edx,0xf
  96:	83 fa 05             	cmp    edx,0x5
  99:	0f 85 e7 03 00 00    	jne    0x486
  9f:	48 0f b6 57 1c       	movzx  rdx,BYTE PTR [rdi+0x1c]
  a4:	83 e2 3f             	and    edx,0x3f
  a7:	48 0f b6 4f 1d       	movzx  rcx,BYTE PTR [rdi+0x1d]
  ac:	09 ca                	or     edx,ecx
  ae:	81 e2 ff 00 00 00    	and    edx,0xff
  b4:	85 d2                	test   edx,edx
  b6:	0f 85 ca 03 00 00    	jne    0x486
  bc:	48 0f b6 57 1f       	movzx  rdx,BYTE PTR [rdi+0x1f]
  c1:	41 bd 02 00 00 00    	mov    r13d,0x2
  c7:	41 bf 02 00 00 00    	mov    r15d,0x2
  cd:	83 fa 01             	cmp    edx,0x1
  d0:	0f 84 f2 03 00 00    	je     0x4c8
  d6:	83 fa 11             	cmp    edx,0x11
  d9:	0f 84 99 0a 00 00    	je     0xb78
  df:	83 fa 06             	cmp    edx,0x6
  e2:	0f 85 e0 03 00 00    	jne    0x4c8
  e8:	48 89 fa             	mov    rdx,rdi
  eb:	48 83 c2 3e          	add    rdx,0x3e
  ef:	41 bd 01 00 00 00    	mov    r13d,0x1
  f5:	41 bf 01 00 00 00    	mov    r15d,0x1
  fb:	48 39 da             	cmp    rdx,rbx
  fe:	0f 87 c4 03 00 00    	ja     0x4c8
 104:	48 0f b6 57 27       	movzx  rdx,BYTE PTR [rdi+0x27]
 109:	c1 e2 08             	shl    edx,0x8
 10c:	48 0f b6 4f 26       	movzx  rcx,BYTE PTR [rdi+0x26]
 111:	09 ca                	or     edx,ecx
 113:	48 0f b6 4f 28       	movzx  rcx,BYTE PTR [rdi+0x28]
 118:	c1 e1 10             	shl    ecx,0x10
 11b:	09 ca                	or     edx,ecx
 11d:	48 0f b6 4f 29       	movzx  rcx,BYTE PTR [rdi+0x29]
 122:	c1 e1 18             	shl    ecx,0x18
 125:	09 ca                	or     edx,ecx
 127:	41 bd 02 00 00 00    	mov    r13d,0x2
 12d:	41 bf 02 00 00 00    	mov    r15d,0x2
 133:	81 fa 0a 64 01 01    	cmp    edx,0x101640a
 139:	0f 85 89 03 00 00    	jne    0x4c8
 13f:	48 0f b6 57 2d       	movzx  rdx,BYTE PTR [rdi+0x2d]
 144:	c1 e2 08             	shl    edx,0x8
 147:	48 0f b6 4f 2c       	movzx  rcx,BYTE PTR [rdi+0x2c]
 14c:	09 ca                	or     edx,ecx
 14e:	81 e2 ff ff 00 00    	and    edx,0xffff
 154:	81 fa 1f 90 00 00    	cmp    edx,0x901f
 15a:	0f 85 68 03 00 00    	jne    0x4c8
 160:	41 bd 01 00 00 00    	mov    r13d,0x1
 166:	41 bf 01 00 00 00    	mov    r15d,0x1
 16c:	48 81 fe ea 05 00 00 	cmp    rsi,0x5ea
 173:	0f 8f 4f 03 00 00    	jg     0x4c8
 179:	48 0f b6 57 18       	movzx  rdx,BYTE PTR [rdi+0x18]
 17e:	c1 e2 08             	shl    edx,0x8
 181:	48 0f b6 77 19       	movzx  rsi,BYTE PTR [rdi+0x19]
 186:	09 f2                	or     edx,esi
 188:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 18c:	4c 0f b6 47 17       	movzx  r8,BYTE PTR [rdi+0x17]
 191:	48 0f b6 4f 23       	movzx  rcx,BYTE PTR [rdi+0x23]
 196:	c1 e1 08             	shl    ecx,0x8
 199:	48 0f b6 77 22       	movzx  rsi,BYTE PTR [rdi+0x22]
 19e:	09 f1                	or     ecx,esi
 1a0:	4c 0f b6 77 24       	movzx  r14,BYTE PTR [rdi+0x24]
 1a5:	41 c1 e6 10          	shl    r14d,0x10
 1a9:	44 09 f1             	or     ecx,r14d
 1ac:	48 0f b6 77 25       	movzx  rsi,BYTE PTR [rdi+0x25]
 1b1:	c1 e6 18             	shl    esi,0x18
 1b4:	09 f1                	or     ecx,esi
 1b6:	48 0f b6 47 2a       	movzx  rax,BYTE PTR [rdi+0x2a]
 1bb:	48 0f b6 57 2b       	movzx  rdx,BYTE PTR [rdi+0x2b]
 1c0:	c1 e2 08             	shl    edx,0x8
 1c3:	09 c2                	or     edx,eax
 1c5:	89 d0                	mov    eax,edx
 1c7:	25 ff ff 00 00       	and    eax,0xffff
 1cc:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
 1d0:	89 c3                	mov    ebx,eax
 1d2:	81 c3 f7 c0 cc 70    	add    ebx,0x70ccc0f7
 1d8:	89 5d e0             	mov    DWORD PTR [rbp-0x20],ebx
 1db:	89 d8                	mov    eax,ebx
 1dd:	c1 e0 0e             	shl    eax,0xe
 1e0:	0d 33 1c 00 00       	or     eax,0x1c33
 1e5:	81 f3 f7 c0 ad e0    	xor    ebx,0xe0adc0f7
 1eb:	29 c3                	sub    ebx,eax
 1ed:	48 b8 15 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c15
 1f4:	79 37 9e 
 1f7:	49 89 cd             	mov    r13,rcx
 1fa:	49 01 c5             	add    r13,rax
 1fd:	4c 89 6d f0          	mov    QWORD PTR [rbp-0x10],r13
 201:	4c 89 e8             	mov    rax,r13
 204:	48 c1 e0 06          	shl    rax,0x6
 208:	49 c1 ed 02          	shr    r13,0x2
 20c:	49 01 c5             	add    r13,rax
 20f:	89 d8                	mov    eax,ebx
 211:	c1 e8 15             	shr    eax,0x15
 214:	41 89 df             	mov    r15d,ebx
 217:	41 c1 e7 0b          	shl    r15d,0xb
 21b:	41 09 c7             	or     r15d,eax
 21e:	44 09 f6             	or     esi,r14d
 221:	81 c1 f7 c0 ad e0    	add    ecx,0xe0adc0f7
 227:	89 d8                	mov    eax,ebx
 229:	31 c8                	xor    eax,ecx
 22b:	44 29 f8             	sub    eax,r15d
 22e:	89 c1                	mov    ecx,eax
 230:	c1 e9 07             	shr    ecx,0x7
 233:	41 89 c6             	mov    r14d,eax
 236:	41 c1 e6 19          	shl    r14d,0x19
 23a:	41 09 ce             	or     r14d,ecx
 23d:	48 b9 1f e0 4b 80 b9 	movabs rcx,0x9e3779b9804be01f
 244:	79 37 9e 
 247:	49 01 cd             	add    r13,rcx
 24a:	0f ca                	bswap  edx
 24c:	81 e2 00 00 ff ff    	and    edx,0xffff0000
 252:	31 f2                	xor    edx,esi
 254:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 258:	83 c6 14             	add    esi,0x14
 25b:	66 c1 ce 08          	ror    si,0x8
 25f:	0f b7 f6             	movzx  esi,si
 262:	49 01 f0             	add    r8,rsi
 265:	89 c1                	mov    ecx,eax
 267:	8b 75 e0             	mov    esi,DWORD PTR [rbp-0x20]
 26a:	31 f1                	xor    ecx,esi
 26c:	44 29 f1             	sub    ecx,r14d
 26f:	89 ce                	mov    esi,ecx
 271:	c1 ee 10             	shr    esi,0x10
 274:	41 89 ce             	mov    r14d,ecx
 277:	41 c1 e6 10          	shl    r14d,0x10
 27b:	41 09 f6             	or     r14d,esi
 27e:	89 4d e0             	mov    DWORD PTR [rbp-0x20],ecx
 281:	31 d9                	xor    ecx,ebx
 283:	44 29 f1             	sub    ecx,r14d
 286:	89 d6                	mov    esi,edx
 288:	c1 ee 10             	shr    esi,0x10
 28b:	49 01 f0             	add    r8,rsi
 28e:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 292:	49 31 f5             	xor    r13,rsi
 295:	4d 89 ee             	mov    r14,r13
 298:	49 c1 ee 02          	shr    r14,0x2
 29c:	4c 89 eb             	mov    rbx,r13
 29f:	48 c1 e3 06          	shl    rbx,0x6
 2a3:	41 89 cf             	mov    r15d,ecx
 2a6:	41 c1 ef 1c          	shr    r15d,0x1c
 2aa:	89 4d f0             	mov    DWORD PTR [rbp-0x10],ecx
 2ad:	89 ce                	mov    esi,ecx
 2af:	c1 e6 04             	shl    esi,0x4
 2b2:	44 09 fe             	or     esi,r15d
 2b5:	49 81 c0 3b df 00 00 	add    r8,0xdf3b
 2bc:	49 81 f8 00 00 01 00 	cmp    r8,0x10000
 2c3:	72 11                	jb     0x2d6
 2c5:	4d 89 c7             	mov    r15,r8
 2c8:	49 c1 ef 10          	shr    r15,0x10
 2cc:	49 81 e0 ff ff 00 00 	and    r8,0xffff
 2d3:	4d 01 f8             	add    r8,r15
 2d6:	4c 01 f3             	add    rbx,r14
 2d9:	8b 4d f0             	mov    ecx,DWORD PTR [rbp-0x10]
 2dc:	41 89 cf             	mov    r15d,ecx
 2df:	41 31 c7             	xor    r15d,eax
 2e2:	41 29 f7             	sub    r15d,esi
 2e5:	49 81 f8 00 00 01 00 	cmp    r8,0x10000
 2ec:	72 11                	jb     0x2ff
 2ee:	4c 89 c6             	mov    rsi,r8
 2f1:	48 c1 ee 10          	shr    rsi,0x10
 2f5:	49 81 e0 ff ff 00 00 	and    r8,0xffff
 2fc:	49 01 f0             	add    r8,rsi
 2ff:	48 8b 75 e8          	mov    rsi,QWORD PTR [rbp-0x18]
 303:	81 ce 00 00 1f 90    	or     esi,0x901f0000
 309:	48 01 f3             	add    rbx,rsi
 30c:	48 be 15 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c15
 313:	79 37 9e 
 316:	48 01 f3             	add    rbx,rsi
 319:	4c 31 eb             	xor    rbx,r13
 31c:	44 89 fe             	mov    esi,r15d
 31f:	c1 ee 12             	shr    esi,0x12
 322:	45 89 fd             	mov    r13d,r15d
 325:	41 c1 e5 0e          	shl    r13d,0xe
 329:	41 09 f5             	or     r13d,esi
 32c:	8b 75 e0             	mov    esi,DWORD PTR [rbp-0x20]
 32f:	41 31 f7             	xor    r15d,esi
 332:	48 89 de             	mov    rsi,rbx
 335:	48 c1 ee 02          	shr    rsi,0x2
 339:	48 89 d8             	mov    rax,rbx
 33c:	48 c1 e0 06          	shl    rax,0x6
 340:	48 01 f0             	add    rax,rsi
 343:	45 29 ef             	sub    r15d,r13d
 346:	44 89 fe             	mov    esi,r15d
 349:	c1 ee 08             	shr    esi,0x8
 34c:	44 89 f9             	mov    ecx,r15d
 34f:	c1 e1 18             	shl    ecx,0x18
 352:	09 f1                	or     ecx,esi
 354:	8b 75 f0             	mov    esi,DWORD PTR [rbp-0x10]
 357:	41 31 f7             	xor    r15d,esi
 35a:	41 29 cf             	sub    r15d,ecx
 35d:	be 01 00 ff ff       	mov    esi,0xffff0001
 362:	4c 89 f9             	mov    rcx,r15
 365:	48 0f af ce          	imul   rcx,rsi
 369:	48 c1 e9 30          	shr    rcx,0x30
 36d:	69 c9 01 00 01 00    	imul   ecx,ecx,0x10001
 373:	41 29 cf             	sub    r15d,ecx
 376:	4c 01 f8             	add    rax,r15
 379:	49 bd 15 7c 4a 7f b9 	movabs r13,0x9e3779b97f4a7c15
 380:	79 37 9e 
 383:	4c 01 e8             	add    rax,r13
 386:	48 31 d8             	xor    rax,rbx
 389:	81 ca ac 10 00 00    	or     edx,0x10ac
 38f:	48 c1 e2 20          	shl    rdx,0x20
 393:	48 81 ca 0a c8 00 02 	or     rdx,0x200c80a
 39a:	49 c1 e0 10          	shl    r8,0x10
 39e:	49 c1 e0 20          	shl    r8,0x20
 3a2:	49 c1 e8 20          	shr    r8,0x20
 3a6:	4c 31 c2             	xor    rdx,r8
 3a9:	48 89 c1             	mov    rcx,rax
 3ac:	48 c1 e9 02          	shr    rcx,0x2
 3b0:	48 89 c6             	mov    rsi,rax
 3b3:	48 c1 e6 06          	shl    rsi,0x6
 3b7:	48 01 ce             	add    rsi,rcx
 3ba:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 3be:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 3c5:	48 31 da             	xor    rdx,rbx
 3c8:	48 b9 0b 00 ff ff 00 	movabs rcx,0x200ffff000b
 3cf:	02 00 00 
 3d2:	48 31 ca             	xor    rdx,rcx
 3d5:	48 b9 16 7c 4a 7f b9 	movabs rcx,0x9e3779b97f4a7c16
 3dc:	79 37 9e 
 3df:	48 01 ce             	add    rsi,rcx
 3e2:	48 31 c6             	xor    rsi,rax
 3e5:	48 89 f1             	mov    rcx,rsi
 3e8:	48 c1 e9 02          	shr    rcx,0x2
 3ec:	49 89 f0             	mov    r8,rsi
 3ef:	49 c1 e0 06          	shl    r8,0x6
 3f3:	49 01 c8             	add    r8,rcx
 3f6:	4d 01 e8             	add    r8,r13
 3f9:	49 31 f0             	xor    r8,rsi
 3fc:	4c 89 c6             	mov    rsi,r8
 3ff:	48 c1 e6 06          	shl    rsi,0x6
 403:	48 01 f3             	add    rbx,rsi
 406:	4c 89 c6             	mov    rsi,r8
 409:	48 c1 ee 02          	shr    rsi,0x2
 40d:	48 01 f3             	add    rbx,rsi
 410:	4c 01 eb             	add    rbx,r13
 413:	4c 31 c3             	xor    rbx,r8
 416:	48 89 de             	mov    rsi,rbx
 419:	48 c1 ee 02          	shr    rsi,0x2
 41d:	48 89 d9             	mov    rcx,rbx
 420:	48 c1 e1 06          	shl    rcx,0x6
 424:	48 01 f1             	add    rcx,rsi
 427:	48 01 d1             	add    rcx,rdx
 42a:	4c 01 e9             	add    rcx,r13
 42d:	48 31 d9             	xor    rcx,rbx
 430:	48 89 ce             	mov    rsi,rcx
 433:	48 c1 ee 02          	shr    rsi,0x2
 437:	49 89 cd             	mov    r13,rcx
 43a:	49 c1 e5 06          	shl    r13,0x6
 43e:	49 01 f5             	add    r13,rsi
 441:	48 be 18 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c18
 448:	79 37 9e 
 44b:	49 01 f5             	add    r13,rsi
 44e:	49 31 cd             	xor    r13,rcx
 451:	41 bf 03 00 00 00    	mov    r15d,0x3
 457:	eb 6f                	jmp    0x4c8
 459:	48 89 fa             	mov    rdx,rdi
 45c:	48 83 c2 3e          	add    rdx,0x3e
 460:	48 39 da             	cmp    rdx,rbx
 463:	77 21                	ja     0x486
 465:	4c 0f b6 77 1c       	movzx  r14,BYTE PTR [rdi+0x1c]
 46a:	41 bd 02 00 00 00    	mov    r13d,0x2
 470:	41 bf 02 00 00 00    	mov    r15d,0x2
 476:	41 83 fe 3a          	cmp    r14d,0x3a
 47a:	74 4c                	je     0x4c8
 47c:	41 83 fe 2c          	cmp    r14d,0x2c
 480:	0f 85 bc 00 00 00    	jne    0x542
 486:	41 bd 01 00 00 00    	mov    r13d,0x1
 48c:	41 bf 01 00 00 00    	mov    r15d,0x1
 492:	eb 34                	jmp    0x4c8
 494:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 49b:	79 37 9e 
 49e:	48 01 d6             	add    rsi,rdx
 4a1:	48 89 f2             	mov    rdx,rsi
 4a4:	48 c1 ea 02          	shr    rdx,0x2
 4a8:	49 89 f5             	mov    r13,rsi
 4ab:	49 c1 e5 06          	shl    r13,0x6
 4af:	49 01 d5             	add    r13,rdx
 4b2:	48 ba 17 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c17
 4b9:	79 37 9e 
 4bc:	49 01 d5             	add    r13,rdx
 4bf:	49 31 f5             	xor    r13,rsi
 4c2:	41 bf 02 00 00 00    	mov    r15d,0x2
 4c8:	4c 89 ea             	mov    rdx,r13
 4cb:	48 c1 ea 02          	shr    rdx,0x2
 4cf:	4c 89 ee             	mov    rsi,r13
 4d2:	48 c1 e6 06          	shl    rsi,0x6
 4d6:	48 01 d6             	add    rsi,rdx
 4d9:	4c 01 fe             	add    rsi,r15
 4dc:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 4e3:	79 37 9e 
 4e6:	48 01 d6             	add    rsi,rdx
 4e9:	4c 31 ee             	xor    rsi,r13
 4ec:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
 4f0:	48 89 f2             	mov    rdx,rsi
 4f3:	48 c1 ea 38          	shr    rdx,0x38
 4f7:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 4fa:	48 89 f2             	mov    rdx,rsi
 4fd:	48 c1 ea 30          	shr    rdx,0x30
 501:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 504:	48 89 f2             	mov    rdx,rsi
 507:	48 c1 ea 28          	shr    rdx,0x28
 50b:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 50e:	48 89 f2             	mov    rdx,rsi
 511:	48 c1 ea 20          	shr    rdx,0x20
 515:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 518:	48 89 f2             	mov    rdx,rsi
 51b:	48 c1 ea 18          	shr    rdx,0x18
 51f:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
 522:	48 89 f2             	mov    rdx,rsi
 525:	48 c1 ea 10          	shr    rdx,0x10
 529:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
 52c:	48 c1 ee 08          	shr    rsi,0x8
 530:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
 534:	b8 02 00 00 00       	mov    eax,0x2
 539:	41 5f                	pop    r15
 53b:	41 5e                	pop    r14
 53d:	41 5d                	pop    r13
 53f:	5b                   	pop    rbx
 540:	c9                   	leave
 541:	c3                   	ret
 542:	48 0f b6 57 1a       	movzx  rdx,BYTE PTR [rdi+0x1a]
 547:	48 89 55 f0          	mov    QWORD PTR [rbp-0x10],rdx
 54b:	48 0f b6 57 1b       	movzx  rdx,BYTE PTR [rdi+0x1b]
 550:	89 95 58 ff ff ff    	mov    DWORD PTR [rbp-0xa8],edx
 556:	48 0f b6 57 16       	movzx  rdx,BYTE PTR [rdi+0x16]
 55b:	48 89 55 a0          	mov    QWORD PTR [rbp-0x60],rdx
 55f:	48 0f b6 57 17       	movzx  rdx,BYTE PTR [rdi+0x17]
 564:	89 95 60 ff ff ff    	mov    DWORD PTR [rbp-0xa0],edx
 56a:	48 0f b6 57 23       	movzx  rdx,BYTE PTR [rdi+0x23]
 56f:	89 55 a8             	mov    DWORD PTR [rbp-0x58],edx
 572:	48 0f b6 57 22       	movzx  rdx,BYTE PTR [rdi+0x22]
 577:	89 95 68 ff ff ff    	mov    DWORD PTR [rbp-0x98],edx
 57d:	48 0f b6 57 27       	movzx  rdx,BYTE PTR [rdi+0x27]
 582:	89 55 b8             	mov    DWORD PTR [rbp-0x48],edx
 585:	48 0f b6 57 26       	movzx  rdx,BYTE PTR [rdi+0x26]
 58a:	89 95 70 ff ff ff    	mov    DWORD PTR [rbp-0x90],edx
 590:	48 0f b6 57 28       	movzx  rdx,BYTE PTR [rdi+0x28]
 595:	89 95 78 ff ff ff    	mov    DWORD PTR [rbp-0x88],edx
 59b:	48 0f b6 57 24       	movzx  rdx,BYTE PTR [rdi+0x24]
 5a0:	89 55 80             	mov    DWORD PTR [rbp-0x80],edx
 5a3:	48 0f b6 57 1f       	movzx  rdx,BYTE PTR [rdi+0x1f]
 5a8:	48 89 55 b0          	mov    QWORD PTR [rbp-0x50],rdx
 5ac:	48 0f b6 57 1e       	movzx  rdx,BYTE PTR [rdi+0x1e]
 5b1:	89 55 88             	mov    DWORD PTR [rbp-0x78],edx
 5b4:	48 0f b6 57 25       	movzx  rdx,BYTE PTR [rdi+0x25]
 5b9:	89 55 90             	mov    DWORD PTR [rbp-0x70],edx
 5bc:	48 0f b6 57 29       	movzx  rdx,BYTE PTR [rdi+0x29]
 5c1:	89 55 98             	mov    DWORD PTR [rbp-0x68],edx
 5c4:	48 0f b6 57 2a       	movzx  rdx,BYTE PTR [rdi+0x2a]
 5c9:	89 55 c0             	mov    DWORD PTR [rbp-0x40],edx
 5cc:	48 0f b6 57 2e       	movzx  rdx,BYTE PTR [rdi+0x2e]
 5d1:	89 55 e8             	mov    DWORD PTR [rbp-0x18],edx
 5d4:	48 0f b6 57 2b       	movzx  rdx,BYTE PTR [rdi+0x2b]
 5d9:	89 55 d8             	mov    DWORD PTR [rbp-0x28],edx
 5dc:	48 0f b6 57 2c       	movzx  rdx,BYTE PTR [rdi+0x2c]
 5e1:	89 55 d0             	mov    DWORD PTR [rbp-0x30],edx
 5e4:	48 0f b6 57 2d       	movzx  rdx,BYTE PTR [rdi+0x2d]
 5e9:	89 55 e0             	mov    DWORD PTR [rbp-0x20],edx
 5ec:	48 0f b6 47 2f       	movzx  rax,BYTE PTR [rdi+0x2f]
 5f1:	4c 0f b6 47 30       	movzx  r8,BYTE PTR [rdi+0x30]
 5f6:	48 0f b6 57 31       	movzx  rdx,BYTE PTR [rdi+0x31]
 5fb:	48 0f b6 4f 20       	movzx  rcx,BYTE PTR [rdi+0x20]
 600:	89 4d f8             	mov    DWORD PTR [rbp-0x8],ecx
 603:	48 0f b6 4f 21       	movzx  rcx,BYTE PTR [rdi+0x21]
 608:	89 4d c8             	mov    DWORD PTR [rbp-0x38],ecx
 60b:	41 83 fe 11          	cmp    r14d,0x11
 60f:	74 28                	je     0x639
 611:	41 83 fe 06          	cmp    r14d,0x6
 615:	0f 85 ad fe ff ff    	jne    0x4c8
 61b:	41 bd 01 00 00 00    	mov    r13d,0x1
 621:	48 89 f9             	mov    rcx,rdi
 624:	48 83 c1 52          	add    rcx,0x52
 628:	41 bf 01 00 00 00    	mov    r15d,0x1
 62e:	48 39 d9             	cmp    rcx,rbx
 631:	0f 87 91 fe ff ff    	ja     0x4c8
 637:	eb 1c                	jmp    0x655
 639:	41 bd 01 00 00 00    	mov    r13d,0x1
 63f:	48 89 f9             	mov    rcx,rdi
 642:	48 83 c1 46          	add    rcx,0x46
 646:	41 bf 01 00 00 00    	mov    r15d,0x1
 64c:	48 39 d9             	cmp    rcx,rbx
 64f:	0f 87 73 fe ff ff    	ja     0x4c8
 655:	41 bd 02 00 00 00    	mov    r13d,0x2
 65b:	41 bf 02 00 00 00    	mov    r15d,0x2
 661:	41 83 fe 06          	cmp    r14d,0x6
 665:	0f 85 5d fe ff ff    	jne    0x4c8
 66b:	c1 e0 08             	shl    eax,0x8
 66e:	41 c1 e0 10          	shl    r8d,0x10
 672:	c1 e2 18             	shl    edx,0x18
 675:	44 09 c2             	or     edx,r8d
 678:	09 c2                	or     edx,eax
 67a:	8b 4d e8             	mov    ecx,DWORD PTR [rbp-0x18]
 67d:	09 ca                	or     edx,ecx
 67f:	81 fa 0a 64 01 01    	cmp    edx,0x101640a
 685:	0f 85 3d fe ff ff    	jne    0x4c8
 68b:	48 0f b6 57 41       	movzx  rdx,BYTE PTR [rdi+0x41]
 690:	c1 e2 08             	shl    edx,0x8
 693:	48 0f b6 4f 40       	movzx  rcx,BYTE PTR [rdi+0x40]
 698:	09 ca                	or     edx,ecx
 69a:	81 e2 ff ff 00 00    	and    edx,0xffff
 6a0:	81 fa 1f 90 00 00    	cmp    edx,0x901f
 6a6:	0f 85 1c fe ff ff    	jne    0x4c8
 6ac:	41 bd 01 00 00 00    	mov    r13d,0x1
 6b2:	41 bf 01 00 00 00    	mov    r15d,0x1
 6b8:	48 81 fe ea 05 00 00 	cmp    rsi,0x5ea
 6bf:	0f 8f 03 fe ff ff    	jg     0x4c8
 6c5:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
 6c9:	c1 e2 08             	shl    edx,0x8
 6cc:	8b b5 58 ff ff ff    	mov    esi,DWORD PTR [rbp-0xa8]
 6d2:	09 f2                	or     edx,esi
 6d4:	48 89 55 f0          	mov    QWORD PTR [rbp-0x10],rdx
 6d8:	48 8b 4d a0          	mov    rcx,QWORD PTR [rbp-0x60]
 6dc:	c1 e1 04             	shl    ecx,0x4
 6df:	8b b5 60 ff ff ff    	mov    esi,DWORD PTR [rbp-0xa0]
 6e5:	c1 ee 04             	shr    esi,0x4
 6e8:	83 e6 0f             	and    esi,0xf
 6eb:	09 f1                	or     ecx,esi
 6ed:	44 8b 75 a8          	mov    r14d,DWORD PTR [rbp-0x58]
 6f1:	41 c1 e6 08          	shl    r14d,0x8
 6f5:	8b b5 68 ff ff ff    	mov    esi,DWORD PTR [rbp-0x98]
 6fb:	41 09 f6             	or     r14d,esi
 6fe:	8b 5d b8             	mov    ebx,DWORD PTR [rbp-0x48]
 701:	c1 e3 08             	shl    ebx,0x8
 704:	8b b5 70 ff ff ff    	mov    esi,DWORD PTR [rbp-0x90]
 70a:	09 f3                	or     ebx,esi
 70c:	8b b5 78 ff ff ff    	mov    esi,DWORD PTR [rbp-0x88]
 712:	c1 e6 10             	shl    esi,0x10
 715:	09 f3                	or     ebx,esi
 717:	8b 75 80             	mov    esi,DWORD PTR [rbp-0x80]
 71a:	c1 e6 10             	shl    esi,0x10
 71d:	41 09 f6             	or     r14d,esi
 720:	4c 8b 7d b0          	mov    r15,QWORD PTR [rbp-0x50]
 724:	41 c1 e7 08          	shl    r15d,0x8
 728:	8b 75 88             	mov    esi,DWORD PTR [rbp-0x78]
 72b:	41 09 f7             	or     r15d,esi
 72e:	8b 75 90             	mov    esi,DWORD PTR [rbp-0x70]
 731:	c1 e6 18             	shl    esi,0x18
 734:	41 09 f6             	or     r14d,esi
 737:	8b 75 98             	mov    esi,DWORD PTR [rbp-0x68]
 73a:	c1 e6 18             	shl    esi,0x18
 73d:	09 f3                	or     ebx,esi
 73f:	8b 75 f8             	mov    esi,DWORD PTR [rbp-0x8]
 742:	c1 e6 10             	shl    esi,0x10
 745:	89 75 f8             	mov    DWORD PTR [rbp-0x8],esi
 748:	41 09 f7             	or     r15d,esi
 74b:	8b 75 c8             	mov    esi,DWORD PTR [rbp-0x38]
 74e:	c1 e6 18             	shl    esi,0x18
 751:	89 75 c8             	mov    DWORD PTR [rbp-0x38],esi
 754:	41 09 f7             	or     r15d,esi
 757:	44 89 f8             	mov    eax,r15d
 75a:	29 d8                	sub    eax,ebx
 75c:	81 c3 ff c0 ad de    	add    ebx,0xdeadc0ff
 762:	41 81 c6 ff c0 ad de 	add    r14d,0xdeadc0ff
 769:	48 0f b6 77 3e       	movzx  rsi,BYTE PTR [rdi+0x3e]
 76e:	48 0f b6 57 3f       	movzx  rdx,BYTE PTR [rdi+0x3f]
 773:	c1 e2 08             	shl    edx,0x8
 776:	09 f2                	or     edx,esi
 778:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
 77c:	89 de                	mov    esi,ebx
 77e:	c1 ee 1c             	shr    esi,0x1c
 781:	89 da                	mov    edx,ebx
 783:	c1 e2 04             	shl    edx,0x4
 786:	09 f2                	or     edx,esi
 788:	31 d0                	xor    eax,edx
 78a:	89 c6                	mov    esi,eax
 78c:	c1 ee 1a             	shr    esi,0x1a
 78f:	89 c2                	mov    edx,eax
 791:	c1 e2 06             	shl    edx,0x6
 794:	09 f2                	or     edx,esi
 796:	45 89 f0             	mov    r8d,r14d
 799:	41 29 c0             	sub    r8d,eax
 79c:	41 31 d0             	xor    r8d,edx
 79f:	44 89 c6             	mov    esi,r8d
 7a2:	c1 ee 18             	shr    esi,0x18
 7a5:	44 89 c2             	mov    edx,r8d
 7a8:	c1 e2 08             	shl    edx,0x8
 7ab:	09 f2                	or     edx,esi
 7ad:	48 81 e1 ff 00 00 00 	and    rcx,0xff
 7b4:	48 8b 75 f0          	mov    rsi,QWORD PTR [rbp-0x10]
 7b8:	83 c6 14             	add    esi,0x14
 7bb:	66 c1 ce 08          	ror    si,0x8
 7bf:	0f b7 f6             	movzx  esi,si
 7c2:	48 01 ce             	add    rsi,rcx
 7c5:	8b 4d f8             	mov    ecx,DWORD PTR [rbp-0x8]
 7c8:	44 8b 6d c8          	mov    r13d,DWORD PTR [rbp-0x38]
 7cc:	44 09 e9             	or     ecx,r13d
 7cf:	89 4d f8             	mov    DWORD PTR [rbp-0x8],ecx
 7d2:	48 8b 4d e8          	mov    rcx,QWORD PTR [rbp-0x18]
 7d6:	0f c9                	bswap  ecx
 7d8:	81 e1 00 00 ff ff    	and    ecx,0xffff0000
 7de:	44 8b 6d f8          	mov    r13d,DWORD PTR [rbp-0x8]
 7e2:	44 31 e9             	xor    ecx,r13d
 7e5:	41 89 c5             	mov    r13d,eax
 7e8:	44 01 f3             	add    ebx,r14d
 7eb:	41 89 de             	mov    r14d,ebx
 7ee:	44 89 45 b8          	mov    DWORD PTR [rbp-0x48],r8d
 7f2:	45 29 c6             	sub    r14d,r8d
 7f5:	41 31 d6             	xor    r14d,edx
 7f8:	48 89 4d c8          	mov    QWORD PTR [rbp-0x38],rcx
 7fc:	89 ca                	mov    edx,ecx
 7fe:	c1 ea 10             	shr    edx,0x10
 801:	48 01 d6             	add    rsi,rdx
 804:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 80b:	79 37 9e 
 80e:	49 01 d7             	add    r15,rdx
 811:	4d 89 f8             	mov    r8,r15
 814:	49 c1 e8 02          	shr    r8,0x2
 818:	4c 89 fa             	mov    rdx,r15
 81b:	48 c1 e2 06          	shl    rdx,0x6
 81f:	4c 01 c2             	add    rdx,r8
 822:	49 b8 1f e0 4b 80 b9 	movabs r8,0x9e3779b9804be01f
 829:	79 37 9e 
 82c:	4c 01 c2             	add    rdx,r8
 82f:	4c 31 fa             	xor    rdx,r15
 832:	41 01 dd             	add    r13d,ebx
 835:	44 89 f3             	mov    ebx,r14d
 838:	c1 eb 10             	shr    ebx,0x10
 83b:	45 89 f0             	mov    r8d,r14d
 83e:	41 c1 e0 10          	shl    r8d,0x10
 842:	41 09 d8             	or     r8d,ebx
 845:	48 81 c6 3b df 00 00 	add    rsi,0xdf3b
 84c:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 850:	25 ff ff 00 00       	and    eax,0xffff
 855:	89 c1                	mov    ecx,eax
 857:	81 c9 00 00 1f 90    	or     ecx,0x901f0000
 85d:	48 89 d3             	mov    rbx,rdx
 860:	48 c1 e3 06          	shl    rbx,0x6
 864:	48 01 d9             	add    rcx,rbx
 867:	48 89 4d f8          	mov    QWORD PTR [rbp-0x8],rcx
 86b:	48 89 d3             	mov    rbx,rdx
 86e:	48 c1 eb 02          	shr    rbx,0x2
 872:	05 f7 c0 cc 70       	add    eax,0x70ccc0f7
 877:	41 89 c7             	mov    r15d,eax
 87a:	41 c1 e7 0e          	shl    r15d,0xe
 87e:	41 81 cf 33 1c 00 00 	or     r15d,0x1c33
 885:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
 889:	35 f7 c0 ad e0       	xor    eax,0xe0adc0f7
 88e:	48 81 fe 00 00 01 00 	cmp    rsi,0x10000
 895:	72 11                	jb     0x8a8
 897:	48 89 f1             	mov    rcx,rsi
 89a:	48 c1 e9 10          	shr    rcx,0x10
 89e:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 8a5:	48 01 ce             	add    rsi,rcx
 8a8:	8b 4d d0             	mov    ecx,DWORD PTR [rbp-0x30]
 8ab:	c1 e1 10             	shl    ecx,0x10
 8ae:	89 4d d0             	mov    DWORD PTR [rbp-0x30],ecx
 8b1:	8b 4d e0             	mov    ecx,DWORD PTR [rbp-0x20]
 8b4:	c1 e1 18             	shl    ecx,0x18
 8b7:	89 4d e0             	mov    DWORD PTR [rbp-0x20],ecx
 8ba:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
 8be:	48 01 d9             	add    rcx,rbx
 8c1:	48 89 cb             	mov    rbx,rcx
 8c4:	44 29 f8             	sub    eax,r15d
 8c7:	41 89 c7             	mov    r15d,eax
 8ca:	8b 45 b8             	mov    eax,DWORD PTR [rbp-0x48]
 8cd:	44 01 e8             	add    eax,r13d
 8d0:	45 29 f5             	sub    r13d,r14d
 8d3:	45 31 c5             	xor    r13d,r8d
 8d6:	48 81 fe 00 00 01 00 	cmp    rsi,0x10000
 8dd:	72 11                	jb     0x8f0
 8df:	48 89 f1             	mov    rcx,rsi
 8e2:	48 c1 e9 10          	shr    rcx,0x10
 8e6:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 8ed:	48 01 ce             	add    rsi,rcx
 8f0:	8b 4d d8             	mov    ecx,DWORD PTR [rbp-0x28]
 8f3:	c1 e1 08             	shl    ecx,0x8
 8f6:	89 4d d8             	mov    DWORD PTR [rbp-0x28],ecx
 8f9:	48 b9 15 7c 4a 7f b9 	movabs rcx,0x9e3779b97f4a7c15
 900:	79 37 9e 
 903:	48 01 cb             	add    rbx,rcx
 906:	48 31 d3             	xor    rbx,rdx
 909:	48 89 5d f8          	mov    QWORD PTR [rbp-0x8],rbx
 90d:	44 89 fa             	mov    edx,r15d
 910:	c1 ea 15             	shr    edx,0x15
 913:	44 89 7d b8          	mov    DWORD PTR [rbp-0x48],r15d
 917:	45 89 f8             	mov    r8d,r15d
 91a:	41 c1 e0 0b          	shl    r8d,0xb
 91e:	44 89 e9             	mov    ecx,r13d
 921:	c1 e9 0d             	shr    ecx,0xd
 924:	44 89 eb             	mov    ebx,r13d
 927:	c1 e3 13             	shl    ebx,0x13
 92a:	09 cb                	or     ebx,ecx
 92c:	41 01 c6             	add    r14d,eax
 92f:	44 29 e8             	sub    eax,r13d
 932:	31 d8                	xor    eax,ebx
 934:	89 c1                	mov    ecx,eax
 936:	c1 e9 1c             	shr    ecx,0x1c
 939:	41 89 c7             	mov    r15d,eax
 93c:	41 c1 e7 04          	shl    r15d,0x4
 940:	41 09 cf             	or     r15d,ecx
 943:	45 01 f5             	add    r13d,r14d
 946:	41 29 c6             	sub    r14d,eax
 949:	44 01 e8             	add    eax,r13d
 94c:	89 c1                	mov    ecx,eax
 94e:	c1 e9 12             	shr    ecx,0x12
 951:	89 c3                	mov    ebx,eax
 953:	c1 e3 0e             	shl    ebx,0xe
 956:	09 cb                	or     ebx,ecx
 958:	45 31 fe             	xor    r14d,r15d
 95b:	44 8b 7d e0          	mov    r15d,DWORD PTR [rbp-0x20]
 95f:	45 01 ef             	add    r15d,r13d
 962:	8b 4d d0             	mov    ecx,DWORD PTR [rbp-0x30]
 965:	41 01 cf             	add    r15d,ecx
 968:	41 09 d0             	or     r8d,edx
 96b:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 96f:	4c 89 ea             	mov    rdx,r13
 972:	48 c1 ea 02          	shr    rdx,0x2
 976:	49 c1 e5 06          	shl    r13,0x6
 97a:	49 01 d5             	add    r13,rdx
 97d:	41 31 c6             	xor    r14d,eax
 980:	41 29 de             	sub    r14d,ebx
 983:	44 89 f2             	mov    edx,r14d
 986:	c1 ea 15             	shr    edx,0x15
 989:	44 89 f1             	mov    ecx,r14d
 98c:	c1 e1 0b             	shl    ecx,0xb
 98f:	09 d1                	or     ecx,edx
 991:	8b 55 d8             	mov    edx,DWORD PTR [rbp-0x28]
 994:	41 01 d7             	add    r15d,edx
 997:	8b 55 c0             	mov    edx,DWORD PTR [rbp-0x40]
 99a:	41 01 d7             	add    r15d,edx
 99d:	45 31 f7             	xor    r15d,r14d
 9a0:	41 29 cf             	sub    r15d,ecx
 9a3:	44 89 fa             	mov    edx,r15d
 9a6:	c1 ea 07             	shr    edx,0x7
 9a9:	44 89 f9             	mov    ecx,r15d
 9ac:	c1 e1 19             	shl    ecx,0x19
 9af:	09 d1                	or     ecx,edx
 9b1:	44 89 fa             	mov    edx,r15d
 9b4:	31 c2                	xor    edx,eax
 9b6:	29 ca                	sub    edx,ecx
 9b8:	89 d1                	mov    ecx,edx
 9ba:	c1 e9 10             	shr    ecx,0x10
 9bd:	89 d0                	mov    eax,edx
 9bf:	c1 e0 10             	shl    eax,0x10
 9c2:	09 c8                	or     eax,ecx
 9c4:	89 d3                	mov    ebx,edx
 9c6:	44 31 f3             	xor    ebx,r14d
 9c9:	29 c3                	sub    ebx,eax
 9cb:	89 d9                	mov    ecx,ebx
 9cd:	c1 e9 1c             	shr    ecx,0x1c
 9d0:	41 89 de             	mov    r14d,ebx
 9d3:	41 c1 e6 04          	shl    r14d,0x4
 9d7:	41 09 ce             	or     r14d,ecx
 9da:	89 d8                	mov    eax,ebx
 9dc:	44 31 f8             	xor    eax,r15d
 9df:	44 29 f0             	sub    eax,r14d
 9e2:	4c 8b 7d c8          	mov    r15,QWORD PTR [rbp-0x38]
 9e6:	41 81 cf ac 10 00 00 	or     r15d,0x10ac
 9ed:	49 c1 e7 20          	shl    r15,0x20
 9f1:	49 81 cf 0a c8 00 02 	or     r15,0x200c80a
 9f8:	48 c1 e6 10          	shl    rsi,0x10
 9fc:	48 c1 e6 20          	shl    rsi,0x20
 a00:	48 c1 ee 20          	shr    rsi,0x20
 a04:	49 31 f7             	xor    r15,rsi
 a07:	89 c6                	mov    esi,eax
 a09:	31 d6                	xor    esi,edx
 a0b:	89 c2                	mov    edx,eax
 a0d:	c1 ea 12             	shr    edx,0x12
 a10:	c1 e0 0e             	shl    eax,0xe
 a13:	09 d0                	or     eax,edx
 a15:	29 c6                	sub    esi,eax
 a17:	4c 8b 75 f0          	mov    r14,QWORD PTR [rbp-0x10]
 a1b:	49 81 e6 ff ff 00 00 	and    r14,0xffff
 a22:	4d 31 f7             	xor    r15,r14
 a25:	48 ba 0b 00 ff ff 00 	movabs rdx,0x200ffff000b
 a2c:	02 00 00 
 a2f:	49 31 d7             	xor    r15,rdx
 a32:	89 f2                	mov    edx,esi
 a34:	c1 ea 08             	shr    edx,0x8
 a37:	89 f1                	mov    ecx,esi
 a39:	c1 e1 18             	shl    ecx,0x18
 a3c:	09 d1                	or     ecx,edx
 a3e:	31 de                	xor    esi,ebx
 a40:	29 ce                	sub    esi,ecx
 a42:	81 c6 f7 c0 ad e0    	add    esi,0xe0adc0f7
 a48:	8b 5d b8             	mov    ebx,DWORD PTR [rbp-0x48]
 a4b:	31 de                	xor    esi,ebx
 a4d:	44 29 c6             	sub    esi,r8d
 a50:	89 f2                	mov    edx,esi
 a52:	c1 ea 07             	shr    edx,0x7
 a55:	89 f1                	mov    ecx,esi
 a57:	c1 e1 19             	shl    ecx,0x19
 a5a:	09 d1                	or     ecx,edx
 a5c:	41 89 f0             	mov    r8d,esi
 a5f:	48 8b 55 e8          	mov    rdx,QWORD PTR [rbp-0x18]
 a63:	41 31 d0             	xor    r8d,edx
 a66:	41 29 c8             	sub    r8d,ecx
 a69:	44 89 c2             	mov    edx,r8d
 a6c:	c1 ea 10             	shr    edx,0x10
 a6f:	44 89 c1             	mov    ecx,r8d
 a72:	c1 e1 10             	shl    ecx,0x10
 a75:	09 d1                	or     ecx,edx
 a77:	44 89 c0             	mov    eax,r8d
 a7a:	31 d8                	xor    eax,ebx
 a7c:	29 c8                	sub    eax,ecx
 a7e:	89 c2                	mov    edx,eax
 a80:	c1 ea 1c             	shr    edx,0x1c
 a83:	89 c1                	mov    ecx,eax
 a85:	c1 e1 04             	shl    ecx,0x4
 a88:	09 d1                	or     ecx,edx
 a8a:	89 c2                	mov    edx,eax
 a8c:	31 f2                	xor    edx,esi
 a8e:	29 ca                	sub    edx,ecx
 a90:	89 d6                	mov    esi,edx
 a92:	c1 ee 12             	shr    esi,0x12
 a95:	89 d1                	mov    ecx,edx
 a97:	c1 e1 0e             	shl    ecx,0xe
 a9a:	09 f1                	or     ecx,esi
 a9c:	44 31 c2             	xor    edx,r8d
 a9f:	29 ca                	sub    edx,ecx
 aa1:	89 d6                	mov    esi,edx
 aa3:	c1 ee 08             	shr    esi,0x8
 aa6:	89 d1                	mov    ecx,edx
 aa8:	c1 e1 18             	shl    ecx,0x18
 aab:	09 f1                	or     ecx,esi
 aad:	31 c2                	xor    edx,eax
 aaf:	29 ca                	sub    edx,ecx
 ab1:	be 01 00 ff ff       	mov    esi,0xffff0001
 ab6:	48 89 d1             	mov    rcx,rdx
 ab9:	48 0f af ce          	imul   rcx,rsi
 abd:	48 c1 e9 30          	shr    rcx,0x30
 ac1:	69 c9 01 00 01 00    	imul   ecx,ecx,0x10001
 ac7:	29 ca                	sub    edx,ecx
 ac9:	49 01 d5             	add    r13,rdx
 acc:	49 b8 15 7c 4a 7f b9 	movabs r8,0x9e3779b97f4a7c15
 ad3:	79 37 9e 
 ad6:	4d 01 c5             	add    r13,r8
 ad9:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 add:	49 31 f5             	xor    r13,rsi
 ae0:	4c 89 ee             	mov    rsi,r13
 ae3:	48 c1 ee 02          	shr    rsi,0x2
 ae7:	4c 89 ea             	mov    rdx,r13
 aea:	48 c1 e2 06          	shl    rdx,0x6
 aee:	48 01 f2             	add    rdx,rsi
 af1:	48 be 16 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c16
 af8:	79 37 9e 
 afb:	48 01 f2             	add    rdx,rsi
 afe:	4c 31 ea             	xor    rdx,r13
 b01:	48 89 d6             	mov    rsi,rdx
 b04:	48 c1 ee 02          	shr    rsi,0x2
 b08:	48 89 d1             	mov    rcx,rdx
 b0b:	48 c1 e1 06          	shl    rcx,0x6
 b0f:	48 01 f1             	add    rcx,rsi
 b12:	4c 01 c1             	add    rcx,r8
 b15:	48 31 d1             	xor    rcx,rdx
 b18:	48 89 ce             	mov    rsi,rcx
 b1b:	48 c1 e6 06          	shl    rsi,0x6
 b1f:	49 01 f6             	add    r14,rsi
 b22:	48 89 ce             	mov    rsi,rcx
 b25:	48 c1 ee 02          	shr    rsi,0x2
 b29:	49 01 f6             	add    r14,rsi
 b2c:	4d 01 c6             	add    r14,r8
 b2f:	49 31 ce             	xor    r14,rcx
 b32:	4c 89 f6             	mov    rsi,r14
 b35:	48 c1 ee 02          	shr    rsi,0x2
 b39:	4c 89 f2             	mov    rdx,r14
 b3c:	48 c1 e2 06          	shl    rdx,0x6
 b40:	48 01 f2             	add    rdx,rsi
 b43:	4c 01 fa             	add    rdx,r15
 b46:	4c 01 c2             	add    rdx,r8
 b49:	4c 31 f2             	xor    rdx,r14
 b4c:	48 89 d6             	mov    rsi,rdx
 b4f:	48 c1 ee 02          	shr    rsi,0x2
 b53:	49 89 d5             	mov    r13,rdx
 b56:	49 c1 e5 06          	shl    r13,0x6
 b5a:	49 01 f5             	add    r13,rsi
 b5d:	48 be 18 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c18
 b64:	79 37 9e 
 b67:	49 01 f5             	add    r13,rsi
 b6a:	49 31 d5             	xor    r13,rdx
 b6d:	41 bf 03 00 00 00    	mov    r15d,0x3
 b73:	e9 50 f9 ff ff       	jmp    0x4c8
 b78:	41 bd 01 00 00 00    	mov    r13d,0x1
 b7e:	48 89 fe             	mov    rsi,rdi
 b81:	48 83 c6 32          	add    rsi,0x32
 b85:	41 bf 01 00 00 00    	mov    r15d,0x1
 b8b:	48 39 de             	cmp    rsi,rbx
 b8e:	0f 87 34 f9 ff ff    	ja     0x4c8
 b94:	41 bd 02 00 00 00    	mov    r13d,0x2
 b9a:	e9 23 f9 ff ff       	jmp    0x4c2
```

## llvmbpf JIT ASM
```asm
not captured
```
