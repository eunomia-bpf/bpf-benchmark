#include "common.h"

#define BCC_RUNQLAT_COUNT 128U
#define BCC_RUNQLAT_MAX_SLOTS 26U
#define BCC_RUNQLAT_INPUT_SIZE (8U + BCC_RUNQLAT_COUNT * 8U)

static __always_inline u32 bcc_runqlat_bucket(u64 raw_delta)
{
    u64 delta_us = ((raw_delta >> 3U) & 0xFFFFFULL) + 1U;
    u32 slot = 0;

    for (u32 bit = 0; bit < 63U; bit++) {
        if (delta_us <= 1U) {
            break;
        }
        delta_us >>= 1U;
        slot++;
    }

    if (slot >= BCC_RUNQLAT_MAX_SLOTS) {
        slot = BCC_RUNQLAT_MAX_SLOTS - 1U;
    }
    return slot;
}

static __always_inline int
bench_bcc_runqlat_log2_histogram_bucket(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, BCC_RUNQLAT_INPUT_SIZE)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    u32 seed = micro_read_u32_le(data, 4U);
    if (count != BCC_RUNQLAT_COUNT) {
        return -1;
    }

    u64 acc = seed;
    for (u32 index = 0; index < BCC_RUNQLAT_COUNT; index++) {
        u64 raw_delta = micro_read_u64_le(data, 8U + index * 8U);
        u32 slot = bcc_runqlat_bucket(raw_delta);

        acc += (u64)(slot + 1U) * (u64)(index + 1U);
        acc ^= micro_rotl64(raw_delta, (slot & 7U) + 1U);
        if (slot == BCC_RUNQLAT_MAX_SLOTS - 1U) {
            acc += raw_delta >> 32U;
        } else {
            acc ^= (u64)slot << ((index & 7U) * 8U);
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bcc_runqlat_log2_histogram_bucket_xdp,
    bench_bcc_runqlat_log2_histogram_bucket,
    bcc_runqlat_log2_histogram_bucket_input_value,
    BCC_RUNQLAT_INPUT_SIZE)
