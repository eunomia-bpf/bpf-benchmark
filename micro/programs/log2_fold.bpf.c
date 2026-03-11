#include "common.h"

#define LOG2_FOLD_COUNT 128U
#define LOG2_FOLD_INPUT_SIZE (8U + LOG2_FOLD_COUNT * 8U)

static __always_inline u64 micro_log2_u32(u32 value)
{
    u32 shift;
    u32 result;

    result = (value > 0xFFFFU) << 4;
    value >>= result;
    shift = (value > 0xFFU) << 3;
    value >>= shift;
    result |= shift;
    shift = (value > 0xFU) << 2;
    value >>= shift;
    result |= shift;
    shift = (value > 0x3U) << 1;
    value >>= shift;
    result |= shift;
    result |= value >> 1;
    return result;
}

static __always_inline u64 micro_log2_u64(u64 value)
{
    u32 high = value >> 32;

    if (high != 0) {
        return micro_log2_u32(high) + 32U;
    }
    return micro_log2_u32((u32)value);
}

static __always_inline int bench_log2_fold(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0);

    if (count != LOG2_FOLD_COUNT) {
        return -1;
    }
    if (!micro_has_bytes(len, 8, LOG2_FOLD_COUNT * 8U)) {
        return -1;
    }

    u64 hash = 0;
    for (u32 i = 0; i < LOG2_FOLD_COUNT; i++) {
        hash ^= micro_log2_u64(micro_read_u64_le(data, 8 + i * 8U));
    }

    *out = hash;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(log2_fold_xdp, bench_log2_fold, log2_fold_input_value, LOG2_FOLD_INPUT_SIZE)
