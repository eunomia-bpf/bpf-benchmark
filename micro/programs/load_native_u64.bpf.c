#include "common.h"

/* Causal isolation: native u64 load path.
 * Reads 128 u64 values via aligned struct cast (direct mov on kernel JIT).
 * Paired with load_byte_recompose which uses byte-by-byte reconstruction
 * (movzbq + shl + or on kernel JIT). The exec_ns difference isolates
 * the byte-recompose time cost. */

#define LNU_COUNT 128U
#define LNU_INPUT_SIZE (8U + LNU_COUNT * 8U)

struct lnu_aligned {
    __u32 count;
    __u32 _pad;
    __u64 values[LNU_COUNT];
};

struct load_native_u64_input_value {
    unsigned char data[LNU_INPUT_SIZE];
};

struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 1);
    __type(key, __u32);
    __type(value, struct load_native_u64_input_value);
} input_map SEC(".maps");

static __always_inline int bench_load_native_u64(const u8 *data, u32 len, u64 *out)
{
    /* Reinterpret the byte array as an aligned struct.
     * BPF verifier accepts this for map value pointers. */
    const struct lnu_aligned *inp = (const struct lnu_aligned *)data;

    if (inp->count != LNU_COUNT)
        return -1;

    u64 acc = 0;
    for (u32 i = 0; i < LNU_COUNT; i++) {
        u64 value = inp->values[i];
        acc += value;
        acc ^= value >> (i & 15U);
    }

    *out = acc;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(
    load_native_u64_xdp,
    bench_load_native_u64,
    load_native_u64_input_value,
    LNU_INPUT_SIZE)
