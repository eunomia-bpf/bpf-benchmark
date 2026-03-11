#include "common.h"

#define BOUNDS_LADDER_RECORDS 32U
#define BOUNDS_LADDER_RECORD_SIZE 32U
#define BOUNDS_LADDER_INPUT_SIZE (8U + BOUNDS_LADDER_RECORDS * BOUNDS_LADDER_RECORD_SIZE)

static __always_inline int bench_bounds_ladder(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0);
    u32 record_size = micro_read_u32_le(data, 4);
    u64 acc = 0;

    if (record_count != BOUNDS_LADDER_RECORDS || record_size != BOUNDS_LADDER_RECORD_SIZE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, BOUNDS_LADDER_RECORDS * BOUNDS_LADDER_RECORD_SIZE)) {
        return -1;
    }

    for (u32 i = 0; i < BOUNDS_LADDER_RECORDS; i++) {
        u32 base = 8 + i * BOUNDS_LADDER_RECORD_SIZE;
        u32 tag;
        u64 left;
        u32 span;
        u64 right;
        u64 tail;

        if (!micro_has_bytes(len, base, 4)) {
            continue;
        }
        tag = micro_read_u32_le(data, base);
        if (!micro_has_bytes(len, base + 4U, 8)) {
            continue;
        }
        left = micro_read_u64_le(data, base + 4U);
        if (!micro_has_bytes(len, base + 12U, 4)) {
            continue;
        }
        span = micro_read_u32_le(data, base + 12U);
        if (!micro_has_bytes(len, base + 16U, 8)) {
            continue;
        }
        right = micro_read_u64_le(data, base + 16U);
        if (!micro_has_bytes(len, base + 24U, 8)) {
            continue;
        }
        tail = micro_read_u64_le(data, base + 24U);
        if (!micro_has_bytes(len, base + 28U, 4)) {
            continue;
        }

        acc += left + right;
        acc ^= tail + tag + span;
        if ((tag & 1U) == 0) {
            acc += span;
        } else {
            acc ^= left >> 5;
        }
        if ((span & 3U) == 0) {
            acc += tail >> 7;
        } else {
            acc ^= right << 1;
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bounds_ladder_xdp,
    bench_bounds_ladder,
    bounds_ladder_input_value,
    BOUNDS_LADDER_INPUT_SIZE)
