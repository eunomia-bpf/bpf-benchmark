#include "common.h"

static __always_inline int bench_ccmp_all_nonzero(const u8 *data, u32 len,
                                                  u64 *out)
{
    u64 a;
    u64 b;
    u64 c;
    u64 d;
    u64 ok;

    if (!micro_has_bytes(len, 1, 4)) {
        return -1;
    }

    a = data[1];
    b = data[2];
    c = data[3];
    d = data[4];

    ok = (a != 0) & (b != 0) & (c != 0) & (d != 0);

    *out = ok;
    return 0;
}

DEFINE_STAGED_INPUT_XDP_BENCH(ccmp_all_nonzero_xdp, bench_ccmp_all_nonzero,
                              ccmp_all_nonzero_input_value, 64U)
