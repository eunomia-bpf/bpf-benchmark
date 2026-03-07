#include "common.h"

#define BOUNDS_CHECK_HEAVY_RECORDS 32U
#define BOUNDS_CHECK_HEAVY_RECORD_SIZE 32U
#define BOUNDS_CHECK_HEAVY_INPUT_SIZE (8U + BOUNDS_CHECK_HEAVY_RECORDS * BOUNDS_CHECK_HEAVY_RECORD_SIZE)

struct bounds_check_heavy_input_value {
    unsigned char data[BOUNDS_CHECK_HEAVY_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct bounds_check_heavy_input_value);
} input_map SEC(".maps");

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
        u32 field1;
        u32 field2;
        u32 field3;
        u64 left;
        u64 right;
        u32 mid;
        u16 tail;

        if (!micro_has_bytes(len, field0, 8U)) {
            continue;
        }
        left = micro_read_u64_le(data, field0);
        field1 = field0 + off1;
        if (!micro_has_bytes(len, field1, 4U)) {
            continue;
        }
        mid = micro_read_u32_le(data, field1);
        field2 = field1 + (span0 & 7U);
        if (!micro_has_bytes(len, field2, 2U)) {
            continue;
        }
        tail = micro_read_u16_le(data, field2);
        field3 = base + 16U + off2;
        if (!micro_has_bytes(len, field3, 8U)) {
            continue;
        }
        right = micro_read_u64_le(data, field3);

        if ((selector & 1U) != 0U) {
            u32 extra = base + 24U + (selector & 3U);
            if (!micro_has_bytes(len, extra, 4U)) {
                continue;
            }
            acc += micro_read_u32_le(data, extra);
        }
        if ((selector & 2U) != 0U) {
            u32 extra2 = base + 20U + ((selector >> 2) & 3U);
            if (!micro_has_bytes(len, extra2, 2U)) {
                continue;
            }
            acc ^= micro_read_u16_le(data, extra2);
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
