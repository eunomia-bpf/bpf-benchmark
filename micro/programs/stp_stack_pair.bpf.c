#include "common.h"

struct stp_stack_pair {
    u64 lo;
    u64 hi;
};

static __noinline u64 consume_stp_stack_pair(const struct stp_stack_pair *pair)
{
    return pair->lo ^ micro_rotl64(pair->hi, 17);
}

static __always_inline int bench_stp_stack_pair(const u8 *data, u32 len,
                                                u64 *out)
{
    struct stp_stack_pair pair;
    u64 lo;
    u64 hi;

    if (!micro_has_bytes(len, 0, 2)) {
        return -1;
    }

    lo = ((u64)len << 32) ^ data[0];
    hi = ((u64)data[1] << 48) | len;
    __asm__ __volatile__("" : "+r"(lo), "+r"(hi) :: "memory");
    pair.lo = lo;
    pair.hi = hi;
    *out = consume_stp_stack_pair(&pair);
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(stp_stack_pair_xdp, bench_stp_stack_pair,
                              stp_stack_pair_input_value, 64U)
