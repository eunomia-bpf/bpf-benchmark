#include "common.h"

#define PREFETCH_MAP_INPUT_SIZE 262144U
#define PREFETCH_MAP_ROUNDS 256U
#define PREFETCH_MAP_PAYLOAD_BASE 4096U
#define PREFETCH_MAP_PAGE_STRIDE 4096U
#define PREFETCH_MAP_LINE_STRIDE 64U
#define PREFETCH_MAP_DELAY_ROUNDS 16U

#ifndef MICRO_NATIVE
struct prefetch_map_research_input {
    u8 data[PREFETCH_MAP_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct prefetch_map_research_input);
} input_map SEC(".maps");

MICRO_DEFINE_SINGLE_RESULT_MAP()
#endif

static __always_inline int prefetch_map_has_bytes(u32 offset, u32 size)
{
    if (offset > PREFETCH_MAP_INPUT_SIZE) {
        return 0;
    }
    return PREFETCH_MAP_INPUT_SIZE - offset >= size;
}

static __always_inline u64 prefetch_map_mix(u64 acc,
                                            u64 value,
                                            u32 index,
                                            u32 salt)
{
    acc ^= value + 0x9E3779B97F4A7C15ULL + ((u64)index << 32) + salt;
    acc = micro_rotl64(acc, ((index + salt) & 31U) + 1U);
    acc += value ^ ((u64)salt * 0xD1342543DE82EF95ULL);
    return acc;
}

#define PREFETCH_MAP_DELAY(ACC, INDEX)                                      \
    do {                                                                    \
        _Pragma("clang loop unroll(disable)")                               \
        for (u32 step = 0; step < PREFETCH_MAP_DELAY_ROUNDS; step++) {      \
            (ACC) ^= ((u64)(INDEX) << 32) ^                                 \
                     ((u64)step * 0xA0761D6478BD642FULL);                  \
            (ACC) = micro_rotl64((ACC) + 0xE7037ED1A0B428DBULL,             \
                                 ((step + INDEX) & 15U) + 1U);             \
        }                                                                   \
    } while (0)

static __always_inline u32 prefetch_map_page_offset(u32 index)
{
    u32 page = (index * 37U) & 31U;
    u32 in_page = ((index * 131U) ^ (index >> 1)) & 504U;
    return PREFETCH_MAP_PAYLOAD_BASE + page * PREFETCH_MAP_PAGE_STRIDE +
           in_page;
}

static __always_inline u32 prefetch_map_line_offset(u32 index)
{
    u32 line = (index * 73U) & 1023U;
    return PREFETCH_MAP_PAYLOAD_BASE + line * PREFETCH_MAP_LINE_STRIDE;
}

static __always_inline int bench_prefetch_map_page_stride(const u8 *data,
                                                          u64 *out)
{
    u64 acc = 0xCBF29CE484222325ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_MAP_ROUNDS; index++) {
        u32 offset = prefetch_map_page_offset(index);
        const u8 *ptr = data + offset;

        if (!prefetch_map_has_bytes(offset, 8U)) {
            return -1;
        }

        PREFETCH_MAP_DELAY(acc, index);
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_map_mix(acc, value, index, 17U);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_map_indirect_page(const u8 *data,
                                                            u64 *out)
{
    u64 acc = 0x84222325CBF29CE4ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_MAP_ROUNDS; index++) {
        u32 table_offset = 128U + ((index * 5U) & 255U);
        u32 table_value = data[table_offset];
        u32 page = (table_value ^ (index * 11U)) & 31U;
        u32 in_page = ((table_value * 17U) ^ (index * 29U)) & 504U;
        u32 offset = PREFETCH_MAP_PAYLOAD_BASE +
                     page * PREFETCH_MAP_PAGE_STRIDE + in_page;
        const u8 *ptr = data + offset;

        if (!prefetch_map_has_bytes(offset, 8U)) {
            return -1;
        }

        PREFETCH_MAP_DELAY(acc, index);
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_map_mix(acc, value, index, table_value);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_map_line_dedup(const u8 *data,
                                                         u64 *out)
{
    u64 acc = 0xA24BAED4963EE407ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_MAP_ROUNDS; index++) {
        u32 offset = prefetch_map_line_offset(index);
        const u8 *line = data + offset;

        if (!prefetch_map_has_bytes(offset, 32U)) {
            return -1;
        }

        PREFETCH_MAP_DELAY(acc, index);
        u64 v0 = micro_read_u64_le(line, 0);
        u64 v1 = micro_read_u64_le(line, 8);
        u64 v2 = micro_read_u64_le(line, 16);
        u64 v3 = micro_read_u64_le(line, 24);
        acc = prefetch_map_mix(acc, v0 ^ v2, index, 31U);
        acc = prefetch_map_mix(acc, v1 ^ v3, index, 47U);
    }

    *out = acc;
    return 0;
}

#ifndef MICRO_NATIVE
#define DEFINE_PREFETCH_MAP_XDP_BENCH(PROG_NAME, BENCH_FN)                   \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                             \
    {                                                                         \
        struct prefetch_map_research_input *input;                            \
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
#define DEFINE_PREFETCH_MAP_XDP_BENCH(PROG_NAME, BENCH_FN)                   \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                             \
    {                                                                         \
        u8 *data = (u8 *)(long)ctx->data;                                     \
        u8 *data_end = (u8 *)(long)ctx->data_end;                             \
        u8 *payload;                                                          \
        u32 payload_len;                                                      \
        u64 result = 0;                                                       \
        if (micro_prepare_packet_payload(data, data_end,                      \
                                         PREFETCH_MAP_INPUT_SIZE,             \
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

DEFINE_PREFETCH_MAP_XDP_BENCH(prefetch_map_page_stride_xdp,
                              bench_prefetch_map_page_stride)
DEFINE_PREFETCH_MAP_XDP_BENCH(prefetch_map_indirect_page_xdp,
                              bench_prefetch_map_indirect_page)
DEFINE_PREFETCH_MAP_XDP_BENCH(prefetch_map_line_dedup_xdp,
                              bench_prefetch_map_line_dedup)

MICRO_LICENSE_ATTR();
