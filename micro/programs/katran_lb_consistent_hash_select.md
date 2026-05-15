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

Disassembly of section .plt:

Disassembly of section .plt.got:

Disassembly of section .text:

0000000000001100 <katran_lb_consistent_hash_select_xdp>:
    1100:	55                   	push   rbp
    1101:	41 57                	push   r15
    1103:	41 56                	push   r14
    1105:	41 55                	push   r13
    1107:	41 54                	push   r12
    1109:	53                   	push   rbx
    110a:	48 8b 0f             	mov    rcx,QWORD PTR [rdi]
    110d:	48 8b 5f 08          	mov    rbx,QWORD PTR [rdi+0x8]
    1111:	31 c0                	xor    eax,eax
    1113:	48 39 d9             	cmp    rcx,rbx
    1116:	0f 87 f6 04 00 00    	ja     1612 <katran_lb_consistent_hash_select_xdp+0x512>
    111c:	48 8d 71 08          	lea    rsi,[rcx+0x8]
    1120:	48 39 de             	cmp    rsi,rbx
    1123:	0f 87 e9 04 00 00    	ja     1612 <katran_lb_consistent_hash_select_xdp+0x512>
    1129:	48 8d 51 16          	lea    rdx,[rcx+0x16]
    112d:	48 39 da             	cmp    rdx,rbx
    1130:	0f 87 dc 04 00 00    	ja     1612 <katran_lb_consistent_hash_select_xdp+0x512>
    1136:	48 b8 15 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c15
    113d:	79 37 9e 
    1140:	49 89 da             	mov    r10,rbx
    1143:	49 29 f2             	sub    r10,rsi
    1146:	0f b7 71 14          	movzx  esi,WORD PTR [rcx+0x14]
    114a:	81 fe 86 dd 00 00    	cmp    esi,0xdd86
    1150:	0f 84 8f 00 00 00    	je     11e5 <katran_lb_consistent_hash_select_xdp+0xe5>
    1156:	83 fe 08             	cmp    esi,0x8
    1159:	0f 85 b5 00 00 00    	jne    1214 <katran_lb_consistent_hash_select_xdp+0x114>
    115f:	48 8d 71 2a          	lea    rsi,[rcx+0x2a]
    1163:	41 b9 01 00 00 00    	mov    r9d,0x1
    1169:	48 39 de             	cmp    rsi,rbx
    116c:	0f 87 79 04 00 00    	ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb>
    1172:	0f b6 12             	movzx  edx,BYTE PTR [rdx]
    1175:	80 e2 0f             	and    dl,0xf
    1178:	80 fa 05             	cmp    dl,0x5
    117b:	0f 85 6a 04 00 00    	jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb>
    1181:	0f b6 51 1c          	movzx  edx,BYTE PTR [rcx+0x1c]
    1185:	0f b6 71 1d          	movzx  esi,BYTE PTR [rcx+0x1d]
    1189:	83 e2 3f             	and    edx,0x3f
    118c:	66 09 f2             	or     dx,si
    118f:	0f 85 56 04 00 00    	jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb>
    1195:	44 0f b6 71 1f       	movzx  r14d,BYTE PTR [rcx+0x1f]
    119a:	be 02 00 00 00       	mov    esi,0x2
    119f:	41 83 fe 01          	cmp    r14d,0x1
    11a3:	0f 84 89 00 00 00    	je     1232 <katran_lb_consistent_hash_select_xdp+0x132>
    11a9:	0f b6 79 17          	movzx  edi,BYTE PTR [rcx+0x17]
    11ad:	0f b7 69 18          	movzx  ebp,WORD PTR [rcx+0x18]
    11b1:	44 0f b7 59 22       	movzx  r11d,WORD PTR [rcx+0x22]
    11b6:	44 0f b6 41 24       	movzx  r8d,BYTE PTR [rcx+0x24]
    11bb:	0f b6 51 25          	movzx  edx,BYTE PTR [rcx+0x25]
    11bf:	44 8b 79 26          	mov    r15d,DWORD PTR [rcx+0x26]
    11c3:	41 83 fe 11          	cmp    r14d,0x11
    11c7:	0f 84 15 04 00 00    	je     15e2 <katran_lb_consistent_hash_select_xdp+0x4e2>
    11cd:	41 83 fe 06          	cmp    r14d,0x6
    11d1:	75 5f                	jne    1232 <katran_lb_consistent_hash_select_xdp+0x132>
    11d3:	4c 8d 61 3e          	lea    r12,[rcx+0x3e]
    11d7:	49 39 dc             	cmp    r12,rbx
    11da:	0f 87 0b 04 00 00    	ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb>
    11e0:	e9 38 04 00 00       	jmp    161d <katran_lb_consistent_hash_select_xdp+0x51d>
    11e5:	48 8d 51 3e          	lea    rdx,[rcx+0x3e]
    11e9:	41 b9 01 00 00 00    	mov    r9d,0x1
    11ef:	48 39 da             	cmp    rdx,rbx
    11f2:	0f 87 f3 03 00 00    	ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb>
    11f8:	44 0f b6 61 1c       	movzx  r12d,BYTE PTR [rcx+0x1c]
    11fd:	41 83 fc 2c          	cmp    r12d,0x2c
    1201:	0f 84 e4 03 00 00    	je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb>
    1207:	41 83 fc 3a          	cmp    r12d,0x3a
    120b:	75 30                	jne    123d <katran_lb_consistent_hash_select_xdp+0x13d>
    120d:	be 02 00 00 00       	mov    esi,0x2
    1212:	eb 1e                	jmp    1232 <katran_lb_consistent_hash_select_xdp+0x132>
    1214:	49 01 c2             	add    r10,rax
    1217:	4c 89 d2             	mov    rdx,r10
    121a:	48 c1 e2 06          	shl    rdx,0x6
    121e:	48 01 c2             	add    rdx,rax
    1221:	4c 89 d6             	mov    rsi,r10
    1224:	48 c1 ee 02          	shr    rsi,0x2
    1228:	48 01 d6             	add    rsi,rdx
    122b:	48 83 c6 02          	add    rsi,0x2
    122f:	4c 31 d6             	xor    rsi,r10
    1232:	41 b9 02 00 00 00    	mov    r9d,0x2
    1238:	e9 b3 03 00 00       	jmp    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0>
    123d:	0f b6 51 16          	movzx  edx,BYTE PTR [rcx+0x16]
    1241:	44 0f b6 79 17       	movzx  r15d,BYTE PTR [rcx+0x17]
    1246:	44 0f b7 71 1a       	movzx  r14d,WORD PTR [rcx+0x1a]
    124b:	8b 79 1e             	mov    edi,DWORD PTR [rcx+0x1e]
    124e:	44 8b 59 26          	mov    r11d,DWORD PTR [rcx+0x26]
    1252:	8b 69 2a             	mov    ebp,DWORD PTR [rcx+0x2a]
    1255:	44 8b 69 2e          	mov    r13d,DWORD PTR [rcx+0x2e]
    1259:	41 b8 ff c0 ad de    	mov    r8d,0xdeadc0ff
    125f:	44 03 41 22          	add    r8d,DWORD PTR [rcx+0x22]
    1263:	be 02 00 00 00       	mov    esi,0x2
    1268:	41 83 fc 11          	cmp    r12d,0x11
    126c:	74 1a                	je     1288 <katran_lb_consistent_hash_select_xdp+0x188>
    126e:	41 83 fc 06          	cmp    r12d,0x6
    1272:	75 be                	jne    1232 <katran_lb_consistent_hash_select_xdp+0x132>
    1274:	48 89 7c 24 f8       	mov    QWORD PTR [rsp-0x8],rdi
    1279:	48 8d 79 52          	lea    rdi,[rcx+0x52]
    127d:	48 39 df             	cmp    rdi,rbx
    1280:	0f 87 65 03 00 00    	ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb>
    1286:	eb 12                	jmp    129a <katran_lb_consistent_hash_select_xdp+0x19a>
    1288:	48 89 7c 24 f8       	mov    QWORD PTR [rsp-0x8],rdi
    128d:	48 8d 79 46          	lea    rdi,[rcx+0x46]
    1291:	48 39 df             	cmp    rdi,rbx
    1294:	0f 87 51 03 00 00    	ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb>
    129a:	41 83 fc 06          	cmp    r12d,0x6
    129e:	75 92                	jne    1232 <katran_lb_consistent_hash_select_xdp+0x132>
    12a0:	41 81 fd 0a 64 01 01 	cmp    r13d,0x101640a
    12a7:	75 89                	jne    1232 <katran_lb_consistent_hash_select_xdp+0x132>
    12a9:	0f b7 79 40          	movzx  edi,WORD PTR [rcx+0x40]
    12ad:	41 b9 02 00 00 00    	mov    r9d,0x2
    12b3:	81 ff 1f 90 00 00    	cmp    edi,0x901f
    12b9:	0f 85 31 03 00 00    	jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0>
    12bf:	be 01 00 00 00       	mov    esi,0x1
    12c4:	41 b9 01 00 00 00    	mov    r9d,0x1
    12ca:	49 81 fa ea 05 00 00 	cmp    r10,0x5ea
    12d1:	0f 8f 19 03 00 00    	jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0>
    12d7:	41 c0 ef 04          	shr    r15b,0x4
    12db:	41 89 d4             	mov    r12d,edx
    12de:	41 c0 e4 04          	shl    r12b,0x4
    12e2:	45 08 fc             	or     r12b,r15b
    12e5:	66 41 c1 c6 08       	rol    r14w,0x8
    12ea:	41 0f b7 f6          	movzx  esi,r14w
    12ee:	89 ef                	mov    edi,ebp
    12f0:	81 e7 00 00 00 ff    	and    edi,0xff000000
    12f6:	45 8d 8b ff c0 ad de 	lea    r9d,[r11-0x21523f01]
    12fd:	41 89 ea             	mov    r10d,ebp
    1300:	41 81 e2 00 00 ff 00 	and    r10d,0xff0000
    1307:	41 01 fa             	add    r10d,edi
    130a:	89 ef                	mov    edi,ebp
    130c:	81 e7 00 ff 00 00    	and    edi,0xff00
    1312:	44 01 d7             	add    edi,r10d
    1315:	40 0f b6 dd          	movzx  ebx,bpl
    1319:	01 fb                	add    ebx,edi
    131b:	48 8b 54 24 f8       	mov    rdx,QWORD PTR [rsp-0x8]
    1320:	89 d7                	mov    edi,edx
    1322:	44 29 df             	sub    edi,r11d
    1325:	45 89 ce             	mov    r14d,r9d
    1328:	41 c1 c6 04          	rol    r14d,0x4
    132c:	41 31 fe             	xor    r14d,edi
    132f:	45 01 c1             	add    r9d,r8d
    1332:	45 29 f0             	sub    r8d,r14d
    1335:	45 89 f2             	mov    r10d,r14d
    1338:	41 c1 c2 06          	rol    r10d,0x6
    133c:	45 31 c2             	xor    r10d,r8d
    133f:	45 01 ce             	add    r14d,r9d
    1342:	43 8d 3c 32          	lea    edi,[r10+r14*1]
    1346:	45 29 d1             	sub    r9d,r10d
    1349:	41 c1 c2 08          	rol    r10d,0x8
    134d:	44 0f b7 41 3e       	movzx  r8d,WORD PTR [rcx+0x3e]
    1352:	45 31 ca             	xor    r10d,r9d
    1355:	45 29 d6             	sub    r14d,r10d
    1358:	45 89 d3             	mov    r11d,r10d
    135b:	41 c1 c3 10          	rol    r11d,0x10
    135f:	45 31 f3             	xor    r11d,r14d
    1362:	41 01 fa             	add    r10d,edi
    1365:	44 29 df             	sub    edi,r11d
    1368:	45 89 de             	mov    r14d,r11d
    136b:	41 c1 c6 13          	rol    r14d,0x13
    136f:	41 31 fe             	xor    r14d,edi
    1372:	45 01 d3             	add    r11d,r10d
    1375:	47 8d 0c 1e          	lea    r9d,[r14+r11*1]
    1379:	45 29 f2             	sub    r10d,r14d
    137c:	41 c1 c6 04          	rol    r14d,0x4
    1380:	41 01 db             	add    r11d,ebx
    1383:	45 31 ca             	xor    r10d,r9d
    1386:	45 31 f2             	xor    r10d,r14d
    1389:	44 89 cf             	mov    edi,r9d
    138c:	c1 c7 0e             	rol    edi,0xe
    138f:	41 29 fa             	sub    r10d,edi
    1392:	44 89 d7             	mov    edi,r10d
    1395:	c1 c7 0b             	rol    edi,0xb
    1398:	45 31 d3             	xor    r11d,r10d
    139b:	41 29 fb             	sub    r11d,edi
    139e:	45 31 d9             	xor    r9d,r11d
    13a1:	44 89 df             	mov    edi,r11d
    13a4:	c1 c7 19             	rol    edi,0x19
    13a7:	41 29 f9             	sub    r9d,edi
    13aa:	45 31 ca             	xor    r10d,r9d
    13ad:	44 89 cf             	mov    edi,r9d
    13b0:	c1 c7 10             	rol    edi,0x10
    13b3:	41 29 fa             	sub    r10d,edi
    13b6:	45 31 d3             	xor    r11d,r10d
    13b9:	44 89 d7             	mov    edi,r10d
    13bc:	c1 c7 04             	rol    edi,0x4
    13bf:	41 29 fb             	sub    r11d,edi
    13c2:	45 31 d9             	xor    r9d,r11d
    13c5:	41 c1 c3 0e          	rol    r11d,0xe
    13c9:	45 29 d9             	sub    r9d,r11d
    13cc:	44 89 cf             	mov    edi,r9d
    13cf:	c1 c7 18             	rol    edi,0x18
    13d2:	45 31 d1             	xor    r9d,r10d
    13d5:	41 29 f9             	sub    r9d,edi
    13d8:	41 81 c1 f7 c0 ad e0 	add    r9d,0xe0adc0f7
    13df:	45 89 c3             	mov    r11d,r8d
    13e2:	41 81 c3 f7 c0 cc 70 	add    r11d,0x70ccc0f7
    13e9:	45 89 da             	mov    r10d,r11d
    13ec:	41 81 f2 f7 c0 ad e0 	xor    r10d,0xe0adc0f7
    13f3:	bf 00 00 cc 70       	mov    edi,0x70cc0000
    13f8:	44 0f ac df 12       	shrd   edi,r11d,0x12
    13fd:	41 29 fa             	sub    r10d,edi
    1400:	45 31 d1             	xor    r9d,r10d
    1403:	44 89 d7             	mov    edi,r10d
    1406:	c1 c7 0b             	rol    edi,0xb
    1409:	41 29 f9             	sub    r9d,edi
    140c:	45 31 cb             	xor    r11d,r9d
    140f:	44 89 cf             	mov    edi,r9d
    1412:	c1 c7 19             	rol    edi,0x19
    1415:	41 29 fb             	sub    r11d,edi
    1418:	44 89 df             	mov    edi,r11d
    141b:	c1 c7 10             	rol    edi,0x10
    141e:	45 31 da             	xor    r10d,r11d
    1421:	41 29 fa             	sub    r10d,edi
    1424:	45 31 d1             	xor    r9d,r10d
    1427:	44 89 d7             	mov    edi,r10d
    142a:	c1 c7 04             	rol    edi,0x4
    142d:	41 29 f9             	sub    r9d,edi
    1430:	45 31 cb             	xor    r11d,r9d
    1433:	41 c1 c1 0e          	rol    r9d,0xe
    1437:	45 29 cb             	sub    r11d,r9d
    143a:	45 31 da             	xor    r10d,r11d
    143d:	41 c1 c3 18          	rol    r11d,0x18
    1441:	45 29 da             	sub    r10d,r11d
    1444:	bf 01 00 ff ff       	mov    edi,0xffff0001
    1449:	49 0f af fa          	imul   rdi,r10
    144d:	48 c1 ef 30          	shr    rdi,0x30
    1451:	41 89 f9             	mov    r9d,edi
    1454:	41 c1 e1 10          	shl    r9d,0x10
    1458:	41 09 f9             	or     r9d,edi
    145b:	45 29 ca             	sub    r10d,r9d
    145e:	48 89 d7             	mov    rdi,rdx
    1461:	48 01 c7             	add    rdi,rax
    1464:	49 89 f9             	mov    r9,rdi
    1467:	49 c1 e1 06          	shl    r9,0x6
    146b:	49 01 c1             	add    r9,rax
    146e:	49 89 fb             	mov    r11,rdi
    1471:	49 c1 eb 02          	shr    r11,0x2
    1475:	4d 01 d9             	add    r9,r11
    1478:	49 81 c1 0a 64 01 01 	add    r9,0x101640a
    147f:	49 31 f9             	xor    r9,rdi
    1482:	4d 89 cb             	mov    r11,r9
    1485:	49 c1 e3 06          	shl    r11,0x6
    1489:	4d 01 c3             	add    r11,r8
    148c:	49 01 c3             	add    r11,rax
    148f:	4c 89 cf             	mov    rdi,r9
    1492:	48 c1 ef 02          	shr    rdi,0x2
    1496:	bb 00 00 1f 90       	mov    ebx,0x901f0000
    149b:	48 01 fb             	add    rbx,rdi
    149e:	4c 01 db             	add    rbx,r11
    14a1:	4c 31 cb             	xor    rbx,r9
    14a4:	48 89 df             	mov    rdi,rbx
    14a7:	48 c1 e7 06          	shl    rdi,0x6
    14ab:	49 89 d9             	mov    r9,rbx
    14ae:	49 c1 e9 02          	shr    r9,0x2
    14b2:	48 01 c7             	add    rdi,rax
    14b5:	4c 01 cf             	add    rdi,r9
    14b8:	4c 01 d7             	add    rdi,r10
    14bb:	48 31 df             	xor    rdi,rbx
    14be:	49 89 f9             	mov    r9,rdi
    14c1:	49 c1 e1 06          	shl    r9,0x6
    14c5:	49 01 c1             	add    r9,rax
    14c8:	49 89 fa             	mov    r10,rdi
    14cb:	49 c1 ea 02          	shr    r10,0x2
    14cf:	4d 01 d1             	add    r9,r10
    14d2:	49 ff c1             	inc    r9
    14d5:	49 31 f9             	xor    r9,rdi
    14d8:	4c 89 cf             	mov    rdi,r9
    14db:	48 c1 e7 06          	shl    rdi,0x6
    14df:	48 01 c7             	add    rdi,rax
    14e2:	4d 89 ca             	mov    r10,r9
    14e5:	49 c1 ea 02          	shr    r10,0x2
    14e9:	49 01 fa             	add    r10,rdi
    14ec:	4d 31 ca             	xor    r10,r9
    14ef:	4d 89 d3             	mov    r11,r10
    14f2:	49 c1 e3 06          	shl    r11,0x6
    14f6:	49 01 f3             	add    r11,rsi
    14f9:	49 01 c3             	add    r11,rax
    14fc:	4d 89 d1             	mov    r9,r10
    14ff:	49 c1 e9 02          	shr    r9,0x2
    1503:	4d 01 d9             	add    r9,r11
    1506:	66 41 c1 c0 08       	rol    r8w,0x8
    150b:	41 c1 e0 10          	shl    r8d,0x10
    150f:	81 e2 00 00 ff ff    	and    edx,0xffff0000
    1515:	44 31 c2             	xor    edx,r8d
    1518:	89 f7                	mov    edi,esi
    151a:	83 c7 14             	add    edi,0x14
    151d:	66 c1 c7 08          	rol    di,0x8
    1521:	45 0f b6 c4          	movzx  r8d,r12b
    1525:	0f b7 ff             	movzx  edi,di
    1528:	41 89 d3             	mov    r11d,edx
    152b:	41 c1 eb 10          	shr    r11d,0x10
    152f:	4c 01 c7             	add    rdi,r8
    1532:	4c 01 df             	add    rdi,r11
    1535:	48 81 c7 3b df 00 00 	add    rdi,0xdf3b
    153c:	41 89 f8             	mov    r8d,edi
    153f:	41 c1 e8 10          	shr    r8d,0x10
    1543:	44 0f b7 df          	movzx  r11d,di
    1547:	4d 01 c3             	add    r11,r8
    154a:	48 81 ff 00 00 01 00 	cmp    rdi,0x10000
    1551:	4c 0f 42 df          	cmovb  r11,rdi
    1555:	44 89 df             	mov    edi,r11d
    1558:	c1 ef 10             	shr    edi,0x10
    155b:	45 0f b7 c3          	movzx  r8d,r11w
    155f:	49 01 f8             	add    r8,rdi
    1562:	49 81 fb 00 00 01 00 	cmp    r11,0x10000
    1569:	4d 0f 42 c3          	cmovb  r8,r11
    156d:	44 89 c7             	mov    edi,r8d
    1570:	c1 ef 10             	shr    edi,0x10
    1573:	45 0f b7 d8          	movzx  r11d,r8w
    1577:	49 01 fb             	add    r11,rdi
    157a:	49 81 f8 00 00 01 00 	cmp    r8,0x10000
    1581:	4d 0f 42 d8          	cmovb  r11,r8
    1585:	44 89 df             	mov    edi,r11d
    1588:	c1 ef 10             	shr    edi,0x10
    158b:	44 01 df             	add    edi,r11d
    158e:	4d 31 d1             	xor    r9,r10
    1591:	81 ca ac 10 00 00    	or     edx,0x10ac
    1597:	48 c1 e2 20          	shl    rdx,0x20
    159b:	48 81 ca 0a c8 00 02 	or     rdx,0x200c80a
    15a2:	49 81 fb 00 00 01 00 	cmp    r11,0x10000
    15a9:	41 0f 42 fb          	cmovb  edi,r11d
    15ad:	c1 e7 10             	shl    edi,0x10
    15b0:	48 31 f2             	xor    rdx,rsi
    15b3:	48 be 0b 00 ff ff 00 	movabs rsi,0x200ffff000b
    15ba:	02 00 00 
    15bd:	48 31 d6             	xor    rsi,rdx
    15c0:	48 31 fe             	xor    rsi,rdi
    15c3:	4c 89 ca             	mov    rdx,r9
    15c6:	48 c1 e2 06          	shl    rdx,0x6
    15ca:	4c 89 cf             	mov    rdi,r9
    15cd:	48 c1 ef 02          	shr    rdi,0x2
    15d1:	48 01 f7             	add    rdi,rsi
    15d4:	48 01 c2             	add    rdx,rax
    15d7:	48 01 fa             	add    rdx,rdi
    15da:	4c 31 ca             	xor    rdx,r9
    15dd:	e9 91 02 00 00       	jmp    1873 <katran_lb_consistent_hash_select_xdp+0x773>
    15e2:	4c 8d 61 32          	lea    r12,[rcx+0x32]
    15e6:	49 39 dc             	cmp    r12,rbx
    15e9:	76 32                	jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d>
    15eb:	be 01 00 00 00       	mov    esi,0x1
    15f0:	48 89 f2             	mov    rdx,rsi
    15f3:	48 c1 e2 06          	shl    rdx,0x6
    15f7:	48 89 f7             	mov    rdi,rsi
    15fa:	48 c1 ef 02          	shr    rdi,0x2
    15fe:	4c 01 cf             	add    rdi,r9
    1601:	48 01 c2             	add    rdx,rax
    1604:	48 01 fa             	add    rdx,rdi
    1607:	48 31 f2             	xor    rdx,rsi
    160a:	48 89 11             	mov    QWORD PTR [rcx],rdx
    160d:	b8 02 00 00 00       	mov    eax,0x2
    1612:	5b                   	pop    rbx
    1613:	41 5c                	pop    r12
    1615:	41 5d                	pop    r13
    1617:	41 5e                	pop    r14
    1619:	41 5f                	pop    r15
    161b:	5d                   	pop    rbp
    161c:	c3                   	ret
    161d:	41 81 ff 0a 64 01 01 	cmp    r15d,0x101640a
    1624:	0f 85 08 fc ff ff    	jne    1232 <katran_lb_consistent_hash_select_xdp+0x132>
    162a:	44 0f b7 49 2c       	movzx  r9d,WORD PTR [rcx+0x2c]
    162f:	41 81 f9 1f 90 00 00 	cmp    r9d,0x901f
    1636:	0f 85 f6 fb ff ff    	jne    1232 <katran_lb_consistent_hash_select_xdp+0x132>
    163c:	41 b9 02 00 00 00    	mov    r9d,0x2
    1642:	41 80 fe 06          	cmp    r14b,0x6
    1646:	75 a8                	jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0>
    1648:	be 01 00 00 00       	mov    esi,0x1
    164d:	41 b9 01 00 00 00    	mov    r9d,0x1
    1653:	49 81 fa ea 05 00 00 	cmp    r10,0x5ea
    165a:	7f 94                	jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0>
    165c:	66 c1 c5 08          	rol    bp,0x8
    1660:	0f b7 f5             	movzx  esi,bp
    1663:	41 c1 e0 10          	shl    r8d,0x10
    1667:	c1 e2 18             	shl    edx,0x18
    166a:	45 09 c3             	or     r11d,r8d
    166d:	41 09 d3             	or     r11d,edx
    1670:	44 0f b7 49 2a       	movzx  r9d,WORD PTR [rcx+0x2a]
    1675:	44 89 cb             	mov    ebx,r9d
    1678:	81 c3 f7 c0 cc 70    	add    ebx,0x70ccc0f7
    167e:	41 89 da             	mov    r10d,ebx
    1681:	41 81 f2 f7 c0 ad e0 	xor    r10d,0xe0adc0f7
    1688:	bd 00 00 cc 70       	mov    ebp,0x70cc0000
    168d:	0f ac dd 12          	shrd   ebp,ebx,0x12
    1691:	41 29 ea             	sub    r10d,ebp
    1694:	41 8d ab f7 c0 ad e0 	lea    ebp,[r11-0x1f523f09]
    169b:	44 31 d5             	xor    ebp,r10d
    169e:	45 89 d6             	mov    r14d,r10d
    16a1:	41 c1 c6 0b          	rol    r14d,0xb
    16a5:	44 29 f5             	sub    ebp,r14d
    16a8:	41 89 ee             	mov    r14d,ebp
    16ab:	41 c1 c6 19          	rol    r14d,0x19
    16af:	31 eb                	xor    ebx,ebp
    16b1:	44 29 f3             	sub    ebx,r14d
    16b4:	41 31 da             	xor    r10d,ebx
    16b7:	41 89 de             	mov    r14d,ebx
    16ba:	41 c1 c6 10          	rol    r14d,0x10
    16be:	45 29 f2             	sub    r10d,r14d
    16c1:	44 31 d5             	xor    ebp,r10d
    16c4:	45 89 d6             	mov    r14d,r10d
    16c7:	41 c1 c6 04          	rol    r14d,0x4
    16cb:	44 29 f5             	sub    ebp,r14d
    16ce:	31 eb                	xor    ebx,ebp
    16d0:	c1 c5 0e             	rol    ebp,0xe
    16d3:	29 eb                	sub    ebx,ebp
    16d5:	41 31 da             	xor    r10d,ebx
    16d8:	c1 c3 18             	rol    ebx,0x18
    16db:	41 29 da             	sub    r10d,ebx
    16de:	bb 01 00 ff ff       	mov    ebx,0xffff0001
    16e3:	49 0f af da          	imul   rbx,r10
    16e7:	48 c1 eb 30          	shr    rbx,0x30
    16eb:	89 dd                	mov    ebp,ebx
    16ed:	c1 e5 10             	shl    ebp,0x10
    16f0:	09 dd                	or     ebp,ebx
    16f2:	41 29 ea             	sub    r10d,ebp
    16f5:	45 89 db             	mov    r11d,r11d
    16f8:	49 01 c3             	add    r11,rax
    16fb:	4c 89 db             	mov    rbx,r11
    16fe:	48 c1 e3 06          	shl    rbx,0x6
    1702:	4d 89 de             	mov    r14,r11
    1705:	49 c1 ee 02          	shr    r14,0x2
    1709:	49 01 c6             	add    r14,rax
    170c:	4c 01 f3             	add    rbx,r14
    170f:	48 81 c3 0a 64 01 01 	add    rbx,0x101640a
    1716:	4c 31 db             	xor    rbx,r11
    1719:	49 89 db             	mov    r11,rbx
    171c:	49 c1 e3 06          	shl    r11,0x6
    1720:	49 89 de             	mov    r14,rbx
    1723:	49 c1 ee 02          	shr    r14,0x2
    1727:	4d 01 ce             	add    r14,r9
    172a:	49 01 c3             	add    r11,rax
    172d:	4d 01 f3             	add    r11,r14
    1730:	41 be 00 00 1f 90    	mov    r14d,0x901f0000
    1736:	4d 01 de             	add    r14,r11
    1739:	49 31 de             	xor    r14,rbx
    173c:	4d 89 f3             	mov    r11,r14
    173f:	49 c1 e3 06          	shl    r11,0x6
    1743:	4c 89 f3             	mov    rbx,r14
    1746:	48 c1 eb 02          	shr    rbx,0x2
    174a:	49 01 c3             	add    r11,rax
    174d:	49 01 db             	add    r11,rbx
    1750:	4d 01 d3             	add    r11,r10
    1753:	4d 31 f3             	xor    r11,r14
    1756:	4d 89 da             	mov    r10,r11
    1759:	49 c1 e2 06          	shl    r10,0x6
    175d:	49 01 c2             	add    r10,rax
    1760:	4c 89 db             	mov    rbx,r11
    1763:	48 c1 eb 02          	shr    rbx,0x2
    1767:	49 01 da             	add    r10,rbx
    176a:	49 ff c2             	inc    r10
    176d:	4d 31 da             	xor    r10,r11
    1770:	4c 89 d3             	mov    rbx,r10
    1773:	48 c1 e3 06          	shl    rbx,0x6
    1777:	48 01 c3             	add    rbx,rax
    177a:	4d 89 d3             	mov    r11,r10
    177d:	49 c1 eb 02          	shr    r11,0x2
    1781:	49 01 db             	add    r11,rbx
    1784:	4d 31 d3             	xor    r11,r10
    1787:	4c 89 db             	mov    rbx,r11
    178a:	48 c1 e3 06          	shl    rbx,0x6
    178e:	48 01 f3             	add    rbx,rsi
    1791:	48 01 c3             	add    rbx,rax
    1794:	4d 89 da             	mov    r10,r11
    1797:	49 c1 ea 02          	shr    r10,0x2
    179b:	66 41 c1 c1 08       	rol    r9w,0x8
    17a0:	49 01 da             	add    r10,rbx
    17a3:	41 c1 e1 10          	shl    r9d,0x10
    17a7:	44 09 c2             	or     edx,r8d
    17aa:	44 31 ca             	xor    edx,r9d
    17ad:	41 89 f0             	mov    r8d,esi
    17b0:	41 83 c0 14          	add    r8d,0x14
    17b4:	66 41 c1 c0 08       	rol    r8w,0x8
    17b9:	45 0f b7 c0          	movzx  r8d,r8w
    17bd:	41 89 d1             	mov    r9d,edx
    17c0:	41 c1 e9 10          	shr    r9d,0x10
    17c4:	49 01 f8             	add    r8,rdi
    17c7:	4b 8d 3c 01          	lea    rdi,[r9+r8*1]
    17cb:	48 81 c7 3b df 00 00 	add    rdi,0xdf3b
    17d2:	41 89 f8             	mov    r8d,edi
    17d5:	41 c1 e8 10          	shr    r8d,0x10
    17d9:	44 0f b7 cf          	movzx  r9d,di
    17dd:	4d 01 c1             	add    r9,r8
    17e0:	48 81 ff 00 00 01 00 	cmp    rdi,0x10000
    17e7:	4c 0f 42 cf          	cmovb  r9,rdi
    17eb:	44 89 cf             	mov    edi,r9d
    17ee:	c1 ef 10             	shr    edi,0x10
    17f1:	45 0f b7 c1          	movzx  r8d,r9w
    17f5:	49 01 f8             	add    r8,rdi
    17f8:	49 81 f9 00 00 01 00 	cmp    r9,0x10000
    17ff:	4d 0f 42 c1          	cmovb  r8,r9
    1803:	44 89 c7             	mov    edi,r8d
    1806:	c1 ef 10             	shr    edi,0x10
    1809:	45 0f b7 c8          	movzx  r9d,r8w
    180d:	49 01 f9             	add    r9,rdi
    1810:	49 81 f8 00 00 01 00 	cmp    r8,0x10000
    1817:	4d 0f 42 c8          	cmovb  r9,r8
    181b:	44 89 cf             	mov    edi,r9d
    181e:	c1 ef 10             	shr    edi,0x10
    1821:	44 01 cf             	add    edi,r9d
    1824:	4d 31 da             	xor    r10,r11
    1827:	81 ca ac 10 00 00    	or     edx,0x10ac
    182d:	48 c1 e2 20          	shl    rdx,0x20
    1831:	48 81 ca 0a c8 00 02 	or     rdx,0x200c80a
    1838:	49 81 f9 00 00 01 00 	cmp    r9,0x10000
    183f:	41 0f 42 f9          	cmovb  edi,r9d
    1843:	c1 e7 10             	shl    edi,0x10
    1846:	48 31 f2             	xor    rdx,rsi
    1849:	48 be 0b 00 ff ff 00 	movabs rsi,0x200ffff000b
    1850:	02 00 00 
    1853:	48 31 d6             	xor    rsi,rdx
    1856:	48 31 fe             	xor    rsi,rdi
    1859:	4c 89 d2             	mov    rdx,r10
    185c:	48 c1 e2 06          	shl    rdx,0x6
    1860:	4c 89 d7             	mov    rdi,r10
    1863:	48 c1 ef 02          	shr    rdi,0x2
    1867:	48 01 f7             	add    rdi,rsi
    186a:	48 01 c2             	add    rdx,rax
    186d:	48 01 fa             	add    rdx,rdi
    1870:	4c 31 d2             	xor    rdx,r10
    1873:	48 89 d6             	mov    rsi,rdx
    1876:	48 c1 e6 06          	shl    rsi,0x6
    187a:	48 01 c6             	add    rsi,rax
    187d:	48 89 d7             	mov    rdi,rdx
    1880:	48 c1 ef 02          	shr    rdi,0x2
    1884:	48 01 fe             	add    rsi,rdi
    1887:	48 83 c6 03          	add    rsi,0x3
    188b:	48 31 d6             	xor    rsi,rdx
    188e:	41 b9 03 00 00 00    	mov    r9d,0x3
    1894:	e9 57 fd ff ff       	jmp    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0>

Disassembly of section .fini:
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
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  24:	48 39 f7             	cmp    rdi,rsi
  27:	0f 87 79 05 00 00    	ja     0x5a6
  2d:	49 89 f8             	mov    r8,rdi
  30:	49 83 c0 08          	add    r8,0x8
  34:	49 39 f0             	cmp    r8,rsi
  37:	0f 87 69 05 00 00    	ja     0x5a6
  3d:	48 89 fa             	mov    rdx,rdi
  40:	48 83 c2 16          	add    rdx,0x16
  44:	48 39 f2             	cmp    rdx,rsi
  47:	0f 87 59 05 00 00    	ja     0x5a6
  4d:	48 89 f1             	mov    rcx,rsi
  50:	4c 29 c1             	sub    rcx,r8
  53:	48 0f b6 47 14       	movzx  rax,BYTE PTR [rdi+0x14]
  58:	4c 0f b6 47 15       	movzx  r8,BYTE PTR [rdi+0x15]
  5d:	49 c1 e0 08          	shl    r8,0x8
  61:	49 09 c0             	or     r8,rax
  64:	49 81 e0 ff ff 00 00 	and    r8,0xffff
  6b:	49 81 f8 86 dd 00 00 	cmp    r8,0xdd86
  72:	0f 84 4e 04 00 00    	je     0x4c6
  78:	49 83 f8 08          	cmp    r8,0x8
  7c:	0f 85 7f 04 00 00    	jne    0x501
  82:	49 89 f8             	mov    r8,rdi
  85:	49 83 c0 2a          	add    r8,0x2a
  89:	49 39 f0             	cmp    r8,rsi
  8c:	0f 87 61 04 00 00    	ja     0x4f3
  92:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
  97:	48 83 e2 0f          	and    rdx,0xf
  9b:	48 83 fa 05          	cmp    rdx,0x5
  9f:	0f 85 4e 04 00 00    	jne    0x4f3
  a5:	48 0f b6 57 1c       	movzx  rdx,BYTE PTR [rdi+0x1c]
  aa:	48 83 e2 3f          	and    rdx,0x3f
  ae:	4c 0f b6 47 1d       	movzx  r8,BYTE PTR [rdi+0x1d]
  b3:	4c 09 c2             	or     rdx,r8
  b6:	48 81 e2 ff 00 00 00 	and    rdx,0xff
  bd:	48 85 d2             	test   rdx,rdx
  c0:	0f 85 2d 04 00 00    	jne    0x4f3
  c6:	48 0f b6 57 1f       	movzx  rdx,BYTE PTR [rdi+0x1f]
  cb:	41 b8 02 00 00 00    	mov    r8d,0x2
  d1:	41 be 02 00 00 00    	mov    r14d,0x2
  d7:	48 83 fa 01          	cmp    rdx,0x1
  db:	0f 84 54 04 00 00    	je     0x535
  e1:	48 83 fa 11          	cmp    rdx,0x11
  e5:	0f 84 75 0c 00 00    	je     0xd60
  eb:	48 83 fa 06          	cmp    rdx,0x6
  ef:	0f 85 40 04 00 00    	jne    0x535
  f5:	48 89 fa             	mov    rdx,rdi
  f8:	48 83 c2 3e          	add    rdx,0x3e
  fc:	41 b8 01 00 00 00    	mov    r8d,0x1
 102:	41 be 01 00 00 00    	mov    r14d,0x1
 108:	48 39 f2             	cmp    rdx,rsi
 10b:	0f 87 24 04 00 00    	ja     0x535
 111:	48 0f b6 77 27       	movzx  rsi,BYTE PTR [rdi+0x27]
 116:	48 c1 e6 08          	shl    rsi,0x8
 11a:	48 0f b6 57 26       	movzx  rdx,BYTE PTR [rdi+0x26]
 11f:	48 09 d6             	or     rsi,rdx
 122:	48 0f b6 57 28       	movzx  rdx,BYTE PTR [rdi+0x28]
 127:	48 c1 e2 10          	shl    rdx,0x10
 12b:	48 09 d6             	or     rsi,rdx
 12e:	48 0f b6 57 29       	movzx  rdx,BYTE PTR [rdi+0x29]
 133:	48 c1 e2 18          	shl    rdx,0x18
 137:	48 09 d6             	or     rsi,rdx
 13a:	48 c1 e6 20          	shl    rsi,0x20
 13e:	48 c1 ee 20          	shr    rsi,0x20
 142:	41 b8 02 00 00 00    	mov    r8d,0x2
 148:	41 be 02 00 00 00    	mov    r14d,0x2
 14e:	48 81 fe 0a 64 01 01 	cmp    rsi,0x101640a
 155:	0f 85 da 03 00 00    	jne    0x535
 15b:	48 0f b6 77 2d       	movzx  rsi,BYTE PTR [rdi+0x2d]
 160:	48 c1 e6 08          	shl    rsi,0x8
 164:	48 0f b6 57 2c       	movzx  rdx,BYTE PTR [rdi+0x2c]
 169:	48 09 d6             	or     rsi,rdx
 16c:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 173:	48 81 fe 1f 90 00 00 	cmp    rsi,0x901f
 17a:	0f 85 b5 03 00 00    	jne    0x535
 180:	41 b8 01 00 00 00    	mov    r8d,0x1
 186:	41 be 01 00 00 00    	mov    r14d,0x1
 18c:	48 81 f9 ea 05 00 00 	cmp    rcx,0x5ea
 193:	0f 8f 9c 03 00 00    	jg     0x535
 199:	48 0f b6 5f 18       	movzx  rbx,BYTE PTR [rdi+0x18]
 19e:	48 c1 e3 08          	shl    rbx,0x8
 1a2:	48 0f b6 77 19       	movzx  rsi,BYTE PTR [rdi+0x19]
 1a7:	48 09 f3             	or     rbx,rsi
 1aa:	48 0f b6 4f 17       	movzx  rcx,BYTE PTR [rdi+0x17]
 1af:	4c 0f b6 6f 23       	movzx  r13,BYTE PTR [rdi+0x23]
 1b4:	49 c1 e5 08          	shl    r13,0x8
 1b8:	4c 0f b6 47 22       	movzx  r8,BYTE PTR [rdi+0x22]
 1bd:	4c 0f b6 77 24       	movzx  r14,BYTE PTR [rdi+0x24]
 1c2:	49 c1 e6 10          	shl    r14,0x10
 1c6:	48 0f b6 77 25       	movzx  rsi,BYTE PTR [rdi+0x25]
 1cb:	48 c1 e6 18          	shl    rsi,0x18
 1cf:	48 0f b6 57 2a       	movzx  rdx,BYTE PTR [rdi+0x2a]
 1d4:	4c 0f b6 7f 2b       	movzx  r15,BYTE PTR [rdi+0x2b]
 1d9:	49 c1 e7 08          	shl    r15,0x8
 1dd:	49 09 d7             	or     r15,rdx
 1e0:	48 89 f0             	mov    rax,rsi
 1e3:	4c 09 f0             	or     rax,r14
 1e6:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 1ea:	4c 89 fa             	mov    rdx,r15
 1ed:	0f ca                	bswap  edx
 1ef:	41 bf 00 00 ff ff    	mov    r15d,0xffff0000
 1f5:	4c 21 fa             	and    rdx,r15
 1f8:	48 31 c2             	xor    rdx,rax
 1fb:	48 89 5d f0          	mov    QWORD PTR [rbp-0x10],rbx
 1ff:	48 89 d8             	mov    rax,rbx
 202:	48 83 c0 14          	add    rax,0x14
 206:	66 c1 c8 08          	ror    ax,0x8
 20a:	0f b7 c0             	movzx  eax,ax
 20d:	48 01 c1             	add    rcx,rax
 210:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 214:	48 89 d0             	mov    rax,rdx
 217:	4c 21 f8             	and    rax,r15
 21a:	48 c1 e8 10          	shr    rax,0x10
 21e:	48 01 c1             	add    rcx,rax
 221:	48 81 c1 3b df 00 00 	add    rcx,0xdf3b
 228:	b8 00 00 01 00       	mov    eax,0x10000
 22d:	48 39 c8             	cmp    rax,rcx
 230:	77 11                	ja     0x243
 232:	49 89 cf             	mov    r15,rcx
 235:	49 c1 ef 10          	shr    r15,0x10
 239:	48 81 e1 ff ff 00 00 	and    rcx,0xffff
 240:	4c 01 f9             	add    rcx,r15
 243:	4d 09 c5             	or     r13,r8
 246:	48 39 c8             	cmp    rax,rcx
 249:	77 11                	ja     0x25c
 24b:	49 89 c8             	mov    r8,rcx
 24e:	49 c1 e8 10          	shr    r8,0x10
 252:	48 81 e1 ff ff 00 00 	and    rcx,0xffff
 259:	4c 01 c1             	add    rcx,r8
 25c:	4d 09 f5             	or     r13,r14
 25f:	49 09 f5             	or     r13,rsi
 262:	4c 89 ee             	mov    rsi,r13
 265:	48 c1 e6 20          	shl    rsi,0x20
 269:	48 c1 ee 20          	shr    rsi,0x20
 26d:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 274:	79 37 9e 
 277:	48 01 d6             	add    rsi,rdx
 27a:	49 89 f0             	mov    r8,rsi
 27d:	49 c1 e0 06          	shl    r8,0x6
 281:	49 89 f7             	mov    r15,rsi
 284:	49 c1 ef 02          	shr    r15,0x2
 288:	4d 01 c7             	add    r15,r8
 28b:	49 b8 1f e0 4b 80 b9 	movabs r8,0x9e3779b9804be01f
 292:	79 37 9e 
 295:	4d 01 c7             	add    r15,r8
 298:	49 31 f7             	xor    r15,rsi
 29b:	48 8b 5d e8          	mov    rbx,QWORD PTR [rbp-0x18]
 29f:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 2a6:	48 89 da             	mov    rdx,rbx
 2a9:	48 81 c2 f7 c0 cc 70 	add    rdx,0x70ccc0f7
 2b0:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
 2b4:	49 89 d0             	mov    r8,rdx
 2b7:	49 c1 e0 0e          	shl    r8,0xe
 2bb:	49 81 c8 33 1c 00 00 	or     r8,0x1c33
 2c2:	48 81 f2 f7 c0 ad e0 	xor    rdx,0xffffffffe0adc0f7
 2c9:	4c 29 c2             	sub    rdx,r8
 2cc:	4d 89 f8             	mov    r8,r15
 2cf:	49 c1 e8 02          	shr    r8,0x2
 2d3:	4d 89 fe             	mov    r14,r15
 2d6:	49 c1 e6 06          	shl    r14,0x6
 2da:	4d 01 c6             	add    r14,r8
 2dd:	41 b8 00 00 e0 ff    	mov    r8d,0xffe00000
 2e3:	48 89 d6             	mov    rsi,rdx
 2e6:	4c 21 c6             	and    rsi,r8
 2e9:	48 c1 ee 15          	shr    rsi,0x15
 2ed:	48 89 d0             	mov    rax,rdx
 2f0:	48 c1 e0 0b          	shl    rax,0xb
 2f4:	48 09 f0             	or     rax,rsi
 2f7:	49 81 c5 f7 c0 ad e0 	add    r13,0xffffffffe0adc0f7
 2fe:	49 89 d0             	mov    r8,rdx
 301:	4d 31 e8             	xor    r8,r13
 304:	49 29 c0             	sub    r8,rax
 307:	49 01 de             	add    r14,rbx
 30a:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 30e:	48 c1 e0 20          	shl    rax,0x20
 312:	48 be 0a c8 00 02 ac 	movabs rsi,0x10ac0200c80a
 319:	10 00 00 
 31c:	48 09 f0             	or     rax,rsi
 31f:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
 323:	be 80 ff ff ff       	mov    esi,0xffffff80
 328:	4c 89 c0             	mov    rax,r8
 32b:	48 21 f0             	and    rax,rsi
 32e:	48 c1 e8 07          	shr    rax,0x7
 332:	4c 89 c6             	mov    rsi,r8
 335:	48 c1 e6 19          	shl    rsi,0x19
 339:	48 09 c6             	or     rsi,rax
 33c:	4d 89 c5             	mov    r13,r8
 33f:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 343:	49 31 c5             	xor    r13,rax
 346:	49 29 f5             	sub    r13,rsi
 349:	4c 89 ee             	mov    rsi,r13
 34c:	b8 00 00 ff ff       	mov    eax,0xffff0000
 351:	48 21 c6             	and    rsi,rax
 354:	48 c1 ee 10          	shr    rsi,0x10
 358:	4c 89 e8             	mov    rax,r13
 35b:	48 c1 e0 10          	shl    rax,0x10
 35f:	48 09 f0             	or     rax,rsi
 362:	4c 89 eb             	mov    rbx,r13
 365:	48 31 d3             	xor    rbx,rdx
 368:	48 29 c3             	sub    rbx,rax
 36b:	48 be 15 7c 69 0f ba 	movabs rsi,0x9e3779ba0f697c15
 372:	79 37 9e 
 375:	49 01 f6             	add    r14,rsi
 378:	4d 31 fe             	xor    r14,r15
 37b:	be 00 00 00 f0       	mov    esi,0xf0000000
 380:	48 89 da             	mov    rdx,rbx
 383:	48 21 f2             	and    rdx,rsi
 386:	48 c1 ea 1c          	shr    rdx,0x1c
 38a:	49 89 df             	mov    r15,rbx
 38d:	49 c1 e7 04          	shl    r15,0x4
 391:	49 09 d7             	or     r15,rdx
 394:	4c 89 f6             	mov    rsi,r14
 397:	48 c1 ee 02          	shr    rsi,0x2
 39b:	4c 89 f0             	mov    rax,r14
 39e:	48 c1 e0 06          	shl    rax,0x6
 3a2:	48 01 f0             	add    rax,rsi
 3a5:	48 89 de             	mov    rsi,rbx
 3a8:	4c 31 c6             	xor    rsi,r8
 3ab:	4c 29 fe             	sub    rsi,r15
 3ae:	ba 00 00 fc ff       	mov    edx,0xfffc0000
 3b3:	49 89 f0             	mov    r8,rsi
 3b6:	49 21 d0             	and    r8,rdx
 3b9:	49 c1 e8 12          	shr    r8,0x12
 3bd:	48 89 f2             	mov    rdx,rsi
 3c0:	48 c1 e2 0e          	shl    rdx,0xe
 3c4:	4c 09 c2             	or     rdx,r8
 3c7:	4c 31 ee             	xor    rsi,r13
 3ca:	48 29 d6             	sub    rsi,rdx
 3cd:	ba 00 ff ff ff       	mov    edx,0xffffff00
 3d2:	49 89 f0             	mov    r8,rsi
 3d5:	49 21 d0             	and    r8,rdx
 3d8:	49 c1 e8 08          	shr    r8,0x8
 3dc:	48 89 f2             	mov    rdx,rsi
 3df:	48 c1 e2 18          	shl    rdx,0x18
 3e3:	4c 09 c2             	or     rdx,r8
 3e6:	48 31 de             	xor    rsi,rbx
 3e9:	48 29 d6             	sub    rsi,rdx
 3ec:	48 c1 e1 10          	shl    rcx,0x10
 3f0:	48 c1 e1 20          	shl    rcx,0x20
 3f4:	48 c1 e9 20          	shr    rcx,0x20
 3f8:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 3fc:	48 31 cb             	xor    rbx,rcx
 3ff:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
 403:	49 81 e0 ff ff 00 00 	and    r8,0xffff
 40a:	4c 31 c3             	xor    rbx,r8
 40d:	48 ba 0b 00 ff ff 00 	movabs rdx,0x200ffff000b
 414:	02 00 00 
 417:	48 31 d3             	xor    rbx,rdx
 41a:	48 c1 e6 20          	shl    rsi,0x20
 41e:	48 c1 ee 20          	shr    rsi,0x20
 422:	50                   	push   rax
 423:	52                   	push   rdx
 424:	49 c7 c3 01 00 01 00 	mov    r11,0x10001
 42b:	48 89 f0             	mov    rax,rsi
 42e:	31 d2                	xor    edx,edx
 430:	49 f7 f3             	div    r11
 433:	48 89 d6             	mov    rsi,rdx
 436:	5a                   	pop    rdx
 437:	58                   	pop    rax
 438:	48 01 f0             	add    rax,rsi
 43b:	48 be 15 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c15
 442:	79 37 9e 
 445:	48 01 f0             	add    rax,rsi
 448:	4c 31 f0             	xor    rax,r14
 44b:	48 89 c6             	mov    rsi,rax
 44e:	48 c1 ee 02          	shr    rsi,0x2
 452:	48 89 c2             	mov    rdx,rax
 455:	48 c1 e2 06          	shl    rdx,0x6
 459:	48 01 f2             	add    rdx,rsi
 45c:	48 be 16 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c16
 463:	79 37 9e 
 466:	48 01 f2             	add    rdx,rsi
 469:	48 31 c2             	xor    rdx,rax
 46c:	48 89 d6             	mov    rsi,rdx
 46f:	48 c1 ee 02          	shr    rsi,0x2
 473:	48 89 d1             	mov    rcx,rdx
 476:	48 c1 e1 06          	shl    rcx,0x6
 47a:	48 01 f1             	add    rcx,rsi
 47d:	48 b8 15 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c15
 484:	79 37 9e 
 487:	48 01 c1             	add    rcx,rax
 48a:	48 31 d1             	xor    rcx,rdx
 48d:	48 89 ce             	mov    rsi,rcx
 490:	48 c1 e6 06          	shl    rsi,0x6
 494:	49 01 f0             	add    r8,rsi
 497:	48 89 ce             	mov    rsi,rcx
 49a:	48 c1 ee 02          	shr    rsi,0x2
 49e:	49 01 f0             	add    r8,rsi
 4a1:	49 01 c0             	add    r8,rax
 4a4:	49 31 c8             	xor    r8,rcx
 4a7:	4c 89 c6             	mov    rsi,r8
 4aa:	48 c1 ee 02          	shr    rsi,0x2
 4ae:	4c 89 c2             	mov    rdx,r8
 4b1:	48 c1 e2 06          	shl    rdx,0x6
 4b5:	48 01 f2             	add    rdx,rsi
 4b8:	48 01 da             	add    rdx,rbx
 4bb:	48 01 c2             	add    rdx,rax
 4be:	4c 31 c2             	xor    rdx,r8
 4c1:	e9 6e 08 00 00       	jmp    0xd34
 4c6:	48 89 fa             	mov    rdx,rdi
 4c9:	48 83 c2 3e          	add    rdx,0x3e
 4cd:	48 39 f2             	cmp    rdx,rsi
 4d0:	77 21                	ja     0x4f3
 4d2:	48 0f b6 5f 1c       	movzx  rbx,BYTE PTR [rdi+0x1c]
 4d7:	41 b8 02 00 00 00    	mov    r8d,0x2
 4dd:	41 be 02 00 00 00    	mov    r14d,0x2
 4e3:	48 83 fb 3a          	cmp    rbx,0x3a
 4e7:	74 4c                	je     0x535
 4e9:	48 83 fb 2c          	cmp    rbx,0x2c
 4ed:	0f 85 bc 00 00 00    	jne    0x5af
 4f3:	41 b8 01 00 00 00    	mov    r8d,0x1
 4f9:	41 be 01 00 00 00    	mov    r14d,0x1
 4ff:	eb 34                	jmp    0x535
 501:	48 be 15 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c15
 508:	79 37 9e 
 50b:	48 01 f1             	add    rcx,rsi
 50e:	48 89 ce             	mov    rsi,rcx
 511:	48 c1 ee 02          	shr    rsi,0x2
 515:	49 89 c8             	mov    r8,rcx
 518:	49 c1 e0 06          	shl    r8,0x6
 51c:	49 01 f0             	add    r8,rsi
 51f:	48 be 17 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c17
 526:	79 37 9e 
 529:	49 01 f0             	add    r8,rsi
 52c:	49 31 c8             	xor    r8,rcx
 52f:	41 be 02 00 00 00    	mov    r14d,0x2
 535:	4c 89 c2             	mov    rdx,r8
 538:	48 c1 ea 02          	shr    rdx,0x2
 53c:	4c 89 c6             	mov    rsi,r8
 53f:	48 c1 e6 06          	shl    rsi,0x6
 543:	48 01 d6             	add    rsi,rdx
 546:	4c 01 f6             	add    rsi,r14
 549:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 550:	79 37 9e 
 553:	48 01 d6             	add    rsi,rdx
 556:	4c 31 c6             	xor    rsi,r8
 559:	48 89 f2             	mov    rdx,rsi
 55c:	48 c1 ea 38          	shr    rdx,0x38
 560:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 563:	48 89 f2             	mov    rdx,rsi
 566:	48 c1 ea 30          	shr    rdx,0x30
 56a:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 56d:	48 89 f2             	mov    rdx,rsi
 570:	48 c1 ea 28          	shr    rdx,0x28
 574:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 577:	48 89 f2             	mov    rdx,rsi
 57a:	48 c1 ea 20          	shr    rdx,0x20
 57e:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 581:	48 89 f2             	mov    rdx,rsi
 584:	48 c1 ea 18          	shr    rdx,0x18
 588:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
 58b:	48 89 f2             	mov    rdx,rsi
 58e:	48 c1 ea 10          	shr    rdx,0x10
 592:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
 595:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
 599:	48 c1 ee 08          	shr    rsi,0x8
 59d:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
 5a1:	b8 02 00 00 00       	mov    eax,0x2
 5a6:	41 5f                	pop    r15
 5a8:	41 5e                	pop    r14
 5aa:	41 5d                	pop    r13
 5ac:	5b                   	pop    rbx
 5ad:	c9                   	leave
 5ae:	c3                   	ret
 5af:	48 0f b6 57 1a       	movzx  rdx,BYTE PTR [rdi+0x1a]
 5b4:	48 89 55 f0          	mov    QWORD PTR [rbp-0x10],rdx
 5b8:	48 0f b6 57 1b       	movzx  rdx,BYTE PTR [rdi+0x1b]
 5bd:	48 89 95 58 ff ff ff 	mov    QWORD PTR [rbp-0xa8],rdx
 5c4:	48 0f b6 57 16       	movzx  rdx,BYTE PTR [rdi+0x16]
 5c9:	48 89 95 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rdx
 5d0:	48 0f b6 57 17       	movzx  rdx,BYTE PTR [rdi+0x17]
 5d5:	48 89 95 60 ff ff ff 	mov    QWORD PTR [rbp-0xa0],rdx
 5dc:	48 0f b6 57 23       	movzx  rdx,BYTE PTR [rdi+0x23]
 5e1:	48 89 55 a8          	mov    QWORD PTR [rbp-0x58],rdx
 5e5:	48 0f b6 57 22       	movzx  rdx,BYTE PTR [rdi+0x22]
 5ea:	48 89 95 68 ff ff ff 	mov    QWORD PTR [rbp-0x98],rdx
 5f1:	48 0f b6 57 27       	movzx  rdx,BYTE PTR [rdi+0x27]
 5f6:	48 89 55 98          	mov    QWORD PTR [rbp-0x68],rdx
 5fa:	48 0f b6 57 26       	movzx  rdx,BYTE PTR [rdi+0x26]
 5ff:	48 89 95 70 ff ff ff 	mov    QWORD PTR [rbp-0x90],rdx
 606:	48 0f b6 57 28       	movzx  rdx,BYTE PTR [rdi+0x28]
 60b:	48 89 55 b8          	mov    QWORD PTR [rbp-0x48],rdx
 60f:	48 0f b6 57 24       	movzx  rdx,BYTE PTR [rdi+0x24]
 614:	48 89 55 c0          	mov    QWORD PTR [rbp-0x40],rdx
 618:	48 0f b6 57 1f       	movzx  rdx,BYTE PTR [rdi+0x1f]
 61d:	48 89 55 a0          	mov    QWORD PTR [rbp-0x60],rdx
 621:	48 0f b6 57 1e       	movzx  rdx,BYTE PTR [rdi+0x1e]
 626:	48 89 55 80          	mov    QWORD PTR [rbp-0x80],rdx
 62a:	48 0f b6 57 25       	movzx  rdx,BYTE PTR [rdi+0x25]
 62f:	48 89 55 88          	mov    QWORD PTR [rbp-0x78],rdx
 633:	48 0f b6 57 29       	movzx  rdx,BYTE PTR [rdi+0x29]
 638:	48 89 55 90          	mov    QWORD PTR [rbp-0x70],rdx
 63c:	48 0f b6 57 2a       	movzx  rdx,BYTE PTR [rdi+0x2a]
 641:	48 89 55 b0          	mov    QWORD PTR [rbp-0x50],rdx
 645:	48 0f b6 57 2e       	movzx  rdx,BYTE PTR [rdi+0x2e]
 64a:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 64e:	48 0f b6 57 2b       	movzx  rdx,BYTE PTR [rdi+0x2b]
 653:	48 89 55 e0          	mov    QWORD PTR [rbp-0x20],rdx
 657:	48 0f b6 57 2c       	movzx  rdx,BYTE PTR [rdi+0x2c]
 65c:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
 660:	48 0f b6 57 2d       	movzx  rdx,BYTE PTR [rdi+0x2d]
 665:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
 669:	48 0f b6 57 2f       	movzx  rdx,BYTE PTR [rdi+0x2f]
 66e:	48 0f b6 47 30       	movzx  rax,BYTE PTR [rdi+0x30]
 673:	4c 0f b6 7f 31       	movzx  r15,BYTE PTR [rdi+0x31]
 678:	4c 0f b6 47 20       	movzx  r8,BYTE PTR [rdi+0x20]
 67d:	4c 89 45 c8          	mov    QWORD PTR [rbp-0x38],r8
 681:	4c 0f b6 47 21       	movzx  r8,BYTE PTR [rdi+0x21]
 686:	4c 89 45 d0          	mov    QWORD PTR [rbp-0x30],r8
 68a:	48 83 fb 11          	cmp    rbx,0x11
 68e:	74 2e                	je     0x6be
 690:	41 b8 02 00 00 00    	mov    r8d,0x2
 696:	48 83 fb 06          	cmp    rbx,0x6
 69a:	0f 85 95 fe ff ff    	jne    0x535
 6a0:	41 b8 01 00 00 00    	mov    r8d,0x1
 6a6:	49 89 fd             	mov    r13,rdi
 6a9:	49 83 c5 52          	add    r13,0x52
 6ad:	41 be 01 00 00 00    	mov    r14d,0x1
 6b3:	49 39 f5             	cmp    r13,rsi
 6b6:	0f 87 79 fe ff ff    	ja     0x535
 6bc:	eb 1c                	jmp    0x6da
 6be:	41 b8 01 00 00 00    	mov    r8d,0x1
 6c4:	49 89 fd             	mov    r13,rdi
 6c7:	49 83 c5 46          	add    r13,0x46
 6cb:	41 be 01 00 00 00    	mov    r14d,0x1
 6d1:	49 39 f5             	cmp    r13,rsi
 6d4:	0f 87 5b fe ff ff    	ja     0x535
 6da:	41 b8 02 00 00 00    	mov    r8d,0x2
 6e0:	41 be 02 00 00 00    	mov    r14d,0x2
 6e6:	48 83 fb 06          	cmp    rbx,0x6
 6ea:	0f 85 45 fe ff ff    	jne    0x535
 6f0:	48 c1 e2 08          	shl    rdx,0x8
 6f4:	48 c1 e0 10          	shl    rax,0x10
 6f8:	49 c1 e7 18          	shl    r15,0x18
 6fc:	49 09 c7             	or     r15,rax
 6ff:	49 09 d7             	or     r15,rdx
 702:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 706:	49 09 f7             	or     r15,rsi
 709:	49 c1 e7 20          	shl    r15,0x20
 70d:	49 c1 ef 20          	shr    r15,0x20
 711:	49 81 ff 0a 64 01 01 	cmp    r15,0x101640a
 718:	0f 85 17 fe ff ff    	jne    0x535
 71e:	48 0f b6 77 41       	movzx  rsi,BYTE PTR [rdi+0x41]
 723:	48 c1 e6 08          	shl    rsi,0x8
 727:	48 0f b6 57 40       	movzx  rdx,BYTE PTR [rdi+0x40]
 72c:	48 09 d6             	or     rsi,rdx
 72f:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 736:	48 81 fe 1f 90 00 00 	cmp    rsi,0x901f
 73d:	0f 85 f2 fd ff ff    	jne    0x535
 743:	41 b8 01 00 00 00    	mov    r8d,0x1
 749:	41 be 01 00 00 00    	mov    r14d,0x1
 74f:	48 81 f9 ea 05 00 00 	cmp    rcx,0x5ea
 756:	0f 8f d9 fd ff ff    	jg     0x535
 75c:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
 760:	48 c1 e2 08          	shl    rdx,0x8
 764:	48 8b b5 58 ff ff ff 	mov    rsi,QWORD PTR [rbp-0xa8]
 76b:	48 09 f2             	or     rdx,rsi
 76e:	4c 8b b5 78 ff ff ff 	mov    r14,QWORD PTR [rbp-0x88]
 775:	49 c1 e6 04          	shl    r14,0x4
 779:	48 8b b5 60 ff ff ff 	mov    rsi,QWORD PTR [rbp-0xa0]
 780:	48 c1 ee 04          	shr    rsi,0x4
 784:	48 83 e6 0f          	and    rsi,0xf
 788:	49 09 f6             	or     r14,rsi
 78b:	4c 8b 7d a8          	mov    r15,QWORD PTR [rbp-0x58]
 78f:	49 c1 e7 08          	shl    r15,0x8
 793:	48 8b b5 68 ff ff ff 	mov    rsi,QWORD PTR [rbp-0x98]
 79a:	49 09 f7             	or     r15,rsi
 79d:	48 8b 5d 98          	mov    rbx,QWORD PTR [rbp-0x68]
 7a1:	48 c1 e3 08          	shl    rbx,0x8
 7a5:	48 8b b5 70 ff ff ff 	mov    rsi,QWORD PTR [rbp-0x90]
 7ac:	48 09 f3             	or     rbx,rsi
 7af:	48 8b 75 b8          	mov    rsi,QWORD PTR [rbp-0x48]
 7b3:	48 c1 e6 10          	shl    rsi,0x10
 7b7:	48 89 75 b8          	mov    QWORD PTR [rbp-0x48],rsi
 7bb:	48 8b 75 c0          	mov    rsi,QWORD PTR [rbp-0x40]
 7bf:	48 c1 e6 10          	shl    rsi,0x10
 7c3:	48 89 75 c0          	mov    QWORD PTR [rbp-0x40],rsi
 7c7:	4c 8b 45 a0          	mov    r8,QWORD PTR [rbp-0x60]
 7cb:	49 c1 e0 08          	shl    r8,0x8
 7cf:	48 8b 4d c8          	mov    rcx,QWORD PTR [rbp-0x38]
 7d3:	48 c1 e1 10          	shl    rcx,0x10
 7d7:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
 7db:	48 c1 e0 18          	shl    rax,0x18
 7df:	48 0f b6 77 3e       	movzx  rsi,BYTE PTR [rdi+0x3e]
 7e4:	4c 0f b6 6f 3f       	movzx  r13,BYTE PTR [rdi+0x3f]
 7e9:	49 c1 e5 08          	shl    r13,0x8
 7ed:	49 09 f5             	or     r13,rsi
 7f0:	48 89 4d c8          	mov    QWORD PTR [rbp-0x38],rcx
 7f4:	48 89 ce             	mov    rsi,rcx
 7f7:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
 7fb:	48 09 c6             	or     rsi,rax
 7fe:	4c 89 6d a8          	mov    QWORD PTR [rbp-0x58],r13
 802:	41 0f cd             	bswap  r13d
 805:	b9 00 00 ff ff       	mov    ecx,0xffff0000
 80a:	49 21 cd             	and    r13,rcx
 80d:	49 31 f5             	xor    r13,rsi
 810:	49 81 e6 ff 00 00 00 	and    r14,0xff
 817:	48 89 55 f0          	mov    QWORD PTR [rbp-0x10],rdx
 81b:	48 89 d6             	mov    rsi,rdx
 81e:	48 83 c6 14          	add    rsi,0x14
 822:	66 c1 ce 08          	ror    si,0x8
 826:	0f b7 f6             	movzx  esi,si
 829:	4c 01 f6             	add    rsi,r14
 82c:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 830:	4c 89 ea             	mov    rdx,r13
 833:	48 21 ca             	and    rdx,rcx
 836:	48 c1 ea 10          	shr    rdx,0x10
 83a:	48 01 d6             	add    rsi,rdx
 83d:	48 81 c6 3b df 00 00 	add    rsi,0xdf3b
 844:	41 be 00 00 01 00    	mov    r14d,0x10000
 84a:	49 39 f6             	cmp    r14,rsi
 84d:	77 11                	ja     0x860
 84f:	48 89 f1             	mov    rcx,rsi
 852:	48 c1 e9 10          	shr    rcx,0x10
 856:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 85d:	48 01 ce             	add    rsi,rcx
 860:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 864:	48 09 d3             	or     rbx,rdx
 867:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
 86b:	49 09 d7             	or     r15,rdx
 86e:	48 8b 55 80          	mov    rdx,QWORD PTR [rbp-0x80]
 872:	49 09 d0             	or     r8,rdx
 875:	48 8b 55 88          	mov    rdx,QWORD PTR [rbp-0x78]
 879:	48 c1 e2 18          	shl    rdx,0x18
 87d:	4c 8b 6d 90          	mov    r13,QWORD PTR [rbp-0x70]
 881:	49 c1 e5 18          	shl    r13,0x18
 885:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 889:	49 39 f6             	cmp    r14,rsi
 88c:	77 11                	ja     0x89f
 88e:	48 89 f1             	mov    rcx,rsi
 891:	48 c1 e9 10          	shr    rcx,0x10
 895:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 89c:	48 01 ce             	add    rsi,rcx
 89f:	49 09 d7             	or     r15,rdx
 8a2:	4c 09 eb             	or     rbx,r13
 8a5:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
 8a9:	49 09 d0             	or     r8,rdx
 8ac:	41 bd 00 00 01 00    	mov    r13d,0x10000
 8b2:	48 8b 4d e0          	mov    rcx,QWORD PTR [rbp-0x20]
 8b6:	48 c1 e1 08          	shl    rcx,0x8
 8ba:	48 89 4d e0          	mov    QWORD PTR [rbp-0x20],rcx
 8be:	48 8b 4d d8          	mov    rcx,QWORD PTR [rbp-0x28]
 8c2:	48 c1 e1 10          	shl    rcx,0x10
 8c6:	48 89 4d d8          	mov    QWORD PTR [rbp-0x28],rcx
 8ca:	48 c1 e0 18          	shl    rax,0x18
 8ce:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
 8d2:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 8d6:	49 09 d0             	or     r8,rdx
 8d9:	49 89 de             	mov    r14,rbx
 8dc:	49 81 c6 ff c0 ad de 	add    r14,0xffffffffdeadc0ff
 8e3:	49 81 c7 ff c0 ad de 	add    r15,0xffffffffdeadc0ff
 8ea:	4c 89 c1             	mov    rcx,r8
 8ed:	48 c1 e1 20          	shl    rcx,0x20
 8f1:	48 c1 e9 20          	shr    rcx,0x20
 8f5:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 8fc:	79 37 9e 
 8ff:	48 01 d1             	add    rcx,rdx
 902:	48 89 c8             	mov    rax,rcx
 905:	48 c1 e8 02          	shr    rax,0x2
 909:	48 89 ca             	mov    rdx,rcx
 90c:	48 c1 e2 06          	shl    rdx,0x6
 910:	48 01 c2             	add    rdx,rax
 913:	48 b8 1f e0 4b 80 b9 	movabs rax,0x9e3779b9804be01f
 91a:	79 37 9e 
 91d:	48 01 c2             	add    rdx,rax
 920:	49 29 d8             	sub    r8,rbx
 923:	bb 00 00 00 f0       	mov    ebx,0xf0000000
 928:	4c 89 f0             	mov    rax,r14
 92b:	48 21 d8             	and    rax,rbx
 92e:	48 c1 e8 1c          	shr    rax,0x1c
 932:	4c 89 f3             	mov    rbx,r14
 935:	48 c1 e3 04          	shl    rbx,0x4
 939:	48 09 c3             	or     rbx,rax
 93c:	48 31 ca             	xor    rdx,rcx
 93f:	49 31 d8             	xor    r8,rbx
 942:	b9 00 00 00 fc       	mov    ecx,0xfc000000
 947:	4c 89 c0             	mov    rax,r8
 94a:	48 21 c8             	and    rax,rcx
 94d:	48 c1 e8 1a          	shr    rax,0x1a
 951:	4c 89 c1             	mov    rcx,r8
 954:	48 c1 e1 06          	shl    rcx,0x6
 958:	48 09 c1             	or     rcx,rax
 95b:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 95f:	48 25 ff ff 00 00    	and    rax,0xffff
 965:	48 89 d3             	mov    rbx,rdx
 968:	48 c1 e3 06          	shl    rbx,0x6
 96c:	48 01 c3             	add    rbx,rax
 96f:	49 89 c5             	mov    r13,rax
 972:	48 89 d0             	mov    rax,rdx
 975:	48 c1 e8 02          	shr    rax,0x2
 979:	48 01 c3             	add    rbx,rax
 97c:	4d 01 fe             	add    r14,r15
 97f:	4d 29 c7             	sub    r15,r8
 982:	49 31 cf             	xor    r15,rcx
 985:	b9 00 00 00 ff       	mov    ecx,0xff000000
 98a:	4c 89 f8             	mov    rax,r15
 98d:	48 21 c8             	and    rax,rcx
 990:	48 c1 e8 18          	shr    rax,0x18
 994:	4c 89 f9             	mov    rcx,r15
 997:	48 c1 e1 08          	shl    rcx,0x8
 99b:	48 09 c1             	or     rcx,rax
 99e:	48 b8 15 7c 69 0f ba 	movabs rax,0x9e3779ba0f697c15
 9a5:	79 37 9e 
 9a8:	48 01 c3             	add    rbx,rax
 9ab:	48 89 5d d0          	mov    QWORD PTR [rbp-0x30],rbx
 9af:	4c 89 e8             	mov    rax,r13
 9b2:	48 05 f7 c0 cc 70    	add    rax,0x70ccc0f7
 9b8:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
 9bc:	49 89 c5             	mov    r13,rax
 9bf:	49 c1 e5 0e          	shl    r13,0xe
 9c3:	49 81 cd 33 1c 00 00 	or     r13,0x1c33
 9ca:	48 35 f7 c0 ad e0    	xor    rax,0xffffffffe0adc0f7
 9d0:	4c 29 e8             	sub    rax,r13
 9d3:	48 89 c3             	mov    rbx,rax
 9d6:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 9da:	49 c1 e5 20          	shl    r13,0x20
 9de:	48 b8 0a c8 00 02 ac 	movabs rax,0x10ac0200c80a
 9e5:	10 00 00 
 9e8:	49 09 c5             	or     r13,rax
 9eb:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 9ef:	4d 01 f0             	add    r8,r14
 9f2:	4d 29 fe             	sub    r14,r15
 9f5:	49 31 ce             	xor    r14,rcx
 9f8:	4c 89 f1             	mov    rcx,r14
 9fb:	b8 00 00 ff ff       	mov    eax,0xffff0000
 a00:	48 21 c1             	and    rcx,rax
 a03:	48 c1 e9 10          	shr    rcx,0x10
 a07:	4c 89 f0             	mov    rax,r14
 a0a:	48 c1 e0 10          	shl    rax,0x10
 a0e:	48 09 c8             	or     rax,rcx
 a11:	48 8b 4d d0          	mov    rcx,QWORD PTR [rbp-0x30]
 a15:	48 31 d1             	xor    rcx,rdx
 a18:	48 89 4d d0          	mov    QWORD PTR [rbp-0x30],rcx
 a1c:	ba 00 00 e0 ff       	mov    edx,0xffe00000
 a21:	48 89 5d c8          	mov    QWORD PTR [rbp-0x38],rbx
 a25:	48 89 d9             	mov    rcx,rbx
 a28:	48 21 d1             	and    rcx,rdx
 a2b:	48 c1 e9 15          	shr    rcx,0x15
 a2f:	48 89 da             	mov    rdx,rbx
 a32:	48 c1 e2 0b          	shl    rdx,0xb
 a36:	48 09 ca             	or     rdx,rcx
 a39:	48 89 55 c0          	mov    QWORD PTR [rbp-0x40],rdx
 a3d:	4d 01 c7             	add    r15,r8
 a40:	4d 29 f0             	sub    r8,r14
 a43:	49 31 c0             	xor    r8,rax
 a46:	b9 00 e0 ff ff       	mov    ecx,0xffffe000
 a4b:	4c 89 c0             	mov    rax,r8
 a4e:	48 21 c8             	and    rax,rcx
 a51:	48 c1 e8 0d          	shr    rax,0xd
 a55:	4c 89 c1             	mov    rcx,r8
 a58:	48 c1 e1 13          	shl    rcx,0x13
 a5c:	48 09 c1             	or     rcx,rax
 a5f:	4d 01 fe             	add    r14,r15
 a62:	4d 29 c7             	sub    r15,r8
 a65:	49 31 cf             	xor    r15,rcx
 a68:	48 8b 5d d0          	mov    rbx,QWORD PTR [rbp-0x30]
 a6c:	48 89 d9             	mov    rcx,rbx
 a6f:	48 c1 e9 02          	shr    rcx,0x2
 a73:	48 c1 e3 06          	shl    rbx,0x6
 a77:	48 01 cb             	add    rbx,rcx
 a7a:	4d 01 f0             	add    r8,r14
 a7d:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 a81:	4c 01 c0             	add    rax,r8
 a84:	4c 89 f9             	mov    rcx,r15
 a87:	4c 01 c1             	add    rcx,r8
 a8a:	41 b8 00 00 fc ff    	mov    r8d,0xfffc0000
 a90:	49 89 cd             	mov    r13,rcx
 a93:	4d 21 c5             	and    r13,r8
 a96:	49 c1 ed 12          	shr    r13,0x12
 a9a:	49 89 c0             	mov    r8,rax
 a9d:	4c 89 f8             	mov    rax,r15
 aa0:	49 89 cf             	mov    r15,rcx
 aa3:	49 c1 e7 0e          	shl    r15,0xe
 aa7:	4d 09 ef             	or     r15,r13
 aaa:	49 89 c5             	mov    r13,rax
 aad:	ba 00 00 00 f0       	mov    edx,0xf0000000
 ab2:	49 21 d5             	and    r13,rdx
 ab5:	49 c1 ed 1c          	shr    r13,0x1c
 ab9:	49 29 c6             	sub    r14,rax
 abc:	48 c1 e0 04          	shl    rax,0x4
 ac0:	4c 09 e8             	or     rax,r13
 ac3:	49 31 c6             	xor    r14,rax
 ac6:	49 31 ce             	xor    r14,rcx
 ac9:	4d 29 fe             	sub    r14,r15
 acc:	4d 89 f5             	mov    r13,r14
 acf:	ba 00 00 e0 ff       	mov    edx,0xffe00000
 ad4:	49 21 d5             	and    r13,rdx
 ad7:	49 c1 ed 15          	shr    r13,0x15
 adb:	4c 89 f2             	mov    rdx,r14
 ade:	48 c1 e2 0b          	shl    rdx,0xb
 ae2:	4c 09 ea             	or     rdx,r13
 ae5:	48 c1 e6 10          	shl    rsi,0x10
 ae9:	48 c1 e6 20          	shl    rsi,0x20
 aed:	48 c1 ee 20          	shr    rsi,0x20
 af1:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 af5:	49 31 f5             	xor    r13,rsi
 af8:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 afc:	49 01 f0             	add    r8,rsi
 aff:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 b03:	49 01 f0             	add    r8,rsi
 b06:	48 8b 75 b0          	mov    rsi,QWORD PTR [rbp-0x50]
 b0a:	49 01 f0             	add    r8,rsi
 b0d:	4d 31 f0             	xor    r8,r14
 b10:	49 29 d0             	sub    r8,rdx
 b13:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 b17:	48 25 ff ff 00 00    	and    rax,0xffff
 b1d:	4c 89 ea             	mov    rdx,r13
 b20:	48 31 c2             	xor    rdx,rax
 b23:	48 be 0b 00 ff ff 00 	movabs rsi,0x200ffff000b
 b2a:	02 00 00 
 b2d:	48 31 f2             	xor    rdx,rsi
 b30:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 b34:	ba 80 ff ff ff       	mov    edx,0xffffff80
 b39:	4c 89 c6             	mov    rsi,r8
 b3c:	48 21 d6             	and    rsi,rdx
 b3f:	48 c1 ee 07          	shr    rsi,0x7
 b43:	4c 89 c2             	mov    rdx,r8
 b46:	48 c1 e2 19          	shl    rdx,0x19
 b4a:	48 09 f2             	or     rdx,rsi
 b4d:	4d 89 c5             	mov    r13,r8
 b50:	49 31 cd             	xor    r13,rcx
 b53:	49 29 d5             	sub    r13,rdx
 b56:	4c 89 ee             	mov    rsi,r13
 b59:	41 bf 00 00 ff ff    	mov    r15d,0xffff0000
 b5f:	4c 21 fe             	and    rsi,r15
 b62:	48 c1 ee 10          	shr    rsi,0x10
 b66:	4c 89 ea             	mov    rdx,r13
 b69:	48 c1 e2 10          	shl    rdx,0x10
 b6d:	48 09 f2             	or     rdx,rsi
 b70:	4c 89 ee             	mov    rsi,r13
 b73:	4c 31 f6             	xor    rsi,r14
 b76:	48 29 d6             	sub    rsi,rdx
 b79:	48 89 f2             	mov    rdx,rsi
 b7c:	41 be 00 00 00 f0    	mov    r14d,0xf0000000
 b82:	4c 21 f2             	and    rdx,r14
 b85:	48 c1 ea 1c          	shr    rdx,0x1c
 b89:	48 89 f1             	mov    rcx,rsi
 b8c:	48 c1 e1 04          	shl    rcx,0x4
 b90:	48 09 d1             	or     rcx,rdx
 b93:	48 89 f2             	mov    rdx,rsi
 b96:	4c 31 c2             	xor    rdx,r8
 b99:	48 29 ca             	sub    rdx,rcx
 b9c:	48 89 d1             	mov    rcx,rdx
 b9f:	41 b8 00 00 fc ff    	mov    r8d,0xfffc0000
 ba5:	4c 21 c1             	and    rcx,r8
 ba8:	48 c1 e9 12          	shr    rcx,0x12
 bac:	49 89 d0             	mov    r8,rdx
 baf:	49 c1 e0 0e          	shl    r8,0xe
 bb3:	49 09 c8             	or     r8,rcx
 bb6:	4c 31 ea             	xor    rdx,r13
 bb9:	4c 29 c2             	sub    rdx,r8
 bbc:	b9 00 ff ff ff       	mov    ecx,0xffffff00
 bc1:	49 89 d0             	mov    r8,rdx
 bc4:	49 21 c8             	and    r8,rcx
 bc7:	49 c1 e8 08          	shr    r8,0x8
 bcb:	49 89 d5             	mov    r13,rdx
 bce:	49 c1 e5 18          	shl    r13,0x18
 bd2:	4d 09 c5             	or     r13,r8
 bd5:	48 31 f2             	xor    rdx,rsi
 bd8:	4c 29 ea             	sub    rdx,r13
 bdb:	48 81 c2 f7 c0 ad e0 	add    rdx,0xffffffffe0adc0f7
 be2:	48 8b 4d c8          	mov    rcx,QWORD PTR [rbp-0x38]
 be6:	48 31 ca             	xor    rdx,rcx
 be9:	48 8b 75 c0          	mov    rsi,QWORD PTR [rbp-0x40]
 bed:	48 29 f2             	sub    rdx,rsi
 bf0:	48 89 d6             	mov    rsi,rdx
 bf3:	41 b8 80 ff ff ff    	mov    r8d,0xffffff80
 bf9:	4c 21 c6             	and    rsi,r8
 bfc:	48 c1 ee 07          	shr    rsi,0x7
 c00:	49 89 d0             	mov    r8,rdx
 c03:	49 c1 e0 19          	shl    r8,0x19
 c07:	49 09 f0             	or     r8,rsi
 c0a:	48 89 d6             	mov    rsi,rdx
 c0d:	4c 8b 6d a8          	mov    r13,QWORD PTR [rbp-0x58]
 c11:	4c 31 ee             	xor    rsi,r13
 c14:	4c 29 c6             	sub    rsi,r8
 c17:	49 89 f0             	mov    r8,rsi
 c1a:	4d 21 f8             	and    r8,r15
 c1d:	49 c1 e8 10          	shr    r8,0x10
 c21:	49 89 f5             	mov    r13,rsi
 c24:	49 c1 e5 10          	shl    r13,0x10
 c28:	4d 09 c5             	or     r13,r8
 c2b:	49 89 f0             	mov    r8,rsi
 c2e:	49 31 c8             	xor    r8,rcx
 c31:	4d 29 e8             	sub    r8,r13
 c34:	4d 89 c5             	mov    r13,r8
 c37:	4d 21 f5             	and    r13,r14
 c3a:	49 c1 ed 1c          	shr    r13,0x1c
 c3e:	4d 89 c6             	mov    r14,r8
 c41:	49 c1 e6 04          	shl    r14,0x4
 c45:	4d 09 ee             	or     r14,r13
 c48:	4d 89 c5             	mov    r13,r8
 c4b:	49 31 d5             	xor    r13,rdx
 c4e:	4d 29 f5             	sub    r13,r14
 c51:	4c 89 ea             	mov    rdx,r13
 c54:	b9 00 00 fc ff       	mov    ecx,0xfffc0000
 c59:	48 21 ca             	and    rdx,rcx
 c5c:	48 c1 ea 12          	shr    rdx,0x12
 c60:	4d 89 ee             	mov    r14,r13
 c63:	49 c1 e6 0e          	shl    r14,0xe
 c67:	49 09 d6             	or     r14,rdx
 c6a:	49 31 f5             	xor    r13,rsi
 c6d:	4d 29 f5             	sub    r13,r14
 c70:	4c 89 ee             	mov    rsi,r13
 c73:	ba 00 ff ff ff       	mov    edx,0xffffff00
 c78:	48 21 d6             	and    rsi,rdx
 c7b:	48 c1 ee 08          	shr    rsi,0x8
 c7f:	4c 89 ea             	mov    rdx,r13
 c82:	48 c1 e2 18          	shl    rdx,0x18
 c86:	48 09 f2             	or     rdx,rsi
 c89:	4d 31 c5             	xor    r13,r8
 c8c:	49 29 d5             	sub    r13,rdx
 c8f:	49 c1 e5 20          	shl    r13,0x20
 c93:	49 c1 ed 20          	shr    r13,0x20
 c97:	50                   	push   rax
 c98:	52                   	push   rdx
 c99:	49 c7 c3 01 00 01 00 	mov    r11,0x10001
 ca0:	4c 89 e8             	mov    rax,r13
 ca3:	31 d2                	xor    edx,edx
 ca5:	49 f7 f3             	div    r11
 ca8:	49 89 d5             	mov    r13,rdx
 cab:	5a                   	pop    rdx
 cac:	58                   	pop    rax
 cad:	4c 01 eb             	add    rbx,r13
 cb0:	49 b8 15 7c 4a 7f b9 	movabs r8,0x9e3779b97f4a7c15
 cb7:	79 37 9e 
 cba:	4c 01 c3             	add    rbx,r8
 cbd:	48 8b 75 d0          	mov    rsi,QWORD PTR [rbp-0x30]
 cc1:	48 31 f3             	xor    rbx,rsi
 cc4:	48 89 de             	mov    rsi,rbx
 cc7:	48 c1 ee 02          	shr    rsi,0x2
 ccb:	48 89 da             	mov    rdx,rbx
 cce:	48 c1 e2 06          	shl    rdx,0x6
 cd2:	48 01 f2             	add    rdx,rsi
 cd5:	48 be 16 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c16
 cdc:	79 37 9e 
 cdf:	48 01 f2             	add    rdx,rsi
 ce2:	48 31 da             	xor    rdx,rbx
 ce5:	48 89 d6             	mov    rsi,rdx
 ce8:	48 c1 ee 02          	shr    rsi,0x2
 cec:	48 89 d1             	mov    rcx,rdx
 cef:	48 c1 e1 06          	shl    rcx,0x6
 cf3:	48 01 f1             	add    rcx,rsi
 cf6:	4c 01 c1             	add    rcx,r8
 cf9:	48 31 d1             	xor    rcx,rdx
 cfc:	48 89 ce             	mov    rsi,rcx
 cff:	48 c1 e6 06          	shl    rsi,0x6
 d03:	48 01 f0             	add    rax,rsi
 d06:	48 89 ce             	mov    rsi,rcx
 d09:	48 c1 ee 02          	shr    rsi,0x2
 d0d:	48 01 f0             	add    rax,rsi
 d10:	4c 01 c0             	add    rax,r8
 d13:	48 31 c8             	xor    rax,rcx
 d16:	48 89 c6             	mov    rsi,rax
 d19:	48 c1 ee 02          	shr    rsi,0x2
 d1d:	48 89 c2             	mov    rdx,rax
 d20:	48 c1 e2 06          	shl    rdx,0x6
 d24:	48 01 f2             	add    rdx,rsi
 d27:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 d2b:	48 01 f2             	add    rdx,rsi
 d2e:	4c 01 c2             	add    rdx,r8
 d31:	48 31 c2             	xor    rdx,rax
 d34:	48 89 d6             	mov    rsi,rdx
 d37:	48 c1 ee 02          	shr    rsi,0x2
 d3b:	49 89 d0             	mov    r8,rdx
 d3e:	49 c1 e0 06          	shl    r8,0x6
 d42:	49 01 f0             	add    r8,rsi
 d45:	48 be 18 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c18
 d4c:	79 37 9e 
 d4f:	49 01 f0             	add    r8,rsi
 d52:	49 31 d0             	xor    r8,rdx
 d55:	41 be 03 00 00 00    	mov    r14d,0x3
 d5b:	e9 d5 f7 ff ff       	jmp    0x535
 d60:	41 b8 01 00 00 00    	mov    r8d,0x1
 d66:	48 89 fa             	mov    rdx,rdi
 d69:	48 83 c2 32          	add    rdx,0x32
 d6d:	41 be 01 00 00 00    	mov    r14d,0x1
 d73:	48 39 f2             	cmp    rdx,rsi
 d76:	0f 87 b9 f7 ff ff    	ja     0x535
 d7c:	41 b8 02 00 00 00    	mov    r8d,0x2
 d82:	e9 a8 f7 ff ff       	jmp    0x52f
```

## llvmbpf JIT ASM
```asm
Disassembly of section .data:

0000000000000000 <.data>:
   0:	f3 0f 1e fa          	endbr64
   4:	8b 07                	mov    eax,DWORD PTR [rdi]
   6:	8b 7f 04             	mov    edi,DWORD PTR [rdi+0x4]
   9:	39 f8                	cmp    eax,edi
   b:	77 15                	ja     0x22
   d:	48 8d 48 08          	lea    rcx,[rax+0x8]
  11:	48 89 fe             	mov    rsi,rdi
  14:	48 29 ce             	sub    rsi,rcx
  17:	72 09                	jb     0x22
  19:	48 8d 50 16          	lea    rdx,[rax+0x16]
  1d:	48 39 fa             	cmp    rdx,rdi
  20:	76 03                	jbe    0x25
  22:	31 c0                	xor    eax,eax
  24:	c3                   	ret
  25:	55                   	push   rbp
  26:	41 57                	push   r15
  28:	41 56                	push   r14
  2a:	41 55                	push   r13
  2c:	41 54                	push   r12
  2e:	53                   	push   rbx
  2f:	48 b9 15 7c 4a 7f b9 	movabs rcx,0x9e3779b97f4a7c15
  36:	79 37 9e 
  39:	44 0f b7 40 14       	movzx  r8d,WORD PTR [rax+0x14]
  3e:	41 81 f8 86 dd 00 00 	cmp    r8d,0xdd86
  45:	0f 84 12 02 00 00    	je     0x25d
  4b:	41 83 f8 08          	cmp    r8d,0x8
  4f:	0f 85 34 02 00 00    	jne    0x289
  55:	4c 8d 40 2a          	lea    r8,[rax+0x2a]
  59:	49 39 f8             	cmp    r8,rdi
  5c:	0f 87 1a 02 00 00    	ja     0x27c
  62:	0f b6 12             	movzx  edx,BYTE PTR [rdx]
  65:	80 e2 0f             	and    dl,0xf
  68:	80 fa 05             	cmp    dl,0x5
  6b:	0f 85 0b 02 00 00    	jne    0x27c
  71:	0f b6 50 1c          	movzx  edx,BYTE PTR [rax+0x1c]
  75:	80 e2 3f             	and    dl,0x3f
  78:	0a 50 1d             	or     dl,BYTE PTR [rax+0x1d]
  7b:	0f 85 fb 01 00 00    	jne    0x27c
  81:	44 0f b6 40 1f       	movzx  r8d,BYTE PTR [rax+0x1f]
  86:	41 83 f8 11          	cmp    r8d,0x11
  8a:	0f 84 72 02 00 00    	je     0x302
  90:	ba 02 00 00 00       	mov    edx,0x2
  95:	41 83 f8 06          	cmp    r8d,0x6
  99:	0f 85 08 02 00 00    	jne    0x2a7
  9f:	4c 8d 48 3e          	lea    r9,[rax+0x3e]
  a3:	41 b8 01 00 00 00    	mov    r8d,0x1
  a9:	49 39 f9             	cmp    r9,rdi
  ac:	0f 87 43 02 00 00    	ja     0x2f5
  b2:	81 78 26 0a 64 01 01 	cmp    DWORD PTR [rax+0x26],0x101640a
  b9:	0f 85 e8 01 00 00    	jne    0x2a7
  bf:	0f b7 78 2c          	movzx  edi,WORD PTR [rax+0x2c]
  c3:	41 b8 02 00 00 00    	mov    r8d,0x2
  c9:	81 ff 1f 90 00 00    	cmp    edi,0x901f
  cf:	0f 85 d8 01 00 00    	jne    0x2ad
  d5:	ba 01 00 00 00       	mov    edx,0x1
  da:	41 b8 01 00 00 00    	mov    r8d,0x1
  e0:	48 81 fe ea 05 00 00 	cmp    rsi,0x5ea
  e7:	0f 8f c0 01 00 00    	jg     0x2ad
  ed:	66 44 0f 38 f0 58 18 	movbe  r11w,WORD PTR [rax+0x18]
  f4:	45 0f b7 eb          	movzx  r13d,r11w
  f8:	0f b6 58 17          	movzx  ebx,BYTE PTR [rax+0x17]
  fc:	0f b6 70 24          	movzx  esi,BYTE PTR [rax+0x24]
 100:	c1 e6 10             	shl    esi,0x10
 103:	44 0f b6 48 25       	movzx  r9d,BYTE PTR [rax+0x25]
 108:	41 c1 e1 18          	shl    r9d,0x18
 10c:	0f b6 78 2b          	movzx  edi,BYTE PTR [rax+0x2b]
 110:	41 89 fa             	mov    r10d,edi
 113:	41 c1 e2 08          	shl    r10d,0x8
 117:	44 0f b6 70 2a       	movzx  r14d,BYTE PTR [rax+0x2a]
 11c:	47 8d 04 32          	lea    r8d,[r10+r14*1]
 120:	4d 8d 3c 31          	lea    r15,[r9+rsi*1]
 124:	45 01 f2             	add    r10d,r14d
 127:	41 81 c2 f7 c0 cc 70 	add    r10d,0x70ccc0f7
 12e:	44 89 f2             	mov    edx,r14d
 131:	c1 e2 18             	shl    edx,0x18
 134:	c1 e7 10             	shl    edi,0x10
 137:	09 d7                	or     edi,edx
 139:	4c 31 ff             	xor    rdi,r15
 13c:	41 8d 53 14          	lea    edx,[r11+0x14]
 140:	66 c1 c2 08          	rol    dx,0x8
 144:	0f b7 d2             	movzx  edx,dx
 147:	48 01 da             	add    rdx,rbx
 14a:	41 89 fb             	mov    r11d,edi
 14d:	41 c1 eb 10          	shr    r11d,0x10
 151:	4e 8d 34 1a          	lea    r14,[rdx+r11*1]
 155:	4c 01 da             	add    rdx,r11
 158:	48 81 c2 3b df 00 00 	add    rdx,0xdf3b
 15f:	41 89 d3             	mov    r11d,edx
 162:	41 c1 eb 10          	shr    r11d,0x10
 166:	0f b7 da             	movzx  ebx,dx
 169:	4c 01 db             	add    rbx,r11
 16c:	49 81 fe c5 20 00 00 	cmp    r14,0x20c5
 173:	48 0f 42 da          	cmovb  rbx,rdx
 177:	44 8d 5b 01          	lea    r11d,[rbx+0x1]
 17b:	44 0f b7 70 22       	movzx  r14d,WORD PTR [rax+0x22]
 180:	49 09 f6             	or     r14,rsi
 183:	4d 09 ce             	or     r14,r9
 186:	49 8d 34 0e          	lea    rsi,[r14+rcx*1]
 18a:	48 89 f2             	mov    rdx,rsi
 18d:	48 c1 e2 06          	shl    rdx,0x6
 191:	49 89 f1             	mov    r9,rsi
 194:	49 c1 e9 02          	shr    r9,0x2
 198:	48 01 ca             	add    rdx,rcx
 19b:	4c 01 ca             	add    rdx,r9
 19e:	48 81 c2 0a 64 01 01 	add    rdx,0x101640a
 1a5:	48 31 f2             	xor    rdx,rsi
 1a8:	44 89 d6             	mov    esi,r10d
 1ab:	81 f6 f7 c0 ad e0    	xor    esi,0xe0adc0f7
 1b1:	45 89 d1             	mov    r9d,r10d
 1b4:	41 c1 e1 0e          	shl    r9d,0xe
 1b8:	44 29 ce             	sub    esi,r9d
 1bb:	81 c6 cd e3 ff ff    	add    esi,0xffffe3cd
 1c1:	49 89 d1             	mov    r9,rdx
 1c4:	49 c1 e9 02          	shr    r9,0x2
 1c8:	4d 01 c1             	add    r9,r8
 1cb:	49 89 d7             	mov    r15,rdx
 1ce:	49 c1 e7 06          	shl    r15,0x6
 1d2:	41 81 c6 f7 c0 ad e0 	add    r14d,0xe0adc0f7
 1d9:	41 31 f6             	xor    r14d,esi
 1dc:	c4 63 7b f0 c6 15    	rorx   r8d,esi,0x15
 1e2:	45 29 c6             	sub    r14d,r8d
 1e5:	48 c1 e7 20          	shl    rdi,0x20
 1e9:	49 b8 0a c8 00 02 ac 	movabs r8,0x10ac0200c80a
 1f0:	10 00 00 
 1f3:	49 09 f8             	or     r8,rdi
 1f6:	45 31 f2             	xor    r10d,r14d
 1f9:	c4 c3 7b f0 fe 07    	rorx   edi,r14d,0x7
 1ff:	41 29 fa             	sub    r10d,edi
 202:	44 31 d6             	xor    esi,r10d
 205:	c4 c3 7b f0 fa 10    	rorx   edi,r10d,0x10
 20b:	29 fe                	sub    esi,edi
 20d:	48 bf 15 7c 69 0f ba 	movabs rdi,0x9e3779ba0f697c15
 214:	79 37 9e 
 217:	4c 01 ff             	add    rdi,r15
 21a:	4c 01 cf             	add    rdi,r9
 21d:	48 31 d7             	xor    rdi,rdx
 220:	41 31 f6             	xor    r14d,esi
 223:	c4 e3 7b f0 d6 1c    	rorx   edx,esi,0x1c
 229:	41 29 d6             	sub    r14d,edx
 22c:	45 31 f2             	xor    r10d,r14d
 22f:	c4 c3 7b f0 d6 12    	rorx   edx,r14d,0x12
 235:	41 29 d2             	sub    r10d,edx
 238:	44 31 d6             	xor    esi,r10d
 23b:	c4 c3 7b f0 d2 08    	rorx   edx,r10d,0x8
 241:	29 d6                	sub    esi,edx
 243:	48 81 fb 00 00 01 00 	cmp    rbx,0x10000
 24a:	44 0f 42 db          	cmovb  r11d,ebx
 24e:	41 c1 e3 10          	shl    r11d,0x10
 252:	4d 31 e8             	xor    r8,r13
 255:	4d 31 d8             	xor    r8,r11
 258:	e9 f3 03 00 00       	jmp    0x650
 25d:	48 8d 50 3e          	lea    rdx,[rax+0x3e]
 261:	48 39 fa             	cmp    rdx,rdi
 264:	77 16                	ja     0x27c
 266:	44 0f b6 40 1c       	movzx  r8d,BYTE PTR [rax+0x1c]
 26b:	ba 02 00 00 00       	mov    edx,0x2
 270:	41 83 f8 3a          	cmp    r8d,0x3a
 274:	74 31                	je     0x2a7
 276:	41 83 f8 2c          	cmp    r8d,0x2c
 27a:	75 5e                	jne    0x2da
 27c:	ba 01 00 00 00       	mov    edx,0x1
 281:	41 b8 01 00 00 00    	mov    r8d,0x1
 287:	eb 24                	jmp    0x2ad
 289:	48 01 ce             	add    rsi,rcx
 28c:	48 89 f2             	mov    rdx,rsi
 28f:	48 c1 ea 02          	shr    rdx,0x2
 293:	48 89 f7             	mov    rdi,rsi
 296:	48 c1 e7 06          	shl    rdi,0x6
 29a:	48 01 ca             	add    rdx,rcx
 29d:	48 01 fa             	add    rdx,rdi
 2a0:	48 83 c2 02          	add    rdx,0x2
 2a4:	48 31 f2             	xor    rdx,rsi
 2a7:	41 b8 02 00 00 00    	mov    r8d,0x2
 2ad:	48 89 d6             	mov    rsi,rdx
 2b0:	48 c1 ee 02          	shr    rsi,0x2
 2b4:	48 89 d7             	mov    rdi,rdx
 2b7:	48 c1 e7 06          	shl    rdi,0x6
 2bb:	4c 01 c7             	add    rdi,r8
 2be:	48 01 ce             	add    rsi,rcx
 2c1:	48 01 fe             	add    rsi,rdi
 2c4:	48 31 d6             	xor    rsi,rdx
 2c7:	48 89 30             	mov    QWORD PTR [rax],rsi
 2ca:	b8 02 00 00 00       	mov    eax,0x2
 2cf:	5b                   	pop    rbx
 2d0:	41 5c                	pop    r12
 2d2:	41 5d                	pop    r13
 2d4:	41 5e                	pop    r14
 2d6:	41 5f                	pop    r15
 2d8:	5d                   	pop    rbp
 2d9:	c3                   	ret
 2da:	41 83 f8 11          	cmp    r8d,0x11
 2de:	74 1c                	je     0x2fc
 2e0:	41 83 f8 06          	cmp    r8d,0x6
 2e4:	75 c1                	jne    0x2a7
 2e6:	4c 8d 48 52          	lea    r9,[rax+0x52]
 2ea:	41 b8 01 00 00 00    	mov    r8d,0x1
 2f0:	49 39 f9             	cmp    r9,rdi
 2f3:	76 22                	jbe    0x317
 2f5:	ba 01 00 00 00       	mov    edx,0x1
 2fa:	eb b1                	jmp    0x2ad
 2fc:	48 8d 50 46          	lea    rdx,[rax+0x46]
 300:	eb 04                	jmp    0x306
 302:	48 8d 50 32          	lea    rdx,[rax+0x32]
 306:	48 39 d7             	cmp    rdi,rdx
 309:	ba 02 00 00 00       	mov    edx,0x2
 30e:	48 83 da 00          	sbb    rdx,0x0
 312:	49 89 d0             	mov    r8,rdx
 315:	eb 96                	jmp    0x2ad
 317:	0f b6 78 2e          	movzx  edi,BYTE PTR [rax+0x2e]
 31b:	44 0f b6 40 2f       	movzx  r8d,BYTE PTR [rax+0x2f]
 320:	44 0f b6 48 30       	movzx  r9d,BYTE PTR [rax+0x30]
 325:	44 0f b6 50 31       	movzx  r10d,BYTE PTR [rax+0x31]
 32a:	41 c1 e0 08          	shl    r8d,0x8
 32e:	41 c1 e1 10          	shl    r9d,0x10
 332:	41 c1 e2 18          	shl    r10d,0x18
 336:	44 09 c7             	or     edi,r8d
 339:	44 09 cf             	or     edi,r9d
 33c:	44 09 d7             	or     edi,r10d
 33f:	81 ff 0a 64 01 01    	cmp    edi,0x101640a
 345:	0f 85 5c ff ff ff    	jne    0x2a7
 34b:	0f b7 78 40          	movzx  edi,WORD PTR [rax+0x40]
 34f:	41 b8 02 00 00 00    	mov    r8d,0x2
 355:	81 ff 1f 90 00 00    	cmp    edi,0x901f
 35b:	0f 85 4c ff ff ff    	jne    0x2ad
 361:	ba 01 00 00 00       	mov    edx,0x1
 366:	41 b8 01 00 00 00    	mov    r8d,0x1
 36c:	48 81 fe ea 05 00 00 	cmp    rsi,0x5ea
 373:	0f 8f 34 ff ff ff    	jg     0x2ad
 379:	44 0f b6 68 1a       	movzx  r13d,BYTE PTR [rax+0x1a]
 37e:	44 0f b6 78 1b       	movzx  r15d,BYTE PTR [rax+0x1b]
 383:	44 0f b6 50 16       	movzx  r10d,BYTE PTR [rax+0x16]
 388:	0f b6 58 17          	movzx  ebx,BYTE PTR [rax+0x17]
 38c:	0f b6 50 23          	movzx  edx,BYTE PTR [rax+0x23]
 390:	44 0f b6 60 22       	movzx  r12d,BYTE PTR [rax+0x22]
 395:	0f b6 70 27          	movzx  esi,BYTE PTR [rax+0x27]
 399:	44 0f b6 48 26       	movzx  r9d,BYTE PTR [rax+0x26]
 39e:	0f b6 78 28          	movzx  edi,BYTE PTR [rax+0x28]
 3a2:	44 0f b6 40 24       	movzx  r8d,BYTE PTR [rax+0x24]
 3a7:	44 0f b6 58 20       	movzx  r11d,BYTE PTR [rax+0x20]
 3ac:	44 0f b6 70 21       	movzx  r14d,BYTE PTR [rax+0x21]
 3b1:	41 c1 e5 08          	shl    r13d,0x8
 3b5:	4d 09 fd             	or     r13,r15
 3b8:	4c 89 6c 24 e8       	mov    QWORD PTR [rsp-0x18],r13
 3bd:	41 c1 e2 04          	shl    r10d,0x4
 3c1:	c1 eb 04             	shr    ebx,0x4
 3c4:	c1 e2 08             	shl    edx,0x8
 3c7:	41 09 d4             	or     r12d,edx
 3ca:	c1 e6 08             	shl    esi,0x8
 3cd:	41 09 f1             	or     r9d,esi
 3d0:	41 c1 e3 10          	shl    r11d,0x10
 3d4:	41 c1 e6 18          	shl    r14d,0x18
 3d8:	44 0f b6 78 3f       	movzx  r15d,BYTE PTR [rax+0x3f]
 3dd:	45 89 fd             	mov    r13d,r15d
 3e0:	41 c1 e5 08          	shl    r13d,0x8
 3e4:	0f b6 70 3e          	movzx  esi,BYTE PTR [rax+0x3e]
 3e8:	42 8d 14 2e          	lea    edx,[rsi+r13*1]
 3ec:	48 89 54 24 f8       	mov    QWORD PTR [rsp-0x8],rdx
 3f1:	4b 8d 14 1e          	lea    rdx,[r14+r11*1]
 3f5:	48 89 54 24 f0       	mov    QWORD PTR [rsp-0x10],rdx
 3fa:	42 8d 2c 2e          	lea    ebp,[rsi+r13*1]
 3fe:	81 c5 f7 c0 cc 70    	add    ebp,0x70ccc0f7
 404:	89 f2                	mov    edx,esi
 406:	c1 e2 18             	shl    edx,0x18
 409:	41 c1 e7 10          	shl    r15d,0x10
 40d:	41 09 d7             	or     r15d,edx
 410:	4c 33 7c 24 f0       	xor    r15,QWORD PTR [rsp-0x10]
 415:	41 0f b6 d2          	movzx  edx,r10b
 419:	09 da                	or     edx,ebx
 41b:	48 8b 74 24 e8       	mov    rsi,QWORD PTR [rsp-0x18]
 420:	83 c6 14             	add    esi,0x14
 423:	66 c1 c6 08          	rol    si,0x8
 427:	0f b7 f6             	movzx  esi,si
 42a:	48 01 d6             	add    rsi,rdx
 42d:	44 89 fa             	mov    edx,r15d
 430:	c1 ea 10             	shr    edx,0x10
 433:	48 8d 1c 16          	lea    rbx,[rsi+rdx*1]
 437:	48 01 f2             	add    rdx,rsi
 43a:	48 81 c2 3b df 00 00 	add    rdx,0xdf3b
 441:	89 d6                	mov    esi,edx
 443:	c1 ee 10             	shr    esi,0x10
 446:	44 0f b7 d2          	movzx  r10d,dx
 44a:	49 01 f2             	add    r10,rsi
 44d:	0f b6 70 1f          	movzx  esi,BYTE PTR [rax+0x1f]
 451:	c1 e7 10             	shl    edi,0x10
 454:	41 c1 e0 10          	shl    r8d,0x10
 458:	c1 e6 08             	shl    esi,0x8
 45b:	48 81 fb c5 20 00 00 	cmp    rbx,0x20c5
 462:	4c 0f 42 d2          	cmovb  r10,rdx
 466:	0f b6 50 1e          	movzx  edx,BYTE PTR [rax+0x1e]
 46a:	44 09 cf             	or     edi,r9d
 46d:	44 0f b6 48 25       	movzx  r9d,BYTE PTR [rax+0x25]
 472:	45 09 e0             	or     r8d,r12d
 475:	0f b6 58 29          	movzx  ebx,BYTE PTR [rax+0x29]
 479:	41 c1 e1 18          	shl    r9d,0x18
 47d:	c1 e3 18             	shl    ebx,0x18
 480:	47 8d 2c 01          	lea    r13d,[r9+r8*1]
 484:	41 81 c5 ff c0 ad de 	add    r13d,0xdeadc0ff
 48b:	44 8d 04 1f          	lea    r8d,[rdi+rbx*1]
 48f:	44 8d 24 3b          	lea    r12d,[rbx+rdi*1]
 493:	41 81 c4 ff c0 ad de 	add    r12d,0xdeadc0ff
 49a:	44 0f b6 48 2b       	movzx  r9d,BYTE PTR [rax+0x2b]
 49f:	48 09 d6             	or     rsi,rdx
 4a2:	4c 09 de             	or     rsi,r11
 4a5:	4c 09 f6             	or     rsi,r14
 4a8:	48 8d 14 0e          	lea    rdx,[rsi+rcx*1]
 4ac:	48 89 d7             	mov    rdi,rdx
 4af:	48 c1 ef 02          	shr    rdi,0x2
 4b3:	49 89 d3             	mov    r11,rdx
 4b6:	49 c1 e3 06          	shl    r11,0x6
 4ba:	48 01 cf             	add    rdi,rcx
 4bd:	49 01 fb             	add    r11,rdi
 4c0:	49 81 c3 0a 64 01 01 	add    r11,0x101640a
 4c7:	44 0f b6 70 2c       	movzx  r14d,BYTE PTR [rax+0x2c]
 4cc:	44 29 c6             	sub    esi,r8d
 4cf:	c4 c3 7b f0 dc 1c    	rorx   ebx,r12d,0x1c
 4d5:	31 f3                	xor    ebx,esi
 4d7:	49 31 d3             	xor    r11,rdx
 4da:	4c 89 da             	mov    rdx,r11
 4dd:	48 c1 e2 06          	shl    rdx,0x6
 4e1:	4c 89 de             	mov    rsi,r11
 4e4:	48 c1 ee 02          	shr    rsi,0x2
 4e8:	48 01 d6             	add    rsi,rdx
 4eb:	c4 e3 7b f0 d3 1a    	rorx   edx,ebx,0x1a
 4f1:	45 01 ec             	add    r12d,r13d
 4f4:	41 29 dd             	sub    r13d,ebx
 4f7:	41 31 d5             	xor    r13d,edx
 4fa:	48 bf 15 7c 69 0f ba 	movabs rdi,0x9e3779ba0f697c15
 501:	79 37 9e 
 504:	48 03 7c 24 f8       	add    rdi,QWORD PTR [rsp-0x8]
 509:	48 01 f7             	add    rdi,rsi
 50c:	89 ee                	mov    esi,ebp
 50e:	81 f6 f7 c0 ad e0    	xor    esi,0xe0adc0f7
 514:	89 ea                	mov    edx,ebp
 516:	c1 e2 0e             	shl    edx,0xe
 519:	29 d6                	sub    esi,edx
 51b:	49 c1 e7 20          	shl    r15,0x20
 51f:	49 b8 0a c8 00 02 ac 	movabs r8,0x10ac0200c80a
 526:	10 00 00 
 529:	4d 09 f8             	or     r8,r15
 52c:	c4 c3 7b f0 d5 18    	rorx   edx,r13d,0x18
 532:	44 01 e3             	add    ebx,r12d
 535:	45 29 ec             	sub    r12d,r13d
 538:	41 31 d4             	xor    r12d,edx
 53b:	0f b6 50 2d          	movzx  edx,BYTE PTR [rax+0x2d]
 53f:	4c 31 df             	xor    rdi,r11
 542:	c4 43 7b f0 dc 10    	rorx   r11d,r12d,0x10
 548:	41 01 dd             	add    r13d,ebx
 54b:	44 29 e3             	sub    ebx,r12d
 54e:	44 31 db             	xor    ebx,r11d
 551:	c4 63 7b f0 db 0d    	rorx   r11d,ebx,0xd
 557:	45 01 ec             	add    r12d,r13d
 55a:	41 29 dd             	sub    r13d,ebx
 55d:	45 31 dd             	xor    r13d,r11d
 560:	44 01 e3             	add    ebx,r12d
 563:	46 8d 3c 2b          	lea    r15d,[rbx+r13*1]
 567:	45 29 ec             	sub    r12d,r13d
 56a:	c4 43 7b f0 dd 1c    	rorx   r11d,r13d,0x1c
 570:	4c 8b 6c 24 e8       	mov    r13,QWORD PTR [rsp-0x18]
 575:	45 31 e3             	xor    r11d,r12d
 578:	45 31 fb             	xor    r11d,r15d
 57b:	c4 43 7b f0 e7 12    	rorx   r12d,r15d,0x12
 581:	45 29 e3             	sub    r11d,r12d
 584:	45 8d 62 01          	lea    r12d,[r10+0x1]
 588:	41 c1 e1 08          	shl    r9d,0x8
 58c:	41 c1 e6 10          	shl    r14d,0x10
 590:	c1 e2 18             	shl    edx,0x18
 593:	81 c6 cd e3 ff ff    	add    esi,0xffffe3cd
 599:	49 81 fa 00 00 01 00 	cmp    r10,0x10000
 5a0:	45 0f 42 e2          	cmovb  r12d,r10d
 5a4:	44 0f b6 50 2a       	movzx  r10d,BYTE PTR [rax+0x2a]
 5a9:	45 09 ca             	or     r10d,r9d
 5ac:	45 09 f2             	or     r10d,r14d
 5af:	41 09 d2             	or     r10d,edx
 5b2:	41 01 da             	add    r10d,ebx
 5b5:	45 31 da             	xor    r10d,r11d
 5b8:	c4 c3 7b f0 d3 15    	rorx   edx,r11d,0x15
 5be:	41 29 d2             	sub    r10d,edx
 5c1:	41 c1 e4 10          	shl    r12d,0x10
 5c5:	4d 31 e8             	xor    r8,r13
 5c8:	4d 31 e0             	xor    r8,r12
 5cb:	45 31 d7             	xor    r15d,r10d
 5ce:	c4 c3 7b f0 d2 07    	rorx   edx,r10d,0x7
 5d4:	41 29 d7             	sub    r15d,edx
 5d7:	45 31 fb             	xor    r11d,r15d
 5da:	c4 c3 7b f0 d7 10    	rorx   edx,r15d,0x10
 5e0:	41 29 d3             	sub    r11d,edx
 5e3:	45 31 da             	xor    r10d,r11d
 5e6:	c4 c3 7b f0 d3 1c    	rorx   edx,r11d,0x1c
 5ec:	41 29 d2             	sub    r10d,edx
 5ef:	45 31 d7             	xor    r15d,r10d
 5f2:	c4 c3 7b f0 d2 12    	rorx   edx,r10d,0x12
 5f8:	41 29 d7             	sub    r15d,edx
 5fb:	45 31 fb             	xor    r11d,r15d
 5fe:	c4 c3 7b f0 d7 08    	rorx   edx,r15d,0x8
 604:	41 29 d3             	sub    r11d,edx
 607:	41 81 c3 f7 c0 ad e0 	add    r11d,0xe0adc0f7
 60e:	41 31 f3             	xor    r11d,esi
 611:	c4 e3 7b f0 d6 15    	rorx   edx,esi,0x15
 617:	41 29 d3             	sub    r11d,edx
 61a:	44 31 dd             	xor    ebp,r11d
 61d:	c4 c3 7b f0 d3 07    	rorx   edx,r11d,0x7
 623:	29 d5                	sub    ebp,edx
 625:	31 ee                	xor    esi,ebp
 627:	c4 e3 7b f0 d5 10    	rorx   edx,ebp,0x10
 62d:	29 d6                	sub    esi,edx
 62f:	41 31 f3             	xor    r11d,esi
 632:	c4 e3 7b f0 d6 1c    	rorx   edx,esi,0x1c
 638:	41 29 d3             	sub    r11d,edx
 63b:	44 31 dd             	xor    ebp,r11d
 63e:	c4 c3 7b f0 d3 12    	rorx   edx,r11d,0x12
 644:	29 d5                	sub    ebp,edx
 646:	31 ee                	xor    esi,ebp
 648:	c4 e3 7b f0 d5 08    	rorx   edx,ebp,0x8
 64e:	29 d6                	sub    esi,edx
 650:	49 b9 0b 00 ff ff 00 	movabs r9,0x200ffff000b
 657:	02 00 00 
 65a:	4d 31 c1             	xor    r9,r8
 65d:	49 89 f8             	mov    r8,rdi
 660:	49 c1 e0 06          	shl    r8,0x6
 664:	48 89 fa             	mov    rdx,rdi
 667:	48 c1 ea 02          	shr    rdx,0x2
 66b:	41 89 f2             	mov    r10d,esi
 66e:	41 bb 01 00 ff ff    	mov    r11d,0xffff0001
 674:	4d 0f af da          	imul   r11,r10
 678:	49 c1 eb 30          	shr    r11,0x30
 67c:	45 89 da             	mov    r10d,r11d
 67f:	41 c1 e2 10          	shl    r10d,0x10
 683:	45 09 da             	or     r10d,r11d
 686:	44 29 d6             	sub    esi,r10d
 689:	48 01 ca             	add    rdx,rcx
 68c:	4c 01 c2             	add    rdx,r8
 68f:	48 01 f2             	add    rdx,rsi
 692:	48 31 fa             	xor    rdx,rdi
 695:	48 89 d6             	mov    rsi,rdx
 698:	48 c1 ee 02          	shr    rsi,0x2
 69c:	48 89 d7             	mov    rdi,rdx
 69f:	48 c1 e7 06          	shl    rdi,0x6
 6a3:	48 01 ce             	add    rsi,rcx
 6a6:	48 01 fe             	add    rsi,rdi
 6a9:	48 ff c6             	inc    rsi
 6ac:	48 31 d6             	xor    rsi,rdx
 6af:	48 89 f2             	mov    rdx,rsi
 6b2:	48 c1 ea 02          	shr    rdx,0x2
 6b6:	48 89 f7             	mov    rdi,rsi
 6b9:	48 c1 e7 06          	shl    rdi,0x6
 6bd:	48 01 ca             	add    rdx,rcx
 6c0:	48 01 fa             	add    rdx,rdi
 6c3:	48 31 f2             	xor    rdx,rsi
 6c6:	48 89 d6             	mov    rsi,rdx
 6c9:	48 c1 e6 06          	shl    rsi,0x6
 6cd:	48 89 d7             	mov    rdi,rdx
 6d0:	48 c1 ef 02          	shr    rdi,0x2
 6d4:	49 01 cd             	add    r13,rcx
 6d7:	49 01 f5             	add    r13,rsi
 6da:	49 01 fd             	add    r13,rdi
 6dd:	49 31 d5             	xor    r13,rdx
 6e0:	4c 89 ea             	mov    rdx,r13
 6e3:	48 c1 ea 02          	shr    rdx,0x2
 6e7:	4c 89 ee             	mov    rsi,r13
 6ea:	48 c1 e6 06          	shl    rsi,0x6
 6ee:	49 01 c9             	add    r9,rcx
 6f1:	49 01 d1             	add    r9,rdx
 6f4:	49 01 f1             	add    r9,rsi
 6f7:	4d 31 e9             	xor    r9,r13
 6fa:	4c 89 ca             	mov    rdx,r9
 6fd:	48 c1 ea 02          	shr    rdx,0x2
 701:	4c 89 ce             	mov    rsi,r9
 704:	48 c1 e6 06          	shl    rsi,0x6
 708:	48 01 ca             	add    rdx,rcx
 70b:	48 01 f2             	add    rdx,rsi
 70e:	48 83 c2 03          	add    rdx,0x3
 712:	4c 31 ca             	xor    rdx,r9
 715:	41 b8 03 00 00 00    	mov    r8d,0x3
 71b:	e9 8d fb ff ff       	jmp    0x2ad
```

## Handcraft C
```c
#include "handcraft_common.h"

#define HC_LEA_PAYLOAD(DST, BASE, INDEX, SCALE, HAS_BASE, HAS_INDEX, DISP) \
    ((__u64)(DST) | ((__u64)(BASE) << 4) | ((__u64)(INDEX) << 8) | \
     ((__u64)(SCALE) << 12) | ((__u64)(HAS_INDEX) << 14) | \
     ((__u64)(HAS_BASE) << 15) | ((__u64)(__u32)(DISP) << 16))

/*
 * Semantic handcraft for katran_lb_consistent_hash_select.
 *
 * Direct native conversion leaves many host-only registers and stack ABI
 * operations unmapped, causing verifier unreachable-code failure. This input
 * starts from verified kernel xlated BPF, restores verifier-facing XDP ctx
 * loads, and replaces same-PC-count mov+add address calculations with x86
 * leaq kinsns. Branch offsets remain valid.
 */

static const struct bpf_insn program[] = {
    HC_RAW(0xb7, BPF_REG_0, BPF_REG_0, 0, 0),
    /* pc 1: restore verifier-facing XDP data_end load */
    HC_LDX(BPF_W, BPF_REG_2, BPF_REG_1, 4),
    /* pc 2: restore verifier-facing XDP data load */
    HC_LDX(BPF_W, BPF_REG_1, BPF_REG_1, 0),
    HC_RAW(0x2d, BPF_REG_1, BPF_REG_2, 334, 0),
    /* pc 4: r5 = r1; r5 += 8; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_1, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_5, BPF_REG_2, 331, 0),
    /* pc 7: r3 = r1; r3 += 22; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_1, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_3, BPF_REG_2, 328, 0),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_2, 0, 0),
    HC_RAW(0x1f, BPF_REG_4, BPF_REG_5, 0, 0),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_1, 20, 0),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_1, 21, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_5, BPF_REG_0, 0, 0),
    HC_RAW(0x57, BPF_REG_5, BPF_REG_0, 0, 65535),
    HC_RAW(0x15, BPF_REG_5, BPF_REG_0, 264, 56710),
    HC_RAW(0x55, BPF_REG_5, BPF_REG_0, 274, 8),
    /* pc 19: r5 = r1; r5 += 42; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_5, BPF_REG_1, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_5, BPF_REG_2, 268, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_3, 0, 0),
    HC_RAW(0x57, BPF_REG_3, BPF_REG_0, 0, 15),
    HC_RAW(0x55, BPF_REG_3, BPF_REG_0, 265, 5),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 28, 0),
    HC_RAW(0x57, BPF_REG_3, BPF_REG_0, 0, 63),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_1, 29, 0),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0x57, BPF_REG_3, BPF_REG_0, 0, 255),
    HC_RAW(0x55, BPF_REG_3, BPF_REG_0, 259, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 31, 0),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 2),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 2),
    HC_RAW(0x15, BPF_REG_3, BPF_REG_0, 271, 1),
    HC_RAW(0x15, BPF_REG_3, BPF_REG_0, 811, 17),
    HC_RAW(0x55, BPF_REG_3, BPF_REG_0, 269, 6),
    /* pc 37: r3 = r1; r3 += 62; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_1, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 1),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 1),
    HC_RAW(0x2d, BPF_REG_3, BPF_REG_2, 264, 0),
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 39, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 38, 0),
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 40, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 16),
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 41, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 24),
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 32),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 32),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 2),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 2),
    HC_RAW(0x55, BPF_REG_2, BPF_REG_0, 249, 16868362),
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 45, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 44, 0),
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x57, BPF_REG_2, BPF_REG_0, 0, 65535),
    HC_RAW(0x55, BPF_REG_2, BPF_REG_0, 243, 36895),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 1),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 1),
    HC_RAW(0x65, BPF_REG_4, BPF_REG_0, 240, 1514),
    HC_RAW(0x71, BPF_REG_6, BPF_REG_1, 24, 0),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 25, 0),
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_2, 0, 0),
    HC_RAW(0x71, BPF_REG_4, BPF_REG_1, 23, 0),
    HC_RAW(0x71, BPF_REG_7, BPF_REG_1, 35, 0),
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_1, 34, 0),
    HC_RAW(0x71, BPF_REG_8, BPF_REG_1, 36, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 16),
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 37, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 24),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 42, 0),
    HC_RAW(0x71, BPF_REG_9, BPF_REG_1, 43, 0),
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_8, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_9, -24, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_9, 0, 0),
    HC_RAW(0xdc, BPF_REG_3, BPF_REG_0, 0, 32),
    HC_RAW(0x18, BPF_REG_9, BPF_REG_0, 0, -65536),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_3, BPF_REG_9, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_6, -16, 0),
    /* pc 92: r0 = r6; r0 += 20; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_6, 0, 0, 1, 0, 20), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0xdc, BPF_REG_0, BPF_REG_0, 0, 16),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_0, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -8, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_3, 0, 0),
    HC_RAW(0x5f, BPF_REG_0, BPF_REG_9, 0, 0),
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 16),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_0, 0, 0),
    HC_RAW(0x07, BPF_REG_4, BPF_REG_0, 0, 57147),
    HC_RAW(0xb7, BPF_REG_0, BPF_REG_0, 0, 65536),
    HC_RAW(0x2d, BPF_REG_0, BPF_REG_4, 4, 0),
    HC_RAW(0xbf, BPF_REG_9, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_9, BPF_REG_0, 0, 16),
    HC_RAW(0x57, BPF_REG_4, BPF_REG_0, 0, 65535),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_9, 0, 0),
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0x2d, BPF_REG_0, BPF_REG_4, 4, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 16),
    HC_RAW(0x57, BPF_REG_4, BPF_REG_0, 0, 65535),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_5, 0, 0),
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_8, 0, 0),
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_7, 0, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 32),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 32),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, 2135587861),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 6),
    HC_RAW(0xbf, BPF_REG_9, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_9, BPF_REG_0, 0, 2),
    HC_RAW(0x0f, BPF_REG_9, BPF_REG_5, 0, 0),
    HC_RAW(0x18, BPF_REG_5, BPF_REG_0, 0, -2142511073),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_9, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_9, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_6, BPF_REG_10, -24, 0),
    HC_RAW(0x57, BPF_REG_6, BPF_REG_0, 0, 65535),
    /* pc 133: r3 = r6; r3 += 1892466935; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_6, 0, 0, 1, 0, 1892466935), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -24, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 14),
    HC_RAW(0x47, BPF_REG_5, BPF_REG_0, 0, 7219),
    HC_RAW(0xa7, BPF_REG_3, BPF_REG_0, 0, -525483785),
    HC_RAW(0x1f, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_9, 0, 0),
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_8, BPF_REG_9, 0, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_8, BPF_REG_5, 0, 0),
    HC_RAW(0x18, BPF_REG_5, BPF_REG_0, 0, -2097152),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x5f, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 21),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 11),
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0x07, BPF_REG_7, BPF_REG_0, 0, -525483785),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_7, 0, 0),
    HC_RAW(0x1f, BPF_REG_5, BPF_REG_0, 0, 0),
    HC_RAW(0x0f, BPF_REG_8, BPF_REG_6, 0, 0),
    HC_RAW(0x79, BPF_REG_0, BPF_REG_10, -8, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 32),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, 33605642),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 4268),
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_0, -8, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, -128),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_5, 0, 0),
    HC_RAW(0x5f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 7),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 25),
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0x79, BPF_REG_0, BPF_REG_10, -24, 0),
    HC_RAW(0xaf, BPF_REG_7, BPF_REG_0, 0, 0),
    HC_RAW(0x1f, BPF_REG_7, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_7, 0, 0),
    HC_RAW(0x18, BPF_REG_0, BPF_REG_0, 0, -65536),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_2, BPF_REG_0, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 16),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_7, 0, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 16),
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_6, BPF_REG_7, 0, 0),
    HC_RAW(0xaf, BPF_REG_6, BPF_REG_3, 0, 0),
    HC_RAW(0x1f, BPF_REG_6, BPF_REG_0, 0, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, 258571285),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531526),
    HC_RAW(0x0f, BPF_REG_8, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_8, BPF_REG_9, 0, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, -268435456),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_6, 0, 0),
    HC_RAW(0x5f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 28),
    HC_RAW(0xbf, BPF_REG_9, BPF_REG_6, 0, 0),
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 4),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_8, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_8, 0, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_6, 0, 0),
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0x1f, BPF_REG_2, BPF_REG_9, 0, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, -262144),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x5f, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 18),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 14),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_7, 0, 0),
    HC_RAW(0x1f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, -256),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x5f, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 8),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 24),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_6, 0, 0),
    HC_RAW(0x1f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 16),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 32),
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 32),
    HC_RAW(0x79, BPF_REG_6, BPF_REG_10, -8, 0),
    HC_RAW(0xaf, BPF_REG_6, BPF_REG_4, 0, 0),
    HC_RAW(0x79, BPF_REG_5, BPF_REG_10, -16, 0),
    HC_RAW(0x57, BPF_REG_5, BPF_REG_0, 0, 65535),
    HC_RAW(0xaf, BPF_REG_6, BPF_REG_5, 0, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, -65525),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 512),
    HC_RAW(0xaf, BPF_REG_6, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 32),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 32),
    HC_RAW(0x97, BPF_REG_2, BPF_REG_0, 0, 65537),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, 2135587861),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_8, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_0, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, 2135587862),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_2, 0, 0),
    HC_RAW(0x18, BPF_REG_0, BPF_REG_0, 0, 2135587861),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_0, 0, 0),
    HC_RAW(0xaf, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_4, 0, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_0, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_4, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_6, 0, 0),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, 554, 0),
    /* pc 282: r3 = r1; r3 += 62; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_1, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x2d, BPF_REG_3, BPF_REG_2, 5, 0),
    HC_RAW(0x71, BPF_REG_6, BPF_REG_1, 28, 0),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 2),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 2),
    HC_RAW(0x15, BPF_REG_6, BPF_REG_0, 17, 58),
    HC_RAW(0x55, BPF_REG_6, BPF_REG_0, 49, 44),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 1),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 1),
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, 13, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, 2135587861),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_4, 0, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, 2135587863),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_4, 0, 0),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_8, 0, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, 2135587861),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 56),
    HC_RAW(0x73, BPF_REG_1, BPF_REG_3, 7, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 48),
    HC_RAW(0x73, BPF_REG_1, BPF_REG_3, 6, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 40),
    HC_RAW(0x73, BPF_REG_1, BPF_REG_3, 5, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 32),
    HC_RAW(0x73, BPF_REG_1, BPF_REG_3, 4, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 24),
    HC_RAW(0x73, BPF_REG_1, BPF_REG_3, 3, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 16),
    HC_RAW(0x73, BPF_REG_1, BPF_REG_3, 2, 0),
    HC_RAW(0x73, BPF_REG_1, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 8),
    HC_RAW(0x73, BPF_REG_1, BPF_REG_2, 1, 0),
    HC_RAW(0xb7, BPF_REG_0, BPF_REG_0, 0, 2),
    HC_RAW(0x95, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 26, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -16, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 27, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -168, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 22, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -136, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 23, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -160, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 35, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -88, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 34, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -152, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 39, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -104, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 38, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -144, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 40, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -72, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 36, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -64, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 31, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -96, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 30, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -128, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 37, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -120, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 41, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -112, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 42, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -80, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 46, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -8, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 43, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -32, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 44, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -40, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 45, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -24, 0),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 47, 0),
    HC_RAW(0x71, BPF_REG_0, BPF_REG_1, 48, 0),
    HC_RAW(0x71, BPF_REG_9, BPF_REG_1, 49, 0),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_1, 32, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_5, -56, 0),
    HC_RAW(0x71, BPF_REG_5, BPF_REG_1, 33, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_5, -48, 0),
    HC_RAW(0x15, BPF_REG_6, BPF_REG_0, 8, 17),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 2),
    HC_RAW(0x55, BPF_REG_6, BPF_REG_0, -81, 6),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 1),
    /* pc 388: r7 = r1; r7 += 82; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_1, 0, 0, 1, 0, 82), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 1),
    HC_RAW(0x2d, BPF_REG_7, BPF_REG_2, -86, 0),
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, 5, 0),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 1),
    /* pc 394: r7 = r1; r7 += 70; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_7, BPF_REG_1, 0, 0, 1, 0, 70), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 1),
    HC_RAW(0x2d, BPF_REG_7, BPF_REG_2, -92, 0),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 2),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 2),
    HC_RAW(0x55, BPF_REG_6, BPF_REG_0, -95, 6),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 8),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 16),
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 24),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_0, 0, 0),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -8, 0),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_2, 0, 0),
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 32),
    HC_RAW(0x77, BPF_REG_9, BPF_REG_0, 0, 32),
    HC_RAW(0x55, BPF_REG_9, BPF_REG_0, -105, 16868362),
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 65, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 8),
    HC_RAW(0x71, BPF_REG_3, BPF_REG_1, 64, 0),
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x57, BPF_REG_2, BPF_REG_0, 0, 65535),
    HC_RAW(0x55, BPF_REG_2, BPF_REG_0, -111, 36895),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 1),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 1),
    HC_RAW(0x65, BPF_REG_4, BPF_REG_0, -114, 1514),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -16, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 8),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -168, 0),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_8, BPF_REG_10, -136, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 4),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -160, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 4),
    HC_RAW(0x57, BPF_REG_2, BPF_REG_0, 0, 15),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_9, BPF_REG_10, -88, 0),
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 8),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -152, 0),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_6, BPF_REG_10, -104, 0),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 8),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -144, 0),
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -72, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 16),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_2, -72, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -64, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 16),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_2, -64, 0),
    HC_RAW(0x79, BPF_REG_5, BPF_REG_10, -96, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 8),
    HC_RAW(0x79, BPF_REG_4, BPF_REG_10, -56, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 16),
    HC_RAW(0x79, BPF_REG_0, BPF_REG_10, -48, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 24),
    HC_RAW(0x71, BPF_REG_2, BPF_REG_1, 62, 0),
    HC_RAW(0x71, BPF_REG_7, BPF_REG_1, 63, 0),
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_2, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_4, -56, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_4, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_0, -48, 0),
    HC_RAW(0x4f, BPF_REG_2, BPF_REG_0, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_7, -88, 0),
    HC_RAW(0xdc, BPF_REG_7, BPF_REG_0, 0, 32),
    HC_RAW(0x18, BPF_REG_4, BPF_REG_0, 0, -65536),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_7, BPF_REG_4, 0, 0),
    HC_RAW(0xaf, BPF_REG_7, BPF_REG_2, 0, 0),
    HC_RAW(0x57, BPF_REG_8, BPF_REG_0, 0, 255),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -16, 0),
    /* pc 466: r2 = r3; r2 += 20; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_3, 0, 0, 1, 0, 20), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0xdc, BPF_REG_2, BPF_REG_0, 0, 16),
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_8, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_7, -8, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_7, 0, 0),
    HC_RAW(0x5f, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 16),
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x07, BPF_REG_2, BPF_REG_0, 0, 57147),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 65536),
    HC_RAW(0x2d, BPF_REG_8, BPF_REG_2, 4, 0),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 16),
    HC_RAW(0x57, BPF_REG_2, BPF_REG_0, 0, 65535),
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_4, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -72, 0),
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -64, 0),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -128, 0),
    HC_RAW(0x4f, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -120, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 24),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -112, 0),
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 24),
    HC_RAW(0x79, BPF_REG_0, BPF_REG_10, -24, 0),
    HC_RAW(0x2d, BPF_REG_8, BPF_REG_2, 4, 0),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_2, 0, 0),
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 16),
    HC_RAW(0x57, BPF_REG_2, BPF_REG_0, 0, 65535),
    HC_RAW(0x0f, BPF_REG_2, BPF_REG_4, 0, 0),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_3, 0, 0),
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_7, 0, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -56, 0),
    HC_RAW(0x4f, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0xb7, BPF_REG_7, BPF_REG_0, 0, 65536),
    HC_RAW(0x79, BPF_REG_4, BPF_REG_10, -32, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 8),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_4, -32, 0),
    HC_RAW(0x79, BPF_REG_4, BPF_REG_10, -40, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 16),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_4, -40, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 24),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_0, -24, 0),
    HC_RAW(0x79, BPF_REG_3, BPF_REG_10, -48, 0),
    HC_RAW(0x4f, BPF_REG_5, BPF_REG_3, 0, 0),
    /* pc 513: r8 = r6; r8 += -559038209; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_8, BPF_REG_6, 0, 0, 1, 0, -559038209), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x07, BPF_REG_9, BPF_REG_0, 0, -559038209),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 32),
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 32),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, 2135587861),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0x18, BPF_REG_0, BPF_REG_0, 0, -2142511073),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0x1f, BPF_REG_5, BPF_REG_6, 0, 0),
    HC_RAW(0x18, BPF_REG_6, BPF_REG_0, 0, -268435456),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_8, 0, 0),
    HC_RAW(0x5f, BPF_REG_0, BPF_REG_6, 0, 0),
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 28),
    HC_RAW(0xbf, BPF_REG_6, BPF_REG_8, 0, 0),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 4),
    HC_RAW(0x4f, BPF_REG_6, BPF_REG_0, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_6, 0, 0),
    HC_RAW(0x18, BPF_REG_4, BPF_REG_0, 0, -67108864),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_5, 0, 0),
    HC_RAW(0x5f, BPF_REG_0, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 26),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 6),
    HC_RAW(0x4f, BPF_REG_4, BPF_REG_0, 0, 0),
    HC_RAW(0x79, BPF_REG_0, BPF_REG_10, -88, 0),
    HC_RAW(0x57, BPF_REG_0, BPF_REG_0, 0, 65535),
    HC_RAW(0xbf, BPF_REG_6, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 2),
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_0, 0, 0),
    HC_RAW(0x0f, BPF_REG_8, BPF_REG_9, 0, 0),
    HC_RAW(0x1f, BPF_REG_9, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_9, BPF_REG_4, 0, 0),
    HC_RAW(0x18, BPF_REG_4, BPF_REG_0, 0, -16777216),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_9, 0, 0),
    HC_RAW(0x5f, BPF_REG_0, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 24),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_9, 0, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 8),
    HC_RAW(0x4f, BPF_REG_4, BPF_REG_0, 0, 0),
    HC_RAW(0x18, BPF_REG_0, BPF_REG_0, 0, 258571285),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531526),
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_0, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_6, -48, 0),
    /* pc 573: r0 = r7; r0 += 1892466935; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_0, BPF_REG_7, 0, 0, 1, 0, 1892466935), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_0, -88, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_0, 0, 0),
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 14),
    HC_RAW(0x47, BPF_REG_7, BPF_REG_0, 0, 7219),
    HC_RAW(0xa7, BPF_REG_0, BPF_REG_0, 0, -525483785),
    HC_RAW(0x1f, BPF_REG_0, BPF_REG_7, 0, 0),
    HC_RAW(0xbf, BPF_REG_6, BPF_REG_0, 0, 0),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 32),
    HC_RAW(0x18, BPF_REG_0, BPF_REG_0, 0, 33605642),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 4268),
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_0, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_7, -8, 0),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_8, 0, 0),
    HC_RAW(0x1f, BPF_REG_8, BPF_REG_9, 0, 0),
    HC_RAW(0xaf, BPF_REG_8, BPF_REG_4, 0, 0),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_8, 0, 0),
    HC_RAW(0x18, BPF_REG_0, BPF_REG_0, 0, -65536),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_4, BPF_REG_0, 0, 0),
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 16),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_8, 0, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 16),
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_4, 0, 0),
    HC_RAW(0x79, BPF_REG_4, BPF_REG_10, -48, 0),
    HC_RAW(0xaf, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_4, -48, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, -2097152),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_6, -56, 0),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_6, 0, 0),
    HC_RAW(0x5f, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 21),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_6, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 11),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -64, 0),
    HC_RAW(0x0f, BPF_REG_9, BPF_REG_5, 0, 0),
    HC_RAW(0x1f, BPF_REG_5, BPF_REG_8, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_0, 0, 0),
    HC_RAW(0x18, BPF_REG_4, BPF_REG_0, 0, -8192),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_5, 0, 0),
    HC_RAW(0x5f, BPF_REG_0, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_0, BPF_REG_0, 0, 13),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 19),
    HC_RAW(0x4f, BPF_REG_4, BPF_REG_0, 0, 0),
    HC_RAW(0x0f, BPF_REG_8, BPF_REG_9, 0, 0),
    HC_RAW(0x1f, BPF_REG_9, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_9, BPF_REG_4, 0, 0),
    HC_RAW(0x79, BPF_REG_6, BPF_REG_10, -48, 0),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_6, 0, 0),
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 2),
    HC_RAW(0x67, BPF_REG_6, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_4, 0, 0),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_8, 0, 0),
    HC_RAW(0x79, BPF_REG_0, BPF_REG_10, -24, 0),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_5, 0, 0),
    /* pc 634: r4 = r9; r4 += r5; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_4, BPF_REG_9, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0x18, BPF_REG_5, BPF_REG_0, 0, -262144),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_4, 0, 0),
    HC_RAW(0x5f, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_7, BPF_REG_0, 0, 18),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_0, BPF_REG_9, 0, 0),
    HC_RAW(0xbf, BPF_REG_9, BPF_REG_4, 0, 0),
    HC_RAW(0x67, BPF_REG_9, BPF_REG_0, 0, 14),
    HC_RAW(0x4f, BPF_REG_9, BPF_REG_7, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_0, 0, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, -268435456),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_7, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_7, BPF_REG_0, 0, 28),
    HC_RAW(0x1f, BPF_REG_8, BPF_REG_0, 0, 0),
    HC_RAW(0x67, BPF_REG_0, BPF_REG_0, 0, 4),
    HC_RAW(0x4f, BPF_REG_0, BPF_REG_7, 0, 0),
    HC_RAW(0xaf, BPF_REG_8, BPF_REG_0, 0, 0),
    HC_RAW(0xaf, BPF_REG_8, BPF_REG_4, 0, 0),
    HC_RAW(0x1f, BPF_REG_8, BPF_REG_9, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_8, 0, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, -2097152),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_7, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_7, BPF_REG_0, 0, 21),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_8, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 11),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_7, 0, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 16),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 32),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 32),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -8, 0),
    HC_RAW(0xaf, BPF_REG_7, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -40, 0),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -32, 0),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -80, 0),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_8, 0, 0),
    HC_RAW(0x1f, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_0, BPF_REG_10, -16, 0),
    HC_RAW(0x57, BPF_REG_0, BPF_REG_0, 0, 65535),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_7, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, -65525),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 512),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x7b, BPF_REG_10, BPF_REG_3, -8, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, -128),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0x5f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 7),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 25),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_7, BPF_REG_4, 0, 0),
    HC_RAW(0x1f, BPF_REG_7, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_7, 0, 0),
    HC_RAW(0x18, BPF_REG_9, BPF_REG_0, 0, -65536),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_2, BPF_REG_9, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 16),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_7, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 16),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_7, 0, 0),
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_8, 0, 0),
    HC_RAW(0x1f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x18, BPF_REG_8, BPF_REG_0, 0, -268435456),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_3, BPF_REG_8, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 28),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_2, 0, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 4),
    HC_RAW(0x4f, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0x1f, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0x18, BPF_REG_5, BPF_REG_0, 0, -262144),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_4, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_4, BPF_REG_0, 0, 18),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 14),
    HC_RAW(0x4f, BPF_REG_5, BPF_REG_4, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_7, 0, 0),
    HC_RAW(0x1f, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0x18, BPF_REG_4, BPF_REG_0, 0, -256),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x5f, BPF_REG_5, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 8),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 24),
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x1f, BPF_REG_3, BPF_REG_7, 0, 0),
    HC_RAW(0x07, BPF_REG_3, BPF_REG_0, 0, -525483785),
    HC_RAW(0x79, BPF_REG_4, BPF_REG_10, -56, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -64, 0),
    HC_RAW(0x1f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x18, BPF_REG_5, BPF_REG_0, 0, -128),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 7),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 25),
    HC_RAW(0x4f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x79, BPF_REG_7, BPF_REG_10, -88, 0),
    HC_RAW(0xaf, BPF_REG_2, BPF_REG_7, 0, 0),
    HC_RAW(0x1f, BPF_REG_2, BPF_REG_5, 0, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x5f, BPF_REG_5, BPF_REG_9, 0, 0),
    HC_RAW(0x77, BPF_REG_5, BPF_REG_0, 0, 16),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_2, 0, 0),
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 16),
    HC_RAW(0x4f, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_4, 0, 0),
    HC_RAW(0x1f, BPF_REG_5, BPF_REG_7, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0x5f, BPF_REG_7, BPF_REG_8, 0, 0),
    HC_RAW(0x77, BPF_REG_7, BPF_REG_0, 0, 28),
    HC_RAW(0xbf, BPF_REG_8, BPF_REG_5, 0, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 4),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_7, 0, 0),
    HC_RAW(0xbf, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_7, BPF_REG_3, 0, 0),
    HC_RAW(0x1f, BPF_REG_7, BPF_REG_8, 0, 0),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_7, 0, 0),
    HC_RAW(0x18, BPF_REG_4, BPF_REG_0, 0, -262144),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_3, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_3, BPF_REG_0, 0, 18),
    HC_RAW(0xbf, BPF_REG_8, BPF_REG_7, 0, 0),
    HC_RAW(0x67, BPF_REG_8, BPF_REG_0, 0, 14),
    HC_RAW(0x4f, BPF_REG_8, BPF_REG_3, 0, 0),
    HC_RAW(0xaf, BPF_REG_7, BPF_REG_2, 0, 0),
    HC_RAW(0x1f, BPF_REG_7, BPF_REG_8, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_7, 0, 0),
    HC_RAW(0x18, BPF_REG_3, BPF_REG_0, 0, -256),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, 0),
    HC_RAW(0x5f, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 8),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_7, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 24),
    HC_RAW(0x4f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_7, BPF_REG_5, 0, 0),
    HC_RAW(0x1f, BPF_REG_7, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_7, BPF_REG_0, 0, 32),
    HC_RAW(0x77, BPF_REG_7, BPF_REG_0, 0, 32),
    HC_RAW(0x97, BPF_REG_7, BPF_REG_0, 0, 65537),
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_7, 0, 0),
    HC_RAW(0x18, BPF_REG_5, BPF_REG_0, 0, 2135587861),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_6, BPF_REG_5, 0, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -48, 0),
    HC_RAW(0xaf, BPF_REG_6, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_6, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_6, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, 2135587862),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_6, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_4, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_2, 0, 0),
    HC_RAW(0x0f, BPF_REG_4, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_4, BPF_REG_3, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_4, 0, 0),
    HC_RAW(0x67, BPF_REG_2, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_4, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_2, 0, 0),
    HC_RAW(0x0f, BPF_REG_0, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_0, BPF_REG_4, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_0, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0x67, BPF_REG_3, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x79, BPF_REG_2, BPF_REG_10, -8, 0),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_2, 0, 0),
    HC_RAW(0x0f, BPF_REG_3, BPF_REG_5, 0, 0),
    HC_RAW(0xaf, BPF_REG_3, BPF_REG_0, 0, 0),
    HC_RAW(0xbf, BPF_REG_2, BPF_REG_3, 0, 0),
    HC_RAW(0x77, BPF_REG_2, BPF_REG_0, 0, 2),
    HC_RAW(0xbf, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0x67, BPF_REG_5, BPF_REG_0, 0, 6),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0x18, BPF_REG_2, BPF_REG_0, 0, 2135587864),
    HC_RAW(0x00, BPF_REG_0, BPF_REG_0, 0, -1640531527),
    HC_RAW(0x0f, BPF_REG_5, BPF_REG_2, 0, 0),
    HC_RAW(0xaf, BPF_REG_5, BPF_REG_3, 0, 0),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 3),
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, -541, 0),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 1),
    /* pc 848: r3 = r1; r3 += 50; leaq kinsn */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_1, 0, 0, 1, 0, 50), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    HC_RAW(0xb7, BPF_REG_8, BPF_REG_0, 0, 1),
    HC_RAW(0x2d, BPF_REG_3, BPF_REG_2, -546, 0),
    HC_RAW(0xb7, BPF_REG_5, BPF_REG_0, 0, 2),
    HC_RAW(0x05, BPF_REG_0, BPF_REG_0, -549, 0),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
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
  1c:	48 8b 77 08          	mov    rsi,QWORD PTR [rdi+0x8]
  20:	48 8b 7f 00          	mov    rdi,QWORD PTR [rdi+0x0]
  24:	48 39 f7             	cmp    rdi,rsi
  27:	0f 87 64 05 00 00    	ja     0x591
  2d:	4c 8d 47 08          	lea    r8,[rdi+0x8]
  31:	49 39 f0             	cmp    r8,rsi
  34:	0f 87 57 05 00 00    	ja     0x591
  3a:	48 8d 57 16          	lea    rdx,[rdi+0x16]
  3e:	48 39 f2             	cmp    rdx,rsi
  41:	0f 87 4a 05 00 00    	ja     0x591
  47:	48 89 f1             	mov    rcx,rsi
  4a:	4c 29 c1             	sub    rcx,r8
  4d:	48 0f b6 47 14       	movzx  rax,BYTE PTR [rdi+0x14]
  52:	4c 0f b6 47 15       	movzx  r8,BYTE PTR [rdi+0x15]
  57:	49 c1 e0 08          	shl    r8,0x8
  5b:	49 09 c0             	or     r8,rax
  5e:	49 81 e0 ff ff 00 00 	and    r8,0xffff
  65:	49 81 f8 86 dd 00 00 	cmp    r8,0xdd86
  6c:	0f 84 42 04 00 00    	je     0x4b4
  72:	49 83 f8 08          	cmp    r8,0x8
  76:	0f 85 70 04 00 00    	jne    0x4ec
  7c:	4c 8d 47 2a          	lea    r8,[rdi+0x2a]
  80:	49 39 f0             	cmp    r8,rsi
  83:	0f 87 55 04 00 00    	ja     0x4de
  89:	48 0f b6 52 00       	movzx  rdx,BYTE PTR [rdx+0x0]
  8e:	48 83 e2 0f          	and    rdx,0xf
  92:	48 83 fa 05          	cmp    rdx,0x5
  96:	0f 85 42 04 00 00    	jne    0x4de
  9c:	48 0f b6 57 1c       	movzx  rdx,BYTE PTR [rdi+0x1c]
  a1:	48 83 e2 3f          	and    rdx,0x3f
  a5:	4c 0f b6 47 1d       	movzx  r8,BYTE PTR [rdi+0x1d]
  aa:	4c 09 c2             	or     rdx,r8
  ad:	48 81 e2 ff 00 00 00 	and    rdx,0xff
  b4:	48 85 d2             	test   rdx,rdx
  b7:	0f 85 21 04 00 00    	jne    0x4de
  bd:	48 0f b6 57 1f       	movzx  rdx,BYTE PTR [rdi+0x1f]
  c2:	41 b8 02 00 00 00    	mov    r8d,0x2
  c8:	41 be 02 00 00 00    	mov    r14d,0x2
  ce:	48 83 fa 01          	cmp    rdx,0x1
  d2:	0f 84 48 04 00 00    	je     0x520
  d8:	48 83 fa 11          	cmp    rdx,0x11
  dc:	0f 84 59 0c 00 00    	je     0xd3b
  e2:	48 83 fa 06          	cmp    rdx,0x6
  e6:	0f 85 34 04 00 00    	jne    0x520
  ec:	48 8d 57 3e          	lea    rdx,[rdi+0x3e]
  f0:	41 b8 01 00 00 00    	mov    r8d,0x1
  f6:	41 be 01 00 00 00    	mov    r14d,0x1
  fc:	48 39 f2             	cmp    rdx,rsi
  ff:	0f 87 1b 04 00 00    	ja     0x520
 105:	48 0f b6 77 27       	movzx  rsi,BYTE PTR [rdi+0x27]
 10a:	48 c1 e6 08          	shl    rsi,0x8
 10e:	48 0f b6 57 26       	movzx  rdx,BYTE PTR [rdi+0x26]
 113:	48 09 d6             	or     rsi,rdx
 116:	48 0f b6 57 28       	movzx  rdx,BYTE PTR [rdi+0x28]
 11b:	48 c1 e2 10          	shl    rdx,0x10
 11f:	48 09 d6             	or     rsi,rdx
 122:	48 0f b6 57 29       	movzx  rdx,BYTE PTR [rdi+0x29]
 127:	48 c1 e2 18          	shl    rdx,0x18
 12b:	48 09 d6             	or     rsi,rdx
 12e:	48 c1 e6 20          	shl    rsi,0x20
 132:	48 c1 ee 20          	shr    rsi,0x20
 136:	41 b8 02 00 00 00    	mov    r8d,0x2
 13c:	41 be 02 00 00 00    	mov    r14d,0x2
 142:	48 81 fe 0a 64 01 01 	cmp    rsi,0x101640a
 149:	0f 85 d1 03 00 00    	jne    0x520
 14f:	48 0f b6 77 2d       	movzx  rsi,BYTE PTR [rdi+0x2d]
 154:	48 c1 e6 08          	shl    rsi,0x8
 158:	48 0f b6 57 2c       	movzx  rdx,BYTE PTR [rdi+0x2c]
 15d:	48 09 d6             	or     rsi,rdx
 160:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 167:	48 81 fe 1f 90 00 00 	cmp    rsi,0x901f
 16e:	0f 85 ac 03 00 00    	jne    0x520
 174:	41 b8 01 00 00 00    	mov    r8d,0x1
 17a:	41 be 01 00 00 00    	mov    r14d,0x1
 180:	48 81 f9 ea 05 00 00 	cmp    rcx,0x5ea
 187:	0f 8f 93 03 00 00    	jg     0x520
 18d:	48 0f b6 5f 18       	movzx  rbx,BYTE PTR [rdi+0x18]
 192:	48 c1 e3 08          	shl    rbx,0x8
 196:	48 0f b6 77 19       	movzx  rsi,BYTE PTR [rdi+0x19]
 19b:	48 09 f3             	or     rbx,rsi
 19e:	48 0f b6 4f 17       	movzx  rcx,BYTE PTR [rdi+0x17]
 1a3:	4c 0f b6 6f 23       	movzx  r13,BYTE PTR [rdi+0x23]
 1a8:	49 c1 e5 08          	shl    r13,0x8
 1ac:	4c 0f b6 47 22       	movzx  r8,BYTE PTR [rdi+0x22]
 1b1:	4c 0f b6 77 24       	movzx  r14,BYTE PTR [rdi+0x24]
 1b6:	49 c1 e6 10          	shl    r14,0x10
 1ba:	48 0f b6 77 25       	movzx  rsi,BYTE PTR [rdi+0x25]
 1bf:	48 c1 e6 18          	shl    rsi,0x18
 1c3:	48 0f b6 57 2a       	movzx  rdx,BYTE PTR [rdi+0x2a]
 1c8:	4c 0f b6 7f 2b       	movzx  r15,BYTE PTR [rdi+0x2b]
 1cd:	49 c1 e7 08          	shl    r15,0x8
 1d1:	49 09 d7             	or     r15,rdx
 1d4:	48 89 f0             	mov    rax,rsi
 1d7:	4c 09 f0             	or     rax,r14
 1da:	4c 89 7d e8          	mov    QWORD PTR [rbp-0x18],r15
 1de:	4c 89 fa             	mov    rdx,r15
 1e1:	0f ca                	bswap  edx
 1e3:	41 bf 00 00 ff ff    	mov    r15d,0xffff0000
 1e9:	4c 21 fa             	and    rdx,r15
 1ec:	48 31 c2             	xor    rdx,rax
 1ef:	48 89 5d f0          	mov    QWORD PTR [rbp-0x10],rbx
 1f3:	48 8d 43 14          	lea    rax,[rbx+0x14]
 1f7:	66 c1 c8 08          	ror    ax,0x8
 1fb:	0f b7 c0             	movzx  eax,ax
 1fe:	48 01 c1             	add    rcx,rax
 201:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 205:	48 89 d0             	mov    rax,rdx
 208:	4c 21 f8             	and    rax,r15
 20b:	48 c1 e8 10          	shr    rax,0x10
 20f:	48 01 c1             	add    rcx,rax
 212:	48 81 c1 3b df 00 00 	add    rcx,0xdf3b
 219:	b8 00 00 01 00       	mov    eax,0x10000
 21e:	48 39 c8             	cmp    rax,rcx
 221:	77 11                	ja     0x234
 223:	49 89 cf             	mov    r15,rcx
 226:	49 c1 ef 10          	shr    r15,0x10
 22a:	48 81 e1 ff ff 00 00 	and    rcx,0xffff
 231:	4c 01 f9             	add    rcx,r15
 234:	4d 09 c5             	or     r13,r8
 237:	48 39 c8             	cmp    rax,rcx
 23a:	77 11                	ja     0x24d
 23c:	49 89 c8             	mov    r8,rcx
 23f:	49 c1 e8 10          	shr    r8,0x10
 243:	48 81 e1 ff ff 00 00 	and    rcx,0xffff
 24a:	4c 01 c1             	add    rcx,r8
 24d:	4d 09 f5             	or     r13,r14
 250:	49 09 f5             	or     r13,rsi
 253:	4c 89 ee             	mov    rsi,r13
 256:	48 c1 e6 20          	shl    rsi,0x20
 25a:	48 c1 ee 20          	shr    rsi,0x20
 25e:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 265:	79 37 9e 
 268:	48 01 d6             	add    rsi,rdx
 26b:	49 89 f0             	mov    r8,rsi
 26e:	49 c1 e0 06          	shl    r8,0x6
 272:	49 89 f7             	mov    r15,rsi
 275:	49 c1 ef 02          	shr    r15,0x2
 279:	4d 01 c7             	add    r15,r8
 27c:	49 b8 1f e0 4b 80 b9 	movabs r8,0x9e3779b9804be01f
 283:	79 37 9e 
 286:	4d 01 c7             	add    r15,r8
 289:	49 31 f7             	xor    r15,rsi
 28c:	48 8b 5d e8          	mov    rbx,QWORD PTR [rbp-0x18]
 290:	48 81 e3 ff ff 00 00 	and    rbx,0xffff
 297:	48 8d 93 f7 c0 cc 70 	lea    rdx,[rbx+0x70ccc0f7]
 29e:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
 2a2:	49 89 d0             	mov    r8,rdx
 2a5:	49 c1 e0 0e          	shl    r8,0xe
 2a9:	49 81 c8 33 1c 00 00 	or     r8,0x1c33
 2b0:	48 81 f2 f7 c0 ad e0 	xor    rdx,0xffffffffe0adc0f7
 2b7:	4c 29 c2             	sub    rdx,r8
 2ba:	4d 89 f8             	mov    r8,r15
 2bd:	49 c1 e8 02          	shr    r8,0x2
 2c1:	4d 89 fe             	mov    r14,r15
 2c4:	49 c1 e6 06          	shl    r14,0x6
 2c8:	4d 01 c6             	add    r14,r8
 2cb:	41 b8 00 00 e0 ff    	mov    r8d,0xffe00000
 2d1:	48 89 d6             	mov    rsi,rdx
 2d4:	4c 21 c6             	and    rsi,r8
 2d7:	48 c1 ee 15          	shr    rsi,0x15
 2db:	48 89 d0             	mov    rax,rdx
 2de:	48 c1 e0 0b          	shl    rax,0xb
 2e2:	48 09 f0             	or     rax,rsi
 2e5:	49 81 c5 f7 c0 ad e0 	add    r13,0xffffffffe0adc0f7
 2ec:	49 89 d0             	mov    r8,rdx
 2ef:	4d 31 e8             	xor    r8,r13
 2f2:	49 29 c0             	sub    r8,rax
 2f5:	49 01 de             	add    r14,rbx
 2f8:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
 2fc:	48 c1 e0 20          	shl    rax,0x20
 300:	48 be 0a c8 00 02 ac 	movabs rsi,0x10ac0200c80a
 307:	10 00 00 
 30a:	48 09 f0             	or     rax,rsi
 30d:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
 311:	be 80 ff ff ff       	mov    esi,0xffffff80
 316:	4c 89 c0             	mov    rax,r8
 319:	48 21 f0             	and    rax,rsi
 31c:	48 c1 e8 07          	shr    rax,0x7
 320:	4c 89 c6             	mov    rsi,r8
 323:	48 c1 e6 19          	shl    rsi,0x19
 327:	48 09 c6             	or     rsi,rax
 32a:	4d 89 c5             	mov    r13,r8
 32d:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 331:	49 31 c5             	xor    r13,rax
 334:	49 29 f5             	sub    r13,rsi
 337:	4c 89 ee             	mov    rsi,r13
 33a:	b8 00 00 ff ff       	mov    eax,0xffff0000
 33f:	48 21 c6             	and    rsi,rax
 342:	48 c1 ee 10          	shr    rsi,0x10
 346:	4c 89 e8             	mov    rax,r13
 349:	48 c1 e0 10          	shl    rax,0x10
 34d:	48 09 f0             	or     rax,rsi
 350:	4c 89 eb             	mov    rbx,r13
 353:	48 31 d3             	xor    rbx,rdx
 356:	48 29 c3             	sub    rbx,rax
 359:	48 be 15 7c 69 0f ba 	movabs rsi,0x9e3779ba0f697c15
 360:	79 37 9e 
 363:	49 01 f6             	add    r14,rsi
 366:	4d 31 fe             	xor    r14,r15
 369:	be 00 00 00 f0       	mov    esi,0xf0000000
 36e:	48 89 da             	mov    rdx,rbx
 371:	48 21 f2             	and    rdx,rsi
 374:	48 c1 ea 1c          	shr    rdx,0x1c
 378:	49 89 df             	mov    r15,rbx
 37b:	49 c1 e7 04          	shl    r15,0x4
 37f:	49 09 d7             	or     r15,rdx
 382:	4c 89 f6             	mov    rsi,r14
 385:	48 c1 ee 02          	shr    rsi,0x2
 389:	4c 89 f0             	mov    rax,r14
 38c:	48 c1 e0 06          	shl    rax,0x6
 390:	48 01 f0             	add    rax,rsi
 393:	48 89 de             	mov    rsi,rbx
 396:	4c 31 c6             	xor    rsi,r8
 399:	4c 29 fe             	sub    rsi,r15
 39c:	ba 00 00 fc ff       	mov    edx,0xfffc0000
 3a1:	49 89 f0             	mov    r8,rsi
 3a4:	49 21 d0             	and    r8,rdx
 3a7:	49 c1 e8 12          	shr    r8,0x12
 3ab:	48 89 f2             	mov    rdx,rsi
 3ae:	48 c1 e2 0e          	shl    rdx,0xe
 3b2:	4c 09 c2             	or     rdx,r8
 3b5:	4c 31 ee             	xor    rsi,r13
 3b8:	48 29 d6             	sub    rsi,rdx
 3bb:	ba 00 ff ff ff       	mov    edx,0xffffff00
 3c0:	49 89 f0             	mov    r8,rsi
 3c3:	49 21 d0             	and    r8,rdx
 3c6:	49 c1 e8 08          	shr    r8,0x8
 3ca:	48 89 f2             	mov    rdx,rsi
 3cd:	48 c1 e2 18          	shl    rdx,0x18
 3d1:	4c 09 c2             	or     rdx,r8
 3d4:	48 31 de             	xor    rsi,rbx
 3d7:	48 29 d6             	sub    rsi,rdx
 3da:	48 c1 e1 10          	shl    rcx,0x10
 3de:	48 c1 e1 20          	shl    rcx,0x20
 3e2:	48 c1 e9 20          	shr    rcx,0x20
 3e6:	48 8b 5d f8          	mov    rbx,QWORD PTR [rbp-0x8]
 3ea:	48 31 cb             	xor    rbx,rcx
 3ed:	4c 8b 45 f0          	mov    r8,QWORD PTR [rbp-0x10]
 3f1:	49 81 e0 ff ff 00 00 	and    r8,0xffff
 3f8:	4c 31 c3             	xor    rbx,r8
 3fb:	48 ba 0b 00 ff ff 00 	movabs rdx,0x200ffff000b
 402:	02 00 00 
 405:	48 31 d3             	xor    rbx,rdx
 408:	48 c1 e6 20          	shl    rsi,0x20
 40c:	48 c1 ee 20          	shr    rsi,0x20
 410:	50                   	push   rax
 411:	52                   	push   rdx
 412:	49 c7 c3 01 00 01 00 	mov    r11,0x10001
 419:	48 89 f0             	mov    rax,rsi
 41c:	31 d2                	xor    edx,edx
 41e:	49 f7 f3             	div    r11
 421:	48 89 d6             	mov    rsi,rdx
 424:	5a                   	pop    rdx
 425:	58                   	pop    rax
 426:	48 01 f0             	add    rax,rsi
 429:	48 be 15 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c15
 430:	79 37 9e 
 433:	48 01 f0             	add    rax,rsi
 436:	4c 31 f0             	xor    rax,r14
 439:	48 89 c6             	mov    rsi,rax
 43c:	48 c1 ee 02          	shr    rsi,0x2
 440:	48 89 c2             	mov    rdx,rax
 443:	48 c1 e2 06          	shl    rdx,0x6
 447:	48 01 f2             	add    rdx,rsi
 44a:	48 be 16 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c16
 451:	79 37 9e 
 454:	48 01 f2             	add    rdx,rsi
 457:	48 31 c2             	xor    rdx,rax
 45a:	48 89 d6             	mov    rsi,rdx
 45d:	48 c1 ee 02          	shr    rsi,0x2
 461:	48 89 d1             	mov    rcx,rdx
 464:	48 c1 e1 06          	shl    rcx,0x6
 468:	48 01 f1             	add    rcx,rsi
 46b:	48 b8 15 7c 4a 7f b9 	movabs rax,0x9e3779b97f4a7c15
 472:	79 37 9e 
 475:	48 01 c1             	add    rcx,rax
 478:	48 31 d1             	xor    rcx,rdx
 47b:	48 89 ce             	mov    rsi,rcx
 47e:	48 c1 e6 06          	shl    rsi,0x6
 482:	49 01 f0             	add    r8,rsi
 485:	48 89 ce             	mov    rsi,rcx
 488:	48 c1 ee 02          	shr    rsi,0x2
 48c:	49 01 f0             	add    r8,rsi
 48f:	49 01 c0             	add    r8,rax
 492:	49 31 c8             	xor    r8,rcx
 495:	4c 89 c6             	mov    rsi,r8
 498:	48 c1 ee 02          	shr    rsi,0x2
 49c:	4c 89 c2             	mov    rdx,r8
 49f:	48 c1 e2 06          	shl    rdx,0x6
 4a3:	48 01 f2             	add    rdx,rsi
 4a6:	48 01 da             	add    rdx,rbx
 4a9:	48 01 c2             	add    rdx,rax
 4ac:	4c 31 c2             	xor    rdx,r8
 4af:	e9 5b 08 00 00       	jmp    0xd0f
 4b4:	48 8d 57 3e          	lea    rdx,[rdi+0x3e]
 4b8:	48 39 f2             	cmp    rdx,rsi
 4bb:	77 21                	ja     0x4de
 4bd:	48 0f b6 5f 1c       	movzx  rbx,BYTE PTR [rdi+0x1c]
 4c2:	41 b8 02 00 00 00    	mov    r8d,0x2
 4c8:	41 be 02 00 00 00    	mov    r14d,0x2
 4ce:	48 83 fb 3a          	cmp    rbx,0x3a
 4d2:	74 4c                	je     0x520
 4d4:	48 83 fb 2c          	cmp    rbx,0x2c
 4d8:	0f 85 bc 00 00 00    	jne    0x59a
 4de:	41 b8 01 00 00 00    	mov    r8d,0x1
 4e4:	41 be 01 00 00 00    	mov    r14d,0x1
 4ea:	eb 34                	jmp    0x520
 4ec:	48 be 15 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c15
 4f3:	79 37 9e 
 4f6:	48 01 f1             	add    rcx,rsi
 4f9:	48 89 ce             	mov    rsi,rcx
 4fc:	48 c1 ee 02          	shr    rsi,0x2
 500:	49 89 c8             	mov    r8,rcx
 503:	49 c1 e0 06          	shl    r8,0x6
 507:	49 01 f0             	add    r8,rsi
 50a:	48 be 17 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c17
 511:	79 37 9e 
 514:	49 01 f0             	add    r8,rsi
 517:	49 31 c8             	xor    r8,rcx
 51a:	41 be 02 00 00 00    	mov    r14d,0x2
 520:	4c 89 c2             	mov    rdx,r8
 523:	48 c1 ea 02          	shr    rdx,0x2
 527:	4c 89 c6             	mov    rsi,r8
 52a:	48 c1 e6 06          	shl    rsi,0x6
 52e:	48 01 d6             	add    rsi,rdx
 531:	4c 01 f6             	add    rsi,r14
 534:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 53b:	79 37 9e 
 53e:	48 01 d6             	add    rsi,rdx
 541:	4c 31 c6             	xor    rsi,r8
 544:	48 89 f2             	mov    rdx,rsi
 547:	48 c1 ea 38          	shr    rdx,0x38
 54b:	88 57 07             	mov    BYTE PTR [rdi+0x7],dl
 54e:	48 89 f2             	mov    rdx,rsi
 551:	48 c1 ea 30          	shr    rdx,0x30
 555:	88 57 06             	mov    BYTE PTR [rdi+0x6],dl
 558:	48 89 f2             	mov    rdx,rsi
 55b:	48 c1 ea 28          	shr    rdx,0x28
 55f:	88 57 05             	mov    BYTE PTR [rdi+0x5],dl
 562:	48 89 f2             	mov    rdx,rsi
 565:	48 c1 ea 20          	shr    rdx,0x20
 569:	88 57 04             	mov    BYTE PTR [rdi+0x4],dl
 56c:	48 89 f2             	mov    rdx,rsi
 56f:	48 c1 ea 18          	shr    rdx,0x18
 573:	88 57 03             	mov    BYTE PTR [rdi+0x3],dl
 576:	48 89 f2             	mov    rdx,rsi
 579:	48 c1 ea 10          	shr    rdx,0x10
 57d:	88 57 02             	mov    BYTE PTR [rdi+0x2],dl
 580:	40 88 77 00          	mov    BYTE PTR [rdi+0x0],sil
 584:	48 c1 ee 08          	shr    rsi,0x8
 588:	40 88 77 01          	mov    BYTE PTR [rdi+0x1],sil
 58c:	b8 02 00 00 00       	mov    eax,0x2
 591:	41 5f                	pop    r15
 593:	41 5e                	pop    r14
 595:	41 5d                	pop    r13
 597:	5b                   	pop    rbx
 598:	c9                   	leave
 599:	c3                   	ret
 59a:	48 0f b6 57 1a       	movzx  rdx,BYTE PTR [rdi+0x1a]
 59f:	48 89 55 f0          	mov    QWORD PTR [rbp-0x10],rdx
 5a3:	48 0f b6 57 1b       	movzx  rdx,BYTE PTR [rdi+0x1b]
 5a8:	48 89 95 58 ff ff ff 	mov    QWORD PTR [rbp-0xa8],rdx
 5af:	48 0f b6 57 16       	movzx  rdx,BYTE PTR [rdi+0x16]
 5b4:	48 89 95 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rdx
 5bb:	48 0f b6 57 17       	movzx  rdx,BYTE PTR [rdi+0x17]
 5c0:	48 89 95 60 ff ff ff 	mov    QWORD PTR [rbp-0xa0],rdx
 5c7:	48 0f b6 57 23       	movzx  rdx,BYTE PTR [rdi+0x23]
 5cc:	48 89 55 a8          	mov    QWORD PTR [rbp-0x58],rdx
 5d0:	48 0f b6 57 22       	movzx  rdx,BYTE PTR [rdi+0x22]
 5d5:	48 89 95 68 ff ff ff 	mov    QWORD PTR [rbp-0x98],rdx
 5dc:	48 0f b6 57 27       	movzx  rdx,BYTE PTR [rdi+0x27]
 5e1:	48 89 55 98          	mov    QWORD PTR [rbp-0x68],rdx
 5e5:	48 0f b6 57 26       	movzx  rdx,BYTE PTR [rdi+0x26]
 5ea:	48 89 95 70 ff ff ff 	mov    QWORD PTR [rbp-0x90],rdx
 5f1:	48 0f b6 57 28       	movzx  rdx,BYTE PTR [rdi+0x28]
 5f6:	48 89 55 b8          	mov    QWORD PTR [rbp-0x48],rdx
 5fa:	48 0f b6 57 24       	movzx  rdx,BYTE PTR [rdi+0x24]
 5ff:	48 89 55 c0          	mov    QWORD PTR [rbp-0x40],rdx
 603:	48 0f b6 57 1f       	movzx  rdx,BYTE PTR [rdi+0x1f]
 608:	48 89 55 a0          	mov    QWORD PTR [rbp-0x60],rdx
 60c:	48 0f b6 57 1e       	movzx  rdx,BYTE PTR [rdi+0x1e]
 611:	48 89 55 80          	mov    QWORD PTR [rbp-0x80],rdx
 615:	48 0f b6 57 25       	movzx  rdx,BYTE PTR [rdi+0x25]
 61a:	48 89 55 88          	mov    QWORD PTR [rbp-0x78],rdx
 61e:	48 0f b6 57 29       	movzx  rdx,BYTE PTR [rdi+0x29]
 623:	48 89 55 90          	mov    QWORD PTR [rbp-0x70],rdx
 627:	48 0f b6 57 2a       	movzx  rdx,BYTE PTR [rdi+0x2a]
 62c:	48 89 55 b0          	mov    QWORD PTR [rbp-0x50],rdx
 630:	48 0f b6 57 2e       	movzx  rdx,BYTE PTR [rdi+0x2e]
 635:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 639:	48 0f b6 57 2b       	movzx  rdx,BYTE PTR [rdi+0x2b]
 63e:	48 89 55 e0          	mov    QWORD PTR [rbp-0x20],rdx
 642:	48 0f b6 57 2c       	movzx  rdx,BYTE PTR [rdi+0x2c]
 647:	48 89 55 d8          	mov    QWORD PTR [rbp-0x28],rdx
 64b:	48 0f b6 57 2d       	movzx  rdx,BYTE PTR [rdi+0x2d]
 650:	48 89 55 e8          	mov    QWORD PTR [rbp-0x18],rdx
 654:	48 0f b6 57 2f       	movzx  rdx,BYTE PTR [rdi+0x2f]
 659:	48 0f b6 47 30       	movzx  rax,BYTE PTR [rdi+0x30]
 65e:	4c 0f b6 7f 31       	movzx  r15,BYTE PTR [rdi+0x31]
 663:	4c 0f b6 47 20       	movzx  r8,BYTE PTR [rdi+0x20]
 668:	4c 89 45 c8          	mov    QWORD PTR [rbp-0x38],r8
 66c:	4c 0f b6 47 21       	movzx  r8,BYTE PTR [rdi+0x21]
 671:	4c 89 45 d0          	mov    QWORD PTR [rbp-0x30],r8
 675:	48 83 fb 11          	cmp    rbx,0x11
 679:	74 2b                	je     0x6a6
 67b:	41 b8 02 00 00 00    	mov    r8d,0x2
 681:	48 83 fb 06          	cmp    rbx,0x6
 685:	0f 85 95 fe ff ff    	jne    0x520
 68b:	41 b8 01 00 00 00    	mov    r8d,0x1
 691:	4c 8d 6f 52          	lea    r13,[rdi+0x52]
 695:	41 be 01 00 00 00    	mov    r14d,0x1
 69b:	49 39 f5             	cmp    r13,rsi
 69e:	0f 87 7c fe ff ff    	ja     0x520
 6a4:	eb 19                	jmp    0x6bf
 6a6:	41 b8 01 00 00 00    	mov    r8d,0x1
 6ac:	4c 8d 6f 46          	lea    r13,[rdi+0x46]
 6b0:	41 be 01 00 00 00    	mov    r14d,0x1
 6b6:	49 39 f5             	cmp    r13,rsi
 6b9:	0f 87 61 fe ff ff    	ja     0x520
 6bf:	41 b8 02 00 00 00    	mov    r8d,0x2
 6c5:	41 be 02 00 00 00    	mov    r14d,0x2
 6cb:	48 83 fb 06          	cmp    rbx,0x6
 6cf:	0f 85 4b fe ff ff    	jne    0x520
 6d5:	48 c1 e2 08          	shl    rdx,0x8
 6d9:	48 c1 e0 10          	shl    rax,0x10
 6dd:	49 c1 e7 18          	shl    r15,0x18
 6e1:	49 09 c7             	or     r15,rax
 6e4:	49 09 d7             	or     r15,rdx
 6e7:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 6eb:	49 09 f7             	or     r15,rsi
 6ee:	49 c1 e7 20          	shl    r15,0x20
 6f2:	49 c1 ef 20          	shr    r15,0x20
 6f6:	49 81 ff 0a 64 01 01 	cmp    r15,0x101640a
 6fd:	0f 85 1d fe ff ff    	jne    0x520
 703:	48 0f b6 77 41       	movzx  rsi,BYTE PTR [rdi+0x41]
 708:	48 c1 e6 08          	shl    rsi,0x8
 70c:	48 0f b6 57 40       	movzx  rdx,BYTE PTR [rdi+0x40]
 711:	48 09 d6             	or     rsi,rdx
 714:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 71b:	48 81 fe 1f 90 00 00 	cmp    rsi,0x901f
 722:	0f 85 f8 fd ff ff    	jne    0x520
 728:	41 b8 01 00 00 00    	mov    r8d,0x1
 72e:	41 be 01 00 00 00    	mov    r14d,0x1
 734:	48 81 f9 ea 05 00 00 	cmp    rcx,0x5ea
 73b:	0f 8f df fd ff ff    	jg     0x520
 741:	48 8b 55 f0          	mov    rdx,QWORD PTR [rbp-0x10]
 745:	48 c1 e2 08          	shl    rdx,0x8
 749:	48 8b b5 58 ff ff ff 	mov    rsi,QWORD PTR [rbp-0xa8]
 750:	48 09 f2             	or     rdx,rsi
 753:	4c 8b b5 78 ff ff ff 	mov    r14,QWORD PTR [rbp-0x88]
 75a:	49 c1 e6 04          	shl    r14,0x4
 75e:	48 8b b5 60 ff ff ff 	mov    rsi,QWORD PTR [rbp-0xa0]
 765:	48 c1 ee 04          	shr    rsi,0x4
 769:	48 83 e6 0f          	and    rsi,0xf
 76d:	49 09 f6             	or     r14,rsi
 770:	4c 8b 7d a8          	mov    r15,QWORD PTR [rbp-0x58]
 774:	49 c1 e7 08          	shl    r15,0x8
 778:	48 8b b5 68 ff ff ff 	mov    rsi,QWORD PTR [rbp-0x98]
 77f:	49 09 f7             	or     r15,rsi
 782:	48 8b 5d 98          	mov    rbx,QWORD PTR [rbp-0x68]
 786:	48 c1 e3 08          	shl    rbx,0x8
 78a:	48 8b b5 70 ff ff ff 	mov    rsi,QWORD PTR [rbp-0x90]
 791:	48 09 f3             	or     rbx,rsi
 794:	48 8b 75 b8          	mov    rsi,QWORD PTR [rbp-0x48]
 798:	48 c1 e6 10          	shl    rsi,0x10
 79c:	48 89 75 b8          	mov    QWORD PTR [rbp-0x48],rsi
 7a0:	48 8b 75 c0          	mov    rsi,QWORD PTR [rbp-0x40]
 7a4:	48 c1 e6 10          	shl    rsi,0x10
 7a8:	48 89 75 c0          	mov    QWORD PTR [rbp-0x40],rsi
 7ac:	4c 8b 45 a0          	mov    r8,QWORD PTR [rbp-0x60]
 7b0:	49 c1 e0 08          	shl    r8,0x8
 7b4:	48 8b 4d c8          	mov    rcx,QWORD PTR [rbp-0x38]
 7b8:	48 c1 e1 10          	shl    rcx,0x10
 7bc:	48 8b 45 d0          	mov    rax,QWORD PTR [rbp-0x30]
 7c0:	48 c1 e0 18          	shl    rax,0x18
 7c4:	48 0f b6 77 3e       	movzx  rsi,BYTE PTR [rdi+0x3e]
 7c9:	4c 0f b6 6f 3f       	movzx  r13,BYTE PTR [rdi+0x3f]
 7ce:	49 c1 e5 08          	shl    r13,0x8
 7d2:	49 09 f5             	or     r13,rsi
 7d5:	48 89 4d c8          	mov    QWORD PTR [rbp-0x38],rcx
 7d9:	48 89 ce             	mov    rsi,rcx
 7dc:	48 89 45 d0          	mov    QWORD PTR [rbp-0x30],rax
 7e0:	48 09 c6             	or     rsi,rax
 7e3:	4c 89 6d a8          	mov    QWORD PTR [rbp-0x58],r13
 7e7:	41 0f cd             	bswap  r13d
 7ea:	b9 00 00 ff ff       	mov    ecx,0xffff0000
 7ef:	49 21 cd             	and    r13,rcx
 7f2:	49 31 f5             	xor    r13,rsi
 7f5:	49 81 e6 ff 00 00 00 	and    r14,0xff
 7fc:	48 89 55 f0          	mov    QWORD PTR [rbp-0x10],rdx
 800:	48 8d 72 14          	lea    rsi,[rdx+0x14]
 804:	66 c1 ce 08          	ror    si,0x8
 808:	0f b7 f6             	movzx  esi,si
 80b:	4c 01 f6             	add    rsi,r14
 80e:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 812:	4c 89 ea             	mov    rdx,r13
 815:	48 21 ca             	and    rdx,rcx
 818:	48 c1 ea 10          	shr    rdx,0x10
 81c:	48 01 d6             	add    rsi,rdx
 81f:	48 81 c6 3b df 00 00 	add    rsi,0xdf3b
 826:	41 be 00 00 01 00    	mov    r14d,0x10000
 82c:	49 39 f6             	cmp    r14,rsi
 82f:	77 11                	ja     0x842
 831:	48 89 f1             	mov    rcx,rsi
 834:	48 c1 e9 10          	shr    rcx,0x10
 838:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 83f:	48 01 ce             	add    rsi,rcx
 842:	48 8b 55 b8          	mov    rdx,QWORD PTR [rbp-0x48]
 846:	48 09 d3             	or     rbx,rdx
 849:	48 8b 55 c0          	mov    rdx,QWORD PTR [rbp-0x40]
 84d:	49 09 d7             	or     r15,rdx
 850:	48 8b 55 80          	mov    rdx,QWORD PTR [rbp-0x80]
 854:	49 09 d0             	or     r8,rdx
 857:	48 8b 55 88          	mov    rdx,QWORD PTR [rbp-0x78]
 85b:	48 c1 e2 18          	shl    rdx,0x18
 85f:	4c 8b 6d 90          	mov    r13,QWORD PTR [rbp-0x70]
 863:	49 c1 e5 18          	shl    r13,0x18
 867:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 86b:	49 39 f6             	cmp    r14,rsi
 86e:	77 11                	ja     0x881
 870:	48 89 f1             	mov    rcx,rsi
 873:	48 c1 e9 10          	shr    rcx,0x10
 877:	48 81 e6 ff ff 00 00 	and    rsi,0xffff
 87e:	48 01 ce             	add    rsi,rcx
 881:	49 09 d7             	or     r15,rdx
 884:	4c 09 eb             	or     rbx,r13
 887:	48 8b 55 c8          	mov    rdx,QWORD PTR [rbp-0x38]
 88b:	49 09 d0             	or     r8,rdx
 88e:	41 bd 00 00 01 00    	mov    r13d,0x10000
 894:	48 8b 4d e0          	mov    rcx,QWORD PTR [rbp-0x20]
 898:	48 c1 e1 08          	shl    rcx,0x8
 89c:	48 89 4d e0          	mov    QWORD PTR [rbp-0x20],rcx
 8a0:	48 8b 4d d8          	mov    rcx,QWORD PTR [rbp-0x28]
 8a4:	48 c1 e1 10          	shl    rcx,0x10
 8a8:	48 89 4d d8          	mov    QWORD PTR [rbp-0x28],rcx
 8ac:	48 c1 e0 18          	shl    rax,0x18
 8b0:	48 89 45 e8          	mov    QWORD PTR [rbp-0x18],rax
 8b4:	48 8b 55 d0          	mov    rdx,QWORD PTR [rbp-0x30]
 8b8:	49 09 d0             	or     r8,rdx
 8bb:	4c 8d b3 ff c0 ad de 	lea    r14,[rbx-0x21523f01]
 8c2:	49 81 c7 ff c0 ad de 	add    r15,0xffffffffdeadc0ff
 8c9:	4c 89 c1             	mov    rcx,r8
 8cc:	48 c1 e1 20          	shl    rcx,0x20
 8d0:	48 c1 e9 20          	shr    rcx,0x20
 8d4:	48 ba 15 7c 4a 7f b9 	movabs rdx,0x9e3779b97f4a7c15
 8db:	79 37 9e 
 8de:	48 01 d1             	add    rcx,rdx
 8e1:	48 89 c8             	mov    rax,rcx
 8e4:	48 c1 e8 02          	shr    rax,0x2
 8e8:	48 89 ca             	mov    rdx,rcx
 8eb:	48 c1 e2 06          	shl    rdx,0x6
 8ef:	48 01 c2             	add    rdx,rax
 8f2:	48 b8 1f e0 4b 80 b9 	movabs rax,0x9e3779b9804be01f
 8f9:	79 37 9e 
 8fc:	48 01 c2             	add    rdx,rax
 8ff:	49 29 d8             	sub    r8,rbx
 902:	bb 00 00 00 f0       	mov    ebx,0xf0000000
 907:	4c 89 f0             	mov    rax,r14
 90a:	48 21 d8             	and    rax,rbx
 90d:	48 c1 e8 1c          	shr    rax,0x1c
 911:	4c 89 f3             	mov    rbx,r14
 914:	48 c1 e3 04          	shl    rbx,0x4
 918:	48 09 c3             	or     rbx,rax
 91b:	48 31 ca             	xor    rdx,rcx
 91e:	49 31 d8             	xor    r8,rbx
 921:	b9 00 00 00 fc       	mov    ecx,0xfc000000
 926:	4c 89 c0             	mov    rax,r8
 929:	48 21 c8             	and    rax,rcx
 92c:	48 c1 e8 1a          	shr    rax,0x1a
 930:	4c 89 c1             	mov    rcx,r8
 933:	48 c1 e1 06          	shl    rcx,0x6
 937:	48 09 c1             	or     rcx,rax
 93a:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
 93e:	48 25 ff ff 00 00    	and    rax,0xffff
 944:	48 89 d3             	mov    rbx,rdx
 947:	48 c1 e3 06          	shl    rbx,0x6
 94b:	48 01 c3             	add    rbx,rax
 94e:	49 89 c5             	mov    r13,rax
 951:	48 89 d0             	mov    rax,rdx
 954:	48 c1 e8 02          	shr    rax,0x2
 958:	48 01 c3             	add    rbx,rax
 95b:	4d 01 fe             	add    r14,r15
 95e:	4d 29 c7             	sub    r15,r8
 961:	49 31 cf             	xor    r15,rcx
 964:	b9 00 00 00 ff       	mov    ecx,0xff000000
 969:	4c 89 f8             	mov    rax,r15
 96c:	48 21 c8             	and    rax,rcx
 96f:	48 c1 e8 18          	shr    rax,0x18
 973:	4c 89 f9             	mov    rcx,r15
 976:	48 c1 e1 08          	shl    rcx,0x8
 97a:	48 09 c1             	or     rcx,rax
 97d:	48 b8 15 7c 69 0f ba 	movabs rax,0x9e3779ba0f697c15
 984:	79 37 9e 
 987:	48 01 c3             	add    rbx,rax
 98a:	48 89 5d d0          	mov    QWORD PTR [rbp-0x30],rbx
 98e:	49 8d 85 f7 c0 cc 70 	lea    rax,[r13+0x70ccc0f7]
 995:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
 999:	49 89 c5             	mov    r13,rax
 99c:	49 c1 e5 0e          	shl    r13,0xe
 9a0:	49 81 cd 33 1c 00 00 	or     r13,0x1c33
 9a7:	48 35 f7 c0 ad e0    	xor    rax,0xffffffffe0adc0f7
 9ad:	4c 29 e8             	sub    rax,r13
 9b0:	48 89 c3             	mov    rbx,rax
 9b3:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 9b7:	49 c1 e5 20          	shl    r13,0x20
 9bb:	48 b8 0a c8 00 02 ac 	movabs rax,0x10ac0200c80a
 9c2:	10 00 00 
 9c5:	49 09 c5             	or     r13,rax
 9c8:	4c 89 6d f8          	mov    QWORD PTR [rbp-0x8],r13
 9cc:	4d 01 f0             	add    r8,r14
 9cf:	4d 29 fe             	sub    r14,r15
 9d2:	49 31 ce             	xor    r14,rcx
 9d5:	4c 89 f1             	mov    rcx,r14
 9d8:	b8 00 00 ff ff       	mov    eax,0xffff0000
 9dd:	48 21 c1             	and    rcx,rax
 9e0:	48 c1 e9 10          	shr    rcx,0x10
 9e4:	4c 89 f0             	mov    rax,r14
 9e7:	48 c1 e0 10          	shl    rax,0x10
 9eb:	48 09 c8             	or     rax,rcx
 9ee:	48 8b 4d d0          	mov    rcx,QWORD PTR [rbp-0x30]
 9f2:	48 31 d1             	xor    rcx,rdx
 9f5:	48 89 4d d0          	mov    QWORD PTR [rbp-0x30],rcx
 9f9:	ba 00 00 e0 ff       	mov    edx,0xffe00000
 9fe:	48 89 5d c8          	mov    QWORD PTR [rbp-0x38],rbx
 a02:	48 89 d9             	mov    rcx,rbx
 a05:	48 21 d1             	and    rcx,rdx
 a08:	48 c1 e9 15          	shr    rcx,0x15
 a0c:	48 89 da             	mov    rdx,rbx
 a0f:	48 c1 e2 0b          	shl    rdx,0xb
 a13:	48 09 ca             	or     rdx,rcx
 a16:	48 89 55 c0          	mov    QWORD PTR [rbp-0x40],rdx
 a1a:	4d 01 c7             	add    r15,r8
 a1d:	4d 29 f0             	sub    r8,r14
 a20:	49 31 c0             	xor    r8,rax
 a23:	b9 00 e0 ff ff       	mov    ecx,0xffffe000
 a28:	4c 89 c0             	mov    rax,r8
 a2b:	48 21 c8             	and    rax,rcx
 a2e:	48 c1 e8 0d          	shr    rax,0xd
 a32:	4c 89 c1             	mov    rcx,r8
 a35:	48 c1 e1 13          	shl    rcx,0x13
 a39:	48 09 c1             	or     rcx,rax
 a3c:	4d 01 fe             	add    r14,r15
 a3f:	4d 29 c7             	sub    r15,r8
 a42:	49 31 cf             	xor    r15,rcx
 a45:	48 8b 5d d0          	mov    rbx,QWORD PTR [rbp-0x30]
 a49:	48 89 d9             	mov    rcx,rbx
 a4c:	48 c1 e9 02          	shr    rcx,0x2
 a50:	48 c1 e3 06          	shl    rbx,0x6
 a54:	48 01 cb             	add    rbx,rcx
 a57:	4d 01 f0             	add    r8,r14
 a5a:	48 8b 45 e8          	mov    rax,QWORD PTR [rbp-0x18]
 a5e:	4c 01 c0             	add    rax,r8
 a61:	4b 8d 0c 07          	lea    rcx,[r15+r8*1]
 a65:	41 b8 00 00 fc ff    	mov    r8d,0xfffc0000
 a6b:	49 89 cd             	mov    r13,rcx
 a6e:	4d 21 c5             	and    r13,r8
 a71:	49 c1 ed 12          	shr    r13,0x12
 a75:	49 89 c0             	mov    r8,rax
 a78:	4c 89 f8             	mov    rax,r15
 a7b:	49 89 cf             	mov    r15,rcx
 a7e:	49 c1 e7 0e          	shl    r15,0xe
 a82:	4d 09 ef             	or     r15,r13
 a85:	49 89 c5             	mov    r13,rax
 a88:	ba 00 00 00 f0       	mov    edx,0xf0000000
 a8d:	49 21 d5             	and    r13,rdx
 a90:	49 c1 ed 1c          	shr    r13,0x1c
 a94:	49 29 c6             	sub    r14,rax
 a97:	48 c1 e0 04          	shl    rax,0x4
 a9b:	4c 09 e8             	or     rax,r13
 a9e:	49 31 c6             	xor    r14,rax
 aa1:	49 31 ce             	xor    r14,rcx
 aa4:	4d 29 fe             	sub    r14,r15
 aa7:	4d 89 f5             	mov    r13,r14
 aaa:	ba 00 00 e0 ff       	mov    edx,0xffe00000
 aaf:	49 21 d5             	and    r13,rdx
 ab2:	49 c1 ed 15          	shr    r13,0x15
 ab6:	4c 89 f2             	mov    rdx,r14
 ab9:	48 c1 e2 0b          	shl    rdx,0xb
 abd:	4c 09 ea             	or     rdx,r13
 ac0:	48 c1 e6 10          	shl    rsi,0x10
 ac4:	48 c1 e6 20          	shl    rsi,0x20
 ac8:	48 c1 ee 20          	shr    rsi,0x20
 acc:	4c 8b 6d f8          	mov    r13,QWORD PTR [rbp-0x8]
 ad0:	49 31 f5             	xor    r13,rsi
 ad3:	48 8b 75 d8          	mov    rsi,QWORD PTR [rbp-0x28]
 ad7:	49 01 f0             	add    r8,rsi
 ada:	48 8b 75 e0          	mov    rsi,QWORD PTR [rbp-0x20]
 ade:	49 01 f0             	add    r8,rsi
 ae1:	48 8b 75 b0          	mov    rsi,QWORD PTR [rbp-0x50]
 ae5:	49 01 f0             	add    r8,rsi
 ae8:	4d 31 f0             	xor    r8,r14
 aeb:	49 29 d0             	sub    r8,rdx
 aee:	48 8b 45 f0          	mov    rax,QWORD PTR [rbp-0x10]
 af2:	48 25 ff ff 00 00    	and    rax,0xffff
 af8:	4c 89 ea             	mov    rdx,r13
 afb:	48 31 c2             	xor    rdx,rax
 afe:	48 be 0b 00 ff ff 00 	movabs rsi,0x200ffff000b
 b05:	02 00 00 
 b08:	48 31 f2             	xor    rdx,rsi
 b0b:	48 89 55 f8          	mov    QWORD PTR [rbp-0x8],rdx
 b0f:	ba 80 ff ff ff       	mov    edx,0xffffff80
 b14:	4c 89 c6             	mov    rsi,r8
 b17:	48 21 d6             	and    rsi,rdx
 b1a:	48 c1 ee 07          	shr    rsi,0x7
 b1e:	4c 89 c2             	mov    rdx,r8
 b21:	48 c1 e2 19          	shl    rdx,0x19
 b25:	48 09 f2             	or     rdx,rsi
 b28:	4d 89 c5             	mov    r13,r8
 b2b:	49 31 cd             	xor    r13,rcx
 b2e:	49 29 d5             	sub    r13,rdx
 b31:	4c 89 ee             	mov    rsi,r13
 b34:	41 bf 00 00 ff ff    	mov    r15d,0xffff0000
 b3a:	4c 21 fe             	and    rsi,r15
 b3d:	48 c1 ee 10          	shr    rsi,0x10
 b41:	4c 89 ea             	mov    rdx,r13
 b44:	48 c1 e2 10          	shl    rdx,0x10
 b48:	48 09 f2             	or     rdx,rsi
 b4b:	4c 89 ee             	mov    rsi,r13
 b4e:	4c 31 f6             	xor    rsi,r14
 b51:	48 29 d6             	sub    rsi,rdx
 b54:	48 89 f2             	mov    rdx,rsi
 b57:	41 be 00 00 00 f0    	mov    r14d,0xf0000000
 b5d:	4c 21 f2             	and    rdx,r14
 b60:	48 c1 ea 1c          	shr    rdx,0x1c
 b64:	48 89 f1             	mov    rcx,rsi
 b67:	48 c1 e1 04          	shl    rcx,0x4
 b6b:	48 09 d1             	or     rcx,rdx
 b6e:	48 89 f2             	mov    rdx,rsi
 b71:	4c 31 c2             	xor    rdx,r8
 b74:	48 29 ca             	sub    rdx,rcx
 b77:	48 89 d1             	mov    rcx,rdx
 b7a:	41 b8 00 00 fc ff    	mov    r8d,0xfffc0000
 b80:	4c 21 c1             	and    rcx,r8
 b83:	48 c1 e9 12          	shr    rcx,0x12
 b87:	49 89 d0             	mov    r8,rdx
 b8a:	49 c1 e0 0e          	shl    r8,0xe
 b8e:	49 09 c8             	or     r8,rcx
 b91:	4c 31 ea             	xor    rdx,r13
 b94:	4c 29 c2             	sub    rdx,r8
 b97:	b9 00 ff ff ff       	mov    ecx,0xffffff00
 b9c:	49 89 d0             	mov    r8,rdx
 b9f:	49 21 c8             	and    r8,rcx
 ba2:	49 c1 e8 08          	shr    r8,0x8
 ba6:	49 89 d5             	mov    r13,rdx
 ba9:	49 c1 e5 18          	shl    r13,0x18
 bad:	4d 09 c5             	or     r13,r8
 bb0:	48 31 f2             	xor    rdx,rsi
 bb3:	4c 29 ea             	sub    rdx,r13
 bb6:	48 81 c2 f7 c0 ad e0 	add    rdx,0xffffffffe0adc0f7
 bbd:	48 8b 4d c8          	mov    rcx,QWORD PTR [rbp-0x38]
 bc1:	48 31 ca             	xor    rdx,rcx
 bc4:	48 8b 75 c0          	mov    rsi,QWORD PTR [rbp-0x40]
 bc8:	48 29 f2             	sub    rdx,rsi
 bcb:	48 89 d6             	mov    rsi,rdx
 bce:	41 b8 80 ff ff ff    	mov    r8d,0xffffff80
 bd4:	4c 21 c6             	and    rsi,r8
 bd7:	48 c1 ee 07          	shr    rsi,0x7
 bdb:	49 89 d0             	mov    r8,rdx
 bde:	49 c1 e0 19          	shl    r8,0x19
 be2:	49 09 f0             	or     r8,rsi
 be5:	48 89 d6             	mov    rsi,rdx
 be8:	4c 8b 6d a8          	mov    r13,QWORD PTR [rbp-0x58]
 bec:	4c 31 ee             	xor    rsi,r13
 bef:	4c 29 c6             	sub    rsi,r8
 bf2:	49 89 f0             	mov    r8,rsi
 bf5:	4d 21 f8             	and    r8,r15
 bf8:	49 c1 e8 10          	shr    r8,0x10
 bfc:	49 89 f5             	mov    r13,rsi
 bff:	49 c1 e5 10          	shl    r13,0x10
 c03:	4d 09 c5             	or     r13,r8
 c06:	49 89 f0             	mov    r8,rsi
 c09:	49 31 c8             	xor    r8,rcx
 c0c:	4d 29 e8             	sub    r8,r13
 c0f:	4d 89 c5             	mov    r13,r8
 c12:	4d 21 f5             	and    r13,r14
 c15:	49 c1 ed 1c          	shr    r13,0x1c
 c19:	4d 89 c6             	mov    r14,r8
 c1c:	49 c1 e6 04          	shl    r14,0x4
 c20:	4d 09 ee             	or     r14,r13
 c23:	4d 89 c5             	mov    r13,r8
 c26:	49 31 d5             	xor    r13,rdx
 c29:	4d 29 f5             	sub    r13,r14
 c2c:	4c 89 ea             	mov    rdx,r13
 c2f:	b9 00 00 fc ff       	mov    ecx,0xfffc0000
 c34:	48 21 ca             	and    rdx,rcx
 c37:	48 c1 ea 12          	shr    rdx,0x12
 c3b:	4d 89 ee             	mov    r14,r13
 c3e:	49 c1 e6 0e          	shl    r14,0xe
 c42:	49 09 d6             	or     r14,rdx
 c45:	49 31 f5             	xor    r13,rsi
 c48:	4d 29 f5             	sub    r13,r14
 c4b:	4c 89 ee             	mov    rsi,r13
 c4e:	ba 00 ff ff ff       	mov    edx,0xffffff00
 c53:	48 21 d6             	and    rsi,rdx
 c56:	48 c1 ee 08          	shr    rsi,0x8
 c5a:	4c 89 ea             	mov    rdx,r13
 c5d:	48 c1 e2 18          	shl    rdx,0x18
 c61:	48 09 f2             	or     rdx,rsi
 c64:	4d 31 c5             	xor    r13,r8
 c67:	49 29 d5             	sub    r13,rdx
 c6a:	49 c1 e5 20          	shl    r13,0x20
 c6e:	49 c1 ed 20          	shr    r13,0x20
 c72:	50                   	push   rax
 c73:	52                   	push   rdx
 c74:	49 c7 c3 01 00 01 00 	mov    r11,0x10001
 c7b:	4c 89 e8             	mov    rax,r13
 c7e:	31 d2                	xor    edx,edx
 c80:	49 f7 f3             	div    r11
 c83:	49 89 d5             	mov    r13,rdx
 c86:	5a                   	pop    rdx
 c87:	58                   	pop    rax
 c88:	4c 01 eb             	add    rbx,r13
 c8b:	49 b8 15 7c 4a 7f b9 	movabs r8,0x9e3779b97f4a7c15
 c92:	79 37 9e 
 c95:	4c 01 c3             	add    rbx,r8
 c98:	48 8b 75 d0          	mov    rsi,QWORD PTR [rbp-0x30]
 c9c:	48 31 f3             	xor    rbx,rsi
 c9f:	48 89 de             	mov    rsi,rbx
 ca2:	48 c1 ee 02          	shr    rsi,0x2
 ca6:	48 89 da             	mov    rdx,rbx
 ca9:	48 c1 e2 06          	shl    rdx,0x6
 cad:	48 01 f2             	add    rdx,rsi
 cb0:	48 be 16 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c16
 cb7:	79 37 9e 
 cba:	48 01 f2             	add    rdx,rsi
 cbd:	48 31 da             	xor    rdx,rbx
 cc0:	48 89 d6             	mov    rsi,rdx
 cc3:	48 c1 ee 02          	shr    rsi,0x2
 cc7:	48 89 d1             	mov    rcx,rdx
 cca:	48 c1 e1 06          	shl    rcx,0x6
 cce:	48 01 f1             	add    rcx,rsi
 cd1:	4c 01 c1             	add    rcx,r8
 cd4:	48 31 d1             	xor    rcx,rdx
 cd7:	48 89 ce             	mov    rsi,rcx
 cda:	48 c1 e6 06          	shl    rsi,0x6
 cde:	48 01 f0             	add    rax,rsi
 ce1:	48 89 ce             	mov    rsi,rcx
 ce4:	48 c1 ee 02          	shr    rsi,0x2
 ce8:	48 01 f0             	add    rax,rsi
 ceb:	4c 01 c0             	add    rax,r8
 cee:	48 31 c8             	xor    rax,rcx
 cf1:	48 89 c6             	mov    rsi,rax
 cf4:	48 c1 ee 02          	shr    rsi,0x2
 cf8:	48 89 c2             	mov    rdx,rax
 cfb:	48 c1 e2 06          	shl    rdx,0x6
 cff:	48 01 f2             	add    rdx,rsi
 d02:	48 8b 75 f8          	mov    rsi,QWORD PTR [rbp-0x8]
 d06:	48 01 f2             	add    rdx,rsi
 d09:	4c 01 c2             	add    rdx,r8
 d0c:	48 31 c2             	xor    rdx,rax
 d0f:	48 89 d6             	mov    rsi,rdx
 d12:	48 c1 ee 02          	shr    rsi,0x2
 d16:	49 89 d0             	mov    r8,rdx
 d19:	49 c1 e0 06          	shl    r8,0x6
 d1d:	49 01 f0             	add    r8,rsi
 d20:	48 be 18 7c 4a 7f b9 	movabs rsi,0x9e3779b97f4a7c18
 d27:	79 37 9e 
 d2a:	49 01 f0             	add    r8,rsi
 d2d:	49 31 d0             	xor    r8,rdx
 d30:	41 be 03 00 00 00    	mov    r14d,0x3
 d36:	e9 e5 f7 ff ff       	jmp    0x520
 d3b:	41 b8 01 00 00 00    	mov    r8d,0x1
 d41:	48 8d 57 32          	lea    rdx,[rdi+0x32]
 d45:	41 be 01 00 00 00    	mov    r14d,0x1
 d4b:	48 39 f2             	cmp    rdx,rsi
 d4e:	0f 87 cc f7 ff ff    	ja     0x520
 d54:	41 b8 02 00 00 00    	mov    r8d,0x2
 d5a:	e9 bb f7 ff ff       	jmp    0x51a
```
