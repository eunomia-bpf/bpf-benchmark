#include "common.h"

struct ldp_stack_pair {
    u64 lo;
    u64 hi;
};

static __noinline void fill_ldp_stack_pair(struct ldp_stack_pair *pair,
                                           u64 lo, u64 hi)
{
    pair->lo = lo;
    pair->hi = hi;
}

static __always_inline int bench_ldp_stack_pair(const u8 *data, u32 len,
                                                u64 *out)
{
    struct ldp_stack_pair pair;
    u64 lo;
    u64 hi;

    if (!micro_has_bytes(len, 0, 2)) {
        return -1;
    }

    lo = ((u64)len << 32) ^ data[0];
    hi = ((u64)data[1] << 48) | len;
    fill_ldp_stack_pair(&pair, lo, hi);
    __asm__ __volatile__("" ::: "memory");
    lo = pair.lo;
    hi = pair.hi;
    __asm__ __volatile__("" : "+r"(lo), "+r"(hi) :: "memory");
    *out = lo ^ micro_rotl64(hi, 17);
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(ldp_stack_pair_xdp, bench_ldp_stack_pair,
                              ldp_stack_pair_input_value, 64U)
