#include "common.h"

#define PREFETCH_RESEARCH_INPUT_SIZE 1400U
#define PREFETCH_RESEARCH_ROUNDS 64U
#define PREFETCH_RESEARCH_TABLE_BASE 64U
#define PREFETCH_RESEARCH_DATA_BASE 256U
#define PREFETCH_RESEARCH_DATA_STRIDE 4U
#define PREFETCH_RESEARCH_INDIRECT_BASE 768U
#define PREFETCH_RESEARCH_INDIRECT_STRIDE 8U
#define PREFETCH_RESEARCH_CACHELINE_STRIDE 64U

static __always_inline int prefetch_research_payload_has_bytes(const u8 *data,
                                                               const u8 *data_end,
                                                               u32 offset,
                                                               u32 size)
{
    const u8 *ptr;

    if (!micro_has_bytes(PREFETCH_RESEARCH_INPUT_SIZE, offset, size)) {
        return 0;
    }

    ptr = data + offset;
    if (ptr < data) {
        return 0;
    }
    if (ptr + size > data_end) {
        return 0;
    }

    return 1;
}

static __always_inline u64 prefetch_research_mix(u64 acc,
                                                 u64 value,
                                                 u32 index,
                                                 u32 salt)
{
    acc ^= value + 0x9E3779B97F4A7C15ULL + ((u64)index << 32) + salt;
    acc = micro_rotl64(acc, ((index + salt) & 31U) + 1U);
    acc += value ^ ((u64)salt * 0x100000001B3ULL);
    return acc;
}

#define PREFETCH_RESEARCH_DELAY(ACC, INDEX, ROUNDS)                         \
    do {                                                                     \
        _Pragma("clang loop unroll(disable)")                                \
        for (u32 step = 0; step < (ROUNDS); step++) {                        \
            (ACC) ^= ((u64)(INDEX) << 32) ^                                  \
                     ((u64)step * 0xD1342543DE82EF95ULL);                   \
            (ACC) = micro_rotl64((ACC) + 0xA0761D6478BD642FULL,              \
                                 ((step + INDEX) & 15U) + 1U);              \
        }                                                                    \
    } while (0)

#define DEFINE_PREFETCH_DISTANCE_CASE(SUFFIX, WORK)                         \
    static __always_inline int bench_prefetch_distance_##SUFFIX(             \
        const u8 *data, const u8 *data_end, u32 len, u64 *out)               \
    {                                                                        \
        if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {        \
            return -1;                                                       \
        }                                                                    \
                                                                             \
        u64 acc = 0xCBF29CE484222325ULL ^ (u64)(WORK);                       \
        _Pragma("clang loop unroll(disable)")                                \
        for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {     \
            u32 slot = (index * 37U + 11U) & 255U;                           \
            u32 offset = PREFETCH_RESEARCH_DATA_BASE +                       \
                         slot * PREFETCH_RESEARCH_DATA_STRIDE;               \
            const u8 *ptr = data + offset;                                   \
            if (!prefetch_research_payload_has_bytes(data, data_end,          \
                                                     offset, 8U)) {           \
                return -1;                                                   \
            }                                                                \
            PREFETCH_RESEARCH_DELAY(acc, index, WORK);                      \
            u64 value = micro_read_u64_le(ptr, 0);                           \
            acc = prefetch_research_mix(acc, value, index, WORK);            \
        }                                                                    \
                                                                             \
        *out = acc;                                                          \
        return 0;                                                            \
    }

DEFINE_PREFETCH_DISTANCE_CASE(0, 0U)
DEFINE_PREFETCH_DISTANCE_CASE(2, 2U)
DEFINE_PREFETCH_DISTANCE_CASE(4, 4U)
DEFINE_PREFETCH_DISTANCE_CASE(8, 8U)
DEFINE_PREFETCH_DISTANCE_CASE(16, 16U)
DEFINE_PREFETCH_DISTANCE_CASE(32, 32U)

static __always_inline int bench_prefetch_indirect_lookup(const u8 *data,
                                                          const u8 *data_end,
                                                          u32 len,
                                                          u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0x84222325CBF29CE4ULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u32 table_offset = PREFETCH_RESEARCH_TABLE_BASE + index;
        u32 target_index = data[table_offset] & 63U;
        u32 target_offset = PREFETCH_RESEARCH_INDIRECT_BASE +
                            target_index * PREFETCH_RESEARCH_INDIRECT_STRIDE;
        const u8 *ptr = data + target_offset;

        if (!prefetch_research_payload_has_bytes(data, data_end,              \
                                                 target_offset, 8U)) {        \
            return -1;                                                        \
        }                                                                     \
        PREFETCH_RESEARCH_DELAY(acc, index, 8U);
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index, target_index);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_indirect_two_stage(const u8 *data,
                                                             const u8 *data_end,
                                                             u32 len,
                                                             u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0xC3A5C85C97CB3127ULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u32 first_offset = PREFETCH_RESEARCH_TABLE_BASE + ((index * 5U) & 63U);
        u32 mid_index = data[first_offset] & 63U;
        u32 mid_offset = PREFETCH_RESEARCH_DATA_BASE + mid_index * 4U;
        const u8 *mid_ptr = data + mid_offset;
        u32 target_index;
        u32 target_offset;
        const u8 *ptr;

        if (!micro_has_bytes(PREFETCH_RESEARCH_INPUT_SIZE, mid_offset, 1U)) {
            return -1;
        }
        if (mid_ptr < data) {
            return -1;
        }
        if (mid_ptr + 1U > data_end) {
            return -1;
        }

        target_index = *mid_ptr & 63U;
        target_offset = PREFETCH_RESEARCH_INDIRECT_BASE +
                        target_index * PREFETCH_RESEARCH_INDIRECT_STRIDE;
        ptr = data + target_offset;
        if (!micro_has_bytes(PREFETCH_RESEARCH_INPUT_SIZE, target_offset, 8U)) {
            return -1;
        }
        if (ptr < data) {
            return -1;
        }
        if (ptr + 8U > data_end) {
            return -1;
        }

        PREFETCH_RESEARCH_DELAY(acc, index, 12U);
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index,
                                    (mid_index << 8) | target_index);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_cacheline_dedup_scan(const u8 *data,
                                                               const u8 *data_end,
                                                               u32 len,
                                                               u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0xA24BAED4963EE407ULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u32 offset = PREFETCH_RESEARCH_DATA_BASE +
                     ((index * PREFETCH_RESEARCH_CACHELINE_STRIDE) & 1023U);
        const u8 *line = data + offset;

        if (!prefetch_research_payload_has_bytes(data, data_end, offset, 32U)) {
            return -1;
        }

        PREFETCH_RESEARCH_DELAY(acc, index, 8U);
        u64 v0 = micro_read_u64_le(line, 0);
        u64 v1 = micro_read_u64_le(line, 8);
        u64 v2 = micro_read_u64_le(line, 16);
        u64 v3 = micro_read_u64_le(line, 24);
        acc = prefetch_research_mix(acc, v0 ^ v2, index, 13U);
        acc = prefetch_research_mix(acc, v1 ^ v3, index, 17U);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_packet_offset_guarded(const u8 *data,
                                                                const u8 *data_end,
                                                                u32 len,
                                                                u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0x6A09E667F3BCC909ULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u32 key_offset = PREFETCH_RESEARCH_TABLE_BASE + ((index * 7U) & 63U);
        u32 target_index = (data[key_offset] ^ (u8)(index * 9U)) & 63U;
        u32 target_offset = PREFETCH_RESEARCH_INDIRECT_BASE +
                            target_index * PREFETCH_RESEARCH_INDIRECT_STRIDE;
        const u8 *ptr = data + target_offset;

        if (!prefetch_research_payload_has_bytes(data, data_end,
                                                 target_offset, 8U)) {
            return -1;
        }

        PREFETCH_RESEARCH_DELAY(acc, index, 20U);
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index, target_index ^ 23U);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_full_packet_ring_scan(const u8 *data,
                                                                const u8 *data_end,
                                                                u32 len,
                                                                u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0xBB67AE8584CAA73BULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < 128U; index++) {
        u32 slot = (index * 29U + 3U) & 127U;
        u32 offset = PREFETCH_RESEARCH_DATA_BASE + slot * 8U;
        const u8 *ptr = data + offset;

        if (!prefetch_research_payload_has_bytes(data, data_end, offset, 8U)) {
            return -1;
        }

        PREFETCH_RESEARCH_DELAY(acc, index, 10U);
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index, slot);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_hot_l1_load(const u8 *data,
                                                      const u8 *data_end,
                                                      u32 len,
                                                      u64 *out)
{
    const u32 offset = PREFETCH_RESEARCH_DATA_BASE + 8U;

    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }
    if (!prefetch_research_payload_has_bytes(data, data_end, offset, 8U)) {
        return -1;
    }

    const u8 *ptr = data + offset;
    u64 acc = 0xA0761D6478BD642FULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index, 3U);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_sequential_scan(const u8 *data,
                                                          const u8 *data_end,
                                                          u32 len,
                                                          u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0xD1342543DE82EF95ULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u32 offset = PREFETCH_RESEARCH_DATA_BASE + index * 8U;
        const u8 *ptr = data + offset;

        if (!prefetch_research_payload_has_bytes(data, data_end, offset, 8U)) {
            return -1;
        }
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index, 5U);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_large_stride_scan(const u8 *data,
                                                            const u8 *data_end,
                                                            u32 len,
                                                            u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0xE7037ED1A0B428DBULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u32 offset = PREFETCH_RESEARCH_DATA_BASE + ((index * 64U) & 1023U);
        const u8 *ptr = data + offset;

        if (!prefetch_research_payload_has_bytes(data, data_end, offset, 8U)) {
            return -1;
        }
        PREFETCH_RESEARCH_DELAY(acc, index, 12U);
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index, 7U);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_permuted_index_scan(const u8 *data,
                                                              const u8 *data_end,
                                                              u32 len,
                                                              u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0x8EBC6AF09C88C6E3ULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u32 cursor = (index * 17U + 23U) & 63U;
        u32 offset = PREFETCH_RESEARCH_INDIRECT_BASE +
                     cursor * PREFETCH_RESEARCH_INDIRECT_STRIDE;
        const u8 *ptr = data + offset;

        if (!prefetch_research_payload_has_bytes(data, data_end, offset, 8U)) {
            return -1;
        }
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index, cursor);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_packet_first_deref(const u8 *data,
                                                             const u8 *data_end,
                                                             u32 len,
                                                             u64 *out)
{
    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }

    u64 acc = 0x589965CC75374CC3ULL;
    _Pragma("clang loop unroll(disable)")
    for (u32 index = 0; index < PREFETCH_RESEARCH_ROUNDS; index++) {
        u32 key_offset = PREFETCH_RESEARCH_TABLE_BASE + ((index * 3U) & 63U);
        u32 target_index = data[key_offset] & 63U;
        u32 target_offset = PREFETCH_RESEARCH_INDIRECT_BASE +
                            target_index * PREFETCH_RESEARCH_INDIRECT_STRIDE;
        const u8 *ptr = data + target_offset;

        if (!prefetch_research_payload_has_bytes(data, data_end,
                                                 target_offset, 8U)) {
            return -1;
        }
        PREFETCH_RESEARCH_DELAY(acc, index, 16U);
        u64 value = micro_read_u64_le(ptr, 0);
        acc = prefetch_research_mix(acc, value, index, target_index ^ 11U);
    }

    *out = acc;
    return 0;
}

static __always_inline int bench_prefetch_single_first_deref(const u8 *data,
                                                             const u8 *data_end,
                                                             u32 len,
                                                             u64 *out)
{
    const u32 key_offset = PREFETCH_RESEARCH_TABLE_BASE + 9U;
    u32 target_index;
    u32 target_offset;
    const u8 *ptr;
    u64 value;
    u64 acc = 0x7F4A7C15D1342543ULL;

    if (!micro_has_bytes(len, 0, PREFETCH_RESEARCH_INPUT_SIZE)) {
        return -1;
    }
    if (!prefetch_research_payload_has_bytes(data, data_end, key_offset, 1U)) {
        return -1;
    }

    target_index = data[key_offset] & 63U;
    target_offset = PREFETCH_RESEARCH_INDIRECT_BASE +
                    target_index * PREFETCH_RESEARCH_INDIRECT_STRIDE;
    ptr = data + target_offset;
    if (!prefetch_research_payload_has_bytes(data, data_end, target_offset, 8U)) {
        return -1;
    }

    PREFETCH_RESEARCH_DELAY(acc, target_index, 16U);
    value = micro_read_u64_le(ptr, 0);
    acc = prefetch_research_mix(acc, value, target_index, 0x5dU);

    *out = acc;
    return 0;
}

#define DEFINE_PREFETCH_RESEARCH_XDP(PROG_NAME, BENCH_FN)                   \
    SEC("xdp") int PROG_NAME(struct xdp_md *ctx)                            \
    {                                                                        \
        u8 *data = (u8 *)(long)ctx->data;                                    \
        u8 *data_end = (u8 *)(long)ctx->data_end;                            \
        u8 *payload;                                                         \
        u64 result = 0;                                                      \
        u32 payload_len;                                                     \
        if (micro_prepare_packet_payload(data, data_end,                     \
                                         PREFETCH_RESEARCH_INPUT_SIZE,       \
                                         &payload, &payload_len) < 0) {      \
            return XDP_ABORTED;                                              \
        }                                                                    \
        if (BENCH_FN(payload, data_end, payload_len, &result) < 0) {         \
            return XDP_ABORTED;                                              \
        }                                                                    \
        micro_write_u64_le(data, result);                                    \
        return XDP_PASS;                                                     \
    }

DEFINE_PREFETCH_RESEARCH_XDP(prefetch_distance_0_xdp, bench_prefetch_distance_0)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_distance_2_xdp, bench_prefetch_distance_2)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_distance_4_xdp, bench_prefetch_distance_4)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_distance_8_xdp, bench_prefetch_distance_8)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_distance_16_xdp, bench_prefetch_distance_16)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_distance_32_xdp, bench_prefetch_distance_32)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_indirect_lookup_xdp,
                             bench_prefetch_indirect_lookup)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_indirect_two_stage_xdp,
                             bench_prefetch_indirect_two_stage)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_cacheline_dedup_scan_xdp,
                             bench_prefetch_cacheline_dedup_scan)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_packet_offset_guarded_xdp,
                             bench_prefetch_packet_offset_guarded)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_full_packet_ring_scan_xdp,
                             bench_prefetch_full_packet_ring_scan)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_hot_l1_load_xdp,
                             bench_prefetch_hot_l1_load)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_sequential_scan_xdp,
                             bench_prefetch_sequential_scan)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_large_stride_scan_xdp,
                             bench_prefetch_large_stride_scan)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_permuted_index_scan_xdp,
                             bench_prefetch_permuted_index_scan)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_packet_first_deref_xdp,
                             bench_prefetch_packet_first_deref)
DEFINE_PREFETCH_RESEARCH_XDP(prefetch_single_first_deref_xdp,
                             bench_prefetch_single_first_deref)

MICRO_LICENSE_ATTR();
