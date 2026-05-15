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
 * native asm to handcraft warnings: 293
 *
 * - 0x1100: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1101: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1103: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1105: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1107: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1109: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x110a: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0]
 * - 0x110d: mov    rbx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4]
 * - 0x1140: mov    r10,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r10,rbx]
 * - 0x1143: sub    r10,rsi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1163: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1178: cmp    dl,0x5 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    dl,0x5]
 * - 0x11ad: movzx  ebp,WORD PTR [rcx+0x18] [warning-unmapped: destination register ebp is not in the BPF JIT register file]
 * - 0x11b1: movzx  r11d,WORD PTR [rcx+0x22] [warning-unmapped: destination register r11d is not in the BPF JIT register file]
 * - 0x11d3: lea    r12,[rcx+0x3e] [warning-unmapped: LEA operands are not representable]
 * - 0x11d7: cmp    r12,rbx [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12,rbx]
 * - 0x11da: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [warning-unmapped: cannot lower cmp    r12,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to BPF branch]
 * - 0x11e9: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x11f8: movzx  r12d,BYTE PTR [rcx+0x1c] [warning-unmapped: destination register r12d is not in the BPF JIT register file]
 * - 0x11fd: cmp    r12d,0x2c [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x2c]
 * - 0x1201: je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [warning-unmapped: cannot lower cmp    r12d,0x2c + je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to BPF branch]
 * - 0x1207: cmp    r12d,0x3a [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x3a]
 * - 0x120b: jne    123d <katran_lb_consistent_hash_select_xdp+0x13d> [warning-unmapped: cannot lower cmp    r12d,0x3a + jne    123d <katran_lb_consistent_hash_select_xdp+0x13d> to BPF branch]
 * - 0x1214: add    r10,rax [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1217: mov    rdx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r10]
 * - 0x1221: mov    rsi,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rsi,r10]
 * - 0x122f: xor    rsi,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x1232: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x124e: mov    r11d,DWORD PTR [rcx+0x26] [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,DWORD PTR [rcx+0x26]]
 * - 0x1252: mov    ebp,DWORD PTR [rcx+0x2a] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [rcx+0x2a]]
 * - 0x1268: cmp    r12d,0x11 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x11]
 * - 0x126c: je     1288 <katran_lb_consistent_hash_select_xdp+0x188> [warning-unmapped: cannot lower cmp    r12d,0x11 + je     1288 <katran_lb_consistent_hash_select_xdp+0x188> to BPF branch]
 * - 0x126e: cmp    r12d,0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x6]
 * - 0x1272: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [warning-unmapped: cannot lower cmp    r12d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to BPF branch]
 * - 0x1274: mov    QWORD PTR [rsp-0x8],rdi [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x1288: mov    QWORD PTR [rsp-0x8],rdi [warning-unmapped: store base rsp is not in the BPF JIT register file]
 * - 0x129a: cmp    r12d,0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x6]
 * - 0x129e: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [warning-unmapped: cannot lower cmp    r12d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to BPF branch]
 * - 0x12ad: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12c4: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x12ca: cmp    r10,0x5ea [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10,0x5ea]
 * - 0x12d1: jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [warning-unmapped: cannot lower cmp    r10,0x5ea + jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to BPF branch]
 * - 0x12db: mov    r12d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,edx]
 * - 0x12de: shl    r12b,0x4 [warning-unmapped: ALU destination r12b is not in the BPF JIT register file]
 * - 0x12e2: or     r12b,r15b [warning-unmapped: ALU destination r12b is not in the BPF JIT register file]
 * - 0x12ee: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp]
 * - 0x12f6: lea    r9d,[r11-0x21523f01] [warning-unmapped: LEA base/index not in BPF register file: [r11-0x21523f01]]
 * - 0x12fd: mov    r10d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ebp]
 * - 0x1300: and    r10d,0xff0000 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1307: add    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x130a: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp]
 * - 0x1312: add    edi,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1315: movzx  ebx,bpl [warning-unmapped: movzx source size not recognized: bpl]
 * - 0x131b: mov    rdx,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file]
 * - 0x1322: sub    edi,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x1325: mov    r14d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x132f: add    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1335: mov    r10d,r14d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r14d]
 * - 0x1338: rol    r10d,0x6 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x133c: xor    r10d,r8d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x133f: add    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1342: lea    edi,[r10+r14*1] [warning-unmapped: LEA base/index not in BPF register file: [r10+r14*1]]
 * - 0x1346: sub    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1349: rol    r10d,0x8 [warning-unmapped: ROL width/register not supported by current selectors: r10d]
 * - 0x1352: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1355: sub    r14d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1358: mov    r11d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r10d]
 * - 0x135b: rol    r11d,0x10 [warning-unmapped: ROL width/register not supported by current selectors: r11d]
 * - 0x135f: xor    r11d,r14d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1362: add    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1365: sub    edi,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x1368: mov    r14d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r11d]
 * - 0x1372: add    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1375: lea    r9d,[r14+r11*1] [warning-unmapped: LEA base/index not in BPF register file: [r14+r11*1]]
 * - 0x1379: sub    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1380: add    r11d,ebx [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1383: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1386: xor    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1389: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x138f: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1392: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d]
 * - 0x1398: xor    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x139b: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x139e: xor    r9d,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x13a1: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d]
 * - 0x13a7: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13aa: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x13ad: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13b3: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x13b6: xor    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x13b9: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d]
 * - 0x13bf: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x13c2: xor    r9d,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x13c5: rol    r11d,0xe [warning-unmapped: ROL width/register not supported by current selectors: r11d]
 * - 0x13c9: sub    r9d,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x13cc: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13d2: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x13d5: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13d8: add    r9d,0xe0adc0f7 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x13df: mov    r11d,r8d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r8d]
 * - 0x13e2: add    r11d,0x70ccc0f7 [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x13e9: mov    r10d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r11d]
 * - 0x13ec: xor    r10d,0xe0adc0f7 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x13f8: shrd   edi,r11d,0x12 [warning-unmapped: SHRD operands are not in the BPF JIT register file: shrd   edi,r11d,0x12]
 * - 0x13fd: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1400: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1403: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d]
 * - 0x1409: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x140c: xor    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x140f: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1415: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1418: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d]
 * - 0x141e: xor    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1421: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1424: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported]
 * - 0x1427: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d]
 * - 0x142d: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1430: xor    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1433: rol    r9d,0xe [warning-reg-remap: roll imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1437: sub    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x143a: xor    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x143d: rol    r11d,0x18 [warning-unmapped: ROL width/register not supported by current selectors: r11d]
 * - 0x1441: sub    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1449: imul   rdi,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rdi,r10]
 * - 0x1451: mov    r9d,edi [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1454: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1458: or     r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x145b: sub    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1464: mov    r9,rdi [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1467: shl    r9,0x6 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x146b: add    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x146e: mov    r11,rdi [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rdi]
 * - 0x1471: shr    r11,0x2 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1475: add    r9,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1478: add    r9,0x101640a [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x147f: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1482: mov    r11,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r9]
 * - 0x1485: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1489: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x148c: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x148f: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x149e: add    rbx,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x14a1: xor    rbx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14ab: mov    r9,rbx [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14ae: shr    r9,0x2 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14b5: add    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14b8: add    rdi,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x14be: mov    r9,rdi [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14c1: shl    r9,0x6 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14c5: add    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14c8: mov    r10,rdi [warning-unmapped: unsupported mnemonic or operand form: mov    r10,rdi]
 * - 0x14cb: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x14cf: add    r9,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x14d2: inc    r9 [warning-reg-remap: incq reg kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14d5: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14d8: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x14e2: mov    r10,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r9]
 * - 0x14e5: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x14e9: add    r10,rdi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x14ec: xor    r10,r9 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x14ef: mov    r11,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r10]
 * - 0x14f2: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x14f6: add    r11,rsi [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x14f9: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x14fc: mov    r9,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r9,r10]
 * - 0x14ff: shr    r9,0x2 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1503: add    r9,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1521: movzx  r8d,r12b [warning-unmapped: movzx source size not recognized: r12b]
 * - 0x1528: mov    r11d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,edx]
 * - 0x152b: shr    r11d,0x10 [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1532: add    rdi,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1543: movzx  r11d,di [warning-unmapped: movzx source size not recognized: di]
 * - 0x1547: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1551: cmovb  r11,rdi [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1555: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d]
 * - 0x155b: movzx  r8d,r11w [warning-unmapped: movzx source size not recognized: r11w]
 * - 0x1562: cmp    r11,0x10000 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r11,0x10000]
 * - 0x1569: cmovb  r8,r11 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1573: movzx  r11d,r8w [warning-unmapped: movzx source size not recognized: r8w]
 * - 0x1577: add    r11,rdi [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1581: cmovb  r11,r8 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1585: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d]
 * - 0x158b: add    edi,r11d [warning-unmapped: ALU source r11d is not supported]
 * - 0x158e: xor    r9,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x15a2: cmp    r11,0x10000 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r11,0x10000]
 * - 0x15a9: cmovb  edi,r11d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x15c3: mov    rdx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x15ca: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x15da: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x15e2: lea    r12,[rcx+0x32] [warning-unmapped: LEA operands are not representable]
 * - 0x15e6: cmp    r12,rbx [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12,rbx]
 * - 0x15e9: jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d> [warning-unmapped: cannot lower cmp    r12,rbx + jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d> to BPF branch]
 * - 0x15fe: add    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1612: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1613: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1615: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1617: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x1619: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x161b: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR]
 * - 0x162a: movzx  r9d,WORD PTR [rcx+0x2c] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x163c: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1642: cmp    r14b,0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r14b,0x6]
 * - 0x164d: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1653: cmp    r10,0x5ea [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10,0x5ea]
 * - 0x165a: jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [warning-unmapped: cannot lower cmp    r10,0x5ea + jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to BPF branch]
 * - 0x165c: rol    bp,0x8 [warning-unmapped: ROL width/register not supported by current selectors: bp]
 * - 0x1660: movzx  esi,bp [warning-unmapped: movzx source size not recognized: bp]
 * - 0x166a: or     r11d,r8d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x166d: or     r11d,edx [warning-unmapped: ALU destination r11d is not in the BPF JIT register file]
 * - 0x1670: movzx  r9d,WORD PTR [rcx+0x2a] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1675: mov    ebx,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x167e: mov    r10d,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ebx]
 * - 0x1681: xor    r10d,0xe0adc0f7 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1688: mov    ebp,0x70cc0000 [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,0x70cc0000]
 * - 0x168d: shrd   ebp,ebx,0x12 [warning-unmapped: SHRD operands are not in the BPF JIT register file: shrd   ebp,ebx,0x12]
 * - 0x1691: sub    r10d,ebp [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x1694: lea    ebp,[r11-0x1f523f09] [warning-unmapped: LEA operands are not representable]
 * - 0x169b: xor    ebp,r10d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x169e: mov    r14d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r10d]
 * - 0x16a5: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16a8: mov    r14d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,ebp]
 * - 0x16af: xor    ebx,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x16b4: xor    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16be: sub    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16c1: xor    ebp,r10d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16c4: mov    r14d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r10d]
 * - 0x16cb: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16ce: xor    ebx,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x16d0: rol    ebp,0xe [warning-unmapped: ROL width/register not supported by current selectors: ebp]
 * - 0x16d3: sub    ebx,ebp [warning-unmapped: ALU source ebp is not supported]
 * - 0x16d5: xor    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16db: sub    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16e3: imul   rbx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rbx,r10]
 * - 0x16eb: mov    ebp,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,ebx]
 * - 0x16ed: shl    ebp,0x10 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16f0: or     ebp,ebx [warning-unmapped: ALU destination ebp is not in the BPF JIT register file]
 * - 0x16f2: sub    r10d,ebp [warning-unmapped: ALU destination r10d is not in the BPF JIT register file]
 * - 0x16f5: mov    r11d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r11d]
 * - 0x16f8: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x16fb: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11]
 * - 0x1702: mov    r14,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r14,r11]
 * - 0x1716: xor    rbx,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x1719: mov    r11,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rbx]
 * - 0x171c: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1727: add    r14,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x172a: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x172d: add    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1736: add    r14,r11 [warning-unmapped: ALU source r11 is not supported]
 * - 0x173c: mov    r11,r14 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r14]
 * - 0x173f: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x174a: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x174d: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1750: add    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1753: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1756: mov    r10,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r11]
 * - 0x1759: shl    r10,0x6 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x175d: add    r10,rax [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1760: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11]
 * - 0x1767: add    r10,rbx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x176a: inc    r10 [warning-unmapped: INC destination r10 is not in the BPF JIT register file]
 * - 0x176d: xor    r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x1770: mov    rbx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r10]
 * - 0x177a: mov    r11,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r10]
 * - 0x177d: shr    r11,0x2 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1781: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1784: xor    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file]
 * - 0x1787: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11]
 * - 0x1794: mov    r10,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r11]
 * - 0x1797: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x179b: rol    r9w,0x8 [warning-reg-remap: rolw imm8 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17a0: add    r10,rbx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x17a3: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17aa: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17bd: mov    r9d,edx [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17c0: shr    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17c7: lea    rdi,[r9+r8*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17d9: movzx  r9d,di [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17dd: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17e7: cmovb  r9,rdi [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x17eb: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17f1: movzx  r8d,r9w [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x17ff: cmovb  r8,r9 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1809: movzx  r9d,r8w [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x180d: add    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1817: cmovb  r9,r8 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x181b: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1821: add    edi,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 * - 0x1824: xor    r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file]
 * - 0x183f: cmovb  edi,r9d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof]
 * - 0x1859: mov    rdx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r10]
 * - 0x1860: mov    rdi,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdi,r10]
 * - 0x1870: xor    rdx,r10 [warning-unmapped: ALU source r10 is not supported]
 * - 0x188e: mov    r9d,0x3 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15]
 */

static const struct bpf_insn program[] = {
    /* 0x1100: push   rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1101: push   r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1103: push   r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1105: push   r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1107: push   r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1109: push   rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x110a: mov    rcx,QWORD PTR [rdi] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 0; BPF XDP ctx uses u32 field at off 0] */
    HC_LDX(BPF_W, BPF_REG_4, BPF_REG_1, 0),
    /* 0x110d: mov    rbx,QWORD PTR [rdi+0x8] [warning-context-abi: native xdp_md uses 64-bit host pointer field at off 8; BPF XDP ctx uses u32 field at off 4] */
    HC_LDX(BPF_W, BPF_REG_6, BPF_REG_1, 4),
    /* 0x1111: xor    eax,eax [bpf-jit: zero idiom] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 0),
    /* 0x1113: cmp    rcx,rbx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1116: ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> [bpf-branch: lowered cmp    rcx,rbx + ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_4, BPF_REG_6, 275),
    /* 0x111c: lea    rsi,[rcx+0x8] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 8), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1120: cmp    rsi,rbx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1123: ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> [bpf-branch: lowered cmp    rsi,rbx + ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_6, 270),
    /* 0x1129: lea    rdx,[rcx+0x16] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_4, 0, 0, 1, 0, 22), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x112d: cmp    rdx,rbx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1130: ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> [bpf-branch: lowered cmp    rdx,rbx + ja     1612 <katran_lb_consistent_hash_select_xdp+0x512> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_6, 265),
    /* 0x1136: movabs rax,0x9e3779b97f4a7c15 [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_0, 0, 0x9e3779b97f4a7c15ULL),
    /* 0x1140: mov    r10,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r10,rbx] */
    /* 0x1143: sub    r10,rsi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1146: movzx  esi,WORD PTR [rcx+0x14] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 20), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x114a: cmp    esi,0xdd86 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 56710), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1150: je     11e5 <katran_lb_consistent_hash_select_xdp+0xe5> [bpf-branch: lowered cmp    esi,0xdd86 + je     11e5 <katran_lb_consistent_hash_select_xdp+0xe5> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_2, 0, 43, 56710),
    /* 0x1156: cmp    esi,0x8 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 8), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1159: jne    1214 <katran_lb_consistent_hash_select_xdp+0x114> [bpf-branch: lowered cmp    esi,0x8 + jne    1214 <katran_lb_consistent_hash_select_xdp+0x114> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_2, 0, 48, 8),
    /* 0x115f: lea    rsi,[rcx+0x2a] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_2, BPF_REG_4, 0, 0, 1, 0, 42), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1163: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x1169: cmp    rsi,rbx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x116c: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    rsi,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_2, BPF_REG_6, 234),
    /* 0x1172: movzx  edx,BYTE PTR [rdx] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_3, 0), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1175: and    dl,0xf [exact-kinsn: andb imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_REG_IMM_TMP_PAYLOAD(BPF_REG_3, 15, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ANDB_IMM),
    /* 0x1178: cmp    dl,0x5 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    dl,0x5] */
    /* 0x117b: jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    dl,0x5 + jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_3, 0, 229, 5),
    /* 0x1181: movzx  edx,BYTE PTR [rcx+0x1c] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 28), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1185: movzx  esi,BYTE PTR [rcx+0x1d] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_2, BPF_REG_4, 29), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1189: and    edx,0x3f [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 63), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x118c: or     dx,si [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x118f: jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered flags from or     dx,si + jne    15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible zero branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_3, 0, 221, 0),
    /* 0x1195: movzx  r14d,BYTE PTR [rcx+0x1f] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_4, 31), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x119a: mov    esi,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x119f: cmp    r14d,0x1 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 1), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11a3: je     1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r14d,0x1 + je     1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_8, 0, 29, 1),
    /* 0x11a9: movzx  edi,BYTE PTR [rcx+0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11ad: movzx  ebp,WORD PTR [rcx+0x18] [warning-unmapped: destination register ebp is not in the BPF JIT register file] */
    /* 0x11b1: movzx  r11d,WORD PTR [rcx+0x22] [warning-unmapped: destination register r11d is not in the BPF JIT register file] */
    /* 0x11b6: movzx  r8d,BYTE PTR [rcx+0x24] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 36), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11bb: movzx  edx,BYTE PTR [rcx+0x25] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 37), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x11bf: mov    r15d,DWORD PTR [rcx+0x26] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 38), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x11c3: cmp    r14d,0x11 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 17), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11c7: je     15e2 <katran_lb_consistent_hash_select_xdp+0x4e2> [bpf-branch: lowered cmp    r14d,0x11 + je     15e2 <katran_lb_consistent_hash_select_xdp+0x4e2> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JEQ | BPF_K, BPF_REG_8, 0, 204, 17),
    /* 0x11cd: cmp    r14d,0x6 [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 6), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x11d1: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r14d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_8, 0, 15, 6),
    /* 0x11d3: lea    r12,[rcx+0x3e] [warning-unmapped: LEA operands are not representable] */
    /* 0x11d7: cmp    r12,rbx [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12,rbx] */
    /* 0x11da: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [warning-unmapped: cannot lower cmp    r12,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to BPF branch] */
    /* 0x11e0: jmp    161d <katran_lb_consistent_hash_select_xdp+0x51d> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 216, 0),
    /* 0x11e5: lea    rdx,[rcx+0x3e] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_3, BPF_REG_4, 0, 0, 1, 0, 62), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x11e9: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x11ef: cmp    rdx,rbx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x11f2: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    rdx,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_3, BPF_REG_6, 194),
    /* 0x11f8: movzx  r12d,BYTE PTR [rcx+0x1c] [warning-unmapped: destination register r12d is not in the BPF JIT register file] */
    /* 0x11fd: cmp    r12d,0x2c [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x2c] */
    /* 0x1201: je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [warning-unmapped: cannot lower cmp    r12d,0x2c + je     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to BPF branch] */
    /* 0x1207: cmp    r12d,0x3a [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x3a] */
    /* 0x120b: jne    123d <katran_lb_consistent_hash_select_xdp+0x13d> [warning-unmapped: cannot lower cmp    r12d,0x3a + jne    123d <katran_lb_consistent_hash_select_xdp+0x13d> to BPF branch] */
    /* 0x120d: mov    esi,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x1212: jmp    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 6, 0),
    /* 0x1214: add    r10,rax [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1217: mov    rdx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r10] */
    /* 0x121a: shl    rdx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 6),
    /* 0x121e: add    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1221: mov    rsi,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rsi,r10] */
    /* 0x1224: shr    rsi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_2, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1228: add    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x122b: add    rsi,0x2 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x122f: xor    rsi,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1232: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 2),
    /* 0x1238: jmp    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 185, 0),
    /* 0x123d: movzx  edx,BYTE PTR [rcx+0x16] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 22), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1241: movzx  r15d,BYTE PTR [rcx+0x17] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 23), MICRO_HANDCRAFT_BPF_X86_MOVZBL_MEM),
    /* 0x1246: movzx  r14d,WORD PTR [rcx+0x1a] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_8, BPF_REG_4, 26), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x124b: mov    edi,DWORD PTR [rcx+0x1e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 30), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x124e: mov    r11d,DWORD PTR [rcx+0x26] [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,DWORD PTR [rcx+0x26]] */
    /* 0x1252: mov    ebp,DWORD PTR [rcx+0x2a] [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,DWORD PTR [rcx+0x2a]] */
    /* 0x1255: mov    r13d,DWORD PTR [rcx+0x2e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_7, BPF_REG_4, 46), MICRO_HANDCRAFT_BPF_X86_MOVL_MEM),
    /* 0x1259: mov    r8d,0xdeadc0ff [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_5, 0, 0, 3735929087),
    /* 0x125f: add    r8d,DWORD PTR [rcx+0x22] [exact-kinsn: addl memory-source kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ALU_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 34, BPF_REG_6, 0), MICRO_HANDCRAFT_BPF_X86_ADDL_MEM),
    /* 0x1263: mov    esi,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 2),
    /* 0x1268: cmp    r12d,0x11 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x11] */
    /* 0x126c: je     1288 <katran_lb_consistent_hash_select_xdp+0x188> [warning-unmapped: cannot lower cmp    r12d,0x11 + je     1288 <katran_lb_consistent_hash_select_xdp+0x188> to BPF branch] */
    /* 0x126e: cmp    r12d,0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x6] */
    /* 0x1272: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [warning-unmapped: cannot lower cmp    r12d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to BPF branch] */
    /* 0x1274: mov    QWORD PTR [rsp-0x8],rdi [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x1279: lea    rdi,[rcx+0x52] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 82), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x127d: cmp    rdi,rbx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1280: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    rdi,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_6, 165),
    /* 0x1286: jmp    129a <katran_lb_consistent_hash_select_xdp+0x19a> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 5, 0),
    /* 0x1288: mov    QWORD PTR [rsp-0x8],rdi [warning-unmapped: store base rsp is not in the BPF JIT register file] */
    /* 0x128d: lea    rdi,[rcx+0x46] [exact-kinsn: LEA via x86 kinsn selector] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_4, 0, 0, 1, 0, 70), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x1291: cmp    rdi,rbx [exact-kinsn: cmpq reg,reg kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_CMPQ_RR),
    /* 0x1294: ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> [bpf-branch: lowered cmp    rdi,rbx + ja     15eb <katran_lb_consistent_hash_select_xdp+0x4eb> to verifier-visible BPF branch] */
    HC_JMP_REG(BPF_JGT, BPF_REG_1, BPF_REG_6, 159),
    /* 0x129a: cmp    r12d,0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12d,0x6] */
    /* 0x129e: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [warning-unmapped: cannot lower cmp    r12d,0x6 + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to BPF branch] */
    /* 0x12a0: cmp    r13d,0x101640a [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_7, 16868362), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x12a7: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r13d,0x101640a + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_7, 0, -30, 16868362),
    /* 0x12a9: movzx  edi,WORD PTR [rcx+0x40] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_1, BPF_REG_4, 64), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x12ad: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 2),
    /* 0x12b3: cmp    edi,0x901f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 36895), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x12b9: jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [bpf-branch: lowered cmp    edi,0x901f + jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_1, 0, 151, 36895),
    /* 0x12bf: mov    esi,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 1),
    /* 0x12c4: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x12ca: cmp    r10,0x5ea [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10,0x5ea] */
    /* 0x12d1: jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [warning-unmapped: cannot lower cmp    r10,0x5ea + jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to BPF branch] */
    /* 0x12d7: shr    r15b,0x4 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_9, 0, 0, 4),
    /* 0x12db: mov    r12d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r12d,edx] */
    /* 0x12de: shl    r12b,0x4 [warning-unmapped: ALU destination r12b is not in the BPF JIT register file] */
    /* 0x12e2: or     r12b,r15b [warning-unmapped: ALU destination r12b is not in the BPF JIT register file] */
    /* 0x12e5: rol    r14w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x12ea: movzx  esi,r14w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x12ee: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp] */
    /* 0x12f0: and    edi,0xff000000 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 4278190080), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x12f6: lea    r9d,[r11-0x21523f01] [warning-unmapped: LEA base/index not in BPF register file: [r11-0x21523f01]] */
    /* 0x12fd: mov    r10d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ebp] */
    /* 0x1300: and    r10d,0xff0000 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1307: add    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x130a: mov    edi,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    edi,ebp] */
    /* 0x130c: and    edi,0xff00 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 65280), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x1312: add    edi,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1315: movzx  ebx,bpl [warning-unmapped: movzx source size not recognized: bpl] */
    /* 0x1319: add    ebx,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x131b: mov    rdx,QWORD PTR [rsp-0x8] [warning-unmapped: memory base rsp is not in the BPF JIT register file] */
    /* 0x1320: mov    edi,edx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_3, 0, 0),
    /* 0x1322: sub    edi,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x1325: mov    r14d,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1328: rol    r14d,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x132c: xor    r14d,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_1, 0, 0),
    /* 0x132f: add    r9d,r8d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x1332: sub    r8d,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_5, BPF_REG_8, 0, 0),
    /* 0x1335: mov    r10d,r14d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r14d] */
    /* 0x1338: rol    r10d,0x6 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x133c: xor    r10d,r8d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x133f: add    r14d,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x1342: lea    edi,[r10+r14*1] [warning-unmapped: LEA base/index not in BPF register file: [r10+r14*1]] */
    /* 0x1346: sub    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1349: rol    r10d,0x8 [warning-unmapped: ROL width/register not supported by current selectors: r10d] */
    /* 0x134d: movzx  r8d,WORD PTR [rcx+0x3e] [exact-kinsn: direct memory load via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_5, BPF_REG_4, 62), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1352: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1355: sub    r14d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1358: mov    r11d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r10d] */
    /* 0x135b: rol    r11d,0x10 [warning-unmapped: ROL width/register not supported by current selectors: r11d] */
    /* 0x135f: xor    r11d,r14d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1362: add    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1365: sub    edi,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x1368: mov    r14d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r11d] */
    /* 0x136b: rol    r14d,0x13 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 19, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x136f: xor    r14d,edi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_1, 0, 0),
    /* 0x1372: add    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1375: lea    r9d,[r14+r11*1] [warning-unmapped: LEA base/index not in BPF register file: [r14+r11*1]] */
    /* 0x1379: sub    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x137c: rol    r14d,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1380: add    r11d,ebx [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1383: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1386: xor    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1389: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x138c: rol    edi,0xe [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 14, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x138f: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1392: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d] */
    /* 0x1395: rol    edi,0xb [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1398: xor    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x139b: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x139e: xor    r9d,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x13a1: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d] */
    /* 0x13a4: rol    edi,0x19 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 25, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x13a7: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x13aa: xor    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x13ad: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x13b0: rol    edi,0x10 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x13b3: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x13b6: xor    r11d,r10d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x13b9: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d] */
    /* 0x13bc: rol    edi,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x13bf: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x13c2: xor    r9d,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x13c5: rol    r11d,0xe [warning-unmapped: ROL width/register not supported by current selectors: r11d] */
    /* 0x13c9: sub    r9d,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x13cc: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x13cf: rol    edi,0x18 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 24, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x13d2: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x13d5: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x13d8: add    r9d,0xe0adc0f7 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 3769483511),
    /* 0x13df: mov    r11d,r8d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r8d] */
    /* 0x13e2: add    r11d,0x70ccc0f7 [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x13e9: mov    r10d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,r11d] */
    /* 0x13ec: xor    r10d,0xe0adc0f7 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x13f3: mov    edi,0x70cc0000 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_1, 0, 0, 1892417536),
    /* 0x13f8: shrd   edi,r11d,0x12 [warning-unmapped: SHRD operands are not in the BPF JIT register file: shrd   edi,r11d,0x12] */
    /* 0x13fd: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1400: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1403: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d] */
    /* 0x1406: rol    edi,0xb [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1409: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x140c: xor    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x140f: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x1412: rol    edi,0x19 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 25, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1415: sub    r11d,edi [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1418: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d] */
    /* 0x141b: rol    edi,0x10 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x141e: xor    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1421: sub    r10d,edi [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1424: xor    r9d,r10d [warning-unmapped: ALU source r10d is not supported] */
    /* 0x1427: mov    edi,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r10d] */
    /* 0x142a: rol    edi,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_1, BPF_REG_1, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x142d: sub    r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x1430: xor    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1433: rol    r9d,0xe [warning-reg-remap: roll imm kinsn; verifier instantiate uses temp BPF_REG_6; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_9, BPF_REG_9, 14, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x1437: sub    r11d,r9d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x143a: xor    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x143d: rol    r11d,0x18 [warning-unmapped: ROL width/register not supported by current selectors: r11d] */
    /* 0x1441: sub    r10d,r11d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1444: mov    edi,0xffff0001 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_1, 0, 0, 4294901761),
    /* 0x1449: imul   rdi,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rdi,r10] */
    /* 0x144d: shr    rdi,0x30 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1451: mov    r9d,edi [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x1454: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x1458: or     r9d,edi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x145b: sub    r10d,r9d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x145e: mov    rdi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1461: add    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x1464: mov    r9,rdi [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1467: shl    r9,0x6 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 6),
    /* 0x146b: add    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x146e: mov    r11,rdi [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rdi] */
    /* 0x1471: shr    r11,0x2 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1475: add    r9,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1478: add    r9,0x101640a [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_9, 0, 0, 16868362),
    /* 0x147f: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x1482: mov    r11,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r9] */
    /* 0x1485: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1489: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x148c: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x148f: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1492: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1496: mov    ebx,0x901f0000 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_6, 0, 0, 2417950720),
    /* 0x149b: add    rbx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_1, 0, 0),
    /* 0x149e: add    rbx,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x14a1: xor    rbx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x14a4: mov    rdi,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x14a7: shl    rdi,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_1, 0, 0, 6),
    /* 0x14ab: mov    r9,rbx [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x14ae: shr    r9,0x2 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x14b2: add    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x14b5: add    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x14b8: add    rdi,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x14bb: xor    rdi,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_1, BPF_REG_6, 0, 0),
    /* 0x14be: mov    r9,rdi [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x14c1: shl    r9,0x6 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 6),
    /* 0x14c5: add    r9,rax [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_0, 0, 0),
    /* 0x14c8: mov    r10,rdi [warning-unmapped: unsupported mnemonic or operand form: mov    r10,rdi] */
    /* 0x14cb: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x14cf: add    r9,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x14d2: inc    r9 [warning-reg-remap: incq reg kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_PAYLOAD(BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_INCQ),
    /* 0x14d5: xor    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x14d8: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x14db: shl    rdi,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_1, 0, 0, 6),
    /* 0x14df: add    rdi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_0, 0, 0),
    /* 0x14e2: mov    r10,r9 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r9] */
    /* 0x14e5: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x14e9: add    r10,rdi [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x14ec: xor    r10,r9 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x14ef: mov    r11,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r10] */
    /* 0x14f2: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x14f6: add    r11,rsi [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x14f9: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x14fc: mov    r9,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r9,r10] */
    /* 0x14ff: shr    r9,0x2 [warning-reg-remap: shrq imm kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1503: add    r9,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1506: rol    r8w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x150b: shl    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x150f: and    edx,0xffff0000 [exact-kinsn: andl imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_3, 4294901760), MICRO_HANDCRAFT_BPF_X86_ANDL_IMM32),
    /* 0x1515: xor    edx,r8d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x1518: mov    edi,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x151a: add    edi,0x14 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 20),
    /* 0x151d: rol    di,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x1521: movzx  r8d,r12b [warning-unmapped: movzx source size not recognized: r12b] */
    /* 0x1525: movzx  edi,di [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x1528: mov    r11d,edx [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,edx] */
    /* 0x152b: shr    r11d,0x10 [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x152f: add    rdi,r8 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x1532: add    rdi,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1535: add    rdi,0xdf3b [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 57147),
    /* 0x153c: mov    r8d,edi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x153f: shr    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x1543: movzx  r11d,di [warning-unmapped: movzx source size not recognized: di] */
    /* 0x1547: add    r11,r8 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x154a: cmp    rdi,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1551: cmovb  r11,rdi [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1555: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d] */
    /* 0x1558: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x155b: movzx  r8d,r11w [warning-unmapped: movzx source size not recognized: r11w] */
    /* 0x155f: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x1562: cmp    r11,0x10000 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r11,0x10000] */
    /* 0x1569: cmovb  r8,r11 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x156d: mov    edi,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x1570: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1573: movzx  r11d,r8w [warning-unmapped: movzx source size not recognized: r8w] */
    /* 0x1577: add    r11,rdi [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x157a: cmp    r8,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1581: cmovb  r11,r8 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1585: mov    edi,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    edi,r11d] */
    /* 0x1588: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x158b: add    edi,r11d [warning-unmapped: ALU source r11d is not supported] */
    /* 0x158e: xor    r9,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1591: or     edx,0x10ac [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_K, BPF_REG_3, 0, 0, 4268),
    /* 0x1597: shl    rdx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 32),
    /* 0x159b: or     rdx,0x200c80a [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_K, BPF_REG_3, 0, 0, 33605642),
    /* 0x15a2: cmp    r11,0x10000 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r11,0x10000] */
    /* 0x15a9: cmovb  edi,r11d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x15ad: shl    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x15b0: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x15b3: movabs rsi,0x200ffff000b [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x200ffff000bULL),
    /* 0x15bd: xor    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x15c0: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x15c3: mov    rdx,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x15c6: shl    rdx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 6),
    /* 0x15ca: mov    rdi,r9 [warning-reg-remap: movq register-to-register kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x15cd: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x15d1: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x15d4: add    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x15d7: add    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x15da: xor    rdx,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x15dd: jmp    1873 <katran_lb_consistent_hash_select_xdp+0x773> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, 131, 0),
    /* 0x15e2: lea    r12,[rcx+0x32] [warning-unmapped: LEA operands are not representable] */
    /* 0x15e6: cmp    r12,rbx [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r12,rbx] */
    /* 0x15e9: jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d> [warning-unmapped: cannot lower cmp    r12,rbx + jbe    161d <katran_lb_consistent_hash_select_xdp+0x51d> to BPF branch] */
    /* 0x15eb: mov    esi,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 1),
    /* 0x15f0: mov    rdx,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_3, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x15f3: shl    rdx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 6),
    /* 0x15f7: mov    rdi,rsi [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_2), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x15fa: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x15fe: add    rdi,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x1601: add    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x1604: add    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1607: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x160a: mov    QWORD PTR [rcx],rdx [exact-kinsn: direct memory store via x86 kinsn selector] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_3, BPF_REG_4, 0), MICRO_HANDCRAFT_BPF_X86_MOVQ_MEM_REG),
    /* 0x160d: mov    eax,0x2 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_0, 0, 0, 2),
    /* 0x1612: pop    rbx [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1613: pop    r12 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1615: pop    r13 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1617: pop    r14 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x1619: pop    r15 [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x161b: pop    rbp [warning-unmapped: native stack-frame instruction belongs to ABI/prologue, not BPF verifier IR] */
    /* 0x161c: ret [bpf-jit: BPF exit; kernel JIT emits the real return sequence] */
    HC_EXIT(),
    /* 0x161d: cmp    r15d,0x101640a [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 16868362), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1624: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r15d,0x101640a + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, -205, 16868362),
    /* 0x162a: movzx  r9d,WORD PTR [rcx+0x2c] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 44), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x162f: cmp    r9d,0x901f [exact-kinsn: cmpl reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 36895), MICRO_HANDCRAFT_BPF_X86_CMPL_IMM32),
    /* 0x1636: jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> [bpf-branch: lowered cmp    r9d,0x901f + jne    1232 <katran_lb_consistent_hash_select_xdp+0x132> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_9, 0, -210, 36895),
    /* 0x163c: mov    r9d,0x2 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 2),
    /* 0x1642: cmp    r14b,0x6 [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r14b,0x6] */
    /* 0x1646: jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [bpf-branch: lowered cmp    r14b,0x6 + jne    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to verifier-visible BPF branch] */
    HC_RAW(BPF_JMP | BPF_JNE | BPF_K, BPF_REG_8, 0, -25, 6),
    /* 0x1648: mov    esi,0x1 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_2, 0, 0, 1),
    /* 0x164d: mov    r9d,0x1 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 1),
    /* 0x1653: cmp    r10,0x5ea [warning-unmapped: CMP operand form has no current kinsn selector: cmp    r10,0x5ea] */
    /* 0x165a: jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [warning-unmapped: cannot lower cmp    r10,0x5ea + jg     15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> to BPF branch] */
    /* 0x165c: rol    bp,0x8 [warning-unmapped: ROL width/register not supported by current selectors: bp] */
    /* 0x1660: movzx  esi,bp [warning-unmapped: movzx source size not recognized: bp] */
    /* 0x1663: shl    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x1667: shl    edx,0x18 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 24),
    /* 0x166a: or     r11d,r8d [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x166d: or     r11d,edx [warning-unmapped: ALU destination r11d is not in the BPF JIT register file] */
    /* 0x1670: movzx  r9d,WORD PTR [rcx+0x2a] [warning-reg-remap: direct memory load via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_MEM_PAYLOAD(BPF_REG_9, BPF_REG_4, 42), MICRO_HANDCRAFT_BPF_X86_MOVZWL_MEM),
    /* 0x1675: mov    ebx,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_6, BPF_REG_9, 0, 0),
    /* 0x1678: add    ebx,0x70ccc0f7 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_6, 0, 0, 1892466935),
    /* 0x167e: mov    r10d,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    r10d,ebx] */
    /* 0x1681: xor    r10d,0xe0adc0f7 [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1688: mov    ebp,0x70cc0000 [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,0x70cc0000] */
    /* 0x168d: shrd   ebp,ebx,0x12 [warning-unmapped: SHRD operands are not in the BPF JIT register file: shrd   ebp,ebx,0x12] */
    /* 0x1691: sub    r10d,ebp [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x1694: lea    ebp,[r11-0x1f523f09] [warning-unmapped: LEA operands are not representable] */
    /* 0x169b: xor    ebp,r10d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x169e: mov    r14d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r10d] */
    /* 0x16a1: rol    r14d,0xb [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 11, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16a5: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16a8: mov    r14d,ebp [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,ebp] */
    /* 0x16ab: rol    r14d,0x19 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 25, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16af: xor    ebx,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x16b1: sub    ebx,r14d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_SUB | BPF_X, BPF_REG_6, BPF_REG_8, 0, 0),
    /* 0x16b4: xor    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16b7: mov    r14d,ebx [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x16ba: rol    r14d,0x10 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 16, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16be: sub    r10d,r14d [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16c1: xor    ebp,r10d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16c4: mov    r14d,r10d [warning-unmapped: unsupported mnemonic or operand form: mov    r14d,r10d] */
    /* 0x16c7: rol    r14d,0x4 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_6] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_8, BPF_REG_8, 4, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16cb: sub    ebp,r14d [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16ce: xor    ebx,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x16d0: rol    ebp,0xe [warning-unmapped: ROL width/register not supported by current selectors: ebp] */
    /* 0x16d3: sub    ebx,ebp [warning-unmapped: ALU source ebp is not supported] */
    /* 0x16d5: xor    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16d8: rol    ebx,0x18 [exact-kinsn: roll imm kinsn; verifier instantiate uses temp BPF_REG_7] */
    HC_KINSN(HC_ROTATE_PAYLOAD(BPF_REG_6, BPF_REG_6, 24, BPF_REG_7), MICRO_HANDCRAFT_BPF_X86_ROLL_IMM),
    /* 0x16db: sub    r10d,ebx [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16de: mov    ebx,0xffff0001 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_6, 0, 0, 4294901761),
    /* 0x16e3: imul   rbx,r10 [warning-unmapped: IMUL operands are not in the 64-bit BPF JIT register file: imul   rbx,r10] */
    /* 0x16e7: shr    rbx,0x30 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 48), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x16eb: mov    ebp,ebx [warning-unmapped: unsupported mnemonic or operand form: mov    ebp,ebx] */
    /* 0x16ed: shl    ebp,0x10 [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16f0: or     ebp,ebx [warning-unmapped: ALU destination ebp is not in the BPF JIT register file] */
    /* 0x16f2: sub    r10d,ebp [warning-unmapped: ALU destination r10d is not in the BPF JIT register file] */
    /* 0x16f5: mov    r11d,r11d [warning-unmapped: unsupported mnemonic or operand form: mov    r11d,r11d] */
    /* 0x16f8: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x16fb: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11] */
    /* 0x16fe: shl    rbx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 6),
    /* 0x1702: mov    r14,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r14,r11] */
    /* 0x1705: shr    r14,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1709: add    r14,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_0, 0, 0),
    /* 0x170c: add    rbx,r14 [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_8, 0, 0),
    /* 0x170f: add    rbx,0x101640a [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_6, 0, 0, 16868362),
    /* 0x1716: xor    rbx,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1719: mov    r11,rbx [warning-unmapped: unsupported mnemonic or operand form: mov    r11,rbx] */
    /* 0x171c: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1720: mov    r14,rbx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_8, BPF_REG_6), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1723: shr    r14,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_8, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1727: add    r14,r9 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_8, BPF_REG_9, 0, 0),
    /* 0x172a: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x172d: add    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1730: mov    r14d,0x901f0000 [bpf-jit: 32-bit immediate move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_8, 0, 0, 2417950720),
    /* 0x1736: add    r14,r11 [warning-unmapped: ALU source r11 is not supported] */
    /* 0x1739: xor    r14,rbx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_8, BPF_REG_6, 0, 0),
    /* 0x173c: mov    r11,r14 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r14] */
    /* 0x173f: shl    r11,0x6 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1743: mov    rbx,r14 [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_6, BPF_REG_8), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1746: shr    rbx,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x174a: add    r11,rax [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x174d: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1750: add    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1753: xor    r11,r14 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1756: mov    r10,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r11] */
    /* 0x1759: shl    r10,0x6 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x175d: add    r10,rax [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1760: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11] */
    /* 0x1763: shr    rbx,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_6, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1767: add    r10,rbx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x176a: inc    r10 [warning-unmapped: INC destination r10 is not in the BPF JIT register file] */
    /* 0x176d: xor    r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1770: mov    rbx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r10] */
    /* 0x1773: shl    rbx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 6),
    /* 0x1777: add    rbx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_0, 0, 0),
    /* 0x177a: mov    r11,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    r11,r10] */
    /* 0x177d: shr    r11,0x2 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1781: add    r11,rbx [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1784: xor    r11,r10 [warning-unmapped: ALU destination r11 is not in the BPF JIT register file] */
    /* 0x1787: mov    rbx,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    rbx,r11] */
    /* 0x178a: shl    rbx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_6, 0, 0, 6),
    /* 0x178e: add    rbx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_2, 0, 0),
    /* 0x1791: add    rbx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_6, BPF_REG_0, 0, 0),
    /* 0x1794: mov    r10,r11 [warning-unmapped: unsupported mnemonic or operand form: mov    r10,r11] */
    /* 0x1797: shr    r10,0x2 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x179b: rol    r9w,0x8 [warning-reg-remap: rolw imm8 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x17a0: add    r10,rbx [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x17a3: shl    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x17a7: or     edx,r8d [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_X, BPF_REG_3, BPF_REG_5, 0, 0),
    /* 0x17aa: xor    edx,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_9, 0, 0),
    /* 0x17ad: mov    r8d,esi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_5, BPF_REG_2, 0, 0),
    /* 0x17b0: add    r8d,0x14 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_K, BPF_REG_5, 0, 0, 20),
    /* 0x17b4: rol    r8w,0x8 [exact-kinsn: rolw imm8 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 8), MICRO_HANDCRAFT_BPF_X86_ROLW_IMM),
    /* 0x17b9: movzx  r8d,r8w [exact-kinsn: movzx r32,r16 kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x17bd: mov    r9d,edx [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_9, BPF_REG_3, 0, 0),
    /* 0x17c0: shr    r9d,0x10 [warning-reg-remap: ALU imm operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_9, 0, 0, 16),
    /* 0x17c4: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x17c7: lea    rdi,[r9+r8*1] [warning-reg-remap: LEA via x86 kinsn selector; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_LEA_PAYLOAD(BPF_REG_1, BPF_REG_9, BPF_REG_5, 0, 1, 1, 0), MICRO_HANDCRAFT_BPF_X86_LEAQ),
    /* 0x17cb: add    rdi,0xdf3b [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_1, 0, 0, 57147),
    /* 0x17d2: mov    r8d,edi [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x17d5: shr    r8d,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_5, 0, 0, 16),
    /* 0x17d9: movzx  r9d,di [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_1), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x17dd: add    r9,r8 [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_5, 0, 0),
    /* 0x17e0: cmp    rdi,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x17e7: cmovb  r9,rdi [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x17eb: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x17ee: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x17f1: movzx  r8d,r9w [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_5, BPF_REG_9), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x17f5: add    r8,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_5, BPF_REG_1, 0, 0),
    /* 0x17f8: cmp    r9,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x17ff: cmovb  r8,r9 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1803: mov    edi,r8d [bpf-jit: 32-bit register move] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_5, 0, 0),
    /* 0x1806: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1809: movzx  r9d,r8w [warning-reg-remap: movzx r32,r16 kinsn; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_9, BPF_REG_5), MICRO_HANDCRAFT_BPF_X86_MOVZWL_RR),
    /* 0x180d: add    r9,rdi [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_9, BPF_REG_1, 0, 0),
    /* 0x1810: cmp    r8,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_5, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x1817: cmovb  r9,r8 [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x181b: mov    edi,r9d [warning-reg-remap: 32-bit register move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x181e: shr    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_RSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1821: add    edi,r9d [warning-reg-remap: ALU reg operation; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_9, 0, 0),
    /* 0x1824: xor    r10,r11 [warning-unmapped: ALU destination r10 is not in the BPF JIT register file] */
    /* 0x1827: or     edx,0x10ac [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_OR | BPF_K, BPF_REG_3, 0, 0, 4268),
    /* 0x182d: shl    rdx,0x20 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 32),
    /* 0x1831: or     rdx,0x200c80a [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_OR | BPF_K, BPF_REG_3, 0, 0, 33605642),
    /* 0x1838: cmp    r9,0x10000 [exact-kinsn: cmpq reg,imm32 kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_9, 65536), MICRO_HANDCRAFT_BPF_X86_CMPQ_IMM32),
    /* 0x183f: cmovb  edi,r9d [warning-unmapped: cmovb is carry-flag-bound; automatic conversion needs an adjacent unsigned cmp proof] */
    /* 0x1843: shl    edi,0x10 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU | BPF_LSH | BPF_K, BPF_REG_1, 0, 0, 16),
    /* 0x1846: xor    rdx,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_3, BPF_REG_2, 0, 0),
    /* 0x1849: movabs rsi,0x200ffff000b [bpf-jit: 64-bit immediate load] */
    HC_LD_IMM64_RAW(BPF_REG_2, 0, 0x200ffff000bULL),
    /* 0x1853: xor    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x1856: xor    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x1859: mov    rdx,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdx,r10] */
    /* 0x185c: shl    rdx,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_3, 0, 0, 6),
    /* 0x1860: mov    rdi,r10 [warning-unmapped: unsupported mnemonic or operand form: mov    rdi,r10] */
    /* 0x1863: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1867: add    rdi,rsi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_1, BPF_REG_2, 0, 0),
    /* 0x186a: add    rdx,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_0, 0, 0),
    /* 0x186d: add    rdx,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_3, BPF_REG_1, 0, 0),
    /* 0x1870: xor    rdx,r10 [warning-unmapped: ALU source r10 is not supported] */
    /* 0x1873: mov    rsi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_2, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1876: shl    rsi,0x6 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_LSH | BPF_K, BPF_REG_2, 0, 0, 6),
    /* 0x187a: add    rsi,rax [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_0, 0, 0),
    /* 0x187d: mov    rdi,rdx [exact-kinsn: movq register-to-register kinsn] */
    HC_KINSN(HC_REG_REG_PAYLOAD(BPF_REG_1, BPF_REG_3), MICRO_HANDCRAFT_BPF_X86_MOVQ_RR),
    /* 0x1880: shr    rdi,0x2 [exact-kinsn: shrq imm kinsn] */
    HC_KINSN(HC_REG_IMM_PAYLOAD(BPF_REG_1, 2), MICRO_HANDCRAFT_BPF_X86_SHRQ_IMM),
    /* 0x1884: add    rsi,rdi [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_X, BPF_REG_2, BPF_REG_1, 0, 0),
    /* 0x1887: add    rsi,0x3 [bpf-jit: ALU imm operation] */
    HC_RAW(BPF_ALU64 | BPF_ADD | BPF_K, BPF_REG_2, 0, 0, 3),
    /* 0x188b: xor    rsi,rdx [bpf-jit: ALU reg operation] */
    HC_RAW(BPF_ALU64 | BPF_XOR | BPF_X, BPF_REG_2, BPF_REG_3, 0, 0),
    /* 0x188e: mov    r9d,0x3 [warning-reg-remap: 32-bit immediate move; native r9 has no exact BPF JIT register; remapped to BPF_REG_9/final r15] */
    HC_RAW(BPF_ALU | BPF_MOV | BPF_K, BPF_REG_9, 0, 0, 3),
    /* 0x1894: jmp    15f0 <katran_lb_consistent_hash_select_xdp+0x4f0> [bpf-branch: lowered direct jmp to verifier-visible BPF jump] */
    HC_RAW(BPF_JMP | BPF_JA, 0, 0, -143, 0),
};

HC_EXPORT_PROGRAM(program)
```

## Handcraft Kernel JIT ASM
```asm
not captured
```
