#include "common.h"

#define OTEL_UNWIND_FRAME_COUNT 24U
#define OTEL_UNWIND_FRAME_SIZE 24U
#define OTEL_UNWIND_INPUT_SIZE \
    (8U + OTEL_UNWIND_FRAME_COUNT * OTEL_UNWIND_FRAME_SIZE)

static __always_inline u32 otel_frame_kind_weight(u16 kind)
{
    switch (kind) {
    case 0U: return 0x21U;
    case 1U: return 0x35U;
    case 2U: return 0x55U;
    case 3U: return 0x89U;
    default: return 0U;
    }
}

static __always_inline int
bench_otel_stack_frame_unwind_scan(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, OTEL_UNWIND_INPUT_SIZE)) {
        return -1;
    }

    u32 frame_count = micro_read_u32_le(data, 0U);
    u32 frame_size = micro_read_u32_le(data, 4U);
    if (frame_count != OTEL_UNWIND_FRAME_COUNT ||
        frame_size != OTEL_UNWIND_FRAME_SIZE) {
        return -1;
    }

    u64 acc = 0x589965CC75374CC3ULL;
    u64 cursor = 0x100000000ULL;
    for (u32 index = 0; index < OTEL_UNWIND_FRAME_COUNT; index++) {
        u32 base = 8U + index * OTEL_UNWIND_FRAME_SIZE;
        u64 ip = micro_read_u64_le(data, base);
        u32 sp_delta = micro_read_u32_le(data, base + 8U);
        u32 fp_delta = micro_read_u32_le(data, base + 12U);
        u16 flags = micro_read_u16_le(data, base + 16U);
        u16 kind = micro_read_u16_le(data, base + 18U);
        u32 symbol_hash = micro_read_u32_le(data, base + 20U);
        u32 weight = otel_frame_kind_weight(kind);
        u32 frame_ok = sp_delta <= 4096U && fp_delta <= 8192U;

        if (weight == 0U || frame_ok == 0U) {
            acc ^= ((u64)kind << 48U) | ip;
            continue;
        }

        cursor += sp_delta + ((flags & 1U) ? fp_delta : 8U);
        u64 frame_sig = ip ^ cursor ^ ((u64)symbol_hash << 32U) ^ weight;
        if ((flags & 2U) != 0U) {
            frame_sig = micro_rotl64(frame_sig, (kind & 7U) + 1U);
        }
        if ((flags & 4U) != 0U) {
            frame_sig += ((u64)fp_delta << 24U) ^ sp_delta;
        }

        acc += micro_rotl64(frame_sig, (index & 7U) + 1U);
        acc ^= ((u64)flags << 40U) | symbol_hash;
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    otel_stack_frame_unwind_scan_xdp,
    bench_otel_stack_frame_unwind_scan,
    otel_stack_frame_unwind_scan_input_value,
    OTEL_UNWIND_INPUT_SIZE)
