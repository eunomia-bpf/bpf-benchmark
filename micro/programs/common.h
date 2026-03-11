#ifndef MICRO_PROGRAMS_COMMON_H
#define MICRO_PROGRAMS_COMMON_H

#include <linux/bpf.h>
#include <linux/pkt_cls.h>
#include <bpf/bpf_helpers.h>

#define u8 unsigned char
#define u16 unsigned short
#define u32 unsigned int
#define u64 unsigned long long

#ifndef __always_inline
#define __always_inline __inline __attribute__((__always_inline__))
#endif

#ifndef __noinline
#define __noinline __attribute__((__noinline__))
#endif

#ifndef CGROUP_SKB_DROP
#define CGROUP_SKB_DROP 0
#endif

#ifndef CGROUP_SKB_OK
#define CGROUP_SKB_OK 1
#endif

#define MICRO_UNBOUNDED_LEN 0xFFFFFFFFU

static __always_inline int micro_has_bytes(u32 len, u32 offset, u32 size)
{
    if (len == MICRO_UNBOUNDED_LEN) {
        return 1;
    }
    if (offset > len) {
        return 0;
    }
    return len - offset >= size;
}

static __always_inline u16 micro_read_u16_le(const u8 *data, u32 offset)
{
    return (u16)((u16)data[offset] | ((u16)data[offset + 1] << 8));
}

static __always_inline u32 micro_read_u32_le(const u8 *data, u32 offset)
{
    return (u32)data[offset] | ((u32)data[offset + 1] << 8) |
           ((u32)data[offset + 2] << 16) | ((u32)data[offset + 3] << 24);
}

static __always_inline u64 micro_read_u64_le(const u8 *data, u32 offset)
{
    u64 value = 0;
    for (u32 i = 0; i < 8; i++) {
        value |= ((u64)data[offset + i]) << (i * 8);
    }
    return value;
}

static __always_inline u16 micro_read_u16_be(const u8 *data, u32 offset)
{
    return (u16)(((u16)data[offset] << 8) | data[offset + 1]);
}

static __always_inline u32 micro_read_u32_be(const u8 *data, u32 offset)
{
    return ((u32)data[offset] << 24) | ((u32)data[offset + 1] << 16) |
           ((u32)data[offset + 2] << 8) | (u32)data[offset + 3];
}

static __always_inline void micro_write_u64_le(u8 *data, u64 value)
{
    for (u32 i = 0; i < 8; i++) {
        data[i] = (u8)(value >> (i * 8));
    }
}

static __always_inline u64 micro_rotl64(u64 value, u32 shift)
{
    shift &= 63U;
    if (shift == 0) {
        return value;
    }
    return (value << shift) | (value >> (64U - shift));
}

static __always_inline u32 micro_rotl32(u32 value, u32 shift)
{
    shift &= 31U;
    if (shift == 0) {
        return value;
    }
    return (value << shift) | (value >> (32U - shift));
}

#define DEFINE_PACKET_BACKED_XDP_BENCH(PROG_NAME, BENCH_FN)                      \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                                 \
    {                                                                            \
        u8 *data = (u8 *)(long)ctx->data;                                        \
        u8 *data_end = (u8 *)(long)ctx->data_end;                                \
        u8 *payload;                                                             \
        u64 result = 0;                                                          \
        u32 payload_len;                                                         \
        if (data > data_end) {                                                   \
            return XDP_ABORTED;                                                  \
        }                                                                        \
        payload = data + 8U;                                                     \
        if (payload > data_end) {                                                \
            return XDP_ABORTED;                                                  \
        }                                                                        \
        payload_len = (u32)(data_end - payload);                                 \
        if (BENCH_FN(payload, payload_len, &result) < 0) {                       \
            return XDP_ABORTED;                                                  \
        }                                                                        \
        micro_write_u64_le(data, result);                                        \
        return XDP_PASS;                                                         \
    }                                                                            \
    char LICENSE[] SEC("license") = "GPL";

#define DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(PROG_NAME, BENCH_FN, INPUT_SIZE)    \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                                 \
    {                                                                            \
        u8 *data = (u8 *)(long)ctx->data;                                        \
        u8 *data_end = (u8 *)(long)ctx->data_end;                                \
        u8 *payload;                                                             \
        u8 *payload_end;                                                         \
        u64 result = 0;                                                          \
        if (data > data_end) {                                                   \
            return XDP_ABORTED;                                                  \
        }                                                                        \
        payload = data + 8U;                                                     \
        if (payload > data_end) {                                                \
            return XDP_ABORTED;                                                  \
        }                                                                        \
        payload_end = payload + (INPUT_SIZE);                                    \
        if (payload_end > data_end) {                                            \
            return XDP_ABORTED;                                                  \
        }                                                                        \
        if (BENCH_FN(payload, INPUT_SIZE, &result) < 0) {                        \
            return XDP_ABORTED;                                                  \
        }                                                                        \
        micro_write_u64_le(data, result);                                        \
        return XDP_PASS;                                                         \
    }                                                                            \
    char LICENSE[] SEC("license") = "GPL";

#define DEFINE_STAGED_INPUT_XDP_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE) \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                                  \
    {                                                                             \
        struct INPUT_TYPE *input;                                                 \
        u8 *data = (u8 *)(long)ctx->data;                                         \
        u8 *data_end = (u8 *)(long)ctx->data_end;                                 \
        u64 result = 0;                                                           \
        __u32 key = 0;                                                            \
        if (data > data_end || data + 8U > data_end) {                            \
            return XDP_ABORTED;                                                   \
        }                                                                         \
        input = bpf_map_lookup_elem(&input_map, &key);                            \
        if (!input) {                                                             \
            return XDP_ABORTED;                                                   \
        }                                                                         \
        if (BENCH_FN(input->data, INPUT_SIZE, &result) < 0) {                     \
            return XDP_ABORTED;                                                   \
        }                                                                         \
        micro_write_u64_le(data, result);                                         \
        return XDP_PASS;                                                          \
    }                                                                             \
    char LICENSE[] SEC("license") = "GPL";

#define DEFINE_MAP_BACKED_XDP_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE) \
    struct {                                                                   \
        __uint(type, BPF_MAP_TYPE_ARRAY);                                      \
        __uint(max_entries, 1);                                                \
        __type(key, __u32);                                                    \
        __type(value, __u64);                                                  \
    } result_map SEC(".maps");                                                 \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                               \
    {                                                                          \
        struct INPUT_TYPE *input;                                              \
        u64 result = 0;                                                        \
        __u32 key = 0;                                                         \
        (void)ctx;                                                             \
        input = bpf_map_lookup_elem(&input_map, &key);                         \
        if (!input) {                                                          \
            return XDP_ABORTED;                                                \
        }                                                                      \
        if (BENCH_FN(input->data, INPUT_SIZE, &result) < 0) {                  \
            return XDP_ABORTED;                                                \
        }                                                                      \
        bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);              \
        return XDP_PASS;                                                       \
    }                                                                          \
    char LICENSE[] SEC("license") = "GPL";

#define MICRO_DEFINE_SINGLE_RESULT_MAP()                                        \
    struct {                                                                    \
        __uint(type, BPF_MAP_TYPE_ARRAY);                                       \
        __uint(max_entries, 1);                                                 \
        __type(key, __u32);                                                     \
        __type(value, __u64);                                                   \
    } result_map SEC(".maps");

#define DEFINE_STAGED_INPUT_TC_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE) \
    MICRO_DEFINE_SINGLE_RESULT_MAP()                                            \
    SEC("tc") int PROG_NAME(struct __sk_buff *skb)                              \
    {                                                                           \
        struct INPUT_TYPE *input;                                               \
        u64 result = ~0ULL;                                                     \
        __u32 key = 0;                                                          \
        (void)skb;                                                              \
        input = bpf_map_lookup_elem(&input_map, &key);                          \
        if (!input) {                                                           \
            bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);           \
            return TC_ACT_SHOT;                                                 \
        }                                                                       \
        if (BENCH_FN(input->data, INPUT_SIZE, &result) < 0) {                   \
            result = ~0ULL;                                                     \
            bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);           \
            return TC_ACT_SHOT;                                                 \
        }                                                                       \
        bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);               \
        return TC_ACT_OK;                                                       \
    }                                                                           \
    char LICENSE[] SEC("license") = "GPL";

#define DEFINE_MAP_BACKED_TC_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE) \
    DEFINE_STAGED_INPUT_TC_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE)

#define DEFINE_STAGED_INPUT_CGROUP_SKB_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE) \
    MICRO_DEFINE_SINGLE_RESULT_MAP()                                                     \
    SEC("cgroup_skb/egress") int PROG_NAME(struct __sk_buff *skb)                        \
    {                                                                                    \
        struct INPUT_TYPE *input;                                                        \
        u64 result = ~0ULL;                                                              \
        __u32 key = 0;                                                                   \
        (void)skb;                                                                       \
        input = bpf_map_lookup_elem(&input_map, &key);                                   \
        if (!input) {                                                                    \
            bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);                    \
            return CGROUP_SKB_DROP;                                                      \
        }                                                                                \
        if (BENCH_FN(input->data, INPUT_SIZE, &result) < 0) {                            \
            result = ~0ULL;                                                              \
            bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);                    \
            return CGROUP_SKB_DROP;                                                      \
        }                                                                                \
        bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);                        \
        return CGROUP_SKB_OK;                                                            \
    }                                                                                    \
    char LICENSE[] SEC("license") = "GPL";

#define DEFINE_MAP_BACKED_CGROUP_SKB_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE) \
    DEFINE_STAGED_INPUT_CGROUP_SKB_BENCH(PROG_NAME, BENCH_FN, INPUT_TYPE, INPUT_SIZE)

#endif
