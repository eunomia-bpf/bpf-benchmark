#include "common.h"

#define BOUNDS_CHECK_HEAVY_RECORDS 32U
#define BOUNDS_CHECK_HEAVY_RECORD_SIZE 32U
#define BOUNDS_CHECK_HEAVY_INPUT_SIZE (8U + BOUNDS_CHECK_HEAVY_RECORDS * BOUNDS_CHECK_HEAVY_RECORD_SIZE)

/*
 * The staged XDP path rejects the original variable-offset packet loads for
 * this benchmark, so the hot loop now keeps the dependent bounds checks but
 * routes the dynamic reads through fixed-offset switch ladders.
 */
static __always_inline u32 bounds_check_heavy_read_mid(const u8 *data, u32 base, u32 off)
{
    switch (off) {
    case 0U:
        return micro_read_u32_le(data, base + 4U);
    case 1U:
        return micro_read_u32_le(data, base + 5U);
    case 2U:
        return micro_read_u32_le(data, base + 6U);
    case 3U:
        return micro_read_u32_le(data, base + 7U);
    case 4U:
        return micro_read_u32_le(data, base + 8U);
    case 5U:
        return micro_read_u32_le(data, base + 9U);
    case 6U:
        return micro_read_u32_le(data, base + 10U);
    case 7U:
        return micro_read_u32_le(data, base + 11U);
    default:
        return 0;
    }
}

static __always_inline u16 bounds_check_heavy_read_tail(const u8 *data, u32 base, u32 off)
{
    switch (off) {
    case 0U:
        return micro_read_u16_le(data, base + 4U);
    case 1U:
        return micro_read_u16_le(data, base + 5U);
    case 2U:
        return micro_read_u16_le(data, base + 6U);
    case 3U:
        return micro_read_u16_le(data, base + 7U);
    case 4U:
        return micro_read_u16_le(data, base + 8U);
    case 5U:
        return micro_read_u16_le(data, base + 9U);
    case 6U:
        return micro_read_u16_le(data, base + 10U);
    case 7U:
        return micro_read_u16_le(data, base + 11U);
    case 8U:
        return micro_read_u16_le(data, base + 12U);
    case 9U:
        return micro_read_u16_le(data, base + 13U);
    case 10U:
        return micro_read_u16_le(data, base + 14U);
    case 11U:
        return micro_read_u16_le(data, base + 15U);
    case 12U:
        return micro_read_u16_le(data, base + 16U);
    case 13U:
        return micro_read_u16_le(data, base + 17U);
    case 14U:
        return micro_read_u16_le(data, base + 18U);
    default:
        return 0;
    }
}

static __always_inline u64 bounds_check_heavy_read_right(const u8 *data, u32 base, u32 off)
{
    switch (off) {
    case 0U:
        return micro_read_u64_le(data, base + 16U);
    case 1U:
        return micro_read_u64_le(data, base + 17U);
    case 2U:
        return micro_read_u64_le(data, base + 18U);
    case 3U:
        return micro_read_u64_le(data, base + 19U);
    case 4U:
        return micro_read_u64_le(data, base + 20U);
    case 5U:
        return micro_read_u64_le(data, base + 21U);
    case 6U:
        return micro_read_u64_le(data, base + 22U);
    case 7U:
        return micro_read_u64_le(data, base + 23U);
    default:
        return 0;
    }
}

static __always_inline u32 bounds_check_heavy_read_extra_u32(const u8 *data, u32 base, u32 off)
{
    switch (off) {
    case 0U:
        return micro_read_u32_le(data, base + 24U);
    case 1U:
        return micro_read_u32_le(data, base + 25U);
    case 2U:
        return micro_read_u32_le(data, base + 26U);
    case 3U:
        return micro_read_u32_le(data, base + 27U);
    default:
        return 0;
    }
}

static __always_inline u16 bounds_check_heavy_read_extra_u16(const u8 *data, u32 base, u32 off)
{
    switch (off) {
    case 0U:
        return micro_read_u16_le(data, base + 20U);
    case 1U:
        return micro_read_u16_le(data, base + 21U);
    case 2U:
        return micro_read_u16_le(data, base + 22U);
    case 3U:
        return micro_read_u16_le(data, base + 23U);
    default:
        return 0;
    }
}

static __always_inline int bench_bounds_check_heavy(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 record_count = micro_read_u32_le(data, 0);
    u32 record_size = micro_read_u32_le(data, 4);
    if (record_count != BOUNDS_CHECK_HEAVY_RECORDS || record_size != BOUNDS_CHECK_HEAVY_RECORD_SIZE) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, BOUNDS_CHECK_HEAVY_RECORDS * BOUNDS_CHECK_HEAVY_RECORD_SIZE)) {
        return -1;
    }

    u64 acc = 0x2545F4914F6CDD1DULL;
    for (u32 i = 0; i < BOUNDS_CHECK_HEAVY_RECORDS; i++) {
        u32 base = 8U + i * BOUNDS_CHECK_HEAVY_RECORD_SIZE;
        if (!micro_has_bytes(len, base, 4U)) {
            return -1;
        }

        u32 span0 = data[base];
        u32 off1 = data[base + 1] & 7U;
        u32 off2 = data[base + 2] & 7U;
        u32 selector = data[base + 3];
        u32 field0 = base + 4U;
        u32 field1 = field0 + off1;
        u32 field2 = field1 + (span0 & 7U);
        u32 field3 = base + 16U + off2;
        u64 left;
        u64 right;
        u32 mid;
        u16 tail;

        if (!micro_has_bytes(len, field0, 8U)) {
            continue;
        }
        left = micro_read_u64_le(data, field0);
        if (!micro_has_bytes(len, field1, 4U)) {
            continue;
        }
        mid = bounds_check_heavy_read_mid(data, base, off1);
        if (!micro_has_bytes(len, field2, 2U)) {
            continue;
        }
        tail = bounds_check_heavy_read_tail(data, base, off1 + (span0 & 7U));
        if (!micro_has_bytes(len, field3, 8U)) {
            continue;
        }
        right = bounds_check_heavy_read_right(data, base, off2);

        if ((selector & 1U) != 0U) {
            u32 extra = base + 24U + (selector & 3U);
            if (!micro_has_bytes(len, extra, 4U)) {
                continue;
            }
            acc += bounds_check_heavy_read_extra_u32(data, base, selector & 3U);
        }
        if ((selector & 2U) != 0U) {
            u32 extra2 = base + 20U + ((selector >> 2) & 3U);
            if (!micro_has_bytes(len, extra2, 2U)) {
                continue;
            }
            acc ^= bounds_check_heavy_read_extra_u16(data, base, (selector >> 2) & 3U);
        }

        acc += left ^ right;
        acc ^= ((u64)mid << (selector & 7U));
        acc += tail + span0 + off1 + off2;
        acc = micro_rotl64(acc, (selector & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    bounds_check_heavy_xdp,
    bench_bounds_check_heavy,
    bounds_check_heavy_input_value,
    BOUNDS_CHECK_HEAVY_INPUT_SIZE)
