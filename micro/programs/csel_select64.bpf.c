#include "common.h"

static __always_inline int bench_csel_select64(const u8 *data, u32 len, u64 *out)
{
    u64 cond0;
    u64 cond1;
    u64 truev;
    u64 falsev;
    u64 first;
    u64 second;

    if (!micro_has_bytes(len, 0, 32)) {
        return -1;
    }

    cond0 = micro_read_u64_le(data, 0);
    cond1 = micro_read_u64_le(data, 8);
    truev = micro_read_u64_le(data, 16);
    falsev = micro_read_u64_le(data, 24);

    first = cond0 ? truev : falsev;
    second = cond1 ? falsev : truev;
    *out = first ^ micro_rotl64(second, 13);
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(csel_select64_xdp, bench_csel_select64,
                              csel_select64_input_value, 64U)
