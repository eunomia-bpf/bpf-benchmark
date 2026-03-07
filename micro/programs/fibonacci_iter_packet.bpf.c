#include "common.h"

#define FIBONACCI_ITER_INPUT_SIZE 16U
#define FIBONACCI_ITER_ROUNDS 1024U

static __always_inline int bench_fibonacci_iter_packet(const u8 *data, u32 len, u64 *out)
{
    if (!micro_has_bytes(len, 0, FIBONACCI_ITER_INPUT_SIZE)) {
        return -1;
    }

    u32 rounds = micro_read_u32_le(data, 0);
    u32 mix = micro_read_u32_le(data, 4);
    u64 seed = micro_read_u64_le(data, 8);

    if (rounds != FIBONACCI_ITER_ROUNDS) {
        return -1;
    }

    u64 left = (u32)seed;
    u64 right = (seed >> 32) | 1U;
    u64 acc = mix;

    for (u32 i = 0; i < FIBONACCI_ITER_ROUNDS; i++) {
        u64 next = left + right + (i & 7U);
        left = right;
        right = next;
        acc ^= next + (acc << 1);
    }

    *out = acc ^ left ^ right;
    return 0;
}

DEFINE_FIXED_PACKET_BACKED_XDP_BENCH(
    fibonacci_iter_packet_xdp,
    bench_fibonacci_iter_packet,
    FIBONACCI_ITER_INPUT_SIZE)
