#ifndef BPFOPT_TESTCCODE_MOCK_BPF_NATIVE_H
#define BPFOPT_TESTCCODE_MOCK_BPF_NATIVE_H

#define __always_inline inline __attribute__((always_inline))
#define __noinline __attribute__((noinline))
#define __used __attribute__((used))
#define SEC(name)
#define NULL ((void *)0)

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;

typedef u16 __be16;
typedef u32 __be32;
typedef u64 __be64;
typedef u32 __wsum;

struct xdp_md {
    u32 data;
    u32 data_end;
};

struct __sk_buff {
    u32 len;
    u32 cb[5];
    u32 data;
    u32 data_end;
};

struct ethhdr {
    u8 h_dest[6];
    u8 h_source[6];
    __be16 h_proto;
};

struct iphdr {
    u8 ihl_version;
    u8 tos;
    __be16 tot_len;
    __be16 id;
    __be16 frag_off;
    u8 ttl;
    u8 protocol;
    __wsum check;
    __be32 saddr;
    __be32 daddr;
};

struct ipv6hdr {
    __be32 flow_lbl;
    __be16 payload_len;
    u8 nexthdr;
    u8 hop_limit;
    __be32 saddr[4];
    __be32 daddr[4];
};

static __always_inline u16 bpf_ntohs(u16 x)
{
    return __builtin_bswap16(x);
}

static __always_inline u16 bpf_htons(u16 x)
{
    return __builtin_bswap16(x);
}

static __always_inline u32 bpf_ntohl(u32 x)
{
    return __builtin_bswap32(x);
}

static __always_inline u32 bpf_htonl(u32 x)
{
    return __builtin_bswap32(x);
}

static __always_inline u64 bpf_be64_to_cpu(u64 x)
{
    return __builtin_bswap64(x);
}

#endif
