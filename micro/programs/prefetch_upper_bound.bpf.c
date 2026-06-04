#include "common.h"

#define PREFETCH_UPPER_INPUT_SIZE 1048576U
#define PREFETCH_UPPER_ROUNDS 512U
#define PREFETCH_UPPER_PAGE_STRIDE 4096U
#define PREFETCH_UPPER_CACHELINE 64U
#define PREFETCH_UPPER_RECORD_STRIDE 256U
#define PREFETCH_UPPER_MLOP_RECORD_STRIDE 1024U

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

static __always_inline u32 prefetch_upper_line_offset(u32 index, u32 stride,
                                                      u32 salt)
{
    u32 raw = index * stride + (((index * salt) ^ (index >> 1)) & 56U);
    return raw & (PREFETCH_UPPER_INPUT_SIZE - PREFETCH_UPPER_CACHELINE);
}

static __always_inline u32 prefetch_upper_variable_stride_offset(u32 index)
{
    u32 stride = PREFETCH_UPPER_CACHELINE << ((index * 13U) & 3U);
    return prefetch_upper_line_offset(index ^ (index >> 3), stride, 47U);
}

static __always_inline u32 prefetch_upper_page_base(u32 index)
{
    return ((index * 131U) & 255U) * PREFETCH_UPPER_PAGE_STRIDE;
}

static __always_inline u32 prefetch_upper_record_base(u32 index)
{
    u32 record = (index * 73U) & 4095U;
    return record * PREFETCH_UPPER_RECORD_STRIDE;
}

static __always_inline u32 prefetch_upper_mlop_offset(u32 index)
{
    u32 record = ((index * 73U) ^ (index >> 2)) & 1023U;
    u32 field = ((index * 19U) & 7U) * PREFETCH_UPPER_CACHELINE;
    return record * PREFETCH_UPPER_MLOP_RECORD_STRIDE + field;
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

static __always_inline int
bench_prefetch_pipeline_horizon_page_stride(const u8 *data, u64 *out,
                                            u32 horizon, u32 salt)
{
    u64 acc = 0xB4F1C3A9D27E8A5DULL ^ ((u64)horizon << 48) ^
              ((u64)salt << 20);
    u32 cur_offset = prefetch_upper_page_offset(0);
    const volatile u8 *cur = data + cur_offset;

    if (!prefetch_upper_has_bytes(cur_offset, 8U)) {
        return -1;
    }

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 future_offset = prefetch_upper_page_offset(index + horizon);
        const volatile u8 *future = data + future_offset;

        future = prefetch_upper_ptr_barrier(future);

        if (!prefetch_upper_has_bytes(future_offset, 8U)) {
            return -1;
        }

        acc = prefetch_upper_delay(
            acc ^ ((u64)future_offset << 19) ^ cur_offset ^
                ((u64)horizon << 43),
            index + salt);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur),
                                 index ^ (horizon * 13U));

        cur_offset = prefetch_upper_page_offset(index + 1U);
        cur = data + cur_offset;
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_pipeline_horizon1_page_stride(const u8 *data, u64 *out)
{
    return bench_prefetch_pipeline_horizon_page_stride(data, out, 1U, 29U);
}

static __always_inline int
bench_prefetch_pipeline_horizon2_page_stride(const u8 *data, u64 *out)
{
    return bench_prefetch_pipeline_horizon_page_stride(data, out, 2U, 31U);
}

static __always_inline int
bench_prefetch_pipeline_horizon4_page_stride(const u8 *data, u64 *out)
{
    return bench_prefetch_pipeline_horizon_page_stride(data, out, 4U, 37U);
}

static __always_inline int bench_prefetch_pipeline_degree_page_stride(const u8 *data,
                                                                      u64 *out)
{
    u64 acc = 0xC6BC279692B5CC83ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_offset = prefetch_upper_page_offset(index);
        u32 next1_offset = prefetch_upper_page_offset(index + 1U);
        u32 next2_offset = prefetch_upper_page_offset(index + 2U);
        u32 next4_offset = prefetch_upper_page_offset(index + 4U);
        const volatile u8 *cur = data + cur_offset;
        const volatile u8 *next1 = data + next1_offset;
        const volatile u8 *next2 = data + next2_offset;
        const volatile u8 *next4 = data + next4_offset;

        next1 = prefetch_upper_ptr_barrier(next1);
        next2 = prefetch_upper_ptr_barrier(next2);
        next4 = prefetch_upper_ptr_barrier(next4);

        if (!prefetch_upper_has_bytes(cur_offset, 8U) ||
            !prefetch_upper_has_bytes(next1_offset, 8U) ||
            !prefetch_upper_has_bytes(next2_offset, 8U) ||
            !prefetch_upper_has_bytes(next4_offset, 8U)) {
            return -1;
        }

        __asm__ __volatile__("" : "+r"(next1), "+r"(next2), "+r"(next4));

        acc = prefetch_upper_delay(
            acc ^ ((u64)next1_offset << 11) ^ ((u64)next2_offset << 23) ^
                ((u64)next4_offset << 37) ^ cur_offset,
            index + 41U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur),
                                 index ^ 0x3dU);
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_stride_class(const u8 *data, u64 *out, u32 stride, u32 salt)
{
    u64 acc = 0x9127C4B92E37A51DULL ^ ((u64)stride << 17) ^
              ((u64)salt << 41);

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_offset = prefetch_upper_line_offset(index, stride, salt);
        u32 future_offset =
            prefetch_upper_line_offset(index + 2U, stride, salt);
        const volatile u8 *cur = data + cur_offset;
        const volatile u8 *future = data + future_offset;

        future = prefetch_upper_ptr_barrier(future);

        if (!prefetch_upper_has_bytes(cur_offset, 8U) ||
            !prefetch_upper_has_bytes(future_offset, 8U)) {
            return -1;
        }

        acc = prefetch_upper_delay(
            acc ^ ((u64)future_offset << 21) ^ cur_offset, index + salt);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur),
                                 index ^ stride);
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_stride64_page_stride(const u8 *data, u64 *out)
{
    return bench_prefetch_stride_class(data, out, 64U, 43U);
}

static __always_inline int
bench_prefetch_stride256_page_stride(const u8 *data, u64 *out)
{
    return bench_prefetch_stride_class(data, out, 256U, 53U);
}

static __always_inline int
bench_prefetch_stride4096_page_stride(const u8 *data, u64 *out)
{
    return bench_prefetch_stride_class(data, out, 4096U, 59U);
}

static __always_inline int
bench_prefetch_variable_stride_page_stride(const u8 *data, u64 *out)
{
    u64 acc = 0x384F0B1A7295D6C3ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_offset = prefetch_upper_variable_stride_offset(index);
        u32 future_offset = prefetch_upper_variable_stride_offset(index + 2U);
        const volatile u8 *cur = data + cur_offset;
        const volatile u8 *future = data + future_offset;

        future = prefetch_upper_ptr_barrier(future);

        if (!prefetch_upper_has_bytes(cur_offset, 8U) ||
            !prefetch_upper_has_bytes(future_offset, 8U)) {
            return -1;
        }

        acc = prefetch_upper_delay(
            acc ^ ((u64)future_offset << 9) ^ ((u64)cur_offset << 27),
            index + 61U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur),
                                 index ^ 0x61U);
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_spatial_page_footprint(const u8 *data, u64 *out)
{
    u64 acc = 0xE12C3B4A59687766ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_base = prefetch_upper_page_base(index);
        u32 future_base = prefetch_upper_page_base(index + 2U);
        const volatile u8 *cur0 = data + cur_base;
        const volatile u8 *cur1 = data + cur_base + 128U;
        const volatile u8 *cur2 = data + cur_base + 256U;
        const volatile u8 *future0 = data + future_base;
        const volatile u8 *future1 = data + future_base + 128U;
        const volatile u8 *future2 = data + future_base + 256U;

        future0 = prefetch_upper_ptr_barrier(future0);
        future1 = prefetch_upper_ptr_barrier(future1);
        future2 = prefetch_upper_ptr_barrier(future2);

        if (!prefetch_upper_has_bytes(cur_base + 256U, 8U) ||
            !prefetch_upper_has_bytes(future_base + 256U, 8U)) {
            return -1;
        }

        __asm__ __volatile__("" : "+r"(future0), "+r"(future1), "+r"(future2));

        acc = prefetch_upper_delay(acc ^ ((u64)future_base << 15) ^ cur_base,
                                   index + 67U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur0),
                                 index);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur1),
                                 index + 1U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur2),
                                 index + 2U);
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_struct_field_fixed_offsets(const u8 *data, u64 *out)
{
    u64 acc = 0xA4E6C81B3D5F7092ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_base = prefetch_upper_record_base(index);
        u32 future_base = prefetch_upper_record_base(index + 2U);
        const volatile u8 *cur0 = data + cur_base;
        const volatile u8 *cur1 = data + cur_base + 64U;
        const volatile u8 *cur2 = data + cur_base + 128U;
        const volatile u8 *future0 = data + future_base;
        const volatile u8 *future1 = data + future_base + 64U;
        const volatile u8 *future2 = data + future_base + 128U;

        future0 = prefetch_upper_ptr_barrier(future0);
        future1 = prefetch_upper_ptr_barrier(future1);
        future2 = prefetch_upper_ptr_barrier(future2);

        if (!prefetch_upper_has_bytes(cur_base + 128U, 8U) ||
            !prefetch_upper_has_bytes(future_base + 128U, 8U)) {
            return -1;
        }

        __asm__ __volatile__("" : "+r"(future0), "+r"(future1), "+r"(future2));

        acc = prefetch_upper_delay(acc ^ ((u64)future_base << 7) ^
                                       ((u64)cur_base << 29),
                                   index + 71U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur0),
                                 index ^ 0x10U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur1),
                                 index ^ 0x20U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur2),
                                 index ^ 0x30U);
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_mlop_index_field(const u8 *data, u64 *out)
{
    u64 acc = 0xF13579BDF2468ACEULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_offset = prefetch_upper_mlop_offset(index);
        u32 future_offset = prefetch_upper_mlop_offset(index + 2U);
        const volatile u8 *cur = data + cur_offset;
        const volatile u8 *future = data + future_offset;

        future = prefetch_upper_ptr_barrier(future);

        if (!prefetch_upper_has_bytes(cur_offset, 8U) ||
            !prefetch_upper_has_bytes(future_offset, 8U)) {
            return -1;
        }

        acc = prefetch_upper_delay(
            acc ^ ((u64)future_offset << 13) ^ ((u64)cur_offset << 31),
            index + 79U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur),
                                 index ^ 0x4dU);
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_degree123_page_stride(const u8 *data, u64 *out)
{
    u64 acc = 0x6C5B4A3928171605ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_offset = prefetch_upper_page_offset(index);
        u32 next2_offset = prefetch_upper_page_offset(index + 2U);
        u32 next4_offset = prefetch_upper_page_offset(index + 4U);
        u32 next8_offset = prefetch_upper_page_offset(index + 8U);
        const volatile u8 *cur = data + cur_offset;
        const volatile u8 *next2 = data + next2_offset;
        const volatile u8 *next4 = data + next4_offset;
        const volatile u8 *next8 = data + next8_offset;

        next2 = prefetch_upper_ptr_barrier(next2);
        next4 = prefetch_upper_ptr_barrier(next4);
        next8 = prefetch_upper_ptr_barrier(next8);

        if (!prefetch_upper_has_bytes(cur_offset, 8U) ||
            !prefetch_upper_has_bytes(next2_offset, 8U) ||
            !prefetch_upper_has_bytes(next4_offset, 8U) ||
            !prefetch_upper_has_bytes(next8_offset, 8U)) {
            return -1;
        }

        __asm__ __volatile__("" : "+r"(next2), "+r"(next4), "+r"(next8));

        acc = prefetch_upper_delay(
            acc ^ ((u64)next2_offset << 5) ^ ((u64)next4_offset << 17) ^
                ((u64)next8_offset << 33) ^ cur_offset,
            index + 83U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur),
                                 index ^ 0x7bU);
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_mixed_policy_table(const u8 *data, u64 *out)
{
    u64 acc = 0x1029384756ABCDEFULL;
    const volatile u8 *hot = data + 64U;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_offset = prefetch_upper_page_offset(index);
        u32 future_offset = prefetch_upper_page_offset(index + 2U);
        const volatile u8 *cur = data + cur_offset;
        const volatile u8 *future = data + future_offset;

        future = prefetch_upper_ptr_barrier(future);

        if (!prefetch_upper_has_bytes(cur_offset, 8U) ||
            !prefetch_upper_has_bytes(future_offset, 8U)) {
            return -1;
        }

        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(hot),
                                 index ^ 0x55U);
        acc = prefetch_upper_delay(acc ^ ((u64)future_offset << 25) ^
                                       ((u64)cur_offset << 3),
                                   index + 89U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur),
                                 index ^ 0xaaU);
    }

    *out = acc;
    return 0;
}

static __always_inline int
bench_prefetch_stream_of_strides(const u8 *data, u64 *out)
{
    u64 acc = 0x89ABCDEF10293847ULL;

    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_UPPER_ROUNDS; index++) {
        u32 cur_a_offset = prefetch_upper_line_offset(index, 256U, 97U);
        u32 cur_b_offset = prefetch_upper_line_offset(index, 4096U, 131U);
        u32 future_a_offset =
            prefetch_upper_line_offset(index + 2U, 256U, 97U);
        u32 future_b_offset =
            prefetch_upper_line_offset(index + 2U, 4096U, 131U);
        const volatile u8 *cur_a = data + cur_a_offset;
        const volatile u8 *cur_b = data + cur_b_offset;
        const volatile u8 *future_a = data + future_a_offset;
        const volatile u8 *future_b = data + future_b_offset;

        future_a = prefetch_upper_ptr_barrier(future_a);
        future_b = prefetch_upper_ptr_barrier(future_b);

        if (!prefetch_upper_has_bytes(cur_a_offset, 8U) ||
            !prefetch_upper_has_bytes(cur_b_offset, 8U) ||
            !prefetch_upper_has_bytes(future_a_offset, 8U) ||
            !prefetch_upper_has_bytes(future_b_offset, 8U)) {
            return -1;
        }

        __asm__ __volatile__("" : "+r"(future_a), "+r"(future_b));

        acc = prefetch_upper_delay(acc ^ ((u64)future_a_offset << 14) ^
                                       ((u64)future_b_offset << 27),
                                   index + 101U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur_a),
                                 index ^ 0x51U);
        acc = prefetch_upper_mix(acc, prefetch_upper_read_u64_le(cur_b),
                                 index ^ 0x91U);
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
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_pipeline_horizon1_page_stride_xdp,
                                bench_prefetch_pipeline_horizon1_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_pipeline_horizon2_page_stride_xdp,
                                bench_prefetch_pipeline_horizon2_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_pipeline_horizon4_page_stride_xdp,
                                bench_prefetch_pipeline_horizon4_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_pipeline_degree_page_stride_xdp,
                                bench_prefetch_pipeline_degree_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_stride64_page_stride_xdp,
                                bench_prefetch_stride64_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_stride256_page_stride_xdp,
                                bench_prefetch_stride256_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_stride4096_page_stride_xdp,
                                bench_prefetch_stride4096_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_variable_stride_page_stride_xdp,
                                bench_prefetch_variable_stride_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_spatial_page_footprint_xdp,
                                bench_prefetch_spatial_page_footprint)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_struct_field_fixed_offsets_xdp,
                                bench_prefetch_struct_field_fixed_offsets)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_mlop_index_field_xdp,
                                bench_prefetch_mlop_index_field)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_degree123_page_stride_xdp,
                                bench_prefetch_degree123_page_stride)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_mixed_policy_table_xdp,
                                bench_prefetch_mixed_policy_table)
DEFINE_PREFETCH_UPPER_XDP_BENCH(prefetch_stream_of_strides_xdp,
                                bench_prefetch_stream_of_strides)

MICRO_LICENSE_ATTR();
