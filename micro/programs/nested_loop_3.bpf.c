#include "common.h"

#define NESTED_LOOP_3_OUTER 8U
#define NESTED_LOOP_3_MIDDLE 8U
#define NESTED_LOOP_3_INNER 4U
#define NESTED_LOOP_3_VALUES (NESTED_LOOP_3_OUTER * NESTED_LOOP_3_MIDDLE * NESTED_LOOP_3_INNER)
#define NESTED_LOOP_3_INPUT_SIZE (16U + NESTED_LOOP_3_VALUES * 8U)

static __always_inline int bench_nested_loop_3(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 16U)) {
        return -1;
    }

    u32 outer = micro_read_u32_le(data, 0);
    u32 middle = micro_read_u32_le(data, 4);
    u32 inner = micro_read_u32_le(data, 8);
    u32 seed = micro_read_u32_le(data, 12);

    if (outer != NESTED_LOOP_3_OUTER || middle != NESTED_LOOP_3_MIDDLE || inner != NESTED_LOOP_3_INNER) {
        return -1;
    }
    if (!micro_has_bytes(len, 16U, NESTED_LOOP_3_VALUES * 8U)) {
        return -1;
    }

    u64 acc = ((u64)seed << 33) ^ 0x94D049BB133111EBULL;
    for (u32 i = 0; i < NESTED_LOOP_3_OUTER; i++) {
        for (u32 j = 0; j < NESTED_LOOP_3_MIDDLE; j++) {
            for (u32 k = 0; k < NESTED_LOOP_3_INNER; k++) {
                u32 index = (i * NESTED_LOOP_3_MIDDLE + j) * NESTED_LOOP_3_INNER + k;
                u64 value = micro_read_u64_le(data, 16U + index * 8U);
                acc += value ^ ((u64)i << 40) ^ ((u64)j << 20) ^ (u64)k;
                if (((i + j + k) & 1U) == 0U) {
                    acc ^= micro_rotl64(value, (k & 7U) + 1U);
                } else {
                    acc += value >> ((j + k) & 7U);
                }
                acc = micro_rotl64(acc, ((i + j + k) & 7U) + 1U);
            }
        }
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    nested_loop_3_xdp,
    bench_nested_loop_3,
    nested_loop_3_input_value,
    NESTED_LOOP_3_INPUT_SIZE)
