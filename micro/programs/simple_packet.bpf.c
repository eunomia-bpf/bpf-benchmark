#include "common.h"

static __always_inline int bench_simple_packet(const u8 *data, u32 len, u64 *out)
{
    (void)data;
    (void)len;
    *out = 12345678ULL;
    return 0;
}

DEFINE_PACKET_BACKED_XDP_BENCH(simple_packet_xdp, bench_simple_packet)
