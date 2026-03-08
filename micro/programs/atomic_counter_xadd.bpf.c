#include "common.h"

#define ATOMIC_COUNTER_XADD_OPS 32U
#define ATOMIC_COUNTER_XADD_SLOTS 4U
#define ATOMIC_COUNTER_XADD_INPUT_SIZE (8U + ATOMIC_COUNTER_XADD_OPS * 8U)

struct atomic_counter_xadd_input_value {
    unsigned char data[ATOMIC_COUNTER_XADD_INPUT_SIZE];
};

struct atomic_counter_xadd_state {
    __u64 counters[ATOMIC_COUNTER_XADD_SLOTS];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct atomic_counter_xadd_input_value);
} input_map SEC(".maps");

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct atomic_counter_xadd_state);
} counter_map SEC(".maps");

static __always_inline int bench_atomic_counter_xadd(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, 8U)) {
        return -1;
    }

    u32 op_count = micro_read_u32_le(data, 0);
    u32 seed = micro_read_u32_le(data, 4);
    if (op_count != ATOMIC_COUNTER_XADD_OPS) {
        return -1;
    }
    if (!micro_has_bytes(len, 8U, ATOMIC_COUNTER_XADD_OPS * 8U)) {
        return -1;
    }

    __u32 key = 0;
    struct atomic_counter_xadd_state *state = bpf_map_lookup_elem(&counter_map, &key);
    if (!state) {
        return -1;
    }

    for (u32 slot = 0; slot < ATOMIC_COUNTER_XADD_SLOTS; slot++) {
        state->counters[slot] = 0;
    }

    u64 acc = ((u64)seed << 32U) ^ 0xA0761D6478BD642FULL;
    for (u32 index = 0; index < ATOMIC_COUNTER_XADD_OPS; index++) {
        u32 base = 8U + index * 8U;
        u32 slot = micro_read_u32_le(data, base) & (ATOMIC_COUNTER_XADD_SLOTS - 1U);
        u32 delta = micro_read_u32_le(data, base + 4U);
        u64 previous = __sync_fetch_and_add(&state->counters[slot], (u64)delta);
        u64 current = state->counters[slot];

        acc += previous ^ ((u64)delta << ((index & 7U) * 4U));
        acc ^= micro_rotl64(current + slot + index, (slot + index) & 7U);
    }

    for (u32 slot = 0; slot < ATOMIC_COUNTER_XADD_SLOTS; slot++) {
        acc += state->counters[slot] << (slot * 8U);
        acc ^= micro_rotl64(state->counters[slot], slot + 1U);
    }

    *out = acc;
    return 0;
}

DEFINE_MAP_BACKED_XDP_BENCH(
    atomic_counter_xadd_xdp,
    bench_atomic_counter_xadd,
    atomic_counter_xadd_input_value,
    ATOMIC_COUNTER_XADD_INPUT_SIZE)
