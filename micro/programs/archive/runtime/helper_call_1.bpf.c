#include "common.h"

#define HELPER_CALL_1_INPUT_SIZE 8U

struct helper_call_1_input_value {
    unsigned char data[HELPER_CALL_1_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct helper_call_1_input_value);
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

static __always_inline int bench_helper_call_1(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, HELPER_CALL_1_INPUT_SIZE)) {
        return -1;
    }

    u32 seed = micro_read_u32_le(data, 0);
    u32 mix = micro_read_u32_le(data, 4);
    u64 acc = ((u64)seed << 32) ^ mix ^ 0xA24BAED4963EE407ULL;
    HELPER_CALL_STEP(1U);
    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    helper_call_1_xdp,
    bench_helper_call_1,
    helper_call_1_input_value,
    HELPER_CALL_1_INPUT_SIZE)
