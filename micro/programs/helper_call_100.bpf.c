#include "common.h"

#define HELPER_CALL_100_INPUT_SIZE 8U

struct helper_call_100_input_value {
    unsigned char data[HELPER_CALL_100_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct helper_call_100_input_value);
} input_map SEC(".maps");

#define HELPER_CALL_STEP(SALT)                                                  \
    do {                                                                        \
        u64 helper_value = bpf_ktime_get_ns();                                  \
        acc ^= helper_value ^ helper_value;                                     \
        acc += (u64)mix + ((u64)(SALT) * 0x9E3779B1ULL);                        \
        acc ^= acc >> (((SALT) & 7U) + 1U);                                     \
        acc = micro_rotl64(acc ^ ((u64)seed << ((SALT) & 7U)),                  \
                           (((SALT) >> 1) & 7U) + 1U);                          \
    } while (0)

#define HELPER_CALL_BLOCK_10(BASE)                                              \
    HELPER_CALL_STEP((BASE) + 0U);                                              \
    HELPER_CALL_STEP((BASE) + 1U);                                              \
    HELPER_CALL_STEP((BASE) + 2U);                                              \
    HELPER_CALL_STEP((BASE) + 3U);                                              \
    HELPER_CALL_STEP((BASE) + 4U);                                              \
    HELPER_CALL_STEP((BASE) + 5U);                                              \
    HELPER_CALL_STEP((BASE) + 6U);                                              \
    HELPER_CALL_STEP((BASE) + 7U);                                              \
    HELPER_CALL_STEP((BASE) + 8U);                                              \
    HELPER_CALL_STEP((BASE) + 9U)

#define HELPER_CALL_BLOCK_100(BASE)                                             \
    HELPER_CALL_BLOCK_10((BASE) + 0U);                                          \
    HELPER_CALL_BLOCK_10((BASE) + 10U);                                         \
    HELPER_CALL_BLOCK_10((BASE) + 20U);                                         \
    HELPER_CALL_BLOCK_10((BASE) + 30U);                                         \
    HELPER_CALL_BLOCK_10((BASE) + 40U);                                         \
    HELPER_CALL_BLOCK_10((BASE) + 50U);                                         \
    HELPER_CALL_BLOCK_10((BASE) + 60U);                                         \
    HELPER_CALL_BLOCK_10((BASE) + 70U);                                         \
    HELPER_CALL_BLOCK_10((BASE) + 80U);                                         \
    HELPER_CALL_BLOCK_10((BASE) + 90U)

static __always_inline int bench_helper_call_100(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, HELPER_CALL_100_INPUT_SIZE)) {
        return -1;
    }

    u32 seed = micro_read_u32_le(data, 0);
    u32 mix = micro_read_u32_le(data, 4);
    u64 acc = ((u64)seed << 32) ^ mix ^ 0x94D049BB133111EBULL;
    HELPER_CALL_BLOCK_100(1U);
    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    helper_call_100_xdp,
    bench_helper_call_100,
    helper_call_100_input_value,
    HELPER_CALL_100_INPUT_SIZE)
