#include "common.h"

#define PREFETCH_UPPER_INPUT_SIZE 1048576U
#define PREFETCH_UPPER_ROUNDS 512U
#define PREFETCH_UPPER_PAGE_STRIDE 4096U

#ifndef MICRO_NATIVE
struct prefetch_upper_bound_input {
    u8 data[PREFETCH_UPPER_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct prefetch_upper_bound_input);
} input_map SEC(".maps");

MICRO_DEFINE_SINGLE_RESULT_MAP()
#endif

static __always_inline int prefetch_upper_has_bytes(u32 offset, u32 size)
{
    if (offset > PREFETCH_UPPER_INPUT_SIZE) {
        return 0;
    }
    return PREFETCH_UPPER_INPUT_SIZE - offset >= size;
}

static __always_inline u32 prefetch_upper_page_offset(u32 index)
{
    u32 page = (index * 131U) & 255U;
    u32 in_page = ((index * 977U) ^ (index >> 1)) & 504U;
    return page * PREFETCH_UPPER_PAGE_STRIDE + in_page;
}

static __always_inline u64 prefetch_upper_rotmix(u64 acc, u32 index, u32 salt)
{
    acc ^= ((u64)index << 32) ^ ((u64)salt * 0xA0761D6478BD642FULL);
    acc = micro_rotl64(acc + 0xE7037ED1A0B428DBULL, ((index + salt) & 31U) + 1U);
    acc ^= 0x8EBC6AF09C88C6E3ULL + ((u64)salt << 24);
    return acc;
}

static __always_inline u64 prefetch_upper_delay(u64 acc, u32 index)
{
    acc = prefetch_upper_rotmix(acc, index, 3U);
    acc = prefetch_upper_rotmix(acc, index, 5U);
    acc = prefetch_upper_rotmix(acc, index, 7U);
    acc = prefetch_upper_rotmix(acc, index, 11U);
    acc = prefetch_upper_rotmix(acc, index, 13U);
    acc = prefetch_upper_rotmix(acc, index, 17U);
    acc = prefetch_upper_rotmix(acc, index, 19U);
    acc = prefetch_upper_rotmix(acc, index, 23U);
    return acc;
}

static __always_inline u64 prefetch_upper_mix(u64 acc, u64 value, u32 index)
{
    acc ^= value + 0x9E3779B97F4A7C15ULL + ((u64)index << 32);
    acc = micro_rotl64(acc, ((index * 7U) & 31U) + 1U);
    acc += value ^ ((u64)index * 0xD1342543DE82EF95ULL);
    return acc;
}

static __always_inline u64 prefetch_upper_read_u64_le(const volatile u8 *data)
{
    u64 value = 0;

    for (u32 i = 0; i < 8; i++) {
        value |= ((u64)data[i]) << (i * 8);
    }
    return value;
}

static __always_inline const volatile u8 *
prefetch_upper_ptr_barrier(const volatile u8 *ptr)
{
    __asm__ __volatile__("" : "+r"(ptr));
    return ptr;
}

static __always_inline int bench_prefetch_upper_page_stride(const u8 *data,
                                                            u64 *out)
{
    u64 acc = 0xD6E8FEB86659FD93ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 offset = prefetch_upper_page_offset(index);
        const volatile u8 *ptr = data + offset;

        if (!prefetch_upper_has_bytes(offset, 8U)) {
            return -1;
        }

        acc = prefetch_upper_delay(acc, index);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(ptr), index);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_pipeline_page_stride(const u8 *data,
                                                               u64 *out)
{
    u64 acc = 0x7B3E9C9D5F45B13BULL;
    u32 cur_offset = prefetch_upper_page_offset(0);
    const volatile u8 *cur = data + cur_offset;

    if (!prefetch_upper_has_bytes(cur_offset, 8U)) {
        return -1;
    }

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 next_offset = prefetch_upper_page_offset(index + 1U);
        const volatile u8 *next = data + next_offset;

        next = prefetch_upper_ptr_barrier(next);

        if (!prefetch_upper_has_bytes(next_offset, 8U)) {
            return -1;
        }

        acc = prefetch_upper_delay(acc ^ ((u64)next_offset << 17) ^ cur_offset,
                                   index);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur), index);
        cur = next;
        cur_offset = next_offset;
    }

    *out = acc;
    return 0;
}

#ifndef MICRO_NATIVE
#define DEFINE_PREFETCH_UPPER_XDP_BENCH(PROG_NAME, BENCH_FN)                 \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                             \
    {                                                                         \
        struct prefetch_upper_bound_input *input;                             \
        u64 result = 0;                                                       \
        __u32 key = 0;                                                        \
        (void)ctx;                                                            \
        input = bpf_map_lookup_elem(&input_map, &key);                        \
        if (!input) {                                                         \
            return XDP_ABORTED;                                               \
        }                                                                     \
        if (BENCH_FN(input->data, &result) < 0) {                             \
            return XDP_ABORTED;                                               \
        }                                                                     \
        bpf_map_update_elem(&result_map, &key, &result, BPF_ANY);             \
        return XDP_PASS;                                                      \
    }
#else
#define DEFINE_PREFETCH_UPPER_XDP_BENCH(PROG_NAME, BENCH_FN)                 \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                             \
    {                                                                         \
        u8 *data = (u8 *)(long)ctx->data;                                     \
        u8 *data_end = (u8 *)(long)ctx->data_end;                             \
        u8 *payload;                                                          \
        u32 payload_len;                                                      \
        u64 result = 0;                                                       \
        if (micro_prepare_packet_payload(data, data_end,                      \
                                         PREFETCH_UPPER_INPUT_SIZE,           \
                                         &payload, &payload_len) < 0) {       \
            return XDP_ABORTED;                                               \
        }                                                                     \
        if (BENCH_FN(payload, &result) < 0) {                                 \
            return XDP_ABORTED;                                               \
        }                                                                     \
        micro_write_u64_le(data, result);                                     \
        return XDP_PASS;                                                      \
    }
#endif

DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_upper_page_stride_xdp,
                                bench_prefetch_upper_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_pipeline_page_stride_xdp,
                                bench_prefetch_pipeline_page_stride)

MICRO_LICENSE_ATTR();
