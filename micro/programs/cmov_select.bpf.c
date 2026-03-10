#include "common.h"

#define CMOV_SELECT_GROUPS 32U
#define CMOV_SELECT_LANES 4U
#define CMOV_SELECT_COUNT (CMOV_SELECT_GROUPS * CMOV_SELECT_LANES)
#define CMOV_SELECT_HEADER_SIZE 8U
#define CMOV_SELECT_ARRAY_BYTES (CMOV_SELECT_COUNT * 8U)
#define CMOV_SELECT_A_OFFSET CMOV_SELECT_HEADER_SIZE
#define CMOV_SELECT_B_OFFSET (CMOV_SELECT_A_OFFSET + CMOV_SELECT_ARRAY_BYTES)
#define CMOV_SELECT_X_OFFSET (CMOV_SELECT_B_OFFSET + CMOV_SELECT_ARRAY_BYTES)
#define CMOV_SELECT_Y_OFFSET (CMOV_SELECT_X_OFFSET + CMOV_SELECT_ARRAY_BYTES)
#define CMOV_SELECT_INPUT_SIZE (CMOV_SELECT_Y_OFFSET + CMOV_SELECT_ARRAY_BYTES)

struct cmov_select_input_value {
    unsigned char data[CMOV_SELECT_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct cmov_select_input_value);
} input_map SEC(".maps");

/*
 * Keep the actual select in a dedicated subprog so the BPF body at the
 * directive site is just register-to-register choice, not extra load work.
 * The userspace scanner should find the select pattern across the full
 * translated program, not just the entry subprog.
 */
static __noinline u64 cmov_select_pick(u64 lhs, u64 rhs, u64 on_true, u64 on_false)
{
    u64 selected = on_true;

    if (lhs <= rhs) {
        selected = on_false;
    }

    return selected;
}

#define CMOV_SELECT_STEP(INDEX, ROT)                                            \
    do {                                                                        \
        u32 index = (INDEX);                                                    \
        u64 a = micro_read_u64_le(data, CMOV_SELECT_A_OFFSET + index * 8U);     \
        u64 b = micro_read_u64_le(data, CMOV_SELECT_B_OFFSET + index * 8U);     \
        u64 x = micro_read_u64_le(data, CMOV_SELECT_X_OFFSET + index * 8U);     \
        u64 y = micro_read_u64_le(data, CMOV_SELECT_Y_OFFSET + index * 8U);     \
        u64 selected = cmov_select_pick(a, b, x, y);                            \
        acc += selected ^ (0x9E3779B97F4A7C15ULL + index);                      \
        acc = micro_rotl64(acc, (ROT));                                         \
        acc ^= selected >> (index & 7U);                                        \
    } while (0)

static __always_inline int bench_cmov_select(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, CMOV_SELECT_HEADER_SIZE)) {
        return -1;
    }

    u32 count = micro_read_u32_le(data, 0U);
    u32 groups = micro_read_u32_le(data, 4U);
    if (count != CMOV_SELECT_COUNT || groups != CMOV_SELECT_GROUPS) {
        return -1;
    }
    if (!micro_has_bytes(len, CMOV_SELECT_A_OFFSET, CMOV_SELECT_ARRAY_BYTES * 4U)) {
        return -1;
    }

    u64 acc = 0x243F6A8885A308D3ULL;
    for (u32 group = 0; group < CMOV_SELECT_GROUPS; group++) {
        u32 base = group * CMOV_SELECT_LANES;

        CMOV_SELECT_STEP(base + 0U, 1U);
        CMOV_SELECT_STEP(base + 1U, 2U);
        CMOV_SELECT_STEP(base + 2U, 3U);
        CMOV_SELECT_STEP(base + 3U, 4U);

        acc ^= micro_rotl64(acc + group, (group & 7U) + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    cmov_select_xdp,
    bench_cmov_select,
    cmov_select_input_value,
    CMOV_SELECT_INPUT_SIZE)
